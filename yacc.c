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

    #define al 10
    #define cxmax 2000
    #define txmax 1000
    #define amax 2048
    #define strmax 20000
    #define stacksize 3000

    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    #include<stdbool.h>
    FILE* fin;
    FILE* fresult = NULL;
    FILE* ftable = NULL;
    FILE* fbug = NULL;
    FILE* fpcode = NULL;
    char fname[al];
    
    int tx;/*table */
    int cx;/* code*/
    int px;/*proctable*/
    int lev;
    int proctable[3];
    char id[al];
    extern int line;
    int err;
    int c_num;/* use to record const */
    int fortable[cxmax];
    int forx;

    int for_var;
    int for_lev[10];
    int for_lx;

    int vartable[cxmax];
    int  varx;
    int total_var;
    int tem;
    int offset;
    int preVar;
    int preVar_cnt;
    int proc_p;
    int pass_cnt;
    int isString;
    char buffer[strmax];
    char temstr[strmax];

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     
    };
    struct instruction
    {
        enum fct f;   /* 虚拟机代码指令 */
        int l;        /* 引用层与声明层的层次差 */
        int a;        /* 根据f的不同而不同 */
    };
    struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */
    enum object 
    {
        constant, 
        variable, 
        procedure,
    };
    enum type
    {
        xint,
        xchar,
        xvoid
    };

    /* 符号表结构 */
    struct tablestruct
    {
    char name[al];      /* 名字 */
    enum object kind;   /* 类型：const，var或procedure */
    int val;            /* 数值，仅const使用 */
        int level;          /* 所处层，仅const不使用 */ 
        int adr;            /* 地址，仅const不使用 */
        int size;           /* 需要分配的数据区空间, 仅procedure使用 */
    enum type t; /* type */
    int is_arry;
    int parameter_cnt;
    };
    struct tablestruct table[txmax]; /* 符号表 */


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

