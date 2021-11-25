%{
    #define al 10
    #define cxmax 2000
    #define txmax 1000
    #define amax 2048


    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    FILE* fin;
    FILE* foutput;
    FILE* ftable;
    char fname[al];
    
    int tx;/*table */
    int cx;/* code*/
    int px;/*proctable*/
    int lev;
    int proctable[3];
    char id[al];
    extern int line;
    int err;
    int c_num;/* use to record const */

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     
    };
    struct instruction
    {
        enum fct f;   /* 虚拟机代码指令 */
        int l;        /* 引用层与声明层的层次差 */
        int a;        /* 根据f的不同而不同 */
    };
    struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */
    enum object 
    {
        constant, 
        variable, 
        procedure,
    };

    /* 符号表结构 */
    struct tablestruct
    {
    char name[al];      /* 名字 */
    enum object kind;   /* 类型：const，var或procedure */
    int val;            /* 数值，仅const使用 */
        int level;          /* 所处层，仅const不使用 */ 
        int adr;            /* 地址，仅const不使用 */
        int size;           /* 需要分配的数据区空间, 仅procedure使用 */
    };
    struct tablestruct table[txmax]; /* 符号表 */


    void init();
    void enter(enum object k);
    void setdx(int n);
    void gen(enum fct x, int y, int z);
    void displaytable();
    void listall();

%}
%union{
    int NUM;
    char* VAR;
    char* OP;
}

%token<NUM> num INT
%token<VAR> var CHAR
%token<OP> Plus Div Minus Mul EQL GEQ LEQ LSS GTR NEQ
%token END LB RB LP RP MAIN SEMI COMMA CONST PROC IF ELSE 
%type<NUM> calcblock get_table_addr get_code_addr declaration_list VarInit Vardecl Vardef 
%type<NUM> block var_p 
%type statement VarInit Vardef condition

%%
/* main{ block } */
procstart:
    | 
    MAIN LB block RB
    ;

block:
    {
       table[tx].adr = cx;
        $<NUM>$ = cx;
        gen(jmp, 0, 0);
    }
    declaration_list
    statements
    {
        listall();
    }
    ;

declaration_list:
    get_table_addr
    Constdecl Vardecl /* Procdecls */
    {
        
        setdx($3);
        printf("cx: %d\n", $1);
        code[$1].a = cx;
        gen(ini, 0, $3 + 3);
        displaytable();
    }
    |
    ;

Vardecl:

    INT VarInit SEMI Vardecl
    {
        $$ = $2 + $4;
    }
    | CHAR VarInit SEMI Vardecl
    {
        $$ = $2 + $4;
    }
    | {$$ = 0;}
    ;

VarInit:
    Vardef { $$ = $1;}
    | Vardef COMMA VarInit {$$ = $1 + $3;}
    ;

Vardef:
    var 
    {
        strcpy(id, $1);
        enter(variable);
        $$ = 1;
    }
    ;
Constdecl:
    CONST CONSTInit SEMI Constdecl
    |
    ;
CONSTInit:
    constdef
    |CONSTInit COMMA constdef
    ;
constdef:
    var EQL num
    {
        strcpy(id, $1);
        c_num = $3;
        enter(constant);
    }
    ;

/*statement */
var_p :var
    {
        printf("get assing var :%s\n", $1);
        $$ = position($1);
    }
    ;
statements :
    statement statements
    |
    ;
statement:
    calcblock {printf("%d \n", $1);} SEMI
    |   asgnstm 
    |   callstm
    |   ifstm
    |   whilestm
    |   readstm
    |   writestm
    ;
asgnstm:
    var_p EQL num SEMI
    {
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else
                gen(sto, lev - table[$1].level, table[$1].adr);
        }
    }
    ;
callstm:
    ;
ifstm: IF LP condition RP get_code_addr
    {
        gen(jpc,0,0);
    }
    statements
    {code[$5].a = cx;}
    ;
whilestm:
    ;
readstm:
    ;
writestm:
    ;

