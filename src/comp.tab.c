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

/* "%code top" blocks.  */
#line 6 "comp.y"

  #include <stdio.h>

#line 72 "src/comp.tab.c"




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

#include "comp.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_MODULE = 3,               /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_IMPORT = 4,               /* TOKEN_IMPORT  */
  YYSYMBOL_TOKEN_FUN = 5,                  /* TOKEN_FUN  */
  YYSYMBOL_TOKEN_VAL = 6,                  /* TOKEN_VAL  */
  YYSYMBOL_TOKEN_VAR = 7,                  /* TOKEN_VAR  */
  YYSYMBOL_TOKEN_TYPE = 8,                 /* TOKEN_TYPE  */
  YYSYMBOL_TOKEN_DO = 9,                   /* TOKEN_DO  */
  YYSYMBOL_TOKEN_IF = 10,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 11,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_FOR = 12,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_WHILE = 13,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_UNTIL = 14,               /* TOKEN_UNTIL  */
  YYSYMBOL_TOKEN_SWITCH = 15,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_NOT = 16,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AND = 17,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 18,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_PLUS = 19,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 20,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULT = 21,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIV = 22,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_EXP = 23,                 /* TOKEN_EXP  */
  YYSYMBOL_TOKEN_MOD = 24,                 /* TOKEN_MOD  */
  YYSYMBOL_TOKEN_LT = 25,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_GT = 26,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_LEQ = 27,                 /* TOKEN_LEQ  */
  YYSYMBOL_TOKEN_GEQ = 28,                 /* TOKEN_GEQ  */
  YYSYMBOL_TOKEN_EQ = 29,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 30,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_EQUAL = 31,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_COLON = 32,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_QUALIFY = 33,             /* TOKEN_QUALIFY  */
  YYSYMBOL_TOKEN_COMMA = 34,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SEMICOLON = 35,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_PIPE = 36,                /* TOKEN_PIPE  */
  YYSYMBOL_TOKEN_AMP = 37,                 /* TOKEN_AMP  */
  YYSYMBOL_TOKEN_LPAREN = 38,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 39,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LBRACE = 40,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 41,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_NEWLINE = 42,             /* TOKEN_NEWLINE  */
  YYSYMBOL_TOKEN_WS = 43,                  /* TOKEN_WS  */
  YYSYMBOL_TOKEN_EOF = 44,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_UNKNOWN = 45,             /* TOKEN_UNKNOWN  */
  YYSYMBOL_IDENTIFIER = 46,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 47,                   /* INTEGER  */
  YYSYMBOL_REAL = 48,                      /* REAL  */
  YYSYMBOL_STRING = 49,                    /* STRING  */
  YYSYMBOL_BOOL = 50,                      /* BOOL  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_source = 52,                    /* source  */
  YYSYMBOL_module_decl = 53,               /* module_decl  */
  YYSYMBOL_top_level_decl_list = 54,       /* top_level_decl_list  */
  YYSYMBOL_top_level_decl = 55,            /* top_level_decl  */
  YYSYMBOL_import_decl = 56,               /* import_decl  */
  YYSYMBOL_term_decl = 57,                 /* term_decl  */
  YYSYMBOL_assignment = 58,                /* assignment  */
  YYSYMBOL_val_or_var = 59,                /* val_or_var  */
  YYSYMBOL_optional_assignment = 60,       /* optional_assignment  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_atomic_value = 62,              /* atomic_value  */
  YYSYMBOL_arithmetic_expr = 63,           /* arithmetic_expr  */
  YYSYMBOL_logical_expr = 64,              /* logical_expr  */
  YYSYMBOL_compound_expr = 65,             /* compound_expr  */
  YYSYMBOL_if_then_else_expr = 66,         /* if_then_else_expr  */
  YYSYMBOL_for_loop_expr = 67,             /* for_loop_expr  */
  YYSYMBOL_range = 68,                     /* range  */
  YYSYMBOL_optional_step = 69,             /* optional_step  */
  YYSYMBOL_while_loop_expr = 70,           /* while_loop_expr  */
  YYSYMBOL_until_loop_expr = 71,           /* until_loop_expr  */
  YYSYMBOL_do_block_expr = 72,             /* do_block_expr  */
  YYSYMBOL_switch_expr = 73,               /* switch_expr  */
  YYSYMBOL_case_expr_list = 74,            /* case_expr_list  */
  YYSYMBOL_case_expr = 75,                 /* case_expr  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_block_expression_list = 77,     /* block_expression_list  */
  YYSYMBOL_block_expression = 78,          /* block_expression  */
  YYSYMBOL_fun_decl = 79,                  /* fun_decl  */
  YYSYMBOL_param_list = 80,                /* param_list  */
  YYSYMBOL_param = 81,                     /* param  */
  YYSYMBOL_funcall = 82,                   /* funcall  */
  YYSYMBOL_arg_list = 83,                  /* arg_list  */
  YYSYMBOL_type_decl = 84,                 /* type_decl  */
  YYSYMBOL_constructor_list = 85,          /* constructor_list  */
  YYSYMBOL_constructor_field = 86          /* constructor_field  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 13 "comp.y"

  int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner,ast_source_t** source_module);
  void yyerror(YYLTYPE* yyllocp, yyscan_t unused, ast_source_t **source_module, const char* msg);

#line 201 "src/comp.tab.c"

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   148,   153,   154,   159,   161,   163,   165,
     167,   172,   177,   181,   186,   187,   191,   192,   196,   197,
     198,   199,   200,   201,   205,   206,   207,   208,   209,   213,
     214,   215,   216,   217,   218,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   234,   235,   236,   237,   238,   239,
     243,   248,   253,   258,   259,   263,   268,   273,   278,   283,
     284,   289,   291,   296,   300,   301,   305,   306,   307,   311,
     315,   316,   317,   321,   325,   329,   330,   331,   335,   339,
     340,   344
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_MODULE",
  "TOKEN_IMPORT", "TOKEN_FUN", "TOKEN_VAL", "TOKEN_VAR", "TOKEN_TYPE",
  "TOKEN_DO", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_WHILE",
  "TOKEN_UNTIL", "TOKEN_SWITCH", "TOKEN_NOT", "TOKEN_AND", "TOKEN_OR",
  "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_EXP",
  "TOKEN_MOD", "TOKEN_LT", "TOKEN_GT", "TOKEN_LEQ", "TOKEN_GEQ",
  "TOKEN_EQ", "TOKEN_NEQ", "TOKEN_EQUAL", "TOKEN_COLON", "TOKEN_QUALIFY",
  "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_PIPE", "TOKEN_AMP",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_NEWLINE", "TOKEN_WS", "TOKEN_EOF", "TOKEN_UNKNOWN", "IDENTIFIER",
  "INTEGER", "REAL", "STRING", "BOOL", "$accept", "source", "module_decl",
  "top_level_decl_list", "top_level_decl", "import_decl", "term_decl",
  "assignment", "val_or_var", "optional_assignment", "expr",
  "atomic_value", "arithmetic_expr", "logical_expr", "compound_expr",
  "if_then_else_expr", "for_loop_expr", "range", "optional_step",
  "while_loop_expr", "until_loop_expr", "do_block_expr", "switch_expr",
  "case_expr_list", "case_expr", "block", "block_expression_list",
  "block_expression", "fun_decl", "param_list", "param", "funcall",
  "arg_list", "type_decl", "constructor_list", "constructor_field", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   -45,    59,   -57,    18,   -57,     9,   -57,    15,    19,
     -57,   -57,    20,    39,   -57,   -57,   -57,   -57,    35,   -57,
     -57,    29,    44,    52,   157,    62,   -57,     5,    49,    56,
     157,    51,   157,   157,   157,   157,   157,    60,   -57,   -57,
     -57,   -57,     1,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    54,    68,    -2,   -57,   -57,    22,
     -57,   -57,   -57,   158,    73,   158,   158,   191,    85,   215,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   -57,     4,    83,     5,    70,
     -57,    49,    97,   107,    81,   -57,   -57,   -57,   -57,   328,
      -1,    61,    61,    50,    50,    50,    50,    85,    50,    85,
      85,    85,    85,    85,    85,   157,   -57,   -57,    74,   -57,
      56,   -57,   -57,    25,   -57,   -57,   238,   -57,    56,   157,
      56,   115,   157,   -57,   257,   -57,   -57,   -57,   -57,   276,
     -57,    89,   -57,   312,   -57,   328,   -57,   157,    56,    56,
     294,   -57,   -57,   157,    93,   328,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     3,     0,     0,
      14,    15,     0,     0,     5,     6,     8,    10,     0,     9,
       7,     0,     0,     0,     0,     0,    11,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      28,    27,     0,    18,    19,    20,    22,    44,    45,    46,
      47,    48,    49,    21,     0,     0,     0,    71,    81,     0,
      79,    64,    57,     0,     0,     0,     0,     0,    35,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      78,     0,     0,     0,     0,    55,    56,    59,    23,    76,
       0,    36,    37,    29,    30,    31,    32,    34,    33,    38,
      39,    40,    41,    42,    43,     0,    17,    12,     0,    72,
       0,    80,    63,    24,    67,    68,     0,    65,     0,     0,
       0,     0,     0,    74,     0,    73,    69,    66,    50,     0,
      51,     0,    58,     0,    60,    77,    16,     0,     0,     0,
      53,    61,    62,     0,     0,    54,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,   -57,   -57,    30,    41,   -19,   -57,
     -30,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -56,   -57,   -57,   -57,   -57,
      46,   -57,   -57,   -57,   -57,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,    14,    15,    16,    17,    18,   117,
      42,    43,    44,    45,    46,    47,    48,   130,   154,    49,
      50,    51,    52,   131,   144,    62,    92,   127,    19,    56,
      57,    53,   100,    20,    59,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,     4,    65,    66,    67,    68,    69,    93,    55,    95,
      96,    10,    11,     8,     9,    10,    11,    12,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    88,   132,     1,   115,    85,    89,   133,   116,
      99,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    13,    24,    90,    91,     5,
       7,    21,   126,    70,   136,    22,    23,    71,    72,    55,
      24,    26,   138,    77,   140,    79,    80,    81,    82,    83,
      84,    25,    27,    28,    77,   134,    79,    80,    81,    82,
      83,    84,   151,   152,    54,    58,    61,    64,    70,   139,
      86,   143,   145,    10,    11,    94,    29,    30,    77,    31,
      32,    33,    34,    35,    87,   118,   120,   150,   128,   129,
     135,   148,   124,   155,    29,    30,   141,    31,    32,    33,
      34,    35,   156,   125,   119,    36,   121,     0,   122,     0,
       0,     0,     0,   123,    38,    39,    40,    41,     0,     0,
       0,     0,     0,    36,     0,     0,   142,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    29,    30,     0,    31,
      32,    33,    34,    35,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,    36,     0,     0,    61,     0,
       0,     0,     0,    37,    38,    39,    40,    41,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,   137,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,   146,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
     147,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,   153,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,   149,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      30,    46,    32,    33,    34,    35,    36,    63,    27,    65,
      66,     6,     7,     4,     5,     6,     7,     8,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    34,    34,     3,    31,    35,    39,    39,    35,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    46,    31,    35,    36,     0,
      42,    46,    92,    38,   120,    46,    46,    17,    18,    88,
      31,    42,   128,    23,   130,    25,    26,    27,    28,    29,
      30,    46,    38,    31,    23,   115,    25,    26,    27,    28,
      29,    30,   148,   149,    32,    46,    40,    46,    38,   129,
      46,   131,   132,     6,     7,    32,     9,    10,    23,    12,
      13,    14,    15,    16,    46,    32,    46,   147,    11,    38,
      46,    32,    92,   153,     9,    10,    11,    12,    13,    14,
      15,    16,    39,    92,    88,    38,    91,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,     9,    10,    -1,    12,
      13,    14,    15,    16,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      34,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    34,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    53,    46,     0,    54,    42,     4,     5,
       6,     7,     8,    46,    55,    56,    57,    58,    59,    79,
      84,    46,    46,    46,    31,    46,    42,    38,    31,     9,
      10,    12,    13,    14,    15,    16,    38,    46,    47,    48,
      49,    50,    61,    62,    63,    64,    65,    66,    67,    70,
      71,    72,    73,    82,    32,    59,    80,    81,    46,    85,
      86,    40,    76,    61,    46,    61,    61,    61,    61,    61,
      38,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    35,    46,    46,    34,    39,
      35,    36,    77,    76,    32,    76,    76,    40,    39,    61,
      83,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    31,    35,    60,    32,    81,
      46,    86,    41,    46,    57,    58,    61,    78,    11,    38,
      68,    74,    34,    39,    61,    46,    76,    35,    76,    61,
      76,    11,    41,    61,    75,    61,    35,    34,    32,    32,
      61,    76,    76,    34,    69,    61,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    55,    55,    55,
      55,    56,    57,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    67,    68,    69,    69,    70,    71,    72,    73,    74,
      74,    75,    75,    76,    77,    77,    78,    78,    78,    79,
      80,    80,    80,    81,    82,    83,    83,    83,    84,    85,
      85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     2,     1,     1,     1,     1,
       1,     3,     5,     4,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     6,     0,     2,     3,     3,     2,     5,     0,
       2,     3,     3,     3,     0,     2,     2,     1,     1,     7,
       0,     1,     3,     4,     4,     0,     1,     3,     5,     1,
       3,     1
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
        yyerror (&yylloc, scanner, source_module, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, source_module); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (source_module);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, source_module);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner, ast_source_t** source_module)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, source_module);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, source_module); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (source_module);
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
yyparse (yyscan_t scanner, ast_source_t** source_module)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner, source_module);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* source: module_decl top_level_decl_list  */
#line 144 "comp.y"
    { (yyval.source)=create_ast_source_t((yyvsp[-1].module_decl), (yyvsp[0].top_level_decl_list)); *source_module=(yyval.source);}
