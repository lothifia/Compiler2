%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    #include<stdbool.h>
    #include "head.h"

    FILE* fin;
    FILE* fresult = NULL;
    FILE* ftable = NULL;
    FILE* fbug = NULL;
    FILE* fpcode = NULL;

    void init();
    void enter(enum object k);
    void _enter(enum object k, int IsArry);
    void setdx(int n);
    void gen(enum fct x, int y, int z);
    void displaytable();
    void listall();
    void interpret();
    int base(int l, int* s, int b);
    void yyerror(const char* s);
    int position(char* a);
    int yylex();
    void redirectInput(FILE *input);
                        char get_void;
%}
%define parse.error verbose /* verbose yyerror messages */

%union{
    int NUM;
    char* VAR;
    char* OP;
}

%token<NUM> num
%token<VAR> var CHAR INT VOID STRING
%token<OP> Plus Div Minus Mul EQL GEQ LEQ LSS GTR NEQ
%token END LB RB LP RP MAIN SEMI_t COMMA CONST PROC IF ELSE READ WRITE FOR WHILE LMB RMB RETURN PP DD RED
%type<NUM> get_table_addr get_code_addr declaration_list VarInit Vardecl Vardef 
%type<NUM> block var_p var_t prevardecl prevardef pass_factor for_3 arry_n
%type statement VarInit Vardef condition STRING defunc

%%
/* main{ block } */
procstart:
    get_code_addr
    {
        preVar_cnt = 0;
        gen(jmp, 0, 0);
    }
    defunc 
    MAIN
    {
        /* Main procedure */
        strcpy(id, "main");
        _enter(procedure, 0);
        table[tx].adr = cx;
        table[tx].t = xvoid;
        code[$1].a = cx;
        proctable[px] = tx;

    } get_table_addr
    LB block RB
    {
        table[$6].size =  total_var;
    }
    ;

var_t: INT {$$ = 1;}| CHAR {$$ = 2;}| VOID {$$ = 3;}
    ;

defunc: 
    var_t var
    {
        strcpy(id, $2);
        _enter(procedure, 0);
        if($1 == 1){
            table[tx].t = xint;
        }else if($1 == 2){
            table[tx].t = xchar;
        }else if($1 == 3){
            table[tx].t = xvoid;
        }
        proc_p = tx;
    } 
    get_table_addr get_code_addr LP prevardecl RP
    {
        table[$4].adr = $5;
        table[$4].parameter_cnt = $7;
        printf("pcnt = %d, table addr is %d\n", $7, $5);
        preVar_cnt = $7;
    }
    LB block RB 
    {
        table[$4].size = total_var;
        preVar_cnt = 0;
        total_var = 0;
        proc_p = 0;
    }
    defunc
    |
    ;
prevardecl: prevardef { $$ = $1 ; }
    | prevardef COMMA prevardecl
    {
        $$ = $1 + $3;
    }
    | { $$ = 0 ;}
    ;
prevardef: var_t var
    {
        strcpy(id, $2);
        _enter(variable, 0);
        if($1 == 1) table[tx].t = xint;
        else if($1 == 2) table[tx].t = xchar;
        total_var ++;
        $$ = 1;
    }
    | var_t var arry_n
    {
        $$ = 1;
        strcpy(id, $2);
        _enter(variable, $3);
        if($1 == 1) table[tx].t = xint;
        else if($1 == 2) table[tx].t = xchar;
        total_var += $3;
        $$ = 1;
    }
    ;
arry_n:
    arry_n LMB num RMB 
    {
        $$ = $1 + $3;
    }
    | {$$ = 0;}
    ;
block:
    declaration_list
    {
        setdx($1 + preVar_cnt);
        gen(ini, 0, total_var + 3);
        for(int i = 0; i < preVar_cnt; i++){
            gen(sto, -1 - i , 2 + preVar_cnt - i);
        }
        
    }
    statements
    {
        gen(opr, preVar_cnt, 0);
        preVar_cnt = $1 + preVar_cnt;
    }
    ;

declaration_list: 
    Constdecl Vardecl 
    {
        printf("total_var: %d\n",total_var);
        $$ = $2;
    }
    |{$$ = 0 ;}
    ;

