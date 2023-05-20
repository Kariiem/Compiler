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

/* "%code top" blocks.  */
#line 6 "comp.y"

  #include <stdio.h>

#line 71 "comp.tab.c"




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
#ifndef YY_YY_COMP_TAB_H_INCLUDED
# define YY_YY_COMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "comp.y"

  typedef void* yyscan_t;
  #include "src/ast/ast.h"

#line 122 "comp.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_MODULE = 258,
    TOKEN_IMPORT = 259,
    TOKEN_FUN = 260,
    TOKEN_VAL = 261,
    TOKEN_VAR = 262,
    TOKEN_TYPE = 263,
    TOKEN_DO = 264,
    TOKEN_IF = 265,
    TOKEN_ELSE = 266,
    TOKEN_FOR = 267,
    TOKEN_WHILE = 268,
    TOKEN_UNTIL = 269,
    TOKEN_SWITCH = 270,
    TOKEN_NOT = 271,
    TOKEN_AND = 272,
    TOKEN_OR = 273,
    TOKEN_PLUS = 274,
    TOKEN_MINUS = 275,
    TOKEN_MULT = 276,
    TOKEN_DIV = 277,
    TOKEN_EXP = 278,
    TOKEN_MOD = 279,
    TOKEN_LT = 280,
    TOKEN_GT = 281,
    TOKEN_LEQ = 282,
    TOKEN_GEQ = 283,
    TOKEN_EQ = 284,
    TOKEN_NEQ = 285,
    TOKEN_EQUAL = 286,
    TOKEN_COLON = 287,
    TOKEN_QUALIFY = 288,
    TOKEN_COMMA = 289,
    TOKEN_SEMICOLON = 290,
    TOKEN_PIPE = 291,
    TOKEN_AMP = 292,
    TOKEN_LPAREN = 293,
    TOKEN_RPAREN = 294,
    TOKEN_LBRACE = 295,
    TOKEN_RBRACE = 296,
    TOKEN_NEWLINE = 297,
    TOKEN_WS = 298,
    TOKEN_EOF = 299,
    TOKEN_UNKNOWN = 300,
    IDENTIFIER = 301,
    INTEGER = 302,
    REAL = 303,
    STRING = 304,
    BOOL = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  /* block_expression  */
  ast_block_expr_t* block_expression;
  /* block  */
  ast_block_t* block;
  /* case_expr  */
  ast_case_t* case_expr;
  /* constructor_field  */
  ast_constructors_t* constructor_field;
  /* do_block_expr  */
  ast_do_t* do_block_expr;
  /* optional_step  */
  ast_expr_t optional_step;
  /* optional_assignment  */
  ast_expr_t* optional_assignment;
  /* expr  */
  ast_expr_t* expr;
  /* atomic_value  */
  ast_expr_t* atomic_value;
  /* arithmetic_expr  */
  ast_expr_t* arithmetic_expr;
  /* logical_expr  */
  ast_expr_t* logical_expr;
  /* compound_expr  */
  ast_expr_t* compound_expr;
  /* for_loop_expr  */
  ast_for_t* for_loop_expr;
  /* param  */
  ast_fun_param_t* param;
  /* funcall  */
  ast_funcall_t* funcall;
  /* fun_decl  */
  ast_fundecl_t* fun_decl;
  /* if_then_else_expr  */
  ast_if_t* if_then_else_expr;
  /* import_decl  */
  ast_import_decl_t* import_decl;
  /* module_decl  */
  ast_module_decl_t* module_decl;
  /* range  */
  ast_range_t* range;
  /* record_field  */
  ast_record_field_t* record_field;
  /* switch_expr  */
  ast_switch_t* switch_expr;
  /* term_decl  */
  ast_term_decl_t* term_decl;
  /* top_level_decl  */
  ast_top_level_decl_t* top_level_decl;
  /* type_decl  */
  ast_type_decl_t* type_decl;
  /* while_loop_expr  */
  ast_while_t* while_loop_expr;
  /* until_loop_expr  */
  ast_while_t* until_loop_expr;
  /* IDENTIFIER  */
  char const* IDENTIFIER;
  /* INTEGER  */
  char const* INTEGER;
  /* REAL  */
  char const* REAL;
  /* STRING  */
  char const* STRING;
  /* BOOL  */
  int64_t BOOL;
  /* val_or_var  */
  int64_t* val_or_var;
  /* block_expression_list  */
  vtype(ast_block_expr_t*) block_expression_list;
  /* case_expr_list  */
  vtype(ast_case_t*) case_expr_list;
  /* constructor_list  */
  vtype(ast_constructors_t*) constructor_list;
  /* arg_list  */
  vtype(ast_expr_t*) arg_list;
  /* param_list  */
  vtype(ast_fun_param_t*) param_list;
  /* record  */
  vtype(ast_record_field_t*) record;
  /* record_field_list  */
  vtype(ast_record_field_t*) record_field_list;
  /* top_level_decl_list  */
  vtype(ast_top_level_decl_t*) top_level_decl_list;
