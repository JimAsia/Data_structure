#ifndef _HTNODE_H
#define _HTNODE_H



typedef struct HTNode {       
	int Weight;               // ���Ȩֵ 
	struct HTNode *Left;     // ָ�������� 
	struct HTNode *Right;	// ָ��������
	int  *Data;    // �洢Ԫ�ص����� 
	int Size;              // ���е�ǰԪ�ظ��� 
	int Capacity;          // �ѵ�������� 
} *HuffmanTree;           // ���������� 





#endif
