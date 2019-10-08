#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include "SSTACK.h"
#include "ACKERMAN.h"

int AkmValue(int n, int x)
{
    if (n == 0)
        return x + 1;
    else {
        switch (n) {
        case 1:
            return x;
        case 2:
            return 0;
        case 3:
            return 1;
        default:
            return 2;
        }
    }
}

int Ackerman(int n, int x, int y)
{
    SQSTACK s;
    elemtype e;
    int val;

    if (!InitSqstack(&s, MAXSIZE)) {
        printf("can't create the stack\n");
        return -2;
    } //if

    e.n = n;
    e.x = x;
    e.y = y;
    Push(&s, e);

    while (1) {
        e = s.elem[s.top];
        n = e.n;
        x = e.x;
        y = e.y;
        while (n > 0 && y > 0) {
            y--;
            e.n = n;
            e.x = x;
            e.y = y;
            Push(&s, e);
        } //while

        val = AkmValue(n, x);
        
        Pop(&s, &e);
        if (IsSqstackEmpty(s)) {
            DestroySqstack(&s);
            return val;
        } else {
            Pop(&s, &e);
            e.n--;
            e.y = e.x;
            e.x = val;
            Push(&s, e);
        }
    } //while(1)
}

void main()
{
    int sum;
    int n, x, y;
    clrscr();
    printf("please input n,x,y of A(n,x,y):\n");
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%d", &x);
    printf("y=");
    scanf("%d", &y);
    sum = Ackerman(n, x, y);
    printf("A(%d,%d,%d)=%d", n, x, y, sum);
    getch();
}