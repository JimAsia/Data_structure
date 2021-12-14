#ifndef CHAIN_H
#define CHAIN_H
#define KEYLENGTH 15   //

typedef char ElementType[KEYLENGTH+1]; // 
typedef struct LNode {
	ElementType Data;
	struct LNode *Next;
} *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode{   // ɢ�б��㶨�� 
	int TableSize;    // �����󳤶� 
	List Heads;       // ָ������ͷ�������� 
} *HashTable;         


#endif
