/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "pl0.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    #include<stdbool.h>
    #include "head.h"

    FILE* fin;
    FILE* fresult = NULL;
    FILE* ftable = NULL;
    FILE* fbug = NULL;
    FILE* fpcode = NULL;

    void init();
    void enter(enum object k);
    void _enter(enum object k, int IsArry);
    void setdx(int n);
    void gen(enum fct x, int y, int z);
    void displaytable();
    void listall();
    void interpret();
    int base(int l, int* s, int b);
    void yyerror(const char* s);
    int position(char* a);
    int yylex();
    void redirectInput(FILE *input);
                        char get_void;

#line 101 "yacc.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    STRING = 263,
    Plus = 264,
    Div = 265,
    Minus = 266,
    Mul = 267,
    EQL = 268,
    GEQ = 269,
    LEQ = 270,
    LSS = 271,
    GTR = 272,
    NEQ = 273,
    END = 274,
    LB = 275,
    RB = 276,
    LP = 277,
    RP = 278,
    MAIN = 279,
    SEMI_t = 280,
    COMMA = 281,
    CONST = 282,
    PROC = 283,
    IF = 284,
    ELSE = 285,
    READ = 286,
    WRITE = 287,
    FOR = 288,
    WHILE = 289,
    LMB = 290,
    RMB = 291,
    RETURN = 292,
    PP = 293,
    DD = 294,
    RED = 295
  };
