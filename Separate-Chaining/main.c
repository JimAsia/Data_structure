#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "TblNode.h"
#define MAXTABLESIZE 100000 // ������ɢ�б�ĳ��� 

typedef char ElementType[KEYLENGTH+1]; //
typedef int Index;


int main(int argc, char *argv[]) {
	return 0;
}

int Hash(const char* Key, int TableSize) {
	unsigned int H;          // ɢ�к���ֵ����ʼ��Ϊ0 
	while ( *Key != '\0' )   // λ��ӳ�� 
		H = (H<<5) + *Key++;
	return H%TableSize;
}


int NextPrime(int N) {
	int i, p = (N%2) ?N+2: N+1;     // �Ӵ���N����һ��������ʼ
	
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
	// ��֤ɢ�б���󳤶������� 
	H->TableSize = NextPrime(TableSize);
	// �����б�ͷ�������
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	// ��ʼ����ͷ��� 
	for ( i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	
	return H;
}


Position Find(HashTable H, ElementType Key) {
	Position P;
	Index Pos;
	
	Pos = Hash(Key, H->TableSize);       // ��ʼɢ��λ�� 
	P = H->Heads[Pos].Next;              // �Ӹ�����ĵ�1����㿪ʼ 
	// ��δ����β������Keyδ�ҵ�ʱ 
	while ( P && strcmp(P->Data, Key))
		P = P->Next;
		
		
	return P;     // ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL 
}


bool Insert(HashTable H, ElementType Key) {
	Position P, NewCell;
	Index Pos;
	
	P = Find(H, Key);
	if ( !P ) {                                  // �ؼ���δ�ҵ������Բ��� 
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		Pos = Hash(Key, H->TableSize);            // ��ʼ��ɢ��λ�� 
		// ��NewCell����δH->Heads[Pos]����ĵ�1����� 
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else {   // �ؼ����Ѿ����� 
		printf("��ֵ�Ѿ�����\n");
		return false;
	}
}


void DestroyTable(HashTable H) {
	int i;
	Position P, Tmp;
	
	// �ͷ�ÿ������Ľ�� 
	for ( i = 0; i < H->TableSize; i++ ) {
		P = H->Heads[i].Next;
		free(P);
		P = Tmp;
	}
	free(H->Heads);         // �ͷ�ͷ������� 
	free(H);                // �ͷ�ɢ�б��� 
}
