#ifndef _GNODE_H
#define _GNODE_H

typedef int ElementType;

typedef struct GNode {
	int Tag; //  ��־��0��ʾ�ý���ǵ�Ԫ�أ�1��ʾ�ý���ǹ���� 
	union {
		//    �ӱ�֤֮��Sublist�뵥Ԫ��������Data���ã������ô���ռ� 
		ElementType Data;
		struct GNode Sublist;
	} URegion;
	struct GNode Next;      // ָ���̽�� 
} *PtrToGNode;

typedef PtrToGNode GList;


#endif
