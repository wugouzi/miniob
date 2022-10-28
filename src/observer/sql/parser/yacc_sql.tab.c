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


#line 174 "yacc_sql.tab.c"

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
  YYSYMBOL_LIKE = 57,                      /* LIKE  */
  YYSYMBOL_ORDER = 58,                     /* ORDER  */
  YYSYMBOL_GROUP = 59,                     /* GROUP  */
  YYSYMBOL_ASC = 60,                       /* ASC  */
  YYSYMBOL_BY = 61,                        /* BY  */
  YYSYMBOL_TEXT_T = 62,                    /* TEXT_T  */
  YYSYMBOL_IN = 63,                        /* IN  */
  YYSYMBOL_EXISTS = 64,                    /* EXISTS  */
  YYSYMBOL_HAVING = 65,                    /* HAVING  */
  YYSYMBOL_NUMBER = 66,                    /* NUMBER  */
  YYSYMBOL_DATE_STR = 67,                  /* DATE_STR  */
  YYSYMBOL_FLOAT = 68,                     /* FLOAT  */
  YYSYMBOL_ID = 69,                        /* ID  */
  YYSYMBOL_PATH = 70,                      /* PATH  */
  YYSYMBOL_SSS = 71,                       /* SSS  */
  YYSYMBOL_STAR = 72,                      /* STAR  */
  YYSYMBOL_STRING_V = 73,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_commands = 75,                  /* commands  */
  YYSYMBOL_command = 76,                   /* command  */
  YYSYMBOL_exit = 77,                      /* exit  */
  YYSYMBOL_help = 78,                      /* help  */
  YYSYMBOL_sync = 79,                      /* sync  */
  YYSYMBOL_begin = 80,                     /* begin  */
  YYSYMBOL_commit = 81,                    /* commit  */
  YYSYMBOL_rollback = 82,                  /* rollback  */
  YYSYMBOL_drop_table = 83,                /* drop_table  */
  YYSYMBOL_show_tables = 84,               /* show_tables  */
  YYSYMBOL_desc_table = 85,                /* desc_table  */
  YYSYMBOL_show_index = 86,                /* show_index  */
  YYSYMBOL_create_index = 87,              /* create_index  */
  YYSYMBOL_index_ids = 88,                 /* index_ids  */
  YYSYMBOL_drop_index = 89,                /* drop_index  */
  YYSYMBOL_create_table = 90,              /* create_table  */
  YYSYMBOL_attr_def_list = 91,             /* attr_def_list  */
  YYSYMBOL_attr_def = 92,                  /* attr_def  */
  YYSYMBOL_number = 93,                    /* number  */
  YYSYMBOL_type = 94,                      /* type  */
  YYSYMBOL_ID_get = 95,                    /* ID_get  */
  YYSYMBOL_insert = 96,                    /* insert  */
  YYSYMBOL_insert_brace = 97,              /* insert_brace  */
  YYSYMBOL_insert_element = 98,            /* insert_element  */
  YYSYMBOL_value_list = 99,                /* value_list  */
  YYSYMBOL_value = 100,                    /* value  */
  YYSYMBOL_delete = 101,                   /* delete  */
  YYSYMBOL_update = 102,                   /* update  */
  YYSYMBOL_update_set = 103,               /* update_set  */
  YYSYMBOL_updates_sets = 104,             /* updates_sets  */
  YYSYMBOL_select_stmt = 105,              /* select_stmt  */
  YYSYMBOL_select_ = 106,                  /* select_  */
  YYSYMBOL_select = 107,                   /* select  */
  YYSYMBOL_having = 108,                   /* having  */
  YYSYMBOL_groupby = 109,                  /* groupby  */
  YYSYMBOL_groupby_ids = 110,              /* groupby_ids  */
  YYSYMBOL_select_attr = 111,              /* select_attr  */
  YYSYMBOL_aggregation_attr = 112,         /* aggregation_attr  */
  YYSYMBOL_aggregation_func = 113,         /* aggregation_func  */
  YYSYMBOL_aggregation_extra_id = 114,     /* aggregation_extra_id  */
  YYSYMBOL_attr_list = 115,                /* attr_list  */
  YYSYMBOL_rel_name = 116,                 /* rel_name  */
  YYSYMBOL_inner_joins = 117,              /* inner_joins  */
  YYSYMBOL_order = 118,                    /* order  */
  YYSYMBOL_order_component = 119,          /* order_component  */
  YYSYMBOL_order_direction = 120,          /* order_direction  */
  YYSYMBOL_order_component_list = 121,     /* order_component_list  */
  YYSYMBOL_rel_list = 122,                 /* rel_list  */
  YYSYMBOL_where = 123,                    /* where  */
  YYSYMBOL_condition_list = 124,           /* condition_list  */
  YYSYMBOL_condition = 125,                /* condition  */
  YYSYMBOL_in_value = 126,                 /* in_value  */
  YYSYMBOL_in_value_list = 127,            /* in_value_list  */
  YYSYMBOL_comOp = 128,                    /* comOp  */
  YYSYMBOL_load_data = 129                 /* load_data  */
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
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   201,   201,   203,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   228,   233,   238,   244,   250,   256,   262,   268,
     274,   281,   288,   294,   302,   304,   310,   317,   326,   328,
     332,   343,   359,   365,   373,   376,   377,   378,   379,   380,
     383,   392,   405,   407,   413,   418,   420,   425,   429,   432,
     436,   439,   442,   449,   460,   471,   476,   478,   483,   491,
     499,   513,   515,   520,   522,   527,   534,   536,   541,   548,
     553,   559,   564,   571,   575,   580,   585,   590,   597,   615,
     618,   621,   624,   627,   632,   634,   637,   640,   643,   647,
     649,   656,   663,   668,   674,   681,   683,   688,   690,   693,
     694,   700,   709,   712,   715,   720,   722,   726,   728,   732,
     734,   738,   740,   745,   758,   767,   778,   789,   801,   812,
     823,   837,   850,   858,   866,   873,   883,   891,   893,   897,
     900,   901,   902,   903,   904,   905,   906,   907,   908,   909,
     910,   914
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
  "NULL_V", "NOT", "INNER", "JOIN", "LIKE", "ORDER", "GROUP", "ASC", "BY",
  "TEXT_T", "IN", "EXISTS", "HAVING", "NUMBER", "DATE_STR", "FLOAT", "ID",
  "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "show_index", "create_index", "index_ids",
  "drop_index", "create_table", "attr_def_list", "attr_def", "number",
  "type", "ID_get", "insert", "insert_brace", "insert_element",
  "value_list", "value", "delete", "update", "update_set", "updates_sets",
  "select_stmt", "select_", "select", "having", "groupby", "groupby_ids",
  "select_attr", "aggregation_attr", "aggregation_func",
  "aggregation_extra_id", "attr_list", "rel_name", "inner_joins", "order",
  "order_component", "order_direction", "order_component_list", "rel_list",
  "where", "condition_list", "condition", "in_value", "in_value_list",
  "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-279)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -279,   186,  -279,    15,    74,  -279,   -50,    76,    21,     5,
       8,   -27,    50,   128,   129,   130,   137,    63,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,   176,   139,  -279,  -279,    40,
      78,   140,    81,    83,   142,   150,   135,  -279,    91,    92,
     133,  -279,  -279,  -279,  -279,  -279,   141,  -279,  -279,  -279,
    -279,  -279,     7,   158,   147,   158,   163,  -279,   164,   148,
     112,   180,   181,  -279,  -279,   118,   160,   161,   124,   132,
     192,   151,  -279,  -279,   153,  -279,    51,   159,   162,   168,
    -279,  -279,   201,   190,    47,   206,   172,   212,   205,     9,
     158,   158,   158,   179,   217,  -279,   218,   218,    14,   218,
    -279,   219,   106,   228,   177,  -279,   231,   231,   240,  -279,
     187,    96,  -279,  -279,  -279,   131,  -279,   175,   175,   220,
    -279,    96,   124,   161,   244,   184,  -279,  -279,  -279,  -279,
     198,  -279,   153,   161,    55,   238,   239,   188,   241,   242,
     159,   243,  -279,  -279,  -279,  -279,  -279,    24,   193,   247,
      96,   190,   190,   248,    96,  -279,   197,  -279,   213,  -279,
    -279,  -279,  -279,  -279,   -26,  -279,  -279,     6,    88,    96,
      47,  -279,  -279,   212,   265,   200,   158,   202,   217,   211,
     218,    17,   218,  -279,  -279,   218,  -279,  -279,   219,   269,
     207,  -279,   221,   257,   208,   258,  -279,   275,  -279,  -279,
     175,  -279,  -279,  -279,    -1,  -279,  -279,   252,  -279,  -279,
    -279,   220,  -279,  -279,   277,  -279,   249,  -279,   223,   216,
    -279,   218,  -279,  -279,   268,  -279,  -279,  -279,   270,  -279,
     222,   271,   257,    96,   272,  -279,    39,  -279,   264,   224,
    -279,  -279,    47,   225,    47,   232,  -279,  -279,  -279,   257,
     283,   278,   258,  -279,    -1,   273,  -279,    96,   279,  -279,
     220,    27,   220,   236,  -279,  -279,  -279,   289,  -279,   264,
     229,   264,  -279,   179,   230,   233,  -279,  -279,   234,  -279,
     284,  -279,  -279,  -279,    33,   286,     2,   287,  -279,   237,
    -279,  -279,  -279,   245,  -279,  -279,   234,  -279,   286,     4,
     287,  -279,  -279,  -279
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
       0,    25,    26,    27,    23,    22,     0,    89,    90,    92,
      91,    93,    99,    99,     0,    99,     0,    70,     0,     0,
       0,     0,     0,    30,    29,     0,     0,   119,     0,     0,
       0,     0,    80,    79,     0,    82,     0,     0,     0,     0,
      28,    36,     0,    52,     0,     0,     0,    66,     0,    99,
      99,    99,    99,   105,   117,    85,    94,    94,    94,    94,
      50,    38,     0,     0,     0,    31,     0,     0,     0,    61,
       0,     0,    57,    60,    58,     0,    59,     0,     0,   121,
      63,     0,     0,   119,     0,     0,   100,   102,   103,    81,
       0,   104,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,    41,     0,     0,
       0,    52,    52,     0,     0,   132,     0,   139,   145,   140,
     141,   142,   143,   144,     0,   148,   149,     0,     0,     0,
       0,   120,    65,    66,     0,     0,    99,     0,   117,    73,
      94,    94,    94,    87,    88,    94,    83,    86,    38,     0,
       0,    42,     0,    34,     0,    55,    53,     0,    62,   133,
       0,   146,   147,   150,     0,   125,   123,   126,   124,   135,
     134,   121,    67,    64,     0,   101,     0,   118,     0,    71,
      98,    94,    95,    97,     0,    39,    37,    44,     0,    43,
       0,     0,    34,     0,     0,    51,     0,   136,   137,     0,
     122,   151,     0,     0,     0,   107,    96,    84,    40,    34,
       0,     0,    55,    54,     0,     0,   127,     0,     0,   128,
     121,    76,   121,     0,    69,    35,    32,     0,    56,   137,
       0,   137,   130,   105,     0,     0,    74,    72,   109,    33,
       0,   129,   138,   106,    76,    76,   114,   115,   131,     0,
      77,    75,   113,     0,   112,   110,   109,   108,    76,   114,
     115,    78,   111,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -233,  -279,  -279,   109,   165,  -279,
    -279,  -279,  -279,   -59,   191,    48,  -121,  -279,  -279,   185,
     126,  -279,   310,  -279,  -279,  -279,  -278,  -279,   -34,  -279,
    -105,   -52,   170,    30,  -279,    10,    11,    12,   136,  -115,
    -201,  -173,    52,  -190,  -122,  -279
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   241,    30,    31,   151,   111,   238,
     157,   112,    32,   117,   161,   244,   127,    33,    34,    97,
     133,    35,   163,    37,   255,   229,   286,    64,   128,    66,
     145,    82,   104,   141,   274,   297,   305,   307,   143,    95,
     181,   129,   248,   268,   177,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,    65,   146,   148,   149,   178,   179,   221,     5,   261,
     182,    83,   302,    85,   302,   118,   300,   301,   184,    44,
     250,    39,   214,    40,    47,    80,   275,    80,   189,   303,
     311,   212,   144,    48,    81,   144,   135,   213,    49,   205,
     200,   147,    50,   209,   231,   284,   101,   136,   137,   138,
     139,   284,   119,    51,   285,   264,   216,   218,   220,   119,
     299,    41,   304,   118,   304,   122,   123,   124,   105,   283,
     126,   287,   122,   123,   124,   215,   201,   126,   202,   270,
      42,   272,    43,    45,    46,   230,   232,   233,   246,   290,
     234,   292,   119,   247,    57,    58,    59,    60,    61,    56,
     119,   120,   206,   207,   118,   122,   123,   124,   265,    68,
     126,   121,   118,   122,   123,   124,   125,   106,   126,   107,
     108,   190,   262,   109,   191,   266,   256,   192,   152,   153,
     154,    52,    53,    54,   225,    57,    58,    59,    60,    61,
      55,   119,    67,   279,   219,    73,   247,    69,    70,   119,
      71,   155,    72,    74,   122,   123,   124,   217,   166,   126,
      76,    77,   122,   123,   124,    75,    78,   126,   156,   167,
     168,   169,   170,   171,   172,   173,    80,    84,    79,    86,
      87,    89,    88,    90,    91,   174,     2,    92,   175,    93,
       3,     4,    94,    96,   176,     5,     6,     7,     8,     9,
      10,    11,   114,    98,   115,    12,    13,    14,   116,   130,
     131,    15,    16,   167,   168,   169,   170,   171,   172,   173,
     102,    17,   103,    57,    58,    59,    60,    61,   110,   174,
     132,   113,   175,   134,   140,   142,   144,   150,   176,    57,
      58,    59,    60,    61,   158,    62,   159,   160,    63,     5,
     185,   164,   180,   186,   187,   193,   194,   195,   196,   197,
     199,    99,   203,   204,   100,   208,   210,   211,   223,   224,
     228,   226,   236,   237,   239,   240,   243,   242,   245,   249,
     251,   254,   267,   252,   253,   257,   276,   258,   260,   263,
     273,   259,   289,   269,   271,   277,   282,   288,   291,   294,
     280,   298,   295,   296,   284,   306,   308,   235,   162,   222,
     278,    36,   188,   293,   309,   198,   310,   183,     0,   281,
     312,     0,   313,     0,   227
};

