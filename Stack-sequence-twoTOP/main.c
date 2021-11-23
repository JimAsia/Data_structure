#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SNode.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 两个栈分别从数组两头开始向中间生长；当两个栈的栈顶指针相遇时，表示两个栈都满了 */

Stack CreateStack ( int MaxSize );     // 生成空堆栈，其最大长度为MaxSize 
bool IsFull ( Stack S );         // 判断堆栈S是否已满。若S中元素个数等于MaxSize时返回true；否则反回false；
bool Push ( Stack S, ElementType X, int Tag );  // 入栈，Tag作为区分两个堆栈的标志，取值为1和2 
bool IsEmpty ( Stack S );     // 判断堆栈S是否为空，若是返回true；否则返回false 
ElementType pop ( Stack S, int Tag );    // 出栈， Tag作为区分两个堆栈的标志，取值为1和2 


int main(int argc, char *argv[]) {
	return 0;
}
