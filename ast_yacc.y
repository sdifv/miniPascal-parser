%{
#include <stdlib.h>
#include "ast.h"
#include "yacc.h"

#define MAXSTR 20
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1

int yyerror(char*);

// define in ast.c
extern struct node root;
extern struct node *tmprtn;

extern int yylex();
extern FILE* yyin;
extern char str1[20];

extern int NXQ;
extern int VarCount;
extern struct QUATERLIST QuaterList[MAXMEMBER];
extern struct VARLIST VarList[MAXMEMBER];
int ef = 1;
int flag_var_def = 0;
%}
%start    ProgDef
%union 
{
 struct {
	 union{
		 int Iv;
		 int CH;
		 int NO;
		 struct { int TC,FC;} _BExpr;
		 struct { int QUAD,CH;} _WBD;
		 struct { int type,place; union{int Iv;float Rv;} Value;} _Expr;
		 char _Rop[5];
		 int First;	//连续定义时，符号链的头指针（在符号表中的序号）
		 /*
		  *var是简单变量时，place:变量在符号表中的序号；offset:0
		  *var是下标变量时，place:存放constpart临时变量地址（在表中的序号），offset:存放varpart临时变量地址（在表中的序号）
		  */
		 struct { int PLACE, OFFSET;} _Var;
		 /*
		  *NO：数组名在符号表中的序号
		  *DIM：用于记录已处理数组下标表达式的个数（最后值代表维数）
		  *place:在计算varpart时，记录存放中间结果的临时变量名（地址）
		  */ 
		 struct { int NO, DIM, PLACE;} _Elist;
		 struct { int QUAD,CH,place;} _Loop;
	 } attr;
 	struct node *Node;
 } all;
 char str[20];
}
/*Define const:  */
%token <str>   	Iden    	300
%token <str>   	IntNo		301
%token <str>  	RealNo  	302
/*Define keywords here:*/
%token	<str>  	Program 	400
%token	<str>  	Begin		401
%token	<str> 	End			402
%token	<str>  	Var			403
%token	<str>  	Integer 	404
%token	<str>  	Real		405
%token	<str>  	While		406
%token	<str>  	Do			407
%token	<str>	If			408
%token	<str>	Then		409
%token	<str>	Else		410
%token	<str>	Or			411
%token	<str>	And			412
%token	<str>	Not			413
%token  <str>	Array		414
%token	<str>	Of			415
%token  <str>   For			416
%token  <str>   To 			417

/*Define double_character terminates:   */
%token		LE	500
%token		GE	501
%token		NE	502
%token		DD	503

%left 	Or
%left		And
%nonassoc  	Not
%nonassoc '<' '>' '=' LE GE NE DD
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%type <all> ProgDef	//ast_node
%type <all> SubProg	//ast_node
%type <all> VarDef	//CH
%type <all> VarDefList	//CH
%type <all> Type	//Iv
%type <all> VarDefState	//CH
%type <all> VarList	//First
%type <all> Statement	//CH
%type <all> StateList	//CH
%type <all> S_L	//CH
%type <all> CompState	//CH
%type <all> AsignState	//CH
%type <all> ISE	//CH
%type <all> IBT	//IBT
%type <all> WBD	//_WBD
%type <all> RelationOp	//_Rop
%type <all> Expr 	//_Expr
/*%type <CH> BAND	
%type <CH> BOR*/
%type <all> Wh	//CH
%type <all> Variable //NO-->_Var
%type <all> Const //_Expr
%type <all>	BoolExpr //_BExpr
%type <all> ArrayMSG
%type <all> ArrayVar
%type <all> ExprList //_Elist
%type <all> ForLoop1 //_Loop
%type <all> ForLoop2

%%
ProgDef:	Program Iden {set_node_val_str(&root,str1);} ';' SubProg '.'
          {
		      struct node *tmpnode=NULL;
              //printf("\n\n**** test ast node ****\n\n");
			  $$.Node=&root;
			  $$.Node->type=e_program;
			  tmpnode=$5.Node;
			  add_son_node(&root,$5.Node);
			  printf("\n\n**** Program %s ****\n",root.val.str);
          }
	;
