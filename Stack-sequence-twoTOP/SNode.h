#ifndef _TOP2_H
#define _TOP2_H


typedef int ElementType;
typedef int Position;

typedef struct SNode {
	ElementType *Data;     // 储存元素的数组 
	Position Top1;          // 堆栈1的栈顶指针 
	Position Top2;         //  堆栈2的栈顶指针 
	int Maxsize;           //  堆栈的最大容量 
} *PtrTosNode;
typedef PtrToSNode Stack;


#endif
