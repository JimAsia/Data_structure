#ifndef _HNODE_H
#define _HNODE_H

typedef int ElementType;
typedef struct HNode {
	ElementType  *Data;    // 存储元素的数组 
	int Size;              // 堆中当前元素个数 
	int Capacity;          // 堆的最大容量 
} *Heap;   // 堆的类型定义 


#endif 
