#ifndef _BOOK322_H
#define _BOOK322_H
#define Maxsize 50

typedef int Position; //
typedef struct LNode {
	int Data[Maxsize];
	Position Last; 
} *PtrToLNode; // L->Data[i] 访问下标为i的元素    L->Last+1 表示长度 
typedef PtrToLNode List;

#endif
