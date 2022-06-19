//
// -----------------------------------------------------------------------------
// parser.y
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
// stackoverflow.com/questions/48850242/thread-safe-reentrant-bison-flex
//

%{
#include <stdio.h>  // printf
#include <stdlib.h> // calloc
#include <string.h> // strncpy
#include "parser.h"
// #include "lexer.h"

int yylex(YYSTYPE *yylvalp, YYLTYPE *yyllocp, yyscan_t scanner);
void yyerror(YYLTYPE *yyllocp, yyscan_t unused, const char *msg);

int num_fields;

%}

// %define parse.trace
%define api.pure full 
%locations

%code requires {
  typedef void *yyscan_t;
}

%param { yyscan_t scanner }
// %param {int *num_fields}

%union {
  char *str;
}

%token <str> FIELD
%token EOL

%type <str> field

%%

input:
  record EOL            // *This is the very first record
                        // check if we want to set a header row
                        // add record to headers if so, otherwise add to data
                        { printf("EOL\n"); 
                          num_fields = 0;}

  | input record EOL    { printf("EOL\n"); 
                          num_fields = 0; }
                        // check that field count is correct
                        // add record to outgoing data structure
                        // increase line count
                        // reset field count

  | input error         { yyerrok; }
  ;

record:
  field                 // *This is the very first field
                        { printf("%d:|%s| ", num_fields, $1); }

  | record ',' field    { printf("%d:|%s| ", num_fields, $3); }
  ;

field:
  %empty                { $$ = "";
                          num_fields++; }
                        // check if the value is a header
                        // add the record to the outgoing data structure

  | FIELD               { $$ = $1;
                          num_fields++; }
                        // check if the value is a header
                        // add the record to the outgoing data structure
                        // increase the field count
  ;

%%