#line 267 "comp.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner, ast_source_t** source_module);

#endif /* !YY_YY_COMP_TAB_H_INCLUDED  */


/* Unqualified %code blocks.  */
#line 13 "comp.y"

  int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner,ast_source_t** source_module);
  void yyerror(YYLTYPE* yyllocp, yyscan_t unused, ast_source_t **source_module, const char* msg);

#line 302 "comp.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   144,   148,   149,   153,   154,   155,   156,
     160,   164,   165,   169,   170,   174,   175,   179,   180,   181,
     182,   183,   184,   188,   189,   190,   191,   192,   196,   197,
     198,   199,   200,   201,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   217,   218,   219,   220,   221,   222,   226,
     230,   234,   238,   239,   243,   247,   251,   255,   259,   260,
     264,   265,   269,   273,   274,   278,   279,   283,   287,   288,
     289,   293,   297,   301,   302,   303,   307,   311,   312,   316,
     320,   321,   325,   326,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_MODULE", "TOKEN_IMPORT",
  "TOKEN_FUN", "TOKEN_VAL", "TOKEN_VAR", "TOKEN_TYPE", "TOKEN_DO",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_WHILE", "TOKEN_UNTIL",
  "TOKEN_SWITCH", "TOKEN_NOT", "TOKEN_AND", "TOKEN_OR", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_EXP", "TOKEN_MOD",
  "TOKEN_LT", "TOKEN_GT", "TOKEN_LEQ", "TOKEN_GEQ", "TOKEN_EQ",
  "TOKEN_NEQ", "TOKEN_EQUAL", "TOKEN_COLON", "TOKEN_QUALIFY",
  "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_PIPE", "TOKEN_AMP",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_NEWLINE", "TOKEN_WS", "TOKEN_EOF", "TOKEN_UNKNOWN", "IDENTIFIER",
  "INTEGER", "REAL", "STRING", "BOOL", "$accept", "module_decl",
  "top_level_decl_list", "top_level_decl", "import_decl", "term_decl",
  "val_or_var", "optional_assignment", "expr", "atomic_value",
  "arithmetic_expr", "logical_expr", "compound_expr", "if_then_else_expr",
  "for_loop_expr", "range", "optional_step", "while_loop_expr",
  "until_loop_expr", "do_block_expr", "switch_expr", "case_expr_list",
  "case_expr", "block", "block_expression_list", "block_expression",
  "fun_decl", "param_list", "param", "funcall", "arg_list", "type_decl",
  "constructor_list", "constructor_field", "record", "record_field_list",
  "record_field", "source", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -35,   -56,    30,    -9,     9,   -56,   -56,    -7,    10,
     -56,   -56,    13,    36,   -56,   -56,   -56,    29,   -56,   -56,
      35,    52,    60,   115,    63,   -56,    20,    46,    56,   115,
      51,   115,   115,   115,   115,   115,    61,   -56,   -56,   -56,
     -56,   196,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,    58,    64,    54,   -56,    67,    38,   -56,
     -56,   -56,   116,    66,   116,   116,   149,    77,   173,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   -56,    26,    80,    20,    68,    69,
     -56,   -56,    46,    22,    98,    75,   -56,   -56,   -56,   -56,
     305,    55,    -5,    -5,   319,   319,   319,   319,    77,   319,
      77,    77,    77,    77,    77,    77,   115,   -56,   -56,    76,
     -56,    56,    89,   -22,   -56,   -56,   -56,    27,   -56,   215,
     -56,    56,   115,    56,    70,   115,   -56,   234,   -56,   -56,
     101,    69,   -56,   -56,   -56,   253,   -56,    91,   -56,   289,
     -56,   305,   -56,   -56,   -56,   115,    56,    56,   271,   -56,
     -56,   115,   109,   305,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     4,     0,     0,     2,     1,     3,     0,     0,
      13,    14,     0,     0,     5,     6,     8,     0,     9,     7,
       0,     0,     0,     0,     0,    10,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    27,
      26,     0,    17,    18,    19,    21,    43,    44,    45,    46,
      47,    48,    20,     0,     0,     0,    69,    80,     0,    77,
      63,    56,     0,     0,     0,     0,     0,    34,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
      79,    76,     0,     0,     0,     0,    54,    55,    58,    22,
      74,     0,    35,    36,    28,    29,    30,    31,    33,    32,
      37,    38,    39,    40,    41,    42,     0,    16,    11,     0,
      70,     0,     0,     0,    82,    78,    62,    23,    66,     0,
      64,     0,     0,     0,     0,     0,    72,     0,    71,    67,
       0,     0,    81,    65,    49,     0,    50,     0,    57,     0,
      59,    75,    15,    84,    83,     0,     0,     0,    52,    60,
      61,     0,     0,    53,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,    57,   -25,   -56,   -29,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -55,   -56,   -56,   -56,   -56,    62,   -56,
     -56,   -56,   -56,    59,   -56,   -56,    11,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    14,    15,    16,    17,   118,    41,    42,
      43,    44,    45,    46,    47,   133,   162,    48,    49,    50,
      51,   134,   150,    61,    93,   130,    18,    55,    56,    52,
     101,    19,    58,    59,    90,   123,   124,     3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    54,    64,    65,    66,    67,    68,    94,     1,    96,
      97,     4,   141,     8,     9,    10,    11,    12,    76,   142,
      78,    79,    80,    81,    82,    83,    10,    11,    10,    11,
       6,    28,    29,     7,    30,    31,    32,    33,    34,    20,
     100,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    13,    21,   116,    23,    22,
      35,   117,    54,   126,   129,    69,   139,    23,   127,    37,
      38,    39,    40,    91,    92,    24,   144,    25,   146,    28,
      29,   147,    30,    31,    32,    33,    34,   137,    87,   135,
      26,    27,    57,    88,   136,    53,    60,    63,    95,    69,
      76,   159,   160,   145,    85,   149,   151,    89,    35,   131,
      86,   148,   119,   132,   121,   122,    36,    37,    38,    39,
      40,   140,   138,   156,    28,    29,   158,    30,    31,    32,
      33,    34,   163,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   153,   164,   120,
     128,   125,   154,    35,     0,     0,    60,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    99,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
     143,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,   152,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,   155,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,   161,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,   157,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    70,    71,     0,     0,
       0,     0,    76,     0,    78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      29,    26,    31,    32,    33,    34,    35,    62,     3,    64,
      65,    46,    34,     4,     5,     6,     7,     8,    23,    41,
      25,    26,    27,    28,    29,    30,     6,     7,     6,     7,
       0,     9,    10,    42,    12,    13,    14,    15,    16,    46,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    46,    46,    31,    31,    46,
      38,    35,    87,    41,    93,    38,   121,    31,    46,    47,
      48,    49,    50,    35,    36,    46,   131,    42,   133,     9,
      10,    11,    12,    13,    14,    15,    16,   116,    34,    34,
      38,    31,    46,    39,    39,    32,    40,    46,    32,    38,
      23,   156,   157,   132,    46,   134,   135,    40,    38,    11,
      46,    41,    32,    38,    46,    46,    46,    47,    48,    49,
      50,    32,    46,    32,     9,    10,   155,    12,    13,    14,
      15,    16,   161,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    46,    39,    87,
      93,    92,   141,    38,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    34,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    34,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    88,    46,    53,     0,    42,     4,     5,
       6,     7,     8,    46,    54,    55,    56,    57,    77,    82,
      46,    46,    46,    31,    46,    42,    38,    31,     9,    10,
      12,    13,    14,    15,    16,    38,    46,    47,    48,    49,
      50,    59,    60,    61,    62,    63,    64,    65,    68,    69,
      70,    71,    80,    32,    57,    78,    79,    46,    83,    84,
      40,    74,    59,    46,    59,    59,    59,    59,    59,    38,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    35,    46,    46,    34,    39,    40,
      85,    35,    36,    75,    74,    32,    74,    74,    40,    39,
      59,    81,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    31,    35,    58,    32,
      79,    46,    46,    86,    87,    84,    41,    46,    56,    59,
      76,    11,    38,    66,    72,    34,    39,    59,    46,    74,
      32,    34,    41,    35,    74,    59,    74,    11,    41,    59,
      73,    59,    35,    46,    87,    34,    32,    32,    59,    74,
      74,    34,    67,    59,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    88,    52,    53,    53,    54,    54,    54,    54,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      65,    66,    67,    67,    68,    69,    70,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      78,    79,    80,    81,    81,    81,    82,    83,    83,    84,
      85,    85,    86,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     2,     1,     1,     1,     1,
       3,     5,     4,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     5,
       5,     6,     0,     2,     3,     3,     2,     5,     0,     2,
       3,     3,     3,     0,     2,     2,     1,     7,     0,     1,
       3,     4,     4,     0,     1,     3,     5,     1,     3,     2,
       0,     3,     1,     3,     3
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
        yyerror (&yylloc, scanner, source_module, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, source_module); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (source_module);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, scanner, source_module);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, ast_source_t** source_module)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, source_module);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, ast_source_t** source_module)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (source_module);
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
yyparse (yyscan_t scanner, ast_source_t** source_module)
{
/* The lookahead symbol.  */
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
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner, source_module);
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
  case 3:
#line 144 "comp.y"
                                            {(yyval.module_decl)=create_ast_module_decl_t((yyvsp[-1].IDENTIFIER));}
#line 1731 "comp.tab.c"
    break;

  case 4:
#line 148 "comp.y"
                                            {(yyval.top_level_decl_list)=NULL;}
#line 1737 "comp.tab.c"
    break;

  case 5:
#line 149 "comp.y"
                                            {(yyval.top_level_decl_list)=(yyvsp[-1].top_level_decl_list); cvector_push_back((yyvsp[-1].top_level_decl_list), (yyvsp[0].top_level_decl));}
#line 1743 "comp.tab.c"
    break;

  case 6:
#line 153 "comp.y"
                                {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_IMPORT, (yyvsp[0].import_decl));}
#line 1749 "comp.tab.c"
    break;

  case 7:
#line 154 "comp.y"
                                {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_TYPE, (yyvsp[0].type_decl));}
#line 1755 "comp.tab.c"
    break;

  case 8:
#line 155 "comp.y"
                                {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_TERM, (yyvsp[0].term_decl));}
#line 1761 "comp.tab.c"
    break;

  case 9:
#line 156 "comp.y"
                                {(yyval.top_level_decl)=create_ast_top_level_decl_t(DECL_FUN, (yyvsp[0].fun_decl));}
