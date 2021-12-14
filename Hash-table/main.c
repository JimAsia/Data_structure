#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Hash.h"

#define MAXTABLESIZE 100000     // �����ٵ����ɢ�б��� 


/*
ɢ�в��ҷ����������������
1.����λ�ã�����ɢ�нṹ����ȷ���ؼ��ʴ洢λ��
2.�����ͻ��Ӧ��ĳ�ֲ��Խ������ؼ���λ����ͬ��λ��
ʱ�临�Ӷȼ����ǳ���O(1)��������ʱ���������ģ�޹�

�������ƣ����ű�(SymbolTable)
���ݶ��󼯣����ű��ǡ�����(Name)-����(Attribute)���Եļ���
��������Table ���� SymbolTable, Name����NameType, Attr����AttributeType 
*/

int NextPrime(int N); 
HashTable CreatTable(int TableSize);
Position Find(HashTable H, ElementType Key);
bool Insert(HashTable H, ElementType Key);
Position Hash(ElementType Key, int TableSize);


int main(int argc, char *argv[]) {
	return 0;
}

Position Hash(ElementType Key, int TableSize) {
	return Key%TableSize;
}


int NextPrime(int N) {
	//  ���ش���N�Ҳ�����MAXTABLESIZE����С���� 
	int i, p = (N%2) ? N+2: N+1;    // �Ӵ���N����һ��������ʼ 
	
	while ( p < MAXTABLESIZE ) {
		for ( i = (int)sqrt(p); i > 2; i--)
			if ( ! (p % i)) break;    // p�������� 
		if ( i == 2 ) break;    // for����������˵��p������ 
		else p += 2;            // ������̽��һ������ 
	}
	return p;
}


HashTable CreatTable(int TableSize) {
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	// ��֤ɢ�б���󳤶������� 
	H->TableSize = NextPrime(TableSize);
	// ������Ԫ���� 
	H->Cells = (Cell*)malloc(H->TableSize * sizeof(Cell));
	// ��ʼ����Ԫ״̬Ϊ�����б� 
	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Info = Empty;
	}
	return H;
}



Position Find(HashTable H, ElementType Key) {
	Position CurrentPos, NewPos;
	int CNum = 0;   // ��¼��ͻ���� 
	
	NewPos = CurrentPos = Hash(Key, H->TableSize);      // ��ʼɢ��λ�� 
	// ����λ�õĵ�Ԫ�ſգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ 
	while(H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		// �ַ������͵Ĺؼ�����Ҫstrcmp���� 
		// ͳ��һ�γ�ͻ�����ж���ż 
		if ( ++CNum % 2) {
			// ����Ϊ+[(CNum+1)/2]^2 
			// �����γ�ͻ 
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4;
			if ( NewPos >= H->TableSize )
				NewPos = NewPos % H->TableSize;      // ����Ϊ�Ϸ���ַ 
		}
		else {   // ż���γ�ͻ 
			NewPos = CurrentPos - CNum * CNum / 4; // ����Ϊ-(CNum/2)^2 
			while ( NewPos < 0 ) 
				NewPos += H->TableSize;      // ����Ϊ�Ϸ���ַ 
		}
	}
	return NewPos;
	// ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ����� 
}


bool Insert(HashTable H, ElementType Key) {
	Position Pos = Find(H, Key);          // �ȼ��key�Ƿ���� 
	
	if ( H->Cells[Pos].Info != Legitimate ) {
		// ��������Ԫû�б�ռ��˵��key���Բ����ڴ� 
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		// �ַ������͵Ĺؼ�����Ҫstrcpy���� 
		return true;
	}
	else {
		printf("��ֵ�Ѵ���\n");
		return false;
	}
}


