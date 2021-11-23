#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QNode.h"
#define ERROR -1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef PtrToQNode Queue;

Queue CreateQueue ( int MaxSize );       // 生成空队列，其最大长度为MaxSize 
bool IsFill ( Queue Q );                 // 判断队列Q是否已满。若是返回true；否则是false； 
bool AddQ ( Queue Q, ElementType X);     // 将元素X压入到队列Q。队列满返回false，否则将数据元素X插入到队列Q并返回true 
bool IsEmpty ( Queue Q );                // 判断队列Q是否为空，若是返回true，不是则为false 
ElementType DeleteQ ( Queue Q );      // 删除并返回队列头元素。若队列为空，返回错误信息；否则将队列头数据元素从队列中删除并返回 

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
	return((Q->Rear+1) % Q->MaxSize == Q->Front );     // 队满 
}


bool AddQ ( Queue Q, ElementType X ) {            // 进队 
	if ( IsFull(Q) ) {
		printf("队列满\n");
		return false;
	}
	else {
		Q->Rear = (Q->Rear+1) % Q->MaxSize;    // 先送值到队尾，队尾指针+1 
		Q->Data[Q->Rear] = X;
		return true;
	}
}


bool IsEmpty ( Queue Q ) {
	return(Q->Front == Q->Rear);
}


ElementType DeleteQ ( Queue Q ) {
	if ( IsEmpty(Q) ) {
		printf("队列空\n");
		return ERROR;
	}
	else {
		Q->Front = (Q->Front+1) % Q->MaxSize;     // 取值。队头指针加1 
		
		return Q->Data[Q->Front];
	}
}