#line 1767 "comp.tab.c"
    break;

  case 10:
#line 160 "comp.y"
                                          {(yyval.import_decl)=create_ast_import_decl_t((yyvsp[-1].IDENTIFIER));}
#line 1773 "comp.tab.c"
    break;

  case 11:
#line 164 "comp.y"
                                                                       {(yyval.term_decl)=create_ast_term_decl_t((yyvsp[-4].val_or_var), (yyvsp[-3].IDENTIFIER), (yyvsp[-1].IDENTIFIER), (yyvsp[0].optional_assignment));}
#line 1779 "comp.tab.c"
    break;

  case 13:
#line 169 "comp.y"
                {(yyval.val_or_var)=TERM_VAL;}
#line 1785 "comp.tab.c"
    break;

  case 14:
#line 170 "comp.y"
                {(yyval.val_or_var)=TERM_VAR;}
#line 1791 "comp.tab.c"
    break;

  case 15:
#line 174 "comp.y"
                                             {(yyval.optional_assignment)=(yyvsp[-1].expr);}
#line 1797 "comp.tab.c"
    break;

  case 16:
#line 175 "comp.y"
                                             {(yyval.optional_assignment)=NULL;}
#line 1803 "comp.tab.c"
    break;

  case 17:
#line 179 "comp.y"
                        { (yyval.expr)=(yyvsp[0].atomic_value); }
#line 1809 "comp.tab.c"
    break;

  case 18:
#line 180 "comp.y"
                        { (yyval.expr)=(yyvsp[0].arithmetic_expr); }
