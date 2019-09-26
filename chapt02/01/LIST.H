typedef int type;

typedef struct {
	type* elem;
	int size;
	int len;
} List;

int Init(List* list, int size);
void Destroy(List* list);
int Full(List list);
int Insert(List* list, type value, int index);
void Print(List list);