static const yytype_int16 yycheck[] =
{
     121,    35,   107,   108,   109,   127,   128,   180,     9,   242,
     131,    63,    10,    65,    10,    16,   294,   295,   133,    69,
     221,     6,    16,     8,     3,    18,   259,    18,   143,    27,
     308,    57,    18,    28,    27,    18,    27,    63,    30,   160,
      16,    27,    69,   164,    27,    18,    80,    99,   100,   101,
     102,    18,    53,     3,    27,    16,   177,   178,   179,    53,
      27,    46,    60,    16,    60,    66,    67,    68,    17,   270,
      71,   272,    66,    67,    68,    69,    52,    71,    54,   252,
       6,   254,     8,     7,     8,   190,   191,   192,   210,   279,
     195,   281,    53,   214,    47,    48,    49,    50,    51,    36,
      53,    54,   161,   162,    16,    66,    67,    68,    69,    69,
      71,    64,    16,    66,    67,    68,    69,    66,    71,    68,
      69,    66,   243,    72,    69,   246,   231,    72,    22,    23,
      24,     3,     3,     3,   186,    47,    48,    49,    50,    51,
       3,    53,     3,   264,   178,     3,   267,    69,     8,    53,
      69,    45,    69,     3,    66,    67,    68,    69,    27,    71,
      69,    69,    66,    67,    68,    30,    33,    71,    62,    38,
      39,    40,    41,    42,    43,    44,    18,    30,    37,    16,
      16,    69,    34,     3,     3,    54,     0,    69,    57,    29,
       4,     5,    31,    69,    63,     9,    10,    11,    12,    13,
      14,    15,    34,    71,     3,    19,    20,    21,    18,     3,
      38,    25,    26,    38,    39,    40,    41,    42,    43,    44,
      69,    35,    69,    47,    48,    49,    50,    51,    69,    54,
      18,    69,    57,    28,    55,    18,    18,    18,    63,    47,
      48,    49,    50,    51,    16,    69,    69,    16,    72,     9,
       6,    64,    32,    69,    56,    17,    17,    69,    17,    17,
      17,    69,    69,    16,    72,    17,    69,    54,     3,    69,
      59,    69,     3,    66,    53,    18,    18,    69,     3,    27,
       3,    65,    18,    34,    61,    17,     3,    17,    17,    17,
      58,    69,     3,    69,    69,    17,    17,    61,    69,    69,
      27,    17,    69,    69,    18,    18,    69,   198,   117,   183,
     262,     1,   142,   283,    69,   150,   306,   132,    -1,   267,
     309,    -1,   310,    -1,   188
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    35,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      89,    90,    96,   101,   102,   105,   106,   107,   129,     6,
       8,    46,     6,     8,    69,     7,     8,     3,    28,    30,
      69,     3,     3,     3,     3,     3,    36,    47,    48,    49,
      50,    51,    69,    72,   111,   112,   113,     3,    69,    69,
       8,    69,    69,     3,     3,    30,    69,    69,    33,    37,
      18,    27,   115,   115,    30,   115,    16,    16,    34,    69,
       3,     3,    69,    29,    31,   123,    69,   103,    71,    69,
      72,   112,    69,    69,   116,    17,    66,    68,    69,    72,
      69,    92,    95,    69,    34,     3,    18,    97,    16,    53,
      54,    64,    66,    67,    68,    69,    71,   100,   112,   125,
       3,    38,    18,   104,    28,    27,   115,   115,   115,   115,
      55,   117,    18,   122,    18,   114,   114,    27,   114,   114,
      18,    91,    22,    23,    24,    45,    62,    94,    16,    69,
      16,    98,    98,   106,    64,   100,    27,    38,    39,    40,
      41,    42,    43,    44,    54,    57,    63,   128,   128,   128,
      32,   124,   100,   103,   123,     6,    69,    56,   116,   123,
      66,    69,    72,    17,    17,    69,    17,    17,    92,    17,
      16,    52,    54,    69,    16,   100,    97,    97,    17,   100,
      69,    54,    57,    63,    16,    69,   100,    69,   100,   112,
     100,   125,   104,     3,    69,   115,    69,   122,    59,   109,
     114,    27,   114,   114,   114,    91,     3,    66,    93,    53,
      18,    88,    69,    18,    99,     3,   128,   100,   126,    27,
     124,     3,    34,    61,    65,   108,   114,    17,    17,    69,
      17,    88,   100,    17,    16,    69,   100,    18,   127,    69,
     125,    69,   125,    58,   118,    88,     3,    17,    99,   100,
      27,   126,    17,   124,    18,    27,   110,   124,    61,     3,
     127,    69,   127,   117,    69,    69,    69,   119,    17,    27,
     110,   110,    10,    27,    60,   120,    18,   121,    69,    69,
     119,   110,   120,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    90,    91,    91,
      92,    92,    92,    92,    93,    94,    94,    94,    94,    94,
      95,    96,    97,    97,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   102,   103,   104,   104,   105,   106,
     107,   108,   108,   109,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   116,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     5,    10,    11,     0,     3,     4,     8,     0,     3,
       5,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     8,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     3,     5,     7,     3,     0,     3,     1,     9,
       2,     0,     3,     0,     4,     6,     0,     3,     5,     2,
       2,     4,     2,     5,     7,     3,     5,     5,     5,     1,
       1,     1,     1,     1,     0,     3,     4,     3,     3,     0,
       3,     5,     3,     3,     2,     0,     7,     0,     4,     0,
       2,     4,     1,     1,     0,     0,     3,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     3,     5,     5,     7,
       6,     8,     2,     3,     3,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     8
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
#line 228 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1524 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 233 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1532 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 238 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1540 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 244 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1548 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 250 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1556 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 256 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1564 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 262 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1573 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 268 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1581 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 274 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1590 "yacc_sql.tab.c"
    break;

  case 31: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 281 "yacc_sql.y"
                             {
  CONTEXT->ssql->flag = SCF_SHOW_INDEX;
  show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
}
#line 1599 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_ids RBRACE SEMICOLON  */
#line 289 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
}
#line 1609 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE_T INDEX ID ON ID LBRACE ID index_ids RBRACE SEMICOLON  */
#line 295 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
}
#line 1619 "yacc_sql.tab.c"
    break;

  case 35: /* index_ids: COMMA ID index_ids  */
