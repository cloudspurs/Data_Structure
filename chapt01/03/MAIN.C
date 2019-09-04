#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <alloc.h>

int main() {
	int N;
	int i; char c;
	char tmpstr[100];
	char **pstr;

	scanf("%d", &N);

	pstr = (char**)malloc(N *sizeof(char*));

	if(pstr == NULL)
		printf("Malloc fail");

	for(i = 0; i < N; i++) {
		//gets(tmpstr);
		printf("Input %d string: ", i);
		scanf("%s", tmpstr);
		pstr[i] = (char*)malloc(strlen(tmpstr) * sizeof(char));
		strcpy(pstr[i], tmpstr);
	}

	clrscr();

	for(i= 0; i < N; i++) {
		textcolor(i+1);
		cprintf("%s", pstr[i]);
		free(pstr[i]);
	}
	free(pstr);

	while(1) {
		if((c = getchar()) == 'q')
        	return 0;
	}
}