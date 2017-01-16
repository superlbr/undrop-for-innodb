/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sql_parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define YYDEBUG 1

#include "tables_dict.h"
table_def_t table_definitions[1];
field_def_t pk_fields[MAX_TABLE_FIELDS];
field_def_t uq_fields[MAX_TABLE_FIELDS];
field_def_t all_fields[MAX_TABLE_FIELDS];

// globals
char column_name[1024];
char table_name[1024];
char table_charset[1024];
unsigned int field_number = 0;
unsigned int pk_field_number = 0;
unsigned int uq_field_number = 0;
int has_primary_key = 0;
int has_unique_key = 0;
unsigned int n_values = 0;
int is_length = 0;
int is_unsigned = 0;
int is_decimals = 0;
int is_primary_index = 0;
int is_unique_index = 0;
int met_unique_index = 0;
unsigned int length = 0;
unsigned int decimals = 0;

extern bool debug;
extern bool process_56;
extern int yylex (void);
extern void error(char*);
extern void yyerror(char*);

field_def_t*  find_field(field_def_t *haystack, field_def_t* needle, field_def_t** result){
    *result = NULL;
    unsigned int i = 0;
    while((haystack + i)->name != NULL){
        if((strlen((haystack + i)->name) == strlen(needle->name))
            && strncmp((haystack + i)->name, needle->name, strlen(needle->name)) == 0){
            *result = (haystack + i);
            return *result;
            }
        i++;
        }
    return *result;
    }

void strip_bq(char*p){
    int i = 0;
    int j = 0;
    char result[1024] = "";
    for(i = 0; i < strlen(p); i++){
        if( p[i] != '`'){
            result[j++] = p[i];
            }
        }
    result[j++] = '\0';
    //fprintf(stderr, "Result %s\n", result);
    strncpy(p, result, sizeof(result));
    }

#line 134 "sql_parser.c" /* yacc.c:339  */

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
    CREATE = 258,
    TABLE = 259,
    TEMPORARY = 260,
    IF_NOT_EXIST = 261,
    SQLNULL = 262,
    DEFAULT = 263,
    NOT = 264,
    COMMENT = 265,
    FULLTEXT = 266,
    SPATIAL = 267,
    CONSTRAINT = 268,
    INDEX = 269,
    KEY = 270,
    PRIMARY = 271,
    UNIQUE = 272,
    FOREIGN_KEY = 273,
    BIT = 274,
    TINYINT = 275,
    SMALLINT = 276,
    MEDIUMINT = 277,
    INT = 278,
    INTEGER = 279,
    BIGINT = 280,
    REAL = 281,
    DOUBLE = 282,
    FLOAT = 283,
    DECIMAL = 284,
    NUMERIC = 285,
    DATE = 286,
    TIME = 287,
    TIMESTAMP = 288,
    DATETIME = 289,
    YEAR = 290,
    CHAR = 291,
    VARCHAR = 292,
    TINYTEXT = 293,
    TEXT = 294,
    MEDIUMTEXT = 295,
    LONGTEXT = 296,
    BINARY = 297,
    VARBINARY = 298,
    TINYBLOB = 299,
    BLOB = 300,
    MEDIUMBLOB = 301,
    LONGBLOB = 302,
    ENUM = 303,
    SET = 304,
    GEOMETRY = 305,
    POINT = 306,
    LINESTRING = 307,
    POLYGON = 308,
    MULTIPOINT = 309,
    MULTILINESTRING = 310,
    MULTIPOLYGON = 311,
    GEOMETRYCOLLECTION = 312,
    UNSIGNED = 313,
    ZEROFILL = 314,
    ASC = 315,
    DESC = 316,
    USING = 317,
    BTREE = 318,
    HASH = 319,
    RTREE = 320,
    MATCH = 321,
    FULL = 322,
    PARTIAL = 323,
    SIMPLE = 324,
    ON_DELETE = 325,
    ON_UPDATE = 326,
    RESTRICT = 327,
    CASCADE = 328,
    NO = 329,
    ACTION = 330,
    ENGINE = 331,
    TYPE = 332,
    AUTO_INCREMENT = 333,
    AVG_ROW_LENGTH = 334,
    CHECKSUM = 335,
    CHARACTER = 336,
    COLLATE = 337,
    CONNECTION = 338,
    DATA = 339,
    DIRECTORY = 340,
    DELAY_KEY_WRITE = 341,
    INSERT_METHOD = 342,
    MAX_ROWS = 343,
    MIN_ROWS = 344,
    PACK_KEYS = 345,
    PASSWORD = 346,
    ROW_FORMAT = 347,
    UNION = 348,
    FIRST = 349,
    LAST = 350,
    DYNAMIC = 351,
    FIXED = 352,
    COMPRESSED = 353,
    REDUNDANT = 354,
    COMPACT = 355,
    string_value = 356,
    entity_name = 357,
    int_value = 358,
    bool_value = 359,
    CURRENT_TIMESTAMP = 360,
    CHARSET = 361,
    REFERENCES = 362,
    CAN_BE_NULL = 363,
    INT_MIN_VAL = 364,
    INT_MAX_VAL = 365,
    CHAR_MIN_LEN = 366,
    CHAR_MAX_LEN = 367,
    CHAR_ASCII_ONLY = 368,
    CHAR_DIGITS_ONLY = 369,
    CHAR_REGEX = 370,
    DATE_VALIDATION = 371,
    ENUM_VALUES = 372,
    SET_VALUES = 373,
    ENUM_VALUES_COUNT = 374,
    SET_VALUES_COUNT = 375
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "sql_parser.y" /* yacc.c:355  */

    char str[1024];
    long long int si;
 