#line 304 "yacc_sql.y"
                      {
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
}
#line 1627 "yacc_sql.tab.c"
    break;

  case 36: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 311 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1636 "yacc_sql.tab.c"
    break;

  case 37: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 318 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_lengths[S_TOP] = 0;
		}
#line 1648 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 328 "yacc_sql.y"
                                   {    }
#line 1654 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 333 "yacc_sql.y"
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
#line 1669 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type  */
#line 344 "yacc_sql.y"
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
#line 1689 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type NULLABLE  */
#line 359 "yacc_sql.y"
                       {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 1700 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type NOT NULL_V  */
#line 365 "yacc_sql.y"
                         {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_lengths[S_TOP]++;
}
#line 1711 "yacc_sql.tab.c"
    break;

  case 44: /* number: NUMBER  */
#line 373 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1717 "yacc_sql.tab.c"
    break;

  case 45: /* type: INT_T  */
#line 376 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1723 "yacc_sql.tab.c"
    break;

  case 46: /* type: STRING_T  */
#line 377 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1729 "yacc_sql.tab.c"
    break;

  case 47: /* type: FLOAT_T  */
#line 378 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1735 "yacc_sql.tab.c"
    break;

  case 48: /* type: DATE_T  */
#line 379 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1741 "yacc_sql.tab.c"
    break;

  case 49: /* type: TEXT_T  */
#line 380 "yacc_sql.y"
         { (yyval.number)=TEXTS; }
#line 1747 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 384 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string);
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1756 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES insert_brace insert_element insert_brace SEMICOLON  */
#line 393 "yacc_sql.y"
{
  // CONTEXT->values[CONTEXT->value_length++] = *$6;

  CONTEXT->ssql->flag=SCF_INSERT;//"insert";
  inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-5].string));
  //inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length);

  //临时变量清零
  CONTEXT->value_lengths[S_TOP]=0;
}
#line 1771 "yacc_sql.tab.c"
    break;

  case 53: /* insert_brace: COMMA insert_element insert_brace  */
