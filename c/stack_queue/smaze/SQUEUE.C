#include <stdio.h>
#include <alloc.h>
#include "squeue.h"

int InitSqqueue(SQQUEUE* q, int n)
{
    q->elem = (elemtype*)malloc((n + 1) * sizeof(elemtype));
    if (q->elem == NULL)
        return 0;
    q->front = q->rear = 0;
    q->size = n + 1;
    return 1;
}

void DestroySqqueue(SQQUEUE* q)
{
    free(q->elem);
    q->elem = NULL;
    q->front = q->rear = 0;
    q->size = 0;
}

int IsSqqueueEmpty(SQQUEUE q)
{
    return q.front == q.rear;
}

int IsSqqueueFull(SQQUEUE q)
{
    return q.front == (q.rear + 1) % q.size;
}

int EnSqqueue(SQQUEUE* q, elemtype e)
{
    if (IsSqqueueFull(*q))
        return 0;
    q->elem[q->rear] = e;
    q->rear = (q->rear + 1) % q->size;
    return 1;
}

int DeSqqueue(SQQUEUE* q, elemtype* e)
{
    if (IsSqqueueEmpty(*q))
        return 0;
    *e = q->elem[q->front];
    q->front = (q->front + 1) % q->size;
    return 1;
}

int SqqueueLen(SQQUEUE q)
{
    return (q.size + q.rear - q.front) % q.size;
}