Vardecl: var_t VarInit SEMI
     {
         if($1 == 1){
         while(varx > 0){
             table[vartable[varx - 1]].t = xint;
             --varx;
         }
         }
         else{
             while(varx > 0){
                 table[vartable[varx - 1]].t = xchar;
                 --varx;
             }
         }
     }
     Vardecl
    {
        printf("2: %d, 5: %d\n", $2, $5);
        $$ = $2 + $5;
    }
    | {$$ = 0;}
    ;

VarInit: Vardef 
    { 
        $$ = $1;
    }
    | Vardef COMMA VarInit {$$ = $1 + $3;}
    ;

Vardef: var 
    {
        ++total_var;
        strcpy(id, $1);
        _enter(variable, 0);
        $$ = 1;
        vartable[varx] = tx;
        ++varx;
    }
    | var LMB num RMB
    {
        total_var += $3;
        strcpy(id, $1);
        _enter(variable, $3);
        $$ = 1;

        vartable[varx] = tx;
        ++varx;
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
        _enter(constant, 0);
    }
    ;

/*statement */
var_p :var
    {
        isString = 0;
        $$ = position($1);
        if(table[$$].t == xchar && table[$$].is_arry) isString = 1;

    }
    | var LMB factor RMB
    {
        isString = 0;
        $$ = position($1);
        gen(lit, 0, table[$$].adr);
        gen(lit, 0, lev - table[$$].level);
    }
    ;
statements :
    statement statements
    |
    ;
statement:
       asgnstm_semi
    |   callstm
    |   ifstm
    |   whilestm
    |   readstm
    |   writestm
    |   forstm
    |   returnstm
    |   error SEMI
    ;
asgnstm_semi: asgnstm_tot get_sto SEMI;

asgnstm_tot: asgnstm
    | asgnstm COMMA asgnstm_tot
    ;
get_sto:
    {
        while(forx > for_var)
        {
            if(table[fortable[forx - 1]].is_arry){
                gen(sto, 0, 0);
                --forx;
            }else{
                gen(sto, lev - table[fortable[forx - 1]].level, table[fortable[forx - 1]].adr);
                --forx;
            }
        }
    }
    ;

returnstm:
    {
        if(table[proc_p].t == xvoid) yyerror("error void cannot return\n");
    }
    RETURN 
    expression SEMI
    {
        gen(sto, -1, 0);
        gen(opr, preVar_cnt, 0);
        --px;
    }
    ;
compstm: statement
    | LB statements RB;
asgnstm:
    var_p 
    EQL expression
    {
        /*
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else{
                if(table[$1].is_arry == 0) {gen(sto, lev - table[$1].level, table[$1].adr);}
                else{
                    gen(sto, 0, 0);
                }
            }
        }
        */
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else{
                fortable[forx] = $1;
                ++forx;
            }
        }
    }
    |var_p EQL STRING
    {
        strcpy(temstr, $3);
        printf("-----------qweqwcasdasdasd---------------: %c  \n", temstr[0]);
        if(isString)
        {
            int teml = table[$1].is_arry;
            for(int i = 0; i < teml; i++){
                gen(lit, 0 , i);
                gen(lit, 0, table[$1].adr);
                gen(lit, 0, lev - table[$1].level);
                gen(lit, 0, temstr[i]);
                fortable[forx] = $1;
                ++forx;
            }
        } else{
        printf("-----------qweqwcasdasdasd---------------: %c  \n", temstr[0]);
            if(strlen(temstr) > 1) yyerror("not a char\n");
            gen(lit, 0, temstr[0]);
            fortable[forx] = $1;
            ++forx;
        }
    }
    |var_p
    ;
callstm:
    ;
forstm:
    FOR LP 
    for_1 SEMI get_code_addr condition get_code_addr
    {
        gen(jpc, 0, 0);
    }
    SEMI for_3
    {
        for_var += $10;
        for_lev[for_lx] = $10;
        ++for_lx;
    }
    RP compstm 
    {
        for_var -= for_lev[--for_lx];
    }
    get_sto
    {
        gen(jmp, 0, $5);
        printf("jpc = %d\n", $7);
        code[$7].a = cx;
    }
    ;
for_1:  asgnstm_tot get_sto|
    ;
for_2: condition |
    ;
