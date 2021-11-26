%{
    #define al 10
    #define cxmax 2000
    #define txmax 1000
    #define amax 2048
    #define stacksize 3000

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
    int fortable[cxmax];
    int forx;

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
    int for_val;
    };
    struct tablestruct table[txmax]; /* 符号表 */


    void init();
    void enter(enum object k);
    void setdx(int n);
    void gen(enum fct x, int y, int z);
    void displaytable();
    void listall();
    void interpret();
    int base(int l, int* s, int b);

%}
%union{
    int NUM;
    char* VAR;
    char* OP;
}

%token<NUM> num INT
%token<VAR> var CHAR
%token<OP> Plus Div Minus Mul EQL GEQ LEQ LSS GTR NEQ
%token END LB RB LP RP MAIN SEMI COMMA CONST PROC IF ELSE READ WRITE FOR WHILE
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
        gen(opr, 0, 0);
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
        $$ = position($1);
    }
    ;
statements :
    statement statements
    |
    ;
statement:
       asgnstm SEMI
    |   callstm
    |   ifstm
    |   whilestm
    |   readstm
    |   writestm
    |   forstm
    ;
compstm: statement
    | LB statements RB;
asgnstm:
    var_p EQL expression
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
forstm:
    FOR LP 
    for_1 SEMI get_code_addr condition get_code_addr
    {
        gen(jpc, 0, 0);
    }
    SEMI for_3 RP 
    compstm
    {
        while(forx > 0)
        {
            gen(sto, lev - table[fortable[forx - 1]].level, table[fortable[forx - 1]].adr);
            forx --;
        }
        gen(jmp, 0, $5);
        printf("jpc = %d\n", $7);
        code[$7].a = cx;
    }
    ;
for_1:  asgnstm |
    ;
for_2: condition |
    ;
for_3:  for_asgn
    |   for_asgn COMMA for_3
    ;
for_asgn:var_p EQL expression
    {
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else{
                fortable[forx] = $1;
                forx ++;
            }

        }
    }

ifstm: IF LP condition RP get_code_addr
    {
        gen(jpc,0,0);
    }
    compstm
    {code[$5].a = cx;}
    ;

whilestm: WHILE LP get_code_addr condition RP get_code_addr
    {
        gen(jpc, 0, 0);
    }
     compstm 
    {
        gen(jmp, 0, $3);
       code[$6].a = cx;
    }
    ;
readstm: READ var_p SEMI
    {
        gen(opr, 0, 16);
        gen(sto, lev - table[$2].level, table[$2].adr);
    }
    ;
writestm:WRITE var_p SEMI
    {
        gen(lod, lev - table[$2].level,table[$2].adr);
        gen(opr, 0, 14);   
        gen(opr, 0, 15);
    }
    ;

condition: expression EQL expression
            {
                gen(opr, 0, 8);
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
        |   expression
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
                else{
                    gen(lod, lev - table[$1].level, table[$1].adr);
                }
            }
        }
    }
    | num
    {
        gen(lit, 0, $1);
    }
    | LP expression RP
    ;

/*calc test
calcblock:
    num Plus num{$$ = $1 + $3;}
    |
    num Div num{$$ = $1 / $3;}
    |
    num Minus num{$$ = $1 - $3;}
    |
    num Mul num{$$ = $1 * $3;}
    ;
*/
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
    forx = 0;
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
void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;	/* 存放当前指令 */
	int s[stacksize];	/* 栈 */

	printf("Start pl0\n");
	/* fprintf(fresult,"Start pl0\n"); */
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;

	do {
	    i = code[p];	/* 读当前指令 */
		p = p + 1;
		switch (i.f)
		{
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
                        printf("t: %d \n p: %d \nb: %d \n ******\n", t, p, b);
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
                        printf("t: %d \n p: %d \nb: %d \n *******\n", t, p, b);
						break;
					case 1: /* 栈顶元素取反 */
						s[t] = - s[t];
						break;
					case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* 次栈顶项减去栈顶项 */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* 次栈顶项乘以栈顶项 */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* 次栈顶项除以栈顶项 */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* 栈顶元素的奇偶判断 */
						s[t] = s[t] % 2;
						break;
					case 8:/* 次栈顶项与栈顶项是否相等 */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* 次栈顶项与栈顶项是否不等 */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* 次栈顶项是否小于栈顶项 */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* 次栈顶项是否大于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* 次栈顶项是否大于栈顶项 */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* 次栈顶项是否小于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* 栈顶值输出 */
						printf("%d", s[t]);
						/* fprintf(fresult, "%d", s[t]); */
						t = t - 1;
						break;
					case 15:/* 输出换行符 */
						printf("\n");
					    /* fprintf(fresult,"\n"); */
						break;
					case 16:/* 读入一个输入置于栈顶 */
						t = t + 1;
						printf("?");
						/* fprintf(fresult, "?"); */
						scanf("%d", &(s[t]));
						/* fprintf(fresult, "%d\n", s[t]); */						
						break;
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				t = t + 1;
				s[t] = s[base(i.l,s,b) + i.a];				
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				s[base(i.l, s, b) + i.a] = s[t];
				t = t - 1;
				break;
			case cal:	/* 调用子过程 */
				s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
				break;
			case jmp:	/* 直接跳转 */
				p = i.a;
				break;
			case jpc:	/* 条件跳转 */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End pl0\n");
	/*fprintf(fresult,"End pl0\n");*/
}
int base(int l, int* s, int b)
{
    int bl;
    bl = b;
    while(l > 0){
        bl = s[bl];
        l--;
    }
    return bl;
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
    interpret();
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