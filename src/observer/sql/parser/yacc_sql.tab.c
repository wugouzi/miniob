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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
#ifdef YYDEBUG
  yydebug = 1;
#endif
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  // size_t select_length;

  // size_t from_length;


  size_t update_length;


  Value values[MAX_NUM][MAX_NUM];
  size_t value_lengths[MAX_NUM];

  Condition conditions[MAX_NUM][MAX_NUM];
  size_t condition_lengths[MAX_NUM];
  Condition having_conditions[MAX_NUM][MAX_NUM];
  size_t having_condition_lengths[MAX_NUM];

  char *alias[MAX_NUM][MAX_NUM];
  size_t alias_lengths[MAX_NUM];

  CompOp comps[MAX_NUM];
  char id[MAX_NUM];
  size_t is_desc;

  AggreType a_types[MAX_NUM];


  size_t joins;

  size_t valuelist_length;
  size_t in_valuelist_num;

  // select start from 1;
  size_t selects_num;
  // int selects_stack[MAX_NUM];
  // int selects_ptr;

  int stack[MAX_NUM];
  int ptr;

  RelAttr aggr_attrs[MAX_NUM][MAX_NUM];
  size_t aggr_attr_lens[MAX_NUM];

  // for aggrs
  int in_having;

  int is_or[MAX_NUM];

  // 为了func增加的单个参数，写得很死！
  char* args[MAX_NUM];
  char* argc[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  // context->condition_length = 0;
  // context->from_length = 0;
  // context->select_length = 0;
  context->update_length = 0;
  memset(context->value_lengths, 0, sizeof(context->value_lengths));
  memset(context->condition_lengths, 0, sizeof(context->condition_lengths));
  memset(context->having_condition_lengths, 0, sizeof(context->having_condition_lengths));
  memset(context->a_types, 0, sizeof(context->a_types));
  memset(context->aggr_attr_lens, 0, sizeof(context->aggr_attr_lens));
  memset(context->args, 0, sizeof(context->args));
  memset(context->argc, 0, sizeof(context->argc));
  context->ssql->sstr.insertion.valuelist_num = 0;
  context->selects_num = 0;

  context->joins = 0;

  context->in_valuelist_num = 0;
  context->ptr = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)
#define S_TOP (CONTEXT->stack[CONTEXT->ptr])


#line 186 "yacc_sql.tab.c"

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
#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
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
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    INDEX = 263,
    SELECT = 264,
    DESC = 265,
    SHOW = 266,
    SYNC = 267,
    INSERT = 268,
    DELETE = 269,
    UPDATE = 270,
    LBRACE = 271,
    RBRACE = 272,
    COMMA = 273,
    TRX_BEGIN = 274,
    TRX_COMMIT = 275,
    TRX_ROLLBACK = 276,
    INT_T = 277,
    STRING_T = 278,
    FLOAT_T = 279,
    HELP = 280,
    EXIT = 281,
    DOT = 282,
    INTO = 283,
    VALUES = 284,
    FROM = 285,
    WHERE = 286,
    AND = 287,
    OR = 288,
    SET = 289,
    ON = 290,
    LOAD = 291,
    DATA_T = 292,
    INFILE = 293,
    EQ = 294,
    IS = 295,
    LT = 296,
    GT = 297,
    LE = 298,
    GE = 299,
    NE = 300,
    DATE_T = 301,
    UNIQUE_T = 302,
    MAX = 303,
    MIN = 304,
    COUNT = 305,
    AVG = 306,
    SUM = 307,
    LENGTH = 308,
    ROUND = 309,
    DATE_FORMAT = 310,
    NULLABLE = 311,
    NULL_V = 312,
    NOT = 313,
    INNER = 314,
    JOIN = 315,
    LIKE = 316,
    ORDER = 317,
    GROUP = 318,
    ASC = 319,
    BY = 320,
    TEXT_T = 321,
    IN = 322,
    EXISTS = 323,
    HAVING = 324,
    AS = 325,
    NUMBER = 326,
    DATE_STR = 327,
    FLOAT = 328,
    ID = 329,
    PATH = 330,
    SSS = 331,
    STAR = 332,
    STRING_V = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 192 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 327 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   412

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  389

#define YYUNDEFTOK  2
#define YYMAXUTOK   333


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   219,   219,   221,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   246,   251,   256,   262,   268,   274,   280,   286,
     292,   299,   306,   312,   320,   322,   328,   335,   344,   346,
     350,   361,   377,   383,   391,   394,   395,   396,   397,   398,
     401,   410,   423,   425,   431,   436,   438,   443,   447,   450,
     454,   457,   460,   467,   478,   489,   494,   496,   501,   509,
     515,   521,   535,   537,   542,   544,   549,   556,   558,   563,
     570,   575,   580,   585,   590,   593,   599,   603,   608,   613,
     618,   625,   643,   646,   649,   652,   655,   661,   664,   667,
     673,   677,   682,   687,   692,   699,   714,   724,   726,   730,
     737,   739,   742,   745,   748,   752,   754,   759,   764,   769,
     774,   778,   784,   791,   793,   798,   800,   803,   804,   810,
     819,   822,   825,   830,   832,   838,   841,   844,   847,   850,
     853,   856,   859,   862,   865,   868,   871,   874,   879,   881,
     885,   887,   891,   893,   897,   903,   913,   926,   935,   946,
     957,   970,   981,   992,  1002,  1012,  1026,  1039,  1047,  1055,
    1062,  1072,  1080,  1082,  1086,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1103
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "HELP", "EXIT", "DOT",
  "INTO", "VALUES", "FROM", "WHERE", "AND", "OR", "SET", "ON", "LOAD",
  "DATA_T", "INFILE", "EQ", "IS", "LT", "GT", "LE", "GE", "NE", "DATE_T",
  "UNIQUE_T", "MAX", "MIN", "COUNT", "AVG", "SUM", "LENGTH", "ROUND",
  "DATE_FORMAT", "NULLABLE", "NULL_V", "NOT", "INNER", "JOIN", "LIKE",
  "ORDER", "GROUP", "ASC", "BY", "TEXT_T", "IN", "EXISTS", "HAVING", "AS",
  "NUMBER", "DATE_STR", "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V",
  "$accept", "commands", "command", "exit", "help", "sync", "begin",
  "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "show_index", "create_index", "index_ids", "drop_index", "create_table",
  "attr_def_list", "attr_def", "number", "type", "ID_get", "insert",
  "insert_brace", "insert_element", "value_list", "value", "delete",
  "update", "update_set", "updates_sets", "select_stmt", "select_",
  "select", "having", "groupby", "groupby_ids", "select_attr",
  "aggregation_attr", "aggregation_func", "non_aggregation_func",
  "func_attr", "func_extra_args", "aggregation_extra_id", "attr_list",
  "rel_name", "inner_joins", "order", "order_component", "order_direction",
  "order_component_list", "alias", "rel_list", "where", "condition_list",
  "condition", "in_value", "in_value_list", "comOp", "load_data", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333
};
# endif

