/**
 * @file   new.h
 * @author Daniel Huebleitner <dh@mbp.huebleitner.net>
 * @date   Sun Oct 23 03:31:51 2016
 *
 * @brief  Header to use new keyword within library \
 * New is implemented via Macro and is NOT tested properly
 */

#ifndef NEW_H

#define new(TYPE) alloc_##TYPE
#define destroy(TYPE) free_##TYPE

#define NEW_H
#endif /*NEW_H*/
