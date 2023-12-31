/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 14 "0316050.y" /* yacc.c:1909  */

	int int_val;
	double real_val;
	char *string;
	struct node *node;

#line 147 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