#line 1815 "comp.tab.c"
    break;

  case 19:
#line 181 "comp.y"
                        { (yyval.expr)=(yyvsp[0].logical_expr); }
#line 1821 "comp.tab.c"
    break;

  case 20:
#line 182 "comp.y"
                        { (yyval.expr)=(yyvsp[0].funcall); }
#line 1827 "comp.tab.c"
    break;

  case 21:
#line 183 "comp.y"
                        { (yyval.expr)=(yyvsp[0].compound_expr); }
#line 1833 "comp.tab.c"
    break;

  case 22:
#line 184 "comp.y"
                                           { (yyval.expr)=(yyvsp[-1].expr); }
#line 1839 "comp.tab.c"
    break;

  case 23:
#line 188 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_IDENTIFIER, (yyvsp[0].IDENTIFIER)); }
#line 1845 "comp.tab.c"
    break;

  case 24:
#line 189 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_INTEGER, (yyvsp[0].INTEGER)); }
#line 1851 "comp.tab.c"
    break;

  case 25:
#line 190 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_REAL, (yyvsp[0].REAL)); }
#line 1857 "comp.tab.c"
    break;

  case 26:
#line 191 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_BOOL, (yyvsp[0].BOOL)); }
#line 1863 "comp.tab.c"
    break;

  case 27:
#line 192 "comp.y"
                    { (yyval.atomic_value)=create_ast_expr_t(EXPR_STRING, (yyvsp[0].STRING)); }
#line 1869 "comp.tab.c"
    break;

  case 28:
#line 196 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_ADD,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_ADD)); }
#line 1875 "comp.tab.c"
    break;

  case 29:
#line 197 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_SUB,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_SUB)); }
#line 1881 "comp.tab.c"
    break;

  case 30:
#line 198 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_MUL,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_MUL)); }
#line 1887 "comp.tab.c"
    break;

  case 31:
#line 199 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_DIV,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_DIV)); }
#line 1893 "comp.tab.c"
    break;

  case 32:
#line 200 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_MOD,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_MOD)); }
#line 1899 "comp.tab.c"
    break;

  case 33:
#line 201 "comp.y"
                              { (yyval.arithmetic_expr)=creat_ast_expr_t(EXPR_EXP,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_EXP)); }
#line 1905 "comp.tab.c"
    break;

  case 34:
#line 205 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_NOT,create_ast_bin_expr_t(NULL, (yyvsp[0].expr) ,EXPR_NOT)); }
#line 1911 "comp.tab.c"
    break;

  case 35:
#line 206 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_AND,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_AND)); }
#line 1917 "comp.tab.c"
    break;

  case 36:
#line 207 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_OR,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_OR)); }
#line 1923 "comp.tab.c"
    break;

  case 37:
#line 208 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_LT,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_LT)); }
#line 1929 "comp.tab.c"
    break;

  case 38:
#line 209 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_GT,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_GT)); }
#line 1935 "comp.tab.c"
    break;

  case 39:
#line 210 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_LEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_LEQ)); }
#line 1941 "comp.tab.c"
    break;

  case 40:
#line 211 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_GEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_GEQ)); }
#line 1947 "comp.tab.c"
    break;

  case 41:
#line 212 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_EQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_EQ)); }
#line 1953 "comp.tab.c"
    break;

  case 42:
#line 213 "comp.y"
                                { (yyval.logical_expr)=creat_ast_expr_t(EXPR_NEQ,create_ast_bin_expr_t((yyvsp[-2].expr), (yyvsp[0].expr), EXPR_NEQ)); }
#line 1959 "comp.tab.c"
    break;

  case 43:
#line 217 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_IF, (yyvsp[0].if_then_else_expr)); }
#line 1965 "comp.tab.c"
    break;

  case 44:
#line 218 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_FOR, (yyvsp[0].for_loop_expr)); }
#line 1971 "comp.tab.c"
    break;

  case 45:
#line 219 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_WHILE, (yyvsp[0].while_loop_expr)); }
#line 1977 "comp.tab.c"
    break;

  case 46:
#line 220 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_UNTIL, (yyvsp[0].until_loop_expr)); }
#line 1983 "comp.tab.c"
    break;

  case 47:
#line 221 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_DO, (yyvsp[0].do_block_expr)); }
#line 1989 "comp.tab.c"
    break;

  case 48:
