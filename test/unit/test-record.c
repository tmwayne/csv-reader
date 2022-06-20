//
// -----------------------------------------------------------------------------
// test-sample.c
// -----------------------------------------------------------------------------
//
// Tyler Wayne (c) 2022
//

#include <stdio.h>  // printf
#include <string.h> // strdup
#include "minunit.h"
#include "dataframe.h"
#include "errorcodes.h"

int tests_run = 0;

static char *
test_recordPush_nullArg() 
{
  record_T record = recordNew();
  char *val = strdup("val");
  mu_assert("recordPush didn't return error for NULL arguments", 
  recordPush(NULL, val) == DF_NULLARG && recordPush(record, NULL) == DF_NULLARG);
}

static char * 
run_all_tests() 
{
  char *(*all_tests[])() = {
    test_recordPush_nullArg,
    NULL
  };

  // Returns message of first failing test
  mu_run_all(all_tests);
    
  return NULL;
}

int 
main(int argc, char** argv) 
{
  char* errmsg = run_all_tests();

  if (!errmsg)  printf("ALL TESTS PASSED\n");
  else          printf("%s\n", errmsg);

  printf("Tests run: %d\n", tests_run);

  return !!errmsg;
}