#line 1436 "src/comp.tab.c"
    break;

  case 3: /* module_decl: TOKEN_MODULE IDENTIFIER TOKEN_NEWLINE  */
#line 149 "comp.y"
    {(yyval.module_decl)=create_ast_module_decl_t((yyvsp[-1].IDENTIFIER));}
#line 1442 "src/comp.tab.c"
    break;

  case 4: /* top_level_decl_list: %empty  */
#line 153 "comp.y"
                                            {(yyval.top_level_decl_list)=NULL;}
#line 1448 "src/comp.tab.c"
    break;

  case 5: /* top_level_decl_list: top_level_decl_list top_level_decl  */
#line 155 "comp.y"
    {cvector_push_back((yyval.top_level_decl_list), (yyvsp[0].top_level_decl));}
#line 1454 "src/comp.tab.c"
    break;

  case 6: /* top_level_decl: import_decl  */
#line 160 "comp.y"
    {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_IMPORT, (yyvsp[0].import_decl));}
#line 1460 "src/comp.tab.c"
    break;

  case 7: /* top_level_decl: type_decl  */
#line 162 "comp.y"
    {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_TYPE, (yyvsp[0].type_decl));}
#line 1466 "src/comp.tab.c"
    break;

  case 8: /* top_level_decl: term_decl  */
