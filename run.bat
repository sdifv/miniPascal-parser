@echo off
rem ��������ast.exe��ִ���ļ�

.\tool\win_flex.exe ast_lex.l

.\tool\win_bison.exe  -d ast_yacc.y

gcc -g ast.c ast_yacc.tab.c  lex.yy.c yacc.c -o parser.exe

echo ��parser.exe + miniPascal�����ı��ļ��� ��ʽִ��

pause



