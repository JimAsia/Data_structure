#ifndef _QNODE_H
#define _QNODE_H


typedef int ElementType;
typedef struct Node {    // �����еĽ�� 
	ElementType Data;
	struct Node *Next;
} *PtrToNode;
typedef PtrToNode Position;

typedef struct QNode {
	Position Front, Rear;   // ���е�ͷ��β��� 
	int MaxSize;            // ���е�������� 
} *PtrToQNode;
typedef PtrToQNode Queue;


#endif
