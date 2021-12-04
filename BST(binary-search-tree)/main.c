#include <stdio.h>
#include <stdlib.h>
#include "TNode.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*binary search tree p125*/ 

/*二叉搜索树的删除 p130
1.要删除的是叶结点，可以直接删除
2.要删除的结点只有一个孩子结点（不一定是叶结点，可以是子树的根），删除之前需要改变其父结点的指针，指向需要删除结点的孩子结点
3.要删除的结点有左右两棵子树*/

/*二叉搜索树进行查找的时间复杂度是由查找过程中的比较次数来衡量的，从根结点到叶结点的路径进行，取决于树的深度
最好情况是O(logN)，退化成单支树是O(N)*/

 
int main(int argc, char *argv[]) {
	return 0;
}


Position Find ( BinTree BST, ElementType X ) {
	while ( BST ) {
		if ( X > BST->Data ) 
			BST = BST->Right;              // 向右子树中移动，继续查找 
		else if ( X < BST->Data )
			BST = BST->Left;              // 向左子树中移动，继续查找 
		else 
			break;	 // 在当前结点查找成功，跳出循环 
	}
	return BST;    // 放回找到的结点地址，或是NULL 
}


Position FindMax ( BinTree BST ) {
	if ( BST ) {
		while ( BST->Right ) {
			BST = BST->Right;                    // 沿右分支一直向下，直到最右端点 
		}
	return BST;
	}
}


Position FindMin ( BinTree BST ) {
	if ( BST ) {
		while ( BST->Left) {
			BST = BST->Left;                    // 沿左分支一直向下，直到最右端点 
		}
	return BST;
	}
}

// 书上递归代码 
BinTree Insert ( BinTree BST, ElementType X ) {
	if ( !BST ) {                      // 若树为空，生成并返回一个结点的二叉搜索树 
		BST = (BinTree)malloc(sizeof(struct TNode));         // 申请结点 
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {               // 开始找要插入元素的位置 
		if ( X < BST->Data )
			BST->Left = Insert(BST->Left, X);        // 递归插入左子树 
		else if ( X > BST->Data )
			BST->Right = Insert(BST->Right, X);       // 递归插入右子树 
		/*else X 已经存在，什么都不做*/ 
			
	}
	return BST; // 返回结点地址 
}


//递归
BinTree Delete( BinTree BST, ElementType X ) {
	Position Tmp;
	if ( !BST )
		printf("\n");
	else {
		if ( X < BST->Data )
			BST->Left = Delete(BST->Left, X);
		else if ( X > BST->Data ) 
			BST->Right = Delete(BST->Right, X);
		else {     // BST就是要删除的结点 
			// 如果被删除结点有左右两个字结点 
			if ( BST->Left && BST->Right ){
				// 从右子树中找到最小的元素填充并删除结点 
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				// 从右子树中删除最小元素 
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else {   // 被删除结点有一个或无子结点 
				Tmp = BST;
				if ( !BST->Left ) 
					BST = BST->Right;          // 只有右孩子或无子结点 
				else
					BST = BST->Left;           // 只有左孩子 
				free(Tmp);
			}
		}
	}
}

 
/*递归 
Position Find ( BinTree BST, ElementType X ) {
	if ( !BST ) return NULL;   //
	
	if ( BST > BST->Data )
		return Find(BST->Right, X);           //
	else if ( X < BST->Data )
		return Find(BST->Left, X);             //
	else             
		return BST;            // 
}


//递归 
Position FindMin ( BinTree BST ) {
	// 最小元素在最左端点 
	if ( !BST ) return NULL;                    // 空的二叉搜素树，返回NULL 
	else if ( !BST->Left ) return BST;      // 找到最左端点并返回 
	else return FindMin(BST->Left);        // 沿分支递归查找 
}
*/