#line 407 "yacc_sql.y"
                                    {

}
#line 1779 "yacc_sql.tab.c"
    break;

  case 54: /* insert_element: LBRACE value value_list RBRACE  */
#line 413 "yacc_sql.y"
                               {
inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values[S_TOP], CONTEXT->value_lengths[S_TOP]);
CONTEXT->value_lengths[S_TOP] = 0;
}
#line 1788 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA value value_list  */
#line 420 "yacc_sql.y"
                              {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1796 "yacc_sql.tab.c"
    break;

  case 57: /* value: NUMBER  */
#line 425 "yacc_sql.y"
          {
      value_init_integer(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].number));
  		// value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
#line 1805 "yacc_sql.tab.c"
    break;

  case 58: /* value: FLOAT  */
#line 429 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].floats));
		}
#line 1813 "yacc_sql.tab.c"
    break;

  case 59: /* value: SSS  */
#line 432 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
		}
#line 1822 "yacc_sql.tab.c"
    break;

  case 60: /* value: DATE_STR  */
#line 436 "yacc_sql.y"
              {
        value_init_date(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++], (yyvsp[0].string));
    }
#line 1830 "yacc_sql.tab.c"
    break;

  case 61: /* value: NULL_V  */
#line 439 "yacc_sql.y"
         {
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
    }
