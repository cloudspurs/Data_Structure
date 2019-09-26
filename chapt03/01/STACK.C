#include <stdio.h>
#include <malloc.h>
#include "stack.h"

int Init(Stack* s, int n) {
	s->elem = (char*)malloc(n * sizeof(char));
	if(s->elem == NULL)
		return 0;
	s->size = n;
	s->top = -1;
	return 1;
}

void Destroy(Stack* s) {
	free(s->elem);
	s->elem == NULL;
	s->top = -1;
	s->size = 0;
}

int Empty(Stack s) {
	return s.top == -1;
}

int Full(Stack s) {
	return s.top == s.size-1;
}

int Push(Stack* s, char c) {
	if(Full(*s))
		return 0;
	s->top++;
	s->elem[s->top] = c;
	return 1;
}

int Pop(Stack* s) {
	if(Empty(*s))
		return 0;
	s->top--;
	return 1;
}

void Print(Stack s) {
	int i;
	for(i = 0; i <= s.top; i++)
		printf("%c", s.elem[i]);
}