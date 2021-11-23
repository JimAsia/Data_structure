#ifndef _QNode_H
#define _QNode_H


typedef int ElementType;
typedef int Position;
typedef struct QNode {
	ElementType *Data;          // 储存元素的数组 
	Position Front, Rear;          // 队列的头、尾指针 
	int MaxSize;	              // 队列的最大容量 
}* PtrToQNode;


#endif
