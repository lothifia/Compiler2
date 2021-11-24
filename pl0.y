%{
    #define al 10

    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    FILE* fin;
    FILE* foutput;
    FILE* ftable;
    char fname[al];


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
procstart block END{printf("%d\n", $2);}
;

block:
num Plus num{$$ = $1 + $3;}
|
num Div num{$$ = $1 / $3;}
|
num Dec num{$$ = $1 - $3;}
|
num Mul num{$$ = $1 * $3;}
;
%%
yyerror(const char* s){
    printf("error!:%s\n", s);
}

int main(){
    printf("Input file");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    if ((foutput = fopen("foutput.txt", "w")) == NULL)
    {
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
    redirectInput(fin);

    yyparse();
    fclose(fin);
    fclose(ftable);
    fclose(foutput);
    return 0;
}