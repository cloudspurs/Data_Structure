#include <stdio.h>
#include <conio.h>
#include "stack.h"

int main() {
	int i;
	char temp[100];
	Stack s;
	Init(&s, 100);

	clrscr();
	printf("Input the expresention string: ");
	gets(temp);

	for(i = 0; i < strlen(temp); i++) {
		if(temp[i] == '(')
			Push(&s, temp[i]);
		if(temp[i] == ')') {
			if(Empty(s)) {
				printf("Error: unexpected )");
				return 1;
			}
			else
				Pop(&s);
		}
	}

	if(!Empty(s))
		printf("\nError: unexpected (");
	else
		printf("\nCorrect Expression");

	//Print(s);

	return 0;
}