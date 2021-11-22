%{
    #include "yacc.tab.h"
    #include<stdio.h>
    int line;

%}

num [0-9]+
char [A-Za-z]
eq [=]
plus [+]
minus [-]
mul [*]
dev [/]
%%
[\n] {++line; return END;}
[+] {printf("get +\n"); return plus;}
{num} {
    printf("get a num %d\n", atoi(yytext));
    yylval.NUM = atoi(yytext);
    return num;
    }
{char} {printf("get a char %s\n", yytext);}
%%

int yywrap(void)
{
    return 1;
}
int main(void){
    yylex();
    printf("lines: %d\n", line);
    return 0;
}
