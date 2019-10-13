#include <alloc.h>
#include "sstack.h"

int InitSqstack(SQSTACK* S, int n)
{
	S->elem = (elemtype*)malloc(n * sizeof(elemtype));
	if (S->elem == NULL)
		return 0;
	S->size = n;
	S->top = -1;
	return 1;
}

void DestroySqstack(SQSTACK* S)
{
	free(S->elem);
	S->elem = NULL;
	S->top = -1;
	S->size = 0;
}

int IsSqstackEmpty(SQSTACK S)
{
	return S.top == -1;
}

int IsSqstackFull(SQSTACK S)
{
	return S.top == S.size - 1;
}

int Push(SQSTACK* S, elemtype e)
{
	if (IsSqstackFull(*S))
		return 0;
	S->top++;
	S->elem[S->top] = e;
	return 1;
}

int Pop(SQSTACK* S, elemtype* e)
{
	if (IsSqstackEmpty(*S))
		return 0;
	*e = S->elem[S->top];
	S->top--;
	return 1;
}
