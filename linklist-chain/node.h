#ifndef _CHAIN_H
#define _CHAIN_H


typedef struct LNode {
	int Data;
	struct LNode *Next;
} *PtrToLNode;
typedef PtrToLNode Position;   // 这里位置是节点的地址 
typedef PtrToLNode List;
List L;


#endif
