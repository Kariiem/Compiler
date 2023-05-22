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
#line 4 "comp.y"


    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #define SYM_TAB_MAX 1000
    #define SYM_MAX 1000
    #define SYM_TAB_STACK_MAX 1000

    typedef enum { false, true } bool;

    // Struct of a single entry in the symbol table
    typedef struct symbol {
        char* name; // Name of the symbol
        int type;   // Type of the symbol
        char* value;  // Value of the symbol
        int line_num;   // Line number of the symbol for debugging
        int symbol_id;     // ID of the symbol
        bool is_const;  // Whether the symbol is a constant
        bool is_enum;   // Whether the symbol is an enum
        bool is_func;   // Whether the symbol is a function
    } symbol;

    // Struct of the symbol table itself
    typedef struct symTable {
        symbol* symbols;
        int num_symbols;
        int max_symbols;
        int index;
    } symTable;

    // Struct of a stack of symbol tables
    typedef struct symTableStack {
        symTable** sym_tabs;
        int num_sym_tabs;
        int max_sym_tabs;
    } symTableStack;


    enum types {
        TYPE_INT,
        TYPE_REAL,
        TYPE_STRING,
        TYPE_BOOL,
        TYPE_VOID,
        TYPE_ENUM,
        TYPE_FUNC,
        TYPE_JUMP   // Used for jumps in the code like IF, ELSE, FOR, WHILE, etc.
    };

    // Define a function to create a new symbol table
    symTable* create_sym_table();

    // Define a function to create a new symbol table stack
    symTableStack* create_sym_tab_stack();

    // Define a function to push a symbol table onto the stack
    void push_sym_tab(symTableStack* stack, symTable* sym_tab);

    // Define a function to pop a symbol table off the stack
    symTable* pop_sym_tab(symTableStack* stack);

    // Define a function to add a symbol to the symbol table
    void add_symbol(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id, bool is_const, bool is_enum, bool is_func);

    // Define a function to get a symbol from the symbol table
    // reverse_search is used to search the symbol table stack from top to bottom with default value false
    symbol* get_symbol(symTableStack* stack, char* name, bool reverse_search, bool search_parent);

    // Define a function to copy value of a symbol to another symbol
    char* copy_value(char* value);
    // Define a function to copy value of void
    void* copy_void(void* value);

    // Define a function to cast type void to type symbol
    symbol* cast_void_to_symbol(void* value){
        return (symbol*)value;
    }

    // Define a function to know the type of an identifier
    int get_type(char* name){
        if(strcmp(name, "int") == 0){
            return TYPE_INT;
        }
        else if(strcmp(name, "double") == 0){
            return TYPE_REAL;
        }
        else if(strcmp(name, "string") == 0){
            return TYPE_STRING;
        }
        else if(strcmp(name, "bool") == 0){
            return TYPE_BOOL;
        }
        else if(strcmp(name, "void") == 0){
            return TYPE_VOID;
        }
        else{
            return -1;
        }
    }


    // Define a function to check for assignment compatibility with a symbol
    // It takes the assignment type as enum and the symbol to check
    bool check_assignment(symbol* sym, char* type_name);

    // Create a global symbol table stack
    symTableStack* sym_tab_stack;

    extern int line_num; // Line number of the current token for debugging

    int symbol_id = 0; // ID of the current symbol

    int if_label_counter = 0; // Counter for the IF labels

    int while_label_counter = 0; // Counter for the WHILE labels

    int identifier_flag = 0; // Flag to check if the current token is an identifier


#line 191 "comp.tab.c"

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
#line 126 "comp.y"

    char* id;
    int integer;
    double real;
    char* string;
    int boolean;
    void* voidVal;
    void* symbolval;

