#ifndef _QNODE_H
#define _QNODE_H


typedef int ElementType;
typedef struct Node {    // 队列中的结点 
	ElementType Data;
	struct Node *Next;
} *PtrToNode;
typedef PtrToNode Position;

typedef struct QNode {
	Position Front, Rear;   // 队列的头、尾结点 
	int MaxSize;            // 队列的最大容量 
} *PtrToQNode;
typedef PtrToQNode Queue;


#endif
