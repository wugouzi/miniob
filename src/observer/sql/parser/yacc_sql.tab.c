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

  AggreType aggr_for_func[MAX_NUM];
  RelAttr rel_stack[MAX_NUM];
  char* rel_args[MAX_NUM];
  char* rel_argc[MAX_NUM];
  int fc;
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


#line 192 "yacc_sql.tab.c"

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
#line 198 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 333 "yacc_sql.tab.c"

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
#define YYLAST   452

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  197
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  414

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
       0,   225,   225,   227,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   252,   257,   262,   268,   274,   280,   286,   292,
     298,   305,   312,   318,   326,   328,   334,   341,   350,   352,
     356,   367,   383,   389,   397,   400,   401,   402,   403,   404,
     407,   416,   429,   431,   437,   442,   444,   449,   453,   456,
     460,   463,   466,   473,   484,   495,   500,   502,   507,   515,
     521,   527,   541,   543,   548,   550,   555,   562,   564,   569,
     576,   581,   586,   591,   596,   599,   605,   609,   614,   619,
     624,   631,   649,   652,   655,   658,   661,   667,   671,   675,
     682,   687,   692,   697,   702,   709,   724,   736,   740,   745,
     750,   755,   762,   779,   783,   794,   796,   802,   808,   817,
     819,   822,   825,   828,   832,   834,   839,   844,   849,   854,
     858,   864,   871,   873,   878,   880,   883,   884,   890,   899,
     902,   905,   910,   912,   918,   921,   924,   927,   930,   933,
     936,   939,   942,   945,   948,   951,   954,   959,   961,   965,
     967,   971,   973,   977,   983,  1003,  1024,  1035,  1048,  1057,
    1068,  1079,  1092,  1103,  1114,  1124,  1134,  1148,  1161,  1169,
    1177,  1184,  1194,  1202,  1204,  1208,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1225
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
  "func_expr", "func_attr", "func_extra_args", "aggregation_extra_id",
  "attr_list", "rel_name", "inner_joins", "order", "order_component",
  "order_direction", "order_component_list", "alias", "rel_list", "where",
  "condition_list", "condition", "in_value", "in_value_list", "comOp",
  "load_data", YY_NULLPTR
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

