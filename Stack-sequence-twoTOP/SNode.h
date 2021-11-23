#ifndef _TOP2_H
#define _TOP2_H


typedef int ElementType;
typedef int Position;

typedef struct SNode {
	ElementType *Data;     // ����Ԫ�ص����� 
	Position Top1;          // ��ջ1��ջ��ָ�� 
	Position Top2;         //  ��ջ2��ջ��ָ�� 
	int Maxsize;           //  ��ջ��������� 
} *PtrTosNode;
typedef PtrToSNode Stack;


#endif
