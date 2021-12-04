#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HNode.h"

#define MAXDATA 1000
#define ERROR -1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
1. 用数组表示完全二叉树是堆的第一个特性
2. 最大堆中，任一结点的值大于或等于其子结点的值
3. 最小堆中，任一结点的值小于或等于其子结点的值
4. 兄弟结点之间不存在约束关系 
*/

// 最大堆(MaxHeap) 
// 数据对象集：有一个N>0个元素的最大堆H是一棵完全二叉树，每个结点上的元素值不小于其子结点元素的值
// Maxsize建立空的最大堆时，数组应该有MaxSize+1个元素，数组起始单位为1，通常第0个单元是无用的 

typedef Heap MaxHeap;          // 最大堆 
typedef Heap MinHeap;          // 最小堆 

 
MaxHeap CreatHeap ( int MaxSize );        // 创建空的最大堆，其最大长度为MaxSize 
bool IsFull ( MaxHeap H );                // 判断最大堆H是否已满，是true，否false 
bool Insert ( MaxHeap H, ElementType X );                // 将元素X插入最大堆H。堆满，返回false，否则将数据元素X插入到堆H并放回true 
bool IsEmpty ( MaxHeap H );               // 判断最大堆H是否为空，返回true，否false 
ElementType DeleteMax ( MaxHeap );        // 删除并返回H中最大元素
void PerDown ( MaxHeap H, int P );
void BuildHeap ( MaxHeap H ); 


int main(int argc, char *argv[]) {
	return 0;
}


MaxHeap CreatHeap ( int MaxSize ) {
	// 创建容量为MaxSize为空的最大堆 
	
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc((MaxSize + 1)*sizeof(ElementType));
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data[0] = MAXDATA;  // 定义“哨兵”为大于堆中所有可能元素的值
	
	return H; 
}


bool IsFull ( MaxHeap H ) {
	return(H->Size==H->Capacity);
}


bool Insert ( MaxHeap H, ElementType X ) {
	// 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 
	int i;
	
	if ( IsFull (H) ) {
		printf("最大堆已满\n");
		return false;
	}
	i = ++H->Size;    // i指向插入后堆中的最后一个元素的位置 
	for ( ; H->Data[i/2] < X; i/=2 ) 
		H->Data[i] = H->Data[i/2];          // 上滤X 
	H->Data[i] = X;        // 将X插入 
	return true;
}


bool IsEmpty ( MaxHeap H ) {
	return(H->Size == 0);
}

// 从根结点开始，用最大堆中的最后一个元素向上过滤向下层结点 
ElementType DeleteMax ( MaxHeap H ) {
	// 从最大堆H中取出键值为最大的元素，并删除一个结点 
	int Parent, Child;
	ElementType MaxItem, X;
	if ( IsEmpty(H) ) {
		printf("\n");
		return ERROR;
	}
	
	MaxItem = H->Data[1];      // 取出根结点存放的最大值 
	// 用最大堆中最后一个元素从根结点开始向上过滤下层结点 
	X = H->Data[H->Size--];    // 注意当前堆的规模要小 
	for ( Parent = 1; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if ((Child!=H->Size) && (H->Data[Child] < H->Data[Child+1]) )
			Child++;           // Child指向左右子结点的较大者 
		if ( X >= H->Data[Child]) break;  // 找到了合适的位置 
		else  // 下滤X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;   // X变成新的父结点 
	
	return MaxItem;   // 返回被删除值 
}


void PerDown ( MaxHeap H, int p ) {
	// 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 
	int Parent, Child;
	ElementType X;
	
	X = H->Data[p];      // 取出结点存放的值 
	for ( Parent = p; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if (( Child != H->Size ) && ( H->Data[Child] < H->Data[Child+1] ))
			Child++;              // Child指向左右结点的较大者 
		if ( X > H->Data[Child] ) break;   // 找到了合适位置 
		else            // 下滤X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}


void BuildHeap ( MaxHeap H ) {
	// 调整H->Data[p]中的元素，使满足最大堆的有序性 
	// 这里假设所有的H->Size个元素已经存在H->Data[]中 
	
	int i;
	
	// 从最后一个结点的父结点开始，到根结点1 
	for ( i = H->Size/2; i > 0; i--)
		PerDown(H, i);
}