#endif
/* Tokens.  */
#define num 258
#define var 259
#define CHAR 260
#define INT 261
#define VOID 262
#define STRING 263
#define Plus 264
#define Div 265
#define Minus 266
#define Mul 267
#define EQL 268
#define GEQ 269
#define LEQ 270
#define LSS 271
#define GTR 272
#define NEQ 273
#define END 274
#define LB 275
#define RB 276
#define LP 277
#define RP 278
#define MAIN 279
#define SEMI_t 280
#define COMMA 281
#define CONST 282
#define PROC 283
#define IF 284
#define ELSE 285
#define READ 286
#define WRITE 287
#define FOR 288
#define WHILE 289
#define LMB 290
#define RMB 291
#define RETURN 292
#define PP 293
#define DD 294
#define RED 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 239 "yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    55,    48,    71,    71,    71,    76,    89,
      96,    75,   103,   105,   106,   110,   112,   121,   134,   133,
     150,   155,   159,   158,   178,   181,   185,   188,   197,   209,
     210,   213,   214,   217,   226,   233,   242,   243,   246,   247,
     248,   249,   250,   251,   252,   253,   255,   257,   258,   261,
     276,   276,   287,   288,   290,   318,   341,   343,   348,   352,
     358,   346,   368,   368,   372,   373,   376,   380,   375,   389,
     390,   393,   392,   403,   432,   461,   468,   472,   476,   480,
     484,   488,   492,   495,   496,   500,   501,   505,   510,   511,
     515,   519,   524,   543,   547,   548,   552,   551,   567,   568,
     570,   574,   579,   583,   585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "var", "CHAR", "INT", "VOID",
  "STRING", "Plus", "Div", "Minus", "Mul", "EQL", "GEQ", "LEQ", "LSS",
  "GTR", "NEQ", "END", "LB", "RB", "LP", "RP", "MAIN", "SEMI_t", "COMMA",
  "CONST", "PROC", "IF", "ELSE", "READ", "WRITE", "FOR", "WHILE", "LMB",
  "RMB", "RETURN", "PP", "DD", "RED", "$accept", "procstart", "$@1", "$@2",
  "var_t", "defunc", "$@3", "$@4", "$@5", "prevardecl", "prevardef",
  "block", "$@6", "declaration_list", "Vardecl", "$@7", "VarInit",
  "Vardef", "Constdecl", "CONSTInit", "constdef", "var_p", "statements",
  "statement", "asgnstm_semi", "asgnstm_tot", "get_sto", "returnstm",
  "$@8", "compstm", "asgnstm", "callstm", "forstm", "$@9", "$@10", "$@11",
  "for_1", "for_3", "ifstm", "$@12", "$@13", "elsestm", "whilestm", "$@14",
  "readstm", "writestm", "condition", "expression", "term", "factor",
  "call_func", "$@15", "pass_factor", "get_table_addr", "get_code_addr",
  "SEMI", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,     6,  -121,  -121,   109,  -121,  -121,  -121,    27,    16,
    -121,  -121,  -121,  -121,  -121,    22,    31,    95,   109,    40,
      36,  -121,   109,    59,    44,    47,    61,    -3,  -121,  -121,
      50,    76,  -121,    51,  -121,   109,    82,  -121,    40,    69,
      63,    77,   100,   161,   103,   107,   117,  -121,    50,  -121,
    -121,  -121,    94,   106,  -121,  -121,  -121,  -121,  -121,  -121,
     110,   113,   116,   132,   124,  -121,  -121,  -121,  -121,  -121,
      73,   161,   113,  -121,   161,   161,   161,    88,    25,    20,
    -121,  -121,   100,  -121,   115,  -121,   113,   161,   100,   147,
    -121,    76,   121,    95,  -121,   130,   128,   145,  -121,    28,
      20,    20,    32,   146,  -121,   161,   161,   161,  -121,    73,
      73,  -121,   113,   161,  -121,    28,  -121,    25,  -121,   131,
     109,  -121,  -121,   148,  -121,  -121,   161,   161,   161,   161,
     161,   161,  -121,    73,     5,     5,    28,  -121,  -121,  -121,
    -121,   150,  -121,  -121,  -121,  -121,  -121,    28,    28,    28,
      28,    28,    28,   149,   151,   161,  -121,   109,    74,    73,
    -121,  -121,  -121,  -121,    50,  -121,  -121,  -121,  -121,    74,
     155,  -121,   113,  -121,  -121,   141,   100,    74,  -121,   152,
    -121,  -121,   100,   154,  -121,    74,  -121,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
     102,     0,     2,     1,    12,     6,     5,     7,     0,     0,
       8,     3,   101,   101,   102,     0,     0,    21,    15,     0,
       0,    18,    24,     0,     0,    13,     0,   104,    31,     4,
      37,     0,    20,    16,     9,    15,     0,    49,     0,    30,
      34,     0,     0,     0,     0,     0,    56,    19,    37,    38,
      49,    45,     0,    47,    39,    44,    40,    41,    42,    43,
      27,   104,    25,     0,     0,    14,    33,   103,    32,    29,
       0,     0,   104,    93,     0,     0,     0,    92,   104,    85,
      88,    95,    63,   102,     0,    36,   104,     0,     0,     0,
      22,     0,     0,    21,    92,     0,     0,    82,    73,     0,
      83,    84,     0,     0,    74,     0,     0,     0,    75,     0,
       0,    49,   104,     0,    55,    54,    46,   104,    48,     0,
      24,    26,    17,     0,    35,   102,     0,     0,     0,     0,
       0,     0,    94,   100,    86,    87,    91,    90,    89,    62,
     102,     0,    51,    28,    23,    10,    66,    76,    81,    79,
      78,    80,    77,    98,     0,     0,   102,    12,    57,   100,
      97,   102,    71,    11,    37,    52,   102,    99,    58,    57,
       0,    67,   104,    72,    53,    70,     0,    57,    68,    64,
      59,    69,     0,     0,    65,    57,    60,    49,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   -11,    23,  -121,  -121,  -121,   144,
    -121,    89,  -121,  -121,    64,  -121,    90,  -121,   153,  -121,
     156,   -30,   -44,   -28,  -121,   -63,   -47,  -121,  -121,   -36,
    -120,  -121,  -121,  -121,  -121,  -121,  -121,     4,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -104,   -38,   -46,   -62,
    -121,  -121,    29,   174,   -13,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,    13,     8,     9,    12,    64,   157,    24,
      25,    20,    30,    21,    32,   120,    61,    62,    22,    27,
      28,    94,    47,   165,    49,    50,    67,    51,    52,   166,
      53,    54,    55,   172,   183,   187,   112,   180,    56,   158,
     175,   178,    57,   169,    58,    59,    96,    99,    79,    80,
      81,   103,   154,    14,     2,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    16,    48,    86,    85,    78,     3,    23,    95,   141,
      90,    31,    72,    77,   -85,   109,   -85,   110,    46,   111,
      48,    98,    37,    38,    23,   118,   104,   108,   100,   101,
     109,    10,   110,    97,   105,   116,   106,   105,   102,   106,
      11,   105,    17,   106,    26,   -85,   115,   137,   138,   117,
      37,   161,    46,    18,    40,   132,   179,    29,    46,   134,
     135,   140,   179,    33,   139,   107,   142,    34,   107,   136,
     113,   153,   107,    35,    36,    97,    73,    40,    40,    41,
      60,    42,    43,    44,    45,    66,    63,   -50,   147,   148,
     149,   150,   151,   152,   164,    76,    19,   153,    70,    71,
     -30,   -30,   -30,    41,    40,    42,    43,    44,    45,    31,
     -96,   -50,   146,    37,     5,     6,     7,    97,    73,    40,
     170,   176,    19,   114,    74,    82,    75,   155,    46,    83,
      84,    87,    88,   173,    46,    92,    48,    76,    37,    46,
     188,   181,    91,   162,    93,    89,    46,    46,   168,   186,
     119,   125,    46,   171,   105,    46,   106,   122,   126,   127,
     128,   129,   130,   131,    73,    40,   124,   143,   133,   145,
      74,   177,    75,   156,   160,   159,   174,   185,   182,    65,
     163,   121,   123,    76,   144,   107,   184,    15,   167,     0,
       0,     0,    69,     0,    68
};

