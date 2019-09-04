#include <stdio.h>

int a[10] = {0};
void getdata(void);

int main() {
	char c;
	int k;
	getdata();
	for(k = 0; k < 5; k++) {
		printf("%d\n", a[k]+1);
	}
	while(1) {
		if((c = getchar()) == 'q')
			return 0;
	}
}