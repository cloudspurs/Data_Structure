typedef struct
    {
    int x, y, pre;
} elemtype;

typedef struct
    {
    elemtype* elem;
    int front, rear;
    int size;
} SQQUEUE;

int InitSqqueue(SQQUEUE* q, int n);
void DestroySqqueue(SQQUEUE* q);
int IsSqqueueEmpty(SQQUEUE q);
int IsSqqueueFull(SQQUEUE q);
int EnSqqueue(SQQUEUE* q, elemtype e);
int DeSqqueue(SQQUEUE* q, elemtype* e);
int SqqueueLen(SQQUEUE q);
