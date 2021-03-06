/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "trabalho.y"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include  <map>

/*
 * Programa exemplo de um compilador para o curso de Compiladores-2014-2 - Zimbrão
 * TODO:
 * - variavel do tipo boolean
 * - Funções e parametros
 * - Variaveis locais
 * - Array
 * - pipes
 *
 */

using namespace std;

const int MAX_STR = 256;

struct Tipo {
  string nome;
  int nDim;
  int d1;
  int d2;
  
  Tipo() { nome = ""; nDim = 0; d1 = 0; d2 = 0; }
  Tipo( string nome ) {
    this->nome = nome;
    nDim = 0; 
    d1 = 0; 
    d2 = 0;
  }
};

struct Atributo {
  string v;  // Valor
  Tipo   t;  // tipo
  string c;  // codigo
  
  Atributo() {}  // inicializacao automatica para vazio ""
  Atributo( string v, string t = "", string c = "" ) {
    this->v = v;
    this->t.nome = t;
    this->c = c;
  }
};

typedef map< string, Tipo > TS;

TS ts_local, ts_global;
TS* ts = &ts_global; // Tabela de simbolos da vez

string pipeAtivo; // Tipo do pipe ativo
string passoPipeAtivo; // Label 'fim' do pipe ativo

Tipo tipoResultado( Tipo a, string operador, Tipo b );
string geraTemp( Tipo tipo );
string geraLabel( string cmd );
string geraDeclaracaoTemporarias();
string geraDeclaracaoVarPipe();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );
void erro( string msg );
string toStr( int n );
int toInt( string n );

void geraCodigoAtribuicaoSemIndice( Atributo* SS, Atributo& lvalue, const Atributo& rvalue );
void geraCodigoAtribuicao1Indice( Atributo* SS, Atributo& lvalue, Atributo& indice1, const Atributo& rvalue );
void geraCodigoAtribuicao2Indices( Atributo* SS, Atributo& lvalue, Atributo& indice1, Atributo& indice2, const Atributo& rvalue );
void geraCodigoAtribuicao3Indices( Atributo* SS, Atributo& lvalue, Atributo& indice1, Atributo& indice2, Atributo& indice3, const Atributo& rvalue );

void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 );
void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds );
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse );
void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen );
void geraCodigoFor( Atributo* SS, const Atributo& inicial, 
                                  const Atributo& condicao, 
                                  const Atributo& passo, 
                                  const Atributo& cmds );
void geraCodigoFilter( Atributo* SS, const Atributo& condicao );

void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id );
                                           
// Usando const Atributo& não cria cópia desnecessária

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);


/* Line 268 of yacc.c  */
#line 172 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _CTE_INT = 258,
     _CTE_CHAR = 259,
     _CTE_DOUBLE = 260,
     _CTE_STRING = 261,
     _ID = 262,
     _INT = 263,
     _CHAR = 264,
     _BOOL = 265,
     _DOUBLE = 266,
     _FLOAT = 267,
     _STRING = 268,
     _COUT = 269,
     _SHIFTL = 270,
     _PROGRAM = 271,
     _VAR = 272,
     _BEGIN = 273,
     _END = 274,
     _FUNCTION = 275,
     _IF = 276,
     _THEN = 277,
     _ELSE = 278,
     _PROCEDURE = 279,
     _PIPE = 280,
     _INTERVALO = 281,
     _FILTER = 282,
     _FOREACH = 283,
     _2PTS = 284,
     _X = 285,
     _SWITCH = 286,
     _BREAK = 287,
     _CASE = 288,
     _FORWARD = 289,
     _RETURN = 290,
     _IG = 291
   };
