#ifndef _HTNODE_H
#define _HTNODE_H



typedef struct HTNode {       
	int Weight;               // 结点权值 
	struct HTNode *Left;     // 指向左子树 
	struct HTNode *Right;	// 指向右子树
	int  *Data;    // 存储元素的数组 
	int Size;              // 堆中当前元素个数 
	int Capacity;          // 堆的最大容量 
} *HuffmanTree;           // 哈夫曼类型 





#endif
