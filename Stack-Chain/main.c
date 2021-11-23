#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SNode.h"
#define ERROR -1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


Stack CreatStack();
bool IsEmpty ( Stack S );
bool Push ( Stack S, ElementType X );
ElementType Pop( Stack S );


int main(int argc, char *argv[]) {
	return 0;
}


Stack CreatStack() {
	// 构造一个堆栈的头结点，返回该结点指针 
	Stack S;
	
	S = malloc(sizeof(PtrToSNode));
	S->Next = NULL;
	
	return S;
}


bool IsEmpty ( Stack S ) {
	// 判断堆栈是否为空 ，空为false，否则为true 
	return ( S->Next == NULL );
}


bool Push ( Stack S, ElementType X ) {
	// 将元素X压入堆栈S 
	PtrToSNode TmpCell;
	
	TmpCell = (PtrToSNode)malloc(sizeof(PtrToSNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	
	return true;
}


ElementType Pop( Stack S ) {
	// 删除并返回堆栈S的栈顶元素 
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if ( IsEmpty(S) ) {
		printf("堆栈空\n");
		
		return ERROR;
	}
	else {
		FirstCell = S->Next;			// S的下一指针值赋给FirstCell 
		TopElem = FirstCell->Data;      // X的值赋给FirstCell结构体内的Data值 
		S->Next = FirstCell->Next;		// S的指针指向FirstCell的下一指针，也就是S->->Next 
		free(FirstCell);				// 释放FirstCell，删除原来S结构体内的Data以及指针值 
		
		return TopElem;
	}
}
