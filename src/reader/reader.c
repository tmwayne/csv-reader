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

void 
yyerror(YYLTYPE *yyllocp, struct data * data, yyscan_t unused, const char *msg)
{
  fprintf(stderr, "[%d:%d]: %s\n",
    yyllocp->first_line, yyllocp->first_column, msg);
}

int 
main(int argc, char **argv) 
{
  // struct data *data;
  // data = calloc(1, sizeof(struct data));

  // yyscan_t scanner;
  // yylex_init(&scanner);

  // yyparse(data, scanner);
  // yylex_destroy(scanner);

  // printf("data has\n"
    // "nfields: %d\n"
    // "nlines:  %d\n", data->nfields, data->nlines);

  record_T record = recordNew();

  for (int i=0; i<10001; i++)
    recordPush(record, strdup("this"));

  printf("10000| %s\n", recordGet(record, 10000));
}
