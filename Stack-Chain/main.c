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
	// ����һ����ջ��ͷ��㣬���ظý��ָ�� 
	Stack S;
	
	S = malloc(sizeof(PtrToSNode));
	S->Next = NULL;
	
	return S;
}


bool IsEmpty ( Stack S ) {
	// �ж϶�ջ�Ƿ�Ϊ�� ����Ϊfalse������Ϊtrue 
	return ( S->Next == NULL );
}


bool Push ( Stack S, ElementType X ) {
	// ��Ԫ��Xѹ���ջS 
	PtrToSNode TmpCell;
	
	TmpCell = (PtrToSNode)malloc(sizeof(PtrToSNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	
	return true;
}


ElementType Pop( Stack S ) {
	// ɾ�������ض�ջS��ջ��Ԫ�� 
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if ( IsEmpty(S) ) {
		printf("��ջ��\n");
		
		return ERROR;
	}
	else {
		FirstCell = S->Next;			// S����һָ��ֵ����FirstCell 
		TopElem = FirstCell->Data;      // X��ֵ����FirstCell�ṹ���ڵ�Dataֵ 
		S->Next = FirstCell->Next;		// S��ָ��ָ��FirstCell����һָ�룬Ҳ����S->->Next 
		free(FirstCell);				// �ͷ�FirstCell��ɾ��ԭ��S�ṹ���ڵ�Data�Լ�ָ��ֵ 
		
		return TopElem;
	}
}
