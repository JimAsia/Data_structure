#ifndef _QNode_H
#define _QNode_H


typedef int ElementType;
typedef int Position;
typedef struct QNode {
	ElementType *Data;          // ����Ԫ�ص����� 
	Position Front, Rear;          // ���е�ͷ��βָ�� 
	int MaxSize;	              // ���е�������� 
}* PtrToQNode;


#endif
