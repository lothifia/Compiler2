%{
    #include<stdio.h>
    #include "yacc.h"
    int line;
    void yyerror(char*);
    int yywrap(void);
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
[+] {printf("get +\n"); return Plus;}
[-] {printf("get -\n"); return Dec;}
[*] {printf("get *\n"); return Mul;}
[/] {printf("get /\n"); return Div;}
{num} {
    printf("get a num %d\n", atoi(yytext));
    yylval.NUM = atoi(yytext);
    return num;
    }
{char} {printf("get a char %s\n", yytext);}
%%

void redirectInput(FILE *input){
    yyin = input;
}
int  yygetchar(void){
    int ret;
    ret = getc(yyin);
    printf("%c", ret);
    return ret;
}


int yywrap(void)
{
    return 1;
}