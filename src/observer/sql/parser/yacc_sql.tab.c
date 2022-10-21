/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  size_t valuelist_length;
  size_t update_length;

  size_t selects_num;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  char id[MAX_NUM];

  AggreType a_type;

  size_t joins;
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
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->update_length = 0;
  context->value_length = 0;
  context->ssql->sstr.insertion.valuelist_num = 0;
  context->selects_num = 0;
  context->a_type = A_NO;
  context->joins = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 141 "yacc_sql.tab.c"

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

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_SELECT = 9,                     /* SELECT  */
  YYSYMBOL_DESC = 10,                      /* DESC  */
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_SYNC = 12,                      /* SYNC  */
  YYSYMBOL_INSERT = 13,                    /* INSERT  */
  YYSYMBOL_DELETE = 14,                    /* DELETE  */
  YYSYMBOL_UPDATE = 15,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 19,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 20,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 21,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 22,                     /* INT_T  */
  YYSYMBOL_STRING_T = 23,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 24,                   /* FLOAT_T  */
  YYSYMBOL_HELP = 25,                      /* HELP  */
  YYSYMBOL_EXIT = 26,                      /* EXIT  */
  YYSYMBOL_DOT = 27,                       /* DOT  */
  YYSYMBOL_INTO = 28,                      /* INTO  */
  YYSYMBOL_VALUES = 29,                    /* VALUES  */
  YYSYMBOL_FROM = 30,                      /* FROM  */
  YYSYMBOL_WHERE = 31,                     /* WHERE  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_SET = 33,                       /* SET  */
  YYSYMBOL_ON = 34,                        /* ON  */
  YYSYMBOL_LOAD = 35,                      /* LOAD  */
  YYSYMBOL_DATA_T = 36,                    /* DATA_T  */
  YYSYMBOL_INFILE = 37,                    /* INFILE  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_IS = 39,                        /* IS  */
  YYSYMBOL_LT = 40,                        /* LT  */
  YYSYMBOL_GT = 41,                        /* GT  */
  YYSYMBOL_LE = 42,                        /* LE  */
  YYSYMBOL_GE = 43,                        /* GE  */
  YYSYMBOL_NE = 44,                        /* NE  */
  YYSYMBOL_DATE_T = 45,                    /* DATE_T  */
  YYSYMBOL_UNIQUE_T = 46,                  /* UNIQUE_T  */
  YYSYMBOL_MAX = 47,                       /* MAX  */
  YYSYMBOL_MIN = 48,                       /* MIN  */
  YYSYMBOL_COUNT = 49,                     /* COUNT  */
  YYSYMBOL_AVG = 50,                       /* AVG  */
  YYSYMBOL_SUM = 51,                       /* SUM  */
  YYSYMBOL_NULLABLE = 52,                  /* NULLABLE  */
  YYSYMBOL_NULL_V = 53,                    /* NULL_V  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_INNER = 55,                     /* INNER  */
  YYSYMBOL_JOIN = 56,                      /* JOIN  */
  YYSYMBOL_NUMBER = 57,                    /* NUMBER  */
  YYSYMBOL_DATE_STR = 58,                  /* DATE_STR  */
  YYSYMBOL_FLOAT = 59,                     /* FLOAT  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_PATH = 61,                      /* PATH  */
  YYSYMBOL_SSS = 62,                       /* SSS  */
  YYSYMBOL_STAR = 63,                      /* STAR  */
  YYSYMBOL_STRING_V = 64,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_commands = 66,                  /* commands  */
  YYSYMBOL_command = 67,                   /* command  */
  YYSYMBOL_exit = 68,                      /* exit  */
  YYSYMBOL_help = 69,                      /* help  */
  YYSYMBOL_sync = 70,                      /* sync  */
  YYSYMBOL_begin = 71,                     /* begin  */
  YYSYMBOL_commit = 72,                    /* commit  */
  YYSYMBOL_rollback = 73,                  /* rollback  */
  YYSYMBOL_drop_table = 74,                /* drop_table  */
  YYSYMBOL_show_tables = 75,               /* show_tables  */
  YYSYMBOL_desc_table = 76,                /* desc_table  */
  YYSYMBOL_show_index = 77,                /* show_index  */
  YYSYMBOL_create_index = 78,              /* create_index  */
  YYSYMBOL_drop_index = 79,                /* drop_index  */
  YYSYMBOL_create_table = 80,              /* create_table  */
  YYSYMBOL_attr_def_list = 81,             /* attr_def_list  */
  YYSYMBOL_attr_def = 82,                  /* attr_def  */
  YYSYMBOL_number = 83,                    /* number  */
  YYSYMBOL_type = 84,                      /* type  */
  YYSYMBOL_ID_get = 85,                    /* ID_get  */
  YYSYMBOL_insert = 86,                    /* insert  */
  YYSYMBOL_insert_brace = 87,              /* insert_brace  */
  YYSYMBOL_insert_element = 88,            /* insert_element  */
  YYSYMBOL_value_list = 89,                /* value_list  */
  YYSYMBOL_value = 90,                     /* value  */
  YYSYMBOL_delete = 91,                    /* delete  */
  YYSYMBOL_update = 92,                    /* update  */
  YYSYMBOL_update_set = 93,                /* update_set  */
  YYSYMBOL_updates_sets = 94,              /* updates_sets  */
  YYSYMBOL_internal_select = 95,           /* internal_select  */
  YYSYMBOL_select = 96,                    /* select  */
  YYSYMBOL_select_attr = 97,               /* select_attr  */
  YYSYMBOL_aggregation_attr = 98,          /* aggregation_attr  */
  YYSYMBOL_aggregation_func = 99,          /* aggregation_func  */
  YYSYMBOL_aggregation_extra_id = 100,     /* aggregation_extra_id  */
  YYSYMBOL_attr_list = 101,                /* attr_list  */
  YYSYMBOL_rel_name = 102,                 /* rel_name  */
  YYSYMBOL_inner_joins = 103,              /* inner_joins  */
  YYSYMBOL_rel_list = 104,                 /* rel_list  */
  YYSYMBOL_where = 105,                    /* where  */
  YYSYMBOL_condition_list = 106,           /* condition_list  */
  YYSYMBOL_condition = 107,                /* condition  */
  YYSYMBOL_comOp = 108,                    /* comOp  */
  YYSYMBOL_load_data = 109                 /* load_data  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   161,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   186,   191,   196,   202,   208,   214,   220,   226,
     232,   239,   246,   254,   261,   270,   272,   276,   287,   298,
     304,   312,   315,   316,   317,   318,   321,   330,   349,   351,
     357,   362,   364,   369,   372,   375,   379,   382,   388,   398,
     409,   412,   418,   420,   425,   441,   464,   469,   475,   480,
     486,   492,   498,   504,   510,   518,   537,   540,   543,   546,
     549,   554,   556,   559,   562,   565,   569,   571,   578,   585,
     590,   595,   602,   604,   608,   610,   614,   616,   620,   622,
     627,   648,   668,   688,   710,   731,   752,   774,   775,   776,
     777,   778,   779,   780,   781,   785
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "HELP",
  "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "ON",
  "LOAD", "DATA_T", "INFILE", "EQ", "IS", "LT", "GT", "LE", "GE", "NE",
  "DATE_T", "UNIQUE_T", "MAX", "MIN", "COUNT", "AVG", "SUM", "NULLABLE",
  "NULL_V", "NOT", "INNER", "JOIN", "NUMBER", "DATE_STR", "FLOAT", "ID",
  "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "show_index", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "insert_brace", "insert_element", "value_list", "value",
  "delete", "update", "update_set", "updates_sets", "internal_select",
  "select", "select_attr", "aggregation_attr", "aggregation_func",
  "aggregation_extra_id", "attr_list", "rel_name", "inner_joins",
  "rel_list", "where", "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -197,    68,  -197,     8,    20,    67,   -33,    77,    28,    21,
      29,    16,    83,    87,    97,   101,   102,    35,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,    39,    46,    64,
      66,  -197,  -197,  -197,  -197,  -197,    11,   111,   106,   111,
     127,   141,   148,   122,  -197,   107,   108,   123,  -197,  -197,
    -197,  -197,  -197,   120,   150,   135,   167,   168,    72,   112,
    -197,  -197,   113,  -197,    -2,  -197,  -197,   114,   146,   145,
     117,   116,   119,   124,  -197,  -197,    42,   111,   111,   111,
     125,   163,  -197,   164,   164,    47,   164,   180,   169,   -40,
     182,   151,   170,   158,  -197,   172,     1,   175,   132,  -197,
    -197,  -197,  -197,   137,  -197,   113,   145,    71,   177,   178,
     136,   181,   183,  -197,   185,   185,  -197,  -197,  -197,  -197,
      69,  -197,   121,   165,  -197,    -6,   117,   145,   193,   119,
     186,  -197,  -197,  -197,  -197,    -4,   142,   111,   144,   163,
     202,   164,    48,   164,  -197,  -197,   164,  -197,  -197,    96,
     169,   169,   147,  -197,   152,  -197,  -197,  -197,  -197,  -197,
     -23,    80,   -40,  -197,   199,  -197,  -197,   170,   206,   153,
     172,   207,   154,  -197,   159,   197,  -197,   184,  -197,  -197,
    -197,   164,  -197,  -197,   198,   201,  -197,   213,   121,  -197,
    -197,  -197,   190,  -197,   165,    67,  -197,  -197,   217,  -197,
    -197,  -197,   204,  -197,   219,   -40,  -197,  -197,    96,   208,
    -197,    88,   166,  -197,   194,  -197,  -197,  -197,   165,   201,
    -197,   196,  -197,  -197,   171,   125,  -197,   173,   163,  -197,
    -197,   145,   210,  -197
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    21,    12,
      13,     8,     5,     7,     6,     4,    18,     0,     0,     0,
       0,    76,    77,    79,    78,    80,    86,    86,     0,    86,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
      67,    66,     0,    69,     0,    30,    29,     0,     0,    96,
       0,     0,     0,     0,    28,    33,    86,    86,    86,    86,
      92,    94,    72,    81,    81,    81,    81,     0,    48,     0,
       0,     0,    62,     0,    46,    35,     0,     0,     0,    87,
      89,    90,    68,     0,    91,     0,    96,     0,     0,     0,
       0,     0,     0,    31,     0,     0,    57,    53,    56,    54,
       0,    55,     0,    98,    58,     0,     0,    96,     0,     0,
       0,    42,    43,    44,    45,    38,     0,    86,     0,    94,
       0,    81,    81,    81,    74,    75,    81,    70,    73,     0,
      48,    48,     0,   107,   113,   108,   109,   110,   111,   112,
       0,     0,     0,    97,     0,    60,    61,    62,     0,     0,
      35,     0,     0,    39,     0,     0,    88,     0,    95,    65,
      85,    81,    82,    84,     0,    51,    49,     0,     0,   114,
     102,   100,   103,   101,    98,     0,    63,    59,     0,    36,
      34,    41,     0,    40,     0,     0,    83,    71,     0,     0,
      47,     0,     0,    99,     0,   115,    37,    32,    98,    51,
      50,     0,   104,   105,     0,    92,    52,     0,    94,    93,
     106,    96,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,    49,    89,  -197,  -197,
    -197,  -197,   -63,   105,     3,  -126,  -197,  -197,    98,    58,
    -197,  -197,    31,   174,  -197,   -89,   -46,   126,     2,  -147,
    -116,  -196,  -161,  -128,  -197
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   140,   105,   212,   145,
     106,    32,   125,   160,   219,   132,    33,    34,   102,   137,
     176,    35,    48,    49,    50,   118,    70,    91,   114,   116,
     100,   173,   133,   170,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     150,    71,   188,    73,   171,   119,   121,   122,   223,   175,
     174,   204,   182,   126,    37,    92,    38,   127,   128,   129,
     130,   178,   131,   141,   142,   143,    39,    51,    40,    68,
     126,    54,   235,   195,   127,   128,   129,   200,    69,   131,
     109,   110,   111,   112,   201,   203,   144,   126,   183,    55,
     184,   127,   128,   129,   228,    93,   131,    94,    95,    56,
      68,    96,   190,   192,   193,   117,   117,   194,     2,   108,
     221,    63,     3,     4,   120,   191,    57,     5,     6,     7,
       8,     9,    10,    11,    52,    53,    58,    12,    13,    14,
      59,   241,   229,    15,    16,   232,   162,   196,   197,    64,
      60,   186,   216,    17,    61,    62,    65,   163,   164,   165,
     166,   167,   168,   169,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,    66,   242,    67,    46,   151,    68,
      47,   152,    86,   126,   153,    87,    72,   127,   128,   129,
     202,   126,   131,    74,    75,   127,   128,   129,   231,   126,
     131,    76,    77,   127,   128,   129,    80,    81,   131,   163,
     164,   165,   166,   167,   168,   169,    82,    78,    79,    83,
      84,    85,    89,    90,    97,    98,    99,   101,   103,   104,
     113,   115,   117,   123,   107,   134,   138,   124,   136,   135,
     139,   146,   147,   148,   154,   155,   156,   172,   157,   179,
     158,   159,   185,   181,   187,   189,   199,   198,   205,   207,
     210,   211,   213,   208,   214,   217,   220,   222,   215,   218,
     225,   226,   227,   237,   234,   230,   233,   243,   180,   209,
     161,   238,   236,   240,   177,   206,   224,   239,     0,     0,
       0,   149,    88
};

static const yytype_int16 yycheck[] =
{
     116,    47,   149,    49,   132,    94,    95,    96,   204,   135,
      16,   172,    16,    53,     6,    17,     8,    57,    58,    59,
      60,   137,    62,    22,    23,    24,     6,    60,     8,    18,
      53,     3,   228,   159,    57,    58,    59,    60,    27,    62,
      86,    87,    88,    89,   170,   171,    45,    53,    52,    28,
      54,    57,    58,    59,   215,    57,    62,    59,    60,    30,
      18,    63,   151,   152,   153,    18,    18,   156,     0,    27,
     198,    36,     4,     5,    27,    27,    60,     9,    10,    11,
      12,    13,    14,    15,     7,     8,     3,    19,    20,    21,
       3,   238,   218,    25,    26,   221,    27,   160,   161,    60,
       3,   147,   191,    35,     3,     3,    60,    38,    39,    40,
      41,    42,    43,    44,    47,    48,    49,    50,    51,    47,
      48,    49,    50,    51,    60,   241,    60,    60,    57,    18,
      63,    60,    60,    53,    63,    63,    30,    57,    58,    59,
      60,    53,    62,    16,     3,    57,    58,    59,    60,    53,
      62,     3,    30,    57,    58,    59,    33,    37,    62,    38,
      39,    40,    41,    42,    43,    44,    16,    60,    60,    34,
       3,     3,    60,    60,    60,    29,    31,    60,    62,    60,
      55,    18,    18,     3,    60,     3,    28,    18,    18,    38,
      18,    16,    60,    56,    17,    17,    60,    32,    17,     6,
      17,    16,    60,    17,    60,     3,    54,    60,     9,     3,
       3,    57,    53,    60,    17,    17,     3,    27,    34,    18,
       3,    17,     3,    27,    30,    17,    60,    17,   139,   180,
     125,    60,   229,    60,   136,   177,   205,   235,    -1,    -1,
      -1,   115,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    35,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    86,    91,    92,    96,   109,     6,     8,     6,
       8,    47,    48,    49,    50,    51,    60,    63,    97,    98,
      99,    60,     7,     8,     3,    28,    30,    60,     3,     3,
       3,     3,     3,    36,    60,    60,    60,    60,    18,    27,
     101,   101,    30,   101,    16,     3,     3,    30,    60,    60,
      33,    37,    16,    34,     3,     3,    60,    63,    98,    60,
      60,   102,    17,    57,    59,    60,    63,    60,    29,    31,
     105,    60,    93,    62,    60,    82,    85,    60,    27,   101,
     101,   101,   101,    55,   103,    18,   104,    18,   100,   100,
      27,   100,   100,     3,    18,    87,    53,    57,    58,    59,
      60,    62,    90,   107,     3,    38,    18,    94,    28,    18,
      81,    22,    23,    24,    45,    84,    16,    60,    56,   102,
     105,    57,    60,    63,    17,    17,    60,    17,    17,    16,
      88,    88,    27,    38,    39,    40,    41,    42,    43,    44,
     108,   108,    32,   106,    16,    90,    95,    93,   105,     6,
      82,    17,    16,    52,    54,    60,   101,    60,   104,     3,
     100,    27,   100,   100,   100,    90,    87,    87,    60,    54,
      60,    90,    60,    90,   107,     9,    94,     3,    60,    81,
       3,    57,    83,    53,    17,    34,   100,    17,    18,    89,
       3,   108,    27,   106,    97,     3,    17,     3,   107,    90,
      17,    60,    90,    60,    30,   106,    89,    27,    60,   103,
      60,   104,   105,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    81,    82,    82,    82,
      82,    83,    84,    84,    84,    84,    85,    86,    87,    87,
      88,    89,    89,    90,    90,    90,    90,    90,    91,    92,
      93,    93,    94,    94,    95,    96,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     5,     9,     4,     8,     0,     3,     5,     2,     3,
       4,     1,     1,     1,     1,     1,     1,     8,     0,     3,
       4,     0,     3,     1,     1,     1,     1,     1,     5,     7,
       3,     3,     0,     3,     8,     7,     2,     2,     4,     2,
       5,     7,     3,     5,     5,     5,     1,     1,     1,     1,
       1,     0,     3,     4,     3,     3,     0,     3,     5,     3,
       3,     2,     0,     7,     0,     3,     0,     3,     0,     3,
       3,     3,     3,     3,     5,     5,     7,     1,     1,     1,
       1,     1,     1,     1,     2,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 22: /* exit: EXIT SEMICOLON  */
