#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HTNode.h"


#define MINDATA -1000
#define ERROR NULL
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*
1. 一棵树的路径长度是指树根到其余各结点的路径长度之和 
2. 结点的带权路径长度是指从根结点到该结点之间的路径长度与该结点上所带权值的乘积
3. 带权路径长度最小的，这棵二叉树就称为最优二叉树或哈曼夫树 
调整最小堆：O(N)
2(N-1)+1个删除：O(NlogN)
N-1个插入：O(NlogN)
整体复杂度： O(NlogN)
*/

// 哈曼夫编码不是唯一的 

typedef HuffmanTree MaxHeap;          // 最大堆 
typedef HuffmanTree MinHeap;          // 最小堆 

 
MaxHeap CreatHeap ( int MinSize );        // 创建空的最大堆，其最大长度为MaxSize 
bool IsFull ( MinHeap H );                // 判断最大堆H是否已满，是true，否false 
bool Insert ( MinHeap H, HuffmanTree X );                // 将元素X插入最大堆H。堆满，返回false，否则将数据元素X插入到堆H并放回true 
bool IsEmpty ( MinHeap H );               // 判断最大堆H是否为空，返回true，否false 
HuffmanTree DeleteMin ( MinHeap );        // 删除并返回H中最大元素
HuffmanTree Huffman ( MinHeap H ); 
void PerDown ( MaxHeap H, int P );
void BuildHeap ( MaxHeap H ); 


int main(int argc, char *argv[]) {
	return 0;
}


HuffmanTree Huffman ( MinHeap H ) {
	// 这里最小堆的元素类型为HuffmanTree 
	// 假设H->Size个权值已经存在H->Data[]->Weight里 
	int i, N;
	HuffmanTree T;
	
	BuildHeap(H);  // 将H->Data[]按权值Weight调整为最小堆 
	N = H->Size;
	for ( i = 1; i < N; i++ ) {        // 做H->Size-1次合并 
		T = (HuffmanTree)malloc(sizeof(struct HTNode));   // 建立一个新的根结点 
		T->Left = DeleteMin(H);         // 从最小堆中删除一个结点，作为新T的左子结点 
		T->Right = DeleteMin(H);           // 从最小堆中删除一个结点，作为新T的右子结点 
		T->Weight = T->Left->Weight + T->Right->Weight;             // 计算新权值 
		Insert(H, T);        // 新T插入最小堆 
		
	}
	return DeleteMin(H);       // 最小堆中最后一个元素即是指向哈夫曼树根结点的指针 
}


MinHeap CreatHeap ( int MaxSize ) {
	// 创建容量为MaxSize为空的最大堆 
	
	MinHeap H = (MinHeap)malloc(sizeof(struct HTNode));
	H->Data = (int*)malloc((MaxSize + 1)*sizeof(int));
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data[0] = MINDATA;  // 定义“哨兵”为大于堆中所有可能元素的值
	H->Left = H->Left = NULL;
	
	return H; 
}


bool IsFull ( MinHeap H ) {
	return(H->Size==H->Capacity);
}


bool Insert ( MinHeap H, HuffmanTree X ) {
	// 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 
	int i;
	
	if ( IsFull (H) ) {
		printf("最小堆已满\n");
		return false;
	}
	i = ++H->Size;    // i指向插入后堆中的最后一个元素的位置 
	for ( ; H->Data[i/2] > X->Weight; i/=2 ) 
		H->Data[i] = H->Data[i/2];          // 上滤X 
	H->Data[i] = X->Weight;        // 将X插入 
	return true;
}


bool IsEmpty ( MinHeap H ) {
	return(H->Size == 0);
}

// 从根结点开始，用最大堆中的最后一个元素向上过滤向下层结点 
HuffmanTree DeleteMin ( MinHeap H ) {
	// 从最大堆H中取出键值为最大的元素，并删除一个结点 
	int Parent, Child;
	int MinItem, X;
	if ( IsEmpty(H) ) {
		printf("\n");
		return ERROR;
	}
	
	MinItem = H->Data[1];      // 取出根结点存放的最大值 
	// 用最大堆中最后一个元素从根结点开始向上过滤下层结点 
	X = H->Data[H->Size--];    // 注意当前堆的规模要小 
	for ( Parent = 1; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if ((Child!=H->Size) && (H->Data[Child] > H->Data[Child+1]) )
			Child++;           // Child指向左右子结点的较大者 
		if ( X <= H->Data[Child]) break;  // 找到了合适的位置 
		else  // 下滤X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;   // X变成新的父结点 
	
	return MinItem;   // 返回被删除值 
}


void PerDown ( MinHeap H, int p ) {
	// 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 
	int Parent, Child;
	int X;
	
	X = H->Data[p];      // 取出结点存放的值 
	for ( Parent = p; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if (( Child != H->Size ) && ( H->Data[Child] > H->Data[Child+1] ))
			Child++;              // Child指向左右结点的较大者 
		if ( X <= H->Data[Child] ) break;   // 找到了合适位置 
		else            // 下滤X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}


void BuildHeap ( MinHeap H ) {
	// 调整H->Data[p]中的元素，使满足最大堆的有序性 
	// 这里假设所有的H->Size个元素已经存在H->Data[]中 
	
	int i;
	
	// 从最后一个结点的父结点开始，到根结点1 
	for ( i = H->Size/2; i > 0; i--)
		PerDown(H, i);
}
