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

typedef struct TblNode{   // 散列表结点定义 
	int TableSize;    // 表的最大长度 
	List Heads;       // 指向链表头结点的数组 
} *HashTable;         


#endif
