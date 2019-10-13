#include <stdio.h>
#include <alloc.h>
#include "LIST.H"

int Init(List* list, int size) {
	list->elem = (type*)malloc(size * sizeof(type));
	if(list->elem == NULL)
		return 0;
	list->size = size;
	list->tail = 0;
	return 1;
}

void Destroy(List* list) {
	free(list->elem);
	list->elem = NULL;
	list->size = 0;
	list->tail = 0;
}

int Full(List list) {
	return list.tail == list.size;
}

int Insert(List* list, type value, int index) {
	int i;
	if(index > list->tail || Full(*list))
		return 0;

	for(i = list->tail-1; i >= index; i--)
		list->elem[i+1] = list->elem[i];

	list->elem[index] = value;
	list->tail++;
	return 0;
}

//void Print(List list) {
//	int i;
//	for(i = 0; i < list.tail; i++)
//	for(i = list.tail-1; i >= 0; i--)
//		printf("%d ", list.elem[i]);
//}