#define YYPACT_NINF (-326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -326,   262,  -326,    44,   106,  -326,   -57,    41,    33,    32,
      49,    11,    94,   101,   116,   128,   143,   108,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   241,   151,  -326,  -326,    88,
      93,   160,   110,   115,   177,   188,   163,  -326,   125,   127,
     168,  -326,  -326,  -326,  -326,  -326,   171,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   -11,   167,   180,   167,   204,
     205,   167,  -326,   206,   214,   149,   235,   236,  -326,  -326,
     166,   221,   220,   178,   179,    22,  -326,  -326,  -326,  -326,
    -326,   271,  -326,   238,   238,   183,   238,    78,    56,   238,
     185,   186,   228,  -326,  -326,   265,   247,   124,   266,   239,
     261,   252,   167,   167,  -326,  -326,  -326,  -326,  -326,  -326,
     251,  -326,  -326,   167,   267,  -326,  -326,   279,   279,     5,
     279,  -326,   296,   296,    38,   269,   296,  -326,  -326,   298,
     142,   301,   210,  -326,   308,   308,   318,  -326,   263,    71,
    -326,  -326,  -326,   203,  -326,   268,   268,   314,    34,  -326,
      71,   178,   220,   326,   238,   238,   184,   167,   167,   167,
     274,   183,   220,    82,   317,   319,   264,   320,   322,    10,
     323,   324,   270,   325,  -326,   329,   185,   330,  -326,  -326,
    -326,  -326,  -326,     6,   275,   327,    71,   247,   247,   331,
      71,  -326,   276,  -326,   293,  -326,  -326,  -326,  -326,  -326,
     -32,  -326,  -326,     4,   155,    71,   278,   124,   124,  -326,
    -326,   261,   350,   280,  -326,  -326,    84,   238,   238,   238,
     238,   295,  -326,   267,   294,   279,    80,   279,  -326,  -326,
     279,  -326,  -326,   279,   279,  -326,  -326,   296,  -326,  -326,
     298,   353,   287,  -326,   302,   342,   288,   343,  -326,   360,
    -326,  -326,   268,  -326,  -326,  -326,    17,   337,  -326,   338,
    -326,  -326,  -326,   349,    34,    34,  -326,  -326,   364,   167,
     167,  -326,  -326,  -326,  -326,   297,  -326,   303,   300,  -326,
     279,  -326,  -326,   355,  -326,  -326,   356,  -326,  -326,  -326,
     357,  -326,   304,   358,   342,    71,   359,  -326,    37,  -326,
     352,   305,   306,   268,  -326,  -326,  -326,   238,   238,   167,
     307,   124,   315,  -326,  -326,  -326,  -326,   342,   379,   366,
     343,  -326,    17,   361,  -326,    71,   367,  -326,  -326,    71,
    -326,  -326,   351,   121,    34,   328,  -326,  -326,  -326,   382,
    -326,   352,   313,   352,  -326,  -326,   124,   316,   321,  -326,
    -326,   332,  -326,   372,  -326,  -326,    34,   123,   373,    18,
     374,  -326,   274,   333,  -326,  -326,  -326,   334,  -326,  -326,
     332,  -326,  -326,   373,    20,   374,  -326,  -326,  -326
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    21,    12,
      13,     8,     5,     7,     6,     0,     0,     4,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,    27,    23,    22,     0,    92,    93,    95,
      94,    96,    97,    98,    99,   135,   135,    70,   135,     0,
       0,   135,    71,     0,     0,     0,     0,     0,    30,    29,
       0,     0,   150,     0,     0,     0,   141,   142,   139,   138,
     140,     0,   137,   115,   115,     0,   115,     0,     0,   115,
       0,     0,     0,    28,    36,     0,    52,     0,     0,     0,
      66,     0,   135,   135,   146,   147,   144,   143,   145,   136,
       0,    82,    80,   135,   148,    84,    88,   110,   110,   110,
     110,   102,   107,   107,   107,     0,   107,    85,    50,    38,
       0,     0,     0,    31,     0,     0,     0,    61,     0,     0,
      57,    60,    58,     0,    59,     0,     0,     0,   152,    63,
       0,     0,   150,     0,   115,   115,   135,   135,   135,   135,
     123,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,    45,    46,
      47,    48,    49,    41,     0,     0,     0,    52,    52,     0,
       0,   167,     0,   174,   180,   175,   176,   177,   178,   179,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   151,
      65,    66,     0,     0,    83,    81,     0,   115,   115,   115,
     115,     0,   122,   148,    74,   110,   110,   110,    90,    91,
     110,    86,    89,   110,   110,   104,   105,   107,   100,   103,
      38,     0,     0,    42,     0,    34,     0,    55,    53,     0,
      62,   168,     0,   181,   182,   185,     0,   158,   156,   159,
     157,   170,   169,     0,   152,   152,    67,    64,     0,   135,
     135,   116,   118,   120,   121,     0,   149,     0,    72,   114,
     110,   111,   113,     0,   108,   109,     0,    39,    37,    44,
       0,    43,     0,     0,    34,     0,     0,    51,     0,   171,
     172,     0,     0,     0,   154,   153,   186,   115,   115,   135,
       0,     0,   125,   112,    87,   101,    40,    34,     0,     0,
      55,    54,     0,   163,   160,     0,     0,   164,   161,     0,
     117,   119,     0,    77,   152,     0,    69,    35,    32,     0,
      56,   172,     0,   172,   165,   155,     0,     0,     0,    75,
      73,   127,    33,     0,   162,   173,   152,    77,    77,   132,
     133,   166,   123,     0,    78,    76,   131,     0,   130,   128,
     127,   126,   124,    77,   132,   133,    79,   129,   134
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -273,  -326,  -326,   144,   211,  -326,
    -326,  -326,  -326,   -72,   253,    66,  -145,  -326,  -326,   240,
     181,  -326,   398,  -326,  -326,  -326,  -325,  -326,   -28,  -326,
     -14,   283,  -109,  -120,   -93,   229,    39,  -326,    24,    21,
      25,   -66,   176,  -128,  -261,  -199,    77,  -168,  -144,  -326
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   303,    30,    31,   187,   139,   300,
     193,   140,    32,   145,   197,   306,   155,    33,    34,   110,
     162,    35,   199,    37,   322,   288,   359,    67,   156,    69,
     157,    71,   180,   174,   121,   124,   232,   346,   370,   379,
     381,    93,   172,   108,   219,   158,   310,   336,   213,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,   122,    96,   125,   201,    99,   137,    68,   175,   177,
     178,   214,   215,   314,   315,   220,    85,    44,   274,   275,
     266,    70,   252,   173,   181,   183,     5,   185,   376,   264,
     376,   329,   176,   146,   222,   265,    47,    86,    87,    88,
      89,    90,   374,   375,   234,   377,   164,   165,    45,    46,
      39,   257,    40,   332,   347,   261,   179,   170,   386,    91,
      48,   147,   253,    92,   254,   182,   217,   218,   268,   270,
     272,   224,   225,   131,   147,   150,   151,   152,   267,    49,
     154,   243,   378,   360,   378,    50,   244,   146,   150,   151,
     152,    41,   168,   154,   147,   126,   112,    51,   173,   113,
     227,   228,   229,   230,    52,   372,    70,   290,   150,   151,
     152,   333,    42,   154,    43,   289,   291,   292,   308,    53,
     293,   309,   344,   294,   295,   258,   259,   132,   147,   133,
     134,    54,   135,   136,   281,   282,   283,   284,   296,   357,
     146,   357,   150,   151,   152,    56,    55,   154,   358,   127,
     373,   128,   129,   235,    72,   130,   236,   366,   279,   237,
     330,   280,    73,   334,   188,   189,   190,    74,    75,   339,
     323,   146,    57,    58,    59,    60,    61,    62,    63,    64,
      78,   147,   148,   363,    76,   365,   271,   351,   191,    77,
     309,    79,   149,    80,   355,   150,   151,   152,   153,    81,
     154,    82,    83,    57,    58,    59,    60,    61,   192,    84,
      95,   226,   147,   317,   318,    86,    87,    88,    89,    90,
      97,    98,   100,   102,   340,   341,   150,   151,   152,   269,
     202,   154,    86,    87,    88,    89,    90,    91,   103,   104,
     105,    92,   203,   204,   205,   206,   207,   208,   209,   101,
     106,   107,   109,   342,    91,   111,   120,   123,    92,   138,
     141,   210,     2,   142,   211,   144,     3,     4,   143,   159,
     212,     5,     6,     7,     8,     9,    10,    11,   160,   161,
     163,    12,    13,    14,   195,   171,   184,    15,    16,    57,
      58,    59,    60,    61,    62,    63,    64,   173,    17,    57,
      58,    59,    60,    61,    62,    63,    64,   203,   204,   205,
     206,   207,   208,   209,   179,    65,   186,   194,    66,   114,
     115,   116,   117,   118,   196,   166,   210,     5,   167,   211,
     216,   200,   223,   231,   238,   212,   239,   241,   240,   242,
     245,   246,   248,   256,   247,   119,   249,   251,   260,   255,
     262,   263,   273,   277,   278,   285,   298,   287,   299,   301,
     302,   305,   304,   307,   311,   312,   313,   316,   320,   321,
     335,   319,   324,   325,   326,   328,   331,   345,   327,   337,
     338,   343,   348,   349,   354,   362,   356,   364,   352,   371,
     367,   357,   380,   361,   297,   368,   350,   250,   198,    36,
     233,   221,   276,   169,   385,   387,   369,   383,   384,   286,
     388,   382,   353
};

