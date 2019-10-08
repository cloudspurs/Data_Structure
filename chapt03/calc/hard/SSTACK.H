#define ERROR 0
#define OPERAND 1
#define OPERATOR 2

typedef struct {
    int type;
    union {
        float X;
        char op;
    }
    word;
} WORD;

typedef WORD elemtype;

typedef struct stack_tag {
    elemtype * elem;
    int top;
    int size;
} SQSTACK;

int InitSqstack(SQSTACK * S, int n);
void DestroySqstack(SQSTACK * S);
int IsSqstackEmpty(SQSTACK S);
int IsSqstackFull(SQSTACK S);
int Push(SQSTACK * S, elemtype e);
int Pop(SQSTACK * S, elemtype * e);
WORD GetWord(char * str, int * k);
