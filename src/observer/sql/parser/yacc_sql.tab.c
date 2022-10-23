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
  size_t is_desc;

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


#line 144 "yacc_sql.tab.c"

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
  YYSYMBOL_NUMBER = 63,                    /* NUMBER  */
  YYSYMBOL_DATE_STR = 64,                  /* DATE_STR  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_ID = 66,                        /* ID  */
  YYSYMBOL_PATH = 67,                      /* PATH  */
  YYSYMBOL_SSS = 68,                       /* SSS  */
  YYSYMBOL_STAR = 69,                      /* STAR  */
  YYSYMBOL_STRING_V = 70,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_commands = 72,                  /* commands  */
  YYSYMBOL_command = 73,                   /* command  */
  YYSYMBOL_exit = 74,                      /* exit  */
  YYSYMBOL_help = 75,                      /* help  */
  YYSYMBOL_sync = 76,                      /* sync  */
  YYSYMBOL_begin = 77,                     /* begin  */
  YYSYMBOL_commit = 78,                    /* commit  */
  YYSYMBOL_rollback = 79,                  /* rollback  */
  YYSYMBOL_drop_table = 80,                /* drop_table  */
  YYSYMBOL_show_tables = 81,               /* show_tables  */
  YYSYMBOL_desc_table = 82,                /* desc_table  */
  YYSYMBOL_show_index = 83,                /* show_index  */
  YYSYMBOL_create_index = 84,              /* create_index  */
  YYSYMBOL_index_ids = 85,                 /* index_ids  */
  YYSYMBOL_drop_index = 86,                /* drop_index  */
  YYSYMBOL_create_table = 87,              /* create_table  */
  YYSYMBOL_attr_def_list = 88,             /* attr_def_list  */
  YYSYMBOL_attr_def = 89,                  /* attr_def  */
  YYSYMBOL_number = 90,                    /* number  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_ID_get = 92,                    /* ID_get  */
  YYSYMBOL_insert = 93,                    /* insert  */
  YYSYMBOL_insert_brace = 94,              /* insert_brace  */
  YYSYMBOL_insert_element = 95,            /* insert_element  */
  YYSYMBOL_value_list = 96,                /* value_list  */
  YYSYMBOL_value = 97,                     /* value  */
  YYSYMBOL_delete = 98,                    /* delete  */
  YYSYMBOL_update = 99,                    /* update  */
  YYSYMBOL_update_set = 100,               /* update_set  */
  YYSYMBOL_updates_sets = 101,             /* updates_sets  */
  YYSYMBOL_internal_select = 102,          /* internal_select  */
  YYSYMBOL_select = 103,                   /* select  */
  YYSYMBOL_select_attr = 104,              /* select_attr  */
  YYSYMBOL_aggregation_attr = 105,         /* aggregation_attr  */
  YYSYMBOL_aggregation_func = 106,         /* aggregation_func  */
  YYSYMBOL_aggregation_extra_id = 107,     /* aggregation_extra_id  */
  YYSYMBOL_attr_list = 108,                /* attr_list  */
  YYSYMBOL_rel_name = 109,                 /* rel_name  */
  YYSYMBOL_inner_joins = 110,              /* inner_joins  */
  YYSYMBOL_order = 111,                    /* order  */
  YYSYMBOL_order_component = 112,          /* order_component  */
  YYSYMBOL_order_direction = 113,          /* order_direction  */
  YYSYMBOL_114_1 = 114,                    /* $@1  */
  YYSYMBOL_order_component_list = 115,     /* order_component_list  */
  YYSYMBOL_rel_list = 116,                 /* rel_list  */
  YYSYMBOL_where = 117,                    /* where  */
  YYSYMBOL_condition_list = 118,           /* condition_list  */
  YYSYMBOL_condition = 119,                /* condition  */
  YYSYMBOL_comOp = 120,                    /* comOp  */
  YYSYMBOL_load_data = 121                 /* load_data  */
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
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   170,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   195,   200,   205,   211,   217,   223,   229,   235,
     241,   248,   255,   261,   269,   271,   277,   284,   293,   295,
     299,   310,   321,   327,   335,   338,   339,   340,   341,   342,
     345,   354,   373,   375,   381,   386,   388,   393,   396,   399,
     403,   406,   412,   422,   433,   436,   442,   444,   449,   465,
     488,   493,   499,   504,   510,   516,   522,   528,   534,   542,
     561,   564,   567,   570,   573,   578,   580,   583,   586,   589,
     593,   595,   602,   609,   614,   619,   626,   628,   633,   635,
     638,   639,   645,   653,   654,   657,   657,   665,   667,   671,
     673,   677,   679,   683,   685,   690,   711,   731,   751,   773,
     794,   815,   838,   839,   840,   841,   842,   843,   844,   845,
     846,   847,   851
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
  "TEXT_T", "NUMBER", "DATE_STR", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "show_index", "create_index", "index_ids", "drop_index", "create_table",
  "attr_def_list", "attr_def", "number", "type", "ID_get", "insert",
  "insert_brace", "insert_element", "value_list", "value", "delete",
  "update", "update_set", "updates_sets", "internal_select", "select",
  "select_attr", "aggregation_attr", "aggregation_func",
  "aggregation_extra_id", "attr_list", "rel_name", "inner_joins", "order",
  "order_component", "order_direction", "$@1", "order_component_list",
  "rel_list", "where", "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-217)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -217,    78,  -217,    12,    44,    77,   -31,    20,    38,    23,
      26,     2,    59,    69,    73,    81,    82,    45,  -217,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,    28,    29,    88,
      34,    35,  -217,  -217,  -217,  -217,  -217,     4,    68,    80,
      68,    92,   108,   111,    85,  -217,    50,    63,    97,  -217,
    -217,  -217,  -217,  -217,    94,   116,   100,    76,   141,   142,
      90,    83,  -217,  -217,    84,  -217,     8,  -217,  -217,    86,
     106,   117,    89,   105,   109,   112,   113,  -217,  -217,     5,
      68,    68,    68,    96,   136,  -217,   140,   140,     6,   140,
     171,   162,   104,   190,   156,   181,   176,  -217,   187,    -8,
     191,   143,   144,  -217,  -217,  -217,  -217,   152,  -217,    84,
     117,   -27,   194,   195,   147,   197,   198,  -217,   200,   200,
    -217,  -217,  -217,  -217,    79,  -217,   122,   185,  -217,    -4,
      89,   117,   212,   109,   202,  -217,  -217,  -217,  -217,  -217,
       1,   154,   205,    68,   157,   136,   164,   140,    11,   140,
    -217,  -217,   140,  -217,  -217,   138,   162,   162,   158,  -217,
     172,  -217,  -217,  -217,  -217,  -217,   168,  -217,   118,   124,
     104,  -217,   218,  -217,  -217,   181,   225,   163,   187,   227,
     169,  -217,   178,   215,   170,  -217,   201,  -217,   173,   234,
    -217,   140,  -217,  -217,   221,   222,  -217,   236,   122,  -217,
    -217,  -217,  -217,   214,  -217,   185,    77,  -217,  -217,   239,
    -217,  -217,  -217,   226,  -217,   179,   229,   215,   104,   182,
    -217,  -217,  -217,   138,   230,  -217,   132,   183,  -217,   220,
    -217,  -217,   215,   241,   235,   185,     3,   233,   222,  -217,
     228,  -217,  -217,   188,  -217,  -217,   250,    96,  -217,   192,
    -217,  -217,   182,  -217,  -217,   193,   136,  -217,  -217,  -217,
       9,   233,  -217,   117,  -217,  -217,   240,  -217
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    21,    12,
      13,     8,     5,     7,     6,     4,    18,     0,     0,     0,
       0,     0,    80,    81,    83,    82,    84,    90,    90,     0,
      90,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,    27,    23,    22,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    70,     0,    73,     0,    30,    29,     0,
       0,   111,     0,     0,     0,     0,     0,    28,    36,    90,
      90,    90,    90,    96,   109,    76,    85,    85,    85,    85,
       0,    52,     0,     0,     0,    66,     0,    50,    38,     0,
       0,     0,     0,    91,    93,    94,    72,     0,    95,     0,
     111,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      61,    57,    60,    58,     0,    59,     0,   113,    62,     0,
       0,   111,     0,     0,     0,    45,    46,    47,    48,    49,
      41,     0,     0,    90,     0,   109,    98,    85,    85,    85,
      78,    79,    85,    74,    77,     0,    52,    52,     0,   122,
     128,   123,   124,   125,   126,   127,     0,   131,     0,     0,
       0,   112,     0,    64,    65,    66,     0,     0,    38,     0,
       0,    42,     0,    34,     0,    92,     0,   110,     0,     0,
      89,    85,    86,    88,     0,    55,    53,     0,     0,   129,
     130,   117,   115,   118,   116,   113,     0,    67,    63,     0,
      39,    37,    44,     0,    43,     0,     0,    34,     0,   100,
      69,    87,    75,     0,     0,    51,     0,     0,   114,     0,
     132,    40,    34,     0,     0,   113,   103,   107,    55,    54,
       0,   119,   120,     0,    35,    32,     0,    96,   105,     0,
     104,   101,   100,    99,    56,     0,   109,    33,    97,   106,
     103,   107,   121,   111,   102,   108,     0,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,  -217,  -217,  -217,  -216,  -217,  -217,    72,   119,  -217,
    -217,  -217,  -217,   -87,   127,    13,  -131,  -217,  -217,   123,
      87,  -217,  -217,    48,   196,  -217,   -92,   -46,   146,    10,
    -217,     7,    -2,  -217,    -1,  -154,  -120,  -205,  -171,  -133,
    -217
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   226,    30,    31,   144,   108,   223,
     150,   109,    32,   129,   166,   234,   136,    33,    34,   105,
     141,   184,    35,    49,    50,    51,   122,    72,    94,   118,
     199,   247,   261,   269,   263,   120,   103,   181,   137,   178,
      36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     156,   197,    73,   179,    75,   123,   125,   126,   183,   215,
     238,   244,   182,   258,   145,   146,   147,   190,    37,   258,
      38,   186,    70,    70,   121,    95,   254,    53,    54,   121,
     259,    71,   112,   124,   205,    52,   157,   148,   201,   158,
     257,    55,   159,   113,   114,   115,   116,   212,   214,   130,
      40,    56,    41,   191,   149,   192,    57,   245,    39,   131,
     132,   133,    59,   260,   135,   200,   202,   203,    58,   260,
     204,    96,    60,    97,    98,   236,    61,    99,     2,   206,
     207,    64,     3,     4,    62,    63,    70,     5,     6,     7,
       8,     9,    10,    11,    65,    66,    67,    12,    13,    14,
      68,    69,   248,    15,    16,   251,   168,   195,    76,   231,
      74,    77,   273,    17,    78,    79,    80,   169,   170,   171,
     172,   173,   174,   175,    42,    43,    44,    45,    46,    81,
      82,    83,    84,   176,    85,   101,   177,    42,    43,    44,
      45,    46,    86,    47,    87,    88,    48,   111,   102,    92,
      93,   117,   100,   276,   119,   104,    89,   130,   121,    90,
     169,   170,   171,   172,   173,   174,   175,   131,   132,   133,
     134,   130,   135,   106,   127,   107,   176,   130,   110,   177,
     128,   131,   132,   133,   211,   130,   135,   131,   132,   133,
     213,   130,   135,   138,   139,   131,   132,   133,   250,   140,
     135,   131,   132,   133,   142,   143,   135,   151,   154,   152,
     153,   160,   161,   162,   163,   164,   165,   180,   187,   189,
     193,   194,   198,   196,   208,   210,   209,   216,   218,   219,
     221,   224,   222,   225,   229,   228,   227,   230,   232,   235,
     233,   237,   240,   241,   255,   242,   243,   249,   246,   252,
     253,   262,   256,   267,   266,   265,   167,   277,   270,   272,
     220,   264,   188,   185,   239,   155,    91,   268,   274,   271,
     275,     0,   217
};

