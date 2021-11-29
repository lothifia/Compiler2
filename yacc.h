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
    VOID = 262,
    Plus = 263,
    Div = 264,
    Minus = 265,
    Mul = 266,
    EQL = 267,
    GEQ = 268,
    LEQ = 269,
    LSS = 270,
    GTR = 271,
    NEQ = 272,
    END = 273,
    LB = 274,
    RB = 275,
    LP = 276,
    RP = 277,
    MAIN = 278,
    SEMI = 279,
    COMMA = 280,
    CONST = 281,
    PROC = 282,
    IF = 283,
    ELSE = 284,
    READ = 285,
    WRITE = 286,
    FOR = 287,
    WHILE = 288,
    LMB = 289,
    RMB = 290,
    RETURN = 291
  };
#endif
/* Tokens.  */
#define num 258
#define var 259
#define CHAR 260
#define INT 261
#define VOID 262
#define Plus 263
#define Div 264
#define Minus 265
#define Mul 266
#define EQL 267
#define GEQ 268
#define LEQ 269
#define LSS 270
#define GTR 271
#define NEQ 272
#define END 273
#define LB 274
#define RB 275
#define LP 276
#define RP 277
#define MAIN 278
#define SEMI 279
#define COMMA 280
#define CONST 281
#define PROC 282
#define IF 283
#define ELSE 284
#define READ 285
#define WRITE 286
#define FOR 287
#define WHILE 288
#define LMB 289
#define RMB 290
#define RETURN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 98 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 135 "yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */
