/*
 * -----------------------------------------------------------------------------
 * lexer.l
 * -----------------------------------------------------------------------------
 *
 * Copyright (c) 2022 Tyler Wayne
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Flex options:
 * reentrant:       adds yyscan_t *scanner to the yylex prototype
 * bison-bridge:    adds YYSTYPE *yylval_param to the yylex prototype
 * bison-locations: adds YYLTYPE *yyllocp to the yylex prototype
 *
 */

%option noyywrap yylineno nodefault
%option reentrant bison-bridge bison-locations
%option nodefault

%option header-file="lexer.h"

%{
#include <stdio.h>
#include "parser.h"

// #define YY_DECL int yylex(YYSTYPE *yylvalp, yyscan_t scanner)

%}

/* TODO: add start conditions to check quote characters */

%%

[^,\r\n"]*  { yylval_param->str = strdup(yytext); 
              return FIELD; }

,           { return ','; }

\n          { return EOL; }

%%