SubProg:	VarDef CompState
		{
		new_node(&($$.Node));
		$$.Node->type = e_sub_prog;
		set_node_val_str($$.Node, "SubProg");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $2.Node);
		}
	;
VarDef:		Var VarDefList ';'
        {
		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_var_def;
		set_node_val_str($$.Node, "Var");
		add_son_node($$.Node, $2.Node);
		}
	;
VarDefList:	VarDefList';'VarDefState
        {
		/* =========================== */
		struct node *last = get_last_node($1.Node);
		add_brother_node(last, $3.Node);
		$$.Node = $1.Node;
		}
	|	VarDefState
	    {
		/* =========================== */
		$$.Node = $1.Node;
        }
	;
VarDefState:	VarList':'Type
		{

		int check = 0;
		while ($1.attr.First) {
			VarList[$1.attr.First].type = $3.attr.Iv;
			$1.attr.First = VarList[$1.attr.First].addr;

			if(check++ > MAXMEMBER) {
				printf("** overdefine variable **\n");
				exit(0);
			}
		}

		/* =========================== */
		struct node *last = get_last_node($1.Node);
		add_brother_node(last, $3.Node);
		$1.Node->type = e_varlist;
		$$.Node = $1.Node;
		}
	|	ArrayVar Type
		{
		int check = 0;
		int NO = $1.attr.NO;

		if ($2.attr.Iv == 1) {
			$2.attr.Iv = 2;//real array
		} else {
			$2.attr.Iv = 3;//int array
		}

		while (NO) {
			VarList[NO].type = $2.attr.Iv;
			NO = VarList[NO].addr;

			if(check++ > MAXMEMBER) {
				printf("** overdefine variable **\n");
				exit(0);
			}
		}
		}
	;
Type:	Integer
		{
		//Type <Iv> <int>
		$$.attr.Iv = 0;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_type_int;
		set_node_val_str($$.Node, "Integer");
		}
	|	Real
		{
		$$.attr.Iv = 1;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_type_real;
		set_node_val_str($$.Node, "Real");
		}
	;
VarList:	VarList','Variable
		{
		// VarList <First> <int>

		$$.attr.First = $3.attr._Var.PLACE;
		VarList[$3.attr._Var.PLACE].addr = $1.attr.First;


		/* =========================== */
		struct node *last = get_last_node($1.Node);
		add_brother_node(last, $3.Node);
		$$.Node = $1.Node;
		}
	|	Variable
		{
		$$.attr.First = $1.attr._Var.PLACE;
		VarList[$1.attr._Var.PLACE].addr = 0;


		/* =========================== */
		$$.Node = $1.Node;
		}
	;
StateList:	S_L Statement
		{
		$$.attr.CH = $2.attr.CH;

		/* =========================== */
		struct node *last = get_last_node($1.Node);
		add_brother_node(last, $2.Node);
		$$.Node = $1.Node;
		}
	|	Statement
		{
		$$.attr.CH = $1.attr.CH;

		/* =========================== */
		$$.Node = $1.Node;
		}
	;
S_L:		StateList ';'
		{
		backPatch($1.attr.CH, NXQ);

		/* =========================== */
		$$.Node = $1.Node;
		}
	;
Statement:	AsignState
		{
		$$.attr.CH = 0;

		/* =========================== */
		$$.Node = $$.Node;
		}
	|	ISE Statement
		{
		$$.attr.CH = merge($1.attr.CH, $2.attr.CH);

		/* =========================== */
		add_son_node($1.Node, $2.Node);
		$$.Node = $1.Node;
		}
	|	IBT Statement
		{
		$$.attr.CH = merge($1.attr.CH, $2.attr.CH);

		/* =========================== */
		add_son_node($1.Node, $2.Node);
		$$.Node = $1.Node;
		}
	|	WBD Statement
		{
		backPatch($2.attr.CH, $1.attr._WBD.QUAD);
		gen("j", 0, 0, $1.attr._WBD.QUAD);
		$$.attr.CH = $1.attr._WBD.CH;

		/* =========================== */
		add_son_node($1.Node, $2.Node);
		$$.Node = $1.Node;
		}
	|	CompState
	    {
		$$.attr.CH = $1.attr.CH;

		/* =========================== */
		$$.Node = $1.Node;
		}
	| 	ForLoop2 Do Statement
		{
			backPatch($3.attr.CH,NXQ);
			gen("+",$1.attr._Loop.place,entry("1"),$1.attr._Loop.place);
			gen("j",0,0,$1.attr._Loop.QUAD);
			$$.attr.CH=$1.attr._Loop.CH;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_for_stat;
		set_node_val_str($$.Node, "for_loop_do");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);

		}
	;
	|	{
	    }
	;
