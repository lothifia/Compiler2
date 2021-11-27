%{
    #include<stdio.h>
    #include "yacc.h"
    int line;
    void yyerror(char*);
    int yywrap(void);
%}

num [0-9]+
char [A-Za-z]+[A-Za-z0-9]*
eq [=]
plus [+]
minus [-]
mul [*]
dev [/]

%%
"main" {return MAIN;}
"int" {return INT;}
"char" {return CHAR;}
"const" {return CONST;}
"if" {return IF;}
"else" {return ELSE;}
"write" {return WRITE;}
"read" {return READ;}
"while" {return WHILE;}
"for" {return FOR;}

"["  {return LMB;}
"]" {return RMB;}
[(] {return LP;}
[)] {return RP;}
[{] {return LB;}
[}] {return RB;}
[\n] {++line;}
"!=" {return NEQ;}
">=" {return GEQ;}
"<=" {return LEQ;}
">" {return GTR;}
"<" {return LSS;}
"=" { return EQL;}
"+" { return Plus;}
"-" {return Minus;}
"*" { return Mul;}
[/] { return Div;}
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