static const yytype_int16 yycheck[] =
{
      30,    14,    30,    50,    48,    43,     0,    18,    70,   113,
      61,    22,    42,    43,     9,    10,    11,    12,    48,    82,
      48,    72,    25,    26,    35,    88,    77,    78,    74,    75,
      10,     4,    12,    71,     9,    86,    11,     9,    76,    11,
      24,     9,    20,    11,     4,    40,    84,   109,   110,    87,
      25,   155,    82,    22,     4,    23,   176,    21,    88,   105,
     106,   112,   182,     4,   111,    40,   117,    23,    40,   107,
      83,   133,    40,    26,    13,   113,     3,     4,     4,    29,
       4,    31,    32,    33,    34,     3,    35,    37,   126,   127,
     128,   129,   130,   131,    20,    22,    27,   159,    35,    22,
       5,     6,     7,    29,     4,    31,    32,    33,    34,   120,
      22,    37,   125,    25,     5,     6,     7,   155,     3,     4,
     164,   172,    27,     8,     9,    22,    11,   140,   158,    22,
      13,    37,    26,   169,   164,     3,   164,    22,    25,   169,
     187,   177,    26,   156,    20,    35,   176,   177,   161,   185,
       3,    23,   182,   166,     9,   185,    11,    36,    13,    14,
      15,    16,    17,    18,     3,     4,    36,    36,    22,    21,
       9,    30,    11,    23,    23,    26,    21,    23,    26,    35,
     157,    91,    93,    22,   120,    40,   182,    13,   159,    -1,
      -1,    -1,    39,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    95,     0,    43,     5,     6,     7,    45,    46,
       4,    24,    47,    44,    94,    94,    95,    20,    22,    27,
      52,    54,    59,    45,    50,    51,     4,    60,    61,    21,
      53,    45,    55,     4,    23,    26,    13,    25,    26,    96,
       4,    29,    31,    32,    33,    34,    62,    63,    64,    65,
      66,    68,    69,    71,    72,    73,    79,    83,    85,    86,
       4,    57,    58,    35,    48,    50,     3,    67,    61,    59,
      35,    22,    62,     3,     9,    11,    22,    62,    88,    89,
      90,    91,    22,    22,    13,    63,    67,    37,    26,    35,
      96,    26,     3,    20,    62,    90,    87,    88,    96,    88,
      89,    89,    88,    92,    96,     9,    11,    40,    96,    10,
      12,    66,    77,    95,     8,    88,    96,    88,    66,     3,
      56,    57,    36,    52,    36,    23,    13,    14,    15,    16,
      17,    18,    23,    22,    89,    89,    88,    90,    90,    67,
      96,    87,    96,    36,    55,    21,    95,    88,    88,    88,
      88,    88,    88,    90,    93,    95,    23,    49,    80,    26,
      23,    87,    95,    46,    20,    64,    70,    93,    95,    84,
      63,    95,    74,    70,    21,    81,    96,    30,    82,    71,
      78,    70,    26,    75,    78,    23,    70,    76,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    44,    42,    45,    45,    45,    47,    48,
      49,    46,    46,    50,    50,    50,    51,    51,    53,    52,
      54,    54,    56,    55,    55,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    66,    67,
      69,    68,    70,    70,    71,    71,    71,    72,    74,    75,
      76,    73,    77,    77,    78,    78,    80,    81,    79,    82,
      82,    84,    83,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    90,    90,    90,    90,    92,    91,    93,    93,
      93,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     9,     1,     1,     1,     0,     0,
       0,    14,     0,     1,     3,     0,     2,     5,     0,     3,
       2,     0,     0,     5,     0,     1,     3,     1,     4,     4,
       0,     1,     3,     3,     1,     4,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     0,
       0,     4,     1,     3,     3,     3,     1,     0,     0,     0,
       0,    15,     2,     0,     1,     3,     0,     0,    10,     2,
       0,     0,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     1,     0,     5,     1,     3,
       0,     0,     0,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 49 "pl0.y"
    {
        preVar_cnt = 0;
        gen(jmp, 0, 0);
    }
#line 1556 "yacc.c"
    break;

  case 3:
#line 55 "pl0.y"
    {
        /* Main procedure */
        strcpy(id, "main");
        _enter(procedure, 0);
        table[tx].adr = cx;
        table[tx].t = xvoid;
        code[(yyvsp[-3].NUM)].a = cx;
        proctable[px] = tx;

    }
#line 1571 "yacc.c"
    break;

  case 4:
#line 66 "pl0.y"
    {
        table[(yyvsp[-3].NUM)].size =  preVar_cnt;
    }
#line 1579 "yacc.c"
    break;

  case 5:
#line 71 "pl0.y"
           {(yyval.NUM) = 1;}
#line 1585 "yacc.c"
    break;

  case 6:
#line 71 "pl0.y"
                           {(yyval.NUM) = 2;}
#line 1591 "yacc.c"
    break;

  case 7:
#line 71 "pl0.y"
                                           {(yyval.NUM) = 3;}
#line 1597 "yacc.c"
    break;

  case 8:
#line 76 "pl0.y"
    {
        strcpy(id, (yyvsp[0].VAR));
        _enter(procedure, 0);
        if((yyvsp[-1].NUM) == 1){
            table[tx].t = xint;
        }else if((yyvsp[-1].NUM) == 2){
            table[tx].t = xchar;
        }else if((yyvsp[-1].NUM) == 3){
            table[tx].t = xvoid;
        }
        proc_p = tx;
    }
#line 1614 "yacc.c"
    break;

  case 9:
#line 89 "pl0.y"
    {
        table[(yyvsp[-4].NUM)].adr = (yyvsp[-3].NUM);
        table[(yyvsp[-4].NUM)].parameter_cnt = (yyvsp[-1].NUM);
        printf("pcnt = %d, table addr is %d\n", (yyvsp[-1].NUM), (yyvsp[-3].NUM));
        preVar_cnt = (yyvsp[-1].NUM);
    }
#line 1625 "yacc.c"
    break;

  case 10:
#line 96 "pl0.y"
    {
        table[(yyvsp[-8].NUM)].size = preVar_cnt;
        preVar_cnt = 0;
        total_var = 0;
        proc_p = 0;
    }
#line 1636 "yacc.c"
    break;

  case 13:
#line 105 "pl0.y"
                      { (yyval.NUM) = (yyvsp[0].NUM) ; }
#line 1642 "yacc.c"
    break;

  case 14:
#line 107 "pl0.y"
    {
        (yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);
    }
#line 1650 "yacc.c"
    break;

  case 15:
#line 110 "pl0.y"
      { (yyval.NUM) = 0 ;}
#line 1656 "yacc.c"
    break;

  case 16:
#line 113 "pl0.y"
    {
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        if((yyvsp[-1].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-1].NUM) == 2) table[tx].t = xchar;
        total_var ++;
        (yyval.NUM) = 1;
    }
