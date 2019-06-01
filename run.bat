@echo off
rem 编译生成ast.exe可执行文件

.\tool\win_flex.exe ast_lex.l

.\tool\win_bison.exe  -d ast_yacc.y

gcc -g ast.c ast_yacc.tab.c  lex.yy.c yacc.c -o parser.exe

echo 以parser.exe + miniPascal程序文本文件名 格式执行

pause