for_3:  asgnstm { $$ = 1; }
    |   asgnstm COMMA for_3 {$$ = 1 + $3;}
    ;
ifstm: IF LP condition RP get_code_addr
    {
        gen(jpc,0,0);
    }
    compstm get_code_addr
    {
        gen(jmp, 0, 0);
        code[$5].a = cx;
    }
    elsestm 
    {
        code[$8].a = cx;
    }
    ;
elsestm: ELSE compstm 
    |
    ;
whilestm: WHILE LP get_code_addr condition RP get_code_addr
    {
        gen(jpc, 0, 0);
    }
     compstm 
    {
        gen(jmp, 0, $3);
        printf("now cx: %d----------------------------------------", cx);
       code[$6].a = cx;
    }
    ;
readstm: READ var_p SEMI
    {
        if(table[$2].is_arry == 0){
            if(table[$2].t == xchar){
                gen(opr, -1, 16);
                gen(sto, lev - table[$2].level, table[$2].adr);
            }else{
            gen(opr, 0, 16);
            gen(sto, lev - table[$2].level, table[$2].adr);
            }
        }else {
            if(isString == 0) {
                gen(opr, 0, 16);
                gen(sto, 0, 0);
            }
            else{
                gen(opr, table[$2].is_arry, 16);
                printf("is_arry = %d \n" , table[$2].is_arry);
                for(int i = 0; i < table[$2].is_arry; i++)
                {
                    gen(lit, 0, i);
                    gen(lit, 0, table[$2].adr);
                    gen(lit, 0, lev - table[$2].level);
                    gen(sto, table[$2].is_arry, 0);
                }
            }
        }
    }
    ;
writestm:WRITE var_p SEMI
    {
        if(table[$2].is_arry == 0 && table[$2].t != xchar){
            gen(lod, lev - table[$2].level,table[$2].adr);
            gen(opr, 0, 14);   
            gen(opr, 0, 15);
        }else if(table[$2].is_arry == 0 && table[$2].t == xchar){
            gen(lod, lev - table[$2].level,table[$2].adr);
            gen(opr, -1, 14);   
            gen(opr, 0, 15);
        }
        else{
            if(isString == 0 && table[$2].t == xchar){
                printf("asdfhoasdgjlasdkjglasdjfl");
                gen(lod, 0, 0);
                gen(opr, -1, 14);   
                gen(opr, 0, 15);
            }else if(isString == 0 && table[$2].t == xint){
                gen(lod, 0, 0);
                gen(opr, 0, 14);
                gen(opr, 0, 15);
            }else{
                for(int i =0; i < table[$2].is_arry; i++){
                    gen(lod, lev - table[$2].level, table[$2].adr + i);
                }
                gen(opr, table[$2].is_arry, 14);
            }
        }
    }
    | WRITE expression SEMI
    {
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
    |   expression RED expression
        {
            gen(opr, 0, 17);
        }
    ;
factor: var_p
    {
        if($1 == 0) yyerror("Symbol not found \n");
        else{
            if(table[$1].kind == procedure) yyerror("procedure can not be variable\n");
            else{
                if(table[$1].kind == constant) gen(lit, 0, table[$1].val);
                else{
                    if(table[$1].is_arry){
                        printf("$1 is :%d, \n", $1);
                        gen(lod, 0, 0);
                    }else{
                        printf("name %s, adr %d", table[$1].name, table[$1].adr);
                        gen(lod, lev - table[$1].level, table[$1].adr);
                    }
                }
            }
        }
    }
    | num
    {
        gen(lit, 0, $1);
    }
    | LP expression RP
    |call_func
    ;
call_func:
    var_p 
    {
        ++px;
        proctable[px] = $1;
    }
    LP pass_factor RP
    {
        if(table[$1].kind != procedure) yyerror("Is  not a procedure \n");
        else{
            if($4 !=  table[$1].parameter_cnt ) yyerror("parameter number not match\n");
            gen(cal, 0, table[$1].adr);
            if(table[$1].t != xvoid) gen(lod, -1, 0); /* get return */
        }
    }
    ;

pass_factor: factor {$$ = 1;}
    | factor COMMA pass_factor
        {$$ = 1 + $3;}
    | {$$ = 0;}
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
SEMI: SEMI_t get_sto
    |
    {
        yyerror("miss a SEMICOM");
    }
    ;
%%

void yyerror(const char* s){
    fprintf(fbug,"error!:%s , located at %d line\n", s, line);
}
void init()
{
	tx = 0;
	cx = 0;
	px = 0;
    forx = 0;
    varx = 0;
    lev = 0;   
    proctable[0] = 0;
    c_num = 0;
    err = 0;
    total_var = 0;
    for_var = 0;
    for_lx = 0;
    offset = 0;
}
int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = tx;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void _enter(enum object k, int IsArry)
{
    enter(k);
    table[tx].is_arry = IsArry;
}
void enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case constant:	/* ?????? */			
			table[tx].val = c_num; /* ?????????????????? */
			break;
		case variable:	/* ?????? */
			table[tx].level = lev;	
			break;
		case procedure:	/* ?????? */
			table[tx].level = lev;
			break;
	}
}
void setdx(int n)
{
    printf("---------------%d\n", n);
    int addr = 3 + total_var;
    for(int i = 1; i <= n; i++){
        if(table[tx - i + 1].is_arry){
            addr -= table[tx - i + 1].is_arry;
        }else{
            addr -= 1;
        }
        table[tx - i + 1].adr = addr;
    }
}

