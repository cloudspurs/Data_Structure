#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "funkey.h"

extern int maze[M][N];

void drawboy(int x, int y)
{
    drawbackgroundblock2(x, y);
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(RED);
    fillellipse(x + 6, y + 6, 5, 5);
    line(x + 2, y + 2, x + 5, y + 4);
    line(x + 12 - 2, y + 2, x + 12 - 5, y + 4);
    line(x + 3, y + 12 - 2, x + 6, y + 12 - 5);
    line(x + 6, y + 12 - 5, x + 12 - 3, y + 12 - 2);
}

void drawbackgroundblock2(int x, int y)
{
    setfillstyle(HATCH_FILL, LIGHTGRAY);
    bar(x, y, x + 11, y + 11);
}

void drawbackgroundblock(int x, int y)
{
    setfillstyle(XHATCH_FILL, DARKGRAY);
    bar(x, y, x + 11, y + 11);
}

void drawmaze(int x, int y)
{
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++) {
            if (maze[i][j] == 0)
                drawbackgroundblock2(x + j * 12, y + i * 12);
            else
                drawwall(x + j * 12, y + i * 12);
        }
}

void drawwall(int x, int y)
{
    setfillstyle(SOLID_FILL, RED);
    bar(x, y, x + 11, y + 11);
    setcolor(WHITE);
    line(x, y, x + 11, y);
    line(x, y + 4, x + 11, y + 4);
    line(x, y + 8, x + 11, y + 8);
    line(x, y, x, y + 4);
    line(x + 4, y + 4, x + 4, y + 4);
    line(x + 8, y + 8, x + 8, y + 11);
}

void drawpos(int x, int y)
{
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x + 6, y + 6, 5, 5);
}

