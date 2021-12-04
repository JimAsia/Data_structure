#include <stdio.h>
#include <stdlib.h>
#include "AVLNode.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Position AVLTree;    // AVL树类型 

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
	// 将X插入AVL树T中，并且返回调整后的AVL树 
	if ( !T ) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 1;
		T->Left = T->Right = NULL;
	} // if(插入空树)结束 
	
	
	else if ( X < T->Data ) {
		// 插入T的左子树 
		T->Left = Insert(T->Left, X);
		// 如果需要左旋 
		if ( GetHeight(T->Left) - GetHeight(T->Right) == 2 ) {
			if ( X < T->Left->Data )
				T = SingleLeftRotation(T);    //
			else 
				T = DoubleLeftRightRotation(T);   //
		}
	}    // else if(插入左子树)结束 
	else if ( X > T->Data ) {
		// 插入T的右子树 
		T->Right = Insert(T->Right, X);
		// 如果需要右旋 
		if ( GetHeight(T->Left) - GetHeight(T->Right) == -2 ) {
			if ( X > T->Right->Data ) 
				T = SingleRightRotation(T);      //
			else
				T = DoubleLeftRightRotation(T);     //
		}      
	}     // else if(插入右子树)结束 
	/* else X == T->Data 无需插入*/
	
	// 更新树高 
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
}


int GetHeight ( AVLTree T ) {
	int HL, HR, MaxH;
	
	if ( T ) {
		HL = GetHeight(T->Left);            // 求左子树高度 
		HR = GetHeight(T->Right);           // 求右子树高度 
		MaxH = HL > HR ? HL: HR;            // 取左右子树较大的高度 
		return(MaxH + 1);                 // 返回树的高度 
	}
	
	else return 0;                   // 空树高度为0 
}


AVLTree SingleLeftRotation ( AVLTree A ) {
	// A必须有一个左子结点 
	// A与B做图4.35所示的左单旋，返回新的根节点B 
	
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	
	return B;
}


AVLTree SingleRightRotation ( AVLTree A ) {
	// A必须有一个右子结点 
	// 
	
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	
	return B;
}


AVLTree DoubleLeftRightRotation ( AVLTree A ) {
	// 必须有一个左子结点B，且B必须有一个右子结点C 
	// A.B.C做图4.38所示的两次单旋，返回新的根结点C 
	
	// 将B与C做右单旋，C被返回 
	A->Left = SingleRightRotation(A->Left);
	// 将A与C做左单旋，C被返回 
	return SingleLeftRotation(A);
} 
