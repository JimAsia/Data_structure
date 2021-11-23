#ifndef _SNODE_H
#define _SNODE_H

typedef int Position;
typedef double ElementType;               // 将堆栈的元素类型具体化 
typedef struct SNode {
	ElementType *Data;
	Position Top;
	int MaxSize;
} *PtrToSNode;

typedef PtrToSNode Stack;


#endif
