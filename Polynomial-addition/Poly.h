#ifndef _POLY_H
#define _POLY_H


typedef struct PolyNode {
	int coef;             // 系数 
	int expon;				// 指数 
	struct PolyNode *link;
} *PtrToPloyNode;


#endif