#line 298 "sql_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 313 "sql_parser.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  263
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   375

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   130,
     122,   123,     2,     2,   124,     2,   131,     2,   128,   129,
       2,     2,     2,     2,     2,     2,     2,     2,   125,   121,
       2,   127,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   126,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   105,   105,   109,   107,   208,   209,
     212,   213,   217,   231,   216,   243,   246,   243,   248,   249,
     252,   249,   256,   257,   261,   263,   263,   265,   265,   267,
     268,   271,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   284,   286,   286,   286,   288,   288,   288,
     288,   288,   290,   290,   292,   292,   298,   300,   300,   302,
     302,   308,   308,   310,   310,   312,   312,   314,   314,   316,
     316,   316,   318,   318,   320,   320,   322,   322,   324,   324,
     334,   334,   346,   349,   349,   353,   353,   355,   356,   359,
     359,   367,   372,   367,   379,   384,   379,   391,   396,   391,
     403,   408,   403,   415,   420,   415,   427,   432,   427,   439,
     439,   442,   442,   446,   446,   450,   450,   450,   458,   462,
     462,   470,   470,   478,   478,   486,   486,   491,   491,   491,
     495,   495,   495,   499,   499,   506,   506,   508,   513,   517,
     521,   525,   525,   529,   529,   533,   533,   537,   537,   541,
     541,   541,   544,   544,   544,   548,   549,   550,   551,   552,
     553,   554,   555,   558,   558,   560,   560,   562,   562,   564,
     564,   566,   566,   568,   568,   570,   570,   570,   572,   572,
     574,   574,   576,   584,   584,   585,   585,   587,   587,   589,
     589,   591,   593,   593,   593,   595,   597,   597,   597,   599,
     601,   601,   601,   601,   603,   603,   605,   605,   607,   607,
     607,   607,   607,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   631,   631,   633,   633,   635,   635,   637,
     637,   637,   639,   639,   641,   641,   641,   641,   641,   641,
     643,   644,   646,   647,   647,   649,   650,   652,   652,   652,
     654,   655,   657,   657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CREATE", "TABLE", "TEMPORARY",
  "IF_NOT_EXIST", "SQLNULL", "DEFAULT", "NOT", "COMMENT", "FULLTEXT",
  "SPATIAL", "CONSTRAINT", "INDEX", "KEY", "PRIMARY", "UNIQUE",
  "FOREIGN_KEY", "BIT", "TINYINT", "SMALLINT", "MEDIUMINT", "INT",
  "INTEGER", "BIGINT", "REAL", "DOUBLE", "FLOAT", "DECIMAL", "NUMERIC",
  "DATE", "TIME", "TIMESTAMP", "DATETIME", "YEAR", "CHAR", "VARCHAR",
  "TINYTEXT", "TEXT", "MEDIUMTEXT", "LONGTEXT", "BINARY", "VARBINARY",
  "TINYBLOB", "BLOB", "MEDIUMBLOB", "LONGBLOB", "ENUM", "SET", "GEOMETRY",
  "POINT", "LINESTRING", "POLYGON", "MULTIPOINT", "MULTILINESTRING",
  "MULTIPOLYGON", "GEOMETRYCOLLECTION", "UNSIGNED", "ZEROFILL", "ASC",
  "DESC", "USING", "BTREE", "HASH", "RTREE", "MATCH", "FULL", "PARTIAL",
  "SIMPLE", "ON_DELETE", "ON_UPDATE", "RESTRICT", "CASCADE", "NO",
  "ACTION", "ENGINE", "TYPE", "AUTO_INCREMENT", "AVG_ROW_LENGTH",
  "CHECKSUM", "CHARACTER", "COLLATE", "CONNECTION", "DATA", "DIRECTORY",
  "DELAY_KEY_WRITE", "INSERT_METHOD", "MAX_ROWS", "MIN_ROWS", "PACK_KEYS",
  "PASSWORD", "ROW_FORMAT", "UNION", "FIRST", "LAST", "DYNAMIC", "FIXED",
  "COMPRESSED", "REDUNDANT", "COMPACT", "string_value", "entity_name",
  "int_value", "bool_value", "CURRENT_TIMESTAMP", "CHARSET", "REFERENCES",
  "CAN_BE_NULL", "INT_MIN_VAL", "INT_MAX_VAL", "CHAR_MIN_LEN",
  "CHAR_MAX_LEN", "CHAR_ASCII_ONLY", "CHAR_DIGITS_ONLY", "CHAR_REGEX",
  "DATE_VALIDATION", "ENUM_VALUES", "SET_VALUES", "ENUM_VALUES_COUNT",
  "SET_VALUES_COUNT", "';'", "'('", "')'", "','", "':'", "'`'", "'='",
  "'0'", "'1'", "'\\''", "'.'", "$accept", "list_sql", "sql_command",
  "create_table", "$@1", "opt_temporary", "list_create_definition",
  "create_definition", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "column_definition", "opt_filter_list", "filter_list", "filter_clause",
  "opt_if_not_exist", "opt_null_clause", "opt_default_clause",
  "opt_auto_increment", "opt_key_clause", "opt_key", "opt_primary",
  "opt_comment_clause", "opt_reference_definition", "adv_index",
  "index_keyword", "opt_symbol", "opt_index_name", "index_name",
  "opt_index_type", "list_index_col_name", "$@8", "$@9", "col_name",
  "$@10", "opt_list_table_option", "list_table_option", "data_type",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46",
  "decimal_type", "opt_length", "length", "$@47", "opt_unsigned",
  "opt_zero_fill", "opt_float_length", "float_length", "$@48", "$@49",
  "opt_length_opt_decimal", "opt_charset_clause", "charset_clause",
  "charset_value", "collate_value", "opt_binary", "opt_collate_clause",
  "collate_clause", "opt_asc", "index_type", "index_type_value",
  "reference_definition", "opt_match_clause", "opt_ondelete_clause",
  "opt_onupdate_clause", "reference_option", "table_option", "opt_equal",
  "opt_default", "one_zero_value", "insert_method_value",
  "pack_keys_value", "row_format_value", "list_tbl_name", "tbl_name",
  "$@50", "list_values", "value", "decimal_value", "opt_constraint", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,    59,    40,    41,    44,    58,    96,    61,    48,    49,
      39,    46
};
# endif

#define YYPACT_NINF -255

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-255)))

