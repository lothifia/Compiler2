/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_YACC_H_INCLUDED
# define YY_YY_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    num = 258,
    var = 259,
    CHAR = 260,
    INT = 261,
    Plus = 262,
    Div = 263,
    Minus = 264,
    Mul = 265,
    EQL = 266,
    GEQ = 267,
    LEQ = 268,
    LSS = 269,
    GTR = 270,
    NEQ = 271,
    END = 272,
    LB = 273,
    RB = 274,
    LP = 275,
    RP = 276,
    MAIN = 277,
    SEMI = 278,
    COMMA = 279,
    CONST = 280,
    PROC = 281,
    IF = 282,
    ELSE = 283,
    READ = 284,
    WRITE = 285,
    FOR = 286,
    WHILE = 287,
    LMB = 288,
    RMB = 289
  };
#endif
/* Tokens.  */
#define num 258
#define var 259
#define CHAR 260
#define INT 261
#define Plus 262
#define Div 263
#define Minus 264
#define Mul 265
#define EQL 266
#define GEQ 267
#define LEQ 268
#define LSS 269
#define GTR 270
#define NEQ 271
#define END 272
#define LB 273
#define RB 274
#define LP 275
#define RP 276
#define MAIN 277
#define SEMI 278
#define COMMA 279
#define CONST 280
#define PROC 281
#define IF 282
#define ELSE 283
#define READ 284
#define WRITE 285
#define FOR 286
#define WHILE 287
#define LMB 288
#define RMB 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 88 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 131 "yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */
