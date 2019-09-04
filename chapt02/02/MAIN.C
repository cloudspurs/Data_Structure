#include <stdio.h>
#include "linklist.h"


int main() {
	char c;
	int i, temp;

	LinkList list;
	Init(&list);

	for(i = 0; i < 5; i++) {
		scanf("%d", &temp);
		Append(list, temp);
	}
	Print(list);
	DeleteOdd(list);
	Print(list);

	Destroy(&list);

	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}