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
    
    int tx;
    int cx;
    int px;
    int lev;
    int proctable[3];
    char id[al];
    extern int line;
    int err;
    int c_num;

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

%}
%union{
    int NUM;
    char* VAR;
    char* OP;
}

%token<NUM> num INT
%token<VAR> var CHAR
%token<OP> Plus Div Dec Mul Eql
%token END LB RB MAIN SEMI COMMA
%type<NUM> calcblock get_table_addr declaration_list VarInit Vardecl Vardef
%type statement VarInit Vardef

%%
/* main{ block } */
procstart:
    | 
    MAIN LB block RB
    ;

block:
    {
        
        table[tx].adr = cx;
        gen(jmp, 0, 0);
    }
    declaration_list
    statement
    ;

statement:
    calcblock {printf("%d \n", $1);} SEMI
    |
    ;

declaration_list:
    get_table_addr
    
    Vardecl 
procdecls
    {
        
        setdx($2);
        printf("%d var,\n ", $2);
        code[$1].a = cx;
        table[$2].adr = cx;
        table[$2].size = $2 + 3;
        gen(ini, 0, $2 + 3);
    }
    |
    ;

Vardecl:

    INT VarInit SEMI 
    {
        $$ = $2;
    }
    | CHAR VarInit SEMI 
    {
        $$ = $2;
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

procdecls:

    ;


/*calc test*/
calcblock:
    num Plus num{$$ = $1 + $3;}
    |
    num Div num{$$ = $1 / $3;}
    |
    num Dec num{$$ = $1 - $3;}
    |
    num Mul num{$$ = $1 * $3;}
    ;

get_table_addr:
    {
        $$ = tx;
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

void enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case constant:	/* 常量 */			
			table[tx].val = num; /* 登记常数的值 */
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
    for(int i = 0; i <= n; i++){
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