void gen(enum fct x, int y, int z)
{
	if (cx >= cxmax)
	{
		printf("Program is too long!\n");	/* ???????????????????????????????????? */
		exit(1);
	}
	if ( z >= amax)
	{
		printf("Displacement address is too big!\n");	/* ?????????????????? */
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
        fprintf(fpcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);

        
    }
}

void displaytable()
{
	int i;
    /* ??????????????? */
	printf("tx : %d\n", tx);
	for (i = 1; i <= tx; i++)
		{
            printf("kind : %d\n", table[i].kind);         
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val);
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d ", table[i].level, table[i].adr);
                    if(table[i].t == xint) printf("type = int \n");
                    else printf("type = char \n");
					fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					break;
			}
		}
		printf("\n");
		fprintf(ftable, "\n");
}
void interpret()
{
	int p = 0; /* ???????????? */
	int b = 1; /* ???????????? */
	int t = 0; /* ???????????? */
	struct instruction i;	/* ?????????????????? */
	int s[stacksize];	/* ??? */

	printf("Start pl0\n");
	fprintf(fresult,"Start pl0\n");
	s[0] = 0; /* s[0]?????? */
	s[1] = 0; /* ???????????????????????????????????????0 */
	s[2] = 0;
	s[3] = 0;

	do {
	    i = code[p];	/* ??????????????? */
		p = p + 1;
		switch (i.f)
		{
			case lit:	/* ?????????a?????????????????? */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* ????????????????????? */
				switch (i.a)
				{
					case 0:  /* ??????????????????????????? */
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        t -= i.l;
                        printf("return to t: %d p: %d b: %d \n *******\n", t, p, b);
						break;
					case 1: /* ?????????????????? */
						s[t] = - s[t];
						break;
					case 2: /* ?????????????????????????????????????????????????????????????????? */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* ??????????????????????????? */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* ??????????????????????????? */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* ??????????????????????????? */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* ??????????????????????????? */
						s[t] = s[t] % 2;
						break;
					case 8:/* ???????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* ???????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* ????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* ??????????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* ????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* ??????????????????????????????????????? */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* ??????????????? */
                        if(i.l == 0){
                            printf("%d", s[t]);
                            fprintf(fresult, "%d", s[t]);
                            t = t - 1;
                        }else if(i.l > 0){
                            memset(buffer, 0, sizeof(buffer));
                            for(int ii = 0; ii < i.l; ii++){
                                printf("t is %d s[t]: %d \n", t ,s[t]);
                                buffer[i.l - ii - 1] = s[t];
                                t = t - 1;
                            }
                            printf("here output %s\n", buffer);
                        }else if(i.l == -1){
                            
                            char c = s[t];
                            t = t - 1;
                            printf("%c", c);
                        }
						break;
					case 15:/* ??????????????? */
						printf("\n");
					    fprintf(fresult,"\n"); 
						break;
					case 16:/* ?????????????????????????????? */
                        if(i.l == 0){
                            t = t + 1;
                            printf("?");
                            /* fprintf(fresult, "?"); */
                            scanf("%d", &(s[t]));
                            /* fprintf(fresult, "%d\n", s[t]); */						
                        }else if(i.l < 0){
                            t = t + 1;
                            printf("?");
                            scanf("%c", &(s[t]));
                        }else{
                            printf("? (need a string)");
                            scanf("%s", buffer);
                            printf("i.l %d, t %d \n", i.l, t);
                            for(int cnt_i = 0; cnt_i < i.l; cnt_i++){
                                printf("t %d, buffer %d \n", t, buffer[cnt_i]);
                                t = t + 1;
                                s[t] = buffer[cnt_i];
                            }
                        }
                        getchar();
                        break;
                    case 17:
                        t = t - 1;
                        s[t] = s[t] % s[t + 1];

						break;
				}
				break;
			case lod:	/* ??????????????????????????????????????????a???????????????????????? */
                if(i.l < 0){
                    t = t + 1;
                    s[t] = s[0];
                }
                else if(i.l == 0 && i.a == 0){
                    s[t - 2] = s[base(s[t],s, b) + s[t - 1] + s[t - 2]];
                    t = t - 2;
                }else if(i.l >0 && i.a > 0){
                    t = t + 1;
                    s[t] = s[base(i.l, s, b) + i.a];
                }else{
				    t = t + 1;
				    s[t] = s[base(i.l,s,b) + i.a];				
                }
                    /* printf("t is %d,lod at : %d  + %d ,%d \n",t ,base(i.l, s, b), i.a, s[base(i.l, s,b) + i.a]); */
				break;
			case sto:	/* ?????????????????????????????????????????????????????????a????????? */
                if(i.l < 0 && i.a != 0){
                    s[b + i.a] = s[b + i.l];   
                }else if(i.l < 0 && i.a == 0){
                    s[0] = s[t];
                }else if(i.l == 0 && i.a == 0){
                    s[base(s[t - 1], s, b) + s[t - 2] + s[t - 3]] = s[t];
                    t = t - 4;
                }else if(i.l > 0 && i.a == 0){
                    s[base(s[t], s, b) + s[t - 1] + s[t - 2]] = s[t - 2 - i.l + s[t - 2]];
                    printf("t is %d,sto at : %d,  %d , %d \n",
                            t,
                            base(s[t], s, b) + s[t - 1] + s[t - 2],
                            s[t - 2],
                            s[t - 2 - i.l + s[t - 2]]);
                    t = t - 3;
                }else{
				    s[base(i.l, s, b) + i.a] = s[t];
				    t = t - 1;
                }
                    /* printf("t is %d,sto at : %d  + %d , %d \n",t ,base(i.l, s, b), i.a, s[b  + i.a]); */
				break;
			case cal:	/* ??????????????? */
                printf("now call , t at %d\n", t);
				s[t + 1] = base(i.l, s, b);	/* ???????????????????????????????????????????????? */
				s[t + 2] = b;	/* ???????????????????????????????????????????????? */
				s[t + 3] = p;	/* ??????????????????????????????????????????????????? */
				b = t + 1;	/* ???????????????????????????????????????????????? */
				p = i.a;	/* ?????? */
                printf("t: %d p: %d b: %d \n *******\n", t, p, b);
				break;
			case ini:	/* ??????????????????????????????????????????a????????????????????? */
				t = t + i.a;	
                printf("ini t is %d\n", t);
				break;
			case jmp:	/* ???????????? */
				p = i.a;
				break;
			case jpc:	/* ???????????? */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End pl0\n");
	fprintf(fresult,"End pl0\n");
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
    line = 0;
    printf("Input file        ");
    scanf("%s", fname);
    getchar();
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    if ((fresult = fopen("fresult.txt", "w")) == NULL)
    {
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
	if ((fpcode = fopen("fpcode.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
	if ((fbug = fopen("fbug.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
    
    redirectInput(fin);
    init();
    yyparse();
    displaytable();
    listall();
    interpret();

    fclose(fin);
    fclose(ftable);
    fclose(fresult);
    fclose(fpcode);
    fclose(fbug);

    return 0;
}
