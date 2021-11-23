#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct _list {
	Node* head;
} List;

void add( List* pList, int number );
void print( List *pList );
void found( List *pList, int number );
void del( List *pList, int number );
void clear( List *pList );

int main(int argc, char *argv[]) {
	List list;
	int number;
	printf("enter -1 to quit.\n");
	list.head = NULL;
	do {
		scanf("%d", &number);
		if ( number != -1 ) {
			add(&list, number);
		}
	} while ( number != -1);
	
	print(&list);
	scanf("%d", &number);
	

	found(&list, number);
	clear(&list);
	
}

void add( List* pList, int number ) {

	// add to linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	// find the last
	Node *last = pList->head;
	if ( last ) {
		while ( last->next ) {
			last = last->next;
		}
		last->next = p;
	}else { 
		pList->head = p;
	}
}

void print( List *pList ) {
	Node *p;
	for ( p=pList->head; p; p=p->next) {
		printf("%d\t", p->value);
	}
	printf("\n");
}

void found( List *pList, int number ) {
	Node *p;
	int isFound = 0;
	for ( p = pList->head; p; p->next ) {
		if ( p->value == number ) {
			printf("Find!\n");
			isFound = 1;
			break;
		}
	}
	if ( !isFound ) {
		printf("Not find.\n");
	}
}

void del( List *pList, int number ) {
	Node *q, *p;
	for ( q=NULL, p=pList->head; p; q=p, p=p->next) {
		if (p->value == number) {
			q->next = p->next;
			if ( q ) {
				q->next = p->next;
			} else {
				pList->head = p->next;
			}
			free(p);
			break;
		}
	}
}

void clear( List *pList ) {
	Node *p, *q;
	for ( p=pList->head; p; p=q ) {
		q = p->next;
		free(p);
		p = q;
	}
}
