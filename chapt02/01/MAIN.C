#include <stdio.h>
#include "list.h"

int main() {
	char c;
	int i, temp;
	List list;

	if(!Init(&list, 5)) {
		printf("Cant' create List");
	}

	for(i = 0; i < 5; i++) {
		printf("Input %d number: ", i);
		scanf("%d", &temp);
		Insert(&list, temp, 0);
	}

	Print(list);
	Destroy(&list);

	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}
