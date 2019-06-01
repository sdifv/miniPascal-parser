#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "ast.h"
#include "yacc.h"

extern int yylex();
extern FILE* yyin;
extern char str1[20];
extern int lineno;
extern int ef;
extern int yylineno;
/*int CheckKeyWord(char *str);*/
int yyparse();
int yyerror(char*);

void OutputQ(void);
void OutputIList(void);
void OutputAST(void);

FILE* fp;

int VarCount = 1;
int tempVarCount = 1;
int NXQ = 1;
struct QUATERLIST QuaterList[MAXMEMBER];
struct VARLIST VarList[MAXMEMBER];

extern struct node root;

/*int yylex(void)
{
}
*/

int main(int argc, char *argv[])
{
	yyin = stdin;
	init_node(&root);

	if (argc>1) {
		if ((yyin = fopen(argv[1], "r")) == NULL) {
			printf("Can't open file %s\n", argv[1]);
			return -1;
		}
	}

	yyparse();

	if(ef){
		OutputQ();
		OutputIList();
		OutputAST();
	}
	
	return 0;
}

int yyerror(char *errstr)
{
	/*lineno:提供当前的行数信息*/
	ef = 0;
	printf("\nError: %s | encountered at line number:%d\n", errstr, yylineno);
	return 0;
}

void OutputIList(void)
{
	int i = 1;

	printf("\n**** Symbol Table ****\n");
	printf(" No.\t name \t\t   type\n");

	if (i >= VarCount) {
		printf("Symbol Table is NULL!\n");
	}

	for (i = 1;i<VarCount;i++) {
		printf("%4d\t%6s\t\t", i, VarList[i].name);
		if (VarList[i].type == 1) {
			printf(" REAL  \n");
		} else if (VarList[i].type == 0) {
			printf(" INTEGER\n");
		} else if (VarList[i].type == 2) {
			printf(" REAL ARRAY\n");
		} else if (VarList[i].type == 3) {
			printf(" INTEGER ARRAY\n");
		}
	}

	return;
}

void OutputQ(void)
{
	int i = 1;

	if (i >= NXQ) {
		printf("no quater exists!\n");
	}
	printf("\n**** Quaters Table ****\n");
	for (i = 1;i<NXQ;i++) {

		printf("(%3d) ( %5s, ", i, QuaterList[i].op);
		if (QuaterList[i].arg1)
			printf("%6s, ", VarList[QuaterList[i].arg1].name);
		else
			printf("      , ");

		if (QuaterList[i].arg2)
			printf("%6s, ", VarList[QuaterList[i].arg2].name);
		else printf("      , ");

		if ((QuaterList[i].op[0] == 'j') || (QuaterList[i].op[0] == 'S'))
			printf("%6d )\n", QuaterList[i].result);
		else if (QuaterList[i].result)
			printf("%6s )\n", VarList[QuaterList[i].result].name);
		else printf("-\t )\n");
	}
	printf("(%3d) (return,      0,       0,     0 )\n",i);

	return;
}

void PreOrder(struct node *root, int tab)
{
	int i = 0;
	struct node *son = root->son;
	if (root != NULL) {
		for (i = 0; i < tab - 1; ++i) {
			printf("|\t");
		}
		if (i == tab - 1) {
			printf("|-----");
		}
		printf("<%s>\n", root->val.str);
		++tab;
		while (son != NULL) {
			PreOrder(son, tab);
			son = son->next;
		}
	}
}

