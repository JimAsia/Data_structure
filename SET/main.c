#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000                 /* ���ϵ����Ԫ�ظ��� */

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElementType;                  // Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;                      // Ĭ���ø������±���Ϊ�������� 
typedef ElementType SetType[MAXN];        // ���輯��Ԫ���´�0��ʼ 
SetName Find ( SetType S, ElementType X );      // 
void Union ( SetType S, SetName Root1, SetName Root2 );     // 

int main(int argc, char *argv[]) {
	return 0;
}

/*
SetName Find ( SetType S, ElementType X ) {
	// Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 
	for ( ; S[X] >= 0; X = S[X] );
	return X;
}
*/


/*
void Union ( SerType S, SetName Root1, SetName Root2 ) {
	// ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� 
	s[Root2] = Root1;
}
*/


void Union ( SetType S, SetName Root1, SetName Root2 ) {
	// ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� 
	// ��֤С���ϲ���󼯺� 
	if ( S[Root2] < S[Root1] ) {        // �������2�Ƚϴ� 
		S[Root2] += S[Root1];           // ����1���뼯��2 
		S[Root1] = Root2;
	}
	else {                              // �������1�Ƚϴ� 
		S[Root1] += S[Root2];           // ����2���뼯��1 
		S[Root2] += Root1;           
	}
}


SetName Find ( SetType S, ElementType X ) {
	// Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 
	if ( S[X] < 0 )   // �ҵ����ϵĸ� 
		return X;
	else
		return S[X] = Find(S, S[X]); // ·��ѹ�� 
}
