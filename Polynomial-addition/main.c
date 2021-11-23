#include <stdio.h>
#include <stdlib.h>
#include "Poly.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 多项式相加 p1=9x^12+15x^8+3x^2
			  p2=26x^19-4x^8-13x^6+82x^0
			  p = p1 + p2 =  9x^12+11x^8+3x^2+26x^19-13x^6+82x^0
*/
/* linkmode:coef(系数值) expon(指数值) PtrRear(指向下一个列表的指针)*/ 
typedef PtrToPloyNode Polynomial;
int Compare ( int e1, int e2 );
void Attach ( int coef, int expon, Polynomial *PtrRear );
Polynomial PolyAdd ( Polynomial P1, Polynomial P2 );


int main(int argc, char *argv[]) {
	return 0;
}


int Compare ( int e1, int e2 ) {
	// 比较两项指数e1和e2，根据大、小、等三种情况并返回1，-1，0 
	if ( e1 > e2 ) return 1;          // e1大返回1 
	else if( e1 < e2 ) return -1;       // e2大返回-1 
	else return 0;                    // 相等返回0 
}

void Attach ( int coef, int expon, Polynomial *PtrRear ) {
	// 由于本函数中需要改变当前结果表达式尾项指针的值 
	// 所以函数进来的是尾项结点指针的地址， *PtrRear指向尾项 
	Polynomial P;
	
	/*申请新结点，并赋值*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expon = expon;
	P->link = NULL;
	//将P指向的新结点插入到当前结果表达式尾项的后面 
	(*PtrRear)->link = P;
	*PtrRear = P;            // 修改PtrRear值 
	
}


Polynomial PolyAdd ( Polynomial P1, Polynomial P2 ) {
	Polynomial front, rear, temp;
	int sum;
	// 为方便表头插入，先产生一个临时空结点作为结果多项式链表头 
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;               // 由front记录结果多项式链表头结点 
	while ( P1 && P2 ) {   // 当两个多项式都有非零项待处理时   指数从大到小，相等的指数系数相加
		switch(Compare(P1->expon, P2->expon)) {
		
			case 1:              // P1中的数据项指数较大 
				Attach(P1->coef, P1->expon, &rear);  
				P1 = P1->link;
				break;
			case -1:             // P2中的数据项指数较大 
				Attach(P2->coef, P2->expon, &rear);
				P2 = P2->link;
				break;
			case 0:              // 两数据指数相等 
				sum=P1->coef + P2->coef;
				if (sum) Attach(sum, P1->expon, &rear);
				P1 = P1->link;
				P2 = P2->link;
				break;
		}
	}
	// 将未处理完的另一个多项式的所有结点依次复制到结果多项式中去 
	for( ; P1; P1=P1->link) Attach(P1->coef, P1->expon, &rear);
	for( ; P2; P2=P2->link) Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;    // 令front指向结果多项式第一个非零项 
	
	free(temp);             // 释放临时空表头结点 
	return front;
}