#line 304 "comp.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMP_TAB_H_INCLUDED  */



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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

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
       0,   224,   224,   224,   228,   233,   234,   239,   241,   243,
     245,   247,   252,   257,   286,   307,   308,   312,   313,   317,
     318,   319,   320,   321,   322,   326,   340,   349,   358,   367,
     379,   380,   381,   382,   383,   384,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   400,   401,   402,   403,   404,
     405,   410,   424,   440,   409,   475,   480,   485,   486,   490,
     502,   490,   536,   541,   546,   551,   552,   557,   559,   564,
     564,   580,   581,   585,   586,   587,   591,   595,   596,   597,
     601,   605,   609,   610,   611,   615,   619,   620,   624
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
  "INTEGER", "REAL", "STRING", "BOOL", "$accept", "source", "$@1",
  "module_decl", "top_level_decl_list", "top_level_decl", "import_decl",
  "term_decl", "assignment", "val_or_var", "optional_assignment", "expr",
  "atomic_value", "arithmetic_expr", "logical_expr", "compound_expr",
  "if_then_else_expr", "$@2", "$@3", "$@4", "for_loop_expr", "range",
  "optional_step", "while_loop_expr", "$@5", "$@6", "until_loop_expr",
  "do_block_expr", "switch_expr", "case_expr_list", "case_expr", "block",
  "$@7", "block_expression_list", "block_expression", "fun_decl",
  "param_list", "param", "funcall", "arg_list", "type_decl",
  "constructor_list", "constructor_field", YY_NULLPTR
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

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -33,    26,   -67,    -6,   -67,   -67,   -67,    10,    -9,
      -8,   -67,   -67,    -7,    27,   -67,   -67,   -67,   -67,    13,
     -67,   -67,    24,    31,    45,   118,    51,   -67,     2,    38,
      46,   118,    44,   -67,   118,   118,   118,   118,    53,   -67,
     -67,   -67,   -67,   223,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,    47,    49,   -14,   -67,   -67,
     -12,   -67,   -67,   -67,   332,    68,   118,   152,   176,    78,
     200,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   -67,   -24,    70,     2,
      57,   -67,    38,   -67,    46,    79,   332,   -67,   -67,   -67,
     332,    23,    52,    52,     4,     4,     4,     4,    78,     4,
      78,    78,    78,    78,    78,    78,   118,   -67,   -67,    72,
     -67,    46,   -67,    58,   -67,   118,    46,    46,   100,   118,
     -67,   242,   -67,   -67,   -67,   -19,   -67,   -67,   261,   -67,
     108,   280,   -67,   -67,    88,   -67,   316,   -67,   332,   -67,
     -67,   -67,   118,    46,    46,    46,   298,   -67,   -67,   -67,
     118,    83,   332,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     5,     4,     3,     0,
       0,    15,    16,     0,     0,     6,     7,     9,    11,     0,
      10,     8,     0,     0,     0,     0,     0,    12,    77,     0,
       0,     0,     0,    59,     0,     0,     0,     0,    25,    26,
      27,    29,    28,     0,    19,    20,    21,    23,    45,    46,
      47,    48,    49,    50,    22,     0,     0,     0,    78,    88,
       0,    86,    69,    63,    51,     0,     0,     0,     0,    36,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    85,     0,    71,     0,     0,    60,    62,    65,    24,
      83,     0,    37,    38,    30,    31,    32,    33,    35,    34,
      39,    40,    41,    42,    43,    44,     0,    18,    13,     0,
      79,     0,    87,     0,    52,     0,     0,     0,     0,     0,
      81,     0,    80,    76,    70,    25,    74,    75,     0,    72,
       0,     0,    55,    61,     0,    64,     0,    66,    84,    17,
      73,    53,     0,     0,     0,     0,    57,    67,    68,    54,
       0,     0,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,     1,   -26,
     -67,   -31,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -66,   -67,   -67,   -67,   -67,   -67,    36,   -67,   -67,
     -67,   -67,    34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     3,     8,    15,    16,    17,    18,    19,
     118,    43,    44,    45,    46,    47,    48,    94,   140,   155,
      49,   126,   161,    50,    66,   127,    51,    52,    53,   128,
     147,    63,    93,   123,   139,    20,    57,    58,    54,   101,
      21,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    97,    56,    67,    68,    69,    70,   116,    11,    12,
       1,   117,    25,     4,     9,    10,    11,    12,    13,    71,
      89,    72,    73,    91,    92,    90,     5,    78,   124,    80,
      81,    82,    83,    84,    85,    96,     7,    22,    23,    24,
     100,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   133,    14,   129,    25,    26,
     142,   143,   130,    56,    11,    12,    27,    30,    31,    28,
      32,    33,    34,    35,    36,    78,    29,    80,    81,    82,
      83,    84,    85,    55,    59,   131,    62,   157,   158,   159,
      65,    71,   138,    87,   141,    88,    37,   146,   148,   134,
      95,    78,   119,   121,   135,    39,    40,    41,    42,    30,
      31,   144,    32,    33,    34,    35,    36,   125,   132,   151,
     153,   156,   163,   136,   137,   120,   122,    30,    31,   162,
      32,    33,    34,    35,    36,     0,     0,     0,    37,     0,
       0,   145,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,   149,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,   150,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,   152,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,   160,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,   154,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      31,    67,    28,    34,    35,    36,    37,    31,     6,     7,
       3,    35,    31,    46,     4,     5,     6,     7,     8,    38,
      34,    17,    18,    35,    36,    39,     0,    23,    94,    25,
      26,    27,    28,    29,    30,    66,    42,    46,    46,    46,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   121,    46,    34,    31,    46,
     126,   127,    39,    89,     6,     7,    42,     9,    10,    38,
      12,    13,    14,    15,    16,    23,    31,    25,    26,    27,
      28,    29,    30,    32,    46,   116,    40,   153,   154,   155,
      46,    38,   123,    46,   125,    46,    38,   128,   129,    41,
      32,    23,    32,    46,    46,    47,    48,    49,    50,     9,
      10,    11,    12,    13,    14,    15,    16,    38,    46,    11,
      32,   152,    39,   123,   123,    89,    92,     9,    10,   160,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    34,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    34,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    54,    46,     0,    53,    42,    55,     4,
       5,     6,     7,     8,    46,    56,    57,    58,    59,    60,
      86,    91,    46,    46,    46,    31,    46,    42,    38,    31,
       9,    10,    12,    13,    14,    15,    16,    38,    46,    47,
      48,    49,    50,    62,    63,    64,    65,    66,    67,    71,
      74,    77,    78,    79,    89,    32,    60,    87,    88,    46,
      92,    93,    40,    82,    62,    46,    75,    62,    62,    62,
      62,    38,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    35,    46,    46,    34,
      39,    35,    36,    83,    68,    32,    62,    82,    40,    39,
      62,    90,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    31,    35,    61,    32,
      88,    46,    93,    84,    82,    38,    72,    76,    80,    34,
      39,    62,    46,    82,    41,    46,    58,    59,    62,    85,
      69,    62,    82,    82,    11,    41,    62,    81,    62,    35,
      35,    11,    34,    32,    32,    70,    62,    82,    82,    82,
      34,    73,    62,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    53,    52,    54,    55,    55,    56,    56,    56,
      56,    56,    57,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    68,    69,    70,    67,    71,    72,    73,    73,    75,
      76,    74,    77,    78,    79,    80,    80,    81,    81,    83,
      82,    84,    84,    85,    85,    85,    86,    87,    87,    87,
      88,    89,    90,    90,    90,    91,    92,    92,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     0,     2,     1,     1,     1,
       1,     1,     3,     5,     4,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     0,     0,     8,     5,     6,     0,     2,     0,
       0,     5,     3,     2,     5,     0,     2,     3,     3,     0,
       4,     0,     2,     2,     1,     1,     7,     0,     1,     3,
       4,     4,     0,     1,     3,     5,     1,     3,     1
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
#line 224 "comp.y"
                {printf("Kak_BEGINE\n");}
