#include <stdio.h>
#include <stdlib.h>
#include "TNode.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*binary search tree p125*/ 

/*������������ɾ�� p130
1.Ҫɾ������Ҷ��㣬����ֱ��ɾ��
2.Ҫɾ���Ľ��ֻ��һ�����ӽ�㣨��һ����Ҷ��㣬�����������ĸ�����ɾ��֮ǰ��Ҫ�ı��丸����ָ�룬ָ����Ҫɾ�����ĺ��ӽ��
3.Ҫɾ���Ľ����������������*/

/*�������������в��ҵ�ʱ�临�Ӷ����ɲ��ҹ����еıȽϴ����������ģ��Ӹ���㵽Ҷ����·�����У�ȡ�����������
��������O(logN)���˻��ɵ�֧����O(N)*/

 
int main(int argc, char *argv[]) {
	return 0;
}


Position Find ( BinTree BST, ElementType X ) {
	while ( BST ) {
		if ( X > BST->Data ) 
			BST = BST->Right;              // �����������ƶ����������� 
		else if ( X < BST->Data )
			BST = BST->Left;              // �����������ƶ����������� 
		else 
			break;	 // �ڵ�ǰ�����ҳɹ�������ѭ�� 
	}
	return BST;    // �Ż��ҵ��Ľ���ַ������NULL 
}


Position FindMax ( BinTree BST ) {
	if ( BST ) {
		while ( BST->Right ) {
			BST = BST->Right;                    // ���ҷ�֧һֱ���£�ֱ�����Ҷ˵� 
		}
	return BST;
	}
}


Position FindMin ( BinTree BST ) {
	if ( BST ) {
		while ( BST->Left) {
			BST = BST->Left;                    // �����֧һֱ���£�ֱ�����Ҷ˵� 
		}
	return BST;
	}
}

// ���ϵݹ���� 
BinTree Insert ( BinTree BST, ElementType X ) {
	if ( !BST ) {                      // ����Ϊ�գ����ɲ�����һ�����Ķ��������� 
		BST = (BinTree)malloc(sizeof(struct TNode));         // ������ 
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {               // ��ʼ��Ҫ����Ԫ�ص�λ�� 
		if ( X < BST->Data )
			BST->Left = Insert(BST->Left, X);        // �ݹ���������� 
		else if ( X > BST->Data )
			BST->Right = Insert(BST->Right, X);       // �ݹ���������� 
		/*else X �Ѿ����ڣ�ʲô������*/ 
			
	}
	return BST; // ���ؽ���ַ 
}


//�ݹ�
BinTree Delete( BinTree BST, ElementType X ) {
	Position Tmp;
	if ( !BST )
		printf("\n");
	else {
		if ( X < BST->Data )
			BST->Left = Delete(BST->Left, X);
		else if ( X > BST->Data ) 
			BST->Right = Delete(BST->Right, X);
		else {     // BST����Ҫɾ���Ľ�� 
			// �����ɾ����������������ֽ�� 
			if ( BST->Left && BST->Right ){
				// �����������ҵ���С��Ԫ����䲢ɾ����� 
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				// ����������ɾ����СԪ�� 
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else {   // ��ɾ�������һ�������ӽ�� 
				Tmp = BST;
				if ( !BST->Left ) 
					BST = BST->Right;          // ֻ���Һ��ӻ����ӽ�� 
				else
					BST = BST->Left;           // ֻ������ 
				free(Tmp);
			}
		}
	}
}

 
/*�ݹ� 
Position Find ( BinTree BST, ElementType X ) {
	if ( !BST ) return NULL;   //
	
	if ( BST > BST->Data )
		return Find(BST->Right, X);           //
	else if ( X < BST->Data )
		return Find(BST->Left, X);             //
	else             
		return BST;            // 
}


//�ݹ� 
Position FindMin ( BinTree BST ) {
	// ��СԪ��������˵� 
	if ( !BST ) return NULL;                    // �յĶ���������������NULL 
	else if ( !BST->Left ) return BST;      // �ҵ�����˵㲢���� 
	else return FindMin(BST->Left);        // �ط�֧�ݹ���� 
}
*/




