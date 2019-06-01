/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "ast_yacc.y"

#include <stdlib.h>
#include "ast.h"
#include "yacc.h"

#define MAXSTR 20
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1

int yyerror(char*);

// define in ast.c
extern struct node root;
extern struct node *tmprtn;

extern int yylex();
extern FILE* yyin;
extern char str1[20];

extern int NXQ;
extern int VarCount;
extern struct QUATERLIST QuaterList[MAXMEMBER];
extern struct VARLIST VarList[MAXMEMBER];
int ef = 1;
int flag_var_def = 0;

/* Line 371 of yacc.c  */
#line 97 "ast_yacc.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "ast_yacc.tab.h".  */
#ifndef YY_YY_AST_YACC_TAB_H_INCLUDED
# define YY_YY_AST_YACC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Iden = 300,
     IntNo = 301,
     RealNo = 302,
     Program = 400,
     Begin = 401,
     End = 402,
     Var = 403,
     Integer = 404,
     Real = 405,
     While = 406,
     Do = 407,
     If = 408,
     Then = 409,
     Else = 410,
     Or = 411,
     And = 412,
     Not = 413,
     Array = 414,
     Of = 415,
     For = 416,
     To = 417,
     LE = 500,
     GE = 501,
     NE = 502,
     DD = 503,
     UMINUS = 505
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 31 "ast_yacc.y"

 struct {
	 union{
		 int Iv;
		 int CH;
		 int NO;
		 struct { int TC,FC;} _BExpr;
		 struct { int QUAD,CH;} _WBD;
		 struct { int type,place; union{int Iv;float Rv;} Value;} _Expr;
		 char _Rop[5];
		 int First;	//连续定义时，符号链的头指针（在符号表中的序号）
		 /*
		  *var是简单变量时，place:变量在符号表中的序号；offset:0
		  *var是下标变量时，place:存放constpart临时变量地址（在表中的序号），offset:存放varpart临时变量地址（在表中的序号）
		  */
		 struct { int PLACE, OFFSET;} _Var;
		 /*
		  *NO：数组名在符号表中的序号
		  *DIM：用于记录已处理数组下标表达式的个数（最后值代表维数）
		  *place:在计算varpart时，记录存放中间结果的临时变量名（地址）
		  */ 
		 struct { int NO, DIM, PLACE;} _Elist;
		 struct { int QUAD,CH,place;} _Loop;
	 } attr;
 	struct node *Node;
 } all;
 char str[20];


