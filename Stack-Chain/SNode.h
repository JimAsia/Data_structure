#ifndef _CHAIN_H
#define _CHAIN_H

typedef int ElementType;
typedef struct SNode {
	ElementType Data;
	struct SNode *Next;
} *PtrToSNode;

typedef PtrToSNode Stack;


#endif