#line 222 "comp.y"
                                { (yyval.compound_expr)=create_ast_expr_t(EXPR_SWITCH, (yyvsp[0].switch_expr)); }
#line 1995 "comp.tab.c"
    break;

  case 49:
#line 226 "comp.y"
                                            { (yyval.if_then_else_expr)=create_ast_if_t((yyvsp[-3].expr), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 2001 "comp.tab.c"
    break;

  case 50:
#line 230 "comp.y"
                                                   { (yyval.for_loop_expr)=create_ast_for_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].range), (yyvsp[0].block)); }
#line 2007 "comp.tab.c"
    break;

  case 51:
#line 234 "comp.y"
                                                                   { (yyval.range)=create_ast_range_t((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[-1].optional_step)); }
#line 2013 "comp.tab.c"
    break;

  case 52:
#line 238 "comp.y"
                    { (yyval.optional_step)=NULL;}
#line 2019 "comp.tab.c"
    break;

  case 53:
#line 239 "comp.y"
                        { (yyval.optional_step)=(yyvsp[0].expr); }
#line 2025 "comp.tab.c"
    break;

  case 54:
#line 243 "comp.y"
                                { (yyval.while_loop_expr)=create_ast_while_t((yyvsp[-1].expr), (yyvsp[0].block));}
#line 2031 "comp.tab.c"
    break;

  case 55:
#line 247 "comp.y"
                              { (yyval.until_loop_expr)=create_ast_while_t((yyvsp[-1].expr), (yyvsp[0].block)); }
#line 2037 "comp.tab.c"
    break;

  case 56:
#line 251 "comp.y"
                          { (yyval.do_block_expr)=create_ast_do_t((yyvsp[0].block)); }
#line 2043 "comp.tab.c"
    break;

  case 57:
#line 255 "comp.y"
                                                                { (yyval.switch_expr)=create_ast_switch_t((yyvsp[-3].expr), (yyvsp[-1].case_expr_list)); }
#line 2049 "comp.tab.c"
    break;

  case 58:
#line 259 "comp.y"
                                    { (yyval.case_expr_list)=NULL; }
#line 2055 "comp.tab.c"
    break;

  case 59:
#line 260 "comp.y"
                                    { (yyval.case_expr_list)=(yyvsp[-1].case_expr_list); cvector_push_back((yyvsp[-1].case_expr_list), (yyvsp[0].case_expr)); }
#line 2061 "comp.tab.c"
    break;

  case 60:
#line 264 "comp.y"
                                    { (yyval.case_expr)=create_ast_case_t(NULL, (yyvsp[0].block)); }
#line 2067 "comp.tab.c"
    break;

  case 61:
#line 265 "comp.y"
                                    { (yyval.case_expr)=create_ast_case_t((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 2073 "comp.tab.c"
    break;

  case 62:
#line 269 "comp.y"
                                                     { (yyval.block)=create_ast_block_t((yyvsp[-1].block_expression_list)); }
#line 2079 "comp.tab.c"
    break;

  case 63:
#line 273 "comp.y"
                                                { (yyval.block_expression_list)=NULL; }
#line 2085 "comp.tab.c"
    break;

  case 64:
#line 274 "comp.y"
                                                { (yyval.block_expression_list)=(yyvsp[-1].block_expression_list); cvector_push_back((yyvsp[-1].block_expression_list), (yyvsp[0].block_expression)); }
#line 2091 "comp.tab.c"
    break;

  case 65:
#line 278 "comp.y"
                                            { (yyval.block_expression)=create_ast_block_expr_t(EXPR, (yyvsp[-1].expr)); }
#line 2097 "comp.tab.c"
    break;

  case 66:
#line 279 "comp.y"
                                            { (yyval.block_expression)=create_ast_block_expr_t(DECL, (yyvsp[0].term_decl)); }
#line 2103 "comp.tab.c"
    break;

  case 67:
#line 283 "comp.y"
                                                                                 { (yyval.fun_decl)=create_ast_fundecl_t((yyvsp[-5].IDENTIFIER), (yyvsp[-3].param_list), (yyvsp[-1].IDENTIFIER), (yyvsp[0].block)); }
#line 2109 "comp.tab.c"
    break;

  case 68:
#line 287 "comp.y"
                                        {(yyval.param_list)=NULL;}
#line 2115 "comp.tab.c"
    break;

  case 69:
#line 288 "comp.y"
                                        {(yyval.param_list)=cvector_create(ast_param_t, 1); cvector_push_back((yyval.param_list), (yyvsp[0].param));}
#line 2121 "comp.tab.c"
    break;

  case 70:
#line 289 "comp.y"
                                        {(yyval.param_list)=(yyvsp[-2].param_list); cvector_push_back((yyvsp[-2].param_list), (yyvsp[0].param));}
#line 2127 "comp.tab.c"
    break;

  case 71:
#line 293 "comp.y"
                                                    { (yyval.param)=create_ast_param_t((yyvsp[-3].val_or_var), (yyvsp[-2].IDENTIFIER), (yyvsp[0].IDENTIFIER)); }
#line 2133 "comp.tab.c"
    break;

  case 72:
#line 297 "comp.y"
                                                    { (yyval.funcall)=create_ast_funcall_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].arg_list)); }
