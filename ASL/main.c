#include <stdio.h>
#include <stdlib.h>
#include "AVLNode.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Position AVLTree;    // AVL������ 

AVLTree Insert ( AVLTree T, ElementType X ); 
int Max ( int a, int b );
int GetHeight ( AVLTree T );
AVLTree SingleLeftRotation ( AVLTree A );
AVLTree SingleRightRotation ( AVLTree A );
AVLTree DoubleLeftRightRotation ( AVLTree A );

int main(int argc, char *argv[]) {
	return 0;
}


int Max ( int a, int b ) {
	return a > b ? a: b;
}


AVLTree Insert ( AVLTree T, ElementType X ) {
	// ��X����AVL��T�У����ҷ��ص������AVL�� 
	if ( !T ) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 1;
		T->Left = T->Right = NULL;
	} // if(�������)���� 
	
	
	else if ( X < T->Data ) {
		// ����T�������� 
		T->Left = Insert(T->Left, X);
		// �����Ҫ���� 
		if ( GetHeight(T->Left) - GetHeight(T->Right) == 2 ) {
			if ( X < T->Left->Data )
				T = SingleLeftRotation(T);    //
			else 
				T = DoubleLeftRightRotation(T);   //
		}
	}    // else if(����������)���� 
	else if ( X > T->Data ) {
		// ����T�������� 
		T->Right = Insert(T->Right, X);
		// �����Ҫ���� 
		if ( GetHeight(T->Left) - GetHeight(T->Right) == -2 ) {
			if ( X > T->Right->Data ) 
				T = SingleRightRotation(T);      //
			else
				T = DoubleLeftRightRotation(T);     //
		}      
	}     // else if(����������)���� 
	/* else X == T->Data �������*/
	
	// �������� 
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
}


int GetHeight ( AVLTree T ) {
	int HL, HR, MaxH;
	
	if ( T ) {
		HL = GetHeight(T->Left);            // ���������߶� 
		HR = GetHeight(T->Right);           // ���������߶� 
		MaxH = HL > HR ? HL: HR;            // ȡ���������ϴ�ĸ߶� 
		return(MaxH + 1);                 // �������ĸ߶� 
	}
	
	else return 0;                   // �����߶�Ϊ0 
}


AVLTree SingleLeftRotation ( AVLTree A ) {
	// A������һ�����ӽ�� 
	// A��B��ͼ4.35��ʾ�������������µĸ��ڵ�B 
	
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	
	return B;
}


AVLTree SingleRightRotation ( AVLTree A ) {
	// A������һ�����ӽ�� 
	// 
	
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	
	return B;
}


AVLTree DoubleLeftRightRotation ( AVLTree A ) {
	// ������һ�����ӽ��B����B������һ�����ӽ��C 
	// A.B.C��ͼ4.38��ʾ�����ε����������µĸ����C 
	
	// ��B��C���ҵ�����C������ 
	A->Left = SingleRightRotation(A->Left);
	// ��A��C��������C������ 
	return SingleLeftRotation(A);
} 