static const yytype_int16 yycheck[] =
{
     120,   155,    48,   136,    50,    97,    98,    99,   139,   180,
     215,   227,    16,    10,    22,    23,    24,    16,     6,    10,
       8,   141,    18,    18,    18,    17,   242,     7,     8,    18,
      27,    27,    27,    27,   165,    66,    63,    45,    27,    66,
     245,     3,    69,    89,    90,    91,    92,   178,   179,    53,
       6,    28,     8,    52,    62,    54,    30,   228,    46,    63,
      64,    65,     3,    60,    68,   157,   158,   159,    66,    60,
     162,    63,     3,    65,    66,   208,     3,    69,     0,   166,
     167,    36,     4,     5,     3,     3,    18,     9,    10,    11,
      12,    13,    14,    15,    66,    66,     8,    19,    20,    21,
      66,    66,   233,    25,    26,   236,    27,   153,    16,   201,
      30,     3,   266,    35,     3,    30,    66,    38,    39,    40,
      41,    42,    43,    44,    47,    48,    49,    50,    51,    66,
      33,    37,    16,    54,    34,    29,    57,    47,    48,    49,
      50,    51,    66,    66,     3,     3,    69,    34,    31,    66,
      66,    55,    66,   273,    18,    66,    66,    53,    18,    69,
      38,    39,    40,    41,    42,    43,    44,    63,    64,    65,
      66,    53,    68,    68,     3,    66,    54,    53,    66,    57,
      18,    63,    64,    65,    66,    53,    68,    63,    64,    65,
      66,    53,    68,     3,    38,    63,    64,    65,    66,    18,
      68,    63,    64,    65,    28,    18,    68,    16,    56,    66,
      66,    17,    17,    66,    17,    17,    16,    32,     6,    17,
      66,    16,    58,    66,    66,    57,    54,     9,     3,    66,
       3,    53,    63,    18,    61,    34,    66,     3,    17,     3,
      18,    27,     3,    17,     3,    66,    17,    17,    66,    66,
      30,    18,    17,     3,    66,    27,   129,    17,    66,    66,
     188,   248,   143,   140,   216,   119,    70,   257,   270,   262,
     271,    -1,   185
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    35,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      86,    87,    93,    98,    99,   103,   121,     6,     8,    46,
       6,     8,    47,    48,    49,    50,    51,    66,    69,   104,
     105,   106,    66,     7,     8,     3,    28,    30,    66,     3,
       3,     3,     3,     3,    36,    66,    66,     8,    66,    66,
      18,    27,   108,   108,    30,   108,    16,     3,     3,    30,
      66,    66,    33,    37,    16,    34,    66,     3,     3,    66,
      69,   105,    66,    66,   109,    17,    63,    65,    66,    69,
      66,    29,    31,   117,    66,   100,    68,    66,    89,    92,
      66,    34,    27,   108,   108,   108,   108,    55,   110,    18,
     116,    18,   107,   107,    27,   107,   107,     3,    18,    94,
      53,    63,    64,    65,    66,    68,    97,   119,     3,    38,
      18,   101,    28,    18,    88,    22,    23,    24,    45,    62,
      91,    16,    66,    66,    56,   109,   117,    63,    66,    69,
      17,    17,    66,    17,    17,    16,    95,    95,    27,    38,
      39,    40,    41,    42,    43,    44,    54,    57,   120,   120,
      32,   118,    16,    97,   102,   100,   117,     6,    89,    17,
      16,    52,    54,    66,    16,   108,    66,   116,    58,   111,
     107,    27,   107,   107,   107,    97,    94,    94,    66,    54,
      57,    66,    97,    66,    97,   119,     9,   101,     3,    66,
      88,     3,    63,    90,    53,    18,    85,    66,    34,    61,
       3,   107,    17,    18,    96,     3,   120,    27,   118,   104,
       3,    17,    66,    17,    85,   119,    66,   112,    97,    17,
      66,    97,    66,    30,    85,     3,    17,   118,    10,    27,
      60,   113,    18,   115,    96,    27,    66,     3,   110,   114,
      66,   112,    66,   116,   113,   115,   117,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    84,    85,    85,    86,    87,    88,    88,
      89,    89,    89,    89,    90,    91,    91,    91,    91,    91,
      92,    93,    94,    94,    95,    96,    96,    97,    97,    97,
      97,    97,    98,    99,   100,   100,   101,   101,   102,   103,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   109,   110,   110,   111,   111,
     112,   112,   112,   113,   113,   114,   113,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121
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
       1,     1,     5,     7,     3,     3,     0,     3,     8,     8,
       2,     2,     4,     2,     5,     7,     3,     5,     5,     5,
       1,     1,     1,     1,     1,     0,     3,     4,     3,     3,
       0,     3,     5,     3,     3,     2,     0,     7,     0,     4,
       0,     2,     4,     0,     1,     0,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     3,     3,     3,     3,     5,
       5,     7,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     8
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
#line 195 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1456 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 200 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1464 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 205 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1472 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 211 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1480 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 217 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1488 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 223 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1496 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 229 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1505 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 235 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1513 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 241 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1522 "yacc_sql.tab.c"
    break;

  case 31: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 248 "yacc_sql.y"
                             {
  CONTEXT->ssql->flag = SCF_SHOW_INDEX;
  show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
}
#line 1531 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_ids RBRACE SEMICOLON  */
#line 256 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
}
#line 1541 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE_T INDEX ID ON ID LBRACE ID index_ids RBRACE SEMICOLON  */
#line 262 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
  create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
}
#line 1551 "yacc_sql.tab.c"
    break;

  case 35: /* index_ids: COMMA ID index_ids  */
