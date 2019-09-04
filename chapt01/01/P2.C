#include <stdio.h>
extern int a[10];
void getdata() {
	int k;
	for(k = 0; k < 5; k++)
		scanf("%d", &a[k]);
}