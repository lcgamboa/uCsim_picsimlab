/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PTOK_PLUS = 258,               /* PTOK_PLUS  */
    PTOK_MINUS = 259,              /* PTOK_MINUS  */
    PTOK_ASTERIX = 260,            /* PTOK_ASTERIX  */
    PTOK_SLASH = 261,              /* PTOK_SLASH  */
    PTOK_EQUAL = 262,              /* PTOK_EQUAL  */
    PTOK_LEFT_PAREN = 263,         /* PTOK_LEFT_PAREN  */
    PTOK_RIGHT_PAREN = 264,        /* PTOK_RIGHT_PAREN  */
    PTOK_LEFT_BRACKET = 265,       /* PTOK_LEFT_BRACKET  */
    PTOK_RIGHT_BRACKET = 266,      /* PTOK_RIGHT_BRACKET  */
    PTOK_DOT = 267,                /* PTOK_DOT  */
    PTOK_AMPERSAND = 268,          /* PTOK_AMPERSAND  */
    PTOK_PIPE = 269,               /* PTOK_PIPE  */
    PTOK_CIRCUM = 270,             /* PTOK_CIRCUM  */
    PTOK_PERCENT = 271,            /* PTOK_PERCENT  */
    PTOK_TILDE = 272,              /* PTOK_TILDE  */
    PTOK_QUESTION = 273,           /* PTOK_QUESTION  */
    PTOK_COLON = 274,              /* PTOK_COLON  */
    PTOK_EXCLAMATION = 275,        /* PTOK_EXCLAMATION  */
    PTOK_LESS = 276,               /* PTOK_LESS  */
    PTOK_GREATHER = 277,           /* PTOK_GREATHER  */
    PTOK_COMMA = 278,              /* PTOK_COMMA  */
    PTOK_AND_OP = 279,             /* PTOK_AND_OP  */
    PTOK_OR_OP = 280,              /* PTOK_OR_OP  */
    PTOK_INC_OP = 281,             /* PTOK_INC_OP  */
    PTOK_DEC_OP = 282,             /* PTOK_DEC_OP  */
    PTOK_EQ_OP = 283,              /* PTOK_EQ_OP  */
    PTOK_NE_OP = 284,              /* PTOK_NE_OP  */
    PTOK_GE_OP = 285,              /* PTOK_GE_OP  */
    PTOK_LE_OP = 286,              /* PTOK_LE_OP  */
    PTOK_LEFT_OP = 287,            /* PTOK_LEFT_OP  */
    PTOK_RIGHT_OP = 288,           /* PTOK_RIGHT_OP  */
    PTOK_MUL_ASSIGN = 289,         /* PTOK_MUL_ASSIGN  */
    PTOK_DIV_ASSIGN = 290,         /* PTOK_DIV_ASSIGN  */
    PTOK_MOD_ASSIGN = 291,         /* PTOK_MOD_ASSIGN  */
    PTOK_ADD_ASSIGN = 292,         /* PTOK_ADD_ASSIGN  */
    PTOK_SUB_ASSIGN = 293,         /* PTOK_SUB_ASSIGN  */
    PTOK_LEFT_ASSIGN = 294,        /* PTOK_LEFT_ASSIGN  */
    PTOK_RIGHT_ASSIGN = 295,       /* PTOK_RIGHT_ASSIGN  */
    PTOK_AND_ASSIGN = 296,         /* PTOK_AND_ASSIGN  */
    PTOK_XOR_ASSIGN = 297,         /* PTOK_XOR_ASSIGN  */
    PTOK_OR_ASSIGN = 298,          /* PTOK_OR_ASSIGN  */
    PTOK_INT = 299,                /* PTOK_INT  */
    PTOK_MEMORY_OBJECT = 300,      /* PTOK_MEMORY_OBJECT  */
    PTOK_MEMORY = 301,             /* PTOK_MEMORY  */
    PTOK_NUMBER = 302,             /* PTOK_NUMBER  */
    PTOK_BIT = 303                 /* PTOK_BIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PTOK_PLUS 258
#define PTOK_MINUS 259
#define PTOK_ASTERIX 260
#define PTOK_SLASH 261
#define PTOK_EQUAL 262
#define PTOK_LEFT_PAREN 263
#define PTOK_RIGHT_PAREN 264
#define PTOK_LEFT_BRACKET 265
#define PTOK_RIGHT_BRACKET 266
#define PTOK_DOT 267
#define PTOK_AMPERSAND 268
#define PTOK_PIPE 269
#define PTOK_CIRCUM 270
#define PTOK_PERCENT 271
#define PTOK_TILDE 272
#define PTOK_QUESTION 273
#define PTOK_COLON 274
#define PTOK_EXCLAMATION 275
#define PTOK_LESS 276
#define PTOK_GREATHER 277
#define PTOK_COMMA 278
#define PTOK_AND_OP 279
#define PTOK_OR_OP 280
#define PTOK_INC_OP 281
#define PTOK_DEC_OP 282
#define PTOK_EQ_OP 283
#define PTOK_NE_OP 284
#define PTOK_GE_OP 285
#define PTOK_LE_OP 286
#define PTOK_LEFT_OP 287
#define PTOK_RIGHT_OP 288
#define PTOK_MUL_ASSIGN 289
#define PTOK_DIV_ASSIGN 290
#define PTOK_MOD_ASSIGN 291
#define PTOK_ADD_ASSIGN 292
#define PTOK_SUB_ASSIGN 293
#define PTOK_LEFT_ASSIGN 294
#define PTOK_RIGHT_ASSIGN 295
#define PTOK_AND_ASSIGN 296
#define PTOK_XOR_ASSIGN 297
#define PTOK_OR_ASSIGN 298
#define PTOK_INT 299
#define PTOK_MEMORY_OBJECT 300
#define PTOK_MEMORY 301
#define PTOK_NUMBER 302
#define PTOK_BIT 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 59 "cmdpars.y"

  long number;
  class cl_memory *memory_object;
  struct {
    class cl_memory *memory;
    long address;
  } memory;
  struct {
    class cl_memory *memory;
    long mem_address, bit_address;
    long mask;
  } bit;

#line 176 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