condition: expression EQL expression
            {
                gen(opr, 0, 7);
            }
        |   expression NEQ expression
            {
                gen(opr, 0, 9);
            }
        |   expression LSS expression
            {
                gen(opr, 0, 10);
            }
        |   expression LEQ expression
            {
                gen(opr, 0, 13);
            }
        |   expression GTR expression
            {
                gen(opr, 0, 12);
            }
        |   expression GEQ expression
            {
                gen(opr, 0, 11);
            }
    ;

expression: Plus term
    | Minus term
    {
        gen(opr, 0, 1);
    }
    |term
    |expression Plus term
    {
        gen(opr, 0, 2);
    }
    |expression Minus term
    {
        gen(opr, 0, 3);
    }
    ;
term: factor
    | term Mul factor
    {
        gen(opr, 0, 4);
    }
    |term Div factor
    {
        gen(opr, 0 , 5);
    }
    ;
factor: var_p
    {
        if($1 == 0) yyerror("Symbol not found \n");
        else{
            if(table[$1].kind != variable) yyerror("Symbol should be variable\n");
            else{
                if(table[$1].kind == constant)
                gen(lit, 0, table[$1].val);
                else
                    gen(lod, lev - table[$1].level, table[$1].adr);
            }
        }
    }
    | num
    {
        gen(lit, 0, $1);
    }
    | LP expression RP
    ;

/*calc test*/
calcblock:
    num Plus num{$$ = $1 + $3;}
    |
    num Div num{$$ = $1 / $3;}
    |
    num Minus num{$$ = $1 - $3;}
    |
    num Mul num{$$ = $1 * $3;}
    ;

get_table_addr:
    {
        $$ = tx;
    }
    ;
get_code_addr:
    {
        $$ = cx;
    }
    ;
%%

yyerror(const char* s){
    printf("error!:%s\n, located at %d line\n", s, line);
}
void init()
{
	tx = 0;
	cx = 0;
	px = 0;  
  lev = 0;   
  proctable[0] = 0;
  c_num = 0;
  err = 0;
}
int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = tx;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}
void enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case constant:	/* 常量 */			
			table[tx].val = c_num; /* 登记常数的值 */
			break;
		case variable:	/* 变量 */
			table[tx].level = lev;	
			break;
		case procedure:	/* 过程 */
			table[tx].level = lev;
			break;
	}
}
void setdx(int n)
{
    printf("---------------%d\n", n);
    for(int i = 1; i <= n; i++){
        table[tx - i + 1].adr = n - i + 3;
    }
}

void gen(enum fct x, int y, int z)
{
	if (cx >= cxmax)
	{
		printf("Program is too long!\n");	/* 生成的虚拟机代码程序过长 */
		exit(1);
	}
	if ( z >= amax)
	{
		printf("Displacement address is too big!\n");	/* 地址偏移越界 */
		exit(1);
	}
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx++;
}
void listall()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},
	};
	
    for (i = 0; i < cx; i++)
    {
        printf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        /* fprintf(fcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        */
        
    }
}

void displaytable()
{
	int i;
    /* 输出符号表 */
	printf("tx : %d\n", tx);
	for (i = 1; i <= tx; i++)
		{
            printf("kind : %d\n", table[i].kind);         
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					/* fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val); */
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d\n", table[i].level, table[i].adr);
					/* fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
                    */
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    /*
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    */
					break;
			}
		}
		printf("\n");
		/* fprintf(ftable, "\n"); */
}

int main(){
    printf("Input file        ");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    /* if ((foutput = fopen("foutput.txt", "w")) == NULL)
    {
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
    */
    redirectInput(fin);
    init();

    yyparse();
    fclose(fin);
    /* fclose(ftable);
    fclose(foutput);
    */
    return 0;
}

/* not use
Procdecls:
    Procdecls procdecl procbody
    |
    ;
procdecl:
    inc_px PROC var SEMI
    {
        strcpy(id, $3);
        enter(procedure);
        proctable[px] = tx;
    }
    ;
procbody:
    inc_level block dec_level_px SEMI
    ;
inc_px: { ++px; }
    ;
inc_level: {++lev;}
    ;
dec_level_px: {--px; --lev;}
    ;

    */