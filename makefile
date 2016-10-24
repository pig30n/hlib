##
##
## @file hlib/make
## @modified 2016-10-24 14:07:27 (CEST)
## @author Daniel Huebleitner
## @brief build targets
##
##
PR := hlib
TSTDIRS = tst/*
INCLDIRS = incl/*
SRCDIRS = src/*
OUTDIRS = out/*
DOCDIRS = doc/*

TST := $(foreach dir,$(TSTDIRS),$(wildcard $(dir)/*.c))
INCL := $(foreach dir,$(INCLDIRS),$(wildcard $(dir)/*.h))
SRC := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
OUT := $(foreach dir,$(OUTDIRS),$(wildcard $(dir)/*.o))
DOC := $(foreach dir,$(DOCDIRS),$(wildcard $(dir)/*))

SHELL = /bin/bash
OPT = -O3
CC = clang
DFLAGS = -g
CFLAGS = -pedantic-errors ${DFLAGS} -Wall -std=c1x ${OPT}

t:
	echo ${INCL}


all: build

build: ${PR}.a

${PR}.a: ${OUT}
	ar rc lib$@ $?
	ranlib lib$@

${OUT}/%.o: ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@ -I${INCLDIRS} -L./ -l${PR}

test: build

doc:

install:

clean:

dist:

clean:
	rm ${OUTDIR}

.SECONDARY:

.PHONY: all build
