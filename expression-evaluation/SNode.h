#ifndef _SNODE_H
#define _SNODE_H

typedef int Position;
typedef double ElementType;               // ����ջ��Ԫ�����;��廯 
typedef struct SNode {
	ElementType *Data;
	Position Top;
	int MaxSize;
} *PtrToSNode;

typedef PtrToSNode Stack;


#endif