#line 186 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1415 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 191 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1423 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 196 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1431 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 202 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1439 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 208 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1447 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 214 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1455 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 220 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1464 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 226 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1472 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 232 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1481 "yacc_sql.tab.c"
    break;

  case 31: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 239 "yacc_sql.y"
                             {
  CONTEXT->ssql->flag = SCF_SHOW_INDEX;
  show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
}
#line 1490 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 247 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1499 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 255 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1508 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 262 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1520 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 272 "yacc_sql.y"
                                   {    }
#line 1526 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 277 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1541 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID_get type  */
#line 288 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4,  0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1556 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def: ID_get type NULLABLE  */
#line 298 "yacc_sql.y"
                       {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_length++;
}
#line 1567 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type NOT NULL_V  */
#line 304 "yacc_sql.y"
                         {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_length++;
}
#line 1578 "yacc_sql.tab.c"
    break;

  case 41: /* number: NUMBER  */
#line 312 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1584 "yacc_sql.tab.c"
    break;

  case 42: /* type: INT_T  */
#line 315 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1590 "yacc_sql.tab.c"
    break;

  case 43: /* type: STRING_T  */
#line 316 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1596 "yacc_sql.tab.c"
    break;

  case 44: /* type: FLOAT_T  */
#line 317 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1602 "yacc_sql.tab.c"
    break;

  case 45: /* type: DATE_T  */
