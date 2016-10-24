#ifndef H_LIB_TYPES_H

#include <types.h>
#include <stdint.h>
#include <stdbool.h>

typedef int8_t       Int8;
typedef int_fast16_t Int16;
typedef int_fast32_t Int32;
typedef int_fast64_t Int64;

typedef uint8_t       Uint8;
typedef uint_fast16_t Uint16;
typedef uint_fast32_t Uint32;
typedef uint_fast64_t Uint64;

typedef size_t Size;
typedef ssize_t Ssize;

#define Bool bool
#define File FILE
#define Void void

#define H_LIB_TYPES_H
#endif /*TYPES_H*/