static const yytype_int16 yycheck[] =
{
      66,    94,    68,    96,   149,    71,    99,    35,   128,   129,
     130,   155,   156,   274,   275,   160,    27,    74,   217,   218,
      16,    35,    16,    18,   133,   134,     9,   136,    10,    61,
      10,   304,    27,    16,   162,    67,     3,    48,    49,    50,
      51,    52,   367,   368,   172,    27,   112,   113,     7,     8,
       6,   196,     8,    16,   327,   200,    18,   123,   383,    70,
      28,    57,    56,    74,    58,    27,    32,    33,   213,   214,
     215,   164,   165,    17,    57,    71,    72,    73,    74,    30,
      76,    71,    64,   344,    64,    74,    76,    16,    71,    72,
      73,    47,   120,    76,    57,    17,    74,     3,    18,    77,
     166,   167,   168,   169,     3,   366,   120,    27,    71,    72,
      73,    74,     6,    76,     8,   235,   236,   237,   262,     3,
     240,   266,   321,   243,   244,   197,   198,    71,    57,    73,
      74,     3,    76,    77,   227,   228,   229,   230,   247,    18,
      16,    18,    71,    72,    73,    37,     3,    76,    27,    71,
      27,    73,    74,    71,     3,    77,    74,   356,    74,    77,
     305,    77,    74,   308,    22,    23,    24,    74,     8,   313,
     290,    16,    48,    49,    50,    51,    52,    53,    54,    55,
       3,    57,    58,   351,    74,   353,   214,   332,    46,    74,
     335,     3,    68,    30,   339,    71,    72,    73,    74,    74,
      76,    74,    34,    48,    49,    50,    51,    52,    66,    38,
      30,    27,    57,   279,   280,    48,    49,    50,    51,    52,
      16,    16,    16,    74,   317,   318,    71,    72,    73,    74,
      27,    76,    48,    49,    50,    51,    52,    70,     3,     3,
      74,    74,    39,    40,    41,    42,    43,    44,    45,    35,
      29,    31,    74,   319,    70,    76,    18,    74,    74,    74,
      74,    58,     0,    35,    61,    18,     4,     5,     3,     3,
      67,     9,    10,    11,    12,    13,    14,    15,    39,    18,
      28,    19,    20,    21,    74,    18,    17,    25,    26,    48,
      49,    50,    51,    52,    53,    54,    55,    18,    36,    48,
      49,    50,    51,    52,    53,    54,    55,    39,    40,    41,
      42,    43,    44,    45,    18,    74,    18,    16,    77,    48,
      49,    50,    51,    52,    16,    74,    58,     9,    77,    61,
      16,    68,     6,    59,    17,    67,    17,    17,    74,    17,
      17,    17,    17,    16,    74,    74,    17,    17,    17,    74,
      74,    58,    74,     3,    74,    60,     3,    63,    71,    57,
      18,    18,    74,     3,    27,    27,    17,     3,    65,    69,
      18,    74,    17,    17,    17,    17,    17,    62,    74,    74,
      74,    74,     3,    17,    17,     3,    35,    74,    27,    17,
      74,    18,    18,    65,   250,    74,   330,   186,   145,     1,
     171,   161,   221,   120,   380,   384,    74,    74,    74,   233,
     385,   372,   335
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    36,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      94,    95,   101,   106,   107,   110,   111,   112,   138,     6,
       8,    47,     6,     8,    74,     7,     8,     3,    28,    30,
      74,     3,     3,     3,     3,     3,    37,    48,    49,    50,
      51,    52,    53,    54,    55,    74,    77,   116,   117,   118,
     119,   120,     3,    74,    74,     8,    74,    74,     3,     3,
      30,    74,    74,    34,    38,    27,    48,    49,    50,    51,
      52,    70,    74,   130,   130,    30,   130,    16,    16,   130,
      16,    35,    74,     3,     3,    74,    29,    31,   132,    74,
     108,    76,    74,    77,    48,    49,    50,    51,    52,    74,
      18,   123,   123,    74,   124,   123,    17,    71,    73,    74,
      77,    17,    71,    73,    74,    76,    77,   123,    74,    97,
     100,    74,    35,     3,    18,   102,    16,    57,    58,    68,
      71,    72,    73,    74,    76,   105,   117,   119,   134,     3,
      39,    18,   109,    28,   130,   130,    74,    77,   117,   120,
     130,    18,   131,    18,   122,   122,    27,   122,   122,    18,
     121,   121,    27,   121,    17,   121,    18,    96,    22,    23,
      24,    46,    66,    99,    16,    74,    16,   103,   103,   111,
      68,   105,    27,    39,    40,    41,    42,    43,    44,    45,
      58,    61,    67,   137,   137,   137,    16,    32,    33,   133,
     105,   108,   132,     6,   123,   123,    27,   130,   130,   130,
     130,    59,   125,   124,   132,    71,    74,    77,    17,    17,
      74,    17,    17,    71,    76,    17,    17,    74,    17,    17,
      97,    17,    16,    56,    58,    74,    16,   105,   102,   102,
      17,   105,    74,    58,    61,    67,    16,    74,   105,    74,
     105,   117,   105,    74,   134,   134,   109,     3,    74,    74,
      77,   123,   123,   123,   123,    60,   131,    63,   114,   122,
      27,   122,   122,   122,   122,   122,   121,    96,     3,    71,
      98,    57,    18,    93,    74,    18,   104,     3,   137,   105,
     135,    27,    27,    17,   133,   133,     3,   130,   130,    74,
      65,    69,   113,   122,    17,    17,    17,    74,    17,    93,
     105,    17,    16,    74,   105,    18,   136,    74,    74,   137,
     123,   123,   130,    74,   134,    62,   126,    93,     3,    17,
     104,   105,    27,   135,    17,   105,    35,    18,    27,   115,
     133,    65,     3,   136,    74,   136,   134,    74,    74,    74,
     127,    17,   133,    27,   115,   115,    10,    27,    64,   128,
      18,   129,   125,    74,    74,   127,   115,   128,   129
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    92,    93,    93,    94,    95,    96,    96,
      97,    97,    97,    97,    98,    99,    99,    99,    99,    99,
     100,   101,   102,   102,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   107,   108,   109,   109,   110,   111,
     111,   112,   113,   113,   114,   114,   114,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   118,   118,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   124,   125,   125,   126,   126,   127,   127,   127,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     5,    10,    11,     0,     3,     4,     8,     0,     3,
       5,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     8,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     3,     5,     7,     3,     0,     3,     1,     9,
       2,     2,     0,     3,     0,     4,     6,     0,     3,     5,
       3,     5,     3,     5,     3,     3,     5,     7,     3,     5,
       5,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     3,     5,     5,     5,     4,     0,     3,     3,
       0,     3,     4,     3,     3,     0,     4,     6,     4,     6,
       4,     4,     3,     0,     8,     0,     4,     0,     2,     4,
       1,     1,     0,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     0,     3,
       0,     3,     0,     3,     3,     6,     3,     3,     3,     3,
       5,     5,     7,     5,     5,     6,     8,     2,     3,     3,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     8
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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
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
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, scanner);
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
  case 22:
#line 246 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1791 "yacc_sql.tab.c"
    break;

  case 23:
#line 251 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1799 "yacc_sql.tab.c"
    break;

  case 24:
#line 256 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1807 "yacc_sql.tab.c"
    break;

  case 25:
#line 262 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1815 "yacc_sql.tab.c"
    break;

  case 26:
#line 268 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1823 "yacc_sql.tab.c"
    break;

  case 27:
#line 274 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1831 "yacc_sql.tab.c"
    break;

  case 28:
#line 280 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1840 "yacc_sql.tab.c"
    break;

  case 29:
#line 286 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1848 "yacc_sql.tab.c"
    break;

  case 30:
#line 292 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1857 "yacc_sql.tab.c"
    break;

  case 31:
#line 299 "yacc_sql.y"
                             {
  CONTEXT->ssql->flag = SCF_SHOW_INDEX;
  show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
}
#line 1866 "yacc_sql.tab.c"
    break;

  case 32:
#line 307 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
}
#line 1876 "yacc_sql.tab.c"
    break;

  case 33:
#line 313 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
}
#line 1886 "yacc_sql.tab.c"
    break;

  case 35:
#line 322 "yacc_sql.y"
                      {
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
}
#line 1894 "yacc_sql.tab.c"
    break;

  case 36:
#line 329 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1903 "yacc_sql.tab.c"
    break;

  case 37:
#line 336 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_lengths[S_TOP] = 0;
		}
#line 1915 "yacc_sql.tab.c"
    break;

  case 39:
#line 346 "yacc_sql.y"
                                   {    }
#line 1921 "yacc_sql.tab.c"
    break;

  case 40:
#line 351 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_lengths[S_TOP]++;
		}
#line 1936 "yacc_sql.tab.c"
    break;

  case 41:
#line 362 "yacc_sql.y"
                {
			AttrInfo attribute;
      if ((yyvsp[0].number) == TEXTS) {
        // TODO
        attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4096,  0);
      } else {
        attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4,  0);
      }
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_lengths[S_TOP]++;
		}
#line 1956 "yacc_sql.tab.c"
    break;

  case 42:
#line 377 "yacc_sql.y"
                       {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 1967 "yacc_sql.tab.c"
    break;

  case 43:
#line 383 "yacc_sql.y"
                         {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 1978 "yacc_sql.tab.c"
    break;

  case 44:
#line 391 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1984 "yacc_sql.tab.c"
    break;

  case 45:
#line 394 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1990 "yacc_sql.tab.c"
    break;

  case 46:
#line 395 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1996 "yacc_sql.tab.c"
    break;

  case 47:
#line 396 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2002 "yacc_sql.tab.c"
    break;

  case 48:
#line 397 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 2008 "yacc_sql.tab.c"
    break;

  case 49:
#line 398 "yacc_sql.y"
         { (yyval.number)=TEXTS; }
#line 2014 "yacc_sql.tab.c"
    break;

  case 50:
#line 402 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string);
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2023 "yacc_sql.tab.c"
    break;

  case 51:
#line 411 "yacc_sql.y"
{
  // CONTEXT->values[CONTEXT->value_length++] = *$6;

  CONTEXT->ssql->flag=SCF_INSERT;//"insert";
  inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-5].string));
  //inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length);

  //临时变量清零
  CONTEXT->value_lengths[S_TOP]=0;
}
#line 2038 "yacc_sql.tab.c"
    break;

  case 53:
#line 425 "yacc_sql.y"
                                    {

}
#line 2046 "yacc_sql.tab.c"
    break;

  case 54:
#line 431 "yacc_sql.y"
                               {
inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values[S_TOP], CONTEXT->value_lengths[S_TOP]);
CONTEXT->value_lengths[S_TOP] = 0;
}
#line 2055 "yacc_sql.tab.c"
    break;

  case 56:
#line 438 "yacc_sql.y"
                              {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2063 "yacc_sql.tab.c"
    break;

  case 57:
#line 443 "yacc_sql.y"
          {
      value_init_integer(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].number));
  		// value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
#line 2072 "yacc_sql.tab.c"
    break;

  case 58:
#line 447 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].floats));
		}
#line 2080 "yacc_sql.tab.c"
    break;

  case 59:
#line 450 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
		}
#line 2089 "yacc_sql.tab.c"
    break;

  case 60:
#line 454 "yacc_sql.y"
              {
        value_init_date(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
    }
#line 2097 "yacc_sql.tab.c"
    break;

  case 61:
#line 457 "yacc_sql.y"
         {
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
    }
#line 2105 "yacc_sql.tab.c"
    break;

  case 62:
#line 460 "yacc_sql.y"
                        {
  value_init_select(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++],
                    &CONTEXT->ssql->selects[CONTEXT->stack[CONTEXT->ptr+1]]);
}
#line 2114 "yacc_sql.tab.c"
    break;

  case 63:
#line 468 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion,
					CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
			CONTEXT->condition_lengths[S_TOP] = 0;
    }
#line 2126 "yacc_sql.tab.c"
    break;

  case 64:
#line 479 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_UPDATE;//"update";
  updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string),
               CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
  CONTEXT->condition_lengths[S_TOP] = 0;
  CONTEXT->value_lengths[S_TOP] = 0;
}
#line 2138 "yacc_sql.tab.c"
    break;

  case 65:
#line 489 "yacc_sql.y"
            {
  // updates_append(&CONTEXT->ssql->sstr.update, $1, &CONTEXT->values[CONTEXT->value_lengths[S_TOP] - 1]);
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1]);
}
#line 2147 "yacc_sql.tab.c"
    break;

  case 67:
#line 496 "yacc_sql.y"
                                {
}
#line 2154 "yacc_sql.tab.c"
    break;

  case 68:
#line 501 "yacc_sql.y"
       {
  CONTEXT->stack[++CONTEXT->ptr] = ++CONTEXT->selects_num;
  // printf("push select %zu, ptr: %d\n", CONTEXT->selects_num, CONTEXT->ptr);
  // CONTEXT->selects_num++;
  CONTEXT->ssql->selects_num = CONTEXT->selects_num;
}
#line 2165 "yacc_sql.tab.c"
    break;

  case 69:
#line 509 "yacc_sql.y"
                                                                          {
  printf("SELECT: num: %d, ptr: %d pop, table: %s, cond num: %d\n", S_TOP, CONTEXT->ptr, CONTEXT->ssql->selects[S_TOP].relations[0], CONTEXT->condition_lengths[S_TOP]);
  selects_append_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
  selects_append_having_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->having_conditions[S_TOP], CONTEXT->having_condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
  CONTEXT->ptr--;
}
#line 2176 "yacc_sql.tab.c"
    break;

  case 70:
#line 515 "yacc_sql.y"
                          {
  selects_append_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
}
#line 2184 "yacc_sql.tab.c"
    break;

  case 71:
#line 522 "yacc_sql.y"
{
  // int num = CONTEXT->selects_num;
  // printf("SELECT: num: %d, ptr: %d pop, table: %s, cond num: %d", S_TOP, CONTEXT->ptr, CONTEXT->ssql->selects[S_TOP].relations[0], CONTEXT->condition_lengths[S_TOP]);
  CONTEXT->ssql->sstr.selection = &CONTEXT->ssql->selects[1];
  CONTEXT->ssql->flag=SCF_SELECT;//"select";

  //临时变量清零
  CONTEXT->condition_lengths[S_TOP]=0;
  // CONTEXT->from_length=0;
  // CONTEXT->select_length=0;
  CONTEXT->value_lengths[S_TOP] = 0;
}
#line 2201 "yacc_sql.tab.c"
    break;

  case 73:
#line 537 "yacc_sql.y"
                                  {

}
#line 2209 "yacc_sql.tab.c"
    break;

  case 75:
#line 544 "yacc_sql.y"
                          {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2219 "yacc_sql.tab.c"
    break;

  case 76:
#line 549 "yacc_sql.y"
                                 {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2229 "yacc_sql.tab.c"
    break;

  case 78:
#line 558 "yacc_sql.y"
                       {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2239 "yacc_sql.tab.c"
    break;

  case 79:
#line 563 "yacc_sql.y"
                              {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2249 "yacc_sql.tab.c"
    break;

  case 80:
#line 570 "yacc_sql.y"
                     {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2259 "yacc_sql.tab.c"
    break;

  case 81:
#line 575 "yacc_sql.y"
                              {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2269 "yacc_sql.tab.c"
    break;

  case 82:
#line 580 "yacc_sql.y"
                     {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2279 "yacc_sql.tab.c"
    break;

  case 83:
#line 585 "yacc_sql.y"
                            {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2289 "yacc_sql.tab.c"
    break;

  case 84:
#line 590 "yacc_sql.y"
                                   {
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2297 "yacc_sql.tab.c"
    break;

  case 85:
#line 593 "yacc_sql.y"
                            {
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2305 "yacc_sql.tab.c"
    break;

  case 86:
#line 599 "yacc_sql.y"
                                                       {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2314 "yacc_sql.tab.c"
    break;

  case 87:
#line 603 "yacc_sql.y"
                                                                {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2324 "yacc_sql.tab.c"
    break;

  case 88:
#line 608 "yacc_sql.y"
                                 {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "fail", A_FAILURE, 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2334 "yacc_sql.tab.c"
    break;

  case 89:
#line 613 "yacc_sql.y"
                                                           {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "*", CONTEXT->a_types[S_TOP] != A_COUNT ? A_FAILURE : CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2344 "yacc_sql.tab.c"
    break;

  case 90:
#line 618 "yacc_sql.y"
                                                             {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, str, CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2356 "yacc_sql.tab.c"
    break;

  case 91:
#line 625 "yacc_sql.y"
                                                            {
  char *buf = malloc(20 * sizeof(char));
  snprintf(buf, 20, "%.2f", (yyvsp[-2].floats));
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
  }
  if (buf[len - 1] == '.') {
    len--;
  }
  buf[len] = '\0';
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, buf, CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2376 "yacc_sql.tab.c"
    break;

  case 92:
#line 643 "yacc_sql.y"
    {
  CONTEXT->a_types[S_TOP] = A_MAX;
}
#line 2384 "yacc_sql.tab.c"
    break;

  case 93:
#line 646 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_MIN;
}
#line 2392 "yacc_sql.tab.c"
    break;

  case 94:
#line 649 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_AVG;
}
#line 2400 "yacc_sql.tab.c"
    break;

  case 95:
#line 652 "yacc_sql.y"
        {
  CONTEXT->a_types[S_TOP] = A_COUNT;
}
#line 2408 "yacc_sql.tab.c"
    break;

  case 96:
#line 655 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_SUM;
}
#line 2416 "yacc_sql.tab.c"
    break;

  case 97:
#line 661 "yacc_sql.y"
       {
  CONTEXT->a_types[S_TOP] = A_LENGTH;
}
#line 2424 "yacc_sql.tab.c"
    break;

  case 98:
#line 664 "yacc_sql.y"
        {
  CONTEXT->a_types[S_TOP] = A_ROUND;
}
#line 2432 "yacc_sql.tab.c"
    break;

  case 99:
#line 667 "yacc_sql.y"
              {
  CONTEXT->a_types[S_TOP] = A_DATE_FORMAT;
}
#line 2440 "yacc_sql.tab.c"
    break;

  case 100:
#line 673 "yacc_sql.y"
                                                      {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2449 "yacc_sql.tab.c"
    break;

  case 101:
#line 677 "yacc_sql.y"
                                                               {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2459 "yacc_sql.tab.c"
    break;

  case 102:
#line 682 "yacc_sql.y"
                                     {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "fail", A_FAILURE, 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2469 "yacc_sql.tab.c"
    break;

  case 103:
#line 687 "yacc_sql.y"
                                                          {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "*", CONTEXT->a_types[S_TOP] != A_COUNT ? A_FAILURE : CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2479 "yacc_sql.tab.c"
    break;

  case 104:
#line 692 "yacc_sql.y"
                                                            {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, str, CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2491 "yacc_sql.tab.c"
    break;

  case 105:
#line 699 "yacc_sql.y"
                                                           {
  char *buf = malloc(20 * sizeof(char));
  snprintf(buf, 20, "%.2f", (yyvsp[-2].floats));
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
  }
  if (buf[len - 1] == '.') {
    len--;
  }
  buf[len] = '\0';
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, buf, CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2511 "yacc_sql.tab.c"
    break;

  case 106:
#line 714 "yacc_sql.y"
                                         {
  char s[1000];
  memset(s, 0, sizeof(s));
  sprintf(s,"length(%s)", (yyvsp[-1].string));
  CONTEXT->a_types[S_TOP] = A_LENGTH;
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-1].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
}
#line 2523 "yacc_sql.tab.c"
    break;

  case 108:
#line 726 "yacc_sql.y"
                                    {
  CONTEXT->args[S_TOP] = (yyvsp[-1].number);
  CONTEXT->argc[S_TOP]++;
}
#line 2532 "yacc_sql.tab.c"
    break;

  case 109:
#line 730 "yacc_sql.y"
                                 {
  CONTEXT->args[S_TOP] = strdup((yyvsp[-1].string));
  CONTEXT->argc[S_TOP]++;
}
#line 2541 "yacc_sql.tab.c"
    break;

  case 111:
#line 739 "yacc_sql.y"
                                {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2549 "yacc_sql.tab.c"
    break;

  case 112:
#line 742 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2557 "yacc_sql.tab.c"
    break;

  case 113:
#line 745 "yacc_sql.y"
                                  {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2565 "yacc_sql.tab.c"
    break;

  case 114:
#line 748 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2573 "yacc_sql.tab.c"
    break;

  case 116:
#line 754 "yacc_sql.y"
                           {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2583 "yacc_sql.tab.c"
    break;

  case 117:
#line 759 "yacc_sql.y"
                                  {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2593 "yacc_sql.tab.c"
    break;

  case 118:
#line 764 "yacc_sql.y"
                             {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2603 "yacc_sql.tab.c"
    break;

  case 119:
#line 769 "yacc_sql.y"
                                    {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2613 "yacc_sql.tab.c"
    break;

  case 120:
#line 774 "yacc_sql.y"
                                         {
  printf("append aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2622 "yacc_sql.tab.c"
    break;

  case 121:
#line 778 "yacc_sql.y"
                                  {
  printf("append map func aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2631 "yacc_sql.tab.c"
    break;

  case 122:
#line 784 "yacc_sql.y"
                     {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-2].string), CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
  selects_reverse_relations(&CONTEXT->ssql->selects[S_TOP], ++CONTEXT->joins);
  CONTEXT->joins = 0;
}
#line 2641 "yacc_sql.tab.c"
    break;

  case 124:
#line 793 "yacc_sql.y"
                                                              {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-5].string), CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
  CONTEXT->joins++;
}
#line 2650 "yacc_sql.tab.c"
    break;

  case 126:
#line 800 "yacc_sql.y"
                                                    {
    }
#line 2657 "yacc_sql.tab.c"
    break;

  case 128:
#line 804 "yacc_sql.y"
                       {
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2668 "yacc_sql.tab.c"
    break;

  case 129:
#line 810 "yacc_sql.y"
                              {
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2679 "yacc_sql.tab.c"
    break;

  case 130:
#line 819 "yacc_sql.y"
     {
  CONTEXT->is_desc = 0;
 }
#line 2687 "yacc_sql.tab.c"
    break;

  case 131:
#line 822 "yacc_sql.y"
        {
  CONTEXT->is_desc = 1;
 }
#line 2695 "yacc_sql.tab.c"
    break;

  case 132:
#line 825 "yacc_sql.y"
   {
  CONTEXT->is_desc = 0;
 }
#line 2703 "yacc_sql.tab.c"
    break;

  case 134:
#line 832 "yacc_sql.y"
                                                 {
      // 啥都不干
    }
#line 2711 "yacc_sql.tab.c"
    break;

  case 135:
#line 838 "yacc_sql.y"
{
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = NULL;
}
#line 2719 "yacc_sql.tab.c"
    break;

  case 136:
#line 841 "yacc_sql.y"
        {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = (yyvsp[0].string);
 }
#line 2727 "yacc_sql.tab.c"
    break;

  case 137:
#line 844 "yacc_sql.y"
     {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = (yyvsp[0].string);
 }
#line 2735 "yacc_sql.tab.c"
    break;

  case 138:
#line 847 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "avg";
}
#line 2743 "yacc_sql.tab.c"
    break;

  case 139:
#line 850 "yacc_sql.y"
        {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "count";
}
#line 2751 "yacc_sql.tab.c"
    break;

  case 140:
#line 853 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "sum";
}
#line 2759 "yacc_sql.tab.c"
    break;

  case 141:
#line 856 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "max";
}
#line 2767 "yacc_sql.tab.c"
    break;

  case 142:
#line 859 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "min";
}
#line 2775 "yacc_sql.tab.c"
    break;

  case 143:
#line 862 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "avg";
}
#line 2783 "yacc_sql.tab.c"
    break;

  case 144:
#line 865 "yacc_sql.y"
           {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "count";
}
#line 2791 "yacc_sql.tab.c"
    break;

  case 145:
#line 868 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "sum";
}
#line 2799 "yacc_sql.tab.c"
    break;

  case 146:
#line 871 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "max";
}
#line 2807 "yacc_sql.tab.c"
    break;

  case 147:
#line 874 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "min";
}
#line 2815 "yacc_sql.tab.c"
    break;

  case 149:
#line 881 "yacc_sql.y"
                              {
      // selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], $2);
		  }
#line 2823 "yacc_sql.tab.c"
    break;

  case 151:
#line 887 "yacc_sql.y"
                                     {	
      // CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2831 "yacc_sql.tab.c"
    break;

  case 153:
#line 893 "yacc_sql.y"
                                  {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
        CONTEXT->is_or[S_TOP]=1;
			}
#line 2840 "yacc_sql.tab.c"
    break;

  case 154:
#line 897 "yacc_sql.y"
                                   {
        CONTEXT->is_or[S_TOP]=0;
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2849 "yacc_sql.tab.c"
    break;

  case 155:
#line 903 "yacc_sql.y"
                                                  {
  RelAttr left_attr;

  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  func_attr_init(&left_attr, NULL, (yyvsp[-3].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  
  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2864 "yacc_sql.tab.c"
    break;

  case 156:
#line 914 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

  // printf("current ptr %d\n", CONTEXT->ptr);
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 2881 "yacc_sql.tab.c"
    break;

  case 157:
#line 927 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 2];
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2894 "yacc_sql.tab.c"
    break;

  case 158:
#line 936 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2909 "yacc_sql.tab.c"
    break;

  case 159:
#line 947 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 2924 "yacc_sql.tab.c"
    break;

  case 160:
#line 958 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
  // printf("append condition in %d\n", S_TOP);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 2940 "yacc_sql.tab.c"
    break;

  case 161:
#line 971 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2955 "yacc_sql.tab.c"
    break;

  case 162:
#line 982 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2970 "yacc_sql.tab.c"
    break;

  case 163:
#line 992 "yacc_sql.y"
                     {
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 2985 "yacc_sql.tab.c"
    break;

  case 164:
#line 1002 "yacc_sql.y"
                     {
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3000 "yacc_sql.tab.c"
    break;

  case 165:
#line 1012 "yacc_sql.y"
                                                {
      RelAttr left_attr;
      relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

      value_init_list(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++],
                      &CONTEXT->ssql->valuelists[CONTEXT->in_valuelist_num]);
      Value *value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
      CONTEXT->in_valuelist_num++;

}
#line 3019 "yacc_sql.tab.c"
    break;

  case 166:
#line 1026 "yacc_sql.y"
                                                    {
      RelAttr left_attr;
      relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));

      value_init_list(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++],
                      &CONTEXT->ssql->valuelists[CONTEXT->in_valuelist_num]);
      Value *value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
      CONTEXT->in_valuelist_num++;
    }
#line 3037 "yacc_sql.tab.c"
    break;

  case 167:
#line 1039 "yacc_sql.y"
               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 3050 "yacc_sql.tab.c"
    break;

  case 168:
#line 1047 "yacc_sql.y"
                   {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_NOT_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 3063 "yacc_sql.tab.c"
    break;

  case 169:
#line 1055 "yacc_sql.y"
                               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 1, &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL,
                     0, NULL, right_value);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 3075 "yacc_sql.tab.c"
    break;

  case 170:
#line 1062 "yacc_sql.y"
                               {
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1,
                     &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 3087 "yacc_sql.tab.c"
    break;

  case 171:
#line 1072 "yacc_sql.y"
      {
  Value *value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  int num = CONTEXT->in_valuelist_num;

  selects_append_in_value(&CONTEXT->ssql->valuelists[num], value);

}
#line 3099 "yacc_sql.tab.c"
    break;

  case 173:
#line 1082 "yacc_sql.y"
                               {
}
#line 3106 "yacc_sql.tab.c"
    break;

  case 174:
#line 1086 "yacc_sql.y"
   {
  CONTEXT->comps[S_TOP] = EQUAL_TO;
}
#line 3114 "yacc_sql.tab.c"
    break;

  case 175:
#line 1089 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_THAN; }
#line 3120 "yacc_sql.tab.c"
    break;

  case 176:
#line 1090 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_THAN; }
#line 3126 "yacc_sql.tab.c"
    break;

  case 177:
#line 1091 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_EQUAL; }
#line 3132 "yacc_sql.tab.c"
    break;

  case 178:
#line 1092 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_EQUAL; }
#line 3138 "yacc_sql.tab.c"
    break;

  case 179:
#line 1093 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = NOT_EQUAL; }
#line 3144 "yacc_sql.tab.c"
    break;

  case 180:
#line 1094 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = IS_EQUAL; }
#line 3150 "yacc_sql.tab.c"
    break;

  case 181:
#line 1095 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = IS_NOT_EQUAL; }
#line 3156 "yacc_sql.tab.c"
    break;

  case 182:
#line 1096 "yacc_sql.y"
           { CONTEXT->comps[S_TOP] = STR_NOT_LIKE; }
#line 3162 "yacc_sql.tab.c"
    break;

  case 183:
#line 1097 "yacc_sql.y"
       { CONTEXT->comps[S_TOP] = STR_LIKE; }
#line 3168 "yacc_sql.tab.c"
    break;

  case 184:
#line 1098 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = VALUE_IN; }
#line 3174 "yacc_sql.tab.c"
    break;

  case 185:
#line 1099 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = VALUE_NOT_IN; }
#line 3180 "yacc_sql.tab.c"
    break;

  case 186:
#line 1104 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3189 "yacc_sql.tab.c"
    break;


#line 3193 "yacc_sql.tab.c"

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
      yyerror (scanner, YY_("syntax error"));
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
        yyerror (scanner, yymsgp);
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
                      yytoken, &yylval, scanner);
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
                  yystos[yystate], yyvsp, scanner);
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
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, scanner);
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
#line 1109 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