#define YYTABLE_NINF -176

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    39,  -255,    48,  -255,   -72,  -255,    51,  -255,  -255,
    -255,    70,  -255,   -31,  -255,     1,  -255,  -255,     8,    16,
      45,  -255,  -255,  -255,  -255,  -255,  -255,  -255,    43,   -62,
    -255,    79,   -25,  -255,    -2,  -255,    72,    45,   -25,  -255,
      73,    91,  -255,   293,  -255,    77,    96,    56,  -255,    93,
     112,    93,    93,    93,    93,    93,    93,   139,    93,    93,
      93,    93,    93,    93,    93,    93,  -255,   175,  -255,   -28,
    -255,    62,   102,    57,   134,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,   189,   169,  -255,   120,   254,
    -255,   -25,  -255,  -255,   170,    93,   168,   171,   173,   174,
      -3,   177,    93,    -3,   -11,   176,   178,    15,   179,    11,
     150,  -255,   225,    93,    93,     2,  -255,  -255,  -255,  -255,
    -255,     2,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   160,   160,   160,   160,   160,   160,   242,   242,
     242,   242,   160,   160,   163,   164,    24,  -255,  -255,   280,
     281,   166,  -255,  -255,    79,   172,  -255,   190,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,   191,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,   -31,    93,   188,   193,    44,
    -255,    68,   194,  -255,  -255,   235,   235,   235,   235,   235,
     235,   195,   235,  -255,   235,   235,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   218,   218,   218,   218,  -255,  -255,   -51,
     -51,   294,  -255,  -255,   227,  -255,  -255,   281,  -255,    36,
     222,   200,  -255,  -255,  -255,    91,   -25,     2,  -255,  -255,
     -21,  -255,   202,  -255,  -255,    91,     2,   160,    91,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,   246,   246,
     246,   218,   218,   257,   226,  -255,   226,   226,   226,  -255,
    -255,   204,    71,  -255,    81,  -255,  -255,   123,  -255,   220,
    -255,   206,  -255,  -255,  -255,   157,   186,   235,   230,    91,
      84,  -255,  -255,  -255,  -255,  -255,   149,  -255,   231,   246,
     246,   246,   246,   246,   246,   229,  -255,  -255,  -255,  -255,
     226,   226,   110,   113,  -255,  -255,  -255,  -255,  -255,   228,
    -255,   -51,  -255,   232,   234,   236,   237,   238,   239,   240,
     241,   243,   244,   245,   247,   248,  -255,  -255,   123,   252,
      86,  -255,   341,   350,   352,   246,     2,   249,   267,   160,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
     272,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
     218,  -255,   218,   273,   275,   276,   277,   278,   279,   282,
     283,   284,   260,   263,   286,   287,  -255,  -255,   288,  -255,
    -255,   291,   267,  -255,  -255,    95,     2,   -31,  -255,   149,
    -255,   226,   226,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,   -51,   -51,  -255,  -255,   264,  -255,  -255,  -255,
    -255,    99,   265,  -255,   253,  -255,  -255,   103,   121,  -255,
      91,  -255,     2,  -255,  -255,  -255,  -255,    91,   124,  -255,
     327,   119,   325,  -255,  -255,  -255,    24,   189,  -255,  -255
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     8,     5,     0,     2,     0,     9,     0,     1,     3,
       4,    42,    43,     0,   252,     0,     6,   253,     0,     0,
     262,   254,    65,    66,   263,    67,    68,    82,     0,     0,
      10,     0,    72,    12,    69,    83,   235,   262,    72,    74,
       0,    76,    73,     0,    70,     0,     0,     0,   236,   233,
       0,   233,   233,   233,   233,   233,   233,     0,   233,   233,
     233,   233,   233,   233,   233,   233,     7,   235,    87,     0,
      11,     0,     0,     0,     0,    77,    89,    91,    94,    97,
     100,   103,   106,   109,   111,   113,   163,   164,   118,   119,
     121,   123,   125,   127,   130,   141,   143,   145,   147,   133,
     135,   137,   138,   139,   140,   149,   152,   155,   156,   157,
     158,   159,   160,   161,   162,   206,    44,   115,     0,     0,
      19,    72,    84,   234,     0,   233,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,   233,   233,     0,    75,   196,   197,   198,
     195,     0,   165,   165,   165,   165,   165,   165,   165,   173,
     173,   173,   165,   165,   165,   165,   165,     0,   187,   187,
     187,   187,   165,     0,     0,     0,     0,    13,    46,     0,
      47,     0,    71,    15,     0,     0,   221,     0,   213,   214,
     215,   216,   237,   238,   219,   222,     0,   224,   239,   240,
     241,   226,   227,   228,   243,   242,   229,   230,   244,   245,
     246,   247,   248,   249,   231,     0,   233,     0,     0,     0,
      78,     0,     0,    90,   166,   169,   169,   169,   169,   169,
     169,     0,   169,   174,   169,   169,   120,   122,   124,   126,
     128,   131,   188,   180,   180,   180,   180,   134,   136,     0,
       0,     0,   208,   209,     0,   212,   207,    47,    45,     0,
      52,     0,   178,   179,   116,    76,    72,     0,   225,   223,
       0,   250,     0,   220,   218,    76,     0,   165,    76,   167,
     170,    92,    95,    98,   101,   104,   107,   175,   171,   171,
     171,   180,   180,     0,   189,   181,   189,   189,   189,   257,
     258,     0,     0,   255,     0,   210,   211,    25,    50,   258,
      51,     0,    48,    49,    53,    54,   167,   169,     0,    76,
       0,   232,   251,   217,    22,    80,   192,    18,     0,   171,
     171,   171,   171,   171,   171,     0,   172,   110,   112,   114,
     189,   189,     0,     0,   142,   190,   144,   146,   148,     0,
     150,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    26,    27,     0,
       0,    60,    57,    61,     0,   171,     0,     0,     0,   165,
     193,   194,    79,   168,    93,    96,    99,   102,   105,   108,
       0,   129,   132,   183,   184,   182,   185,   186,   191,   259,
     180,   256,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,   260,     0,    58,
      55,     0,    63,    56,   117,     0,     0,     0,    23,   192,
     176,   189,   189,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,    40,    41,     0,    62,    24,    64,
      16,     0,     0,    81,     0,   151,   154,     0,     0,   261,
      76,    20,     0,   177,    38,    39,    17,    76,     0,    21,
     200,     0,   204,   201,   202,   203,     0,   206,   205,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,   393,  -255,  -255,  -255,  -255,   360,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,    31,  -255,  -255,  -255,
     141,  -255,  -255,  -255,  -255,  -255,  -255,  -255,   -14,  -255,
     -36,  -255,  -254,  -151,  -255,  -255,   -19,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -150,   -27,
    -255,  -160,  -198,    89,   219,  -255,  -255,  -255,  -204,  -255,
    -255,  -255,    30,  -251,  -255,   -24,  -255,  -255,   -20,  -255,
    -255,   -76,   -73,   337,   -26,  -255,   -18,  -255,  -255,  -255,
    -255,  -206,  -255,  -240,  -228,  -255,  -255
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    18,     7,    29,    30,    43,   257,
     265,   460,   184,   467,   115,   366,   367,   368,    13,   180,
     260,   315,   373,   420,   374,   422,   448,    31,    32,    46,
      41,    42,    74,   219,   277,   379,   220,    47,    66,    67,
     116,   152,   153,   329,   154,   330,   155,   331,   156,   332,
     157,   333,   158,   334,   159,   160,   161,   181,   317,   162,
     163,   164,   165,   166,   291,   167,   292,   172,   173,   168,
     169,   170,   171,   174,   400,   175,   402,   117,   223,   224,
     328,   281,   337,   232,   233,   335,   454,   264,   294,   295,
     395,   398,   243,   344,   345,   382,    75,   150,   428,   472,
     477,   177,   256,    68,   124,    69,   194,   201,   206,   214,
     270,    16,    19,   302,   303,   313,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     221,    33,    71,   225,   226,   227,   228,   229,   230,   271,
     304,   318,   236,   237,   238,   239,   240,    38,    33,   208,
       1,   324,   247,   204,   327,   126,   127,   128,   129,   130,
     131,   312,   133,   134,   135,   136,   137,   138,   139,   140,
     296,   297,   298,   308,     6,   346,   347,   348,     8,    10,
     299,     1,   300,   142,   143,    11,    22,    23,    24,    25,
      26,    36,    37,   198,   322,   377,   282,   283,   284,   285,
     286,    14,   288,   251,   289,   290,    12,    39,   144,   301,
      48,    14,    49,   199,   200,   185,    50,   340,   341,   391,
     392,   338,   339,    25,    26,    15,   252,   253,   254,   187,
      44,    40,   321,    17,    27,    15,   196,   209,   210,   211,
     212,   213,   119,   120,   121,   197,   320,   217,   218,   205,
     147,   148,   149,   401,    45,   192,   193,   326,    28,   255,
      20,   384,   385,   386,   387,   388,   389,   299,     2,   309,
     241,   310,    21,   192,   193,    35,   248,    27,    51,    52,
      53,    54,    55,    73,   262,    56,    57,   375,    58,    59,
      60,    61,    62,    63,    64,    65,   311,   275,   276,     2,
     266,    28,   -59,   371,   372,    72,   178,   424,   179,   118,
     455,   456,   122,    48,   145,    49,   473,   474,   475,    50,
     272,   278,   276,   -85,   350,   351,   431,   125,   432,   244,
     245,   246,   457,   458,   352,   351,   466,   378,   276,   380,
     381,   393,   394,   469,   396,   397,   399,   418,   450,   276,
     123,   452,   461,   276,   132,   425,   464,   351,   146,   429,
     319,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   465,   351,   182,   470,   276,   234,
     235,    51,    52,    53,    54,    55,   151,   325,    56,    57,
     176,    58,    59,    60,    61,    62,    63,    64,    65,   183,
     188,   186,   215,   189,   216,   451,   190,   191,   195,   202,
     207,   203,   222,   231,   242,   249,   250,   258,   261,   259,
     273,   268,   269,   280,   267,   274,   -86,   279,   287,   293,
     314,   305,   306,   316,   323,   336,   342,   349,   343,   370,
    -175,   468,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   369,   376,   390,   383,   417,   419,   403,   399,   404,
     421,   405,   406,   407,   408,   409,   410,   423,   411,   412,
     413,   426,   414,   415,   427,   430,   463,   433,   434,   435,
     436,   437,   442,   438,   440,   443,   439,   462,   441,   444,
     445,   446,   447,   471,   459,   476,     9,    70,   307,   416,
     263,   479,   449,   478,   141,   453
};

