#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include "sstack.h"

#define MAXNUM 10
int hole[3][MAXNUM];
int plate_height[3] = { 0 };

void drawplate(int x, int y, int wide)
{
    setfillstyle(SOLID_FILL, wide / 20);
    bar(x - wide / 2, y, x + wide / 2, y + 16 - 1);
}

void eraseplate(int x, int y, int wide)
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(x - wide / 2, y, x + wide / 2, y + 16 - 1);
}

void move(int x, int y)
{
    int px, py, wide;

    if (getch() == 27) {
        closegraph();
        exit(1);
    }
    wide = hole[x - 1][plate_height[x - 1] - 1] * 20;
    px = 100 + 200 * (x - 1);
    py = 480 - plate_height[x - 1] * 16;
    eraseplate(px, py, wide);
    setfillstyle(SOLID_FILL, x - 1 + 11);
    bar(100 + 200 * (x - 1) - 5, py, 100 + 200 * (x - 1) + 5, py + 16 - 1);

    hole[y - 1][plate_height[y - 1]] = hole[x - 1][plate_height[x - 1] - 1];
    plate_height[x - 1]--;
    plate_height[y - 1]++;

    px = 100 + 200 * (y - 1);
    py = 480 - plate_height[y - 1] * 16;
    drawplate(px, py, wide);

    delay(400);
}

void hanoi(int n, int A, int B, int C)
{
    SQSTACK s;
    elemtype e;
    int t;

    InitSqstack(&s, 200);

    e.n = n;
    e.x = A;
    e.y = B;
    e.z = C;
    Push(&s, e);

    while (1) {
        e = s.elem[s.top];
        while (e.n > 1) {
            e.n--;
            t = e.y;
            e.y = e.z;
            e.z = t;
            Push(&s, e);
        }

        Pop(&s, &e);
        move(e.x, e.z);

        if (IsSqstackEmpty(s)) {
            DestroySqstack(&s);
            return;
        }

        Pop(&s, &e);
        move(e.x, e.z);

        e.n--;
        t = e.x;
        e.x = e.y;
        e.y = t;
        Push(&s, e);
    }
}

void main()
{
    int m, i;

    int gdriver = DETECT, gmode;

    printf("input the number of diskes:");
    scanf("%d", &m);

    if (m > 10) {
        printf("Too many plates!\nYou would kill me?\n");
        return;
    }

    for (i = m; i >= 1; i--)
        hole[0][m - i] = i;
    plate_height[0] = m;
    plate_height[1] = plate_height[2] = 0;

    printf("press any key to see the moving steps.");
    getch();

    registerbgidriver(EGAVGA_driver);
    initgraph(&gdriver, &gmode, "");

    for (i = 0; i < 3; i++) {
        setfillstyle(SOLID_FILL, 11 + i);
        bar(100 + 200 * i - 5, 480 - 16 * 12, 100 + 200 * i + 5, 480);
    }

    for (i = 0; i < plate_height[0]; i++) {
        int wide;
        wide = hole[0][i] * 20;
        drawplate(100, 480 - (i + 1) * 16, wide);
    }

    hanoi(m, 1, 2, 3);

    getch();
    closegraph();
}
