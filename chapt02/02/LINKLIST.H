typedef int type;

typedef struct node {
	type data;
	struct node *next;
} Node, *NodePtr, *LinkList;

int Init(LinkList *list);
void Destroy(LinkList *list);
int Append(LinkList list, type value);
void DeleteOdd(LinkList list);
void Print(LinkList list);