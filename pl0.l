%{
    #include<stdio.h>
    #include "yacc.h"
    int line;
    void yyerror(char*);
    int yywrap(void);
%}

num [0-9]+
char [A-Za-z]+[A-Za-z]*
eq [=]
plus [+]
minus [-]
mul [*]
dev [/]

%%
"main" {return MAIN;}
"int" {return INT;}
"char" {return CHAR;}

[{] {return LB;}
[}] {return RB;}
[\n] {++line;}
[=] {printf("get =\n"); return Eql;}
[+] {printf("get +\n"); return Plus;}
[-] {printf("get -\n"); return Dec;}
[*] {printf("get *\n"); return Mul;}
[/] {printf("get /\n"); return Div;}
[;] {return SEMI;}
[,] {return COMMA;}
{num} {
    printf("get a num %d\n", atoi(yytext));
    yylval.NUM = atoi(yytext);
    return num;
    }
{char} {yylval.VAR = (char*)malloc(strlen(yytext) + 1);
        strcpy(yylval.VAR, yytext);
         return var;}
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