#line 1646 "comp.tab.c"
    break;

  case 3:
#line 224 "comp.y"
                                                                   {printf("Kak_END\n");}
#line 1652 "comp.tab.c"
    break;

  case 4:
#line 229 "comp.y"
    {}
#line 1658 "comp.tab.c"
    break;

  case 5:
#line 233 "comp.y"
                                            {}
#line 1664 "comp.tab.c"
    break;

  case 6:
#line 235 "comp.y"
    {}
#line 1670 "comp.tab.c"
    break;

  case 7:
#line 240 "comp.y"
    {}
#line 1676 "comp.tab.c"
    break;

  case 8:
#line 242 "comp.y"
    {}
#line 1682 "comp.tab.c"
    break;

  case 9:
#line 244 "comp.y"
    {}
#line 1688 "comp.tab.c"
    break;

  case 10:
#line 246 "comp.y"
    {}
#line 1694 "comp.tab.c"
    break;

  case 11:
#line 248 "comp.y"
    {}
#line 1700 "comp.tab.c"
    break;

  case 12:
#line 253 "comp.y"
    {}
#line 1706 "comp.tab.c"
    break;

  case 13:
#line 258 "comp.y"
    {
        // First check if the name is already taken
        symbol* sym = get_symbol(sym_tab_stack, (yyvsp[-3].id), false, false);

        // If the symbol is not found, add it to the symbol table
        if(sym == NULL){
            // Check if the type is valid
            // The $4 is the type of the variable but it is stored as a string in the token
            // We match the string to the type and get the type as an integer
            int type = get_type((yyvsp[-1].id));
            symbol_id++;
            add_symbol(sym_tab_stack, (yyvsp[-3].id), type, (yyvsp[0].symbolval), line_num, symbol_id ,((yyvsp[-4].integer) == 0), false, false);
            if((yyvsp[0].symbolval)!=NULL)
            {
                // Write an assembly command to sotre the value of the variable
                printf("PUSH_MEM %d\n", symbol_id);
            }
        }
        else{
            printf("ERROR: Symbol %s already defined on line %d\n", (yyvsp[-3].id), sym->line_num);
            exit(1);
        }

        
    }
