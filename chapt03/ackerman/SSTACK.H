typedef struct {
    int n, x, y;
} elemtype;

typedef struct stack_tag {
    elemtype* elem;
    int top;
    int size;
} SQSTACK;

int InitSqstack(SQSTACK* S, int n);
void DestroySqstack(SQSTACK* S);
int IsSqstackEmpty(SQSTACK S);
int IsSqstackFull(SQSTACK S);
int Push(SQSTACK* S, elemtype e);
int Pop(SQSTACK* S, elemtype* e);