#line 164 "comp.y"
    {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_TERM, (yyvsp[0].term_decl));}
#line 1472 "src/comp.tab.c"
    break;

  case 9: /* top_level_decl: fun_decl  */
#line 166 "comp.y"
    {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_FUN, (yyvsp[0].fun_decl));}
#line 1478 "src/comp.tab.c"
    break;

  case 10: /* top_level_decl: assignment  */
#line 168 "comp.y"
    {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_ASSIGN, (yyvsp[0].assignment));}
#line 1484 "src/comp.tab.c"
    break;

  case 11: /* import_decl: TOKEN_IMPORT IDENTIFIER TOKEN_NEWLINE  */
#line 173 "comp.y"
    {(yyval.import_decl)=create_ast_import_decl_t((yyvsp[-1].IDENTIFIER));}
#line 1490 "src/comp.tab.c"
    break;

  case 12: /* term_decl: val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER optional_assignment  */
#line 177 "comp.y"
                                                                       {(yyval.term_decl)=create_ast_term_decl_t((yyvsp[-4].val_or_var), (yyvsp[-3].IDENTIFIER), (yyvsp[-1].IDENTIFIER), (yyvsp[0].optional_assignment));}
#line 1496 "src/comp.tab.c"
    break;

  case 13: /* assignment: IDENTIFIER TOKEN_EQUAL expr TOKEN_SEMICOLON  */