CompState:	Begin StateList End
		{
		$$.attr.CH = $2.attr.CH;

		new_node(&($$.Node));
		$$.Node->type = e_compstat;
		set_node_val_str($$.Node, "begin_end");
		add_son_node($$.Node, $2.Node);
		}
	;
AsignState:	Variable ':''=' Expr
		{
		if (!$1.attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
			gen(":=", $4.attr._Expr.place, 0, $1.attr._Var.PLACE);
		} else {  /*OFFSET不为0，下标变量*/ 
			gen("[]=", $4.attr._Expr.place, 0, $1.attr._Var.PLACE);
		}
		$$.attr.CH =$1.attr._Var.PLACE;

		if (flag_var_def == 0) {
			printf("** undefined variable %s **", VarList[$1.attr._Var.PLACE].name);
			exit(0);
		}
		
		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_assign_stat;
		set_node_val_str($$.Node, ":=");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $4.Node);
		}
	;
ISE:		IBT Statement Else
		{
		int q = NXQ;
		gen("j", 0, 0, 0);
		backPatch($1.attr.CH, NXQ); // right now, NXQ = q + 1
		$$.attr.CH = merge($2.attr.CH, q);

		/* =========================== */
		new_node(&($$.Node));  
		$$.Node->type = e_if_then_else_stat;
		set_node_val_str($$.Node, "if_then_else");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $2.Node);
		}
	;
IBT:		If BoolExpr Then
		{
		backPatch($2.attr._BExpr.TC, NXQ); $$.attr.CH = $2.attr._BExpr.FC;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_if_then_stat;
		set_node_val_str($$.Node, "if_then");
		add_son_node($$.Node, $2.Node);
		}

	;
WBD: Wh BoolExpr Do
		{
		// WBD <_WBD> <QUAD, CH>

		backPatch($2.attr._BExpr.TC, NXQ);
		$$.attr._WBD.CH = $2.attr._BExpr.FC;
		$$.attr._WBD.QUAD = $1.attr.CH;

		/* =========================== */
		add_son_node($1.Node, $2.Node);
		$$.Node = $1.Node;
		}
	;
Wh:		While
        {
		$$.attr.CH = NXQ;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_while_stat;
		set_node_val_str($$.Node, "while");
        }
	;
Expr:		Expr'+'Expr
		{
		$$.attr._Expr.place = newTemp();
		gen("+", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_exp;
		set_node_val_str($$.Node, "+");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);
		}
	|	Expr'-'Expr
		{
		$$.attr._Expr.place = newTemp();
		gen("-", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_exp;
		set_node_val_str($$.Node, "-");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);
		}
	|	Expr'*'Expr
		{
		$$.attr._Expr.place = newTemp();
		gen("*", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_exp;
		set_node_val_str($$.Node, "*");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);
		}
	|	Expr'/'Expr
		{
		$$.attr._Expr.place = newTemp();
		gen("/", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_exp;
		set_node_val_str($$.Node, "/");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);
		}
	|	'('Expr')'
		{
		$$.attr._Expr.place = $2.attr._Expr.place;

		/* =========================== */
		$$.Node = $2.Node;
		}
	|	'-' Expr %prec UMINUS
		{
		$$.attr._Expr.place = newTemp();
		gen("-", $2.attr._Expr.place, 0, $$.attr._Expr.place);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_exp;
		set_node_val_str($$.Node, "-");
		add_son_node($$.Node, $2.Node);
		}
	|	Variable
		{
		if (!$1.attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
			$$.attr._Expr.place = $1.attr._Var.PLACE;
		} else {  /*OFFSET不为0，下标变量*/ 
			int T = newTemp();
			gen("=[]", $1.attr._Var.PLACE, 0, T);	//T=C[V]
			$$.attr._Expr.place = T;
		}

		// undefined error
		if (flag_var_def == 0) {
			printf("** undefined variable %s **", VarList[$1.attr._Var.PLACE].name);
			exit(0);
		}

		/* =========================== */
		$$.Node = $1.Node;
		}

	|	Const
		{
		$$.attr._Expr.type = $1.attr._Expr.type;
		$$.attr._Expr.place = $1.attr._Expr.place;
		if ($$.attr._Expr.type) {
			$$.attr._Expr.Value.Rv = $1.attr._Expr.Value.Rv;
		} else {
			$$.attr._Expr.Value.Iv = $1.attr._Expr.Value.Iv;
		}

		/* =========================== */
		$$.Node = $1.Node;
		}
	;