#line 177 "yacc.c"

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
    SEMI = 280,
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
    RETURN = 292
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
#define SEMI 280
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 107 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 309 "yacc.c"

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
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   131,   124,   144,   144,   144,   149,   162,
     169,   148,   175,   177,   178,   182,   184,   193,   206,   205,
     221,   226,   230,   229,   249,   252,   256,   259,   268,   280,
     281,   284,   285,   288,   297,   304,   313,   314,   317,   318,
     319,   320,   321,   322,   323,   324,   326,   328,   329,   332,
     347,   347,   358,   359,   361,   389,   413,   418,   422,   428,
     416,   438,   438,   442,   443,   446,   445,   454,   453,   463,
     487,   517,   521,   525,   529,   533,   537,   541,   544,   545,
     549,   550,   554,   559,   560,   564,   569,   588,   592,   593,
     597,   596,   612,   613,   615,   619,   624
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "var", "CHAR", "INT", "VOID",
  "STRING", "Plus", "Div", "Minus", "Mul", "EQL", "GEQ", "LEQ", "LSS",
  "GTR", "NEQ", "END", "LB", "RB", "LP", "RP", "MAIN", "SEMI", "COMMA",
  "CONST", "PROC", "IF", "ELSE", "READ", "WRITE", "FOR", "WHILE", "LMB",
  "RMB", "RETURN", "$accept", "procstart", "$@1", "$@2", "var_t", "defunc",
  "$@3", "$@4", "$@5", "prevardecl", "prevardef", "block", "$@6",
  "declaration_list", "Vardecl", "$@7", "VarInit", "Vardef", "Constdecl",
  "CONSTInit", "constdef", "var_p", "statements", "statement",
  "asgnstm_semi", "asgnstm_tot", "get_sto", "returnstm", "$@8", "compstm",
  "asgnstm", "callstm", "forstm", "$@9", "$@10", "$@11", "for_1", "for_3",
  "ifstm", "$@12", "whilestm", "$@13", "readstm", "writestm", "condition",
  "expression", "term", "factor", "call_func", "$@14", "pass_factor",
  "get_table_addr", "get_code_addr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -146,    15,  -146,  -146,    44,  -146,  -146,  -146,    20,    10,
    -146,  -146,  -146,    24,  -146,    16,    18,    55,    32,  -146,
      44,    44,    56,    54,  -146,  -146,     4,    73,  -146,    77,
      72,    71,    97,    74,    55,    68,    80,   100,   100,    85,
      86,    92,  -146,     4,  -146,  -146,  -146,    75,    84,  -146,
    -146,  -146,  -146,  -146,  -146,    81,    99,   101,    90,  -146,
      44,  -146,  -146,  -146,     6,    87,   103,   105,   100,  -146,
      67,  -146,   106,     6,   100,   123,  -146,    73,   131,   115,
    -146,  -146,    87,   114,   102,  -146,     6,     6,   116,   104,
      42,  -146,  -146,  -146,  -146,   117,    87,  -146,    49,  -146,
     119,  -146,   109,    44,  -146,   111,    16,    83,   126,  -146,
      42,    42,  -146,     6,     6,    87,    87,    87,    87,    87,
      87,     6,     6,  -146,  -146,   118,  -146,  -146,  -146,  -146,
     128,  -146,     6,  -146,    42,    42,    49,    49,    49,    49,
      49,    49,  -146,  -146,    87,  -146,  -146,   124,   129,    53,
    -146,  -146,    44,     6,  -146,     4,  -146,  -146,  -146,    53,
    -146,  -146,   130,   132,  -146,  -146,   100,   127,  -146,   100,
     133,  -146,    53,  -146,  -146,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      96,     0,     2,     1,    12,     6,     5,     7,     0,     0,
       8,     3,    95,     0,    96,    21,     0,     0,     0,    18,
      24,    15,     0,     0,    31,     4,    37,     0,    20,     0,
       0,    13,     0,    30,     0,    34,     0,     0,     0,     0,
       0,     0,    19,    37,    38,    49,    45,     0,    47,    39,
      44,    40,    41,    42,    43,    27,     0,    25,    16,     9,
      15,    33,    29,    32,     0,     0,     0,     0,    62,    96,
       0,    36,     0,     0,     0,     0,    22,     0,     0,     0,
      14,    87,     0,    86,     0,    89,     0,     0,     0,    77,
      80,    83,    69,    70,    49,     0,     0,    55,    54,    46,
       0,    48,     0,    24,    26,     0,    21,     0,     0,    35,
      78,    79,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    96,     0,    51,    28,    23,    17,
       0,    88,    94,    65,    81,    82,    71,    76,    74,    73,
      75,    72,    85,    84,     0,    96,    10,    92,     0,    50,
      96,    67,    12,    94,    91,    37,    52,    66,    57,    50,
      11,    93,     0,     0,    68,    53,     0,    63,    58,     0,
       0,    64,    50,    59,    49,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,   -15,     2,  -146,  -146,  -146,    95,
    -146,    52,  -146,  -146,    57,  -146,    82,  -146,   134,  -146,
     135,   -26,   -41,  -133,  -146,   -43,   -91,  -146,  -146,  -145,
    -137,  -146,  -146,  -146,  -146,  -146,  -146,    -8,  -146,  -146,
    -146,  -146,  -146,  -146,   -89,   -52,   -67,   -60,  -146,  -146,
       9,  -146,   -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,    13,     8,     9,    12,    79,   152,    30,
      31,    18,    26,    19,    28,   103,    56,    57,    20,    23,
      24,    83,    42,    43,    44,    45,    72,    46,    47,   157,
      48,    49,    50,   163,   170,   174,    95,   168,    51,   149,
      52,   159,    53,    54,    88,    89,    90,    91,    85,   108,
     148,    14,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    16,    71,   123,    84,    27,    29,   125,    35,    81,
      35,    66,    67,   100,   164,     3,   156,    41,    98,   110,
     111,   -30,   -30,   -30,    10,    94,   156,   173,    82,   167,
     107,   101,   167,    36,    11,    37,    38,    39,    40,   156,
      21,   -50,    41,    17,    15,    29,   134,   135,    41,     5,
       6,     7,   121,    25,   122,   150,    96,    35,   113,    22,
     114,   142,   143,   136,   137,   138,   139,   140,   141,    32,
      81,    35,   147,   155,   -56,    97,    86,    55,    87,    33,
      34,    58,    36,   175,    37,    38,    39,    40,    27,    82,
      81,    35,   113,   147,   114,    59,    86,    60,    87,   133,
      61,    17,    65,    64,    35,    70,   131,    68,    69,    82,
      74,   144,    73,   113,   162,   114,    75,   115,   116,   117,
     118,   119,   120,    41,    76,    78,   102,    77,    92,    41,
      93,    99,   151,    41,   105,   106,   -90,   158,   109,   112,
      41,   145,   124,    41,   126,   127,    41,   129,   132,   146,
     153,   165,   154,   169,   160,    80,   172,   166,   130,   104,
     128,   171,   161,     0,     0,     0,     0,    62,     0,    63
};

