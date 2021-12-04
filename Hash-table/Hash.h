#ifndef _HASH_H
#define _HASH_H

typedef int ElementType;    // �ؼ������������� 
typedef int Index;          // ɢ�е�ַ���� 
typedef Index Position;     // ��������λ����ɢ�е�ַ��ͬ������ 
typedef enum {
	Legitimate,            // �Ϸ�Ԫ�� 
	Empty,                // �յ�Ԫ 
	Deleted,               // ��ɾ��Ԫ�� 
} EntryType;            

typedef struct HashEntry{     
	ElementType Data;       // ���Ԫ��  
	EntryType Info;         // ��Ԫ״̬ 
} Cell; // ɢ�б�Ԫ���� 

typedef struct TblNode {     // ɢ�б����� 
	int TableSize;          // ɢ�б��㶨�� 
	Cell *Cells;           // �����󳤶� 
} *HashTable;            // ���ɢ�е�Ԫ���ݵ����� 


#endif
