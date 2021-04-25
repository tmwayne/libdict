//
// -----------------------------------------------------------------------------
// main.c
// -----------------------------------------------------------------------------
//
// Simple example using dict_T
//

#include <stdio.h>  // printf
#include <stdlib.h> // free
#include <string.h> // strdup
#include "dict.h"   // dict_set, dict_dump, dict_free

int main() {

  char *key = "this";
  char *val = strdup("this");

  dict_T dict = dict_new();
  dict_set(dict, key, val);
  
  printf("Value of %s is: %s\n", key, (char *) dict_get(dict, key));

  // Dict_set(dict, "this", "dog");
  // printf("Value of %s is now: %s\n", key, (char *) Dict_get(dict, key)); 

  dict_dump(dict);
  dict_free(&dict, free);

}