#line 271 "yacc_sql.y"
                      {
  create_index_append(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
}
#line 1559 "yacc_sql.tab.c"
    break;

  case 36: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 278 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1568 "yacc_sql.tab.c"
    break;

  case 37: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 285 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1580 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 295 "yacc_sql.y"
                                   {    }
#line 1586 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 300 "yacc_sql.y"
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
#line 1601 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type  */
#line 311 "yacc_sql.y"
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
#line 1616 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type NULLABLE  */
#line 321 "yacc_sql.y"
                       {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_length++;
}
#line 1627 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type NOT NULL_V  */
#line 327 "yacc_sql.y"
                         {
      AttrInfo attribute;
      attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
      create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
      CONTEXT->value_length++;
}
#line 1638 "yacc_sql.tab.c"
    break;

  case 44: /* number: NUMBER  */
#line 335 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1644 "yacc_sql.tab.c"
    break;

  case 45: /* type: INT_T  */
#line 338 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1650 "yacc_sql.tab.c"
    break;

  case 46: /* type: STRING_T  */
#line 339 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1656 "yacc_sql.tab.c"
    break;

  case 47: /* type: FLOAT_T  */
#line 340 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1662 "yacc_sql.tab.c"
    break;

  case 48: /* type: DATE_T  */
#line 341 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1668 "yacc_sql.tab.c"
    break;

  case 49: /* type: TEXT_T  */
#line 342 "yacc_sql.y"
         { (yyval.number)=TEXTS; }
#line 1674 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 346 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string);
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1683 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES insert_brace insert_element insert_brace SEMICOLON  */
#line 355 "yacc_sql.y"
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
#line 1705 "yacc_sql.tab.c"
    break;

  case 53: /* insert_brace: COMMA insert_element insert_brace  */
#line 375 "yacc_sql.y"
                                    {

}
#line 1713 "yacc_sql.tab.c"
    break;

  case 54: /* insert_element: LBRACE value value_list RBRACE  */
#line 381 "yacc_sql.y"
                               {
inserts_append_values(&CONTEXT->ssql->sstr.insertion, CONTEXT->values, CONTEXT->value_length);
CONTEXT->value_length = 0;
}
#line 1722 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA value value_list  */
#line 388 "yacc_sql.y"
                              {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1730 "yacc_sql.tab.c"
    break;

  case 57: /* value: NUMBER  */
#line 393 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1738 "yacc_sql.tab.c"
    break;

  case 58: /* value: FLOAT  */
#line 396 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1746 "yacc_sql.tab.c"
    break;

  case 59: /* value: SSS  */
#line 399 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1755 "yacc_sql.tab.c"
    break;

  case 60: /* value: DATE_STR  */
#line 403 "yacc_sql.y"
              {
        value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1763 "yacc_sql.tab.c"
    break;

  case 61: /* value: NULL_V  */
#line 406 "yacc_sql.y"
         {
      value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1771 "yacc_sql.tab.c"
    break;

  case 62: /* delete: DELETE FROM ID where SEMICOLON  */
#line 413 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion,
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
    }
#line 1783 "yacc_sql.tab.c"
    break;

  case 63: /* update: UPDATE ID SET update_set updates_sets where SEMICOLON  */
#line 423 "yacc_sql.y"
{
  CONTEXT->ssql->flag = SCF_UPDATE;//"update";
  updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string),
               CONTEXT->conditions, CONTEXT->condition_length);
  CONTEXT->condition_length = 0;
  CONTEXT->value_length = 0;
}
#line 1795 "yacc_sql.tab.c"
    break;

  case 64: /* update_set: ID EQ value  */
#line 433 "yacc_sql.y"
            {
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[CONTEXT->value_length - 1]);
}
#line 1803 "yacc_sql.tab.c"
    break;

  case 65: /* update_set: ID EQ internal_select  */