#line 318 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1608 "yacc_sql.tab.c"
    break;

  case 46: /* ID_get: ID  */
#line 322 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string);
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1617 "yacc_sql.tab.c"
    break;

  case 47: /* insert: INSERT INTO ID VALUES insert_brace insert_element insert_brace SEMICOLON  */
#line 331 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

          CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
          //inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values, CONTEXT->value_length);
          //CONTEXT->value_length = 0;
            inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-5].string));
    //inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }
#line 1639 "yacc_sql.tab.c"
    break;

  case 49: /* insert_brace: COMMA insert_element insert_brace  */
#line 351 "yacc_sql.y"
                                    {

}
#line 1647 "yacc_sql.tab.c"
    break;

  case 50: /* insert_element: LBRACE value value_list RBRACE  */
#line 357 "yacc_sql.y"
                               {
inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values, CONTEXT->value_length);
CONTEXT->value_length = 0;
}
#line 1656 "yacc_sql.tab.c"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 364 "yacc_sql.y"
                              {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1664 "yacc_sql.tab.c"
    break;

  case 53: /* value: NUMBER  */
#line 369 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1672 "yacc_sql.tab.c"
    break;

  case 54: /* value: FLOAT  */
#line 372 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1680 "yacc_sql.tab.c"
    break;

  case 55: /* value: SSS  */
#line 375 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1689 "yacc_sql.tab.c"
    break;

  case 56: /* value: DATE_STR  */
#line 379 "yacc_sql.y"
              {
        value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1697 "yacc_sql.tab.c"
    break;

  case 57: /* value: NULL_V  */
#line 382 "yacc_sql.y"
         {
      value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1705 "yacc_sql.tab.c"
    break;

  case 58: /* delete: DELETE FROM ID where SEMICOLON  */
#line 389 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion,
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
    }
#line 1717 "yacc_sql.tab.c"
    break;

  case 59: /* update: UPDATE ID SET update_set updates_sets where SEMICOLON  */
#line 399 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_UPDATE;//"update";
  updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string),
               CONTEXT->conditions, CONTEXT->condition_length);
  CONTEXT->condition_length = 0;
  CONTEXT->value_length = 0;
}
#line 1729 "yacc_sql.tab.c"
    break;

  case 60: /* update_set: ID EQ value  */
