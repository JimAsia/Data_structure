#ifndef _AVL_H
#define _AVL_H


typedef int ElementType;
typedef struct AVLNode {        
	ElementType Data;           // ������� 
	struct AVLNode *Left;     // ָ�������� 
	struct AVLNode *Right;       // ָ�������� 
	int Height;               // ���� 
} *Position;


#endif
