#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SNode.h"
#define ERROR -1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*栈的顺序储存*/

Stack CreateStack ( int MaxSize );     // 生成空堆栈，其最大长度为MaxSize 
bool IsFull ( Stack S );         // 判断堆栈S是否已满。若S中元素个数等于MaxSize时返回true；否则反回false； 
bool Push ( Stack S, ElementType X );    // 将元素X压入堆栈。若堆栈已满，false；否则将数据元素X插入到堆栈S栈顶处并返回true。 
bool IsEmpty ( Stack S );     // 判断堆栈S是否为空，若是返回true；否则返回false 
ElementType Pop ( Stack S );    // 删除并返回栈顶元素。若栈为空，返回错误信息；否则将栈顶数据元素从堆栈中删除并返回 



int main(int argc, char *argv[]) {
	return 0;
}


Stack CreateStack ( int MaxSize ) {
	Stack S = (Stack)malloc(sizeof(PtrToSNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	
	return S;
}


bool IsFull ( Stack S ) {
	return (S->Top == S->MaxSize-1);     // 栈满条件 
}


bool Push ( Stack S, ElementType X ) {
	if ( IsFull( S ) ) {
		printf("堆栈满\n");
		return false;
	}
	else {
		S->Data[ ++(S->Top) ] = X;
		return true;
	}
}


bool IsEmpty ( Stack S ) {
	return ( S->Top == -1 );               // 栈空 
}


ElementType pop ( Stack S ) {
	if ( IsEmpty(S) ) {
		printf("堆栈空\n");
		return ERROR;                     // ERROR是ElementType的特殊值，标志错误 
	}
	else
		return ( S->Data[(S->Top)--]);   // (S->Top) 减1    删除并出栈 
}