#define YYPACT_NINF (-345)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -345,   322,  -345,    46,   181,  -345,   -18,    16,    65,    41,
      54,    38,   108,   150,   151,   166,   167,   154,  -345,  -345,
    -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,  -345,  -345,   301,   189,  -345,  -345,    74,
     137,   212,   149,   152,   221,   222,   199,  -345,   156,   157,
     200,  -345,  -345,  -345,  -345,  -345,   194,  -345,  -345,  -345,
    -345,  -345,  -345,  -345,  -345,   213,    -9,   203,    -9,   226,
     240,    -9,  -345,   241,   208,   184,   256,   257,  -345,  -345,
     192,   238,   237,   206,   205,   -19,  -345,  -345,  -345,  -345,
    -345,   127,  -345,   264,   264,   210,   264,   111,    43,   264,
     211,   214,   251,  -345,  -345,   286,   273,   145,   289,   254,
     276,   267,    -9,    -9,  -345,  -345,  -345,  -345,  -345,  -345,
     311,  -345,  -345,    -9,   278,  -345,  -345,   280,   280,    69,
     280,  -345,   281,   281,   281,   107,   283,   281,  -345,  -345,
     291,     5,   294,   239,  -345,   295,   295,   303,  -345,   246,
     133,  -345,  -345,  -345,   263,  -345,   328,   328,   299,   328,
       4,  -345,   133,   206,   237,   310,   264,   264,   227,    -9,
      -9,    -9,   258,   210,   237,    97,   302,   306,   244,   308,
     312,    59,   321,   323,   327,   265,   329,  -345,   340,   211,
     357,  -345,  -345,  -345,  -345,  -345,    14,   271,   304,   133,
     273,   273,   359,   133,  -345,   305,  -345,   270,  -345,  -345,
    -345,  -345,  -345,   -17,  -345,  -345,    50,   198,   133,    89,
      37,   145,   145,  -345,  -345,   276,   374,   307,  -345,  -345,
      24,   264,   264,   264,   264,   320,  -345,   278,   319,   280,
     118,   280,  -345,  -345,   280,  -345,  -345,   280,   280,   280,
    -345,  -345,  -345,   281,  -345,  -345,   291,   380,   313,  -345,
     330,   372,   317,   375,  -345,   389,  -345,  -345,   328,  -345,
    -345,  -345,    10,   367,  -345,   369,  -345,  -345,  -345,  -345,
    -345,   281,   281,   119,   381,   281,  -345,  -345,     4,     4,
    -345,  -345,   394,    -9,    -9,  -345,  -345,  -345,  -345,   325,
    -345,   335,   332,  -345,   280,  -345,  -345,   385,  -345,  -345,
    -345,   386,  -345,  -345,  -345,   387,  -345,   331,   390,   372,
     133,   391,  -345,   165,  -345,   388,   336,   337,   392,   395,
     339,   397,  -345,   398,  -345,  -345,  -345,   264,   264,    -9,
     342,   145,   355,  -345,  -345,  -345,  -345,   372,   415,   402,
     375,  -345,    10,   393,  -345,   133,   404,  -345,  -345,  -345,
    -345,   281,  -345,  -345,  -345,  -345,   396,   140,     4,   358,
    -345,  -345,  -345,   419,  -345,   388,   350,   388,  -345,   408,
     145,   352,   353,  -345,  -345,   354,  -345,   412,  -345,  -345,
    -345,     4,   146,   414,    11,   416,  -345,   258,   356,  -345,
    -345,  -345,   361,  -345,  -345,   354,  -345,  -345,   414,    15,
     416,  -345,  -345,  -345
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
      94,    96,    97,    98,    99,   144,   144,    70,   144,     0,
       0,   144,    71,     0,     0,     0,     0,     0,    30,    29,
       0,     0,   159,     0,     0,     0,   150,   151,   148,   147,
     149,     0,   146,   124,   124,     0,   124,     0,     0,   124,
       0,     0,     0,    28,    36,     0,    52,     0,     0,     0,
      66,     0,   144,   144,   155,   156,   153,   152,   154,   145,
       0,    82,    80,   144,   157,    84,    88,   119,   119,   119,
     119,   109,   115,   115,   115,   115,     0,   115,    85,    50,
      38,     0,     0,     0,    31,     0,     0,     0,    61,     0,
       0,    57,    60,    58,     0,    59,     0,     0,     0,     0,
     161,    63,     0,     0,   159,     0,   124,   124,   144,   144,
     144,   144,   132,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
       0,    45,    46,    47,    48,    49,    41,     0,     0,     0,
      52,    52,     0,     0,   178,     0,   185,   191,   186,   187,
     188,   189,   190,     0,   194,   195,     0,     0,     0,     0,
       0,     0,     0,   160,    65,    66,     0,     0,    83,    81,
       0,   124,   124,   124,   124,     0,   131,   157,    74,   119,
     119,   119,    90,    91,   119,    86,    89,   119,   119,   119,
     111,   113,   112,   115,   107,   110,    38,     0,     0,    42,
       0,    34,     0,    55,    53,     0,    62,   179,     0,   192,
     193,   196,     0,   169,   167,   170,   168,   181,   165,   180,
     102,   115,   115,   115,     0,   115,   164,   166,   161,   161,
      67,    64,     0,   144,   144,   125,   127,   129,   130,     0,
     158,     0,    72,   123,   119,   120,   122,     0,   116,   118,
     117,     0,    39,    37,    44,     0,    43,     0,     0,    34,
       0,     0,    51,     0,   182,   183,     0,     0,     0,     0,
       0,     0,   106,     0,   163,   162,   197,   124,   124,   144,
       0,     0,   134,   121,    87,   108,    40,    34,     0,     0,
      55,    54,     0,   174,   171,     0,     0,   175,   172,   104,
     105,   115,   100,   103,   126,   128,     0,    77,   161,     0,
      69,    35,    32,     0,    56,   183,     0,   183,   176,     0,
       0,     0,     0,    75,    73,   136,    33,     0,   173,   184,
     101,   161,    77,    77,   141,   142,   177,   132,     0,    78,
      76,   140,     0,   139,   137,   136,   135,   133,    77,   141,
     142,    79,   138,   143
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,  -345,  -285,  -345,  -345,   177,   247,  -345,
    -345,  -345,  -345,  -101,   292,    87,  -140,  -345,  -345,   277,
     216,  -345,   438,  -345,  -345,  -345,  -344,  -345,   -31,  -345,
     -23,  -132,   324,  -126,   -97,   -93,   269,    48,  -345,    42,
      34,    36,   -66,   215,  -129,  -273,  -208,    93,  -167,  -139,
    -345
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   318,    30,    31,   190,   140,   315,
     196,   141,    32,   146,   200,   321,   156,    33,    34,   110,
     164,    35,   202,    37,   342,   302,   383,    67,   157,    69,
     158,   159,    71,   182,   176,   121,   124,   236,   370,   395,
     404,   406,    93,   174,   108,   223,   160,   325,   356,   216,
      38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,   122,    96,   125,    68,    99,   138,   183,   184,   186,
     204,   188,    70,   288,   289,   334,   335,   217,   218,     5,
     220,   401,   224,    45,    46,   401,   147,   191,   192,   193,
     258,   177,   179,   180,   349,   226,   221,   222,   402,    86,
      87,    88,    89,    90,   270,   238,   166,   167,   399,   400,
     271,   194,    39,   147,    40,   112,    44,   172,   113,   263,
     131,    91,   371,   267,   411,    92,   272,   148,    47,    48,
     259,   195,   260,   228,   229,   403,   274,   276,   279,   403,
     286,   151,   152,   153,    49,   278,   155,   175,   287,   170,
      62,    63,    64,    41,   148,   384,   178,    70,   293,   264,
     265,   294,   231,   232,   233,   234,   280,   148,   151,   152,
     153,    51,    50,   155,   132,   133,   134,   135,   397,   136,
     137,   151,   152,   153,   273,   181,   155,   311,   126,   323,
     247,   248,   324,   368,   185,   249,   175,   181,   295,   296,
     297,   298,   303,   305,   306,   304,   330,   307,    73,   147,
     308,   309,   310,    52,    53,   328,   329,   331,   381,   333,
     281,   147,   282,   283,   381,   284,   285,   382,   239,    54,
      55,   240,   391,   398,   241,   114,   115,   116,   117,   118,
     350,   352,   127,   354,   128,   129,   277,    42,   130,    43,
     148,    56,    72,    57,    58,    59,    60,    61,    62,    63,
      64,   119,   148,   149,   151,   152,   153,   343,   387,   155,
     389,    74,   375,   150,   147,   324,   151,   152,   153,   154,
      75,   155,   148,    76,    78,    79,    77,   337,   338,    80,
      81,    82,    84,    95,    83,   379,   151,   152,   153,   353,
      85,   155,    97,   101,   364,   365,    57,    58,    59,    60,
      61,    62,    63,    64,   230,   148,    98,   100,   102,   103,
     104,    86,    87,    88,    89,    90,   105,   106,   107,   151,
     152,   153,   275,   366,   155,    86,    87,    88,    89,    90,
     109,   111,   120,    91,   123,   139,   143,    92,   142,   144,
     205,   145,   161,   162,   163,   165,   173,    91,   175,   181,
     187,    92,   206,   207,   208,   209,   210,   211,   212,   189,
     197,   199,     5,   198,   203,   219,   227,   235,   244,   242,
     262,   213,     2,   243,   214,   245,     3,     4,   269,   246,
     215,     5,     6,     7,     8,     9,    10,    11,   250,   253,
     251,    12,    13,    14,   252,   261,   254,    15,    16,    57,
      58,    59,    60,    61,    62,    63,    64,   255,    17,    57,
      58,    59,    60,    61,    62,    63,    64,   206,   207,   208,
     209,   210,   211,   212,   257,    65,   266,   291,    66,   268,
     299,   292,   301,   313,   314,   168,   213,   316,   169,   214,
     317,   319,   322,   320,   326,   215,   327,   336,   332,   339,
     340,   341,   344,   345,   346,   347,   355,   348,   351,   359,
     357,   358,   360,   361,   362,   363,   367,   369,   372,   373,
     376,   378,   386,   385,   388,   390,   392,   393,   394,   396,
     408,   380,   381,   312,   405,   409,   256,   374,   201,    36,
     225,   290,   237,   412,   171,   407,   413,   410,   377,     0,
       0,     0,   300
};