static const yytype_uint16 yycheck[] =
{
     151,    20,    38,   153,   154,   155,   156,   157,   158,   215,
     250,   265,   162,   163,   164,   165,   166,    31,    37,     8,
       3,   275,   172,     8,   278,    51,    52,    53,    54,    55,
      56,   259,    58,    59,    60,    61,    62,    63,    64,    65,
     244,   245,   246,     7,     5,   296,   297,   298,     0,   121,
     101,     3,   103,    81,    82,     4,    11,    12,    13,    14,
      15,   123,   124,    74,   270,   319,   226,   227,   228,   229,
     230,   102,   232,    49,   234,   235,     6,   102,   106,   130,
       8,   102,    10,    94,    95,   121,    14,   291,   292,   340,
     341,   289,   290,    14,    15,   126,    72,    73,    74,   125,
     102,   126,   123,   102,   102,   126,   132,    96,    97,    98,
      99,   100,    16,    17,    18,   133,   267,   143,   144,   137,
      63,    64,    65,   351,   126,   128,   129,   277,   126,   105,
     122,   329,   330,   331,   332,   333,   334,   101,   121,   103,
     167,   105,   126,   128,   129,   102,   173,   102,    76,    77,
      78,    79,    80,    62,   181,    83,    84,   317,    86,    87,
      88,    89,    90,    91,    92,    93,   130,   123,   124,   121,
     184,   126,    15,    16,    17,   102,     7,   375,     9,   102,
     431,   432,   126,     8,   122,    10,    67,    68,    69,    14,
     216,   123,   124,   121,   123,   124,   400,    85,   402,   169,
     170,   171,   442,   443,   123,   124,   460,   123,   124,    60,
      61,   101,   102,   467,   101,   102,   130,   131,   123,   124,
     127,   427,   123,   124,    85,   376,   123,   124,   126,   379,
     266,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   123,   124,   126,   123,   124,   160,
     161,    76,    77,    78,    79,    80,   122,   276,    83,    84,
      71,    86,    87,    88,    89,    90,    91,    92,    93,    15,
     102,   101,   122,   102,    49,   426,   103,   103,   101,   103,
     101,   103,   122,   122,    42,   122,   122,     7,   122,     8,
     102,   101,   101,    58,   122,   102,   121,   103,   103,    81,
      78,     7,    75,   103,   102,    59,    49,   103,    82,   103,
     124,   462,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   131,   122,   124,   123,   103,    15,   125,   130,   125,
      10,   125,   125,   125,   125,   125,   125,    15,   125,   125,
     125,   122,   125,   125,   107,   103,   123,   104,   103,   103,
     103,   103,   122,   104,   101,   122,   104,   122,   104,   103,
     103,   103,   101,    66,   130,    70,     3,    37,   257,   368,
     181,   477,   422,   476,    67,   429
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   121,   133,   134,   135,     5,   137,     0,   134,
     121,     4,     6,   150,   102,   126,   243,   102,   136,   244,
     122,   126,    11,    12,    13,    14,    15,   102,   126,   138,
     139,   159,   160,   168,   248,   102,   123,   124,   160,   102,
     126,   162,   163,   140,   102,   126,   161,   169,     8,    10,
      14,    76,    77,    78,    79,    80,    83,    84,    86,    87,
      88,    89,    90,    91,    92,    93,   170,   171,   235,   237,
     139,   162,   102,    62,   164,   228,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   146,   172,   209,   102,    16,
      17,    18,   126,   127,   236,    85,   236,   236,   236,   236,
     236,   236,    85,   236,   236,   236,   236,   236,   236,   236,
     236,   235,    81,    82,   106,   122,   126,    63,    64,    65,
     229,   122,   173,   174,   176,   178,   180,   182,   184,   186,
     187,   188,   191,   192,   193,   194,   195,   197,   201,   202,
     203,   204,   199,   200,   205,   207,    71,   233,     7,     9,
     151,   189,   126,    15,   144,   162,   101,   236,   102,   102,
     103,   103,   128,   129,   238,   101,   236,   238,    74,    94,
      95,   239,   103,   103,     8,   238,   240,   101,     8,    96,
      97,    98,    99,   100,   241,   122,    49,   236,   236,   165,
     168,   165,   122,   210,   211,   210,   210,   210,   210,   210,
     210,   122,   215,   216,   215,   215,   210,   210,   210,   210,
     210,   211,    42,   224,   224,   224,   224,   210,   211,   122,
     122,    49,    72,    73,    74,   105,   234,   141,     7,     8,
     152,   122,   211,   216,   219,   142,   160,   122,   101,   101,
     242,   243,   236,   102,   102,   123,   124,   166,   123,   103,
      58,   213,   213,   213,   213,   213,   213,   103,   213,   213,
     213,   196,   198,    81,   220,   221,   220,   220,   220,   101,
     103,   130,   245,   246,   245,     7,    75,   152,     7,   103,
     105,   130,   246,   247,    78,   153,   103,   190,   164,   162,
     165,   123,   243,   102,   164,   168,   210,   164,   212,   175,
     177,   179,   181,   183,   185,   217,    59,   214,   214,   214,
     220,   220,    49,    82,   225,   226,   225,   225,   225,   103,
     123,   124,   123,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   147,   148,   149,   131,
     103,    16,    17,   154,   156,   213,   122,   164,   123,   167,
      60,    61,   227,   123,   214,   214,   214,   214,   214,   214,
     124,   225,   225,   101,   102,   222,   101,   102,   223,   130,
     206,   246,   208,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   148,   103,   131,    15,
     155,    10,   157,    15,   214,   165,   122,   107,   230,   210,
     103,   220,   220,   104,   103,   103,   103,   103,   104,   104,
     101,   104,   122,   122,   103,   103,   103,   101,   158,   230,
     123,   165,   243,   227,   218,   225,   225,   245,   245,   130,
     143,   123,   122,   123,   123,   123,   164,   145,   165,   164,
     123,    66,   231,    67,    68,    69,    70,   232,   234,   233
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   132,   133,   133,   134,   134,   136,   135,   137,   137,
     138,   138,   140,   141,   139,   142,   143,   139,   139,   144,
     145,   139,   139,   139,   146,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   150,   150,   151,   151,   151,   152,   152,   152,
     152,   152,   153,   153,   154,   154,   154,   155,   155,   156,
     156,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161,   161,   162,   162,   163,   163,   164,   164,   166,   165,
     167,   165,   168,   169,   168,   170,   170,   171,   171,   173,
     172,   174,   175,   172,   176,   177,   172,   178,   179,   172,
     180,   181,   172,   182,   183,   172,   184,   185,   172,   186,
     172,   187,   172,   188,   172,   189,   190,   172,   172,   191,
     172,   192,   172,   193,   172,   194,   172,   195,   196,   172,
     197,   198,   172,   199,   172,   200,   172,   172,   172,   172,
     172,   201,   172,   202,   172,   203,   172,   204,   172,   205,
     206,   172,   207,   208,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   209,   209,   210,   210,   212,   211,   213,
     213,   214,   214,   215,   215,   217,   218,   216,   219,   219,
     220,   220,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   227,   227,   227,   228,   229,   229,   229,   230,
     231,   231,   231,   231,   232,   232,   233,   233,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   236,   236,   237,   237,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     242,   242,   243,   244,   243,   245,   245,   246,   246,   246,
     247,   247,   248,   248
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     0,    10,     0,     1,
       1,     3,     0,     0,     7,     0,     0,    11,     7,     0,
       0,    12,     7,     8,     7,     0,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     5,
       3,     3,     0,     1,     0,     2,     1,     0,     2,     2,
       2,     2,     0,     1,     0,     2,     2,     0,     1,     0,
       1,     0,     2,     0,     1,     1,     1,     1,     1,     0,
       1,     3,     0,     1,     1,     3,     0,     1,     0,     4,
       0,     6,     1,     0,     4,     0,     1,     1,     2,     0,
       3,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       5,     0,     5,     0,     5,     0,     0,     6,     1,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     0,     6,
       0,     0,     6,     0,     3,     0,     3,     1,     1,     1,
       1,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       0,     8,     0,     0,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     4,     0,
       1,     0,     1,     0,     1,     0,     0,     7,     1,     1,
       0,     1,     3,     1,     1,     1,     1,     0,     1,     0,
       1,     2,     0,     1,     1,     2,     1,     1,     1,     8,
       0,     2,     2,     2,     0,     2,     0,     2,     1,     1,
       2,     2,     1,     3,     3,     3,     3,     5,     4,     3,
       4,     3,     3,     4,     3,     4,     3,     3,     3,     3,
       3,     3,     5,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     4,     1,     3,     1,     1,     3,
       3,     5,     0,     1
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
        case 6:
#line 109 "sql_parser.y" /* yacc.c:1646  */
    {
        strip_bq(table_name);
        if(debug) printf("Parsing sturcture of %s\n", table_name);
        table_definitions[0].name = strdup(table_name);
        }
#line 1772 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "sql_parser.y" /* yacc.c:1646  */
    {
        // if table_charset it utf8 or utf8mb
        // increste max_size of each VARCHAR or TEXT field
        unsigned int factor = 1;
        if(strcmp(table_charset, "utf8") == 0) factor = 3;
        if(strcmp(table_charset, "utf8mb4") == 0) factor = 4;
        int i = 0;
        for(i = 0; i < field_number; i++){
            // If charset isn't set explicitely apply table-wide factor
            if(all_fields[i].charset == NULL){
                all_fields[i].fixed_length = all_fields[i].fixed_length * factor;
                }
            }
        // generate table_defs based on all_fields
        unsigned int meta_i = 0;
        if(has_primary_key){
            unsigned int i = 0;
            for(i = 0; i < pk_field_number; i++){
                if(debug) printf("Primary key: %s, type: %d\n", pk_fields[i].name, pk_fields[i].type);
                field_def_t* fld;
                find_field(all_fields, pk_fields + i, &fld);
                assert(fld != NULL);
                memcpy(table_definitions[0].fields + meta_i, fld, sizeof(field_def_t));
                meta_i++;
                }
            }
        else{
            if(has_unique_key){
                unsigned int i = 0;
                for(i = 0; i < uq_field_number; i++){
                    if(debug) printf("Unique key: %s\n", uq_fields[i].name);
                    field_def_t* fld;
                    find_field(all_fields, uq_fields + i, &fld);
                    assert(fld != NULL);
                    memcpy(table_definitions[0].fields + meta_i, fld, sizeof(field_def_t));
                    meta_i++;
                    }
                
                }
            else{
                if(debug) printf("Has primary: %d\n", has_primary_key);
                field_def_t row_id;
                row_id.name = strdup("DB_ROW_ID");
                row_id.type = FT_INTERNAL;
                row_id.can_be_null = 0;
                row_id.fixed_length = 6;
                memcpy(table_definitions[0].fields + meta_i, &row_id, sizeof(field_def_t));
                meta_i++;
                }
            }
        // Add MVCC fields
        field_def_t trx_id, roll_ptr, none;
        trx_id.name = strdup("DB_TRX_ID");
        trx_id.type = FT_INTERNAL;
        trx_id.can_be_null = 0;
        trx_id.fixed_length = 6;
        roll_ptr.name = strdup("DB_ROLL_PTR");
        roll_ptr.type = FT_INTERNAL;
        roll_ptr.can_be_null = 0;
        roll_ptr.fixed_length = 7;
        memcpy(table_definitions[0].fields + meta_i++, &trx_id, sizeof(field_def_t));
        memcpy(table_definitions[0].fields + meta_i++, &roll_ptr, sizeof(field_def_t));
        for(i = 0; i < field_number; i++){
            if(debug) printf("field[%u]: \n", i);
            field_def_t* fld;
            find_field(table_definitions[0].fields, all_fields + i, &fld);
            if(fld == NULL){
                if(debug) printf("Other field[%u]: %s\n", i, all_fields[i].name);
                memcpy(table_definitions[0].fields + meta_i++, all_fields + i, sizeof(field_def_t));
                }
            }
        none.type = FT_NONE;
        //memcpy(table_definitions[0].fields + meta_i++, &none, sizeof(field_def_t));
        i = 0;
        if(debug) printf("Table_defs %s\n", table_definitions[0].name);
        while(table_definitions[0].fields[i].name != NULL){
            if(debug) printf("             name: %s\n", table_definitions[0].fields[i].name);
            if(debug) printf("             type: %d\n", table_definitions[0].fields[i].type);
            if(debug) printf("          charset: %s\n", table_definitions[0].fields[i].charset);
            if(debug) printf("       min_length: %d\n", table_definitions[0].fields[i].min_length);
            if(debug) printf("       max_length: %d\n", table_definitions[0].fields[i].max_length);
            if(debug) printf("      can_be_null: %lu\n", table_definitions[0].fields[i].can_be_null);
            if(debug) printf("     fixed_length: %d\n", table_definitions[0].fields[i].fixed_length);
            if(debug) printf("decimal_precision: %d\n", table_definitions[0].fields[i].decimal_precision);
            if(debug) printf("   decimal_digits: %d\n", table_definitions[0].fields[i].decimal_digits);
            if(debug) printf("   time_precision: %d\n", table_definitions[0].fields[i].time_precision);
            if(debug) printf("       has_limits: %lu\n", table_definitions[0].fields[i].has_limits);
            if(debug) printf("\n");
            i++;
            }
        }
#line 1868 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "sql_parser.y" /* yacc.c:1646  */
    {
            // Reset floags
            is_length = 0;
            is_unsigned = 0;
            is_decimals = 0;
            n_values = 0;
            // Save name
            strip_bq(column_name);
            if(debug) printf("Column %s\n", column_name);
            all_fields[field_number].name = strdup(column_name);
            all_fields[field_number].min_length = 0;
            all_fields[field_number].can_be_null = 1;
            }
#line 1886 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 231 "sql_parser.y" /* yacc.c:1646  */
    { 
            if(debug) printf("all_fields[%d].name  = %s, type: %d, size: %u\n", 
                    field_number, 
                    all_fields[field_number].name,
                    all_fields[field_number].type,
                    all_fields[field_number].fixed_length);
            all_fields[field_number].has_limits = FALSE;
            all_fields[field_number].char_rstrip_spaces = 0;
            }
#line 1900 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 242 "sql_parser.y" /* yacc.c:1646  */
    { field_number++; }
#line 1906 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 243 "sql_parser.y" /* yacc.c:1646  */
    { 
            has_primary_key = 1; 
            is_primary_index = 1;
            }
#line 1915 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "sql_parser.y" /* yacc.c:1646  */
    {
            is_primary_index = 0; }
#line 1922 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 249 "sql_parser.y" /* yacc.c:1646  */
    {
            has_unique_key = 1;
            is_unique_index = 1;
            }
#line 1931 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "sql_parser.y" /* yacc.c:1646  */
    {
            is_unique_index = 0;
            met_unique_index = 1;
            }
#line 1940 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 263 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].has_limits = TRUE; }
#line 1946 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 267 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.can_be_null = (yyvsp[0].si); }
#line 1952 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 268 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.int_min_val = (yyvsp[0].si);
                                  all_fields[field_number].limits.uint_min_val = (yyvsp[0].si);
                                }