#line 182 "comp.y"
    {(yyval.assignment)=create_ast_assignment_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].expr));}
#line 1502 "src/comp.tab.c"
    break;

  case 14: /* val_or_var: TOKEN_VAL  */
#line 186 "comp.y"
                {(yyval.val_or_var)=TERM_VAL;}
#line 1508 "src/comp.tab.c"
    break;

  case 15: /* val_or_var: TOKEN_VAR  */
#line 187 "comp.y"
                {(yyval.val_or_var)=TERM_VAR;}
#line 1514 "src/comp.tab.c"
    break;

  case 16: /* optional_assignment: TOKEN_EQUAL expr TOKEN_SEMICOLON  */
#line 191 "comp.y"
                                             {(yyval.optional_assignment)=(yyvsp[-1].expr);}
#line 1520 "src/comp.tab.c"
    break;

  case 17: /* optional_assignment: TOKEN_SEMICOLON  */
#line 192 "comp.y"
                                             {(yyval.optional_assignment)=NULL;}
#line 1526 "src/comp.tab.c"
    break;

  case 18: /* expr: atomic_value  */
#line 196 "comp.y"
                        { (yyval.expr)=(yyvsp[0].atomic_value); }
#line 1532 "src/comp.tab.c"
    break;

  case 19: /* expr: arithmetic_expr  */
