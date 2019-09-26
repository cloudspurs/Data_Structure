#include<alloc.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
 int i,j,len,num,N;
 char tmpstr[20];
 char **pstr;

 clrscr();
 printf("Number of strings input:");
 scanf("%d",&N);
 pstr=(char **)malloc(N*sizeof(char *));

  //	fflush(stdin);
 for(i=0;i<N;i++)
 {
   scanf("%s", tmpstr);
//   gets(tmpstr);
  len=strlen(tmpstr);
   pstr[i]=(char *)malloc(len*sizeof(char));
   strcpy(pstr[i],tmpstr);
 }
 num=random(15)+1;
 for(i=0;i<N;i++)
 {
  textcolor(i+1);
  printf("%s", pstr[i]);
  cprintf("%s",pstr[i]);
   printf("\n");
  num++;
 }



}