#line 1960 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 271 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.int_max_val = (yyvsp[0].si); 
                                  all_fields[field_number].limits.uint_max_val = (yyvsp[0].si);
                                }
#line 1968 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 274 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.char_min_len = (yyvsp[0].si); }
#line 1974 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 275 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.char_max_len = (yyvsp[0].si); }
#line 1980 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 276 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.char_ascii_only = (yyvsp[0].si); }
#line 1986 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 277 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.char_digits_only = (yyvsp[0].si); }
#line 1992 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 279 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].limits.date_validation = (yyvsp[0].si); }
#line 1998 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 286 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].can_be_null = 0; }
#line 2004 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 292 "sql_parser.y" /* yacc.c:1646  */
    {
        has_unique_key = 1;
        if(!met_unique_index){
            memcpy(uq_fields + uq_field_number, all_fields + field_number, sizeof(field_def_t));
            uq_field_number++;
            }
        }
#line 2016 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 302 "sql_parser.y" /* yacc.c:1646  */
    { 
        has_primary_key = 1;
        memcpy(pk_fields + pk_field_number, all_fields + field_number, sizeof(field_def_t));
        pk_field_number++;
        }
#line 2026 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_primary_index){
            strip_bq(column_name);
            pk_fields[pk_field_number++].name = strdup(column_name);
            }
        if(is_unique_index && !met_unique_index){
            strip_bq(column_name);
            uq_fields[uq_field_number++].name = strdup(column_name);
            }
        }