#line 197 "comp.y"
                        { (yyval.expr)=(yyvsp[0].arithmetic_expr); }
#line 1538 "src/comp.tab.c"
    break;

  case 20: /* expr: logical_expr  */
#line 198 "comp.y"
                        { (yyval.expr)=(yyvsp[0].logical_expr); }
#line 1544 "src/comp.tab.c"
    break;

  case 21: /* expr: funcall  */
#line 199 "comp.y"
                        { (yyval.expr)=create_ast_expr_t(EXPR_FUNCALL,(yyvsp[0].funcall)); }
#line 1550 "src/comp.tab.c"
    break;

  case 22: /* expr: compound_expr  */
#line 200 "comp.y"
                        { (yyval.expr)=(yyvsp[0].compound_expr); }
#line 1556 "src/comp.tab.c"
    break;

  case 23: /* expr: TOKEN_LPAREN expr TOKEN_RPAREN  */
#line 201 "comp.y"
                                           { (yyval.expr)=(yyvsp[-1].expr); }
#line 1562 "src/comp.tab.c"
    break;

  case 24: /* atomic_value: IDENTIFIER  */
#line 205 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_IDENTIFIER, (yyvsp[0].IDENTIFIER)); }
#line 1568 "src/comp.tab.c"
    break;

  case 25: /* atomic_value: INTEGER  */
#line 206 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_INTEGER, (yyvsp[0].INTEGER)); }
#line 1574 "src/comp.tab.c"
    break;

  case 26: /* atomic_value: REAL  */
#line 207 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_REAL, (yyvsp[0].REAL)); }
#line 1580 "src/comp.tab.c"
    break;

  case 27: /* atomic_value: BOOL  */
#line 208 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_BOOL, (yyvsp[0].BOOL)); }
#line 1586 "src/comp.tab.c"
    break;

  case 28: /* atomic_value: STRING  */
#line 209 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_STRING, (yyvsp[0].STRING)); }
#line 1592 "src/comp.tab.c"
    break;

  case 29: /* arithmetic_expr: expr TOKEN_PLUS expr  */
#line 213 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_ADD,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_ADD)); }
#line 1598 "src/comp.tab.c"
    break;

  case 30: /* arithmetic_expr: expr TOKEN_MINUS expr  */
#line 214 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_SUB,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_SUB)); }
#line 1604 "src/comp.tab.c"
    break;

  case 31: /* arithmetic_expr: expr TOKEN_MULT expr  */
#line 215 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_MUL,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_MUL)); }
#line 1610 "src/comp.tab.c"
    break;

  case 32: /* arithmetic_expr: expr TOKEN_DIV expr  */