#line 1669 "yacc.c"
    break;

  case 17:
#line 122 "pl0.y"
    {
        (yyval.NUM) = 1;
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        if((yyvsp[-4].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-4].NUM) == 2) table[tx].t = xchar;
        total_var += (yyvsp[-1].NUM);
        (yyval.NUM) = 1;
    }
#line 1683 "yacc.c"
    break;

  case 18:
#line 134 "pl0.y"
    {
        setdx((yyvsp[0].NUM) + preVar_cnt);
        gen(ini, 0, total_var + 3);
        for(int i = 0; i < preVar_cnt; i++){
            gen(sto, -1 - i , 2 + preVar_cnt - i);
        }
        
    }
#line 1696 "yacc.c"
    break;

  case 19:
#line 143 "pl0.y"
    {
        gen(opr, preVar_cnt, 0);
        preVar_cnt = (yyvsp[-2].NUM) + preVar_cnt;
    }
#line 1705 "yacc.c"
    break;

  case 20:
#line 151 "pl0.y"
    {
        printf("total_var: %d\n",total_var);
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1714 "yacc.c"
    break;

  case 21:
#line 155 "pl0.y"
     {(yyval.NUM) = 0 ;}
#line 1720 "yacc.c"
    break;

  case 22:
#line 159 "pl0.y"
     {
         if((yyvsp[-2].NUM) == 1){
         while(varx > 0){
             table[vartable[varx - 1]].t = xint;
             --varx;
         }
         }
         else{
             while(varx > 0){
                 table[vartable[varx - 1]].t = xchar;
                 --varx;
             }
         }
     }
#line 1739 "yacc.c"
    break;

  case 23:
#line 174 "pl0.y"
    {
        printf("2: %d, 5: %d\n", (yyvsp[-3].NUM), (yyvsp[0].NUM));
        (yyval.NUM) = (yyvsp[-3].NUM) + (yyvsp[0].NUM);
    }
#line 1748 "yacc.c"
    break;

  case 24:
#line 178 "pl0.y"
      {(yyval.NUM) = 0;}
#line 1754 "yacc.c"
    break;

  case 25:
#line 182 "pl0.y"
    { 
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1762 "yacc.c"
    break;

  case 26:
#line 185 "pl0.y"
                           {(yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);}
#line 1768 "yacc.c"
    break;

  case 27:
#line 189 "pl0.y"
    {
        ++total_var;
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        (yyval.NUM) = 1;
        vartable[varx] = tx;
        ++varx;
    }
#line 1781 "yacc.c"
    break;

  case 28:
#line 198 "pl0.y"
    {
        total_var += (yyvsp[-1].NUM);
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        (yyval.NUM) = 1;

        vartable[varx] = tx;
        ++varx;
    }
#line 1795 "yacc.c"
    break;

  case 33:
#line 218 "pl0.y"
    {
        strcpy(id, (yyvsp[-2].VAR));
        c_num = (yyvsp[0].NUM);
        _enter(constant, 0);
    }
#line 1805 "yacc.c"
    break;

  case 34:
#line 227 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[0].VAR));
        if(table[(yyval.NUM)].t == xchar && table[(yyval.NUM)].is_arry) isString = 1;

    }
#line 1816 "yacc.c"
    break;

  case 35:
#line 234 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[-3].VAR));
        gen(lit, 0, table[(yyval.NUM)].adr);
        gen(lit, 0, lev - table[(yyval.NUM)].level);
    }
