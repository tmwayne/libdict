//
// -----------------------------------------------------------------------------
// test-dict.c
// -----------------------------------------------------------------------------
//
// Test libdict
//

#include <stdio.h> // printf

#include <error.h> // TRY, EXCEPT, END_TRY, Assert_Failed
#include "minunit.h"
#include "dict.h"

int tests_run = 0;

// Mem_alloc -------------------------------------------------------------------

static char *empty_test() {
  return 0;
}

// static char *test_ALLOC_0_bytes() {
//   int pass = 0;
//   TRY ALLOC(0);
//   EXCEPT (Mem_Failed) pass = 1;
//   END_TRY;
//   mu_assert("Test Failed: Mem_alloc didn't throw Exception for NULL pointer", pass);
//   return 0;
// }

// static char *test_Mem_alloc_valid() {
//   char *str = Mem_alloc(1, "file", 1);
//   mu_assert("Test Failed: Mem_alloc failed to allocate one byte", str);
//   return 0;
// }

// Run tests -------------------------------------------------------------------

static char *run_tests() {

  mu_run_test(empty_test);

  return 0;

}

int main(int argc, char **argv) {
  
  char *result = run_tests();

  if (result != 0) printf("%s\n", result);
  else printf("ALL TESTS PASSED\n");

  printf("Tests run %d\n", tests_run);
  return result != 0;

}