/* Line 387 of yacc.c  */
#line 198 "ast_yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_AST_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 226 "ast_yacc.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   505

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    33,    31,    39,    32,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    36,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    42,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    26,    27,     2,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    14,    18,    22,    24,    28,
      31,    33,    35,    39,    41,    44,    46,    49,    51,    54,
      57,    60,    62,    66,    67,    71,    76,    80,    84,    88,
      90,    94,    98,   102,   106,   110,   113,   115,   117,   121,
     124,   127,   130,   134,   136,   139,   141,   143,   145,   147,
     149,   151,   153,   155,   159,   167,   173,   177,   180,   184
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,     6,     3,    46,    36,    47,    37,
      -1,    48,    56,    -1,     9,    49,    36,    -1,    49,    36,
      50,    -1,    50,    -1,    52,    38,    51,    -1,    67,    51,
      -1,    10,    -1,    11,    -1,    52,    39,    64,    -1,    64,
      -1,    54,    55,    -1,    55,    -1,    53,    36,    -1,    57,
      -1,    58,    55,    -1,    59,    55,    -1,    60,    55,    -1,
      56,    -1,    69,    13,    55,    -1,    -1,     7,    53,     8,
      -1,    64,    38,    30,    62,    -1,    59,    55,    16,    -1,
      14,    63,    15,    -1,    61,    63,    13,    -1,    12,    -1,
      62,    31,    62,    -1,    62,    32,    62,    -1,    62,    33,
      62,    -1,    62,    34,    62,    -1,    40,    62,    41,    -1,
      32,    62,    -1,    64,    -1,    65,    -1,    62,    66,    62,
      -1,    63,    18,    -1,    63,    17,    -1,    19,    63,    -1,
      40,    63,    41,    -1,     3,    -1,    71,    42,    -1,     4,
      -1,     5,    -1,    28,    -1,    29,    -1,    30,    -1,    25,
      -1,    26,    -1,    24,    -1,    68,    42,    21,    -1,    52,
      38,    20,    43,    65,    27,    65,    -1,    68,    39,    65,
      27,    65,    -1,    70,    23,    62,    -1,    22,    57,    -1,
      64,    43,    62,    -1,    71,    39,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   128,   139,   148,   157,   164,   170,   190,
     212,   222,   232,   245,   255,   264,   272,   280,   287,   295,
     303,   313,   320,   336,   339,   349,   371,   386,   398,   411,
     421,   433,   445,   457,   469,   476,   487,   507,   522,   535,
     539,   543,   553,   561,   577,   592,   605,   617,   623,   627,
     631,   635,   639,   645,   651,   666,   681,   700,   713,   720
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Iden", "IntNo", "RealNo", "Program",
  "Begin", "End", "Var", "Integer", "Real", "While", "Do", "If", "Then",
  "Else", "Or", "And", "Not", "Array", "Of", "For", "To", "LE", "GE", "NE",
  "DD", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "UMINUS", "';'",
  "'.'", "':'", "','", "'('", "')'", "']'", "'['", "$accept", "ProgDef",
  "$@1", "SubProg", "VarDef", "VarDefList", "VarDefState", "Type",
  "VarList", "StateList", "S_L", "Statement", "CompState", "AsignState",
  "ISE", "IBT", "WBD", "Wh", "Expr", "BoolExpr", "Variable", "Const",
  "RelationOp", "ArrayVar", "ArrayMSG", "ForLoop2", "ForLoop1", "ExprList", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   504,   300,   301,   302,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   500,   501,   502,   503,    60,    62,
      61,    43,    45,    42,    47,   505,    59,    46,    58,    44,
      40,    41,    93,    91
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    57,    58,    59,    60,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    68,    68,    69,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     3,     3,     1,     3,     2,
       1,     1,     3,     1,     2,     1,     2,     1,     2,     2,
       2,     1,     3,     0,     3,     4,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     2,     1,     1,     3,     2,
       2,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     7,     5,     3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     0,     0,     0,
      43,     0,     7,     0,    13,     0,     0,     0,     3,    23,
       4,     5,     0,     0,     0,    10,    11,     9,     0,     0,
       0,    44,    29,     0,     0,     0,    23,    15,    21,    17,
      23,    23,    23,     0,     0,     0,     0,     6,     0,     8,
      12,    45,    46,     0,     0,    58,    36,    37,     0,    53,
      59,     0,     0,     0,     0,    57,    24,    16,    14,    18,
      19,    20,     0,     0,    23,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    41,     0,     0,    52,    50,    51,
      47,    48,    49,     0,    27,    40,    39,    26,    28,     0,
      22,    56,     0,    34,    30,    31,    32,    33,    55,    42,
      38,    25,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     8,     9,    11,    12,    27,    13,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    63,    64,
      56,    57,    93,    15,    16,    45,    46,    17
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -35
static const yytype_int8 yypact[] =
{
      -4,    10,    46,   -35,   -35,    18,    64,    58,    41,    91,
     -35,    80,   -35,    42,    45,    72,    -6,    35,   -35,    57,
     -35,    58,    52,    58,    13,   -35,   -35,   -35,    92,    96,
      13,   -35,   -35,     0,    58,    15,    57,   -35,   -35,   -35,
      57,    57,    57,     0,    -9,   105,    98,   -35,    76,   -35,
      45,   -35,   -35,    13,    13,    34,    45,   -35,    95,   -35,
      34,     0,     0,    75,    32,   -35,   -35,   -35,   -35,   -35,
     107,   -35,     8,    94,    57,    13,    92,   -35,    79,    13,
      13,    13,    13,    92,   -35,    61,    -3,   -35,   -35,   -35,
     -35,   -35,   -35,    13,   -35,   -35,   -35,   -35,   -35,    13,
     -35,    34,    99,   -35,    81,    81,   -35,   -35,   -35,   -35,
      34,    34,    92,   -35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,   -35,   -35,   -35,   104,   106,   -35,   -35,
     -35,   -30,   118,    97,   -35,   -35,   -35,   -35,   -23,   -34,
       1,   -28,   -35,   -35,   -35,   -35,   -35,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      58,    55,     1,    10,    51,    52,    68,    60,    14,    72,
      69,    70,    71,     3,    95,    96,    10,    51,    52,    61,
      44,    98,    14,    66,    50,    95,    96,    84,    86,    73,
      77,    78,    53,    28,    24,    44,    29,    44,   109,    85,
      62,    44,    44,    44,   100,    53,     4,    94,   102,    95,
      96,    67,   101,    54,     6,   108,   104,   105,   106,   107,
      10,    10,    25,    26,    19,    79,    80,    81,    82,    32,
     110,    33,    48,     7,    30,    44,   111,    31,    18,    34,
      22,    23,    25,    26,   113,    87,    88,    89,    24,    90,
      91,    92,    79,    80,    81,    82,    51,    52,    19,    87,
      88,    89,   103,    90,    91,    92,    79,    80,    81,    82,
      79,    80,    81,    82,    81,    82,    21,    59,    74,    76,
     103,    75,    83,    97,    99,    47,   112,    20,    49,     0,
       0,    65
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      28,    24,     6,     3,     4,     5,    36,    30,     7,    43,
      40,    41,    42,     3,    17,    18,     3,     4,     5,    19,
      19,    13,    21,     8,    23,    17,    18,    61,    62,    38,
      53,    54,    32,    39,    43,    34,    42,    36,    41,    62,
      40,    40,    41,    42,    74,    32,     0,    15,    76,    17,
      18,    36,    75,    40,    36,    83,    79,    80,    81,    82,
       3,     3,    10,    11,     7,    31,    32,    33,    34,    12,
      93,    14,    20,     9,    39,    74,    99,    42,    37,    22,
      38,    39,    10,    11,   112,    24,    25,    26,    43,    28,
      29,    30,    31,    32,    33,    34,     4,     5,     7,    24,
      25,    26,    41,    28,    29,    30,    31,    32,    33,    34,
      31,    32,    33,    34,    33,    34,    36,    21,    13,    43,
      41,    23,    27,    16,    30,    21,    27,     9,    22,    -1,
      -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    45,     3,     0,    46,    36,     9,    47,    48,
       3,    49,    50,    52,    64,    67,    68,    71,    37,     7,
      56,    36,    38,    39,    43,    10,    11,    51,    39,    42,
      39,    42,    12,    14,    22,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    64,    69,    70,    50,    20,    51,
      64,     4,     5,    32,    40,    62,    64,    65,    65,    21,
      62,    19,    40,    62,    63,    57,     8,    36,    55,    55,
      55,    55,    63,    38,    13,    23,    43,    62,    62,    31,
      32,    33,    34,    27,    63,    62,    63,    24,    25,    26,
      28,    29,    30,    66,    15,    17,    18,    16,    13,    30,
      55,    62,    65,    41,    62,    62,    62,    62,    65,    41,
      62,    62,    27,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 128 "ast_yacc.y"
    {set_node_val_str(&root,str1);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 129 "ast_yacc.y"
    {
		      struct node *tmpnode=NULL;
              //printf("\n\n**** test ast node ****\n\n");
			  (yyval.all).Node=&root;
			  (yyval.all).Node->type=e_program;
			  tmpnode=(yyvsp[(5) - (6)].all).Node;
			  add_son_node(&root,(yyvsp[(5) - (6)].all).Node);
			  printf("\n\n**** Program %s ****\n",root.val.str);
          }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 140 "ast_yacc.y"
    {
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_sub_prog;
		set_node_val_str((yyval.all).Node, "SubProg");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (2)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(2) - (2)].all).Node);
		}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 149 "ast_yacc.y"
    {
		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_var_def;
		set_node_val_str((yyval.all).Node, "Var");
		add_son_node((yyval.all).Node, (yyvsp[(2) - (3)].all).Node);
		}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 158 "ast_yacc.y"
    {
		/* =========================== */
		struct node *last = get_last_node((yyvsp[(1) - (3)].all).Node);
		add_brother_node(last, (yyvsp[(3) - (3)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (3)].all).Node;
		}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 165 "ast_yacc.y"
    {
		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
        }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 171 "ast_yacc.y"
    {

		int check = 0;
		while ((yyvsp[(1) - (3)].all).attr.First) {
			VarList[(yyvsp[(1) - (3)].all).attr.First].type = (yyvsp[(3) - (3)].all).attr.Iv;
			(yyvsp[(1) - (3)].all).attr.First = VarList[(yyvsp[(1) - (3)].all).attr.First].addr;

			if(check++ > MAXMEMBER) {
				printf("** overdefine variable **\n");
				exit(0);
			}
		}

		/* =========================== */
		struct node *last = get_last_node((yyvsp[(1) - (3)].all).Node);
		add_brother_node(last, (yyvsp[(3) - (3)].all).Node);
		(yyvsp[(1) - (3)].all).Node->type = e_varlist;
		(yyval.all).Node = (yyvsp[(1) - (3)].all).Node;
		}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 191 "ast_yacc.y"
    {
		int check = 0;
		int NO = (yyvsp[(1) - (2)].all).attr.NO;

		if ((yyvsp[(2) - (2)].all).attr.Iv == 1) {
			(yyvsp[(2) - (2)].all).attr.Iv = 2;//real array
		} else {
			(yyvsp[(2) - (2)].all).attr.Iv = 3;//int array
		}

		while (NO) {
			VarList[NO].type = (yyvsp[(2) - (2)].all).attr.Iv;
			NO = VarList[NO].addr;

			if(check++ > MAXMEMBER) {
				printf("** overdefine variable **\n");
				exit(0);
			}
		}
		}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 213 "ast_yacc.y"
    {
		//Type <Iv> <int>
		(yyval.all).attr.Iv = 0;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_type_int;
		set_node_val_str((yyval.all).Node, "Integer");
		}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 223 "ast_yacc.y"
    {
		(yyval.all).attr.Iv = 1;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_type_real;
		set_node_val_str((yyval.all).Node, "Real");
		}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 233 "ast_yacc.y"
    {
		// VarList <First> <int>

		(yyval.all).attr.First = (yyvsp[(3) - (3)].all).attr._Var.PLACE;
		VarList[(yyvsp[(3) - (3)].all).attr._Var.PLACE].addr = (yyvsp[(1) - (3)].all).attr.First;


		/* =========================== */
		struct node *last = get_last_node((yyvsp[(1) - (3)].all).Node);
		add_brother_node(last, (yyvsp[(3) - (3)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (3)].all).Node;
		}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 246 "ast_yacc.y"
    {
		(yyval.all).attr.First = (yyvsp[(1) - (1)].all).attr._Var.PLACE;
		VarList[(yyvsp[(1) - (1)].all).attr._Var.PLACE].addr = 0;


		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
		}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 256 "ast_yacc.y"
    {
		(yyval.all).attr.CH = (yyvsp[(2) - (2)].all).attr.CH;

		/* =========================== */
		struct node *last = get_last_node((yyvsp[(1) - (2)].all).Node);
		add_brother_node(last, (yyvsp[(2) - (2)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (2)].all).Node;
		}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 265 "ast_yacc.y"
    {
		(yyval.all).attr.CH = (yyvsp[(1) - (1)].all).attr.CH;

		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
		}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 273 "ast_yacc.y"
    {
		backPatch((yyvsp[(1) - (2)].all).attr.CH, NXQ);

		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (2)].all).Node;
		}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 281 "ast_yacc.y"
    {
		(yyval.all).attr.CH = 0;

		/* =========================== */
		(yyval.all).Node = (yyval.all).Node;
		}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 288 "ast_yacc.y"
    {
		(yyval.all).attr.CH = merge((yyvsp[(1) - (2)].all).attr.CH, (yyvsp[(2) - (2)].all).attr.CH);

		/* =========================== */
		add_son_node((yyvsp[(1) - (2)].all).Node, (yyvsp[(2) - (2)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (2)].all).Node;
		}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 296 "ast_yacc.y"
    {
		(yyval.all).attr.CH = merge((yyvsp[(1) - (2)].all).attr.CH, (yyvsp[(2) - (2)].all).attr.CH);

		/* =========================== */
		add_son_node((yyvsp[(1) - (2)].all).Node, (yyvsp[(2) - (2)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (2)].all).Node;
		}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 304 "ast_yacc.y"
    {
		backPatch((yyvsp[(2) - (2)].all).attr.CH, (yyvsp[(1) - (2)].all).attr._WBD.QUAD);
		gen("j", 0, 0, (yyvsp[(1) - (2)].all).attr._WBD.QUAD);
		(yyval.all).attr.CH = (yyvsp[(1) - (2)].all).attr._WBD.CH;

		/* =========================== */
		add_son_node((yyvsp[(1) - (2)].all).Node, (yyvsp[(2) - (2)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (2)].all).Node;
		}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 314 "ast_yacc.y"
    {
		(yyval.all).attr.CH = (yyvsp[(1) - (1)].all).attr.CH;

		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
		}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 321 "ast_yacc.y"
    {
			backPatch((yyvsp[(3) - (3)].all).attr.CH,NXQ);
			gen("+",(yyvsp[(1) - (3)].all).attr._Loop.place,entry("1"),(yyvsp[(1) - (3)].all).attr._Loop.place);
			gen("j",0,0,(yyvsp[(1) - (3)].all).attr._Loop.QUAD);
			(yyval.all).attr.CH=(yyvsp[(1) - (3)].all).attr._Loop.CH;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_for_stat;
		set_node_val_str((yyval.all).Node, "for_loop_do");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);

		}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 336 "ast_yacc.y"
    {
	    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 340 "ast_yacc.y"
    {
		(yyval.all).attr.CH = (yyvsp[(2) - (3)].all).attr.CH;

		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_compstat;
		set_node_val_str((yyval.all).Node, "begin_end");
		add_son_node((yyval.all).Node, (yyvsp[(2) - (3)].all).Node);
		}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 350 "ast_yacc.y"
    {
		if (!(yyvsp[(1) - (4)].all).attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
			gen(":=", (yyvsp[(4) - (4)].all).attr._Expr.place, 0, (yyvsp[(1) - (4)].all).attr._Var.PLACE);
		} else {  /*OFFSET不为0，下标变量*/ 
			gen("[]=", (yyvsp[(4) - (4)].all).attr._Expr.place, 0, (yyvsp[(1) - (4)].all).attr._Var.PLACE);
		}
		(yyval.all).attr.CH =(yyvsp[(1) - (4)].all).attr._Var.PLACE;

		if (flag_var_def == 0) {
			printf("** undefined variable %s **", VarList[(yyvsp[(1) - (4)].all).attr._Var.PLACE].name);
			exit(0);
		}
		
		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_assign_stat;
		set_node_val_str((yyval.all).Node, ":=");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (4)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(4) - (4)].all).Node);
		}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 372 "ast_yacc.y"
    {
		int q = NXQ;
		gen("j", 0, 0, 0);
		backPatch((yyvsp[(1) - (3)].all).attr.CH, NXQ); // right now, NXQ = q + 1
		(yyval.all).attr.CH = merge((yyvsp[(2) - (3)].all).attr.CH, q);

		/* =========================== */
		new_node(&((yyval.all).Node));  
		(yyval.all).Node->type = e_if_then_else_stat;
		set_node_val_str((yyval.all).Node, "if_then_else");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(2) - (3)].all).Node);
		}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 387 "ast_yacc.y"
    {
		backPatch((yyvsp[(2) - (3)].all).attr._BExpr.TC, NXQ); (yyval.all).attr.CH = (yyvsp[(2) - (3)].all).attr._BExpr.FC;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_if_then_stat;
		set_node_val_str((yyval.all).Node, "if_then");
		add_son_node((yyval.all).Node, (yyvsp[(2) - (3)].all).Node);
		}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 399 "ast_yacc.y"
    {
		// WBD <_WBD> <QUAD, CH>

		backPatch((yyvsp[(2) - (3)].all).attr._BExpr.TC, NXQ);
		(yyval.all).attr._WBD.CH = (yyvsp[(2) - (3)].all).attr._BExpr.FC;
		(yyval.all).attr._WBD.QUAD = (yyvsp[(1) - (3)].all).attr.CH;

		/* =========================== */
		add_son_node((yyvsp[(1) - (3)].all).Node, (yyvsp[(2) - (3)].all).Node);
		(yyval.all).Node = (yyvsp[(1) - (3)].all).Node;
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 412 "ast_yacc.y"
    {
		(yyval.all).attr.CH = NXQ;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_while_stat;
		set_node_val_str((yyval.all).Node, "while");
        }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 422 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = newTemp();
		gen("+", (yyvsp[(1) - (3)].all).attr._Expr.place, (yyvsp[(3) - (3)].all).attr._Expr.place, (yyval.all).attr._Expr.place);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_exp;
		set_node_val_str((yyval.all).Node, "+");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 434 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = newTemp();
		gen("-", (yyvsp[(1) - (3)].all).attr._Expr.place, (yyvsp[(3) - (3)].all).attr._Expr.place, (yyval.all).attr._Expr.place);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_exp;
		set_node_val_str((yyval.all).Node, "-");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 446 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = newTemp();
		gen("*", (yyvsp[(1) - (3)].all).attr._Expr.place, (yyvsp[(3) - (3)].all).attr._Expr.place, (yyval.all).attr._Expr.place);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_exp;
		set_node_val_str((yyval.all).Node, "*");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 458 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = newTemp();
		gen("/", (yyvsp[(1) - (3)].all).attr._Expr.place, (yyvsp[(3) - (3)].all).attr._Expr.place, (yyval.all).attr._Expr.place);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_exp;
		set_node_val_str((yyval.all).Node, "/");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 470 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = (yyvsp[(2) - (3)].all).attr._Expr.place;

		/* =========================== */
		(yyval.all).Node = (yyvsp[(2) - (3)].all).Node;
		}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 477 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.place = newTemp();
		gen("-", (yyvsp[(2) - (2)].all).attr._Expr.place, 0, (yyval.all).attr._Expr.place);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_exp;
		set_node_val_str((yyval.all).Node, "-");
		add_son_node((yyval.all).Node, (yyvsp[(2) - (2)].all).Node);
		}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 488 "ast_yacc.y"
    {
		if (!(yyvsp[(1) - (1)].all).attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
			(yyval.all).attr._Expr.place = (yyvsp[(1) - (1)].all).attr._Var.PLACE;
		} else {  /*OFFSET不为0，下标变量*/ 
			int T = newTemp();
			gen("=[]", (yyvsp[(1) - (1)].all).attr._Var.PLACE, 0, T);	//T=C[V]
			(yyval.all).attr._Expr.place = T;
		}

		// undefined error
		if (flag_var_def == 0) {
			printf("** undefined variable %s **", VarList[(yyvsp[(1) - (1)].all).attr._Var.PLACE].name);
			exit(0);
		}

		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
		}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 508 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.type = (yyvsp[(1) - (1)].all).attr._Expr.type;
		(yyval.all).attr._Expr.place = (yyvsp[(1) - (1)].all).attr._Expr.place;
		if ((yyval.all).attr._Expr.type) {
			(yyval.all).attr._Expr.Value.Rv = (yyvsp[(1) - (1)].all).attr._Expr.Value.Rv;
		} else {
			(yyval.all).attr._Expr.Value.Iv = (yyvsp[(1) - (1)].all).attr._Expr.Value.Iv;
		}

		/* =========================== */
		(yyval.all).Node = (yyvsp[(1) - (1)].all).Node;
		}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 523 "ast_yacc.y"
    {
		(yyval.all).attr._BExpr.TC = NXQ; (yyval.all).attr._BExpr.FC = NXQ + 1;
		gen((yyvsp[(2) - (3)].all).attr._Rop, (yyvsp[(1) - (3)].all).attr._Expr.place, (yyvsp[(3) - (3)].all).attr._Expr.place, 0);
		gen("j", 0, 0, 0); 

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_bool_exp;
		set_node_val_str((yyval.all).Node, &((yyvsp[(2) - (3)].all).attr._Rop[1]));
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 536 "ast_yacc.y"
    {
		backPatch((yyvsp[(1) - (2)].all).attr._BExpr.TC, NXQ); (yyval.all).attr._BExpr.FC = (yyvsp[(1) - (2)].all).attr._BExpr.FC;
		}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 540 "ast_yacc.y"
    {
		backPatch((yyvsp[(1) - (2)].all).attr._BExpr.FC, NXQ); (yyval.all).attr._BExpr.TC = (yyvsp[(1) - (2)].all).attr._BExpr.TC;
		}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 544 "ast_yacc.y"
    {
		(yyval.all).attr._BExpr.TC = (yyvsp[(2) - (2)].all).attr._BExpr.FC; (yyval.all).attr._BExpr.FC = (yyvsp[(2) - (2)].all).attr._BExpr.TC;

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_bool_exp;
		set_node_val_str((yyval.all).Node, "Not");
		add_son_node((yyval.all).Node, (yyvsp[(2) - (2)].all).Node);
		}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 554 "ast_yacc.y"
    {
		(yyval.all).attr._BExpr.TC = (yyvsp[(2) - (3)].all).attr._BExpr.TC; (yyval.all).attr._BExpr.FC = (yyvsp[(2) - (3)].all).attr._BExpr.FC;

		/* =========================== */
		(yyval.all).Node = (yyvsp[(2) - (3)].all).Node;
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 562 "ast_yacc.y"
    {
		//Variable <NO> <int>
		if (lookUp(str1)) {
			flag_var_def = 1;
		} else {
			flag_var_def = 0;
		}
		(yyval.all).attr._Var.PLACE = entry(str1); 
		(yyval.all).attr._Var.OFFSET = 0;
		

		/* =========================== */
		new_node(&((yyval.all).Node));
		set_node_val_str((yyval.all).Node, str1);
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 578 "ast_yacc.y"
    {
			char Cstr[10], astr[10] = "ArrPtr";
			int C,a;
			int T = newTemp();
			C = Access_C((yyvsp[(1) - (2)].all).attr._Elist.NO);
			a = Access_a((yyvsp[(1) - (2)].all).attr._Elist.NO);

			sprintf(Cstr, "%d", C);
			sprintf(astr, "%d", a);
			gen("-", entry(astr), entry(Cstr),T); /*产生a-C的代码，结果存于T*/ 
			(yyval.all).attr._Elist.PLACE = T; /*CONSTPART*/
			(yyval.all).attr._Var.OFFSET = (yyvsp[(1) - (2)].all).attr._Elist.PLACE;/*VARPART*/
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 593 "ast_yacc.y"
    {
		//Const <_Expr> <int, int , int/float>

		(yyval.all).attr._Expr.type = 0;
		(yyval.all).attr._Expr.place = entry(str1);
		VarList[(yyval.all).attr._Expr.place].type = 0;
		(yyval.all).attr._Expr.Value.Iv = atoi(str1);

		/* =========================== */
		new_node(&((yyval.all).Node));
		set_node_val_str((yyval.all).Node, str1);
		}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 606 "ast_yacc.y"
    {
		(yyval.all).attr._Expr.type = 1;
		(yyval.all).attr._Expr.place = entry(str1);
		VarList[(yyval.all).attr._Expr.place].type = 1;
		(yyval.all).attr._Expr.Value.Rv = (float)atof(str1);
		
		/* =========================== */
		new_node(&((yyval.all).Node));
		set_node_val_str((yyval.all).Node, str1);
		}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 618 "ast_yacc.y"
    {
		//RelationOp <_Rop> <char [5]>
		
		strcpy((yyval.all).attr._Rop, "j<");
		}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 624 "ast_yacc.y"
    {
		strcpy((yyval.all).attr._Rop, "j>");
		}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 628 "ast_yacc.y"
    {
		strcpy((yyval.all).attr._Rop, "j=");
		}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 632 "ast_yacc.y"
    {
		strcpy((yyval.all).attr._Rop, "j>=");
		}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 636 "ast_yacc.y"
    {
		strcpy((yyval.all).attr._Rop, "j!=");
		}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 640 "ast_yacc.y"
    {
		strcpy((yyval.all).attr._Rop, "j<=");
		}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 646 "ast_yacc.y"
    {
			(yyval.all).attr.NO = (yyvsp[(1) - (3)].all).attr.NO;
			FillArrMSG_C((yyval.all).attr.NO);   
		}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 652 "ast_yacc.y"
    {
			//一维数组情形
			// ArrayMSG <NO> <int>
			int NO = (yyval.all).attr.NO;
			int low = (yyvsp[(5) - (7)].all).attr._Expr.Value.Iv, high = (yyvsp[(7) - (7)].all).attr._Expr.Value.Iv;
			(yyval.all).attr.NO = (yyvsp[(1) - (7)].all).attr.First;	//连续定义的情形
			//内情向量表的构造
			VarList[NO].ADDR = malloc(sizeof(struct arr_info));
			VarList[NO].ADDR->DIM = 1;
			VarList[NO].ADDR->Vector = malloc(5*sizeof(int));		
			VarList[NO].ADDR->Vector[2] = low;
			VarList[NO].ADDR->Vector[3] = high;
			VarList[NO].ADDR->Vector[4] = (high - low) + 1;
		}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 667 "ast_yacc.y"
    {
			//多维数组情形
			int NO = (yyvsp[(1) - (5)].all).attr.NO;
			int dim = VarList[NO].ADDR->DIM+1;
			int low = (yyvsp[(3) - (5)].all).attr._Expr.Value.Iv, high = (yyvsp[(5) - (5)].all).attr._Expr.Value.Iv;
			(yyval.all).attr.NO = NO;

			VarList[NO].ADDR->DIM++;
			VarList[NO].ADDR->Vector = realloc(VarList[NO].ADDR->Vector, (3 * dim + 2) * sizeof(int));
			VarList[NO].ADDR->Vector[3*dim - 1] = low;
			VarList[NO].ADDR->Vector[3*dim] = high;
			VarList[NO].ADDR->Vector[3*dim + 1] = (high - low) + 1;
		}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 682 "ast_yacc.y"
    {
			int p = NXQ;
			(yyval.all).attr._Loop.QUAD = NXQ;	//传递循环返回点信息
			gen("j<=", (yyvsp[(1) - (3)].all).attr._Loop.place,(yyvsp[(3) - (3)].all).attr._Expr.place,p+2); 	//判断循环是否继续
			(yyval.all).attr._Loop.place = (yyvsp[(1) - (3)].all).attr._Loop.place;	//iden在表中的序号
			(yyval.all).attr._Loop.CH = NXQ;		//循环语句的出口
			gen("j",0,0,0);

		/* =========================== */
		new_node(&((yyval.all).Node));
		(yyval.all).Node->type = e_for_stat;
		set_node_val_str((yyval.all).Node, "to");
		add_son_node((yyval.all).Node, (yyvsp[(1) - (3)].all).Node);
		add_son_node((yyval.all).Node, (yyvsp[(3) - (3)].all).Node);

		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 701 "ast_yacc.y"
    {
			(yyval.all).attr._Loop.place = (yyvsp[(2) - (2)].all).attr.CH;

		/* =========================== */
		//new_node(&($$.Node));
		//$$.Node->type = e_for_stat;
		//set_node_val_str($$.Node, "");
		//add_son_node($$.Node, $2.Node);
		(yyval.all).Node=(yyvsp[(2) - (2)].all).Node;
		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 714 "ast_yacc.y"
    {
			//ExprList
			(yyval.all).attr._Elist.PLACE = (yyvsp[(3) - (3)].all).attr._Expr.place;	//相当于VARPART=i1
			(yyval.all).attr._Elist.DIM = 1;
			(yyval.all).attr._Elist.NO = (yyvsp[(1) - (3)].all).attr._Var.PLACE;
		}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 721 "ast_yacc.y"
    {
			char num[5];
			int k,d;
			int T = newTemp();
			k = (yyvsp[(1) - (3)].all).attr._Elist.DIM + 1;
			d = Access_d((yyvsp[(1) - (3)].all).attr._Elist.NO, k);
			sprintf(num, "%d", d);	//将d转化为字符形式，结果存在num
			gen("*", (yyvsp[(1) - (3)].all).attr._Elist.PLACE, entry(num), T);
			gen("+", (yyvsp[(3) - (3)].all).attr._Expr.place, T, T); /*相当于VARPART=VARPART*d+ik*/ 
			(yyval.all).attr._Elist.NO = (yyvsp[(1) - (3)].all).attr._Elist.NO;;/*传递Entry(iden)*/ 
			(yyval.all).attr._Elist.PLACE = T;/*传递存放VARPART中间结果的T*/ 
			(yyval.all).attr._Elist.DIM = k;
		}
    break;


/* Line 1792 of yacc.c  */
#line 2347 "ast_yacc.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 736 "ast_yacc.y"