#line 1736 "comp.tab.c"
    break;

  case 14:
#line 287 "comp.y"
    {
        // First check if the symbol exists
        symbol* sym = get_symbol(sym_tab_stack, (yyvsp[-3].id), false, true);

        // If the symbol is not found, add it to the symbol table
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", (yyvsp[-3].id), line_num);
            exit(1);
        }
        else{
            // Check if the assignment is valid
            ////TODO: Apply the stack approach that kamal mentioned and if the identifier is a variable, pop it from the stack machine and but check first if it's there
            // Note that there may be compound expressions on the right hand side of the assignment and binary operations not just atomic values
            // Write an assembly command to store the value of the variable
            printf("PUSH_MEM %d\n", sym->symbol_id);
        }
    }
#line 1758 "comp.tab.c"
    break;

  case 15:
#line 307 "comp.y"
                { (yyval.integer)=0;}
#line 1764 "comp.tab.c"
    break;

  case 16:
#line 308 "comp.y"
                { (yyval.integer)=1; }
#line 1770 "comp.tab.c"
    break;

  case 17:
#line 312 "comp.y"
                                             {(yyval.symbolval) = (yyvsp[-1].symbolval);}
#line 1776 "comp.tab.c"
    break;

  case 18:
#line 313 "comp.y"
                                             {(yyval.symbolval) = NULL;}
#line 1782 "comp.tab.c"
    break;

  case 19:
#line 317 "comp.y"
                        { (yyval.symbolval) = (yyvsp[0].symbolval); }
#line 1788 "comp.tab.c"
    break;

  case 20:
#line 318 "comp.y"
                        {  }
#line 1794 "comp.tab.c"
    break;

  case 21:
#line 319 "comp.y"
                        {  }
#line 1800 "comp.tab.c"
    break;

  case 22:
#line 320 "comp.y"
                        {  }
#line 1806 "comp.tab.c"
    break;

  case 23:
#line 321 "comp.y"
                        {  }
#line 1812 "comp.tab.c"
    break;

  case 24:
#line 322 "comp.y"
                                           { (yyval.symbolval) = (yyvsp[-1].symbolval); }
#line 1818 "comp.tab.c"
    break;

  case 25:
#line 326 "comp.y"
                    { 
                    identifier_flag = 1; (yyval.symbolval) = (yyvsp[0].id); 
                    // First check if the symbol exists
                    symbol* sym = get_symbol(sym_tab_stack, (yyvsp[0].id), false, true);
                    
                    // If the symbol is not found, error out
                    if(sym == NULL){
                        printf("ERROR: Symbol %s not defined on line %d\n", (yyvsp[0].id), line_num);
                        exit(1);
                    }
                    else{
                        printf("POP_MEM %d\n", sym->symbol_id);
                    }
                    }
#line 1837 "comp.tab.c"
    break;

  case 26:
#line 340 "comp.y"
                    { 
                    printf("PUSH %d\n", (yyvsp[0].integer));
                    //Create a new void pointer to store the value of the integer
                    void* val = malloc(sizeof(int));
                    //Copy the value of the integer to the void pointer
                    memcpy(val, &(yyvsp[0].integer), sizeof(int));
                    //Return the void pointer
                    (yyval.symbolval) = val;
                    }
#line 1851 "comp.tab.c"
    break;

  case 27:
#line 349 "comp.y"
                    { 
                    printf("PUSH %f\n", (yyvsp[0].real));
                    //Create a new void pointer to store the value of the real
                    void* val = malloc(sizeof(double));
                    //Copy the value of the real to the void pointer
                    memcpy(val, &(yyvsp[0].real), sizeof(double));
                    //Return the void pointer
                    (yyval.symbolval) = val;
                    }
#line 1865 "comp.tab.c"
    break;

  case 28:
#line 358 "comp.y"
                    { 
                    printf("PUSH %d\n", (yyvsp[0].boolean)); 
                    //Create a new void pointer to store the value of the boolean
                    void* val = malloc(sizeof(bool));
                    //Copy the value of the boolean to the void pointer
                    memcpy(val, &(yyvsp[0].boolean), sizeof(bool));
                    //Return the void pointer
                    (yyval.symbolval) = val;
                    }
#line 1879 "comp.tab.c"
    break;

  case 29:
#line 367 "comp.y"
                    { 
                    printf("PUSH %s\n", (yyvsp[0].string));
                    //Create a new void pointer to store the value of the string
                    void* val = malloc(sizeof(char*));
                    //Copy the value of the string to the void pointer
                    memcpy(val, &(yyvsp[0].string), sizeof(char*));
                    //Return the void pointer
                    (yyval.symbolval) = val;
                    }
#line 1893 "comp.tab.c"
    break;

  case 30:
#line 379 "comp.y"
                              { printf("ADD\n"); }
#line 1899 "comp.tab.c"
    break;

  case 31:
#line 380 "comp.y"
                              { printf("SUB\n"); }
#line 1905 "comp.tab.c"
    break;

  case 32:
#line 381 "comp.y"
                              { printf("MUL\n"); }
#line 1911 "comp.tab.c"
    break;

  case 33:
#line 382 "comp.y"
                              { printf("DIV\n"); }
#line 1917 "comp.tab.c"
    break;

  case 34:
#line 383 "comp.y"
                              { printf("MOD\n"); }
#line 1923 "comp.tab.c"
    break;

  case 35:
#line 384 "comp.y"
                              { printf("EXP\n"); }
#line 1929 "comp.tab.c"
    break;

  case 36:
#line 388 "comp.y"
                                { printf("NOT\n"); }
#line 1935 "comp.tab.c"
    break;

  case 37:
#line 389 "comp.y"
                                { printf("AND\n"); }
#line 1941 "comp.tab.c"
    break;

  case 38:
#line 390 "comp.y"
                                { printf("OR\n"); }
#line 1947 "comp.tab.c"
    break;

  case 39:
#line 391 "comp.y"
                                { printf("LT\n"); }
#line 1953 "comp.tab.c"
    break;

  case 40:
#line 392 "comp.y"
                                { printf("GT\n"); }
#line 1959 "comp.tab.c"
    break;

  case 41:
#line 393 "comp.y"
                                { printf("LEQ\n"); }
#line 1965 "comp.tab.c"
    break;

  case 42:
#line 394 "comp.y"
                                { printf("GEQ\n"); }
#line 1971 "comp.tab.c"
    break;

  case 43:
#line 395 "comp.y"
                                { printf("EQ\n"); }
#line 1977 "comp.tab.c"
    break;

  case 44:
#line 396 "comp.y"
                                { printf("NEQ\n"); }
#line 1983 "comp.tab.c"
    break;

  case 45:
#line 400 "comp.y"
                                { }
#line 1989 "comp.tab.c"
    break;

  case 46:
#line 401 "comp.y"
                                {  }
#line 1995 "comp.tab.c"
    break;

  case 47:
#line 402 "comp.y"
                                {  }
#line 2001 "comp.tab.c"
    break;

  case 48:
#line 403 "comp.y"
                                {  }
#line 2007 "comp.tab.c"
    break;

  case 49:
#line 404 "comp.y"
                                {  }
#line 2013 "comp.tab.c"
    break;

  case 50:
#line 405 "comp.y"
                                {  }
#line 2019 "comp.tab.c"
    break;

  case 51:
#line 410 "comp.y"
    {
        // How to hanle labels of the if statement:
        // increment the if_label_counter which is global
        // Store it in the symbol_id of the symbol entry in the symbol table
        // Else and End_if will get the latest entry in the symbol table with type IF 
        // If the expression is flase, Jump to the else label
        if_label_counter++;
        printf("JMP_FALSE ELSE_IF_%d\n", if_label_counter);

        // Create a new symbol for the if statement and push it to the symbol table
        add_symbol(sym_tab_stack, "IF", TYPE_JUMP , NULL , line_num ,if_label_counter, false, false, false);

    }
#line 2037 "comp.tab.c"
    break;

  case 52:
#line 424 "comp.y"
    {
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JUMP END_IF_%d\n", sym->symbol_id);
        }

    }
#line 2058 "comp.tab.c"
    break;

  case 53:
#line 440 "comp.y"
               {
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the else block
            printf("ELSE_IF_%d:\n", sym->symbol_id);
        }

    }
#line 2079 "comp.tab.c"
    break;

  case 54:
#line 456 "comp.y"
          { 
        // Search for the last symbol with name IF in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "IF", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "IF", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the else block
            printf("END_IF_%d:\n", sym->symbol_id);
        }

    }
#line 2100 "comp.tab.c"
    break;

  case 55:
#line 476 "comp.y"
    {  }
#line 2106 "comp.tab.c"
    break;

  case 56:
#line 481 "comp.y"
    {  }
#line 2112 "comp.tab.c"
    break;

  case 57:
#line 485 "comp.y"
                    { }
#line 2118 "comp.tab.c"
    break;

  case 58:
#line 486 "comp.y"
                        {  }
#line 2124 "comp.tab.c"
    break;

  case 59:
#line 490 "comp.y"
               {
        // How to hanle labels of the while statement:
        // increment the while_label_counter which is global
        // Store it in the symbol_id of the symbol entry in the symbol table
        // End_while will get the latest entry in the symbol table with type WHILE 
        // If the expression is flase, Jump to the end_while label
        while_label_counter++;
        printf("BEGIN_WHILE_%d:\n", while_label_counter);

        // Create a new symbol for the while statement and push it to the symbol table
        add_symbol(sym_tab_stack, "WHILE", TYPE_JUMP , NULL , line_num ,while_label_counter, false, false, false);
    }
#line 2141 "comp.tab.c"
    break;

  case 60:
#line 502 "comp.y"
        {
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JMP_FALSE END_WHILE_%d\n", sym->symbol_id);
        }
    }
#line 2161 "comp.tab.c"
    break;

  case 61:
#line 517 "comp.y"
         {
        // Search for the last symbol with name WHILE in the symbol table
        // Search from the top of the stack
        symbol* sym = get_symbol(sym_tab_stack, "WHILE", true, false);

        // If the symbol is not found, error out
        if(sym == NULL){
            printf("ERROR: Symbol %s not defined on line %d\n", "WHILE", line_num);
            exit(1);
        }
        else{
            // If the symbol is found, print the label for the jump block
            printf("JUMP BEGIN_WHILE_%d\n", sym->symbol_id);
            printf("END_WHILE_%d:\n", sym->symbol_id);
        }
    }
#line 2182 "comp.tab.c"
    break;

  case 62:
#line 537 "comp.y"
    {  }
#line 2188 "comp.tab.c"
    break;

  case 63:
#line 542 "comp.y"
    {  }
#line 2194 "comp.tab.c"
    break;

  case 64:
#line 547 "comp.y"
    {  }
#line 2200 "comp.tab.c"
    break;

  case 65:
#line 551 "comp.y"
                                    {  }
#line 2206 "comp.tab.c"
    break;

  case 66:
#line 553 "comp.y"
    {  }
#line 2212 "comp.tab.c"
    break;

  case 67:
#line 558 "comp.y"
    {  }
#line 2218 "comp.tab.c"
    break;

  case 68:
#line 560 "comp.y"
    {  }
#line 2224 "comp.tab.c"
    break;

  case 69:
#line 564 "comp.y"
                 {
        // Create a new symbol table for the if block and push it to the stack
        symTable* block_sym_tab = create_sym_table();
        push_sym_tab(sym_tab_stack, block_sym_tab);

    }
#line 2235 "comp.tab.c"
    break;

  case 70:
#line 571 "comp.y"
                  { 
        // After evaluating the block, pop the symbol table on top of the stack
        // First pop the symbol table on top of the stack
        pop_sym_tab(sym_tab_stack);

     }
#line 2246 "comp.tab.c"
    break;

  case 71:
#line 580 "comp.y"
                                                {  }
#line 2252 "comp.tab.c"
    break;

  case 72:
#line 581 "comp.y"
                                                { }
#line 2258 "comp.tab.c"
    break;

  case 73:
#line 585 "comp.y"
                                            {  }
#line 2264 "comp.tab.c"
    break;

  case 74:
#line 586 "comp.y"
                                            {  }
#line 2270 "comp.tab.c"
    break;

  case 75:
#line 587 "comp.y"
                                            {  }
#line 2276 "comp.tab.c"
    break;

  case 76:
#line 591 "comp.y"
                                                                                 { }
#line 2282 "comp.tab.c"
    break;

  case 77:
#line 595 "comp.y"
                                        {}
