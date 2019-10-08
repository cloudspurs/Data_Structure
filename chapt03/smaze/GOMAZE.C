#include <conio.h>
#include <bios.h>
#include <graphics.h>
#include <dos.h>
#include "funkey.h"
#include "squeue.h"

int movex[5] = { 0, 0, 1, 0, -1 }, movey[5] = { 0, -1, 0, 1, 0 };
void go1(int maze[M][N], int x, int y, int xx, int yy)
{
    elemtype e;
    SQQUEUE q;
    int x1, y1, i, k;

    if (!InitSqqueue(&q, M * N))
        return;

    e.x = x;
    e.y = y;
    e.pre = -1;
    EnSqqueue(&q, e);
    maze[y][x] = 2;
    
    while (!IsSqqueueEmpty(q)) {
		DeSqqueue(&q, &e);
        x1 = e.x;
        y1 = e.y;

        e.pre = (q.front - 1) % q.size;
        for (i = 1; i <= 4; i++) {
            e.x = x1 + movex[i];
            e.y = y1 + movey[i];
            if (maze[e.y][e.x] == 0) {
                EnSqqueue(&q, e);
                maze[e.y][e.x] = 2;
                if (e.x == xx && e.y == yy) {
                    k = (q.rear - 1) % q.size;
                    while (k != -1) {
                        e = q.elem[k];
                        drawbackgroundblock(H + e.x * 12, L + e.y * 12);
                        k = q.elem[k].pre;
                    }
                    DestroySqqueue(&q);
                    return;
                }
            }
        }
    }
}
