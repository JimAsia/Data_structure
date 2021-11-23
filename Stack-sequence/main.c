#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SNode.h"
#define ERROR -1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*ջ��˳�򴢴�*/

Stack CreateStack ( int MaxSize );     // ���ɿն�ջ������󳤶�ΪMaxSize 
bool IsFull ( Stack S );         // �ж϶�ջS�Ƿ���������S��Ԫ�ظ�������MaxSizeʱ����true�����򷴻�false�� 
bool Push ( Stack S, ElementType X );    // ��Ԫ��Xѹ���ջ������ջ������false����������Ԫ��X���뵽��ջSջ����������true�� 
bool IsEmpty ( Stack S );     // �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false 
ElementType Pop ( Stack S );    // ɾ��������ջ��Ԫ�ء���ջΪ�գ����ش�����Ϣ������ջ������Ԫ�شӶ�ջ��ɾ�������� 



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
	return (S->Top == S->MaxSize-1);     // ջ������ 
}


bool Push ( Stack S, ElementType X ) {
	if ( IsFull( S ) ) {
		printf("��ջ��\n");
		return false;
	}
	else {
		S->Data[ ++(S->Top) ] = X;
		return true;
	}
}


bool IsEmpty ( Stack S ) {
	return ( S->Top == -1 );               // ջ�� 
}


ElementType pop ( Stack S ) {
	if ( IsEmpty(S) ) {
		printf("��ջ��\n");
		return ERROR;                     // ERROR��ElementType������ֵ����־���� 
	}
	else
		return ( S->Data[(S->Top)--]);   // (S->Top) ��1    ɾ������ջ 
}