#endif
/* Tokens.  */
#define _CTE_INT 258
#define _CTE_CHAR 259
#define _CTE_DOUBLE 260
#define _CTE_STRING 261
#define _ID 262
#define _INT 263
#define _CHAR 264
#define _BOOL 265
#define _DOUBLE 266
#define _FLOAT 267
#define _STRING 268
#define _COUT 269
#define _SHIFTL 270
#define _PROGRAM 271
#define _VAR 272
#define _BEGIN 273
#define _END 274
#define _FUNCTION 275
#define _IF 276
#define _THEN 277
#define _ELSE 278
#define _PROCEDURE 279
#define _PIPE 280
#define _INTERVALO 281
#define _FILTER 282
#define _FOREACH 283
#define _2PTS 284
#define _X 285
#define _SWITCH 286
#define _BREAK 287
#define _CASE 288
#define _FORWARD 289
#define _RETURN 290
#define _IG 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 286 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      46,    47,    41,    39,    49,    40,    45,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    44,
      36,    54,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    13,    16,    17,    18,    23,    28,
      34,    35,    43,    48,    54,    57,    63,    67,    71,    76,
      79,    83,    86,    90,    91,    93,    96,    99,   101,   103,
     106,   109,   111,   115,   124,   129,   138,   140,   144,   146,
     151,   156,   163,   172,   175,   179,   180,   184,   187,   189,
     194,   201,   203,   205,   207,   209,   211,   213,   217,   224,
     233,   244,   248,   252,   256,   260,   264,   268,   272,   276,
     278,   282,   284,   286,   291,   293,   295,   297,   301,   303,
     308,   316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    16,     7,    44,    57,    65,    45,    -1,
      58,    57,    -1,    60,    57,    -1,    -1,    -1,    17,    59,
      81,    44,    -1,    62,    61,    44,    63,    -1,    62,    61,
      44,    34,    44,    -1,    -1,    20,     7,    46,    66,    47,
      48,    82,    -1,    20,     7,    48,    82,    -1,    24,     7,
      46,    66,    47,    -1,    24,     7,    -1,    64,    18,    68,
      19,    44,    -1,    17,    81,    44,    -1,    18,    68,    19,
      -1,    66,    49,    82,     7,    -1,    82,     7,    -1,    50,
      68,    51,    -1,    69,    68,    -1,    73,    44,    68,    -1,
      -1,    67,    -1,    84,    44,    -1,    79,    44,    -1,    78,
      -1,    71,    -1,    70,    44,    -1,    35,    85,    -1,    35,
      -1,    31,    72,    51,    -1,    46,    85,    47,    50,    33,
      85,    48,    68,    -1,    72,    33,    48,    68,    -1,    26,
      52,    85,    29,    74,    53,    75,    77,    -1,    85,    -1,
      25,    76,    75,    -1,    25,    -1,    27,    52,    85,    53,
      -1,    28,    52,    69,    53,    -1,    21,    85,    22,    68,
      19,    21,    -1,    21,    85,    22,    68,    23,    68,    19,
      21,    -1,    14,    80,    -1,    80,    15,    85,    -1,    -1,
      81,    49,     7,    -1,    82,     7,    -1,    83,    -1,    83,
      52,     3,    53,    -1,    83,    52,     3,    30,     3,    53,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,     7,    54,    85,    -1,     7,    52,    85,
      53,    54,    85,    -1,     7,    52,    85,    49,    85,    53,
      54,    85,    -1,     7,    52,    85,    49,    85,    49,    85,
      53,    54,    85,    -1,    85,    39,    85,    -1,    85,    40,
      85,    -1,    85,    41,    85,    -1,    85,    43,    85,    -1,
      85,    42,    85,    -1,    85,    36,    85,    -1,    85,    38,
      85,    -1,    85,    37,    85,    -1,    87,    -1,    86,    49,
      85,    -1,    85,    -1,     7,    -1,     7,    46,    86,    47,
      -1,     3,    -1,     5,    -1,     6,    -1,    46,    85,    47,
      -1,    30,    -1,     7,    52,    85,    53,    -1,     7,    52,
      85,    53,    52,    85,    53,    -1,     7,    52,    85,    53,
      52,    85,    53,    52,    85,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   121,   124,   128,   131,   131,   135,   136,
     139,   142,   143,   144,   145,   148,   151,   154,   158,   159,
     162,   166,   167,   168,   169,   172,   173,   174,   175,   176,
     179,   180,   183,   186,   187,   190,   209,   215,   217,   221,
     225,   229,   231,   235,   239,   246,   250,   253,   258,   259,
     263,   270,   271,   272,   273,   274,   275,   278,   280,   282,
     284,   288,   290,   292,   294,   296,   298,   300,   302,   304,
     307,   310,   313,   319,   326,   329,   332,   335,   336,   342,
     343,   344
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_CTE_INT", "_CTE_CHAR", "_CTE_DOUBLE",
  "_CTE_STRING", "_ID", "_INT", "_CHAR", "_BOOL", "_DOUBLE", "_FLOAT",
  "_STRING", "_COUT", "_SHIFTL", "_PROGRAM", "_VAR", "_BEGIN", "_END",
  "_FUNCTION", "_IF", "_THEN", "_ELSE", "_PROCEDURE", "_PIPE",
  "_INTERVALO", "_FILTER", "_FOREACH", "_2PTS", "_X", "_SWITCH", "_BREAK",
  "_CASE", "_FORWARD", "_RETURN", "'<'", "'>'", "_IG", "'+'", "'-'", "'*'",
  "'/'", "'%'", "';'", "'.'", "'('", "')'", "':'", "','", "'{'", "'}'",
  "'['", "']'", "'='", "$accept", "S1", "DECLS", "VARGLOBAL", "$@1",
  "FUNC", "PREPARA_FUNCAO", "CABECALHO", "CORPO", "VARLOCAL", "MAIN",
  "PARAMS", "BLOCO", "CMDS", "CMD", "CMD_RETURN", "CMD_SW", "SW",
  "CMD_PIPE", "INI_PIPE", "PROCS", "PROC", "CONSOME", "CMD_IF", "CMD_OUT",
  "COUT_EXPR", "DECLVAR", "TIPO", "TIPOSIMPLES", "CMD_ATR", "E", "ARGS",
  "F", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    60,    62,   291,    43,
      45,    42,    47,    37,    59,    46,    40,    41,    58,    44,
     123,   125,    91,    93,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    59,    58,    60,    60,
      61,    62,    62,    62,    62,    63,    64,    65,    66,    66,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    75,    75,    76,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     0,     0,     4,     4,     5,
       0,     7,     4,     5,     2,     5,     3,     3,     4,     2,
       3,     2,     3,     0,     1,     2,     2,     1,     1,     2,
       2,     1,     3,     8,     4,     8,     1,     3,     1,     4,
       4,     6,     8,     2,     3,     0,     3,     2,     1,     4,
       6,     1,     1,     1,     1,     1,     1,     3,     6,     8,
      10,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     4,     1,     1,     1,     3,     1,     4,
       7,    10
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     6,     0,     0,     0,
       5,     5,    10,     0,     0,    14,    23,     0,     3,     4,
       0,    51,    52,    53,    54,    55,    56,     0,     0,    48,
       0,     0,     0,     0,    45,     0,     0,     0,    31,    23,
      24,     0,    23,     0,    28,     0,    27,     0,     0,     2,
       0,     7,     0,    47,     0,     0,     0,    12,     0,     0,
       0,    43,    74,    75,    76,    72,    78,     0,     0,    69,
       0,     0,     0,    30,     0,    17,    21,    29,    23,    26,
      25,     0,     0,     8,     0,    46,     0,     0,     0,    19,
      13,     0,    57,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      20,    22,     0,     9,    23,     0,    49,     0,     0,     0,
       0,    44,    71,     0,     0,    77,     0,    66,    68,    67,
      61,    62,    63,    65,    64,     0,     0,    23,    16,     0,
       0,    11,    18,     0,     0,    73,     0,    79,     0,    23,
       0,    36,     0,    34,     0,    50,     0,     0,    58,    70,
       0,    41,     0,     0,     0,    15,     0,     0,     0,     0,
      38,     0,     0,     0,    59,    80,    42,     0,     0,     0,
      35,    23,     0,     0,     0,    37,     0,    33,    60,     0,
       0,     0,    81,    39,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    13,    11,    20,    12,    83,    84,
      17,    55,    40,    41,    42,    43,    44,    72,    45,   150,
     171,   178,   180,    46,    47,    61,    27,    28,    29,    48,
      68,   123,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int16 yypact[] =
{
      -9,    21,    45,     2,   -40,    -8,   -40,    47,    61,    55,
      -8,    -8,   -40,   164,     5,    37,    -1,    40,   -40,   -40,
      43,   -40,   -40,   -40,   -40,   -40,   -40,   -39,   100,    58,
     164,   164,   164,    22,   -40,    12,    60,    67,    12,    -1,
     -40,    95,    -1,    72,   -40,    73,   -40,    75,    76,   -40,
       6,   -40,   116,   -40,   121,    30,   120,   -40,    31,    12,
      12,   110,   -40,   -40,   -40,   -11,   -40,    12,    53,   -40,
      12,    12,   -25,   233,    77,   -40,   -40,   -40,    -1,   -40,
     -40,   164,    96,   -40,   123,   -40,   -26,    90,   164,   -40,
     -40,    62,   233,    12,    12,    12,   209,    -1,    12,    12,
      12,    12,    12,    12,    12,    12,   188,   221,    91,   -40,
     -40,   -40,    -5,   -40,    -1,   139,   -40,   164,   141,    12,
      97,   233,   233,    35,   118,   -40,    24,   241,   241,   241,
      29,    29,   -40,   -40,   -40,    12,    99,    -1,   -40,   131,
     117,   -40,   -40,    94,    12,   -40,    12,   146,   157,    -1,
     143,   233,   119,   -40,   155,   -40,    12,   147,   233,   233,
      12,   -40,   181,   177,    12,   -40,   126,    12,   144,   182,
     187,   176,   196,   161,   233,   166,   -40,   167,   177,   168,
     -40,    -1,    12,    12,    12,   -40,    17,   -40,   233,   152,
     170,   163,   -40,   -40,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,    26,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   189,   -40,   -28,    36,   -40,   -40,   -40,   -40,   -40,
      63,   -40,   -40,   -40,   -40,   -40,   159,   -29,   -40,   -40,
     -38,   -40,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      73,    56,    57,    56,   115,    51,    33,     1,   108,     6,
      52,    74,     7,    34,    76,    62,     8,    63,    64,    65,
      35,    91,    92,    81,    33,    36,   109,   116,     3,    96,
      37,    34,   106,   107,    38,    94,    18,    19,    35,   138,
      82,    95,    66,   148,    52,     4,     5,   149,    37,    39,
     111,    30,    38,    31,    14,   121,   122,   124,    67,   118,
     127,   128,   129,   130,   131,   132,   133,   134,    15,   126,
     103,   104,   105,    16,    59,    97,    60,    87,    90,    88,
      88,   143,   145,    32,   146,    49,   139,    50,   141,    98,
      99,   100,   101,   102,   103,   104,   105,   151,    98,    99,
     100,   101,   102,   103,   104,   105,   158,    53,   159,   153,
      54,   119,    70,    71,    75,   120,    77,    78,   166,    79,
      80,   162,   168,    85,    86,    93,   172,    89,   110,   174,
      98,    99,   100,   101,   102,   103,   104,   105,   117,   137,
     113,   114,   140,   156,   188,   189,   190,   157,   142,   152,
     154,   144,   164,   187,    98,    99,   100,   101,   102,   103,
     104,   105,    98,    99,   100,   101,   102,   103,   104,   105,
     155,   147,    21,    22,    23,    24,    25,    26,   161,   173,
      98,    99,   100,   101,   102,   103,   104,   105,    98,    99,
     100,   101,   102,   103,   104,   105,   163,   175,   160,   165,
     169,   167,   170,   176,   179,   192,    98,    99,   100,   101,
     102,   103,   104,   105,   177,   182,   194,   135,   183,   184,
     186,    58,   191,   193,    98,    99,   100,   101,   102,   103,
     104,   105,    98,    99,   100,   101,   102,   103,   104,   105,
     112,   185,     0,     0,   181,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   125,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   136,    98,
      99,   100,   101,   102,   103,   104,   105,    -1,    -1,    -1,
     101,   102,   103,   104,   105
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-40))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      38,    30,    31,    32,    30,    44,     7,    16,    33,    17,
      49,    39,    20,    14,    42,     3,    24,     5,     6,     7,
      21,    59,    60,    17,     7,    26,    51,    53,     7,    67,
      31,    14,    70,    71,    35,    46,    10,    11,    21,    44,
      34,    52,    30,    19,    49,     0,    44,    23,    31,    50,
      78,    46,    35,    48,     7,    93,    94,    95,    46,    88,
      98,    99,   100,   101,   102,   103,   104,   105,     7,    97,
      41,    42,    43,    18,    52,    22,    54,    47,    47,    49,
      49,   119,    47,    46,    49,    45,   114,    44,   117,    36,
      37,    38,    39,    40,    41,    42,    43,   135,    36,    37,
      38,    39,    40,    41,    42,    43,   144,     7,   146,   137,
      52,    49,    52,    46,    19,    53,    44,    44,   156,    44,
      44,   149,   160,     7,     3,    15,   164,     7,    51,   167,
      36,    37,    38,    39,    40,    41,    42,    43,    48,    48,
      44,    18,     3,    49,   182,   183,   184,    53,     7,    50,
      19,    54,    33,   181,    36,    37,    38,    39,    40,    41,
      42,    43,    36,    37,    38,    39,    40,    41,    42,    43,
      53,    53,     8,     9,    10,    11,    12,    13,    21,    53,
      36,    37,    38,    39,    40,    41,    42,    43,    36,    37,
      38,    39,    40,    41,    42,    43,    53,    53,    52,    44,
      19,    54,    25,    21,    28,    53,    36,    37,    38,    39,
      40,    41,    42,    43,    27,    54,    53,    29,    52,    52,
      52,    32,   186,    53,    36,    37,    38,    39,    40,    41,
      42,    43,    36,    37,    38,    39,    40,    41,    42,    43,
      81,   178,    -1,    -1,    48,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    36,
      37,    38,    39,    40,    41,    42,    43,    36,    37,    38,
      39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    56,     7,     0,    44,    17,    20,    24,    57,
      58,    60,    62,    59,     7,     7,    18,    65,    57,    57,
      61,     8,     9,    10,    11,    12,    13,    81,    82,    83,
      46,    48,    46,     7,    14,    21,    26,    31,    35,    50,
      67,    68,    69,    70,    71,    73,    78,    79,    84,    45,
      44,    44,    49,     7,    52,    66,    82,    82,    66,    52,
      54,    80,     3,     5,     6,     7,    30,    46,    85,    87,
      52,    46,    72,    85,    68,    19,    68,    44,    44,    44,
      44,    17,    34,    63,    64,     7,     3,    47,    49,     7,
      47,    85,    85,    15,    46,    52,    85,    22,    36,    37,
      38,    39,    40,    41,    42,    43,    85,    85,    33,    51,
      51,    68,    81,    44,    18,    30,    53,    48,    82,    49,
      53,    85,    85,    86,    85,    47,    68,    85,    85,    85,
      85,    85,    85,    85,    85,    29,    47,    48,    44,    68,
       3,    82,     7,    85,    54,    47,    49,    53,    19,    23,
      74,    85,    50,    68,    19,    53,    49,    53,    85,    85,
      52,    21,    68,    53,    33,    44,    85,    54,    85,    19,
      25,    75,    85,    53,    85,    53,    21,    27,    76,    28,
      77,    48,    54,    52,    52,    75,    52,    68,    85,    85,
      85,    69,    53,    53,    53
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  *++yyvsp = yylval;

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