#line 1838 "yacc_sql.tab.c"
    break;

  case 62: /* value: LBRACE select_ RBRACE  */
#line 442 "yacc_sql.y"
                        {
  value_init_select(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++],
                    &CONTEXT->ssql->selects[CONTEXT->stack[CONTEXT->ptr+1]]);
}
#line 1847 "yacc_sql.tab.c"
    break;

  case 63: /* delete: DELETE FROM ID where SEMICOLON  */
#line 450 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion,
					CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
			CONTEXT->condition_lengths[S_TOP] = 0;
    }
#line 1859 "yacc_sql.tab.c"
    break;

  case 64: /* update: UPDATE ID SET update_set updates_sets where SEMICOLON  */
#line 461 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_UPDATE;//"update";
  updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string),
               CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
  CONTEXT->condition_lengths[S_TOP] = 0;
  CONTEXT->value_lengths[S_TOP] = 0;
}
#line 1871 "yacc_sql.tab.c"
    break;

  case 65: /* update_set: ID EQ value  */
#line 471 "yacc_sql.y"
            {
  // updates_append(&CONTEXT->ssql->sstr.update, $1, &CONTEXT->values[CONTEXT->value_lengths[S_TOP] - 1]);
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1]);
}
#line 1880 "yacc_sql.tab.c"
    break;

  case 67: /* updates_sets: COMMA update_set updates_sets  */
#line 478 "yacc_sql.y"
                                {
}
#line 1887 "yacc_sql.tab.c"
    break;

  case 68: /* select_stmt: SELECT  */