static const yytype_int16 yycheck[] =
{
      26,    14,    43,    94,    64,    20,    21,    96,     4,     3,
       4,    37,    38,    73,   159,     0,   149,    43,    70,    86,
      87,     5,     6,     7,     4,    68,   159,   172,    22,   166,
      82,    74,   169,    29,    24,    31,    32,    33,    34,   172,
      22,    37,    68,    27,    20,    60,   113,   114,    74,     5,
       6,     7,    10,    21,    12,   144,    69,     4,     9,     4,
      11,   121,   122,   115,   116,   117,   118,   119,   120,    13,
       3,     4,   132,    20,    21,     8,     9,     4,    11,    25,
      26,     4,    29,   174,    31,    32,    33,    34,   103,    22,
       3,     4,     9,   153,    11,    23,     9,    26,    11,   112,
       3,    27,    22,    35,     4,    13,    23,    22,    22,    22,
      26,   124,    37,     9,   155,    11,    35,    13,    14,    15,
      16,    17,    18,   149,    25,    35,     3,    26,    25,   155,
      25,    25,   145,   159,     3,    20,    22,   150,    36,    23,
     166,    23,    25,   169,    25,    36,   172,    36,    22,    21,
      26,    21,    23,    26,   152,    60,    23,    25,   106,    77,
     103,   169,   153,    -1,    -1,    -1,    -1,    33,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    90,     0,    40,     5,     6,     7,    42,    43,
       4,    24,    44,    41,    89,    20,    90,    27,    49,    51,
      56,    22,     4,    57,    58,    21,    50,    42,    52,    42,
      47,    48,    13,    25,    26,     4,    29,    31,    32,    33,
      34,    59,    60,    61,    62,    63,    65,    66,    68,    69,
      70,    76,    78,    80,    81,     4,    54,    55,     4,    23,
      26,     3,    56,    58,    35,    22,    59,    59,    22,    22,
      13,    60,    64,    37,    26,    35,    25,    26,    35,    45,
      47,     3,    22,    59,    85,    86,     9,    11,    82,    83,
      84,    85,    25,    25,    63,    74,    90,     8,    83,    25,
      85,    63,     3,    53,    54,     3,    20,    83,    87,    36,
      84,    84,    23,     9,    11,    13,    14,    15,    16,    17,
      18,    10,    12,    64,    25,    82,    25,    36,    52,    36,
      49,    23,    22,    90,    84,    84,    83,    83,    83,    83,
      83,    83,    85,    85,    90,    23,    21,    85,    88,    77,
      82,    90,    46,    26,    23,    20,    61,    67,    90,    79,
      43,    88,    60,    71,    67,    21,    25,    68,    75,    26,
      72,    75,    23,    67,    73,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    40,    41,    39,    42,    42,    42,    44,    45,
      46,    43,    43,    47,    47,    47,    48,    48,    50,    49,
      51,    51,    53,    52,    52,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    64,
      66,    65,    67,    67,    68,    68,    69,    71,    72,    73,
      70,    74,    74,    75,    75,    77,    76,    79,    78,    80,
      81,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      87,    86,    88,    88,    88,    89,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     1,     1,     1,     0,     0,
       0,    14,     0,     1,     3,     0,     2,     5,     0,     3,
       2,     0,     0,     5,     0,     1,     3,     1,     4,     4,
       0,     1,     3,     3,     1,     4,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     0,
       0,     4,     1,     3,     3,     3,     0,     0,     0,     0,
      15,     2,     0,     1,     3,     0,     7,     0,     8,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       1,     3,     3,     1,     3,     3,     1,     1,     3,     1,
       0,     5,     1,     3,     0,     0,     0
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
#line 125 "pl0.y"
    {
        preVar_cnt = 0;
        gen(jmp, 0, 0);
    }
#line 1612 "yacc.c"
    break;

  case 3:
#line 131 "pl0.y"
    {
        /* Main procedure */
        strcpy(id, "main");
        _enter(procedure, 0);
        table[tx].adr = cx;
        table[tx].t = xvoid;
        code[(yyvsp[-3].NUM)].a = cx;
        proctable[px] = tx;

    }
#line 1627 "yacc.c"
    break;

  case 5:
#line 144 "pl0.y"
           {(yyval.NUM) = 1;}
#line 1633 "yacc.c"
    break;

  case 6:
#line 144 "pl0.y"
                           {(yyval.NUM) = 2;}
#line 1639 "yacc.c"
    break;

  case 7:
#line 144 "pl0.y"
                                           {(yyval.NUM) = 3;}
#line 1645 "yacc.c"
    break;

  case 8:
#line 149 "pl0.y"
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
#line 1662 "yacc.c"
    break;

  case 9:
#line 162 "pl0.y"
    {
        table[(yyvsp[-4].NUM)].adr = (yyvsp[-3].NUM);
        table[(yyvsp[-4].NUM)].parameter_cnt = (yyvsp[-1].NUM);
        printf("pcnt = %d, table addr is %d\n", (yyvsp[-1].NUM), (yyvsp[-3].NUM));
        preVar_cnt = (yyvsp[-1].NUM);
    }
#line 1673 "yacc.c"
    break;

  case 10:
#line 169 "pl0.y"
    {
        preVar_cnt = 0;
        total_var = 0;
        proc_p = 0;
    }
#line 1683 "yacc.c"
    break;

  case 13:
#line 177 "pl0.y"
                      { (yyval.NUM) = (yyvsp[0].NUM) ; }
#line 1689 "yacc.c"
    break;

  case 14:
#line 179 "pl0.y"
    {
        (yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);
    }
#line 1697 "yacc.c"
    break;

  case 15:
#line 182 "pl0.y"
      { (yyval.NUM) = 0 ;}
#line 1703 "yacc.c"
    break;

  case 16:
#line 185 "pl0.y"
    {
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        if((yyvsp[-1].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-1].NUM) == 2) table[tx].t = xchar;
        total_var ++;
        (yyval.NUM) = 1;
    }
