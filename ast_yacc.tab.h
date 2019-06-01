/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
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


/* Line 2058 of yacc.c  */
#line 115 "ast_yacc.tab.h"
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