#line 2041 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 334 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_primary_index){
            strip_bq(column_name);
            pk_fields[pk_field_number++].name = strdup(column_name);
            }
        if(is_unique_index && !met_unique_index){
            strip_bq(column_name);
            uq_fields[uq_field_number++].name = strdup(column_name);
            }
        }
#line 2056 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 346 "sql_parser.y" /* yacc.c:1646  */
    { 
                memset(column_name, 0, sizeof(column_name)); 
                strncpy(column_name, (yyvsp[0].str), strlen((yyvsp[0].str))); }
#line 2064 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 349 "sql_parser.y" /* yacc.c:1646  */
    { 
                memset(column_name, 0, sizeof(column_name)); 
                strncpy(column_name, (yyvsp[0].str), strlen((yyvsp[0].str))); }
#line 2072 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 359 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BIT; 
        all_fields[field_number].fixed_length = 1;
        }
#line 2081 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 362 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            all_fields[field_number].fixed_length = floor((length + 7 ) / 8);
            }
        }
#line 2091 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 367 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT; 
        all_fields[field_number].fixed_length = 1;
        all_fields[field_number].limits.int_min_val = -127; 
        all_fields[field_number].limits.int_max_val = 127; 
        }
#line 2102 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 372 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 255; 
            }
        }
