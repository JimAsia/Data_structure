#ifndef _GNODE_H
#define _GNODE_H

typedef int ElementType;

typedef struct GNode {
	int Tag; //  标志域：0表示该结点是单元素；1表示该结点是广义表 
	union {
		//    子表之证域Sublist与单元素数据域Data复用，即共用储存空间 
		ElementType Data;
		struct GNode Sublist;
	} URegion;
	struct GNode Next;      // 指向后继结点 
} *PtrToGNode;

typedef PtrToGNode GList;


#endif