BoolExpr:	Expr RelationOp Expr
		{
		$$.attr._BExpr.TC = NXQ; $$.attr._BExpr.FC = NXQ + 1;
		gen($2.attr._Rop, $1.attr._Expr.place, $3.attr._Expr.place, 0);
		gen("j", 0, 0, 0); 

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_bool_exp;
		set_node_val_str($$.Node, &($2.attr._Rop[1]));
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);
		}
	|	BoolExpr And
	    {
		backPatch($1.attr._BExpr.TC, NXQ); $$.attr._BExpr.FC = $1.attr._BExpr.FC;
		}
	|	BoolExpr Or
	    {
		backPatch($1.attr._BExpr.FC, NXQ); $$.attr._BExpr.TC = $1.attr._BExpr.TC;
		}	
	|	Not BoolExpr
	    {
		$$.attr._BExpr.TC = $2.attr._BExpr.FC; $$.attr._BExpr.FC = $2.attr._BExpr.TC;

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_bool_exp;
		set_node_val_str($$.Node, "Not");
		add_son_node($$.Node, $2.Node);
		}
	|	'(' BoolExpr ')'
	    {
		$$.attr._BExpr.TC = $2.attr._BExpr.TC; $$.attr._BExpr.FC = $2.attr._BExpr.FC;

		/* =========================== */
		$$.Node = $2.Node;
		}
	;
Variable:	Iden
		{
		//Variable <NO> <int>
		if (lookUp(str1)) {
			flag_var_def = 1;
		} else {
			flag_var_def = 0;
		}
		$$.attr._Var.PLACE = entry(str1); 
		$$.attr._Var.OFFSET = 0;
		

		/* =========================== */
		new_node(&($$.Node));
		set_node_val_str($$.Node, str1);
		}
	|	ExprList ']'
		{
			char Cstr[10], astr[10] = "ArrPtr";
			int C,a;
			int T = newTemp();
			C = Access_C($1.attr._Elist.NO);
			a = Access_a($1.attr._Elist.NO);

			sprintf(Cstr, "%d", C);
			sprintf(astr, "%d", a);
			gen("-", entry(astr), entry(Cstr),T); /*产生a-C的代码，结果存于T*/ 
			$$.attr._Elist.PLACE = T; /*CONSTPART*/
			$$.attr._Var.OFFSET = $1.attr._Elist.PLACE;/*VARPART*/
		}
	;
Const:		IntNo
		{
		//Const <_Expr> <int, int , int/float>

		$$.attr._Expr.type = 0;
		$$.attr._Expr.place = entry(str1);
		VarList[$$.attr._Expr.place].type = 0;
		$$.attr._Expr.Value.Iv = atoi(str1);

		/* =========================== */
		new_node(&($$.Node));
		set_node_val_str($$.Node, str1);
		}
	|	RealNo
		{
		$$.attr._Expr.type = 1;
		$$.attr._Expr.place = entry(str1);
		VarList[$$.attr._Expr.place].type = 1;
		$$.attr._Expr.Value.Rv = (float)atof(str1);
		
		/* =========================== */
		new_node(&($$.Node));
		set_node_val_str($$.Node, str1);
		}
	;
