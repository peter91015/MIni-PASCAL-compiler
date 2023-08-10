/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "0316050.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "node.h"
int yylex();
int yyerror( char *msg );
extern int line_no;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */

#line 80 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    id = 258,
    PROGRAM = 259,
    PROCEDURE = 260,
    ARRAY = 261,
    VAR = 262,
    OF = 263,
    FUNCTION = 264,
    INTEGER = 265,
    REAL = 266,
    STRING = 267,
    DOTDOT = 268,
    RBRAC = 269,
    LBRAC = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    PBEGIN = 276,
    END = 277,
    NOT = 278,
    ASSIGNMENT = 279,
    COLON = 280,
    SEMICOLON = 281,
    LPAREN = 282,
    RPAREN = 283,
    DOT = 284,
    COMMA = 285,
    PLUS = 286,
    MINUS = 287,
    STAR = 288,
    SLASH = 289,
    GT = 290,
    EQUAL = 291,
    LE = 292,
    GE = 293,
    notEQUAL = 294,
    LT = 295,
    CONST_INT = 296,
    CONST_REAL = 297,
    CONST_STRING = 298
  };
#endif
/* Tokens.  */
#define id 258
#define PROGRAM 259
#define PROCEDURE 260
#define ARRAY 261
#define VAR 262
#define OF 263
#define FUNCTION 264
#define INTEGER 265
#define REAL 266
#define STRING 267
#define DOTDOT 268
#define RBRAC 269
#define LBRAC 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WHILE 274
#define DO 275
#define PBEGIN 276
#define END 277
#define NOT 278
#define ASSIGNMENT 279
#define COLON 280
#define SEMICOLON 281
#define LPAREN 282
#define RPAREN 283
#define DOT 284
#define COMMA 285
#define PLUS 286
#define MINUS 287
#define STAR 288
#define SLASH 289
#define GT 290
#define EQUAL 291
#define LE 292
#define GE 293
#define notEQUAL 294
#define LT 295
#define CONST_INT 296
#define CONST_REAL 297
#define CONST_STRING 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "0316050.y" /* yacc.c:355  */

	int int_val;
	double real_val;
	char *string;
	struct node *node;

