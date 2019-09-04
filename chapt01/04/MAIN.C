#include <stdio.h>
#include <conio.h>
#define MAX_LINE 1024

int main() {
	char c;
	char line[MAX_LINE];
	int count = 1;
	FILE *fp;

	fp = fopen("MAIN.C", "rt");
	if(fp == NULL) {
		printf("Error: open file");
		return 1;
	}

	clrscr();

	while(!feof(fp)) {
		fgets(line, MAX_LINE, fp);
		printf("%d: %s", count++, line);
	}

    fclose(fp);

	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}