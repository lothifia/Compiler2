%{
    #include<stdio.h>

%}
%union{
    int NUM;
    char* VAR;
    char* OP;
}

%token<NUM> num
%token<VAR> var
%token<OP> Plus Div Dec Mul
%type<NUM> block
%token END

%%
procstart:
|
block procstart END{printf("%d", $1);}
;

block:
num Plus num{$$ = $1 + $3;}
;
%%
yyerror(const char* s){
    printf("error!:%s\n", s);
}

int main(){
    yyparse();
    return 0;
}