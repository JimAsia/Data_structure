#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#define ERROR -1
#define NotFound 0  // 找不到返回0 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* 链表的顺序储存 */

typedef int ElementType;
List MakeEmpty();    // 初始化一个新的空线性表 
int FindKth( List L, int i );   // 根据指定的位序i，返回L中相应元素a(i) 
Position Find( List L, int X );   //   已知X，返回线性表L中与X相同的第一个元素的位置；若不存在则返回错误信息。
bool Insert( List L, int X, int i );      // 在L的指定位序i前插入一个新元素X；成功true，失败false 
bool Delete( List L, int i );    //  从L中删除指定位序i的元素； 成功true，失败false 
int Length( List L);            // 返回线性表长度L
Position SequentialSearch ( List Tb1, ElementType K ); // 顺序查找
Position BinarySearch ( List Tb1, ElementType K ); // 二分查找 
 


int main(int argc, char *argv[]) {
	MakeEmpty();
	
	return 0;
	
}



List MakeEmpty () {
	List L;  // L->Data[i] 访问下标为i的元素    L->Last+1 表示长度 
	L = (List)malloc(sizeof(PtrToLNode));
	L->Last = -1;
	return L;
}


Position Find ( List L, int X) {
	Position i;
	while ( i <= L->Last && L->Data[i] != X) {
		i++;
	}
	if (i > L->Last ) return ERROR;   // 未找到 返回错误信息 
	else return i;   // 找到了，返回数字i 平均查找次数 (n+1)/2 平均时间复杂度为O(n) 
}


bool Insert ( List L, int X, int i ) {
	Position j;
	
	if ( L->Last == Maxsize-1 ) {     // 表满， 不能插入 
		printf("FULL!");
		return false;
	}
	if ( i < 1 || i > L->Last+2 ) {  // 检查插入位序的合法性：是否存在1~n+1。n为当前元素个数，即Last+1 
		printf("位序不合法");
		return false;
	} 
	for ( j = L->Last; j >= i-1; j-- ) {  // Last指向序列最后元素a(n) 
		L->Data[j+1] = L->Data[j];   // 将位序i及以后的元素顺序向后移动 
	} 
	L->Data[i-1] = X;  // 新元素插入第i位序，其数组下标为i-1 
	L->Last++;         // Last仍指向最后元素 
	return true;
}


bool Delete( List L, int i) {    // 从L中删除指定位序i的元素，该元素数组下标为i-1 
	Position j;
	
	if ( i < 1 || i > L->Last+1 ) {   // 检查空列表及删除位序的合法性 
		printf("位序%d不存在元素", i);
		return false;
	}
	for ( j = i; j <= L->Last; j++ ) {
		L->Data[j-1] = L->Data[j];  // 将位序i+1及以后的元素顺序向前移动 
	}
	L->Last--;                      // Last仍指向最后元素 
	return true;
} 


Position SequentialSearch ( List Tb1, ElementType K ) {
	// 再顺序储存的表Tb1中查找关键字为K的数据元素，使用“哨兵” 
	Position i;
	
	Tb1->Data[0] = K; // 建立哨兵 
	for ( i = Tb1->Last; Tb1->Data[i] != K; i--);
	return i;         // 查找成功返回数据元素所在单元下标；查找不成功返回0 
}


Position BinarySearch ( List Tb1, ElementType K ) {
	// 再顺序存储的表[1...Last]中查找关键字为K的数据元素 
	Position left, right, mid;
	
	left = 1;            // 初始左边界 
	right = Tb1->Last;   // 初始右边界 
	while ( left <= right) {
		mid = (left + right) / 2;        // 计算中间元素坐标 
		if ( K < Tb1->Data[mid] ) right = mid - 1;          // 调整右边界 
		else if ( K > Tb1->Data[mid] ) left = mid + 1;      // 调整左边界 
		else return mid;         // 查找成功， 返回数据元素的下标 
	}
	
	return NotFound;   // 返回查找不成功的标识 
}