#line 1827 "yacc.c"
    break;

  case 49:
#line 261 "pl0.y"
    {
        while(forx > for_var)
        {
            if(table[fortable[forx - 1]].is_arry){
                gen(sto, 0, 0);
                --forx;
            }else{
                gen(sto, lev - table[fortable[forx - 1]].level, table[fortable[forx - 1]].adr);
                --forx;
            }
        }
    }
#line 1844 "yacc.c"
    break;

  case 50:
#line 276 "pl0.y"
    {
        if(table[proc_p].t == xvoid) yyerror("error void cannot return\n");
    }
#line 1852 "yacc.c"
    break;

  case 51:
#line 281 "pl0.y"
    {
        gen(sto, -1, 0);
        gen(opr, preVar_cnt, 0);
        --px;
    }
#line 1862 "yacc.c"
    break;

  case 54:
#line 292 "pl0.y"
    {
        /*
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else{
                if(table[$1].is_arry == 0) {gen(sto, lev - table[$1].level, table[$1].adr);}
                else{
                    gen(sto, 0, 0);
                }
            }
        }
        */
        if((yyvsp[-2].NUM) == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[(yyvsp[-2].NUM)].kind != variable) yyerror("Symbol not variable\n");
            else{
                fortable[forx] = (yyvsp[-2].NUM);
                ++forx;
            }
        }
    }
#line 1893 "yacc.c"
    break;

  case 55:
#line 319 "pl0.y"
    {
        strcpy(temstr, (yyvsp[0].VAR));
        printf("-----------qweqwcasdasdasd---------------: %c  \n", temstr[0]);
        if(isString)
        {
            int teml = table[(yyvsp[-2].NUM)].is_arry;
            for(int i = 0; i < teml; i++){
                gen(lit, 0 , i);
                gen(lit, 0, table[(yyvsp[-2].NUM)].adr);
                gen(lit, 0, lev - table[(yyvsp[-2].NUM)].level);
                gen(lit, 0, temstr[i]);
                fortable[forx] = (yyvsp[-2].NUM);
                ++forx;
            }
        } else{
        printf("-----------qweqwcasdasdasd---------------: %c  \n", temstr[0]);
            if(strlen(temstr) > 1) yyerror("not a char\n");
            gen(lit, 0, temstr[0]);
            fortable[forx] = (yyvsp[-2].NUM);
            ++forx;
        }
    }
#line 1920 "yacc.c"
    break;

  case 58:
#line 348 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 1928 "yacc.c"
    break;

  case 59:
#line 352 "pl0.y"
    {
        for_var += (yyvsp[0].NUM);
        for_lev[for_lx] = (yyvsp[0].NUM);
        ++for_lx;
    }
#line 1938 "yacc.c"
    break;

  case 60:
#line 358 "pl0.y"
    {
        for_var -= for_lev[--for_lx];
    }
#line 1946 "yacc.c"
    break;

  case 61:
#line 362 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-10].NUM));
        printf("jpc = %d\n", (yyvsp[-8].NUM));
        code[(yyvsp[-8].NUM)].a = cx;
    }
#line 1956 "yacc.c"
    break;

  case 64:
#line 372 "pl0.y"
                { (yyval.NUM) = 1; }
#line 1962 "yacc.c"
    break;

  case 65:
#line 373 "pl0.y"
                            {(yyval.NUM) = 1 + (yyvsp[0].NUM);}
#line 1968 "yacc.c"
    break;

  case 66:
#line 376 "pl0.y"
    {
        gen(jpc,0,0);
    }
#line 1976 "yacc.c"
    break;

  case 67:
#line 380 "pl0.y"
    {
        gen(jmp, 0, 0);
        code[(yyvsp[-3].NUM)].a = cx;
    }
#line 1985 "yacc.c"
    break;

  case 68:
#line 385 "pl0.y"
    {
        code[(yyvsp[-2].NUM)].a = cx;
    }
#line 1993 "yacc.c"
    break;

  case 71:
#line 393 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 2001 "yacc.c"
    break;

  case 72:
#line 397 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-5].NUM));
        printf("now cx: %d----------------------------------------", cx);
       code[(yyvsp[-2].NUM)].a = cx;
    }
#line 2011 "yacc.c"
    break;

  case 73:
