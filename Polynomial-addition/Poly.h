#ifndef _POLY_H
#define _POLY_H


typedef struct PolyNode {
	int coef;             // ϵ�� 
	int expon;				// ָ�� 
	struct PolyNode *link;
} *PtrToPloyNode;


#endif
