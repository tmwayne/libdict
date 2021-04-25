// 
// -----------------------------------------------------------------------------
// dict.h
// -----------------------------------------------------------------------------
//
// The Dictionary ADT is a simple key/value store. Setting an existing key
// will update the current value with the new one. The value is a pointer
// pointing to anything. This will have to be cast to the correct type
// depending on the use case.
//
// Tyler Wayne © 2021
//

#ifndef DICT_INCLUDED
#define DICT_INCLUDED

#include "except.h"

#define D dict_T
typedef struct D *D;

extern const Except_T Dict_EmptyKey;

extern D      dict_new();
extern int    dict_size(D);
extern void   dict_set(D, char *key, void *val);
extern void  *dict_get(D, char *key);
extern void   dict_free(D *, void (*free_val)(void *));
extern void   dict_dump(D dict);

#undef D
#endif