static const yytype_int16 yycheck[] =
{
      66,    94,    68,    96,    35,    71,    99,   133,   134,   135,
     150,   137,    35,   221,   222,   288,   289,   156,   157,     9,
     159,    10,   162,     7,     8,    10,    16,    22,    23,    24,
      16,   128,   129,   130,   319,   164,    32,    33,    27,    48,
      49,    50,    51,    52,    61,   174,   112,   113,   392,   393,
      67,    46,     6,    16,     8,    74,    74,   123,    77,   199,
      17,    70,   347,   203,   408,    74,    16,    57,     3,    28,
      56,    66,    58,   166,   167,    64,   216,   217,   218,    64,
     220,    71,    72,    73,    30,   217,    76,    18,   220,   120,
      53,    54,    55,    47,    57,   368,    27,   120,    74,   200,
     201,    77,   168,   169,   170,   171,    17,    57,    71,    72,
      73,     3,    74,    76,    71,    72,    73,    74,   391,    76,
      77,    71,    72,    73,    74,    18,    76,   253,    17,   268,
      71,    72,   272,   341,    27,    76,    18,    18,   231,   232,
     233,   234,   239,   240,   241,    27,    27,   244,    74,    16,
     247,   248,   249,     3,     3,   281,   282,   283,    18,   285,
      71,    16,    73,    74,    18,    76,    77,    27,    71,     3,
       3,    74,   380,    27,    77,    48,    49,    50,    51,    52,
     320,    16,    71,   323,    73,    74,   217,     6,    77,     8,
      57,    37,     3,    48,    49,    50,    51,    52,    53,    54,
      55,    74,    57,    58,    71,    72,    73,   304,   375,    76,
     377,    74,   352,    68,    16,   355,    71,    72,    73,    74,
       8,    76,    57,    74,     3,     3,    74,   293,   294,    30,
      74,    74,    38,    30,    34,   361,    71,    72,    73,    74,
      27,    76,    16,    35,   337,   338,    48,    49,    50,    51,
      52,    53,    54,    55,    27,    57,    16,    16,    74,     3,
       3,    48,    49,    50,    51,    52,    74,    29,    31,    71,
      72,    73,    74,   339,    76,    48,    49,    50,    51,    52,
      74,    76,    18,    70,    74,    74,    35,    74,    74,     3,
      27,    18,     3,    39,    18,    28,    18,    70,    18,    18,
      17,    74,    39,    40,    41,    42,    43,    44,    45,    18,
      16,    16,     9,    74,    68,    16,     6,    59,    74,    17,
      16,    58,     0,    17,    61,    17,     4,     5,    58,    17,
      67,     9,    10,    11,    12,    13,    14,    15,    17,    74,
      17,    19,    20,    21,    17,    74,    17,    25,    26,    48,
      49,    50,    51,    52,    53,    54,    55,    17,    36,    48,
      49,    50,    51,    52,    53,    54,    55,    39,    40,    41,
      42,    43,    44,    45,    17,    74,    17,     3,    77,    74,
      60,    74,    63,     3,    71,    74,    58,    57,    77,    61,
      18,    74,     3,    18,    27,    67,    27,     3,    17,    74,
      65,    69,    17,    17,    17,    74,    18,    17,    17,    17,
      74,    74,    17,    74,    17,    17,    74,    62,     3,    17,
      27,    17,     3,    65,    74,    17,    74,    74,    74,    17,
      74,    35,    18,   256,    18,    74,   189,   350,   146,     1,
     163,   225,   173,   409,   120,   397,   410,   405,   355,    -1,
      -1,    -1,   237
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    36,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      94,    95,   101,   106,   107,   110,   111,   112,   139,     6,
       8,    47,     6,     8,    74,     7,     8,     3,    28,    30,
      74,     3,     3,     3,     3,     3,    37,    48,    49,    50,
      51,    52,    53,    54,    55,    74,    77,   116,   117,   118,
     119,   121,     3,    74,    74,     8,    74,    74,     3,     3,
      30,    74,    74,    34,    38,    27,    48,    49,    50,    51,
      52,    70,    74,   131,   131,    30,   131,    16,    16,   131,
      16,    35,    74,     3,     3,    74,    29,    31,   133,    74,
     108,    76,    74,    77,    48,    49,    50,    51,    52,    74,
      18,   124,   124,    74,   125,   124,    17,    71,    73,    74,
      77,    17,    71,    72,    73,    74,    76,    77,   124,    74,
      97,   100,    74,    35,     3,    18,   102,    16,    57,    58,
      68,    71,    72,    73,    74,    76,   105,   117,   119,   120,
     135,     3,    39,    18,   109,    28,   131,   131,    74,    77,
     117,   121,   131,    18,   132,    18,   123,   123,    27,   123,
     123,    18,   122,   122,   122,    27,   122,    17,   122,    18,
      96,    22,    23,    24,    46,    66,    99,    16,    74,    16,
     103,   103,   111,    68,   105,    27,    39,    40,    41,    42,
      43,    44,    45,    58,    61,    67,   138,   138,   138,    16,
     138,    32,    33,   134,   105,   108,   133,     6,   124,   124,
      27,   131,   131,   131,   131,    59,   126,   125,   133,    71,
      74,    77,    17,    17,    74,    17,    17,    71,    72,    76,
      17,    17,    17,    74,    17,    17,    97,    17,    16,    56,
      58,    74,    16,   105,   102,   102,    17,   105,    74,    58,
      61,    67,    16,    74,   105,    74,   105,   117,   120,   105,
      17,    71,    73,    74,    76,    77,   105,   120,   135,   135,
     109,     3,    74,    74,    77,   124,   124,   124,   124,    60,
     132,    63,   114,   123,    27,   123,   123,   123,   123,   123,
     123,   122,    96,     3,    71,    98,    57,    18,    93,    74,
      18,   104,     3,   138,   105,   136,    27,    27,   122,   122,
      27,   122,    17,   122,   134,   134,     3,   131,   131,    74,
      65,    69,   113,   123,    17,    17,    17,    74,    17,    93,
     105,    17,    16,    74,   105,    18,   137,    74,    74,    17,
      17,    74,    17,    17,   124,   124,   131,    74,   135,    62,
     127,    93,     3,    17,   104,   105,    27,   136,    17,   122,
      35,    18,    27,   115,   134,    65,     3,   137,    74,   137,
      17,   135,    74,    74,    74,   128,    17,   134,    27,   115,
     115,    10,    27,    64,   129,    18,   130,   126,    74,    74,
     128,   115,   129,   130
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
     121,   121,   121,   121,   121,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   139
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
       5,     7,     3,     5,     5,     5,     4,     5,     7,     3,
       5,     5,     5,     5,     4,     0,     3,     3,     3,     0,
       3,     4,     3,     3,     0,     4,     6,     4,     6,     4,
       4,     3,     0,     8,     0,     4,     0,     2,     4,     1,
       1,     0,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     7,     5,     5,     6,     8,     2,     3,
       3,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     8
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
#line 252 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1820 "yacc_sql.tab.c"
    break;

  case 23:
#line 257 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1828 "yacc_sql.tab.c"
    break;

  case 24:
#line 262 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1836 "yacc_sql.tab.c"
    break;

  case 25:
#line 268 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1844 "yacc_sql.tab.c"
    break;

  case 26:
#line 274 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1852 "yacc_sql.tab.c"
    break;

  case 27:
#line 280 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1860 "yacc_sql.tab.c"
    break;

  case 28:
#line 286 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1869 "yacc_sql.tab.c"
    break;

  case 29:
#line 292 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1877 "yacc_sql.tab.c"
    break;

  case 30:
#line 298 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1886 "yacc_sql.tab.c"
    break;

  case 31:
#line 305 "yacc_sql.y"
                             {
  CONTEXT->ssql->flag = SCF_SHOW_INDEX;
  show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
}
#line 1895 "yacc_sql.tab.c"
    break;

  case 32:
#line 313 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
}
#line 1905 "yacc_sql.tab.c"
    break;

  case 33:
#line 319 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
}
#line 1915 "yacc_sql.tab.c"
    break;

  case 35:
#line 328 "yacc_sql.y"
                      {
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
}
#line 1923 "yacc_sql.tab.c"
    break;

  case 36:
#line 335 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1932 "yacc_sql.tab.c"
    break;

  case 37:
#line 342 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_lengths[S_TOP] = 0;
		}
#line 1944 "yacc_sql.tab.c"
    break;

  case 39:
#line 352 "yacc_sql.y"
                                   {    }
#line 1950 "yacc_sql.tab.c"
    break;

  case 40:
#line 357 "yacc_sql.y"
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
#line 1965 "yacc_sql.tab.c"
    break;

  case 41:
#line 368 "yacc_sql.y"
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
#line 1985 "yacc_sql.tab.c"
    break;

  case 42:
#line 383 "yacc_sql.y"
                       {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 1996 "yacc_sql.tab.c"
    break;

  case 43:
#line 389 "yacc_sql.y"
                         {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 2007 "yacc_sql.tab.c"
    break;

  case 44:
#line 397 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2013 "yacc_sql.tab.c"
    break;

  case 45:
#line 400 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2019 "yacc_sql.tab.c"
    break;

  case 46:
#line 401 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2025 "yacc_sql.tab.c"
    break;

  case 47:
#line 402 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2031 "yacc_sql.tab.c"
    break;

  case 48:
#line 403 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 2037 "yacc_sql.tab.c"
    break;

  case 49:
#line 404 "yacc_sql.y"
         { (yyval.number)=TEXTS; }
#line 2043 "yacc_sql.tab.c"
    break;

  case 50:
#line 408 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string);
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2052 "yacc_sql.tab.c"
    break;

  case 51:
#line 417 "yacc_sql.y"
{
  // CONTEXT->values[CONTEXT->value_length++] = *$6;

  CONTEXT->ssql->flag=SCF_INSERT;//"insert";
  inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-5].string));
  //inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length);

  //临时变量清零
  CONTEXT->value_lengths[S_TOP]=0;
}
#line 2067 "yacc_sql.tab.c"
    break;

  case 53:
#line 431 "yacc_sql.y"
                                    {

}
#line 2075 "yacc_sql.tab.c"
    break;

  case 54:
#line 437 "yacc_sql.y"
                               {
inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values[S_TOP], CONTEXT->value_lengths[S_TOP]);
CONTEXT->value_lengths[S_TOP] = 0;
}
#line 2084 "yacc_sql.tab.c"
    break;

  case 56:
#line 444 "yacc_sql.y"
                              {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2092 "yacc_sql.tab.c"
    break;

  case 57:
#line 449 "yacc_sql.y"
          {
      value_init_integer(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].number));
  		// value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
#line 2101 "yacc_sql.tab.c"
    break;

  case 58:
#line 453 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].floats));
		}
#line 2109 "yacc_sql.tab.c"
    break;

  case 59:
#line 456 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
		}
#line 2118 "yacc_sql.tab.c"
    break;

  case 60:
#line 460 "yacc_sql.y"
              {
        value_init_date(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
    }
#line 2126 "yacc_sql.tab.c"
    break;

  case 61:
#line 463 "yacc_sql.y"
         {
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
    }
#line 2134 "yacc_sql.tab.c"
    break;

  case 62:
#line 466 "yacc_sql.y"
                        {
  value_init_select(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++],
                    &CONTEXT->ssql->selects[CONTEXT->stack[CONTEXT->ptr+1]]);
}
#line 2143 "yacc_sql.tab.c"
    break;

  case 63:
#line 474 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion,
					CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
			CONTEXT->condition_lengths[S_TOP] = 0;
    }
#line 2155 "yacc_sql.tab.c"
    break;

  case 64:
#line 485 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_UPDATE;//"update";
  updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string),
               CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
  CONTEXT->condition_lengths[S_TOP] = 0;
  CONTEXT->value_lengths[S_TOP] = 0;
}
#line 2167 "yacc_sql.tab.c"
    break;

  case 65:
#line 495 "yacc_sql.y"
            {
  // updates_append(&CONTEXT->ssql->sstr.update, $1, &CONTEXT->values[CONTEXT->value_lengths[S_TOP] - 1]);
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1]);
}
#line 2176 "yacc_sql.tab.c"
    break;

  case 67:
#line 502 "yacc_sql.y"
                                {
}
#line 2183 "yacc_sql.tab.c"
    break;

  case 68:
#line 507 "yacc_sql.y"
       {
  CONTEXT->stack[++CONTEXT->ptr] = ++CONTEXT->selects_num;
  // printf("push select %zu, ptr: %d\n", CONTEXT->selects_num, CONTEXT->ptr);
  // CONTEXT->selects_num++;
  CONTEXT->ssql->selects_num = CONTEXT->selects_num;
}
#line 2194 "yacc_sql.tab.c"
    break;

  case 69:
#line 515 "yacc_sql.y"
                                                                          {
  printf("SELECT: num: %d, ptr: %d pop, table: %s, cond num: %d\n", S_TOP, CONTEXT->ptr, CONTEXT->ssql->selects[S_TOP].relations[0], CONTEXT->condition_lengths[S_TOP]);
  selects_append_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
  selects_append_having_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->having_conditions[S_TOP], CONTEXT->having_condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
  CONTEXT->ptr--;
}
#line 2205 "yacc_sql.tab.c"
    break;

  case 70:
#line 521 "yacc_sql.y"
                          {
  selects_append_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP], CONTEXT->is_or[S_TOP]);
}
#line 2213 "yacc_sql.tab.c"
    break;

  case 71:
#line 528 "yacc_sql.y"
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
#line 2230 "yacc_sql.tab.c"
    break;

  case 73:
#line 543 "yacc_sql.y"
                                  {

}
#line 2238 "yacc_sql.tab.c"
    break;

  case 75:
