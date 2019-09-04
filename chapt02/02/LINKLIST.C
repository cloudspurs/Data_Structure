#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

int Init(LinkList *list) {
	*list = (LinkList)malloc(sizeof(Node));
	if(*list == NULL)
		return 0;
	(*list)->next = NULL;
	return 1;
}

void Destroy(LinkList *list) {
	NodePtr p, q;
	p = *list;

	while(p) {
	 q = p;
	 p = p->next;
	 free(q);
	}

	*list = NULL;
}

int Append(LinkList list, type value) {
	NodePtr p;
	p = (NodePtr)malloc(sizeof(Node));
	if(p == NULL)
		return 0;

	p->data = value;
	p->next = list->next;
	list->next = p;

	return 1;
}

void DeleteOdd(LinkList list) {
	NodePtr p, pre;
	pre = list;
	p = list->next;

	while(p != NULL) {
		if(p->data%2 == 1) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
}

void Print(LinkList list) {
	NodePtr p;
	p = list->next;

	while(p) {
		printf("\n%d", p->data);
		p = p->next;
	}
	printf("\n");
}