#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    59,    66,    78,    98,   104,   123,   143,
     147,   151,   158,   171,   178,   189,   208,   224,   231,   238,
     249,   271,   274,   280,   290,   294,   302,   307,   317,   325,
     329,   333,   345,   354,   362,   374,   384,   391,   399,   416,
     424,   436,   441,   453,   458,   469,   474,   486,   495,   506,
     511,   516,   523,   532,   537,   544,   549,   557,   562,   567,
     572,   577,   582,   588,   592,   596,   600
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "PROGRAM", "PROCEDURE", "ARRAY",
  "VAR", "OF", "FUNCTION", "INTEGER", "REAL", "STRING", "DOTDOT", "RBRAC",
  "LBRAC", "IF", "THEN", "ELSE", "WHILE", "DO", "PBEGIN", "END", "NOT",
  "ASSIGNMENT", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "DOT", "COMMA",
  "PLUS", "MINUS", "STAR", "SLASH", "GT", "EQUAL", "LE", "GE", "notEQUAL",
  "LT", "CONST_INT", "CONST_REAL", "CONST_STRING", "$accept", "prog",
  "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "optional_var", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable", "tail",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "addop", "mulop", "relop", "NUM",
  "lambda", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,    30,    63,    40,  -103,    70,  -103,    53,    66,    82,
    -103,  -103,    86,  -103,    70,    33,  -103,    -6,    91,    92,
      18,    71,  -103,    67,    60,    62,    62,    -2,     8,     8,
    -103,    76,    74,  -103,    77,  -103,    78,  -103,     7,  -103,
      87,  -103,  -103,  -103,    79,  -103,    96,    80,  -103,    83,
       8,     8,  -103,  -103,    28,     8,     8,    34,  -103,  -103,
    -103,    90,    21,    13,  -103,  -103,    89,  -103,    18,     8,
    -103,    34,  -103,  -103,    84,    70,  -103,  -103,    68,    97,
      54,  -103,     8,  -103,  -103,    85,  -103,    18,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     8,     8,  -103,  -103,
       8,    18,  -103,  -103,  -103,   101,  -103,    44,    93,    95,
    -103,     8,    58,  -103,    98,    13,    59,  -103,  -103,    34,
      60,  -103,  -103,  -103,  -103,    18,   103,    99,  -103,   107,
      96,    60,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
      66,     4,    66,     6,     0,     0,    13,     0,     0,     0,
      66,     0,    66,     0,     0,    66,    66,    37,     0,     0,
      30,     0,    24,    26,     0,    29,    25,    12,     0,     2,
       0,     9,    10,    11,     0,     7,    66,     0,    18,     0,
       0,     0,    34,    36,    66,     0,     0,     0,    63,    65,
      64,     0,    41,    43,    45,    49,     0,    23,    66,     0,
      14,     0,     5,    21,     0,     0,    22,    16,     0,     0,
       0,    39,     0,    47,    52,     0,    50,    66,    53,    54,
      58,    59,    60,    61,    62,    57,     0,     0,    55,    56,
       0,    66,    27,    33,    28,     0,    17,     0,     0,    66,
      38,     0,     0,    51,     0,    44,    42,    46,    32,     0,
       0,    15,    35,    40,    48,    66,     0,    19,    31,     0,
      66,     0,    20,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,   -13,   100,  -102,    43,  -103,  -103,  -103,   102,
     -12,  -103,    -8,  -103,  -103,   -60,  -103,   -45,  -103,    41,
     -24,    27,    31,   -52,  -103,  -103,  -103,   -51,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    44,    45,    15,    21,    22,    47,
      74,    75,    30,    31,    32,    33,    34,    52,    35,    80,
      81,    62,    63,    64,    96,   100,    97,    65,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    17,    16,    84,    61,    66,    86,    23,   102,    83,
      36,    54,    13,    50,    14,    48,    48,    53,   127,    24,
     105,    27,   -66,     1,     9,    51,    79,   114,    20,   133,
      70,    55,    85,     3,    28,    56,    76,    29,    18,    20,
      57,   118,    19,    50,    53,   104,    98,    99,   117,    58,
      59,    60,    88,    89,    20,    82,    90,    91,    92,    93,
      94,    95,   107,     4,   122,   128,    40,     5,   126,   120,
      41,    42,    43,     6,     9,    58,    59,    60,    41,    42,
      43,     8,   110,     9,   111,    11,   124,   123,   111,    46,
      88,    89,    10,    14,    25,    26,    39,    37,    67,    53,
      68,    69,    71,    73,   -33,    72,    77,    87,    78,   101,
      50,   109,   106,   113,   119,   131,   125,   129,   132,   121,
      76,   108,    38,   112,   116,   130,     0,   115,    49
};