#line 2288 "comp.tab.c"
    break;

  case 78:
#line 596 "comp.y"
                                        {}
#line 2294 "comp.tab.c"
    break;

  case 79:
#line 597 "comp.y"
                                        {}
#line 2300 "comp.tab.c"
    break;

  case 80:
#line 601 "comp.y"
                                                    {  }
#line 2306 "comp.tab.c"
    break;

  case 81:
#line 605 "comp.y"
                                                    {  }
#line 2312 "comp.tab.c"
    break;

  case 82:
#line 609 "comp.y"
                        {}
#line 2318 "comp.tab.c"
    break;

  case 83:
#line 610 "comp.y"
                        {}
#line 2324 "comp.tab.c"
    break;

  case 84:
#line 611 "comp.y"
                                {}
#line 2330 "comp.tab.c"
    break;

  case 85:
#line 615 "comp.y"
                                                                         {  }
#line 2336 "comp.tab.c"
    break;

  case 86:
#line 619 "comp.y"
                                                        {  }
#line 2342 "comp.tab.c"
    break;

  case 87:
#line 620 "comp.y"
                                                        {  }
#line 2348 "comp.tab.c"
    break;

  case 88:
#line 624 "comp.y"
                                                        { }
#line 2354 "comp.tab.c"
    break;


#line 2358 "comp.tab.c"

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
#line 628 "comp.y"




int main (void) {
	/* init symbol table */

    // Assign the global sym_tab_stack
    sym_tab_stack = create_sym_tab_stack();

    // Create the global symbol table empty and push it to the stack
    symTable *global_sym_tab = create_sym_table();

    // Push the global symbol table to the stack
    push_sym_tab(sym_tab_stack, global_sym_tab);

	return yyparse ( );
}

// Define a function to create a new symbol table
symTable* create_sym_table(){
    symTable *new_sym_tab = (symTable*)malloc(sizeof(symTable));
    new_sym_tab->num_symbols = 0;
    new_sym_tab->max_symbols = SYM_MAX;
    new_sym_tab->index = 0;
    new_sym_tab->symbols = (symbol*)malloc(sizeof(symbol)*SYM_MAX);
    return new_sym_tab;
}

// Define a function to create a new symbol table stack
symTableStack* create_sym_tab_stack(){
    symTableStack *new_sym_tab_stack = (symTableStack*)malloc(sizeof(symTableStack));
    new_sym_tab_stack->num_sym_tabs = 0;
    new_sym_tab_stack->max_sym_tabs = SYM_TAB_MAX;
    new_sym_tab_stack->sym_tabs = (symTable**)malloc(sizeof(symTable *)*SYM_TAB_MAX);
    return new_sym_tab_stack;
}

// Define a function to push a symbol table to the stack
void push_sym_tab(symTableStack *sym_tab_stack, symTable *sym_tab){
    if(sym_tab_stack->num_sym_tabs < sym_tab_stack->max_sym_tabs){
        sym_tab->index = sym_tab_stack->num_sym_tabs;   // Set the index of the symbol table
        sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs] = sym_tab; // Push the symbol table to the stack
        sym_tab_stack->num_sym_tabs++;  // Increment the number of symbol tables in the stack
    }
    else{
        printf("Error: Symbol table stack overflow\n");
    }
}

