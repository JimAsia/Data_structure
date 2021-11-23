#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "SNode.h"

#define MAXOP 100        // ����������ܵ���󳤶� 
#define INFINITY 1e9     // ���������� 
#define ERROR -1
typedef enum {num, opr, end} Type;           	     // �������ζ�Ӧ����������������ַ�����β 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*��������������������*/
/*��ͷ��β��ȡ��׺���ʽ��ÿ�����󣬶Բ�ͬ���󰴲�ͬ�������
1. ��������ֱ�����
2. �����ţ�ѹ���ջ
3. �����ţ���ջ��������������������ֱ�����������ţ���ջ���������
4. ������������ȼ�����ջ�������ʱ�������ѹջ
		   �����ȼ�С�ڵ���ջ�������ʱ����ջ�������������������ٱȽ��µ�ջ���������ֱ�������������ջ����������ȼ�Ϊֹ��
		   Ȼ�󽫸������ѹջ��
5. ������������ϣ���Ѷ�ջ�д����������һ����� */ 


Stack CreatStack ( int MaxSize );
bool IsFull ( Stack S );
bool IsEmpty ( Stack S );
bool Push ( Stack S, ElementType X );
ElementType Pop ( Stack S );
Type GetOp ( char * Expr, int * start, char * str );
ElementType PostfixExp ( char * Expr );


int main( int argc, char *argv[]) {
	char Expr[MAXOP];
	ElementType f;
	
	gets(Expr);
	f = PostfixExp(Expr);
	if ( f < INFINITY )
		printf("%.4f\n", f);
	else
		printf("���ʽ����\n");
		
		
	return 0;
}


Type GetOp ( char * Expr, int * start, char * str ) {
	// ��*start��ʼ������һ�����󣨲�������������������������ַ���str�С� 
	int i = 0;
	
	// ���ʽ����ǰ�ո� 
	while ( ( str[0] = Expr[(*start)++]) == ' ' );
	
	while ( str[i] != ' ' && str[i] != '\0' )
		str[++i] = Expr[(*start)++];
	if ( str[i] == '\0' )           // �����������Ľ�β 
		(*start)--;                 // *start ָ������� 
	str[i] = '\0';                  // ����һ������Ļ�ȡ 
	
	if( i == 0 ) return end;   // �����˽��� 
	// ���str[0]�����֡����Ƿ��Ÿ������� 
	else if ( isdigit(str[0]) || isdigit(str[1]) )
		return num;                    // ��ʾ��ʱstr�д����һ������ 
	else                               // ���str���ǿմ����ֲ������� 
		return opr;                    // ��ʾ��ʱstr�д����һ������� 
}


ElementType PostfixExp ( char * Expr ) {
	// ����GetOp���������׺���ʽ����ֵ
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;
	
	// ����һ���¶�ջ 
	S = CreatStack(MAXOP);
	
	Op1 = Op2 = 0;
	while ( (T = GetOp( Expr, &start, str)) != end ) {
		// ��δ�����������ʱ 
		if ( T == num )
			Push(S, atof(str));
		else {
			if ( !IsEmpty(S) )
				Op2 = Pop(S);
			else
				Op2 = INFINITY;
			if ( !IsEmpty (S) )
				Op1 = Pop(S);
			else
				Op2 = INFINITY;
			switch ( str[0] ) {
				case '+' :
					Push( S, Op1 + Op2 );
					break;
				case '*' :
					Push( S, Op1 * Op2 );
					break;
				case '-':
					Push( S, Op1 - Op2 );
					break;
				case '/':
					if ( Op2 != 0.0 )          // �������ķ�ĸ�Ƿ�Ϊ0 
						Push( S, Op1 / Op2);
					else {
						printf("���󣺳�����ĸΪ��\n");
						Op2 = INFINITY;
					}
					break;
				default:
					printf("����δ֪�����%s\n", str);
					Op2 = INFINITY;
					break;
			}
			if ( Op2 >= INFINITY ) break;
		}
	}
	if ( Op2 < INFINITY )                  // ����������˱��ʽ 
		if ( !IsEmpty(S) )					// ��ʱ��ջ���� 
			Op2 = Pop(S);					// ��¼������ 
		else Op2 = INFINITY;				// �����Ǵ��� 
	free(S);								// �ͷŶ�ջ 
	return Op2; 
}


Stack CreatStack ( int MaxSize ) {
	Stack S = (Stack)malloc(sizeof(PtrToSNode));
	S->Data = (ElementType *)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull ( Stack S ) {
	return( S->Top == S->MaxSize-1 );
}


bool Push ( Stack S, ElementType X ) {
	if (IsFull(S)) {
		printf("��ջ��\n");
		return false;
	}
	else {
		S->Data[++(S->Top)] == X;
		return true;
	}
}


bool IsEmpty ( Stack S ) {
	return(S->Top == -1);
}


ElementType Pop ( Stack S ) {
	if ( IsEmpty(S) ) {
		printf("��ջ��");
		return ERROR;
	}
	else {
		return(S->Data[(S->Top)--]);
	}
}
