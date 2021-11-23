#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "SNode.h"

#define MAXOP 100        // 操作数序可能的最大长度 
#define INFINITY 1e9     // 代表正无穷 
#define ERROR -1
typedef enum {num, opr, end} Type;           	     // 类型依次对应运算数、运算符、字符串结尾 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*运算数输出，运算符存入*/
/*从头到尾读取中缀表达式的每个对象，对不同对象按不同情况处理
1. 运算数：直接输出
2. 左括号：压入堆栈
3. 右括号：将栈顶的运算符弹出并输出，直到遇到左括号（出栈，不输出）
4. 运算符：若优先级大于栈顶运算符时，则把它压栈
		   若优先级小于等于栈顶运算符时，将栈顶运算符弹出并输出；再比较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，
		   然后将该运算符压栈。
5. 若各对象处理完毕，则把堆栈中存留的运算符一并输出 */ 


Stack CreatStack ( int MaxSize );
bool IsFull ( Stack S );
bool IsEmpty ( Stack S );
bool Push ( Stack S, ElementType X );
ElementType Pop ( Stack S );
Type GetOp ( char * Expr, int * start, char * str );
ElementType PostfixExp ( char * Expr );


int main( int argc, char *argv[]) {
	char Expr[MAXOP];
	ElementType f;
	
	gets(Expr);
	f = PostfixExp(Expr);
	if ( f < INFINITY )
		printf("%.4f\n", f);
	else
		printf("表达式错误\n");
		
		
	return 0;
}


Type GetOp ( char * Expr, int * start, char * str ) {
	// 从*start开始读入下一个对象（操作数或运算符），并保存在字符串str中。 
	int i = 0;
	
	// 表达式跳过前空格 
	while ( ( str[0] = Expr[(*start)++]) == ' ' );
	
	while ( str[i] != ' ' && str[i] != '\0' )
		str[++i] = Expr[(*start)++];
	if ( str[i] == '\0' )           // 如果读到输入的结尾 
		(*start)--;                 // *start 指向结束符 
	str[i] = '\0';                  // 结束一个对象的获取 
	
	if( i == 0 ) return end;   // 读到了结束 
	// 如果str[0]是数字、或是符号跟个数字 
	else if ( isdigit(str[0]) || isdigit(str[1]) )
		return num;                    // 表示此时str中存的是一个数字 
	else                               // 如果str不是空串，又不是数字 
		return opr;                    // 表示此时str中存的是一个运算符 
}


ElementType PostfixExp ( char * Expr ) {
	// 调用GetOp函数读入后缀表达式并求值
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;
	
	// 申请一个新堆栈 
	S = CreatStack(MAXOP);
	
	Op1 = Op2 = 0;
	while ( (T = GetOp( Expr, &start, str)) != end ) {
		// 当未读到输入结束时 
		if ( T == num )
			Push(S, atof(str));
		else {
			if ( !IsEmpty(S) )
				Op2 = Pop(S);
			else
				Op2 = INFINITY;
			if ( !IsEmpty (S) )
				Op1 = Pop(S);
			else
				Op2 = INFINITY;
			switch ( str[0] ) {
				case '+' :
					Push( S, Op1 + Op2 );
					break;
				case '*' :
					Push( S, Op1 * Op2 );
					break;
				case '-':
					Push( S, Op1 - Op2 );
					break;
				case '/':
					if ( Op2 != 0.0 )          // 检查除法的分母是否为0 
						Push( S, Op1 / Op2);
					else {
						printf("错误：除法分母为零\n");
						Op2 = INFINITY;
					}
					break;
				default:
					printf("错误：未知运算符%s\n", str);
					Op2 = INFINITY;
					break;
			}
			if ( Op2 >= INFINITY ) break;
		}
	}
	if ( Op2 < INFINITY )                  // 如果处理完了表达式 
		if ( !IsEmpty(S) )					// 此时堆栈正常 
			Op2 = Pop(S);					// 记录计算结果 
		else Op2 = INFINITY;				// 否则标记错误 
	free(S);								// 释放堆栈 
	return Op2; 
}


Stack CreatStack ( int MaxSize ) {
	Stack S = (Stack)malloc(sizeof(PtrToSNode));
	S->Data = (ElementType *)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull ( Stack S ) {
	return( S->Top == S->MaxSize-1 );
}


bool Push ( Stack S, ElementType X ) {
	if (IsFull(S)) {
		printf("堆栈满\n");
		return false;
	}
	else {
		S->Data[++(S->Top)] == X;
		return true;
	}
}


bool IsEmpty ( Stack S ) {
	return(S->Top == -1);
}


ElementType Pop ( Stack S ) {
	if ( IsEmpty(S) ) {
		printf("堆栈空");
		return ERROR;
	}
	else {
		return(S->Data[(S->Top)--]);
	}
}