// Define a function to pop a symbol table from the stack
symTable* pop_sym_tab(symTableStack *sym_tab_stack){
    if(sym_tab_stack->num_sym_tabs > 0){
        symTable *sym_tab = sym_tab_stack->sym_tabs[sym_tab_stack->num_sym_tabs-1]; // Pop the symbol table from the stack
        sym_tab_stack->num_sym_tabs--;  // Decrement the number of symbol tables in the stack
        return sym_tab;
    }
    else{
        printf("Error: Symbol table stack underflow\n");
        return NULL;
    }
}

    // Define a function to add a symbol to the symbol table
    void add_symbol(symTableStack* stack, char* name, int type, char* value, int line_num, int symbol_id ,bool is_const, bool is_enum, bool is_func)
    {

        // Check if the symbol table stack is empty
        if(stack->num_sym_tabs == 0){
            // If it is, Error out
            printf("Error: Symbol table stack is empty\n");
            return;
        }

        // Get the top symbol table from the stack
        symTable* sym_tab = stack->sym_tabs[stack->num_sym_tabs - 1];

        // Check if the symbol is already in the symbol table
        for(int i = 0; i < sym_tab->num_symbols; i++){
            if(strcmp(sym_tab->symbols[i].name, name) == 0){
                // If it is, Error out
                printf("Error: Symbol %s already exists in symbol table\n", name);
                return;
            }
        }

        // copy the value to avoid dangling pointers
        char* value_copy = copy_value(value);

        // Create instance of symbol
        symbol sym = {
            .name = name,
            .type = type,
            .value = value_copy,
            .line_num = line_num,
            .symbol_id = symbol_id,
            .is_const = is_const,
            .is_enum = is_enum,
            .is_func = is_func,
        };

        // Add the symbol to the symbol table
        sym_tab->symbols[sym_tab->num_symbols] = sym;
        sym_tab->num_symbols++;

    }

    // Define a function to get a symbol from the symbol table
    symbol* get_symbol(symTableStack* stack, char* name, bool reverse_search, bool search_parent){


        // Check if the symbol table stack is empty
        if(stack->num_sym_tabs == 0){
            // If it is, Error out
            printf("Error: Symbol table stack is empty\n");
            return NULL;
        }
        // Loop over the stack until the symbol is found or the stack is empty
        for(int i = stack->num_sym_tabs - 1; i >= 0; i--){

            // Get the symbol table from the stack
            symTable* sym_tab = stack->sym_tabs[i];

            if (reverse_search){
                // Check if the symbol is in the symbol table
                for(int j = sym_tab->num_symbols - 1; j >= 0; j--){
                    if(strcmp(sym_tab->symbols[j].name, name) == 0){
                        // If it is, return the symbol
                        return &sym_tab->symbols[j];
                    }
                }
            }
            else {
                // Check if the symbol is in the symbol table
                for(int j = 0; j < sym_tab->num_symbols; j++){
                    if(strcmp(sym_tab->symbols[j].name, name) == 0){
                        // If it is, return the symbol
                        return &sym_tab->symbols[j];
                    }
                }
            }
            if (!search_parent){
                break;
            }
        }


        // If it is not, Error out
        return NULL;
    
    }

    // Define a function to copy value of a symbol to another symbol
    char* copy_value(char* value)
    {
        // Check if the value is null
        if(value == NULL){
            // If it is, return null
            return NULL;
        }

        // Get the length of the value
        int len = strlen(value);

        // Allocate memory for the copy
        char* copy = malloc(len + 1);

        // Copy the value
        strcpy(copy, value);

        // Return the copy
        return copy;
    }

    // Define a function to check for assignment compatibility with a symbol
    // It takes the assignment type as enum and the symbol to check
    bool check_assignment(symbol* sym, char* type_name)
    {
        int type = get_type(type_name);
        if (type == -1) {
            // Check if the type_name is actually a number
            return true;    //TODO: Handle type checking for numbers
        }
        // Check if the symbol is null
        if(sym == NULL){
            // If it is, return false
            return false;
        }

        // Check if the symbol is a constant
        if(sym->is_const){
            // If it is, error out
            printf("Error: Cannot assign to constant\n");
            exit(1);
        }

        // Check if the symbol is an enum
        if(sym->is_enum){
            // If it is, error out
            printf("Error: Cannot assign to enum\n");
            exit(1);
        }

        // Check if the symbol is a function
        if(sym->is_func){
            // If it is, error out
            printf("Error: Cannot assign to function\n");
            exit(1);
        }

        // Check if the symbol is a void
        if(sym->type == TYPE_VOID){
            // If it is, error out
            printf("Error: Cannot assign to void\n");
            exit(1);
        }

        // Check if the symbol is an integer
        if(sym->type == TYPE_INT){
            // If it is, check if the assignment type is an integer or real
            if(type == TYPE_INT || type == TYPE_REAL){
                // If it is, return true
                return true;
            }
        }

        // Check if the symbol is a real
        if(sym->type == TYPE_REAL){
            // If it is, check if the assignment type is an integer or real
            if(type == TYPE_INT || type == TYPE_REAL){
                // If it is, return true
                return true;
            }
        }

        // Check if the symbol is a string
        if(sym->type == TYPE_STRING){
            // If it is, check if the assignment type is a string
            if(type == TYPE_STRING){
                // If it is, return true
                return true;
            }
        }

        // Check if the symbol is a boolean
        if(sym->type == TYPE_BOOL){
            // If it is, check if the assignment type is a boolean
            if(type == TYPE_BOOL){
                // If it is, return true
                return true;
            }
        }

        // If it is not, return false
        return false;
    }



void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