RelationOp:	'<'
		{
		//RelationOp <_Rop> <char [5]>
		
		strcpy($$.attr._Rop, "j<");
		}
	|	'>'
		{
		strcpy($$.attr._Rop, "j>");
		}	
	|	'='
		{
		strcpy($$.attr._Rop, "j=");
		}
	|	GE
		{
		strcpy($$.attr._Rop, "j>=");
		}
	|	NE
		{
		strcpy($$.attr._Rop, "j!=");
		}
	|	LE
		{
		strcpy($$.attr._Rop, "j<=");
		}
	;

ArrayVar: ArrayMSG ']' Of
		{
			$$.attr.NO = $1.attr.NO;
			FillArrMSG_C($$.attr.NO);   
		}
	;
ArrayMSG: VarList ':' Array '[' Const DD Const	
		{
			//一维数组情形
			// ArrayMSG <NO> <int>
			int NO = $$.attr.NO;
			int low = $5.attr._Expr.Value.Iv, high = $7.attr._Expr.Value.Iv;
			$$.attr.NO = $1.attr.First;	//连续定义的情形
			//内情向量表的构造
			VarList[NO].ADDR = malloc(sizeof(struct arr_info));
			VarList[NO].ADDR->DIM = 1;
			VarList[NO].ADDR->Vector = malloc(5*sizeof(int));		
			VarList[NO].ADDR->Vector[2] = low;
			VarList[NO].ADDR->Vector[3] = high;
			VarList[NO].ADDR->Vector[4] = (high - low) + 1;
		}
	|	  ArrayMSG ',' Const DD Const	
		{
			//多维数组情形
			int NO = $1.attr.NO;
			int dim = VarList[NO].ADDR->DIM+1;
			int low = $3.attr._Expr.Value.Iv, high = $5.attr._Expr.Value.Iv;
			$$.attr.NO = NO;

			VarList[NO].ADDR->DIM++;
			VarList[NO].ADDR->Vector = realloc(VarList[NO].ADDR->Vector, (3 * dim + 2) * sizeof(int));
			VarList[NO].ADDR->Vector[3*dim - 1] = low;
			VarList[NO].ADDR->Vector[3*dim] = high;
			VarList[NO].ADDR->Vector[3*dim + 1] = (high - low) + 1;
		}
	;
ForLoop2: ForLoop1 To Expr
		{
			int p = NXQ;
			$$.attr._Loop.QUAD = NXQ;	//传递循环返回点信息
			gen("j<=", $1.attr._Loop.place,$3.attr._Expr.place,p+2); 	//判断循环是否继续
			$$.attr._Loop.place = $1.attr._Loop.place;	//iden在表中的序号
			$$.attr._Loop.CH = NXQ;		//循环语句的出口
			gen("j",0,0,0);

		/* =========================== */
		new_node(&($$.Node));
		$$.Node->type = e_for_stat;
		set_node_val_str($$.Node, "to");
		add_son_node($$.Node, $1.Node);
		add_son_node($$.Node, $3.Node);

		}
	;

ForLoop1:	For AsignState
		{
			$$.attr._Loop.place = $2.attr.CH;

		/* =========================== */
		//new_node(&($$.Node));
		//$$.Node->type = e_for_stat;
		//set_node_val_str($$.Node, "");
		//add_son_node($$.Node, $2.Node);
		$$.Node=$2.Node;
		}
	;

ExprList: Variable '[' Expr
		{
			//ExprList
			$$.attr._Elist.PLACE = $3.attr._Expr.place;	//相当于VARPART=i1
			$$.attr._Elist.DIM = 1;
			$$.attr._Elist.NO = $1.attr._Var.PLACE;
		}
	|	ExprList ',' Expr
		{
			char num[5];
			int k,d;
			int T = newTemp();
			k = $1.attr._Elist.DIM + 1;
			d = Access_d($1.attr._Elist.NO, k);
			sprintf(num, "%d", d);	//将d转化为字符形式，结果存在num
			gen("*", $1.attr._Elist.PLACE, entry(num), T);
			gen("+", $3.attr._Expr.place, T, T); /*相当于VARPART=VARPART*d+ik*/ 
			$$.attr._Elist.NO = $1.attr._Elist.NO;;/*传递Entry(iden)*/ 
			$$.attr._Elist.PLACE = T;/*传递存放VARPART中间结果的T*/ 
			$$.attr._Elist.DIM = k;
		}
	;
	
%%
