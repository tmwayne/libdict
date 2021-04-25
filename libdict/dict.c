//
// -----------------------------------------------------------------------------
// dict.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne © 2021
//

#include <stdio.h> // printf
#include <string.h> // strdup
#include "dict.h"
#include "mem.h" // NEW, FREE
#include "assert.h" // assert
#include "except.h" // RAISE
#include "c-strings.h" // strmatch

#define D dict_T

const Except_T Dict_EmptyKey = { "Dictionary key is empty" };

typedef struct Elem_T {
  char *key;
  void *val;
  struct Elem_T *link;
} *Elem_T;

struct D {
  Elem_T head;
};

D dict_new() {
  D dict;
  NEW(dict);
  dict->head = NULL;
  return dict;
}

int dict_size(D dict) {

  assert(dict);

  Elem_T elem;
  int size = 0;

  for (elem=dict->head; elem; elem=elem->link) size++;

  return size;

}

void dict_set(D dict, char *key, void *val) {

  assert(dict && key && val);
  if (*key == '\0') RAISE(Dict_EmptyKey);

  Elem_T elem;

  for (elem=dict->head; elem; elem=elem->link) {
    if (strmatch(elem->key, key)) {
      elem->val = val;
      return;
    }
  }

  NEW(elem);
  elem->key = strdup(key);
  elem->val = val;
  elem->link = dict->head;
  dict->head = elem;
}

void *dict_get(D dict, char *key) {

  assert(dict && key);

  if (*key == '\0') RAISE(Dict_EmptyKey);

  for (Elem_T elem=dict->head; elem; elem=elem->link)
    if (strmatch(elem->key, key))
      return elem->val;

  return NULL;
}

void dict_free(D *dict, void (*free_val)(void *)) {

  assert(dict && *dict);

  Elem_T elem, link;

  for (elem=(*dict)->head; elem; elem=link) {
    link = elem->link;
    FREE(elem->key);
    if (free_val) free_val(elem->val);
    FREE(elem);
  }
  FREE(*dict);
}

void dict_dump(D dict) {
  assert(dict);
  for (Elem_T elem=dict->head; elem; elem=elem->link)
    printf("Key: %s, Val: %s\n", elem->key, (char *) elem->val);
}