#line 1716 "yacc.c"
    break;

  case 17:
#line 194 "pl0.y"
    {
        (yyval.NUM) = 1;
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        if((yyvsp[-4].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-4].NUM) == 2) table[tx].t = xchar;
        total_var += (yyvsp[-1].NUM);
        (yyval.NUM) = 1;
    }
#line 1730 "yacc.c"
    break;

  case 18:
#line 206 "pl0.y"
    {
        setdx((yyvsp[0].NUM) + preVar_cnt);
        gen(ini, 0, total_var + 3);
        for(int i = 0; i < preVar_cnt; i++){
            gen(sto, -1 - i , 2 + preVar_cnt - i);
        }
        
    }
#line 1743 "yacc.c"
    break;

  case 19:
#line 215 "pl0.y"
    {
        gen(opr, preVar_cnt, 0);
    }
#line 1751 "yacc.c"
    break;

  case 20:
#line 222 "pl0.y"
    {
        printf("total_var: %d\n",total_var);
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1760 "yacc.c"
    break;

  case 21:
#line 226 "pl0.y"
     {(yyval.NUM) = 0 ;}
#line 1766 "yacc.c"
    break;

  case 22:
#line 230 "pl0.y"
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
#line 1785 "yacc.c"
    break;

  case 23:
#line 245 "pl0.y"
    {
        printf("2: %d, 5: %d\n", (yyvsp[-3].NUM), (yyvsp[0].NUM));
        (yyval.NUM) = (yyvsp[-3].NUM) + (yyvsp[0].NUM);
    }
#line 1794 "yacc.c"
    break;

  case 24:
#line 249 "pl0.y"
      {(yyval.NUM) = 0;}
#line 1800 "yacc.c"
    break;

  case 25:
#line 253 "pl0.y"
    { 
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1808 "yacc.c"
    break;

  case 26:
#line 256 "pl0.y"
                           {(yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);}
#line 1814 "yacc.c"
    break;

  case 27:
#line 260 "pl0.y"
    {
        ++total_var;
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        (yyval.NUM) = 1;
        vartable[varx] = tx;
        ++varx;
    }
#line 1827 "yacc.c"
    break;

  case 28:
#line 269 "pl0.y"
    {
        total_var += (yyvsp[-1].NUM);
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        (yyval.NUM) = 1;

        vartable[varx] = tx;
        ++varx;
    }
#line 1841 "yacc.c"
    break;

  case 33:
#line 289 "pl0.y"
    {
        strcpy(id, (yyvsp[-2].VAR));
        c_num = (yyvsp[0].NUM);
        _enter(constant, 0);
    }
#line 1851 "yacc.c"
    break;

  case 34:
#line 298 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[0].VAR));
        if(table[(yyval.NUM)].t == xchar && table[(yyval.NUM)].is_arry) isString = 1;

    }
#line 1862 "yacc.c"
    break;

  case 35:
#line 305 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[-3].VAR));
        gen(lit, 0, table[(yyval.NUM)].adr);
        gen(lit, 0, lev - table[(yyval.NUM)].level);
    }