#define MAX 50
void levelOrder(struct node *root)
{
	struct node *tmp, *son;
	int node_num_cur_level = 0, node_num_next_level = 0;
	//queue
	struct node *Q[MAX];
	int f, r;
	f = r = 0;

	//enqueue
	Q[r] = root;
	r = (r + 1) % MAX;
	++node_num_cur_level;

	//loop when queue is not empty
	while (!(f == r)) {
		//dequeue
		tmp = Q[f];
		f = (f + 1) % MAX;
		
		//process tmp
		printf("| %s |", tmp->val.str);
		//
		son = tmp->son;
		while (son != NULL) {
			//enqueue
			Q[r] = son;
			r = (r + 1) % MAX;
			son = son->next;

			if (node_num_cur_level > 0) {
				++node_num_next_level;
			}
		}
		--node_num_cur_level;
		if (node_num_cur_level == 0) {
			printf("\n");
			node_num_cur_level = node_num_next_level;
			node_num_next_level = 0;
		}
	}
}
void OutputAST(void)
{
	printf("\n**** Abstract Sytax Tree ****\n");
	//levelOrder(&root);
	//printf("\n");
	PreOrder(&root, 0);
}

int lookUp(char *Name)
{
	int i;
	for (i = 1; i < VarCount; ++i) {
		if (!strcmp(Name, VarList[i].name)) {
			return i;
		}
	}
	return 0;
}

/*****************************
 * 在符号表里创建一个新的符号
 *****************************/
int enter(char *Name)
{
	//printf("* %s *", Name);
	strcpy(VarList[VarCount].name, Name);
	VarList[VarCount].type = 0; // default type is INTEGER
	return VarCount++;
}

/*****************************
 * 以Name为名字查、填符号表
 *****************************/
int entry(char *Name)
{
	int i = lookUp(Name);
	if (i > 0) {
		return i;
	} else {
		return enter(Name);
	}
}

int newTemp(void)
{
	char temp[5];
	sprintf(temp, "T%d", tempVarCount);
	strcpy(VarList[MAXMEMBER - tempVarCount].name, temp);
	VarList[MAXMEMBER - tempVarCount].type = 0;
	return MAXMEMBER-(tempVarCount++);
}

/*****************************
 * 生成四元式，同时NXQ++
 *****************************/
void gen(char *op, int arg1, int arg2, int result)
{
	strcpy(QuaterList[NXQ].op, op);
	QuaterList[NXQ].arg1 = arg1;
	QuaterList[NXQ].arg2 = arg2;
	QuaterList[NXQ].result = result;
	NXQ++;
}

/*****************************
 * 合并两条链，返回链首指针，等待回填
 *****************************/
int merge(int p1, int p2)
{
	int p;
	if (!p2) { // p2 = 0????????????
		return p1;
	} else {
		//find the last quadruple of chain p2
		p = p2;
		while (QuaterList[p].result) {
			p = QuaterList[p].result;
		}
		// append p1 to p2
		QuaterList[p].result = p1;
		return p2;
	}
}

/*****************************
 * 回填函数
 *****************************/
void backPatch(int p, int t)
{
	int q = p, q1;
	while (q) {
		q1 = QuaterList[q].result;
		QuaterList[q].result = t;
		q = q1;
	}
	return;
}

/*****************************
 * 用四元式序号t回填以p为首的链，将链 中每个四元式的Result域改写为t的值。
 *****************************/
void FillArrMSG_C(int NO)
{
	int n = VarList[NO].ADDR->DIM;
	int C = 0, j, k, mul;
	for (j = 1; j < n; ++j) {
		mul = 1;
		for (k = j + 1; k < n + 1; ++k) {
			mul *= VarList[NO].ADDR->Vector[3*k + 1];
		}
		C += VarList[NO].ADDR->Vector[3 * j - 1] * mul;
	}
	VarList[NO].ADDR->Vector[0] = C;
}

/*****************************
* 从符号表第no 项的ADDR域所指示的内情向量中取出C值。
*****************************/
int Access_C(int no)
{
	return VarList[no].ADDR->Vector[0];
}

/*****************************
 * no含义同上, 取内情向量中的a值
 *****************************/
int Access_a(int no)
{
	return VarList[no].addr;
}

/*****************************
 * no含义 同上,取数组的第k维界差。
 *****************************/
int Access_d(int no, int k)
{
	return VarList[no].ADDR->Vector[3 * k + 1];
}