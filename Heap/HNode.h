#ifndef _HNODE_H
#define _HNODE_H

typedef int ElementType;
typedef struct HNode {
	ElementType  *Data;    // �洢Ԫ�ص����� 
	int Size;              // ���е�ǰԪ�ظ��� 
	int Capacity;          // �ѵ�������� 
} *Heap;   // �ѵ����Ͷ��� 


#endif 