#line 409 "yacc_sql.y"
            {
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[CONTEXT->value_length - 1]);
}
#line 1737 "yacc_sql.tab.c"
    break;

  case 61: /* update_set: ID EQ internal_select  */
#line 412 "yacc_sql.y"
                        {
  value_init_select(&CONTEXT->values[CONTEXT->value_length],
                    &CONTEXT->ssql->selects[CONTEXT->selects_num - 1]);
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[CONTEXT->value_length++]);
}
#line 1747 "yacc_sql.tab.c"
    break;

  case 63: /* updates_sets: COMMA update_set updates_sets  */
#line 420 "yacc_sql.y"
                                {
}
#line 1754 "yacc_sql.tab.c"
    break;

  case 64: /* internal_select: LBRACE SELECT select_attr FROM ID rel_list where RBRACE  */
#line 425 "yacc_sql.y"
                                                        {
  int num = CONTEXT->selects_num;
  selects_append_relation(&CONTEXT->ssql->selects[num], (yyvsp[-3].string));
  // selects_reverse_relations(&CONTEXT->ssql->selects[num]);
  selects_append_conditions(&CONTEXT->ssql->selects[num], CONTEXT->conditions, CONTEXT->condition_length);

  //临时变量清零
  CONTEXT->condition_length=0;
  CONTEXT->from_length=0;
  CONTEXT->select_length=0;
  CONTEXT->value_length = 0;
  CONTEXT->selects_num++;
  CONTEXT->ssql->selects_num = CONTEXT->selects_num;
}
#line 1773 "yacc_sql.tab.c"
    break;

  case 65: /* select: SELECT select_attr FROM rel_name rel_list where SEMICOLON  */
