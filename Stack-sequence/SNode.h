#ifndef _SNODE_H
#define _SNODE_H


// TOPָ��-1ʱ����ʾ��ջ��TOPָ��MaxSize-1ʱ����ʾջ�� 

typedef int Position;
typedef int ElementType;
typedef struct SNode {
	ElementType * Data;       // ����Ԫ�ص����� 
	Position Top;             // ջ��ָ�룬��¼��ǰջ��Ԫ�ص��±�ֵ 
	int MaxSize;              // ��ջ��������� 
} *PtrToSNode;
typedef PtrToSNode Stack;


#endif
