#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#define ERROR_1 0
#define ERROR_2 NULL

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 
result:
1. 在单链表上插入、删除一个结点，必须知道其前驱结点
2.单链表不具有按序号随机访问的特点，只能从头指针开始一个个顺序进行
*/ 


int Length( List L );   // 求表长
int FindKth( List L, int K );   // 按位序查找，根据指定位序K，返回L中相应元素
Position Find ( List L, int X );    // 按值查找 
List Insert ( List L, int X, int i );   // 插入，不考虑表头指针L的值变化（不考虑插入发生在表头） 
bool Insert2 ( List L, int X, int i );   // 插入，考虑当插入发生在表头结点时，L需要指向新的表头结点。 
bool Delete( List L, int i);   // 删除i值 





int main(int argc, char *argv[]) {
	return 0;
}


int Length ( List L ) {
	Position p;
	int cnt = 0;   // 初始化计数器 
	p = L;         // p 指向表的第一个结点 
	while ( p ) {
		p = p->Next;
		cnt++;     // 当前 p 指向的是第cnt个节点 
	}
	
	return cnt;
}


int FindKth( List L, int K ) {             // 按位序查找，根据指定位序K，返回L中相应元素 
	Position p;
	int cnt = 1;            // 位序从1开始 
	p = L;                 //  p指向L的第1个结点 
	while ( p && cnt < K ) {
		p = p->Next;
		cnt++;
	}
	if ( ( cnt == K ) && p )
		return p->Data;              // 找到第K个 
	else
		return ERROR_1;                 // 返回错误信息 
}


Position Find ( List L, int X ) {                  // 按值查找 
	Position p = L;                               // p 指向L的第1个结点 
	
	while ( p && p->Data != X ) {
		p = p->Next;
	}
	if( p )       // 可用return p替换 
		return p;
	else
		return ERROR_2;
}


List Insert ( List L, int X, int i ) {
	Position tmp, pre;
	
	tmp = (Position)malloc(sizeof(PtrToLNode));      //申请、填装结点 
	tmp->Data = X;
	if ( i == 1 ) {          // 新结点插入在表头 
		tmp->Next = L;
		return tmp;       // 返回新表头指针 
	}
	else {
		// 查找位序为i-1的结点 
		int cnt = 1;             // 位序从1开始 
		pre = L;                 // pre 指向L的第1个结点 
		while ( pre && cnt < i-1 ) {
			pre = pre ->Next;
			cnt++;
		}
	
		if ( pre == NULL || cnt != i-1 ) {                // 所找结点不在L中 
			printf("插入位置参数错误\n");
			free(tmp);
			return ERROR_2;
		}
		else {       // 找到了待插结点的前一个结点pre 
			// 插入新结点，并且返回表头L 
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}
	}
}


bool Insert2 ( List L, int X, int i ) {
	Position tmp, pre;
	
	tmp = (Position)malloc(sizeof(PtrToLNode));
	tmp->Data = X;
	if ( i == 1) {                  // ???不知道是否正确，书上默认有表头 
		tmp->Next = L;
		return tmp;
	}
	else {
		 // 默认有表头 
		int cnt = 0;
		// 查找位序为i-1的结点 
		pre = L;              // pre 指向表头 
		while ( pre && cnt < i-1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i-1 ) {         // 所找结点不在L中 
			printf("插入位置参数错误\n");
			return false;
		}
		else {                       // 找到了待插结点的前一结点pre；若i为1，pre指向表头 
			// 插入新结点
			/* tmp = (Position)malloc(sizeof(PtrToLNode));
			   tmp->Data = X; */ 
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return true;
		}
	}

}


bool Delete( List L, int i) {
	Position tmp, pre;
	
	if ( i == 1) {
		tmp->Next = L;
		return tmp;
	}
	else {
		// 书上默认有表头 
		int cnt = 0;
		// 查找位序为i-1的结点 
		pre = L;          // pre 指向表头 
		while ( pre && cnt < i-1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i-1 || pre->Next == NULL ) {
			// 所找结点或位序为i的结点不在L中 
			printf("删除位置参数错误\n");
			return false;
		}
		else {    // 找到了待删除结点的前一个结点pre 
			// 将结点删除 
			tmp = pre->Next;        // 将待删除结点的地址存入tmp中 
			pre->Next = tmp->Next;   // pre指向下一个地址 
			free(tmp);              // 释放tmp所储存的地址内存， 删除该结点 
			return true;
		}
	}

}
