%option yylineno

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define   Iden    300
#define   IntNo		301
#define	  RealNo  302

/*Define  keywords here:*/
#define	  Program 400
#define	  Begin		401
#define	  End			402
#define	  Var			403
#define	  Integer 404
#define	  Real		405
#define	  While		406
#define	  Do			407
#define		If			408
#define		Then		409
#define		Else		410
#define		Or			411
#define		And			412
#define		Not			413
#define		Array		414
#define		Of			415
#define     For         416
#define     To          417

/*Define double_character terminates: */
#define		LE		500
#define		GE		501
#define		NE		502
#define		DD		503

#define		ERRORCHAR	600

#define MAXSTR 20

static char KeyWord[][MAXSTR]=
{
 "PROGRAM",
 "BEGIN",
 "END",
 "VAR",
 "INTEGER",
 "REAL",
 "WHILE",
 "DO",
 "IF",
 "THEN",
 "ELSE",
 "OR",
 "AND",
 "NOT",
 "ARRAY",
 "OF"
 "For"
 "To"
};

int lineno = 0;
char str1[MAXSTR];
int id_or_keyword(char *);
%}   
/************************************
*	MACRO DEFINITION	*
*************************************/
letter		[A-Za-z]
alnum			[A-Za-z0-9]
d					[0-9]
white			[\t\n\040]
%start		COMMENT

/*****************************************
*	RECOGNIION RULES	         *
*****************************************/
%%

\{														{BEGIN COMMENT;}
<COMMENT>\}										{BEGIN 0;}
<COMMENT>\n										{}
<COMMENT>[^}]+ 								{}
[Bb][eE][Gg][iI][Nn]					{ECHO;return Begin;}
[eE][Nn][Dd]									{ECHO;return End;}
[Pp][Rr][oO][Gg][Rr][Aa][Mm]	{ECHO;return Program;}
[Vv][Aa][Rr]									{ECHO;return Var;}
[Ii][nN][Tt][eE][Gg][eE][Rr]	{ECHO;return Integer;}
[Rr][eE][Aa][lL]							{ECHO;return Real;}
[Ww][Hh][Ii][Ll][Ee]					{ECHO;return While;}
[Dd][oO]					{ECHO;return Do;}
[iI][Ff]					{ECHO;return If;}
[Tt][Hh][Ee][Nn]	{ECHO;return Then;}
[Ee][Ll][Ss][Ee]	{ECHO;return Else;}
[Aa][Nn][Dd]			{ECHO;return And;}
[Oo][Rr]					{ECHO;return Or;}
[Nn][Oo][Tt]			{ECHO;return Not;}
[Aa][Rr][Rr][Aa][Yy]	{ECHO;return Array;}
[Oo][Ff]				{ECHO;return Of;}
[Ff][Oo][Rr]			{ECHO;return For;}
[Tt][Oo]				{ECHO;return To;}

"\.\."		{ECHO;return DD;}
({d}+(\.{d}*)?[Ee]([+-])?{d}+)|({d}*\.{d}+[Ee]([+-])?{d}+)	{ECHO;;strcpy(str1,yytext);return RealNo;}
{d}+\.{d}*|{d}*\.{d}+		{ECHO;strcpy(str1,yytext);return RealNo;}
{d}+										{ECHO;strcpy(str1,yytext);return IntNo;}
\n  						{lineno++; }


"("			{ECHO;return '(';}
")"			{ECHO;return ')';}
"["			{ECHO;return '[';}
"]"			{ECHO;return ']';}
">"			{ECHO;return '>';}
"<"			{ECHO;return '<';}
"="			{ECHO;return '=';}
"<="		{ECHO;return LE;}
">="		{ECHO;return GE;}
"<>"		{ECHO;return NE;}
":"			{ECHO;return ':';}
";"			{ECHO;return ';';}

"\."		{ECHO;return '.';}
"*"			{ECHO;return '*';}
"+"			{ECHO;return '+';}
"-"			{ECHO;return '-';}
"/"			{ECHO;return '/';}
"%"			{ECHO;return '%';}
","			{ECHO;return ',';}
{letter}{alnum}*	{ ECHO;strcpy(str1,yytext);return Iden;}
{white}+		{ECHO;}
{d}+{alnum}+        {printf("Invalid char %s\n",yytext);/*return ERRORCHAR;*/exit(0);}
.						{printf("Invalid char %s\n",yytext);/*return ERRORCHAR;*/exit(0); }

%%
int id_or_keyword(char *str)
{
	unsigned int i,j;
	char *p,buf[MAXSTR];
 
	for(i=0;i<sizeof(KeyWord)/sizeof(KeyWord[0]);i++) { 
		p=str;
		for(j=0;j<strlen(str);j++)
			buf[j]=(char)toupper(p[j]);
		buf[j]='\0';
		
		if(!strcmp(KeyWord[i],buf)){
			break;
		}
	}
	
	if(i<sizeof(KeyWord)/sizeof(KeyWord[0])) return i + 400;
	
	return Iden;
}

#ifdef LEX_MAIN
int main(int argc, char** argv)
{
	int c;
	FILE *pout;
	
	yyin = stdin;
	if(argc>1) {
		if((yyin=fopen(argv[1],"r"))==NULL) {
			printf("Can't open file %s\n",argv[1]); 
			return -1;
		}
	}
	
	pout=fopen("rslt.dat","w");
	while(c=yylex()) {
  	static int i=0;
   	fprintf(pout,"(%4d,  %s)\t", c, yytext); i++;
   	if( i==i/4*4) fprintf(pout,"\n");
  }
	fprintf(pout,"\n");
	fclose(pout);
	return 0;
}
#endif

#ifndef yywrap
int yywrap()
{
	return 1;
}
#endif
