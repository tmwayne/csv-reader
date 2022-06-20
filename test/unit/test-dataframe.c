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

// dataframePush(dataframe_T df, const record_T record)

static char *
test_dataframeSetHeaders_nullArg() 
{
  dataframe_T df = dataframeNew();
  record_T headers = recordNew();
  mu_assert("dataframeSetHeaders didn't return error for NULL arguments", 
  dataframeSetHeaders(NULL, headers) == DF_NULLARG &&
    dataframeSetHeaders(df, NULL) == DF_NULLARG);
}

static char *
test_dataframePush_recordTooLong()
{
  record_T headers = recordNew();
  recordPush(headers, strdup("col1"));

  record_T record = recordNew();
  for (int i=0; i<2; i++) recordPush(record, strdup("val"));

  dataframe_T dfWithHeader = dataframeNew();
  dataframeSetHeaders(dfWithHeader, headers);

  dataframe_T dfWithoutHeader = dataframeNew();
  dataframePush(dfWithoutHeader, headers);

  mu_assert("dataframePush didn't return error for too long of record",
    dataframePush(dfWithHeader, record) == DF_INVRECORD &&
    dataframePush(dfWithoutHeader, record) == DF_INVRECORD);
}

static char *
test_dataframePush_recordTooShort()
{
  record_T headers = recordNew();
  recordPush(headers, strdup("col1"));
  recordPush(headers, strdup("col2"));

  record_T record = recordNew();
  recordPush(record, strdup("val"));

  dataframe_T dfWithHeader = dataframeNew();
  dataframeSetHeaders(dfWithHeader, headers);

  dataframe_T dfWithoutHeader = dataframeNew();
  dataframePush(dfWithoutHeader, headers);

  mu_assert("dataframePush didn't return error for too short of record",
    dataframePush(dfWithHeader, record) == DF_INVRECORD &&
    dataframePush(dfWithoutHeader, record) == DF_INVRECORD);
}


static char * 
run_all_tests() 
{
  char *(*all_tests[])() = {
    test_dataframeSetHeaders_nullArg,
    test_dataframePush_recordTooLong,
    test_dataframePush_recordTooShort,
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