#line 2139 "comp.tab.c"
    break;

  case 73:
#line 301 "comp.y"
                        {(yyval.arg_list)=NULL;}
#line 2145 "comp.tab.c"
    break;

  case 74:
#line 302 "comp.y"
                        {cvector_push_back((yyval.arg_list), (yyvsp[0].expr));}
#line 2151 "comp.tab.c"
    break;

  case 75:
#line 303 "comp.y"
                             {(yyval.arg_list)=(yyvsp[-2].arg_list);cvector_push_back((yyvsp[-2].arg_list),(yyvsp[0].expr));}
#line 2157 "comp.tab.c"
    break;

  case 76:
#line 307 "comp.y"
                                                                         { (yyval.type_decl)=create_ast_type_decl_t((yyvsp[-3].IDENTIFIER), (yyvsp[-1].constructor_list)); }
#line 2163 "comp.tab.c"
    break;

  case 77:
#line 311 "comp.y"
                                                        { (yyval.constructor_list)=cvector_create(ast_constructor_t, 1); cvector_push_back((yyval.constructor_list), (yyvsp[0].constructor_field)); }
#line 2169 "comp.tab.c"
    break;

  case 78:
#line 312 "comp.y"
                                                        { (yyval.constructor_list)=(yyvsp[-2].constructor_list); cvector_push_back((yyvsp[-2].constructor_list), (yyvsp[0].constructor_field)); }
#line 2175 "comp.tab.c"
    break;

  case 79:
#line 316 "comp.y"
                                                   { (yyval.constructor_field)=create_ast_constructors_t((yyvsp[-1].IDENTIFIER), (yyvsp[0].record)); }
#line 2181 "comp.tab.c"
    break;

  case 80:
#line 320 "comp.y"
                                                    { (yyval.record)=NULL; }
#line 2187 "comp.tab.c"
    break;

  case 81:
#line 321 "comp.y"
                                                    { (yyval.record)=(yyvsp[-1].record_field_list); }
#line 2193 "comp.tab.c"
    break;

  case 82:
#line 325 "comp.y"
                                                    { (yyval.record_field_list)=cvector_create(ast_record_field_t, 1); cvector_push_back((yyval.record_field_list), (yyvsp[0].record_field)); }
#line 2199 "comp.tab.c"
    break;

  case 83:
#line 326 "comp.y"
                                                    { (yyval.record_field_list)=(yyvsp[-2].record_field_list); cvector_push_back((yyvsp[-2].record_field_list), (yyvsp[0].record_field)); }
#line 2205 "comp.tab.c"
    break;

  case 84:
#line 330 "comp.y"
                                                    { (yyval.record_field)=create_ast_record_field_t((yyvsp[-2].IDENTIFIER), (yyvsp[0].IDENTIFIER)); }
#line 2211 "comp.tab.c"
    break;


#line 2215 "comp.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, source_module, YY_("syntax error"));
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
        yyerror (&yylloc, scanner, source_module, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, source_module);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, scanner, source_module, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, source_module);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, scanner, source_module);
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
#line 332 "comp.y"


void yyerror(YYLTYPE* yyllocp, yyscan_t unused,ast_source_t **source_module, const char* msg) {
  
  char token_name[255];
  
  fprintf(stderr, "[%d:%d]: %s\n",
                  yyllocp->first_line, yyllocp->first_column, msg);
}