#line 404 "pl0.y"
    {
        if(table[(yyvsp[-1].NUM)].is_arry == 0){
            if(table[(yyvsp[-1].NUM)].t == xchar){
                gen(opr, -1, 16);
                gen(sto, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr);
            }else{
            gen(opr, 0, 16);
            gen(sto, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr);
            }
        }else {
            if(isString == 0) {
                gen(opr, 0, 16);
                gen(sto, 0, 0);
            }
            else{
                gen(opr, table[(yyvsp[-1].NUM)].is_arry, 16);
                printf("is_arry = %d \n" , table[(yyvsp[-1].NUM)].is_arry);
                for(int i = 0; i < table[(yyvsp[-1].NUM)].is_arry; i++)
                {
                    gen(lit, 0, i);
                    gen(lit, 0, table[(yyvsp[-1].NUM)].adr);
                    gen(lit, 0, lev - table[(yyvsp[-1].NUM)].level);
                    gen(sto, table[(yyvsp[-1].NUM)].is_arry, 0);
                }
            }
        }
    }
#line 2043 "yacc.c"
    break;

  case 74:
#line 433 "pl0.y"
    {
        if(table[(yyvsp[-1].NUM)].is_arry == 0 && table[(yyvsp[-1].NUM)].t != xchar){
            gen(lod, lev - table[(yyvsp[-1].NUM)].level,table[(yyvsp[-1].NUM)].adr);
            gen(opr, 0, 14);   
            gen(opr, 0, 15);
        }else if(table[(yyvsp[-1].NUM)].is_arry == 0 && table[(yyvsp[-1].NUM)].t == xchar){
            gen(lod, lev - table[(yyvsp[-1].NUM)].level,table[(yyvsp[-1].NUM)].adr);
            gen(opr, -1, 14);   
            gen(opr, 0, 15);
        }
        else{
            if(isString == 0 && table[(yyvsp[-1].NUM)].t == xchar){
                printf("asdfhoasdgjlasdkjglasdjfl");
                gen(lod, 0, 0);
                gen(opr, -1, 14);   
                gen(opr, 0, 15);
            }else if(isString == 0 && table[(yyvsp[-1].NUM)].t == xint){
                gen(lod, 0, 0);
                gen(opr, 0, 14);
                gen(opr, 0, 15);
            }else{
                for(int i =0; i < table[(yyvsp[-1].NUM)].is_arry; i++){
                    gen(lod, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr + i);
                }
                gen(opr, table[(yyvsp[-1].NUM)].is_arry, 14);
            }
        }
    }
#line 2076 "yacc.c"
    break;

  case 75:
#line 462 "pl0.y"
    {
        gen(opr, 0, 14);
        gen(opr, 0, 15);
    }
#line 2085 "yacc.c"
    break;

  case 76:
#line 469 "pl0.y"
            {
                gen(opr, 0, 8);
            }
#line 2093 "yacc.c"
    break;

  case 77:
#line 473 "pl0.y"
            {
                gen(opr, 0, 9);
            }
#line 2101 "yacc.c"
    break;

  case 78:
#line 477 "pl0.y"
            {
                gen(opr, 0, 10);
            }
#line 2109 "yacc.c"
    break;

  case 79:
#line 481 "pl0.y"
            {
                gen(opr, 0, 13);
            }
#line 2117 "yacc.c"
    break;

  case 80:
#line 485 "pl0.y"
            {
                gen(opr, 0, 12);
            }
#line 2125 "yacc.c"
    break;

  case 81:
#line 489 "pl0.y"
            {
                gen(opr, 0, 11);
            }
#line 2133 "yacc.c"
    break;

  case 84:
#line 497 "pl0.y"
    {
        gen(opr, 0, 1);
    }
#line 2141 "yacc.c"
    break;

  case 86:
#line 502 "pl0.y"
    {
        gen(opr, 0, 2);
    }
#line 2149 "yacc.c"
    break;

  case 87:
#line 506 "pl0.y"
    {
        gen(opr, 0, 3);
    }
#line 2157 "yacc.c"
    break;

  case 89:
#line 512 "pl0.y"
    {
        gen(opr, 0, 4);
    }
#line 2165 "yacc.c"
    break;

  case 90:
#line 516 "pl0.y"
    {
        gen(opr, 0 , 5);
    }
#line 2173 "yacc.c"
    break;

  case 91:
#line 520 "pl0.y"
        {
            gen(opr, 0, 17);
        }
#line 2181 "yacc.c"
    break;

  case 92:
#line 525 "pl0.y"
    {
        if((yyvsp[0].NUM) == 0) yyerror("Symbol not found \n");
        else{
            if(table[(yyvsp[0].NUM)].kind == procedure) yyerror("procedure can not be variable\n");
            else{
                if(table[(yyvsp[0].NUM)].kind == constant) gen(lit, 0, table[(yyvsp[0].NUM)].val);
                else{
                    if(table[(yyvsp[0].NUM)].is_arry){
                        printf("$1 is :%d, \n", (yyvsp[0].NUM));
                        gen(lod, 0, 0);
                    }else{
                        printf("name %s, adr %d", table[(yyvsp[0].NUM)].name, table[(yyvsp[0].NUM)].adr);
                        gen(lod, lev - table[(yyvsp[0].NUM)].level, table[(yyvsp[0].NUM)].adr);
                    }
                }
            }
        }
    }
