#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QNode.h"
#define ERROR -1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef PtrToQNode Queue;

Queue CreateQueue ( int MaxSize );       // ���ɿն��У�����󳤶�ΪMaxSize 
bool IsFill ( Queue Q );                 // �ж϶���Q�Ƿ����������Ƿ���true��������false�� 
bool AddQ ( Queue Q, ElementType X);     // ��Ԫ��Xѹ�뵽����Q������������false����������Ԫ��X���뵽����Q������true 
bool IsEmpty ( Queue Q );                // �ж϶���Q�Ƿ�Ϊ�գ����Ƿ���true��������Ϊfalse 
ElementType DeleteQ ( Queue Q );      // ɾ�������ض���ͷԪ�ء�������Ϊ�գ����ش�����Ϣ�����򽫶���ͷ����Ԫ�شӶ�����ɾ�������� 

int main(int argc, char *argv[]) {
	
	return 0;
}


Queue CreateQueue ( int MaxSize ) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}


bool IsFull ( Queue Q ) {
	return((Q->Rear+1) % Q->MaxSize == Q->Front );     // ���� 
}


bool AddQ ( Queue Q, ElementType X ) {            // ���� 
	if ( IsFull(Q) ) {
		printf("������\n");
		return false;
	}
	else {
		Q->Rear = (Q->Rear+1) % Q->MaxSize;    // ����ֵ����β����βָ��+1 
		Q->Data[Q->Rear] = X;
		return true;
	}
}


bool IsEmpty ( Queue Q ) {
	return(Q->Front == Q->Rear);
}


ElementType DeleteQ ( Queue Q ) {
	if ( IsEmpty(Q) ) {
		printf("���п�\n");
		return ERROR;
	}
	else {
		Q->Front = (Q->Front+1) % Q->MaxSize;     // ȡֵ����ͷָ���1 
		
		return Q->Data[Q->Front];
	}
}
