#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SNode.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* ����ջ�ֱ��������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ������ */

Stack CreateStack ( int MaxSize );     // ���ɿն�ջ������󳤶�ΪMaxSize 
bool IsFull ( Stack S );         // �ж϶�ջS�Ƿ���������S��Ԫ�ظ�������MaxSizeʱ����true�����򷴻�false��
bool Push ( Stack S, ElementType X, int Tag );  // ��ջ��Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 
bool IsEmpty ( Stack S );     // �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false 
ElementType pop ( Stack S, int Tag );    // ��ջ�� Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 


int main(int argc, char *argv[]) {
	return 0;
}