#line 2114 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 379 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT;
        all_fields[field_number].fixed_length = 2; 
        all_fields[field_number].limits.int_min_val = -32768; 
        all_fields[field_number].limits.int_max_val = 32767; 
        }
#line 2125 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 384 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 65535; 
            }
        }
#line 2137 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 391 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT; 
        all_fields[field_number].fixed_length = 3;
        all_fields[field_number].limits.int_min_val = -8388608L; 
        all_fields[field_number].limits.int_max_val = 8388607L; 
        }
#line 2148 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 396 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 16777215UL; 
            }
        }
#line 2160 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 403 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT; 
        all_fields[field_number].fixed_length = 4;
        all_fields[field_number].limits.int_min_val = -2147483648LL; 
        all_fields[field_number].limits.int_max_val = 2147483647LL; 
        }
#line 2171 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 408 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 4294967295ULL; 
            }
        }
#line 2183 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 415 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT; 
        all_fields[field_number].fixed_length = 4;
        all_fields[field_number].limits.int_min_val = -2147483648LL; 
        all_fields[field_number].limits.int_max_val = 2147483647LL; 
        }
#line 2194 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 420 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 4294967295ULL; 
            }
        }
#line 2206 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 427 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_INT;
        all_fields[field_number].fixed_length = 8;
        all_fields[field_number].limits.int_min_val = -9223372036854775806LL; 
        all_fields[field_number].limits.int_max_val = 9223372036854775807LL; 
        }
#line 2217 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 432 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_unsigned){
            all_fields[field_number].type = FT_UINT;
            all_fields[field_number].limits.uint_min_val = 0; 
            all_fields[field_number].limits.uint_max_val = 18446744073709551615ULL; 
            }
        }
#line 2229 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 439 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_FLOAT; 
        all_fields[field_number].fixed_length = 4;
        }
#line 2237 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 442 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_DOUBLE; 
        all_fields[field_number].fixed_length = 8;
        }
#line 2246 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 446 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_FLOAT; 
        all_fields[field_number].fixed_length = 4;
        }
#line 2255 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 450 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_DECIMAL ; }
#line 2261 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 450 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            decimals = (is_decimals) ? decimals: 0;
            all_fields[field_number].fixed_length = ceil((float)(length-decimals) * 4 / 9) + ceil((float)decimals*4/9);
            all_fields[field_number].decimal_precision = length;
            all_fields[field_number].decimal_digits = decimals;
            }
        }
#line 2274 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 458 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_DATE; 
        all_fields[field_number].fixed_length = 3;
        }
#line 2283 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 462 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TIME; 
        all_fields[field_number].fixed_length = 3;
        }
#line 2292 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 465 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            all_fields[field_number].fixed_length = 3 + ceil(length/2.0);
            }
        }
#line 2302 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 470 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TIMESTAMP; 
        all_fields[field_number].fixed_length = 4;
        }
