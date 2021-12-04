#ifndef _HASH_H
#define _HASH_H

typedef int ElementType;    // 关键词类型用整型 
typedef int Index;          // 散列地址类型 
typedef Index Position;     // 数据所在位置与散列地址是同意类型 
typedef enum {
	Legitimate,            // 合法元素 
	Empty,                // 空单元 
	Deleted,               // 已删除元素 
} EntryType;            

typedef struct HashEntry{     
	ElementType Data;       // 存放元素  
	EntryType Info;         // 单元状态 
} Cell; // 散列表单元类型 

typedef struct TblNode {     // 散列表类型 
	int TableSize;          // 散列表结点定义 
	Cell *Cells;           // 表的最大长度 
} *HashTable;            // 存放散列单元数据的数组 


#endif
