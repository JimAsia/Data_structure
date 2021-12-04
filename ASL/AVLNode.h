#ifndef _AVL_H
#define _AVL_H


typedef int ElementType;
typedef struct AVLNode {        
	ElementType Data;           // 结点数据 
	struct AVLNode *Left;     // 指向左子树 
	struct AVLNode *Right;       // 指向右子树 
	int Height;               // 树高 
} *Position;


#endif