#line 2204 "yacc.c"
    break;

  case 93:
#line 544 "pl0.y"
    {
        gen(lit, 0, (yyvsp[0].NUM));
    }
#line 2212 "yacc.c"
    break;

  case 96:
#line 552 "pl0.y"
    {
        ++px;
        proctable[px] = (yyvsp[0].NUM);
    }
#line 2221 "yacc.c"
    break;

  case 97:
#line 557 "pl0.y"
    {
        if(table[(yyvsp[-4].NUM)].kind != procedure) yyerror("Is  not a procedure \n");
        else{
            if((yyvsp[-1].NUM) !=  table[(yyvsp[-4].NUM)].parameter_cnt ) yyerror("parameter number not match\n");
            gen(cal, 0, table[(yyvsp[-4].NUM)].adr);
            if(table[(yyvsp[-4].NUM)].t != xvoid) gen(lod, -1, 0); /* get return */
        }
    }
#line 2234 "yacc.c"
    break;

  case 98:
#line 567 "pl0.y"
                    {(yyval.NUM) = 1;}
#line 2240 "yacc.c"
    break;

  case 99:
#line 569 "pl0.y"
        {(yyval.NUM) = 1 + (yyvsp[0].NUM);}
#line 2246 "yacc.c"
    break;

  case 100:
#line 570 "pl0.y"
      {(yyval.NUM) = 0;}
#line 2252 "yacc.c"
    break;

  case 101:
#line 574 "pl0.y"
    {
        (yyval.NUM) = tx;
    }
#line 2260 "yacc.c"
    break;

  case 102:
#line 579 "pl0.y"
    {
        (yyval.NUM) = cx;
    }
#line 2268 "yacc.c"
    break;

  case 104:
#line 585 "pl0.y"
    {
        yyerror("miss a SEMICOM");
    }
#line 2276 "yacc.c"
    break;


#line 2280 "yacc.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 588 "pl0.y"


void yyerror(const char* s){
    fprintf(fbug,"error!:%s , located at %d line\n", s, line);
}
void init()
{
	tx = 0;
	cx = 0;
	px = 0;
    forx = 0;
    varx = 0;
    lev = 0;   
    proctable[0] = 0;
    c_num = 0;
    err = 0;
    total_var = 0;
    for_var = 0;
    for_lx = 0;
    offset = 0;
}
int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = tx;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void _enter(enum object k, int IsArry)
{
    enter(k);
    table[tx].is_arry = IsArry;
}
void enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case constant:	/* 常量 */			
			table[tx].val = c_num; /* 登记常数的值 */
			break;
		case variable:	/* 变量 */
			table[tx].level = lev;	
			break;
		case procedure:	/* 过程 */
			table[tx].level = lev;
			break;
	}
}
void setdx(int n)
{
    printf("---------------%d\n", n);
    int addr = 3 + total_var;
    for(int i = 1; i <= n; i++){
        if(table[tx - i + 1].is_arry){
            addr -= table[tx - i + 1].is_arry;
        }else{
            addr -= 1;
        }
        table[tx - i + 1].adr = addr;
    }
}

void gen(enum fct x, int y, int z)
{
	if (cx >= cxmax)
	{
		printf("Program is too long!\n");	/* 生成的虚拟机代码程序过长 */
		exit(1);
	}
	if ( z >= amax)
	{
		printf("Displacement address is too big!\n");	/* 地址偏移越界 */
		exit(1);
	}
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx++;
}
void listall()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},
	};
	
    for (i = 0; i < cx; i++)
    {
        printf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        fprintf(fpcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);

        
    }
}

