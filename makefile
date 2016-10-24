##
##
## @file hlib/make
## @modified 2016-10-24 16:49:03 (CEST)
## @author Daniel Huebleitner
## @brief build targets
##
##
PR := hlib
MODULES := util data error

INCLDIR := ./incl/
TSTDIR := ./tst/
SRCDIR := ./src/
DOCDIR := ./doc/
BINDIR := ./bin/

INCLDIRS := $(addprefix ${INCLDIR},$(MODULES))
TSTDIRS := $(addprefix ${TSTDIR},$(MODULES))
SRCDIRS := $(addprefix ${SRCDIR},$(MODULES))
DOCDIRS := $(addprefix ${DOCDIR},$(MODULES))
BINDIRS := $(addprefix ${BINDIR},$(MODULES))

INCL := $(foreach dir,$(INCLDIRS),$(wildcard $(dir)/*.h))
TST := $(foreach dir,$(TSTDIRS),$(wildcard $(dir)/*.c))
SRC := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
DOC := $(foreach dir,$(DOCDIRS),$(wildcard $(dir)/*))
BIN := $(patsubst ${SRCDIR}%, ${BINDIR}%, $(patsubst %.c,%.o,${SRC}))

SHELL = /bin/bash
OPT = -O3
CC = clang
DFLAGS = -g
CFLAGS = -pedantic-errors ${DFLAGS} -Wall -std=c1x ${OPT}

all: build

##build
build: ${BINDIRS} ${BINDIR}lib${PR}.a

${BINDIR}lib${PR}.a: ${BIN}
	ar rc $@ $?
	ranlib $@

$(BINDIRS):
	@mkdir -p $@

${BIN}: ${SRC}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCLDIR}

##test
test: build
	${CC} ${CFLAGS} -c $< -o $@ -I${INCLDIR} -L${BINDIR} -l${PR}

##doc
doc:

##install
install:

##clean
clean:
	-rm -r -f ${BINDIR}*

##dist
dist:

.SECONDARY:

.PHONY: all build  test doc install clean dist
