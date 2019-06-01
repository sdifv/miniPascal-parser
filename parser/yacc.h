#pragma once
#ifndef __YACC_H__
#define __YACC_H__

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXSTR 20
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1

struct QUATERLIST {
	char op[6];
	int arg1, arg2, result;
};

struct arr_info {	//内情向量表
	int DIM;	//记录已处理的数组下标表达式个数
	int *Vector;//Vector[0]
};
struct VARLIST {	
	char name[20];
	int type;	//IF type is REAL THEN type = 1, ELSE IF type is INTEGER type = 0
	int addr;	//指向连续定义下，该变量下一个变量在符号表中的序号
	struct arr_info *ADDR;	//直接指向内存单元中数组的头地址
	/*union{int Iv;float Rv;} Value;*/
};


// 以Name查符号表，若查到则返回相应登记项的序号 (≥1),否则返回0。 
int lookUp(char *Name);
// 以Name为名字在符号表中登录新的一项,返回值为该项 的序号
int enter(char *Name);
// 以Name为名字查、填符号表: 
int entry(char *Name);
// 产生临时变量的函数，每次调用都定义一个新的临时 变量。返回值为该变量的编号。
int newTemp(void);
// 根据所给实参产生一个四元式： (Op,Arg1,Arg2,Result)，且送入四元式表中，返回值为 该四元式的序号。Arg1或Arg2为零时表示该参数缺省 。
void gen(char *op, int arg1, int arg2, int result);
// 将链首“指针”分别为p1和p2的两条链合 并为一条，并返回新链的链首“指针”（此处的“指针”实际 上是四元式的序号，应为整型值）
int merge(int p1, int p2);
// 用四元式序号t回填以p为首的链，将链 中每个四元式的Result域改写为t的值。 
void backPatch(int p, int t);
// 计算并填写符号表中第NO登记项ADDR所 指示的内情向量中的C(CONSTPART)值。
void FillArrMSG_C(int NO);
// 从符号表第no 项的ADDR域所指示的内情向量 中取出C值。
int Access_C(int no);
//  no含义同上, 取内情向量中的a值
int Access_a(int no);
// no含义 同上,取数组的第k维界差。
int Access_d(int no, int k);

#endif