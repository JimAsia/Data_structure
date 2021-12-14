#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "TblNode.h"
#define MAXTABLESIZE 100000 // 允许开辟散列表的长度 

typedef char ElementType[KEYLENGTH+1]; //
typedef int Index;


int main(int argc, char *argv[]) {
	return 0;
}

int Hash(const char* Key, int TableSize) {
	unsigned int H;          // 散列函数值，初始化为0 
	while ( *Key != '\0' )   // 位移映射 
		H = (H<<5) + *Key++;
	return H%TableSize;
}


int NextPrime(int N) {
	int i, p = (N%2) ?N+2: N+1;     // 从大于N的下一个奇数开始
	
	while( p < MAXTABLESIZE ) {
		for( i = (int)sqrt(p); i > 2; i-- ) {
			if( ! (p%i) ) break;
		}
		if( i == 2 ) break;
		else p += 2;
	}
	return p;
}

HashTable  CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	// 保证散列表最大长度是素数 
	H->TableSize = NextPrime(TableSize);
	// 分配列表头结点数组
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	// 初始化表头结点 
	for ( i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	
	return H;
}


Position Find(HashTable H, ElementType Key) {
	Position P;
	Index Pos;
	
	Pos = Hash(Key, H->TableSize);       // 初始散列位置 
	P = H->Heads[Pos].Next;              // 从该链表的第1个结点开始 
	// 当未到表尾，并且Key未找到时 
	while ( P && strcmp(P->Data, Key))
		P = P->Next;
		
		
	return P;     // 此时P或者指向找到的结点，或者为NULL 
}


bool Insert(HashTable H, ElementType Key) {
	Position P, NewCell;
	Index Pos;
	
	P = Find(H, Key);
	if ( !P ) {                                  // 关键词未找到，可以插入 
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		Pos = Hash(Key, H->TableSize);            // 初始化散列位置 
		// 将NewCell插入未H->Heads[Pos]链表的第1个结点 
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else {   // 关键词已经存在 
		printf("键值已经存在\n");
		return false;
	}
}


void DestroyTable(HashTable H) {
	int i;
	Position P, Tmp;
	
	// 释放每个链表的结点 
	for ( i = 0; i < H->TableSize; i++ ) {
		P = H->Heads[i].Next;
		free(P);
		P = Tmp;
	}
	free(H->Heads);         // 释放头结点数组 
	free(H);                // 释放散列表结点 
}
