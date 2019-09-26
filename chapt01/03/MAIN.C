#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <alloc.h>

int main() {
	int N;
	int i; char c;
	char tmpstr[100];
	char **pstr;

	printf("Input the N number:\n");
	scanf("%d", &N);

	pstr = (char**)malloc(N*sizeof(char*));

	if(pstr == NULL)
		printf("Malloc fail");

//   	fflush(stdin);
	for(i = 0; i < N; i++) {
		printf("Input %d string: ", i);
//		gets(tmpstr);
		scanf("%s", tmpstr);
		pstr[i] = (char*)malloc((strlen(tmpstr)+1) * sizeof(char));
		strcpy(pstr[i], tmpstr);
	}

	clrscr();

	for(i= 0; i < N; i++) {
		textcolor(i+1);
		printf("%s", pstr[i]);
		cprintf("%s", pstr[i]);
		printf("\n");
		free(pstr[i]);
	}
	free(pstr);

	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}