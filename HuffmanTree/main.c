#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HTNode.h"


#define MINDATA -1000
#define ERROR NULL
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*
1. һ������·��������ָ���������������·������֮�� 
2. ���Ĵ�Ȩ·��������ָ�Ӹ���㵽�ý��֮���·��������ý��������Ȩֵ�ĳ˻�
3. ��Ȩ·��������С�ģ���ö������ͳ�Ϊ���Ŷ�������������� 
������С�ѣ�O(N)
2(N-1)+1��ɾ����O(NlogN)
N-1�����룺O(NlogN)
���帴�Ӷȣ� O(NlogN)
*/

// ��������벻��Ψһ�� 

typedef HuffmanTree MaxHeap;          // ���� 
typedef HuffmanTree MinHeap;          // ��С�� 

 
MaxHeap CreatHeap ( int MinSize );        // �����յ����ѣ�����󳤶�ΪMaxSize 
bool IsFull ( MinHeap H );                // �ж�����H�Ƿ���������true����false 
bool Insert ( MinHeap H, HuffmanTree X );                // ��Ԫ��X��������H������������false����������Ԫ��X���뵽��H���Ż�true 
bool IsEmpty ( MinHeap H );               // �ж�����H�Ƿ�Ϊ�գ�����true����false 
HuffmanTree DeleteMin ( MinHeap );        // ɾ��������H�����Ԫ��
HuffmanTree Huffman ( MinHeap H ); 
void PerDown ( MaxHeap H, int P );
void BuildHeap ( MaxHeap H ); 


int main(int argc, char *argv[]) {
	return 0;
}


HuffmanTree Huffman ( MinHeap H ) {
	// ������С�ѵ�Ԫ������ΪHuffmanTree 
	// ����H->Size��Ȩֵ�Ѿ�����H->Data[]->Weight�� 
	int i, N;
	HuffmanTree T;
	
	BuildHeap(H);  // ��H->Data[]��ȨֵWeight����Ϊ��С�� 
	N = H->Size;
	for ( i = 1; i < N; i++ ) {        // ��H->Size-1�κϲ� 
		T = (HuffmanTree)malloc(sizeof(struct HTNode));   // ����һ���µĸ���� 
		T->Left = DeleteMin(H);         // ����С����ɾ��һ����㣬��Ϊ��T�����ӽ�� 
		T->Right = DeleteMin(H);           // ����С����ɾ��һ����㣬��Ϊ��T�����ӽ�� 
		T->Weight = T->Left->Weight + T->Right->Weight;             // ������Ȩֵ 
		Insert(H, T);        // ��T������С�� 
		
	}
	return DeleteMin(H);       // ��С�������һ��Ԫ�ؼ���ָ���������������ָ�� 
}


MinHeap CreatHeap ( int MaxSize ) {
	// ��������ΪMaxSizeΪ�յ����� 
	
	MinHeap H = (MinHeap)malloc(sizeof(struct HTNode));
	H->Data = (int*)malloc((MaxSize + 1)*sizeof(int));
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data[0] = MINDATA;  // ���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ
	H->Left = H->Left = NULL;
	
	return H; 
}


bool IsFull ( MinHeap H ) {
	return(H->Size==H->Capacity);
}


bool Insert ( MinHeap H, HuffmanTree X ) {
	// ��Ԫ��X��������H������H->Data[0]�Ѿ�����Ϊ�ڱ� 
	int i;
	
	if ( IsFull (H) ) {
		printf("��С������\n");
		return false;
	}
	i = ++H->Size;    // iָ��������е����һ��Ԫ�ص�λ�� 
	for ( ; H->Data[i/2] > X->Weight; i/=2 ) 
		H->Data[i] = H->Data[i/2];          // ����X 
	H->Data[i] = X->Weight;        // ��X���� 
	return true;
}


bool IsEmpty ( MinHeap H ) {
	return(H->Size == 0);
}

// �Ӹ���㿪ʼ���������е����һ��Ԫ�����Ϲ������²��� 
HuffmanTree DeleteMin ( MinHeap H ) {
	// ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� 
	int Parent, Child;
	int MinItem, X;
	if ( IsEmpty(H) ) {
		printf("\n");
		return ERROR;
	}
	
	MinItem = H->Data[1];      // ȡ��������ŵ����ֵ 
	// �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� 
	X = H->Data[H->Size--];    // ע�⵱ǰ�ѵĹ�ģҪС 
	for ( Parent = 1; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if ((Child!=H->Size) && (H->Data[Child] > H->Data[Child+1]) )
			Child++;           // Childָ�������ӽ��Ľϴ��� 
		if ( X <= H->Data[Child]) break;  // �ҵ��˺��ʵ�λ�� 
		else  // ����X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;   // X����µĸ���� 
	
	return MinItem;   // ���ر�ɾ��ֵ 
}


void PerDown ( MinHeap H, int p ) {
	// ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� 
	int Parent, Child;
	int X;
	
	X = H->Data[p];      // ȡ������ŵ�ֵ 
	for ( Parent = p; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if (( Child != H->Size ) && ( H->Data[Child] > H->Data[Child+1] ))
			Child++;              // Childָ�����ҽ��Ľϴ��� 
		if ( X <= H->Data[Child] ) break;   // �ҵ��˺���λ�� 
		else            // ����X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}


void BuildHeap ( MinHeap H ) {
	// ����H->Data[p]�е�Ԫ�أ�ʹ�������ѵ������� 
	// ����������е�H->Size��Ԫ���Ѿ�����H->Data[]�� 
	
	int i;
	
	// �����һ�����ĸ���㿪ʼ���������1 
	for ( i = H->Size/2; i > 0; i--)
		PerDown(H, i);
}
