#ifndef _CHAIN_H
#define _CHAIN_H


typedef struct LNode {
	int Data;
	struct LNode *Next;
} *PtrToLNode;
typedef PtrToLNode Position;   // ����λ���ǽڵ�ĵ�ַ 
typedef PtrToLNode List;
List L;


#endif