#line 436 "yacc_sql.y"
                        {
  value_init_select(&CONTEXT->values[CONTEXT->value_length],
                    &CONTEXT->ssql->selects[CONTEXT->selects_num - 1]);
  updates_append(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string), &CONTEXT->values[CONTEXT->value_length++]);
}
#line 1813 "yacc_sql.tab.c"
    break;

  case 67: /* updates_sets: COMMA update_set updates_sets  */
#line 444 "yacc_sql.y"
                                {
}
#line 1820 "yacc_sql.tab.c"
    break;

  case 68: /* internal_select: LBRACE SELECT select_attr FROM ID rel_list where RBRACE  */
#line 449 "yacc_sql.y"
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
#line 1839 "yacc_sql.tab.c"
    break;

  case 69: /* select: SELECT select_attr FROM rel_name rel_list where order SEMICOLON  */
#line 466 "yacc_sql.y"
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
#line 1864 "yacc_sql.tab.c"
    break;

  case 70: /* select_attr: STAR attr_list  */
#line 488 "yacc_sql.y"
               {
  RelAttr attr;
  relation_attr_init(&attr, NULL, "*");
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1874 "yacc_sql.tab.c"
    break;

  case 71: /* select_attr: ID attr_list  */
#line 493 "yacc_sql.y"
               {

  RelAttr attr;
  relation_attr_init(&attr, NULL, (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1885 "yacc_sql.tab.c"
    break;

  case 72: /* select_attr: ID DOT ID attr_list  */
#line 499 "yacc_sql.y"
                      {
  RelAttr attr;
  relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
}
#line 1895 "yacc_sql.tab.c"
    break;

  case 73: /* select_attr: aggregation_attr attr_list  */
#line 504 "yacc_sql.y"
                             {

}
#line 1903 "yacc_sql.tab.c"
    break;

  case 74: /* aggregation_attr: aggregation_func LBRACE ID aggregation_extra_id RBRACE  */
#line 510 "yacc_sql.y"
                                                       {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1914 "yacc_sql.tab.c"
    break;

  case 75: /* aggregation_attr: aggregation_func LBRACE ID DOT ID aggregation_extra_id RBRACE  */
#line 516 "yacc_sql.y"
                                                                {
  RelAttr attr;
  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1925 "yacc_sql.tab.c"
    break;

  case 76: /* aggregation_attr: aggregation_func LBRACE RBRACE  */
#line 522 "yacc_sql.y"
                                 {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, "fail", A_FAILURE, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1936 "yacc_sql.tab.c"
    break;

  case 77: /* aggregation_attr: aggregation_func LBRACE STAR aggregation_extra_id RBRACE  */
#line 528 "yacc_sql.y"
                                                           {
  RelAttr attr;
  aggregation_attr_init(&attr, NULL, "*", CONTEXT->a_type != A_COUNT ? A_FAILURE : CONTEXT->a_type, 0);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1947 "yacc_sql.tab.c"
    break;

  case 78: /* aggregation_attr: aggregation_func LBRACE NUMBER aggregation_extra_id RBRACE  */
#line 534 "yacc_sql.y"
                                                             {
  RelAttr attr;
  char *str = malloc(10 * sizeof(char));
  snprintf(str, 10, "%d", (yyvsp[-2].number));
  aggregation_attr_init(&attr, NULL, str, CONTEXT->a_type, 1);
  selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
  CONTEXT->a_type = A_NO;
}
#line 1960 "yacc_sql.tab.c"
    break;

  case 79: /* aggregation_attr: aggregation_func LBRACE FLOAT aggregation_extra_id RBRACE  */
#line 542 "yacc_sql.y"
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
#line 1981 "yacc_sql.tab.c"
    break;

  case 80: /* aggregation_func: MAX  */
#line 561 "yacc_sql.y"
    {
  CONTEXT->a_type = A_MAX;
}
#line 1989 "yacc_sql.tab.c"
    break;

  case 81: /* aggregation_func: MIN  */
#line 564 "yacc_sql.y"
      {
  CONTEXT->a_type = A_MIN;
}
#line 1997 "yacc_sql.tab.c"
    break;

  case 82: /* aggregation_func: AVG  */
#line 567 "yacc_sql.y"
      {
  CONTEXT->a_type = A_AVG;
}
#line 2005 "yacc_sql.tab.c"
    break;

  case 83: /* aggregation_func: COUNT  */
#line 570 "yacc_sql.y"
        {
  CONTEXT->a_type = A_COUNT;
}
#line 2013 "yacc_sql.tab.c"
    break;

  case 84: /* aggregation_func: SUM  */
#line 573 "yacc_sql.y"
      {
  CONTEXT->a_type = A_SUM;
}
#line 2021 "yacc_sql.tab.c"
    break;

  case 86: /* aggregation_extra_id: COMMA ID aggregation_extra_id  */
#line 580 "yacc_sql.y"
                                {
  CONTEXT->a_type = A_FAILURE;
}
#line 2029 "yacc_sql.tab.c"
    break;

  case 87: /* aggregation_extra_id: COMMA ID DOT aggregation_extra_id  */
#line 583 "yacc_sql.y"
                                    {
  CONTEXT->a_type = A_FAILURE;
}
#line 2037 "yacc_sql.tab.c"
    break;

  case 88: /* aggregation_extra_id: COMMA STAR aggregation_extra_id  */
#line 586 "yacc_sql.y"
                                  {
  CONTEXT->a_type = A_FAILURE;
}
#line 2045 "yacc_sql.tab.c"
    break;

  case 89: /* aggregation_extra_id: COMMA NUMBER aggregation_extra_id  */
#line 589 "yacc_sql.y"
                                    {
  CONTEXT->a_type = A_FAILURE;
}
#line 2053 "yacc_sql.tab.c"
    break;

  case 91: /* attr_list: COMMA ID attr_list  */
#line 595 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2065 "yacc_sql.tab.c"
    break;

  case 92: /* attr_list: COMMA ID DOT ID attr_list  */
#line 602 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2077 "yacc_sql.tab.c"
    break;

  case 93: /* attr_list: COMMA STAR attr_list  */
#line 609 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr);
    }
#line 2087 "yacc_sql.tab.c"
    break;

  case 94: /* attr_list: COMMA aggregation_attr attr_list  */
#line 614 "yacc_sql.y"
                                   {

}
#line 2095 "yacc_sql.tab.c"
    break;

  case 95: /* rel_name: ID inner_joins  */
#line 619 "yacc_sql.y"
               {
  selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], (yyvsp[-1].string));
  selects_reverse_relations(&CONTEXT->ssql->selects[CONTEXT->selects_num], ++CONTEXT->joins);
  CONTEXT->joins = 0;
}
#line 2105 "yacc_sql.tab.c"
    break;

  case 97: /* inner_joins: INNER JOIN ID ON condition condition_list inner_joins  */
#line 628 "yacc_sql.y"
                                                        {
  selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], (yyvsp[-4].string));
  CONTEXT->joins++;
}
#line 2114 "yacc_sql.tab.c"
    break;

  case 99: /* order: ORDER BY order_component order_component_list  */
#line 635 "yacc_sql.y"
                                                    {
    }
#line 2121 "yacc_sql.tab.c"
    break;

  case 101: /* order_component: ID order_direction  */
#line 639 "yacc_sql.y"
                       {
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2132 "yacc_sql.tab.c"
    break;

  case 102: /* order_component: ID DOT ID order_direction  */
#line 645 "yacc_sql.y"
                              {
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
      selects_append_order_field(&CONTEXT->ssql->selects[CONTEXT->selects_num], &attr, CONTEXT->is_desc);
      CONTEXT->is_desc = 0;
  }
#line 2143 "yacc_sql.tab.c"
    break;

  case 104: /* order_direction: ASC  */
#line 654 "yacc_sql.y"
        {
  CONTEXT->is_desc = 0;
 }
#line 2151 "yacc_sql.tab.c"
    break;

  case 105: /* $@1: %empty  */
#line 657 "yacc_sql.y"
        {
  CONTEXT->is_desc = 1;
 }
#line 2159 "yacc_sql.tab.c"
    break;

  case 106: /* order_direction: DESC $@1  */
#line 660 "yacc_sql.y"
 {
  CONTEXT->is_desc = 0;
 }
#line 2167 "yacc_sql.tab.c"
    break;

  case 108: /* order_component_list: COMMA order_component order_component_list  */
#line 667 "yacc_sql.y"
                                                 {
      // 啥都不干
    }
#line 2175 "yacc_sql.tab.c"
    break;

  case 110: /* rel_list: COMMA rel_name rel_list  */
#line 673 "yacc_sql.y"
                              {
      // selects_append_relation(&CONTEXT->ssql->selects[CONTEXT->selects_num], $2);
		  }
#line 2183 "yacc_sql.tab.c"
    break;

  case 112: /* where: WHERE condition condition_list  */
#line 679 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2191 "yacc_sql.tab.c"
    break;

  case 114: /* condition_list: AND condition condition_list  */
#line 685 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2199 "yacc_sql.tab.c"
    break;

  case 115: /* condition: ID comOp value  */
#line 691 "yacc_sql.y"
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
#line 2224 "yacc_sql.tab.c"
    break;

  case 116: /* condition: value comOp value  */
#line 712 "yacc_sql.y"
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
#line 2248 "yacc_sql.tab.c"
    break;

  case 117: /* condition: ID comOp ID  */
#line 732 "yacc_sql.y"
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
#line 2272 "yacc_sql.tab.c"
    break;

  case 118: /* condition: value comOp ID  */
#line 752 "yacc_sql.y"
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
#line 2298 "yacc_sql.tab.c"
    break;

  case 119: /* condition: ID DOT ID comOp value  */
#line 774 "yacc_sql.y"
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
#line 2323 "yacc_sql.tab.c"
    break;

  case 120: /* condition: value comOp ID DOT ID  */
#line 795 "yacc_sql.y"
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
#line 2348 "yacc_sql.tab.c"
    break;

  case 121: /* condition: ID DOT ID comOp ID DOT ID  */
#line 816 "yacc_sql.y"
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
#line 2371 "yacc_sql.tab.c"
    break;

  case 122: /* comOp: EQ  */
#line 838 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2377 "yacc_sql.tab.c"
    break;

  case 123: /* comOp: LT  */
#line 839 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2383 "yacc_sql.tab.c"
    break;

  case 124: /* comOp: GT  */
#line 840 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2389 "yacc_sql.tab.c"
    break;

  case 125: /* comOp: LE  */
#line 841 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2395 "yacc_sql.tab.c"
    break;

  case 126: /* comOp: GE  */
#line 842 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2401 "yacc_sql.tab.c"
    break;

  case 127: /* comOp: NE  */
#line 843 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2407 "yacc_sql.tab.c"
    break;

  case 128: /* comOp: IS  */
#line 844 "yacc_sql.y"
     { CONTEXT->comp = IS_EQUAL; }
#line 2413 "yacc_sql.tab.c"
    break;

  case 129: /* comOp: IS NOT  */
#line 845 "yacc_sql.y"
         { CONTEXT->comp = IS_NOT_EQUAL; }
#line 2419 "yacc_sql.tab.c"
    break;

  case 130: /* comOp: NOT LIKE  */
#line 846 "yacc_sql.y"
           { CONTEXT->comp = STR_NOT_LIKE; }
#line 2425 "yacc_sql.tab.c"
    break;

  case 131: /* comOp: LIKE  */
#line 847 "yacc_sql.y"
       { CONTEXT->comp = STR_LIKE; }
#line 2431 "yacc_sql.tab.c"
    break;

  case 132: /* load_data: LOAD DATA_T INFILE SSS INTO TABLE ID SEMICOLON  */
#line 852 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2440 "yacc_sql.tab.c"
    break;


#line 2444 "yacc_sql.tab.c"

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

#line 857 "yacc_sql.y"

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
