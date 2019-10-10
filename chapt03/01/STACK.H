typedef struct stack_node {
	char* elem;
	int top;
	int size;
} Stack;


int Init(Stack* s, int n);
void Destroy(Stack* s);
int Empty(Stack s);
int Full(Stack s);
int Push(Stack* s, char c);
int Pop(Stack* s);
void Print(Stack s);