#line 442 "yacc_sql.y"
{
  // CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
  // &CONTEXT->ssql->sstr.selects[CONTEXT->selects_num]
  int num = CONTEXT->selects_num;
  // selects_append_relation(&CONTEXT->ssql->selects[num], $4);
  // selects_reverse_relations(&CONTEXT->ssql->selects[num]);
  selects_append_conditions(&CONTEXT->ssql->selects[num], CONTEXT->conditions, CONTEXT->condition_length);
  CONTEXT->ssql->sstr.selection = &CONTEXT->ssql->selects[num];

  CONTEXT->ssql->flag=SCF_SELECT;//"select";
  // CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

  //临时变量清零
  CONTEXT->condition_length=0;
  CONTEXT->from_length=0;
  CONTEXT->select_length=0;
  CONTEXT->value_length = 0;
  CONTEXT->selects_num++;
  CONTEXT->ssql->selects_num = CONTEXT->selects_num;
}
#line 1798 "yacc_sql.tab.c"
    break;

  case 66: /* select_attr: STAR attr_list  */
#line 464 "yacc_sql.y"
               {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1808 "yacc_sql.tab.c"
    break;

  case 67: /* select_attr: ID attr_list  */
#line 469 "yacc_sql.y"
               {

  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1819 "yacc_sql.tab.c"
    break;

  case 68: /* select_attr: ID DOT ID attr_list  */
#line 475 "yacc_sql.y"
                      {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1829 "yacc_sql.tab.c"
    break;

  case 69: /* select_attr: aggregation_attr attr_list  */
#line 480 "yacc_sql.y"
                             {

}
#line 1837 "yacc_sql.tab.c"
    break;

  case 70: /* aggregation_attr: aggregation_func LBRACE ID aggregation_extra_id RBRACE  */
#line 486 "yacc_sql.y"
                                                       {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1848 "yacc_sql.tab.c"
    break;

  case 71: /* aggregation_attr: aggregation_func LBRACE ID DOT ID aggregation_extra_id RBRACE  */
#line 492 "yacc_sql.y"
                                                                {
  RelAttr attr;
  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1859 "yacc_sql.tab.c"
    break;

  case 72: /* aggregation_attr: aggregation_func LBRACE RBRACE  */
#line 498 "yacc_sql.y"
                                 {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, "fail", A_FAILURE, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1870 "yacc_sql.tab.c"
    break;

  case 73: /* aggregation_attr: aggregation_func LBRACE STAR aggregation_extra_id RBRACE  */
#line 504 "yacc_sql.y"
                                                           {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, "*", CONTEXT->a_type != A_COUNT ? A_FAILURE : CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1881 "yacc_sql.tab.c"
    break;

  case 74: /* aggregation_attr: aggregation_func LBRACE NUMBER aggregation_extra_id RBRACE  */
#line 510 "yacc_sql.y"
                                                             {
  RelAttr attr;
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  aggregation_attr_init(&attr, NULL, str, CONTEXT->a_type, 1);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1894 "yacc_sql.tab.c"
    break;

  case 75: /* aggregation_attr: aggregation_func LBRACE FLOAT aggregation_extra_id RBRACE  */
#line 518 "yacc_sql.y"
                                                            {
  RelAttr attr;
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
  aggregation_attr_init(&attr, NULL, buf, CONTEXT->a_type, 1);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1915 "yacc_sql.tab.c"
    break;

  case 76: /* aggregation_func: MAX  */
#line 537 "yacc_sql.y"
    {
  CONTEXT->a_type = A_MAX;
}
#line 1923 "yacc_sql.tab.c"
    break;

  case 77: /* aggregation_func: MIN  */
#line 540 "yacc_sql.y"
      {
  CONTEXT->a_type = A_MIN;
}
#line 1931 "yacc_sql.tab.c"
    break;

  case 78: /* aggregation_func: AVG  */
#line 543 "yacc_sql.y"
      {
  CONTEXT->a_type = A_AVG;
}
#line 1939 "yacc_sql.tab.c"
    break;

  case 79: /* aggregation_func: COUNT  */
#line 546 "yacc_sql.y"
        {
  CONTEXT->a_type = A_COUNT;
}
#line 1947 "yacc_sql.tab.c"
    break;

  case 80: /* aggregation_func: SUM  */
#line 549 "yacc_sql.y"
      {
  CONTEXT->a_type = A_SUM;
}
#line 1955 "yacc_sql.tab.c"
    break;

  case 82: /* aggregation_extra_id: COMMA ID aggregation_extra_id  */
#line 556 "yacc_sql.y"
                                {
  CONTEXT->a_type = A_FAILURE;
}
#line 1963 "yacc_sql.tab.c"
    break;

  case 83: /* aggregation_extra_id: COMMA ID DOT aggregation_extra_id  */
#line 559 "yacc_sql.y"
                                    {
  CONTEXT->a_type = A_FAILURE;
}
#line 1971 "yacc_sql.tab.c"
    break;

  case 84: /* aggregation_extra_id: COMMA STAR aggregation_extra_id  */
#line 562 "yacc_sql.y"
                                  {
  CONTEXT->a_type = A_FAILURE;
}
#line 1979 "yacc_sql.tab.c"
    break;

  case 85: /* aggregation_extra_id: COMMA NUMBER aggregation_extra_id  */
#line 565 "yacc_sql.y"
                                    {
  CONTEXT->a_type = A_FAILURE;
}
#line 1987 "yacc_sql.tab.c"
    break;

  case 87: /* attr_list: COMMA ID attr_list  */
#line 571 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 1999 "yacc_sql.tab.c"
    break;

  case 88: /* attr_list: COMMA ID DOT ID attr_list  */
#line 578 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2011 "yacc_sql.tab.c"
    break;

  case 89: /* attr_list: COMMA STAR attr_list  */
#line 585 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
    }
#line 2021 "yacc_sql.tab.c"
    break;

  case 90: /* attr_list: COMMA aggregation_attr attr_list  */
#line 590 "yacc_sql.y"
                                   {

}
#line 2029 "yacc_sql.tab.c"
    break;

  case 91: /* rel_name: ID inner_joins  */
#line 595 "yacc_sql.y"
               {
  selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], (yyvsp[-1].string));
  selects_reverse_relations(&CONTEXT->ssql->selects[CONTEXT->selects_num], ++CONTEXT->joins);
  CONTEXT->joins = 0;
}
#line 2039 "yacc_sql.tab.c"
    break;

  case 93: /* inner_joins: INNER JOIN ID ON condition condition_list inner_joins  */
#line 604 "yacc_sql.y"
                                                        {
  selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], (yyvsp[-4].string));
  CONTEXT->joins++;
}
#line 2048 "yacc_sql.tab.c"
    break;

  case 95: /* rel_list: COMMA rel_name rel_list  */
#line 610 "yacc_sql.y"
                              {
      // selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], $2);
		  }
#line 2056 "yacc_sql.tab.c"
    break;

  case 97: /* where: WHERE condition condition_list  */
#line 616 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2064 "yacc_sql.tab.c"
    break;

  case 99: /* condition_list: AND condition condition_list  */
#line 622 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2072 "yacc_sql.tab.c"
    break;

  case 100: /* condition: ID comOp value  */
#line 628 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2097 "yacc_sql.tab.c"
    break;

  case 101: /* condition: value comOp value  */
#line 649 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2121 "yacc_sql.tab.c"
    break;

  case 102: /* condition: ID comOp ID  */
#line 669 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2145 "yacc_sql.tab.c"
    break;

  case 103: /* condition: value comOp ID  */
#line 689 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 2171 "yacc_sql.tab.c"
    break;

  case 104: /* condition: ID DOT ID comOp value  */
#line 711 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
#line 2196 "yacc_sql.tab.c"
    break;

  case 105: /* condition: value comOp ID DOT ID  */
#line 732 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2221 "yacc_sql.tab.c"
    break;

  case 106: /* condition: ID DOT ID comOp ID DOT ID  */
#line 753 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2244 "yacc_sql.tab.c"
    break;

  case 107: /* comOp: EQ  */
#line 774 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2250 "yacc_sql.tab.c"
    break;

  case 108: /* comOp: LT  */
#line 775 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2256 "yacc_sql.tab.c"
    break;

  case 109: /* comOp: GT  */
#line 776 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2262 "yacc_sql.tab.c"
    break;

  case 110: /* comOp: LE  */
#line 777 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2268 "yacc_sql.tab.c"
    break;

  case 111: /* comOp: GE  */
#line 778 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2274 "yacc_sql.tab.c"
    break;

  case 112: /* comOp: NE  */
#line 779 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2280 "yacc_sql.tab.c"
    break;

  case 113: /* comOp: IS  */
#line 780 "yacc_sql.y"
     { CONTEXT->comp = IS_EQUAL; }
#line 2286 "yacc_sql.tab.c"
    break;

  case 114: /* comOp: IS NOT  */
#line 781 "yacc_sql.y"
         { CONTEXT->comp = IS_NOT_EQUAL; }
#line 2292 "yacc_sql.tab.c"
    break;

  case 115: /* load_data: LOAD DATA_T INFILE SSS INTO TABLE ID SEMICOLON  */
#line 786 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2301 "yacc_sql.tab.c"
    break;


#line 2305 "yacc_sql.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (scanner, YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 791 "yacc_sql.y"

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