#line 550 "yacc_sql.y"
                          {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2248 "yacc_sql.tab.c"
    break;

  case 76:
#line 555 "yacc_sql.y"
                                 {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2258 "yacc_sql.tab.c"
    break;

  case 78:
#line 564 "yacc_sql.y"
                       {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2268 "yacc_sql.tab.c"
    break;

  case 79:
#line 569 "yacc_sql.y"
                              {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2278 "yacc_sql.tab.c"
    break;

  case 80:
#line 576 "yacc_sql.y"
                     {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2288 "yacc_sql.tab.c"
    break;

  case 81:
#line 581 "yacc_sql.y"
                              {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2298 "yacc_sql.tab.c"
    break;

  case 82:
#line 586 "yacc_sql.y"
                     {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2308 "yacc_sql.tab.c"
    break;

  case 83:
#line 591 "yacc_sql.y"
                            {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2318 "yacc_sql.tab.c"
    break;

  case 84:
#line 596 "yacc_sql.y"
                                   {
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2326 "yacc_sql.tab.c"
    break;

  case 85:
#line 599 "yacc_sql.y"
                            {
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2334 "yacc_sql.tab.c"
    break;

  case 86:
#line 605 "yacc_sql.y"
                                                       {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2343 "yacc_sql.tab.c"
    break;

  case 87:
#line 609 "yacc_sql.y"
                                                                {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2353 "yacc_sql.tab.c"
    break;

  case 88:
#line 614 "yacc_sql.y"
                                 {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "fail", A_FAILURE, 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2363 "yacc_sql.tab.c"
    break;

  case 89:
#line 619 "yacc_sql.y"
                                                           {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "*", CONTEXT->a_types[S_TOP] != A_COUNT ? A_FAILURE : CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2373 "yacc_sql.tab.c"
    break;

  case 90:
#line 624 "yacc_sql.y"
                                                             {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, str, CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2385 "yacc_sql.tab.c"
    break;

  case 91:
#line 631 "yacc_sql.y"
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
#line 2405 "yacc_sql.tab.c"
    break;

  case 92:
#line 649 "yacc_sql.y"
    {
  CONTEXT->a_types[S_TOP] = A_MAX;
}
#line 2413 "yacc_sql.tab.c"
    break;

  case 93:
#line 652 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_MIN;
}
#line 2421 "yacc_sql.tab.c"
    break;

  case 94:
#line 655 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_AVG;
}
#line 2429 "yacc_sql.tab.c"
    break;

  case 95:
#line 658 "yacc_sql.y"
        {
  CONTEXT->a_types[S_TOP] = A_COUNT;
}
#line 2437 "yacc_sql.tab.c"
    break;

  case 96:
#line 661 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_SUM;
}
#line 2445 "yacc_sql.tab.c"
    break;

  case 97:
#line 667 "yacc_sql.y"
       {
  CONTEXT->a_types[S_TOP] = A_LENGTH;
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_LENGTH;
}
#line 2454 "yacc_sql.tab.c"
    break;

  case 98:
#line 671 "yacc_sql.y"
        {
  CONTEXT->a_types[S_TOP] = A_ROUND;
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_ROUND;
}
#line 2463 "yacc_sql.tab.c"
    break;

  case 99:
#line 675 "yacc_sql.y"
              {
  CONTEXT->a_types[S_TOP] = A_DATE_FORMAT;
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_DATE_FORMAT;
}
#line 2472 "yacc_sql.tab.c"
    break;

  case 100:
#line 682 "yacc_sql.y"
                                                      {
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, (yyvsp[-2].string), CONTEXT->aggr_for_func[CONTEXT->fc], 0, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2482 "yacc_sql.tab.c"
    break;

  case 101:
#line 687 "yacc_sql.y"
                                                               {
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->aggr_for_func[CONTEXT->fc], 0, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2492 "yacc_sql.tab.c"
    break;

  case 102:
#line 692 "yacc_sql.y"
                                     {
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, "fail", A_FAILURE, 0, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2502 "yacc_sql.tab.c"
    break;

  case 103:
#line 697 "yacc_sql.y"
                                                          {
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, "*", CONTEXT->aggr_for_func[CONTEXT->fc] != A_COUNT ? A_FAILURE : CONTEXT->aggr_for_func[CONTEXT->fc], 1, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2512 "yacc_sql.tab.c"
    break;

  case 104:
#line 702 "yacc_sql.y"
                                                            {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, str, CONTEXT->aggr_for_func[CONTEXT->fc], 1, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2524 "yacc_sql.tab.c"
    break;

  case 105:
#line 709 "yacc_sql.y"
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
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, buf, CONTEXT->aggr_for_func[CONTEXT->fc], 1, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_NO;
  CONTEXT->fc++;
}
#line 2544 "yacc_sql.tab.c"
    break;

  case 106:
#line 724 "yacc_sql.y"
                                         {
  char s[1000];
  memset(s, 0, sizeof(s));
  sprintf(s,"length(%s)", (yyvsp[-1].string));
  printf("hahaa=%s\n", s);
  CONTEXT->aggr_for_func[CONTEXT->fc] = A_LENGTH;
  func_attr_init(&CONTEXT->rel_stack[CONTEXT->fc], NULL, (yyvsp[-1].string), CONTEXT->aggr_for_func[CONTEXT->fc], 0, CONTEXT->rel_argc[CONTEXT->fc], CONTEXT->rel_args[CONTEXT->fc]);
  CONTEXT->fc++;
}
#line 2558 "yacc_sql.tab.c"
    break;

  case 107:
#line 736 "yacc_sql.y"
                                                      {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2567 "yacc_sql.tab.c"
    break;

  case 108:
#line 740 "yacc_sql.y"
                                                               {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2577 "yacc_sql.tab.c"
    break;

  case 109:
#line 745 "yacc_sql.y"
                                     {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "fail", A_FAILURE, 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2587 "yacc_sql.tab.c"
    break;

  case 110:
#line 750 "yacc_sql.y"
                                                          {
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "*", CONTEXT->a_types[S_TOP] != A_COUNT ? A_FAILURE : CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2597 "yacc_sql.tab.c"
    break;

  case 111:
#line 755 "yacc_sql.y"
                                                            {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, str, CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2609 "yacc_sql.tab.c"
    break;

  case 112:
#line 762 "yacc_sql.y"
                                                           {
  char *buf = malloc(20 * sizeof(char));
  // printf("3=%f\n", $3);
  snprintf(buf, 20, "%.4f", (yyvsp[-2].floats));
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
  }
  if (buf[len - 1] == '.') {
    len--;
  }
  buf[len] = '\0';
  // printf("buf=%s\n", buf);
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, buf, CONTEXT->a_types[S_TOP], 1, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2631 "yacc_sql.tab.c"
    break;

  case 113:
#line 779 "yacc_sql.y"
                                                              {
  CONTEXT->a_types[S_TOP] = A_DATE_FORMAT;
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
}
#line 2640 "yacc_sql.tab.c"
    break;

  case 114:
#line 783 "yacc_sql.y"
                                         {
  char s[1000];
  memset(s, 0, sizeof(s));
  sprintf(s,"length(%s)", (yyvsp[-1].string));
  // printf("hahaa=%s\n", s);
  CONTEXT->a_types[S_TOP] = A_LENGTH;
  func_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-1].string), CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
}
#line 2653 "yacc_sql.tab.c"
    break;

  case 116:
#line 796 "yacc_sql.y"
                                    {
  CONTEXT->args[S_TOP] = (yyvsp[-1].number);
  CONTEXT->argc[S_TOP]++;
  CONTEXT->rel_args[CONTEXT->fc] = (yyvsp[-1].number);
  CONTEXT->rel_argc[CONTEXT->fc]++;
}
#line 2664 "yacc_sql.tab.c"
    break;

  case 117:
#line 802 "yacc_sql.y"
                                 {
  CONTEXT->args[S_TOP] = strdup((yyvsp[-1].string));
  CONTEXT->argc[S_TOP]++;
  CONTEXT->rel_args[CONTEXT->fc] = strdup((yyvsp[-1].string));
  CONTEXT->rel_argc[CONTEXT->fc]++;
}
#line 2675 "yacc_sql.tab.c"
    break;

  case 118:
#line 808 "yacc_sql.y"
                                      {
  CONTEXT->args[S_TOP] = strdup((yyvsp[-1].string));
  CONTEXT->argc[S_TOP]++;
  CONTEXT->rel_args[CONTEXT->fc] = strdup((yyvsp[-1].string));
  CONTEXT->rel_argc[CONTEXT->fc]++;
}
#line 2686 "yacc_sql.tab.c"
    break;

  case 120:
#line 819 "yacc_sql.y"
                                {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2694 "yacc_sql.tab.c"
    break;

  case 121:
#line 822 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2702 "yacc_sql.tab.c"
    break;

  case 122:
#line 825 "yacc_sql.y"
                                  {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2710 "yacc_sql.tab.c"
    break;

  case 123:
#line 828 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2718 "yacc_sql.tab.c"
    break;

  case 125:
#line 834 "yacc_sql.y"
                           {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2728 "yacc_sql.tab.c"
    break;

  case 126:
#line 839 "yacc_sql.y"
                                  {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2738 "yacc_sql.tab.c"
    break;

  case 127:
#line 844 "yacc_sql.y"
                             {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2748 "yacc_sql.tab.c"
    break;

  case 128:
#line 849 "yacc_sql.y"
                                    {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-4].string), "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2758 "yacc_sql.tab.c"
    break;

  case 129:
#line 854 "yacc_sql.y"
                                         {
  printf("append aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2767 "yacc_sql.tab.c"
    break;

  case 130:
#line 858 "yacc_sql.y"
                                  {
  printf("append map func aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
}
#line 2776 "yacc_sql.tab.c"
    break;

  case 131:
#line 864 "yacc_sql.y"
                     {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-2].string), CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
  selects_reverse_relations(&CONTEXT->ssql->selects[S_TOP], ++CONTEXT->joins);
  CONTEXT->joins = 0;
}
#line 2786 "yacc_sql.tab.c"
    break;

  case 133:
#line 873 "yacc_sql.y"
                                                              {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-5].string), CONTEXT->alias[S_TOP][--CONTEXT->alias_lengths[S_TOP]]);
  CONTEXT->joins++;
}
#line 2795 "yacc_sql.tab.c"
    break;

  case 135:
#line 880 "yacc_sql.y"
                                                    {
    }
#line 2802 "yacc_sql.tab.c"
    break;

  case 137:
#line 884 "yacc_sql.y"
                       {
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2813 "yacc_sql.tab.c"
    break;

  case 138:
#line 890 "yacc_sql.y"
                              {
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2824 "yacc_sql.tab.c"
    break;

  case 139:
#line 899 "yacc_sql.y"
     {
  CONTEXT->is_desc = 0;
 }
#line 2832 "yacc_sql.tab.c"
    break;

  case 140:
#line 902 "yacc_sql.y"
        {
  CONTEXT->is_desc = 1;
 }
#line 2840 "yacc_sql.tab.c"
    break;

  case 141:
#line 905 "yacc_sql.y"
   {
  CONTEXT->is_desc = 0;
 }
#line 2848 "yacc_sql.tab.c"
    break;

  case 143:
#line 912 "yacc_sql.y"
                                                 {
      // 啥都不干
    }
#line 2856 "yacc_sql.tab.c"
    break;

  case 144:
#line 918 "yacc_sql.y"
{
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = NULL;
}
#line 2864 "yacc_sql.tab.c"
    break;

  case 145:
#line 921 "yacc_sql.y"
        {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = (yyvsp[0].string);
 }
#line 2872 "yacc_sql.tab.c"
    break;

  case 146:
#line 924 "yacc_sql.y"
     {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = (yyvsp[0].string);
 }
#line 2880 "yacc_sql.tab.c"
    break;

  case 147:
#line 927 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "avg";
}
#line 2888 "yacc_sql.tab.c"
    break;

  case 148:
#line 930 "yacc_sql.y"
        {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "count";
}
#line 2896 "yacc_sql.tab.c"
    break;

  case 149:
#line 933 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "sum";
}
#line 2904 "yacc_sql.tab.c"
    break;

  case 150:
#line 936 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "max";
}
#line 2912 "yacc_sql.tab.c"
    break;

  case 151:
#line 939 "yacc_sql.y"
      {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "min";
}
#line 2920 "yacc_sql.tab.c"
    break;

  case 152:
#line 942 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "avg";
}
#line 2928 "yacc_sql.tab.c"
    break;

  case 153:
#line 945 "yacc_sql.y"
           {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "count";
}
#line 2936 "yacc_sql.tab.c"
    break;

  case 154:
#line 948 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "sum";
}
#line 2944 "yacc_sql.tab.c"
    break;

  case 155:
#line 951 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "max";
}
#line 2952 "yacc_sql.tab.c"
    break;

  case 156:
#line 954 "yacc_sql.y"
         {
  CONTEXT->alias[S_TOP][CONTEXT->alias_lengths[S_TOP]++] = "min";
}
#line 2960 "yacc_sql.tab.c"
    break;

  case 158:
#line 961 "yacc_sql.y"
                              {
      // selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], $2);
		  }
#line 2968 "yacc_sql.tab.c"
    break;

  case 160:
#line 967 "yacc_sql.y"
                                     {	
      // CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2976 "yacc_sql.tab.c"
    break;

  case 162:
#line 973 "yacc_sql.y"
                                  {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
        CONTEXT->is_or[S_TOP]=1;
			}
#line 2985 "yacc_sql.tab.c"
    break;

  case 163:
#line 977 "yacc_sql.y"
                                   {
        CONTEXT->is_or[S_TOP]=0;
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2994 "yacc_sql.tab.c"
    break;

  case 164:
#line 983 "yacc_sql.y"
                      {
  RelAttr* left_attr = &CONTEXT->rel_stack[CONTEXT->fc-1];

  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  // func_attr_init(&left_attr, NULL, $3, CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  
  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, left_attr, NULL, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3009 "yacc_sql.tab.c"
    break;

  case 165:
#line 1003 "yacc_sql.y"
                        {
  RelAttr* right_attr = &CONTEXT->rel_stack[CONTEXT->fc-1];

  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  // func_attr_init(&right_attr, NULL, $6, CONTEXT->a_types[S_TOP], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3024 "yacc_sql.tab.c"
    break;

  case 166:
#line 1024 "yacc_sql.y"
                            {
  RelAttr* left_attr = &CONTEXT->rel_stack[CONTEXT->fc-2];
  RelAttr* right_attr = &CONTEXT->rel_stack[CONTEXT->fc-1];

  // func_attr_init(&left_attr, $3, $5, CONTEXT->aggr_for_func[CONTEXT->fc-2], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);
  // func_attr_init(&right_attr, $10, $12,CONTEXT->aggr_for_func[CONTEXT->fc-1], 0, CONTEXT->argc[S_TOP], CONTEXT->args[S_TOP]);

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, left_attr, NULL, 1, right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3040 "yacc_sql.tab.c"
    break;

  case 167:
#line 1036 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

  // printf("current ptr %d\n", CONTEXT->ptr);
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 3057 "yacc_sql.tab.c"
    break;

  case 168:
#line 1049 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 2];
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 0, NULL, right_value);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3070 "yacc_sql.tab.c"
    break;

  case 169:
#line 1058 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3085 "yacc_sql.tab.c"
    break;

  case 170:
#line 1069 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 3100 "yacc_sql.tab.c"
    break;

  case 171:
#line 1080 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
  Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
  // printf("append condition in %d\n", S_TOP);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

}
#line 3116 "yacc_sql.tab.c"
    break;

  case 172:
#line 1093 "yacc_sql.y"
{
  Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3131 "yacc_sql.tab.c"
    break;

  case 173:
#line 1104 "yacc_sql.y"
{
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3146 "yacc_sql.tab.c"
    break;

  case 174:
#line 1114 "yacc_sql.y"
                     {
  RelAttr left_attr;
  relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3161 "yacc_sql.tab.c"
    break;

  case 175:
#line 1124 "yacc_sql.y"
                     {
  RelAttr left_attr;
  relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
  RelAttr right_attr;
  relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

  Condition condition;
  condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
  CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
}
#line 3176 "yacc_sql.tab.c"
    break;

  case 176:
#line 1134 "yacc_sql.y"
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
#line 3195 "yacc_sql.tab.c"
    break;

  case 177:
#line 1148 "yacc_sql.y"
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
#line 3213 "yacc_sql.tab.c"
    break;

  case 178:
#line 1161 "yacc_sql.y"
               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 3226 "yacc_sql.tab.c"
    break;

  case 179:
#line 1169 "yacc_sql.y"
                   {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_NOT_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 3239 "yacc_sql.tab.c"
    break;

  case 180:
#line 1177 "yacc_sql.y"
                               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 1, &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL,
                     0, NULL, right_value);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 3251 "yacc_sql.tab.c"
    break;

  case 181:
#line 1184 "yacc_sql.y"
                               {
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1,
                     &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 3263 "yacc_sql.tab.c"
    break;

  case 182:
#line 1194 "yacc_sql.y"
      {
  Value *value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  int num = CONTEXT->in_valuelist_num;

  selects_append_in_value(&CONTEXT->ssql->valuelists[num], value);

}
#line 3275 "yacc_sql.tab.c"
    break;

  case 184:
#line 1204 "yacc_sql.y"
                               {
}
#line 3282 "yacc_sql.tab.c"
    break;

  case 185:
#line 1208 "yacc_sql.y"
   {
  CONTEXT->comps[S_TOP] = EQUAL_TO;
}
#line 3290 "yacc_sql.tab.c"
    break;

  case 186:
#line 1211 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_THAN; }
#line 3296 "yacc_sql.tab.c"
    break;

  case 187:
#line 1212 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_THAN; }
#line 3302 "yacc_sql.tab.c"
    break;

  case 188:
#line 1213 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_EQUAL; }
#line 3308 "yacc_sql.tab.c"
    break;

  case 189:
#line 1214 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_EQUAL; }
#line 3314 "yacc_sql.tab.c"
    break;

  case 190:
#line 1215 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = NOT_EQUAL; }
#line 3320 "yacc_sql.tab.c"
    break;

  case 191:
#line 1216 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = IS_EQUAL; }
#line 3326 "yacc_sql.tab.c"
    break;

  case 192:
#line 1217 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = IS_NOT_EQUAL; }
#line 3332 "yacc_sql.tab.c"
    break;

  case 193:
#line 1218 "yacc_sql.y"
           { CONTEXT->comps[S_TOP] = STR_NOT_LIKE; }
#line 3338 "yacc_sql.tab.c"
    break;

  case 194:
#line 1219 "yacc_sql.y"
       { CONTEXT->comps[S_TOP] = STR_LIKE; }
#line 3344 "yacc_sql.tab.c"
    break;

  case 195:
#line 1220 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = VALUE_IN; }
#line 3350 "yacc_sql.tab.c"
    break;

  case 196:
#line 1221 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = VALUE_NOT_IN; }
#line 3356 "yacc_sql.tab.c"
    break;

  case 197:
#line 1226 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3365 "yacc_sql.tab.c"
    break;


#line 3369 "yacc_sql.tab.c"

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
#line 1231 "yacc_sql.y"

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
