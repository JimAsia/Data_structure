#ifndef _SNODE_H
#define _SNODE_H


// TOP指向-1时，表示空栈；TOP指向MaxSize-1时，表示栈满 

typedef int Position;
typedef int ElementType;
typedef struct SNode {
	ElementType * Data;       // 储存元素的数组 
	Position Top;             // 栈顶指针，记录当前栈顶元素的下标值 
	int MaxSize;              // 堆栈的最大容量 
} *PtrToSNode;
typedef PtrToSNode Stack;


#endif
