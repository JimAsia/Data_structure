#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HNode.h"

#define MAXDATA 1000
#define ERROR -1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
1. �������ʾ��ȫ�������Ƕѵĵ�һ������
2. �����У���һ����ֵ���ڻ�������ӽ���ֵ
3. ��С���У���һ����ֵС�ڻ�������ӽ���ֵ
4. �ֵܽ��֮�䲻����Լ����ϵ 
*/

// ����(MaxHeap) 
// ���ݶ��󼯣���һ��N>0��Ԫ�ص�����H��һ����ȫ��������ÿ������ϵ�Ԫ��ֵ��С�����ӽ��Ԫ�ص�ֵ
// Maxsize�����յ�����ʱ������Ӧ����MaxSize+1��Ԫ�أ�������ʼ��λΪ1��ͨ����0����Ԫ�����õ� 

typedef Heap MaxHeap;          // ���� 
typedef Heap MinHeap;          // ��С�� 

 
MaxHeap CreatHeap ( int MaxSize );        // �����յ����ѣ�����󳤶�ΪMaxSize 
bool IsFull ( MaxHeap H );                // �ж�����H�Ƿ���������true����false 
bool Insert ( MaxHeap H, ElementType X );                // ��Ԫ��X��������H������������false����������Ԫ��X���뵽��H���Ż�true 
bool IsEmpty ( MaxHeap H );               // �ж�����H�Ƿ�Ϊ�գ�����true����false 
ElementType DeleteMax ( MaxHeap );        // ɾ��������H�����Ԫ��
void PerDown ( MaxHeap H, int P );
void BuildHeap ( MaxHeap H ); 


int main(int argc, char *argv[]) {
	return 0;
}


MaxHeap CreatHeap ( int MaxSize ) {
	// ��������ΪMaxSizeΪ�յ����� 
	
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc((MaxSize + 1)*sizeof(ElementType));
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data[0] = MAXDATA;  // ���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ
	
	return H; 
}


bool IsFull ( MaxHeap H ) {
	return(H->Size==H->Capacity);
}


bool Insert ( MaxHeap H, ElementType X ) {
	// ��Ԫ��X��������H������H->Data[0]�Ѿ�����Ϊ�ڱ� 
	int i;
	
	if ( IsFull (H) ) {
		printf("��������\n");
		return false;
	}
	i = ++H->Size;    // iָ��������е����һ��Ԫ�ص�λ�� 
	for ( ; H->Data[i/2] < X; i/=2 ) 
		H->Data[i] = H->Data[i/2];          // ����X 
	H->Data[i] = X;        // ��X���� 
	return true;
}


bool IsEmpty ( MaxHeap H ) {
	return(H->Size == 0);
}

// �Ӹ���㿪ʼ���������е����һ��Ԫ�����Ϲ������²��� 
ElementType DeleteMax ( MaxHeap H ) {
	// ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� 
	int Parent, Child;
	ElementType MaxItem, X;
	if ( IsEmpty(H) ) {
		printf("\n");
		return ERROR;
	}
	
	MaxItem = H->Data[1];      // ȡ��������ŵ����ֵ 
	// �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� 
	X = H->Data[H->Size--];    // ע�⵱ǰ�ѵĹ�ģҪС 
	for ( Parent = 1; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if ((Child!=H->Size) && (H->Data[Child] < H->Data[Child+1]) )
			Child++;           // Childָ�������ӽ��Ľϴ��� 
		if ( X >= H->Data[Child]) break;  // �ҵ��˺��ʵ�λ�� 
		else  // ����X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;   // X����µĸ���� 
	
	return MaxItem;   // ���ر�ɾ��ֵ 
}


void PerDown ( MaxHeap H, int p ) {
	// ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� 
	int Parent, Child;
	ElementType X;
	
	X = H->Data[p];      // ȡ������ŵ�ֵ 
	for ( Parent = p; Parent*2 <= H->Size; Parent = Child ) {
		Child = Parent * 2;
		if (( Child != H->Size ) && ( H->Data[Child] < H->Data[Child+1] ))
			Child++;              // Childָ�����ҽ��Ľϴ��� 
		if ( X > H->Data[Child] ) break;   // �ҵ��˺���λ�� 
		else            // ����X 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}


void BuildHeap ( MaxHeap H ) {
	// ����H->Data[p]�е�Ԫ�أ�ʹ�������ѵ������� 
	// ����������е�H->Size��Ԫ���Ѿ�����H->Data[]�� 
	
	int i;
	
	// �����һ�����ĸ���㿪ʼ���������1 
	for ( i = H->Size/2; i > 0; i--)
		PerDown(H, i);
}
