#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int* twoSum(int *nums, int numSize, int target, int* returnSize);
struct hashTable* find(int ikey);
void insert(int ikey, int ival);

struct hashTable {
	int key;
	int val;
	UT_hash_handle hh;          // makes this structure hashable ʹ����ṹ��Ϊ�ɹ�ϣ�� 
};

struct hashTable* hashtable;

int main(int argc, char *argv[]) {
	int a[4] = {1, 2, 3, 4};
	int sum = 4;
	int aSize = sizeof(a) / sizeof(int);
	int* returnSize = 0;
	int* ret;
	int i;
	ret = twoSum(a, aSize, sum, returnSize);
	for (i = 0; i < sizeof(ret) / sizeof(int); i++) {
		printf("%d", ret[i]);
	}
	
	return 0;
}


struct hashTable* find(int ikey) {          // ����ṹ�庯�����ҵ� 
	struct hashTable* tmp;
	HASH_FIND_INT(hashtable, &ikey, tmp);     // ���ҽ�����ظ�tmp 
	return tmp;
}

void insert(int ikey, int ival) {
	struct hashTable* it = find(ikey);
	if (it == NULL) {
		struct hashTable* tmp = malloc(sizeof(struct hashTable));
		tmp->key = ikey;
		tmp->val = ival;
		HASH_ADD_INT(hashtable, key, tmp);            // ��ӵļ�ֵΪ���� 
	} else {
		it->val = ival;
	}
}


int* twoSum(int *nums, int numSize, int target, int* returnSize) {
	hashtable = NULL;
	int i;
	for (i = 0; i < numSize; i++) {
		struct hashTable* it = find(target - nums[i]);
		if (it != NULL) {
			int* ret = malloc(sizeof(int) * 2);
			ret[0] = it->val, ret[1] = i;
			*returnSize = 2;
			return ret;
		}
		insert(nums[i], i);
	}
	*returnSize = 0;
	return NULL;
}
