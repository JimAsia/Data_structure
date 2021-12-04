#ifndef _TNODE_H
#define _TNODE_H

typedef int ElementType;
typedef struct TNode {
	ElementType Data;
	struct TNode *Right;
	struct TNode *Left;
} *Position;
typedef Position BinTree;


#endif