#line 2311 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 473 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            all_fields[field_number].fixed_length = 4 + ceil(length/2.0);
            }
        }
#line 2321 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 478 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_DATETIME;
        all_fields[field_number].fixed_length = (process_56) ? 5: 8;
        }
#line 2330 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 481 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            all_fields[field_number].fixed_length = 5 + ceil(length/2.0);
            }
        }
#line 2340 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 486 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_YEAR; 
        all_fields[field_number].fixed_length = 1;
        }
#line 2349 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 491 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_CHAR; }
#line 2355 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 491 "sql_parser.y" /* yacc.c:1646  */
    {
        all_fields[field_number].fixed_length = (is_length) ? length : 1;
        }
#line 2363 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 495 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_CHAR; }
#line 2369 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 495 "sql_parser.y" /* yacc.c:1646  */
    {
        all_fields[field_number].max_length = length;
        }
#line 2377 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 499 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BIN; }
#line 2384 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 500 "sql_parser.y" /* yacc.c:1646  */
    {
        if(is_length){
            all_fields[field_number].fixed_length = length;
            }
        }
#line 2394 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 506 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_BIN; }
#line 2400 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 506 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].max_length = length;}
#line 2406 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 508 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BLOB; 
        all_fields[field_number].max_length = 255;
        }
#line 2415 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 513 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BLOB; 
        all_fields[field_number].max_length = 65535;
        }
#line 2424 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 517 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BLOB; 
        all_fields[field_number].max_length = 16777215;
        }
#line 2433 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 521 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_BLOB; 
        all_fields[field_number].max_length = 4294967295;
        }
#line 2442 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 525 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TEXT; 
        all_fields[field_number].max_length = 255;
        }
#line 2451 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 529 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TEXT;
        all_fields[field_number].max_length = 65535; 
        }
#line 2460 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 533 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TEXT; 
        all_fields[field_number].max_length = 16777215;
        }
#line 2469 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 537 "sql_parser.y" /* yacc.c:1646  */
    { 
        all_fields[field_number].type = FT_TEXT; 
        all_fields[field_number].max_length = 4294967295;
        }
#line 2478 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 541 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_ENUM; }
#line 2484 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 541 "sql_parser.y" /* yacc.c:1646  */
    {
        all_fields[field_number].fixed_length = (n_values > 255) ? 2 : 1;
        }
#line 2492 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 544 "sql_parser.y" /* yacc.c:1646  */
    { all_fields[field_number].type = FT_SET; }
#line 2498 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 544 "sql_parser.y" /* yacc.c:1646  */
    {
        int set_size = (n_values + 7 ) / 8;
        all_fields[field_number].fixed_length = (set_size > 4 ) ? 8 : set_size;
        }
#line 2507 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 548 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type GEOMETRY"); }
#line 2513 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 549 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type POINT"); }
#line 2519 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 550 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type LINESTRING"); }
#line 2525 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 551 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type POLYGON"); }
#line 2531 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 552 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type MULTIPOINT"); }
#line 2537 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 553 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type MULTILINESTRING"); }
#line 2543 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 554 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type MULTIPOLYGON"); }
#line 2549 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 555 "sql_parser.y" /* yacc.c:1646  */
    { error("Unsupported type GEOMETRYCOLLECTION"); }
#line 2555 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 560 "sql_parser.y" /* yacc.c:1646  */
    { is_length = 1; }
#line 2561 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 562 "sql_parser.y" /* yacc.c:1646  */
    { length = (yyvsp[0].si); }
#line 2567 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 564 "sql_parser.y" /* yacc.c:1646  */
    { is_unsigned = 1; }
#line 2573 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 570 "sql_parser.y" /* yacc.c:1646  */
    {is_length = 1; length = (yyvsp[0].si);}
#line 2579 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 570 "sql_parser.y" /* yacc.c:1646  */
    { is_decimals = 1; decimals = (yyvsp[0].si); }
#line 2585 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 572 "sql_parser.y" /* yacc.c:1646  */
    { is_length = 1; }
#line 2591 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 576 "sql_parser.y" /* yacc.c:1646  */
    {
        // if field is multibyte multiply its max size
        unsigned int factor = 1;
        if(strcmp((yyvsp[0].str), "utf8") == 0) factor = 3;
        if(strcmp((yyvsp[0].str), "utf8mb4") == 0) factor = 4;
        all_fields[field_number].fixed_length = all_fields[field_number].fixed_length * factor;
        }
#line 2603 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 646 "sql_parser.y" /* yacc.c:1646  */
    { strncpy(table_name, (yyvsp[0].str), strlen((yyvsp[0].str))); }
#line 2609 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 647 "sql_parser.y" /* yacc.c:1646  */
    { strncpy(table_name, (yyvsp[0].str), strlen((yyvsp[0].str))); }
#line 2615 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 649 "sql_parser.y" /* yacc.c:1646  */
    { n_values++; }
#line 2621 "sql_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 650 "sql_parser.y" /* yacc.c:1646  */
    { n_values++; }
#line 2627 "sql_parser.c" /* yacc.c:1646  */
    break;


#line 2631 "sql_parser.c" /* yacc.c:1646  */
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
#line 659 "sql_parser.y" /* yacc.c:1906  */

#include "lex.yy.c"

void yyerror(char *errmsg)
{
    fprintf(stderr, "Line %u: %s at '%s'\n", lineno, errmsg, yytext);
    fprintf(stderr, "%2u: %s\n", lineno -1 , linebuf_prev);
    fprintf(stderr, "%2u: %s\n", lineno , linebuf);
}

int load_table(char* f){
#ifdef DEBUG
    yydebug=1;
#endif
    extern FILE *yyin;
    yyin = fopen(f, "r");
    if(yyin == NULL){
        fprintf(stderr, "Could not open file %s\n", f);
        perror("load_table()");
        exit(EXIT_FAILURE);
    }
    // save first line in case there is an error in it
    if(NULL == fgets(linebuf, sizeof(linebuf), yyin)){
        fprintf(stderr, "Could not read from %s\n", f);
        exit(EXIT_FAILURE);
        }
    rewind(yyin);
    return yyparse();    
}

//int main(int argc, char** argv){
//    load_table(argv[1]);
//}
