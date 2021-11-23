#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#define ERROR_1 0
#define ERROR_2 NULL

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 
result:
1. �ڵ������ϲ��롢ɾ��һ����㣬����֪����ǰ�����
2.���������а����������ʵ��ص㣬ֻ�ܴ�ͷָ�뿪ʼһ����˳�����
*/ 


int Length( List L );   // ���
int FindKth( List L, int K );   // ��λ����ң�����ָ��λ��K������L����ӦԪ��
Position Find ( List L, int X );    // ��ֵ���� 
List Insert ( List L, int X, int i );   // ���룬�����Ǳ�ͷָ��L��ֵ�仯�������ǲ��뷢���ڱ�ͷ�� 
bool Insert2 ( List L, int X, int i );   // ���룬���ǵ����뷢���ڱ�ͷ���ʱ��L��Ҫָ���µı�ͷ��㡣 
bool Delete( List L, int i);   // ɾ��iֵ 





int main(int argc, char *argv[]) {
	return 0;
}


int Length ( List L ) {
	Position p;
	int cnt = 0;   // ��ʼ�������� 
	p = L;         // p ָ���ĵ�һ����� 
	while ( p ) {
		p = p->Next;
		cnt++;     // ��ǰ p ָ����ǵ�cnt���ڵ� 
	}
	
	return cnt;
}


int FindKth( List L, int K ) {             // ��λ����ң�����ָ��λ��K������L����ӦԪ�� 
	Position p;
	int cnt = 1;            // λ���1��ʼ 
	p = L;                 //  pָ��L�ĵ�1����� 
	while ( p && cnt < K ) {
		p = p->Next;
		cnt++;
	}
	if ( ( cnt == K ) && p )
		return p->Data;              // �ҵ���K�� 
	else
		return ERROR_1;                 // ���ش�����Ϣ 
}


Position Find ( List L, int X ) {                  // ��ֵ���� 
	Position p = L;                               // p ָ��L�ĵ�1����� 
	
	while ( p && p->Data != X ) {
		p = p->Next;
	}
	if( p )       // ����return p�滻 
		return p;
	else
		return ERROR_2;
}


List Insert ( List L, int X, int i ) {
	Position tmp, pre;
	
	tmp = (Position)malloc(sizeof(PtrToLNode));      //���롢��װ��� 
	tmp->Data = X;
	if ( i == 1 ) {          // �½������ڱ�ͷ 
		tmp->Next = L;
		return tmp;       // �����±�ͷָ�� 
	}
	else {
		// ����λ��Ϊi-1�Ľ�� 
		int cnt = 1;             // λ���1��ʼ 
		pre = L;                 // pre ָ��L�ĵ�1����� 
		while ( pre && cnt < i-1 ) {
			pre = pre ->Next;
			cnt++;
		}
	
		if ( pre == NULL || cnt != i-1 ) {                // ���ҽ�㲻��L�� 
			printf("����λ�ò�������\n");
			free(tmp);
			return ERROR_2;
		}
		else {       // �ҵ��˴������ǰһ�����pre 
			// �����½�㣬���ҷ��ر�ͷL 
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
	if ( i == 1) {                  // ???��֪���Ƿ���ȷ������Ĭ���б�ͷ 
		tmp->Next = L;
		return tmp;
	}
	else {
		 // Ĭ���б�ͷ 
		int cnt = 0;
		// ����λ��Ϊi-1�Ľ�� 
		pre = L;              // pre ָ���ͷ 
		while ( pre && cnt < i-1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i-1 ) {         // ���ҽ�㲻��L�� 
			printf("����λ�ò�������\n");
			return false;
		}
		else {                       // �ҵ��˴������ǰһ���pre����iΪ1��preָ���ͷ 
			// �����½��
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
		// ����Ĭ���б�ͷ 
		int cnt = 0;
		// ����λ��Ϊi-1�Ľ�� 
		pre = L;          // pre ָ���ͷ 
		while ( pre && cnt < i-1 ) {
			pre = pre->Next;
			cnt++;
		}
		if ( pre == NULL || cnt != i-1 || pre->Next == NULL ) {
			// ���ҽ���λ��Ϊi�Ľ�㲻��L�� 
			printf("ɾ��λ�ò�������\n");
			return false;
		}
		else {    // �ҵ��˴�ɾ������ǰһ�����pre 
			// �����ɾ�� 
			tmp = pre->Next;        // ����ɾ�����ĵ�ַ����tmp�� 
			pre->Next = tmp->Next;   // preָ����һ����ַ 
			free(tmp);              // �ͷ�tmp������ĵ�ַ�ڴ棬 ɾ���ý�� 
			return true;
		}
	}

}