void displaytable()
{
	int i;
    /* 输出符号表 */
	printf("tx : %d\n", tx);
	for (i = 1; i <= tx; i++)
		{
            printf("kind : %d\n", table[i].kind);         
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val);
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d ", table[i].level, table[i].adr);
                    if(table[i].t == xint) printf("type = int \n");
                    else printf("type = char \n");
					fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					break;
			}
		}
		printf("\n");
		fprintf(ftable, "\n");
}
void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;	/* 存放当前指令 */
	int s[stacksize];	/* 栈 */

	printf("Start pl0\n");
	fprintf(fresult,"Start pl0\n");
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;

	do {
	    i = code[p];	/* 读当前指令 */
		p = p + 1;
		switch (i.f)
		{
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        t -= i.l;
                        printf("return to t: %d p: %d b: %d \n *******\n", t, p, b);
						break;
					case 1: /* 栈顶元素取反 */
						s[t] = - s[t];
						break;
					case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* 次栈顶项减去栈顶项 */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* 次栈顶项乘以栈顶项 */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* 次栈顶项除以栈顶项 */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* 栈顶元素的奇偶判断 */
						s[t] = s[t] % 2;
						break;
					case 8:/* 次栈顶项与栈顶项是否相等 */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* 次栈顶项与栈顶项是否不等 */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* 次栈顶项是否小于栈顶项 */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* 次栈顶项是否大于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* 次栈顶项是否大于栈顶项 */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* 次栈顶项是否小于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* 栈顶值输出 */
                        if(i.l == 0){
                            printf("%d", s[t]);
                            fprintf(fresult, "%d", s[t]);
                            t = t - 1;
                        }else if(i.l > 0){
                            memset(buffer, 0, sizeof(buffer));
                            for(int ii = 0; ii < i.l; ii++){
                                printf("t is %d s[t]: %d \n", t ,s[t]);
                                buffer[i.l - ii - 1] = s[t];
                                t = t - 1;
                            }
                            printf("here output %s\n", buffer);
                        }else if(i.l == -1){
                            
                            char c = s[t];
                            t = t - 1;
                            printf("%c", c);
                        }
						break;
					case 15:/* 输出换行符 */
						printf("\n");
					    fprintf(fresult,"\n"); 
						break;
					case 16:/* 读入一个输入置于栈顶 */
                        if(i.l == 0){
                            t = t + 1;
                            printf("?");
                            /* fprintf(fresult, "?"); */
                            scanf("%d", &(s[t]));
                            /* fprintf(fresult, "%d\n", s[t]); */						
                        }else if(i.l < 0){
                            t = t + 1;
                            printf("?");
                            scanf("%c", &(s[t]));
                        }else{
                            printf("? (need a string)");
                            scanf("%s", buffer);
                            printf("i.l %d, t %d \n", i.l, t);
                            for(int cnt_i = 0; cnt_i < i.l; cnt_i++){
                                printf("t %d, buffer %d \n", t, buffer[cnt_i]);
                                t = t + 1;
                                s[t] = buffer[cnt_i];
                            }
                        }
                        getchar();
                        break;
                    case 17:
                        t = t - 1;
                        s[t] = s[t] % s[t + 1];

						break;
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
                if(i.l < 0){
                    t = t + 1;
                    s[t] = s[0];
                }
                else if(i.l == 0 && i.a == 0){
                    s[t - 2] = s[base(s[t],s, b) + s[t - 1] + s[t - 2]];
                    t = t - 2;
                }else if(i.l >0 && i.a > 0){
                    t = t + 1;
                    s[t] = s[base(i.l, s, b) + i.a];
                }else{
				    t = t + 1;
				    s[t] = s[base(i.l,s,b) + i.a];				
                }
                    /* printf("t is %d,lod at : %d  + %d ,%d \n",t ,base(i.l, s, b), i.a, s[base(i.l, s,b) + i.a]); */
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
                if(i.l < 0 && i.a != 0){
                    s[b + i.a] = s[b + i.l];   
                }else if(i.l < 0 && i.a == 0){
                    s[0] = s[t];
                }else if(i.l == 0 && i.a == 0){
                    s[base(s[t - 1], s, b) + s[t - 2] + s[t - 3]] = s[t];
                    t = t - 4;
                }else if(i.l > 0 && i.a == 0){
                    s[base(s[t], s, b) + s[t - 1] + s[t - 2]] = s[t - 2 - i.l + s[t - 2]];
                    printf("t is %d,sto at : %d,  %d , %d \n",
                            t,
                            base(s[t], s, b) + s[t - 1] + s[t - 2],
                            s[t - 2],
                            s[t - 2 - i.l + s[t - 2]]);
                    t = t - 3;
                }else{
				    s[base(i.l, s, b) + i.a] = s[t];
				    t = t - 1;
                }
                    /* printf("t is %d,sto at : %d  + %d , %d \n",t ,base(i.l, s, b), i.a, s[b  + i.a]); */
				break;
			case cal:	/* 调用子过程 */
                printf("now call , t at %d\n", t);
				s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
                printf("t: %d p: %d b: %d \n *******\n", t, p, b);
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
                printf("ini t is %d\n", t);
				break;
			case jmp:	/* 直接跳转 */
				p = i.a;
				break;
			case jpc:	/* 条件跳转 */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End pl0\n");
	fprintf(fresult,"End pl0\n");
}
int base(int l, int* s, int b)
{
    int bl;
    bl = b;
    while(l > 0){
        bl = s[bl];
        l--;
    }
    return bl;
}

int main(){
    line = 0;
    printf("Input file        ");
    scanf("%s", fname);
    getchar();
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    if ((fresult = fopen("fresult.txt", "w")) == NULL)
    {
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
	if ((fpcode = fopen("fpcode.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
	if ((fbug = fopen("fbug.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
    
    redirectInput(fin);
    init();
    yyparse();
    displaytable();
    listall();
    interpret();

    fclose(fin);
    fclose(ftable);
    fclose(fresult);
    fclose(fpcode);
    fclose(fbug);

    return 0;
}