#line 483 "yacc_sql.y"
       {
  CONTEXT->stack[++CONTEXT->ptr] = ++CONTEXT->selects_num;
  // printf("push select %zu, ptr: %d\n", CONTEXT->selects_num, CONTEXT->ptr);
  // CONTEXT->selects_num++;
  CONTEXT->ssql->selects_num = CONTEXT->selects_num;
}
#line 1898 "yacc_sql.tab.c"
    break;

  case 69: /* select_: select_stmt select_attr FROM rel_name rel_list where groupby having order  */
#line 491 "yacc_sql.y"
                                                                          {
  // printf("SELECT: num: %d, ptr: %d pop, table: %s, cond num: %d\n", S_TOP, CONTEXT->ptr, CONTEXT->ssql->selects[S_TOP].relations[0], CONTEXT->condition_lengths[S_TOP]);
  selects_append_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->conditions[S_TOP], CONTEXT->condition_lengths[S_TOP]);
  selects_append_having_conditions(&CONTEXT->ssql->selects[S_TOP], CONTEXT->having_conditions[S_TOP], CONTEXT->having_condition_lengths[S_TOP]);
  CONTEXT->ptr--;
}
#line 1909 "yacc_sql.tab.c"
    break;

  case 70: /* select: select_ SEMICOLON  */
#line 500 "yacc_sql.y"
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
#line 1926 "yacc_sql.tab.c"
    break;

  case 72: /* having: HAVING condition condition_list  */
#line 515 "yacc_sql.y"
                                  {

}
#line 1934 "yacc_sql.tab.c"
    break;

  case 74: /* groupby: GROUP BY ID groupby_ids  */