#line 216 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_DIV,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_DIV)); }
#line 1616 "src/comp.tab.c"
    break;

  case 33: /* arithmetic_expr: expr TOKEN_MOD expr  */
#line 217 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_MOD,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_MOD)); }
#line 1622 "src/comp.tab.c"
    break;

  case 34: /* arithmetic_expr: expr TOKEN_EXP expr  */
#line 218 "comp.y"
                              { (yyval.arithmetic_expr)=create_ast_expr_t(EXPR_EXP,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_EXP)); }
#line 1628 "src/comp.tab.c"
    break;

  case 35: /* logical_expr: TOKEN_NOT expr  */
#line 222 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_NOT,(yyvsp[0].expr)); }
#line 1634 "src/comp.tab.c"
    break;

  case 36: /* logical_expr: expr TOKEN_AND expr  */
#line 223 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_AND,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_AND)); }
#line 1640 "src/comp.tab.c"
    break;

  case 37: /* logical_expr: expr TOKEN_OR expr  */
#line 224 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_OR,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_OR)); }
#line 1646 "src/comp.tab.c"
    break;

  case 38: /* logical_expr: expr TOKEN_LT expr  */
#line 225 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_LT,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_LT)); }
#line 1652 "src/comp.tab.c"
    break;

  case 39: /* logical_expr: expr TOKEN_GT expr  */
#line 226 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_GT,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_GT)); }
#line 1658 "src/comp.tab.c"
    break;

  case 40: /* logical_expr: expr TOKEN_LEQ expr  */
#line 227 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_LEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_LEQ)); }
#line 1664 "src/comp.tab.c"
    break;

  case 41: /* logical_expr: expr TOKEN_GEQ expr  */
#line 228 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_GEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_GEQ)); }
#line 1670 "src/comp.tab.c"
    break;

  case 42: /* logical_expr: expr TOKEN_EQ expr  */
#line 229 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_EQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_EQ)); }
#line 1676 "src/comp.tab.c"
    break;

  case 43: /* logical_expr: expr TOKEN_NEQ expr  */
#line 230 "comp.y"
                                { (yyval.logical_expr)=create_ast_expr_t(EXPR_NEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_NEQ)); }
#line 1682 "src/comp.tab.c"
    break;

  case 44: /* compound_expr: if_then_else_expr  */
#line 234 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_IF, (yyvsp[0].if_then_else_expr)); }
#line 1688 "src/comp.tab.c"
    break;

  case 45: /* compound_expr: for_loop_expr  */
#line 235 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_FOR, (yyvsp[0].for_loop_expr)); }
#line 1694 "src/comp.tab.c"
    break;

  case 46: /* compound_expr: while_loop_expr  */
#line 236 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_WHILE, (yyvsp[0].while_loop_expr)); }
#line 1700 "src/comp.tab.c"
    break;

  case 47: /* compound_expr: until_loop_expr  */
#line 237 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_UNTIL, (yyvsp[0].until_loop_expr)); }
#line 1706 "src/comp.tab.c"
    break;

  case 48: /* compound_expr: do_block_expr  */
#line 238 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_DO, (yyvsp[0].do_block_expr)); }
#line 1712 "src/comp.tab.c"
    break;

  case 49: /* compound_expr: switch_expr  */
#line 239 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_SWITCH, (yyvsp[0].switch_expr)); }
#line 1718 "src/comp.tab.c"
    break;

  case 50: /* if_then_else_expr: TOKEN_IF expr block TOKEN_ELSE block  */
#line 244 "comp.y"
    { (yyval.if_then_else_expr)=create_ast_if_t((yyvsp[-3].expr), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1724 "src/comp.tab.c"
    break;

  case 51: /* for_loop_expr: TOKEN_FOR IDENTIFIER TOKEN_COLON range block  */
#line 249 "comp.y"
    { (yyval.for_loop_expr)=create_ast_for_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].range), (yyvsp[0].block)); }
#line 1730 "src/comp.tab.c"
    break;

  case 52: /* range: TOKEN_LPAREN expr TOKEN_COMMA expr optional_step TOKEN_RPAREN  */
