#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#define ERROR -1
#define NotFound 0  // �Ҳ�������0 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* �����˳�򴢴� */

typedef int ElementType;
List MakeEmpty();    // ��ʼ��һ���µĿ����Ա� 
int FindKth( List L, int i );   // ����ָ����λ��i������L����ӦԪ��a(i) 
Position Find( List L, int X );   //   ��֪X���������Ա�L����X��ͬ�ĵ�һ��Ԫ�ص�λ�ã����������򷵻ش�����Ϣ��
bool Insert( List L, int X, int i );      // ��L��ָ��λ��iǰ����һ����Ԫ��X���ɹ�true��ʧ��false 
bool Delete( List L, int i );    //  ��L��ɾ��ָ��λ��i��Ԫ�أ� �ɹ�true��ʧ��false 
int Length( List L);            // �������Ա���L
Position SequentialSearch ( List Tb1, ElementType K ); // ˳�����
Position BinarySearch ( List Tb1, ElementType K ); // ���ֲ��� 
 


int main(int argc, char *argv[]) {
	MakeEmpty();
	
	return 0;
	
}



List MakeEmpty () {
	List L;  // L->Data[i] �����±�Ϊi��Ԫ��    L->Last+1 ��ʾ���� 
	L = (List)malloc(sizeof(PtrToLNode));
	L->Last = -1;
	return L;
}


Position Find ( List L, int X) {
	Position i;
	while ( i <= L->Last && L->Data[i] != X) {
		i++;
	}
	if (i > L->Last ) return ERROR;   // δ�ҵ� ���ش�����Ϣ 
	else return i;   // �ҵ��ˣ���������i ƽ�����Ҵ��� (n+1)/2 ƽ��ʱ�临�Ӷ�ΪO(n) 
}


bool Insert ( List L, int X, int i ) {
	Position j;
	
	if ( L->Last == Maxsize-1 ) {     // ������ ���ܲ��� 
		printf("FULL!");
		return false;
	}
	if ( i < 1 || i > L->Last+2 ) {  // ������λ��ĺϷ��ԣ��Ƿ����1~n+1��nΪ��ǰԪ�ظ�������Last+1 
		printf("λ�򲻺Ϸ�");
		return false;
	} 
	for ( j = L->Last; j >= i-1; j-- ) {  // Lastָ���������Ԫ��a(n) 
		L->Data[j+1] = L->Data[j];   // ��λ��i���Ժ��Ԫ��˳������ƶ� 
	} 
	L->Data[i-1] = X;  // ��Ԫ�ز����iλ���������±�Ϊi-1 
	L->Last++;         // Last��ָ�����Ԫ�� 
	return true;
}


bool Delete( List L, int i) {    // ��L��ɾ��ָ��λ��i��Ԫ�أ���Ԫ�������±�Ϊi-1 
	Position j;
	
	if ( i < 1 || i > L->Last+1 ) {   // �����б�ɾ��λ��ĺϷ��� 
		printf("λ��%d������Ԫ��", i);
		return false;
	}
	for ( j = i; j <= L->Last; j++ ) {
		L->Data[j-1] = L->Data[j];  // ��λ��i+1���Ժ��Ԫ��˳����ǰ�ƶ� 
	}
	L->Last--;                      // Last��ָ�����Ԫ�� 
	return true;
} 


Position SequentialSearch ( List Tb1, ElementType K ) {
	// ��˳�򴢴�ı�Tb1�в��ҹؼ���ΪK������Ԫ�أ�ʹ�á��ڱ��� 
	Position i;
	
	Tb1->Data[0] = K; // �����ڱ� 
	for ( i = Tb1->Last; Tb1->Data[i] != K; i--);
	return i;         // ���ҳɹ���������Ԫ�����ڵ�Ԫ�±ꣻ���Ҳ��ɹ�����0 
}


Position BinarySearch ( List Tb1, ElementType K ) {
	// ��˳��洢�ı�[1...Last]�в��ҹؼ���ΪK������Ԫ�� 
	Position left, right, mid;
	
	left = 1;            // ��ʼ��߽� 
	right = Tb1->Last;   // ��ʼ�ұ߽� 
	while ( left <= right) {
		mid = (left + right) / 2;        // �����м�Ԫ������ 
		if ( K < Tb1->Data[mid] ) right = mid - 1;          // �����ұ߽� 
		else if ( K > Tb1->Data[mid] ) left = mid + 1;      // ������߽� 
		else return mid;         // ���ҳɹ��� ��������Ԫ�ص��±� 
	}
	
	return NotFound;   // ���ز��Ҳ��ɹ��ı�ʶ 
}