#line 522 "yacc_sql.y"
                          {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1944 "yacc_sql.tab.c"
    break;

  case 75: /* groupby: GROUP BY ID DOT ID groupby_ids  */
#line 527 "yacc_sql.y"
                                 {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1954 "yacc_sql.tab.c"
    break;

  case 77: /* groupby_ids: COMMA ID groupby_ids  */
#line 536 "yacc_sql.y"
                       {
  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1964 "yacc_sql.tab.c"
    break;

  case 78: /* groupby_ids: COMMA ID DOT ID groupby_ids  */
#line 541 "yacc_sql.y"
                              {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_groupby(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1974 "yacc_sql.tab.c"
    break;

  case 79: /* select_attr: STAR attr_list  */
#line 548 "yacc_sql.y"
               {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1984 "yacc_sql.tab.c"
    break;

  case 80: /* select_attr: ID attr_list  */
#line 553 "yacc_sql.y"
               {

  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 1995 "yacc_sql.tab.c"
    break;

  case 81: /* select_attr: ID DOT ID attr_list  */
#line 559 "yacc_sql.y"
                      {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
}
#line 2005 "yacc_sql.tab.c"
    break;

  case 82: /* select_attr: aggregation_attr attr_list  */
#line 564 "yacc_sql.y"
                             {
  printf("append aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]]);
}
#line 2014 "yacc_sql.tab.c"
    break;

  case 83: /* aggregation_attr: aggregation_func LBRACE ID aggregation_extra_id RBRACE  */
#line 571 "yacc_sql.y"
                                                       {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2023 "yacc_sql.tab.c"
    break;

  case 84: /* aggregation_attr: aggregation_func LBRACE ID DOT ID aggregation_extra_id RBRACE  */
#line 575 "yacc_sql.y"
                                                                {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_types[S_TOP], 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2033 "yacc_sql.tab.c"
    break;

  case 85: /* aggregation_attr: aggregation_func LBRACE RBRACE  */
#line 580 "yacc_sql.y"
                                 {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "fail", A_FAILURE, 0);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2043 "yacc_sql.tab.c"
    break;

  case 86: /* aggregation_attr: aggregation_func LBRACE STAR aggregation_extra_id RBRACE  */
#line 585 "yacc_sql.y"
                                                           {
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, "*", CONTEXT->a_types[S_TOP] != A_COUNT ? A_FAILURE : CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2053 "yacc_sql.tab.c"
    break;

  case 87: /* aggregation_attr: aggregation_func LBRACE NUMBER aggregation_extra_id RBRACE  */
#line 590 "yacc_sql.y"
                                                             {
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  aggregation_attr_init(&CONTEXT->aggr_attrs[S_TOP][CONTEXT->aggr_attr_lens[S_TOP]++], NULL, str, CONTEXT->a_types[S_TOP], 1);
  // selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
  CONTEXT->a_types[S_TOP] = A_NO;
}
#line 2065 "yacc_sql.tab.c"
    break;

  case 88: /* aggregation_attr: aggregation_func LBRACE FLOAT aggregation_extra_id RBRACE  */
#line 597 "yacc_sql.y"
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
#line 2085 "yacc_sql.tab.c"
    break;

  case 89: /* aggregation_func: MAX  */
#line 615 "yacc_sql.y"
    {
  CONTEXT->a_types[S_TOP] = A_MAX;
}
#line 2093 "yacc_sql.tab.c"
    break;

  case 90: /* aggregation_func: MIN  */
#line 618 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_MIN;
}
#line 2101 "yacc_sql.tab.c"
    break;

  case 91: /* aggregation_func: AVG  */
#line 621 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_AVG;
}
#line 2109 "yacc_sql.tab.c"
    break;

  case 92: /* aggregation_func: COUNT  */
#line 624 "yacc_sql.y"
        {
  CONTEXT->a_types[S_TOP] = A_COUNT;
}
#line 2117 "yacc_sql.tab.c"
    break;

  case 93: /* aggregation_func: SUM  */
#line 627 "yacc_sql.y"
      {
  CONTEXT->a_types[S_TOP] = A_SUM;
}
#line 2125 "yacc_sql.tab.c"
    break;

  case 95: /* aggregation_extra_id: COMMA ID aggregation_extra_id  */
#line 634 "yacc_sql.y"
                                {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2133 "yacc_sql.tab.c"
    break;

  case 96: /* aggregation_extra_id: COMMA ID DOT aggregation_extra_id  */
#line 637 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2141 "yacc_sql.tab.c"
    break;

  case 97: /* aggregation_extra_id: COMMA STAR aggregation_extra_id  */
#line 640 "yacc_sql.y"
                                  {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2149 "yacc_sql.tab.c"
    break;

  case 98: /* aggregation_extra_id: COMMA NUMBER aggregation_extra_id  */
#line 643 "yacc_sql.y"
                                    {
  CONTEXT->a_types[S_TOP] = A_FAILURE;
}
#line 2157 "yacc_sql.tab.c"
    break;

  case 100: /* attr_list: COMMA ID attr_list  */
#line 649 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2169 "yacc_sql.tab.c"
    break;

  case 101: /* attr_list: COMMA ID DOT ID attr_list  */
#line 656 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2181 "yacc_sql.tab.c"
    break;

  case 102: /* attr_list: COMMA STAR attr_list  */
#line 663 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &attr);
    }
#line 2191 "yacc_sql.tab.c"
    break;

  case 103: /* attr_list: COMMA aggregation_attr attr_list  */
#line 668 "yacc_sql.y"
                                   {
  printf("append aggr\n");
  selects_append_attribute(&CONTEXT->ssql->selects[S_TOP], &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]]);
}
#line 2200 "yacc_sql.tab.c"
    break;

  case 104: /* rel_name: ID inner_joins  */
#line 674 "yacc_sql.y"
               {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-1].string));
  selects_reverse_relations(&CONTEXT->ssql->selects[S_TOP], ++CONTEXT->joins);
  CONTEXT->joins = 0;
}
#line 2210 "yacc_sql.tab.c"
    break;

  case 106: /* inner_joins: INNER JOIN ID ON condition condition_list inner_joins  */
#line 683 "yacc_sql.y"
                                                        {
  selects_append_relation(&CONTEXT->ssql->selects[S_TOP], (yyvsp[-4].string));
  CONTEXT->joins++;
}
#line 2219 "yacc_sql.tab.c"
    break;

  case 108: /* order: ORDER BY order_component order_component_list  */
#line 690 "yacc_sql.y"
                                                    {
    }
#line 2226 "yacc_sql.tab.c"
    break;

  case 110: /* order_component: ID order_direction  */
#line 694 "yacc_sql.y"
                       {
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2237 "yacc_sql.tab.c"
    break;

  case 111: /* order_component: ID DOT ID order_direction  */
#line 700 "yacc_sql.y"
                              {
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[S_TOP], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2248 "yacc_sql.tab.c"
    break;

  case 112: /* order_direction: ASC  */
#line 709 "yacc_sql.y"
     {
  CONTEXT->is_desc = 0;
 }
#line 2256 "yacc_sql.tab.c"
    break;

  case 113: /* order_direction: DESC  */
#line 712 "yacc_sql.y"
        {
  CONTEXT->is_desc = 1;
 }
#line 2264 "yacc_sql.tab.c"
    break;

  case 114: /* order_direction: %empty  */
#line 715 "yacc_sql.y"
   {
  CONTEXT->is_desc = 0;
 }
#line 2272 "yacc_sql.tab.c"
    break;

  case 116: /* order_component_list: COMMA order_component order_component_list  */
#line 722 "yacc_sql.y"
                                                 {
      // 啥都不干
    }
#line 2280 "yacc_sql.tab.c"
    break;

  case 118: /* rel_list: COMMA rel_name rel_list  */
#line 728 "yacc_sql.y"
                              {
      // selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], $2);
		  }
#line 2288 "yacc_sql.tab.c"
    break;

  case 120: /* where: WHERE condition condition_list  */
#line 734 "yacc_sql.y"
                                     {	
      // CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2296 "yacc_sql.tab.c"
    break;

  case 122: /* condition_list: AND condition condition_list  */
#line 740 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2304 "yacc_sql.tab.c"
    break;

  case 123: /* condition: ID comOp value  */
#line 746 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

      // printf("current ptr %d\n", CONTEXT->ptr);
			Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

		}
#line 2321 "yacc_sql.tab.c"
    break;

  case 124: /* condition: value comOp value  */
#line 759 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 2];
			Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
		}
#line 2334 "yacc_sql.tab.c"
    break;

  case 125: /* condition: ID comOp ID  */
#line 768 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
		}
#line 2349 "yacc_sql.tab.c"
    break;

  case 126: /* condition: value comOp ID  */
#line 779 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

		}
#line 2364 "yacc_sql.tab.c"
    break;

  case 127: /* condition: ID DOT ID comOp value  */
#line 790 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 0, NULL, right_value);
      // printf("append condition in %d\n", S_TOP);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;

    }
#line 2380 "yacc_sql.tab.c"
    break;

  case 128: /* condition: value comOp ID DOT ID  */
#line 802 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 2395 "yacc_sql.tab.c"
    break;

  case 129: /* condition: ID DOT ID comOp ID DOT ID  */
#line 813 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comps[S_TOP], 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 2410 "yacc_sql.tab.c"
    break;

  case 130: /* condition: ID comOp LBRACE in_value in_value_list RBRACE  */
#line 823 "yacc_sql.y"
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
#line 2429 "yacc_sql.tab.c"
    break;

  case 131: /* condition: ID DOT ID comOp LBRACE value in_value_list RBRACE  */
#line 837 "yacc_sql.y"
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
#line 2447 "yacc_sql.tab.c"
    break;

  case 132: /* condition: EXISTS value  */
#line 850 "yacc_sql.y"
               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 2460 "yacc_sql.tab.c"
    break;

  case 133: /* condition: NOT EXISTS value  */
#line 858 "yacc_sql.y"
                   {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      value_init_null(&CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP]++]);
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, VALUE_NOT_EXISTS, 0, NULL, left_value, 0, NULL, right_value);
      CONTEXT->conditions[S_TOP][CONTEXT->condition_lengths[S_TOP]++] = condition;
    }
