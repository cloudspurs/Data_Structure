#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	char input[100];
	char number[100];
	char c;
	int i,j;
	int output;

	gets(input);

	clrscr();
	textcolor(YELLOW);
	gotoxy(0, 0);
	cprintf("%s", input);

	for(i = 0, j = 0; i < strlen(input); i++) {
		if(input[i] >= '0' && input[i] <= '9') {
			number[j] = input[i];
			j++;
		}
		number[j] = 0;
	}

	sscanf(number, "%d", &output);

//	printf("\n%d\n", output);
	textcolor(BLUE);
	gotoxy(35, 12);
	cprintf("%x", output);

	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}