#line 254 "comp.y"
    { (yyval.range)=create_ast_range_t((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[-1].optional_step)); }
#line 1736 "src/comp.tab.c"
    break;

  case 53: /* optional_step: %empty  */
#line 258 "comp.y"
                    { (yyval.optional_step)=NULL;}
#line 1742 "src/comp.tab.c"
    break;

  case 54: /* optional_step: TOKEN_COMMA expr  */
#line 259 "comp.y"
                        { (yyval.optional_step)=(yyvsp[0].expr); }
#line 1748 "src/comp.tab.c"
    break;

  case 55: /* while_loop_expr: TOKEN_WHILE expr block  */
#line 264 "comp.y"
    { (yyval.while_loop_expr)=create_ast_while_t((yyvsp[-1].expr), (yyvsp[0].block));}
#line 1754 "src/comp.tab.c"
    break;

  case 56: /* until_loop_expr: TOKEN_UNTIL expr block  */
#line 269 "comp.y"
    { (yyval.until_loop_expr)=create_ast_while_t(create_ast_expr_t(EXPR_NOT,(yyvsp[-1].expr)), (yyvsp[0].block)); }
#line 1760 "src/comp.tab.c"
    break;

  case 57: /* do_block_expr: TOKEN_DO block  */
#line 274 "comp.y"
    { (yyval.do_block_expr)=create_ast_do_t((yyvsp[0].block)); }
#line 1766 "src/comp.tab.c"
    break;

  case 58: /* switch_expr: TOKEN_SWITCH expr TOKEN_LBRACE case_expr_list TOKEN_RBRACE  */
#line 279 "comp.y"
    { (yyval.switch_expr)=create_ast_switch_t((yyvsp[-3].expr), (yyvsp[-1].case_expr_list)); }
#line 1772 "src/comp.tab.c"
    break;

  case 59: /* case_expr_list: %empty  */
#line 283 "comp.y"
                                    { (yyval.case_expr_list)=NULL; }
#line 1778 "src/comp.tab.c"
    break;

  case 60: /* case_expr_list: case_expr_list case_expr  */
#line 285 "comp.y"
    { cvector_push_back((yyval.case_expr_list), (yyvsp[0].case_expr)); }
#line 1784 "src/comp.tab.c"
    break;

  case 61: /* case_expr: TOKEN_ELSE TOKEN_COLON block  */
#line 290 "comp.y"
    { (yyval.case_expr)=create_ast_case_t(NULL, (yyvsp[0].block)); }
#line 1790 "src/comp.tab.c"
    break;

  case 62: /* case_expr: expr TOKEN_COLON block  */