#line 1873 "yacc.c"
    break;

  case 49:
#line 332 "pl0.y"
    {
        while(forx > for_var)
        {
            if(table[fortable[forx - 1]].is_arry){
                gen(sto, 0, 0);
                --forx;
            }else{
                gen(sto, lev - table[fortable[forx - 1]].level, table[fortable[forx - 1]].adr );
                --forx;
            }
        }
    }
#line 1890 "yacc.c"
    break;

  case 50:
#line 347 "pl0.y"
    {
        if(table[proc_p].t == xvoid) yyerror("error void cannot return\n");
    }
#line 1898 "yacc.c"
    break;

  case 51:
#line 352 "pl0.y"
    {
        gen(sto, -1, 0);
        gen(opr, preVar_cnt, 0);
        --px;
    }
#line 1908 "yacc.c"
    break;

  case 54:
#line 363 "pl0.y"
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
#line 1939 "yacc.c"
    break;

  case 55:
#line 390 "pl0.y"
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
#line 1966 "yacc.c"
    break;

  case 57:
#line 418 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 1974 "yacc.c"
    break;

  case 58:
#line 422 "pl0.y"
    {
        for_var += (yyvsp[0].NUM);
        for_lev[for_lx] = (yyvsp[0].NUM);
        ++for_lx;
    }
#line 1984 "yacc.c"
    break;

  case 59:
#line 428 "pl0.y"
    {
        for_var -= for_lev[--for_lx];
    }
#line 1992 "yacc.c"
    break;

  case 60:
#line 432 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-10].NUM));
        printf("jpc = %d\n", (yyvsp[-8].NUM));
        code[(yyvsp[-8].NUM)].a = cx;
    }
#line 2002 "yacc.c"
    break;

  case 63:
#line 442 "pl0.y"
                { (yyval.NUM) = 1; }
#line 2008 "yacc.c"
    break;

  case 64:
#line 443 "pl0.y"
                            {(yyval.NUM) = 1 + (yyvsp[0].NUM);}
#line 2014 "yacc.c"
    break;

  case 65:
#line 446 "pl0.y"
    {
        gen(jpc,0,0);
    }
#line 2022 "yacc.c"
    break;

  case 66:
#line 450 "pl0.y"
    {code[(yyvsp[-2].NUM)].a = cx;}
#line 2028 "yacc.c"
    break;

  case 67:
#line 454 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 2036 "yacc.c"
    break;

  case 68:
#line 458 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-5].NUM));
       code[(yyvsp[-2].NUM)].a = cx;
    }
#line 2045 "yacc.c"
    break;

  case 69:
#line 464 "pl0.y"
    {
        if(table[(yyvsp[-1].NUM)].is_arry == 0){
            gen(opr, 0, 16);
            gen(sto, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr);
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
#line 2072 "yacc.c"
    break;

  case 70:
#line 488 "pl0.y"
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
#line 2104 "yacc.c"
    break;

  case 71:
#line 518 "pl0.y"
            {
                gen(opr, 0, 8);
            }
#line 2112 "yacc.c"
    break;

  case 72:
#line 522 "pl0.y"
            {
                gen(opr, 0, 9);
            }
#line 2120 "yacc.c"
    break;

  case 73:
#line 526 "pl0.y"
            {
                gen(opr, 0, 10);
            }
#line 2128 "yacc.c"
    break;

  case 74:
#line 530 "pl0.y"
            {
                gen(opr, 0, 13);
            }
#line 2136 "yacc.c"
    break;

  case 75:
#line 534 "pl0.y"
            {
                gen(opr, 0, 12);
            }
#line 2144 "yacc.c"
    break;

  case 76:
#line 538 "pl0.y"
            {
                gen(opr, 0, 11);
            }
#line 2152 "yacc.c"
    break;

  case 79:
#line 546 "pl0.y"
    {
        gen(opr, 0, 1);
    }
#line 2160 "yacc.c"
    break;

  case 81:
#line 551 "pl0.y"
    {
        gen(opr, 0, 2);
    }
#line 2168 "yacc.c"
    break;

  case 82:
#line 555 "pl0.y"
    {
        gen(opr, 0, 3);
    }
#line 2176 "yacc.c"
    break;

  case 84:
#line 561 "pl0.y"
    {
        gen(opr, 0, 4);
    }
#line 2184 "yacc.c"
    break;

  case 85:
#line 565 "pl0.y"
    {
        gen(opr, 0 , 5);
    }
#line 2192 "yacc.c"
    break;

  case 86:
#line 570 "pl0.y"
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
#line 2215 "yacc.c"
    break;

  case 87:
#line 589 "pl0.y"
    {
        gen(lit, 0, (yyvsp[0].NUM));
    }
#line 2223 "yacc.c"
    break;

  case 90:
#line 597 "pl0.y"
    {
        ++px;
        proctable[px] = (yyvsp[0].NUM);
    }
#line 2232 "yacc.c"
    break;

  case 91:
#line 602 "pl0.y"
    {
        if(table[(yyvsp[-4].NUM)].kind != procedure) yyerror("Is  not a procedure \n");
        else{
            if((yyvsp[-1].NUM) !=  table[(yyvsp[-4].NUM)].parameter_cnt ) yyerror("parameter number not match\n");
            gen(cal, 0, table[(yyvsp[-4].NUM)].adr);
            if(table[(yyvsp[-4].NUM)].t != xvoid) gen(lod, -1, 0); /* get return */
        }
    }
#line 2245 "yacc.c"
    break;

  case 92:
#line 612 "pl0.y"
                    {(yyval.NUM) = 1;}
#line 2251 "yacc.c"
    break;

  case 93:
#line 614 "pl0.y"
        {(yyval.NUM) = 1 + (yyvsp[0].NUM);}
#line 2257 "yacc.c"
    break;

  case 94:
#line 615 "pl0.y"
      {(yyval.NUM) = 0;}
#line 2263 "yacc.c"
    break;

  case 95:
#line 619 "pl0.y"
    {
        (yyval.NUM) = tx;
    }
#line 2271 "yacc.c"
    break;

  case 96:
#line 624 "pl0.y"
    {
        (yyval.NUM) = cx;
    }
#line 2279 "yacc.c"
    break;


#line 2283 "yacc.c"

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
#line 628 "pl0.y"


void yyerror(const char* s){
    printf("error!:%s\n, located at %d line\n", s, line);
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
                            printf("here output %s", buffer);
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
                    printf("t is %d,lod at : %d  + %d ,%d \n",t ,base(i.l, s, b), i.a, s[base(i.l, s,b) + i.a]);
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
                if(i.l < 0 && i.a != 0){
                    s[b + i.a] = s[b + i.l];   
                    printf("wa!!\n");
                    printf("i.l = %d, i.a = %d\n", i.l, i.a);
                }else if(i.l < 0 && i.a == 0){
                    s[0] = s[t];
                    printf("s[0] is %d \n", s[0]);
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
    printf("Input file        ");
    scanf("%s", fname);
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
