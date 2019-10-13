#include <conio.h>
#include <bios.h>
#include <graphics.h>
#include <dos.h>
#include "funkey.h"
#include "sstack.h"

int movex[5] = { 0, 0, 1, 0, -1 }, movey[5] = { 0, -1, 0, 1, 0 };

void go(int maze[M][N], int x0, int y0, int xx, int yy)
{
    int x, y, x1, y1, v;

    SQSTACK s;
    elemtype e;

    InitSqstack(&s, MAXSIZE);

    drawpos(H + xx * 12, L + yy * 12);
    drawboy(H + x0 * 12, L + y0 * 12);

    getch();

    e.x = x0;
    e.y = y0;
    e.v = 0;
    Push(&s, e);
    maze[y0][x0] = 2;

    while (!IsSqstackEmpty(s)) {
        Pop(&s, &e);
        x = e.x;
        y = e.y;
        v = e.v + 1;
        if (e.v > 0) {
            maze[y + movey[e.v]][x + movex[e.v]] = 0;
            if (kbhit()) {
                int key;
                key = getch();
                if (key == ESC)
                    return;
                else
                    getch();
            }
            // clear gone sign
            drawbackgroundblock2(H + (x + movex[e.v]) * 12, L + (y + movey[e.v]) * 12);
            delay(50);
        }

        while (v <= 4) {
            x1 = x + movex[v];
            y1 = y + movey[v];
            
            if (x1 == xx && y1 == yy) {
                outtextxy(1, 10, "want another way?(y/n)");
                while (!kbhit()) {
                    int temp;
                    temp = getch();
                    if (temp == 'y') {
                        v++;
                        break;
                    } else
                        return;
                }
            } else if (x1 > 0 && x1 < N - 1 && y1 > 0 && y1 < M - 1 && !maze[y1][x1]) {
                drawbackgroundblock(H + x1 * 12, L + y1 * 12);
                delay(50);
                e.x = x;
                e.y = y;
                e.v = v;
                Push(&s, e);
                if (kbhit()) {
                    int key;
                    key = getch();
                    if (key == ESC)
                        return;
                    else
                        getch();
                }
                x = x1;
                y = y1;
                v = 1;
                maze[y][x] = 2;
            } else
                v++;
        }
    }
}