#line 292 "comp.y"
    { (yyval.case_expr)=create_ast_case_t((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1796 "src/comp.tab.c"
    break;

  case 63: /* block: TOKEN_LBRACE block_expression_list TOKEN_RBRACE  */
#line 296 "comp.y"
                                                     { (yyval.block)=create_ast_block_t((yyvsp[-1].block_expression_list)); }
#line 1802 "src/comp.tab.c"
    break;

  case 64: /* block_expression_list: %empty  */
#line 300 "comp.y"
                                                { (yyval.block_expression_list)=NULL; }
#line 1808 "src/comp.tab.c"
    break;

  case 65: /* block_expression_list: block_expression_list block_expression  */
#line 301 "comp.y"
                                                { cvector_push_back((yyval.block_expression_list), (yyvsp[0].block_expression)); }
#line 1814 "src/comp.tab.c"
    break;

  case 66: /* block_expression: expr TOKEN_SEMICOLON  */
#line 305 "comp.y"
                                            { (yyval.block_expression)=create_ast_block_expr_t(EXPR, (yyvsp[-1].expr)); }
#line 1820 "src/comp.tab.c"
    break;

  case 67: /* block_expression: term_decl  */
#line 306 "comp.y"
                                            { (yyval.block_expression)=create_ast_block_expr_t(DECL, (yyvsp[0].term_decl)); }
#line 1826 "src/comp.tab.c"
    break;

  case 68: /* block_expression: assignment  */
#line 307 "comp.y"
                                            { (yyval.block_expression)=create_ast_block_expr_t(ASSIGN, (yyvsp[0].assignment)); }
#line 1832 "src/comp.tab.c"
    break;

  case 69: /* fun_decl: TOKEN_FUN IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN IDENTIFIER block  */
#line 311 "comp.y"
                                                                                 { (yyval.fun_decl)=create_ast_fundecl_t((yyvsp[-5].IDENTIFIER), (yyvsp[-3].param_list), (yyvsp[-1].IDENTIFIER), (yyvsp[0].block)); }
#line 1838 "src/comp.tab.c"
    break;

  case 70: /* param_list: %empty  */
#line 315 "comp.y"
                                        {(yyval.param_list)=NULL;}
#line 1844 "src/comp.tab.c"
    break;

  case 71: /* param_list: param  */
#line 316 "comp.y"
                                        {(yyval.param_list)=NULL; cvector_push_back((yyval.param_list), (yyvsp[0].param));}
#line 1850 "src/comp.tab.c"
    break;

  case 72: /* param_list: param_list TOKEN_COMMA param  */
#line 317 "comp.y"
                                        {cvector_push_back((yyval.param_list), (yyvsp[0].param));}
#line 1856 "src/comp.tab.c"
    break;

  case 73: /* param: val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER  */
#line 321 "comp.y"
                                                    { (yyval.param)=create_ast_fun_param_t((yyvsp[-3].val_or_var), (yyvsp[-2].IDENTIFIER), (yyvsp[0].IDENTIFIER)); }
#line 1862 "src/comp.tab.c"
    break;

  case 74: /* funcall: IDENTIFIER TOKEN_LPAREN arg_list TOKEN_RPAREN  */
#line 325 "comp.y"
                                                    { (yyval.funcall)=create_ast_funcall_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].arg_list)); }
#line 1868 "src/comp.tab.c"
    break;

  case 75: /* arg_list: %empty  */
#line 329 "comp.y"
                        {(yyval.arg_list)=NULL;}
#line 1874 "src/comp.tab.c"
    break;

  case 76: /* arg_list: expr  */
#line 330 "comp.y"
                        {(yyval.arg_list)=NULL; cvector_push_back((yyval.arg_list), (yyvsp[0].expr));}
#line 1880 "src/comp.tab.c"
    break;

  case 77: /* arg_list: arg_list TOKEN_COMMA expr  */
#line 331 "comp.y"
                             {cvector_push_back((yyval.arg_list),(yyvsp[0].expr));}
#line 1886 "src/comp.tab.c"
    break;

  case 78: /* type_decl: TOKEN_TYPE IDENTIFIER TOKEN_EQUAL constructor_list TOKEN_SEMICOLON  */
#line 335 "comp.y"
                                                                         { (yyval.type_decl)=create_ast_type_decl_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].constructor_list)); }
#line 1892 "src/comp.tab.c"
    break;

  case 79: /* constructor_list: constructor_field  */
#line 339 "comp.y"
                                                        { (yyval.constructor_list)=NULL; cvector_push_back((yyval.constructor_list), (yyvsp[0].constructor_field)); }
#line 1898 "src/comp.tab.c"
    break;

  case 80: /* constructor_list: constructor_list TOKEN_PIPE constructor_field  */
#line 340 "comp.y"
                                                        { cvector_push_back((yyval.constructor_list), (yyvsp[0].constructor_field)); }
#line 1904 "src/comp.tab.c"
    break;

  case 81: /* constructor_field: IDENTIFIER  */
#line 344 "comp.y"
                                                        { (yyval.constructor_field)=create_ast_constructors_t((yyvsp[0].IDENTIFIER), NULL); }
#line 1910 "src/comp.tab.c"
    break;


#line 1914 "src/comp.tab.c"

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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, scanner, source_module, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, scanner, source_module);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, source_module);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, scanner, source_module, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, source_module);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, source_module);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 348 "comp.y"


void yyerror(YYLTYPE* yyllocp, yyscan_t unused,ast_source_t **source_module, const char* msg) {
  
  char token_name[255];
  
  fprintf(stderr, "[%d:%d]: %s\n",
                  yyllocp->first_line, yyllocp->first_column, msg);
}