static const yytype_int16 yycheck[] =
{
      10,    14,    12,    55,    28,    29,    57,    15,    68,    54,
      20,     3,    22,    15,     7,    25,    26,    27,   120,    25,
      71,     3,    24,     4,    30,    27,    50,    87,    21,   131,
      38,    23,    56,     3,    16,    27,    46,    19,     5,    21,
      32,   101,     9,    15,    54,    69,    33,    34,   100,    41,
      42,    43,    31,    32,    21,    27,    35,    36,    37,    38,
      39,    40,    75,     0,   109,   125,     6,    27,   119,    25,
      10,    11,    12,     3,    30,    41,    42,    43,    10,    11,
      12,    28,    28,    30,    30,     3,    28,   111,    30,    27,
      31,    32,    26,     7,     3,     3,    29,    26,    22,   109,
      26,    24,    15,     7,    26,    26,    26,    17,    25,    20,
      15,    14,    28,    28,    13,     8,    18,    14,   130,    26,
     130,    78,    22,    82,    97,    26,    -1,    96,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    45,     3,     0,    27,     3,    46,    28,    30,
      26,     3,    47,    72,     7,    50,    72,    46,     5,     9,
      21,    51,    52,    56,    25,     3,     3,     3,    16,    19,
      56,    57,    58,    59,    60,    62,    72,    26,    47,    29,
       6,    10,    11,    12,    48,    49,    27,    53,    72,    53,
      15,    27,    61,    72,     3,    23,    27,    32,    41,    42,
      43,    64,    65,    66,    67,    71,    64,    22,    26,    24,
      56,    15,    26,     7,    54,    55,    72,    26,    25,    64,
      63,    64,    27,    61,    67,    64,    71,    17,    31,    32,
      35,    36,    37,    38,    39,    40,    68,    70,    33,    34,
      69,    20,    59,    72,    64,    71,    28,    46,    49,    14,
      28,    30,    63,    28,    59,    66,    65,    67,    59,    13,
      25,    26,    61,    64,    28,    18,    71,    48,    59,    14,
      26,     8,    54,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     1,     1,     8,     1,
       1,     1,     3,     1,     3,     6,     4,     3,     1,     4,
       6,     1,     1,     3,     1,     1,     1,     3,     3,     1,
       1,     6,     4,     1,     2,     4,     1,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     4,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 43 "0316050.y" /* yacc.c:1646  */
    {
			(yyval.node) = newNode(NODE_prog);
			struct node *temp = newNode(K_id);
			temp->string = strdup((yyvsp[-8].string));
			addChild((yyval.node),temp);//first child of "prog" is the name of program
			addChild((yyval.node),(yyvsp[-6].node));//second one is the parameter passed in the program
			addChild((yyval.node),(yyvsp[-3].node));//3rd child is declarations of global variable
			addChild((yyval.node),(yyvsp[-2].node));//4th child is declarations of subprogram
			addChild((yyval.node),(yyvsp[-1].node));//compound_statement: the variable in it may need classifying
			printf("reduce prog->PROGRAM PROGRAM id ( identifier_list ) ; declarations subprogram_declarations compound_statement .\n");
			semanticCheck((yyval.node));
		}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "0316050.y" /* yacc.c:1646  */
    {
		printf("reduce identifier_list->id\n");
		(yyval.node) = newNode(NODE_identifier_list);
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[0].string));
		addChild((yyval.node),temp);
	}
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "0316050.y" /* yacc.c:1646  */
    {
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[0].string));
		addChild((yyvsp[-2].node),temp);
		(yyval.node) = (yyvsp[-2].node);
		printf("reduce identifier_list-> identifier_list , id\n");
	}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "0316050.y" /* yacc.c:1646  */
    {//there are bugs here
		struct node *temp = newNode(NODE_declaration);//a "declaration" contains id_list and type,while "declarations" is  the parent of sets of declaration
		addChild(temp,(yyvsp[-3].node));//the first child of declaration is its id_list
		addChild(temp,(yyvsp[-1].node));//second one is its type
		if((yyvsp[-5].node)!=NULL){
			addChild((yyvsp[-5].node),temp);				
			(yyval.node) = (yyvsp[-5].node);                        
		}                                   
		else{
			(yyval.node) = newNode(NODE_declarations);
			addChild((yyval.node),temp);
		}
			
		printf("reduce declarations->declarations VAR identifier_list , type ;\n");
	}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_declarations);//this is declarataion with NULL child
		printf("reduce declarations->lambda\n");
	}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_type);
		switch((yyvsp[0].node)->nodeType){
			case K_INTEGER:
				(yyval.node)->tokenType = K_INTEGER;
			break;
			case K_REAL:
				(yyval.node)->tokenType = K_REAL;
			break;
			case K_STRING:
				(yyval.node)->tokenType = K_STRING;
			break;
		}
		(yyval.node)->arraydepth=0;
		(yyval.node)->ref = NULL;
		(yyval.node)->idxstart = 0;
		(yyval.node)->idxend   = 0;
		printf("reduce type->standard_type\n");
	}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 130 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_type);
		(yyval.node)->tokenType = (yyvsp[0].node)->tokenType;
		(yyval.node)->arraydepth= (yyvsp[0].node)->arraydepth + 1;
		(yyval.node)->idxstart = (yyvsp[-5].node);
		(yyval.node)->idxend = (yyvsp[-3].node);
		(yyval.node)->ref = (yyvsp[0].node);
		printf("reduce type->array [ num .. num ] of type \n");
	}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(K_INTEGER);
		printf("reduce standard_type->integer\n");
	}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(K_REAL);
		printf("reduce standard_type->real\n");
	}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 151 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(K_STRING);
		printf("reduce standard_type->string\n");
	}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "0316050.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].node) == NULL){
			(yyval.node) = newNode(NODE_subprogram_declarations);
			addChild((yyval.node),(yyvsp[-1].node));
		}
		else{
			addChild((yyvsp[-2].node),(yyvsp[-1].node));
			(yyval.node) = (yyvsp[-2].node);
		}
		printf("reduce subprogram_declarations->subprogram_declarations subprogram_declaration ;\n");
	}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 171 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_subprogram_declarations);
		printf("reduce subprogram_declarations->lamda\n");
	}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 180 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_subprogram_declaration);
		addChild((yyval.node),(yyvsp[-2].node));//the first child is subprogram_head;
		addChild((yyval.node),(yyvsp[-1].node));//second one is declaration
		addChild((yyval.node),(yyvsp[0].node));//third one is compound_statement, need to verify the semantics
		printf("reduce subprogram_declaration->subprogram_head declarations compound_statement\n");
	}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_subprogram_head);
		struct node *temp = newNode(K_id),*temp2 = newNode(NODE_type);
		temp2->tokenType = (yyvsp[-1].node)->nodeType;
		temp2->arraydepth=0;
		temp2->ref = NULL;
		temp2->idxstart = 0;
		temp2->idxend   = 0;
		temp->string = strdup((yyvsp[-4].string));
		addChild((yyval.node),temp);//first child is name of subprogram
		addChild((yyval.node),(yyvsp[-3].node));//second child is arguments
		addChild((yyval.node),temp2);//third one is type of subprogram
		printf("reduce subprogram_head->FUNCTION id arguments : standard_type ; \n");
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_subprogram_head);
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[-2].string));
		addChild((yyval.node),temp);//first child is name of subprogram
		addChild((yyval.node),(yyvsp[-1].node));//third child is arguments
		struct node *null_type = newNode(VALUE_INVALID);//should not be any type here!
		printf("reduce subprogram_head->PROCEDURE id arguments;\n");
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_arguments);
		addChild((yyval.node),(yyvsp[-1].node));//first child is parameter_list
		printf("reduce arguments->( parameter_list ) \n");
	}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_arguments);
		printf("reduce arguments->lambda\n");
	}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 241 "0316050.y" /* yacc.c:1646  */
    {
		struct node *temp = newNode(NODE_parameter_list_single);
		addChild(temp,(yyvsp[-2].node));//the first child of single list is id_list
		addChild(temp,(yyvsp[0].node));//the second one is type
		(yyval.node) = newNode(NODE_parameter_list);//parameter_list holds sets of single parameter_list
		addChild((yyval.node),temp);
		printf("reduce parameter_list->optional_var identifier_list : type\n");
	}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 254 "0316050.y" /* yacc.c:1646  */
    {
		struct node *temp = newNode(NODE_parameter_list_single);
		addChild(temp,(yyvsp[-4].node));
		addChild(temp,(yyvsp[-2].node));
		if((yyvsp[0].node)!=NULL){
			addChild((yyvsp[0].node),temp);
			(yyval.node) = (yyvsp[0].node);
		}
		else{
			(yyval.node) = newNode(NODE_parameter_list);
			addChild((yyval.node),temp);
		}
		printf("reduce parameter_list->optional_var identifier : type ; parameter_list\n");
	}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 271 "0316050.y" /* yacc.c:1646  */
    {
		printf("reduce optional_var->VAR\n");
	}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "0316050.y" /* yacc.c:1646  */
    {
		printf("reduce optional_val->lambda\n");
	}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 282 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_compound_statement);
		addChild((yyval.node),(yyvsp[-1].node));
		printf("reduce compound_statement->BEGIN optional_statements END\n");
	}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);//the content of optional_statements is just list of statement
		printf("reduce optional_statements->statement_list\n");
	}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 294 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement_list);//statement list with no content
		printf("reduce optional_statements->lambda\n");
	}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 302 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement_list);
		addChild((yyval.node),(yyvsp[0].node));
		printf("reduce statement_list->statement\n");
	}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 309 "0316050.y" /* yacc.c:1646  */
    {
		addChild((yyvsp[-2].node),(yyvsp[0].node));//the child of statement list is statement
		(yyval.node) = (yyvsp[-2].node);
		printf("reduce statement_list->statement';'statement\n");
	}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 319 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement);
		addChild((yyval.node),(yyvsp[-2].node));//first child of statement is variable to be assigned
		addChild((yyval.node),(yyvsp[0].node));//second one is expression
		printf("reduce statement->variable := expression\n");
	}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 325 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		printf("reduce statement->procedure_statement\n");
	}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 329 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		printf("reduce statement->compound_statement\n");
	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 338 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement_IF);
		addChild((yyval.node),(yyvsp[-4].node));//the first child of if statement is the expression of condition
		addChild((yyval.node),(yyvsp[-2].node));//the second one is statement of right condition
		addChild((yyval.node),(yyvsp[0].node));//third one is statement of worong condition
		printf("reduce statement->if expression then statement else statement\n"); 
	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 348 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement_WHILE);
		addChild((yyval.node),(yyvsp[-2].node));//the first child of if statement is the expression of condition
		addChild((yyval.node),(yyvsp[0].node));//the second one is statement of right condition
		printf("reduce statement->while expression do statement\n");
	}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 354 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_statement);//this is a node with no child
		printf("reduce statement->lambda\n");
	}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 363 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_variable);
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[-1].string));
		addChild((yyval.node),temp);//first child is the name of variable(mabe single one or array)
		addChild((yyval.node),(yyvsp[0].node));//second one is tail of variable(exist if it is an array)
		printf("reduce variable->id tail\n");
	}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 377 "0316050.y" /* yacc.c:1646  */
    {
		addChild((yyvsp[0].node),(yyvsp[-2].node));//here temp is the last
		(yyvsp[0].node)->child = (yyvsp[-2].node);//here make temp be the first child
		(yyval.node) = (yyvsp[0].node);
		// 12/14 A.M.02:13 expression should store the value to compute the value if it crosses the bound
		printf("reduce tail->[ expression ] tail\n");
	}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 384 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_tail);
		printf("reduce tail->lambda\n");
	}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 391 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_procedure_statement_single_id);
		struct node* temp = newNode(K_id);
		temp->string = strdup((yyvsp[0].string));
		addChild((yyval.node),temp);
		printf("reduce procedure_statement->id\n");
	}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 402 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_procedure_statement_parameter);
		struct node* temp = newNode(K_id);
		temp->string = strdup((yyvsp[-3].string));
		
		addChild((yyval.node),temp);
		
		addChild((yyval.node),(yyvsp[-1].node));
		
		printf("reduce procedure_statement->id (expression_list)\n");
	}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 416 "0316050.y" /* yacc.c:1646  */
    {
		
		(yyval.node) = newNode(NODE_expression_list);
		
		addChild((yyval.node),(yyvsp[0].node));
		
		printf("reduce expression_list->expression\n");
	}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 426 "0316050.y" /* yacc.c:1646  */
    {
		
		addChild((yyvsp[-2].node),(yyvsp[0].node));
		
		(yyval.node) = (yyvsp[-2].node);
		printf("reduce expression_list->expression_list , expression\n");
	}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 436 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_expression_single);//if the expression doesn't have relation operator that's simple expression
		addChild((yyval.node),(yyvsp[0].node));
		printf("reduce expression->simple_expression\n");
	}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 443 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_expression_multi);
		addChild((yyval.node),(yyvsp[-2].node));//the first operend
		addChild((yyval.node),(yyvsp[-1].node));//the relation operator
		addChild((yyval.node),(yyvsp[0].node));//the second operend
		printf("reduce->simple_expression relop simple_expression\n");
	}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 453 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_simple_expression_single);
		addChild((yyval.node),(yyvsp[0].node));
		printf("reduce simple_expression->term\n");
	}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 460 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_simple_expression_multi);
		addChild((yyval.node),(yyvsp[-2].node));//the first operend
		addChild((yyval.node),(yyvsp[-1].node));//the addition or substraction operator
		addChild((yyval.node),(yyvsp[0].node));//the second operend
		printf("reduce simple_expression-> simple_expression addop term\n");
	}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 469 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_term_single);
		addChild((yyval.node),(yyvsp[0].node));
		printf("reduce term->factor\n");
	}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 476 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_term_multi);
		addChild((yyval.node),(yyvsp[-2].node));//the first operend
		addChild((yyval.node),(yyvsp[-1].node));//the mulitiplication or division operator
		addChild((yyval.node),(yyvsp[0].node));//the second operend
		printf("reduce term->term mulop factor\n");
	}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 487 "0316050.y" /* yacc.c:1646  */
    {
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[-1].string));
		(yyval.node) = newNode(NODE_factor_tail);
		addChild((yyval.node),temp);//first child is variable called
		addChild((yyval.node),(yyvsp[0].node));//second is tail(for array);
		printf("reduce factor->ID tail\n");
	}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 498 "0316050.y" /* yacc.c:1646  */
    {
		struct node *temp = newNode(K_id);
		temp->string = strdup((yyvsp[-3].string));
		(yyval.node) = newNode(NODE_factor_expression_list);//maybe the function call in an expression
		addChild((yyval.node),temp);
		addChild((yyval.node),(yyvsp[-1].node));
		printf("reduce factor->id (expression_list)\n");
	}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 506 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_factor_NUM);
		addChild((yyval.node),(yyvsp[0].node));
		printf("reduce factor->NUM\n");
	}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 511 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_factor_NUM);
		addChild((yyval.node),(yyvsp[-1].string));
		printf("reduce factor->'-'NUM\n");
	}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 518 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_factor_factor);
		addChild((yyval.node),(yyvsp[-1].node));
		printf("reduce factor->(expression_list)\n");
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 524 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_factor_not);//this factor is inverted
		addChild((yyval.node),(yyvsp[0].node));//only store the factor below
		printf("reduce factor->not factor\n");
	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 532 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_addop);
		(yyval.node)->string = "+";
		printf("reduce addop->+\n");
	}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 537 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_addop);
		(yyval.node)->string = "-";
		printf("reduce addop->-\n");
	}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 544 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_mulop);
		(yyval.node)->string = "*";
		printf("reduce mulop->*\n");
	}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 549 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_mulop);
		(yyval.node)->string = "/";
		printf("reduce mulop->/\n");
	}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 557 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = "<";
		printf("reduce relop-><\n");
	}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 562 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = ">";
		printf("reduce relop->>\n");
	}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 567 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = "=";
		printf("reduce relop->=\n");
	}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 572 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = "<=";
		printf("reduce relop-><=\n");
	}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 577 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = ">=";
		printf("reduce relop->>=\n");
	}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 582 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_relop);
		(yyval.node)->string = "!=";
		printf("reduce relop->!=\n");
	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 588 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NUM_INT);
		(yyval.node)->iValue = (yyvsp[0].int_val);
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 592 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NUM_STRING);
		(yyval.node)->string = strdup((yyvsp[0].string));
	}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 596 "0316050.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NUM_REAL);
		(yyval.node)->rValue = (yyvsp[0].real_val);
	}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2124 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 601 "0316050.y" /* yacc.c:1906  */

int yyerror( char *msg )
{
  fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d:\n", line_no);
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
  fprintf( stderr, "|--------------------------------------------------------------------------\n" );
  exit(-1);
}

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}


