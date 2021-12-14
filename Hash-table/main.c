#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Hash.h"

#define MAXTABLESIZE 100000     // 允许开辟的最大散列表长度 


/*
散列查找法的两项基本工作：
1.计算位置：构造散列结构函数确定关键词存储位置
2.解决冲突：应用某种策略解决多个关键词位置相同的位置
时间复杂度几乎是常量O(1)，即查找时间与问题规模无关

类型名称：符号表(SymbolTable)
数据对象集：符号表是“名字(Name)-属性(Attribute)”对的集合
操作集：Table 属于 SymbolTable, Name属于NameType, Attr属于AttributeType 
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
	//  返回大于N且不超过MAXTABLESIZE的最小素数 
	int i, p = (N%2) ? N+2: N+1;    // 从大于N的下一个奇数开始 
	
	while ( p < MAXTABLESIZE ) {
		for ( i = (int)sqrt(p); i > 2; i--)
			if ( ! (p % i)) break;    // p不是素数 
		if ( i == 2 ) break;    // for正常结束，说明p是素数 
		else p += 2;            // 否则试探下一个奇数 
	}
	return p;
}


HashTable CreatTable(int TableSize) {
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	// 保证散列表最大长度是素数 
	H->TableSize = NextPrime(TableSize);
	// 声明单元数组 
	H->Cells = (Cell*)malloc(H->TableSize * sizeof(Cell));
	// 初始化单元状态为“空列表” 
	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Info = Empty;
	}
	return H;
}



Position Find(HashTable H, ElementType Key) {
	Position CurrentPos, NewPos;
	int CNum = 0;   // 记录冲突次数 
	
	NewPos = CurrentPos = Hash(Key, H->TableSize);      // 初始散列位置 
	// 当该位置的单元排空，并且不是要找的元素时，发生冲突 
	while(H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		// 字符串类型的关键词需要strcmp函数 
		// 统计一次冲突，并判断奇偶 
		if ( ++CNum % 2) {
			// 增量为+[(CNum+1)/2]^2 
			// 奇数次冲突 
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4;
			if ( NewPos >= H->TableSize )
				NewPos = NewPos % H->TableSize;      // 调整为合法地址 
		}
		else {   // 偶数次冲突 
			NewPos = CurrentPos - CNum * CNum / 4; // 增量为-(CNum/2)^2 
			while ( NewPos < 0 ) 
				NewPos += H->TableSize;      // 调整为合法地址 
		}
	}
	return NewPos;
	// 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到） 
}


bool Insert(HashTable H, ElementType Key) {
	Position Pos = Find(H, Key);          // 先检查key是否存在 
	
	if ( H->Cells[Pos].Info != Legitimate ) {
		// 如果这个单元没有被占，说明key可以插入在此 
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		// 字符串类型的关键词需要strcpy函数 
		return true;
	}
	else {
		printf("键值已存在\n");
		return false;
	}
}