/* Line 1806 of yacc.c  */
#line 115 "trabalho.y"
    { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << (yyvsp[(4) - (6)]).c << (yyvsp[(5) - (6)]).c << endl; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 122 "trabalho.y"
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 125 "trabalho.y"
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 128 "trabalho.y"
    { (yyval) = Atributo(); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 131 "trabalho.y"
    { ts = &ts_global; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 132 "trabalho.y"
    { (yyval) = (yyvsp[(3) - (4)]); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 139 "trabalho.y"
    { ts = &ts_local; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 155 "trabalho.y"
    { geraCodigoFuncaoPrincipal( &(yyval), (yyvsp[(2) - (3)]) ); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 163 "trabalho.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 166 "trabalho.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 167 "trabalho.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 168 "trabalho.y"
    { (yyval) = Atributo(); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 191 "trabalho.y"
    { 
            Atributo inicio, condicao, passo, cmd;
            
            inicio.c = (yyvsp[(3) - (8)]).c + (yyvsp[(5) - (8)]).c +
                       "  x_" + pipeAtivo + " = " + (yyvsp[(3) - (8)]).v + ";\n";
            condicao.t.nome = "bool";
            condicao.v = geraTemp( Tipo( "bool" ) ); 
            condicao.c = "  " + condicao.v + " = " + "x_" + pipeAtivo + 
                         " <= " + (yyvsp[(5) - (8)]).v + ";\n";
            passo.c = passoPipeAtivo + ":\n" + 
                      "  x_" + pipeAtivo + " = x_" + pipeAtivo + " + 1;\n";
            cmd.c = (yyvsp[(7) - (8)]).c + (yyvsp[(8) - (8)]).c;
            
            geraCodigoFor( &(yyval), inicio, condicao, passo, cmd );
            
            pipeAtivo = ""; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 210 "trabalho.y"
    { (yyval) = (yyvsp[(1) - (1)]);
             pipeAtivo =  (yyvsp[(1) - (1)]).t.nome;
	     passoPipeAtivo = geraLabel( "passo_pipe" ); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 216 "trabalho.y"
    { (yyval).c = (yyvsp[(2) - (3)]).c + (yyvsp[(3) - (3)]).c; }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 218 "trabalho.y"
    { (yyval) = Atributo(); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 222 "trabalho.y"
    { geraCodigoFilter( &(yyval), (yyvsp[(3) - (4)]) ); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 226 "trabalho.y"
    { (yyval).c = (yyvsp[(3) - (4)]).c; }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 230 "trabalho.y"
    { geraCodigoIfSemElse( &(yyval), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]) ); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 232 "trabalho.y"
    { geraCodigoIfComElse( &(yyval), (yyvsp[(2) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(6) - (8)]) ); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 236 "trabalho.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 240 "trabalho.y"
    { if( (yyvsp[(3) - (3)]).t.nome == "int" )
                (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + 
                       "  printf( \"%d\" , " + (yyvsp[(3) - (3)]).v + " );\n";
              else if( (yyvsp[(3) - (3)]).t.nome == "string" )
                (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + 
                       "  printf( \"%s\" , " + (yyvsp[(3) - (3)]).v + " );\n";}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 246 "trabalho.y"
    { (yyval) = Atributo(); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 251 "trabalho.y"
    { insereVariavelTS( *ts, (yyvsp[(3) - (3)]).v, (yyvsp[(1) - (3)]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 254 "trabalho.y"
    { insereVariavelTS( *ts, (yyvsp[(2) - (2)]).v, (yyvsp[(1) - (2)]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]) ); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 260 "trabalho.y"
    { (yyval) = (yyvsp[(1) - (4)]);
         (yyval).t.nDim = 1;
         (yyval).t.d1 = toInt( (yyvsp[(3) - (4)]).v ); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 264 "trabalho.y"
    { (yyval) = (yyvsp[(1) - (6)]);
         (yyval).t.nDim = 2;
         (yyval).t.d1 = toInt( (yyvsp[(3) - (6)]).v ); 
         (yyval).t.d2 = toInt( (yyvsp[(5) - (6)]).v ); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 279 "trabalho.y"
    { geraCodigoAtribuicaoSemIndice( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 281 "trabalho.y"
    { geraCodigoAtribuicao1Indice( &(yyval), (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]) ); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 283 "trabalho.y"
    { geraCodigoAtribuicao2Indices( &(yyval), (yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(8) - (8)]) ); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 285 "trabalho.y"
    { geraCodigoAtribuicao3Indices( &(yyval), (yyvsp[(1) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(10) - (10)]) ); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 289 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 291 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 293 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 295 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 297 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 299 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 301 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 303 "trabalho.y"
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]) ); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 308 "trabalho.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c;
         (yyval).v = (yyvsp[(1) - (3)]).v + ", " + (yyvsp[(3) - (3)]).v; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 314 "trabalho.y"
    { if( buscaVariavelTS( *ts, (yyvsp[(1) - (1)]).v, &(yyval).t ) ) 
      (yyval).v = (yyvsp[(1) - (1)]).v; 
    else
      erro( "Variavel nao declarada: " + (yyvsp[(1) - (1)]).v );
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 320 "trabalho.y"
    { // $$.t BUSCAR ID na tabela de funções
      (yyval).t = Tipo("int");
      (yyval).v = geraTemp( (yyval).t );
      (yyval).c = (yyvsp[(3) - (4)]).c +
             (yyval).v + " = " + (yyvsp[(1) - (4)]).v + "( " + (yyvsp[(3) - (4)]).v + ");\n"; 
    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 327 "trabalho.y"
    {  (yyval).v = (yyvsp[(1) - (1)]).v; 
       (yyval).t = Tipo( "int" ); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 330 "trabalho.y"
    {  (yyval).v = (yyvsp[(1) - (1)]).v; 
       (yyval).t = Tipo( "double" ); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 333 "trabalho.y"
    {  (yyval).v = (yyvsp[(1) - (1)]).v; 
       (yyval).t = Tipo( "string" ); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 335 "trabalho.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 337 "trabalho.y"
    { if( pipeAtivo != "" )
        (yyval) = Atributo( "x_" + pipeAtivo, pipeAtivo ); 
      else
        erro( "Variavel 'x' so pode ser usada dentro de pipe" );
    }
    break;



/* Line 1806 of yacc.c  */
#line 2078 "y.tab.c"
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 347 "trabalho.y"

int nlinha = 1;
map<string,int> n_var_temp;
map<string,Tipo> resultadoOperador;
map<string,int> label;

string geraLabel( string cmd ) {
  return "L_" + cmd +"_" + toStr( ++label[cmd] );
}

void geraCodigoFor( Atributo* SS, const Atributo& inicial, 
                                  const Atributo& condicao, 
                                  const Atributo& passo, 
                                  const Atributo& cmds ) {
  string forCond = geraLabel( "for_cond" ),
         forFim = geraLabel( "for_fim" );
  string valorNotCond = geraTemp( Tipo( "bool" ) );
         
  *SS = Atributo();
  if( condicao.t.nome != "bool" )
    erro( "A expressão de teste deve ser booleana: " + condicao.t.nome ); 
  
  // Funciona apenas para filtro, sem pipe que precisa de buffer 
  // (sort, por exemplo, não funciona)
  SS->c = inicial.c + forCond + ":\n" + condicao.c +
          "  " + valorNotCond + " = !" + condicao.v + ";\n" +
          "  if( " + valorNotCond + " ) goto " + forFim + ";\n" +
          cmds.c +
          passo.c +
          "  goto " + forCond + ";\n" + 
          forFim + ":\n";
}

void geraCodigoFilter( Atributo* SS, const Atributo& condicao ) {
  *SS = Atributo();
  SS->v = geraTemp( Tipo( "bool" ) );
  SS->c = condicao.c + 
          "  " + SS->v + " = !" + condicao.v + ";\n" +
          "  if( " + SS->v + " ) goto " + passoPipeAtivo + ";\n";
}

void geraCodigoAtribuicaoSemIndice( Atributo* SS, Atributo& lvalue, 
                                         const Atributo& rvalue ) {
  if( !buscaVariavelTS( *ts, lvalue.v, &lvalue.t ) ) 
    erro( "Variavel nao declarada: " + lvalue.v );
  else if( lvalue.t.nome != rvalue.t.nome )
    erro( "Expressao " + rvalue.t.nome + 
            " nao pode ser atribuida a variavel " + lvalue.t.nome );
  else if( lvalue.t.nDim != 0 || rvalue.t.nDim != 0 )
    erro( "Atribuicao de array nao e permitida: " + lvalue.v + " = " + rvalue.v );
  else if( lvalue.t.nome == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      }
      else
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
}      
       
void geraCodigoAtribuicao1Indice( Atributo* SS, Atributo& lvalue, 
                                                Atributo& indice1, 
                                                const Atributo& rvalue ) {
  SS->c = indice1.c + rvalue.c +
          "  " + lvalue.v + "[" + indice1.v + "] = " + rvalue.v + ";\n";
}
void geraCodigoAtribuicao2Indices( Atributo* SS, Atributo& lvalue, 
                                                 Atributo& indice1, 
                                                 Atributo& indice2, 
                                                 const Atributo& rvalue ){
}
void geraCodigoAtribuicao3Indices( Atributo* SS, Atributo& lvalue, 
                                                 Atributo& indice1, 
                                                 Atributo& indice2, 
                                                 Atributo& indice3, 
                                                 const Atributo& rvalue ){
}
       
       
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse ) {
  string ifTrue = geraLabel( "if_true" ),
         ifFalse = geraLabel( "if_false" ),
         ifFim = geraLabel( "if_fim" );
      
  *SS = Atributo();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifFalse + ";\n" +
          "  " + ifTrue + ":\n" + cmdsThen.c +
          "  goto " + ifFim + ";\n" +
          "  " + ifFalse + ":\n" + cmdsElse.c +
          "  " + ifFim + ":\n";
}

void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen ) {
}


void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id ) {
  SS->v = "";
  SS->t = tipo.t;
  if( tipo.t.nome == "string" ) {
    SS->c = tipo.c + 
           "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  }
  switch( tipo.t.nDim ) {
    case 0: 
      SS->c = tipo.c + tipo.t.nome + " " + id.v + ";\n"; 
      break;
      
   case 1:
     SS->c = tipo.c + tipo.t.nome + " " + id.v + "[" + toStr( tipo.t.d1 ) + "];\n";
    
  }
}

void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds ) {
  *SS = Atributo();
  SS->c = "\nint main() {\n" +
           geraDeclaracaoVarPipe() + 
           "\n" + 
           geraDeclaracaoTemporarias() + 
           "\n" +
           cmds.c + 
           "  return 0;\n" 
           "}\n";
}  

string geraDeclaracaoTemporarias() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["char"]; i++ )
    c += "  char temp_char_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["float"]; i++ )
    c += "  float temp_float_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["string"]; i++ )
    c += "  char temp_string_" + toStr( i + 1 ) + "[" + toStr( MAX_STR )+ "];\n";
    
  return c;  
}

void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 ) {
  SS->t = tipoResultado( S1.t, S2.v, S3.t );
  SS->v = geraTemp( SS->t );

  if( SS->t.nome == "string" ) {
    // Falta o operador de comparação para string
    SS->c = S1.c + S3.c + 
            "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  strncat( " + SS->v + ", " + S3.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  }
  else
    SS->c = S1.c + S3.c + 
            "  " + SS->v + " = " + S1.v + " " + S2.v + " " + S3.v + ";\n";
}

void inicializaResultadoOperador() {
  resultadoOperador["string+string"] = Tipo( "string" );
  resultadoOperador["int+int"] = Tipo( "int" );
  resultadoOperador["int-int"] = Tipo( "int" );
  resultadoOperador["int*int"] = Tipo( "int" );
  resultadoOperador["int==int"] = Tipo( "bool" );
  resultadoOperador["int%int"] = Tipo( "int" );
  resultadoOperador["int/int"] = Tipo( "int" );
  resultadoOperador["int<int"] = Tipo( "bool" );
  resultadoOperador["int>int"] = Tipo( "bool" );
  resultadoOperador["double+int"] = Tipo( "double" );
  resultadoOperador["int*double"] = Tipo( "double" );
  // TODO: completar essa lista... :(
}

#include "lex.yy.c"

int yyparse();

int toInt( string n ) {
  int aux = 0;
  sscanf( n.c_str(), "%d", &aux );
  
  return aux;
}

string toStr( int n ) {  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

void yyerror( const char* st )
{
  puts( st );
  printf( "Linha: %d\nPerto de: '%s'\n", nlinha, yytext );
}

void erro( string msg ) {
  yyerror( msg.c_str() );
  exit(1);
}

string geraDeclaracaoVarPipe() {
  return "  int x_int;\n"
         "  double x_double;\n"
         "  float x_float;\n";
}

string geraTemp( Tipo tipo ) {
  return "temp_" + tipo.nome + "_" + toStr( ++n_var_temp[tipo.nome] );
}

void insereVariavelTS( TS& ts, string nomeVar, Tipo tipo ) {
  if( !buscaVariavelTS( ts, nomeVar, &tipo ) )
    ts[nomeVar] = tipo;
  else  
    erro( "Variavel já definida: " + nomeVar );
}

bool buscaVariavelTS( TS& ts, string nomeVar, Tipo* tipo ) {
  if( ts.find( nomeVar ) != ts.end() ) {
    *tipo = ts[ nomeVar ];
    return true;
  }
  else
    return false;
}

Tipo tipoResultado( Tipo a, string operador, Tipo b ) {
  if( resultadoOperador.find( a.nome + operador + b.nome ) == resultadoOperador.end() )
    erro( "Operacao nao permitida: " + a.nome + operador + b.nome );

  return resultadoOperador[a.nome + operador + b.nome];
}

int main( int argc, char* argv[] )
{
  inicializaResultadoOperador();
  yyparse();
}