#line 2473 "yacc_sql.tab.c"
    break;

  case 134: /* condition: aggregation_attr comOp value  */
#line 866 "yacc_sql.y"
                               {
      Value *right_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 1, &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL,
                     0, NULL, right_value);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 2485 "yacc_sql.tab.c"
    break;

  case 135: /* condition: value comOp aggregation_attr  */
#line 873 "yacc_sql.y"
                               {
      Value *left_value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
      Condition condition;
      condition_init(&condition, CONTEXT->comps[S_TOP], 0, NULL, left_value, 1,
                     &CONTEXT->aggr_attrs[S_TOP][--CONTEXT->aggr_attr_lens[S_TOP]], NULL);
      CONTEXT->having_conditions[S_TOP][CONTEXT->having_condition_lengths[S_TOP]++] = condition;
    }
#line 2497 "yacc_sql.tab.c"
    break;

  case 136: /* in_value: value  */
#line 883 "yacc_sql.y"
      {
  Value *value = &CONTEXT->values[S_TOP][CONTEXT->value_lengths[S_TOP] - 1];
  int num = CONTEXT->in_valuelist_num;

  selects_append_in_value(&CONTEXT->ssql->valuelists[num], value);

}
#line 2509 "yacc_sql.tab.c"
    break;

  case 138: /* in_value_list: COMMA in_value in_value_list  */
#line 893 "yacc_sql.y"
                               {
}
#line 2516 "yacc_sql.tab.c"
    break;

  case 139: /* comOp: EQ  */
#line 897 "yacc_sql.y"
   {
  CONTEXT->comps[S_TOP] = EQUAL_TO;
}
#line 2524 "yacc_sql.tab.c"
    break;

  case 140: /* comOp: LT  */
#line 900 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_THAN; }
#line 2530 "yacc_sql.tab.c"
    break;

  case 141: /* comOp: GT  */
#line 901 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_THAN; }
#line 2536 "yacc_sql.tab.c"
    break;

  case 142: /* comOp: LE  */
#line 902 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = LESS_EQUAL; }
#line 2542 "yacc_sql.tab.c"
    break;

  case 143: /* comOp: GE  */
#line 903 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = GREAT_EQUAL; }
#line 2548 "yacc_sql.tab.c"
    break;

  case 144: /* comOp: NE  */
#line 904 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = NOT_EQUAL; }
#line 2554 "yacc_sql.tab.c"
    break;

  case 145: /* comOp: IS  */
#line 905 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = IS_EQUAL; }
#line 2560 "yacc_sql.tab.c"
    break;

  case 146: /* comOp: IS NOT  */
#line 906 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = IS_NOT_EQUAL; }
#line 2566 "yacc_sql.tab.c"
    break;

  case 147: /* comOp: NOT LIKE  */
#line 907 "yacc_sql.y"
           { CONTEXT->comps[S_TOP] = STR_NOT_LIKE; }
#line 2572 "yacc_sql.tab.c"
    break;

  case 148: /* comOp: LIKE  */
#line 908 "yacc_sql.y"
       { CONTEXT->comps[S_TOP] = STR_LIKE; }
#line 2578 "yacc_sql.tab.c"
    break;

  case 149: /* comOp: IN  */
#line 909 "yacc_sql.y"
     { CONTEXT->comps[S_TOP] = VALUE_IN; }
#line 2584 "yacc_sql.tab.c"
    break;

  case 150: /* comOp: NOT IN  */
#line 910 "yacc_sql.y"
         { CONTEXT->comps[S_TOP] = VALUE_NOT_IN; }
#line 2590 "yacc_sql.tab.c"
    break;

  case 151: /* load_data: LOAD DATA_T INFILE SSS INTO TABLE ID SEMICOLON  */
#line 915 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2599 "yacc_sql.tab.c"
    break;


#line 2603 "yacc_sql.tab.c"

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

#line 920 "yacc_sql.y"

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
