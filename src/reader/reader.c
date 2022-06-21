//
// -----------------------------------------------------------------------------
// main.c
// -----------------------------------------------------------------------------
//
// Copyright (c) 2022 Tyler Wayne
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdio.h>
#include "parser.h"
#include "lexer.h"
#include "dataframe.h"
#include "errorcodes.h"
#include "error-functions.h"

void
yyerror(const dataframe_T data, const struct scannerArgs scanner, const char *msg)
{
  fprintf(stderr, "Error: %s\n", msg);
}

dataframe_T
parseDelim(FILE *file, struct scannerArgs scanner)
{
  // TODO: add error detection
  
  dataframe_T data = dataframeNew();

  if (yyparse(data, scanner) == -1)
    errExit("Failed to parse data");

  return data;
}

int 
main(int argc, char **argv) 
{
  struct scannerArgs scanner = {
    .yyin = stdin,
    .sep = '|',
    .headers = 1,
    .quotes = 1
  };

  dataframe_T data = parseDelim(stdin, scanner);

  printf("data has\n"
    "nfields: %d\n"
    "nlines:  %d\n", data->nfields, data->nrecords);

  if(data->headers) {
    for (int i=0; i<data->nfields; i++)
      printf("%d| %s\n", i, data->headers->fields[i]);
  }
}
