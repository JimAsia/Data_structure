#ifndef _BOOK322_H
#define _BOOK322_H
#define Maxsize 50

typedef int Position; //
typedef struct LNode {
	int Data[Maxsize];
	Position Last; 
} *PtrToLNode; // L->Data[i] �����±�Ϊi��Ԫ��    L->Last+1 ��ʾ���� 
typedef PtrToLNode List;

#endif
