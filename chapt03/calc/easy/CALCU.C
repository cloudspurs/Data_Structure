#include <stdio.h>
#include <conio.h>
#include <bios.h>
#include <dos.h>
#include <string.h>
#include "calcu.h"

void main()
{
    float f;
    char str[80] = { 0 };
    int key, len, i;
    char keystr[] = "1234567890.^()+-*/=\x08";

    _setcursortype(_NOCURSOR);
    clrscr();
    gotoxy(1, 2);
    printf("旼컴컴컴컴컴컴컴컴컴컴컴컴?n");
    printf("?                        ?n");
    printf("쳐컴컴컴컴컴컴컴컴컴컴컴컴?n");
    printf("? 1   2   3     +   -    ?n");
    printf("?                        ?n");
    printf("? 4   5   6     *   /    ?n");
    printf("?                        ?n");
    printf("? 7   8   9     =   \x1b    ?n");
    printf("?                        ?n");
    printf("? 0   .         ^   End  ?n");
    printf("읕컴컴컴컴컴컴컴컴컴컴컴컴?n");

    while (1) {
        if (kbhit()) {
            key = bioskey(0);
            if (key == END)
                break;
            if (strlen(str) == 0) {
                gotoxy(2, 3);
                printf("                         ");
            }
            key &= 0x00ff;
            len = strlen(keystr);
            for (i = 0; i < len; i++)
                if (key == keystr[i])
                    break;
            if (i == len) { /*illegal input*/
                printf("\07");
                continue;
            }
            if (key != '=') {
                len = strlen(str);
                if (key == 8) {	// backspace
                    if (len > 0) {
                        gotoxy(2 + len - 1, 3);
                        printf(" ");
                        str[len - 1] = 0;
                    }
                }
                else {
                    str[len] = key;
                    str[len + 1] = 0;
                }
                gotoxy(2, 3);
                printf("%s", str);
            }
            else { //begin calculate the value of the expression
                if (str[0] != 0) {
                    len = strlen(str);
                    str[len] = '=';
                    str[len + 1] = 0;
                    if (Evaluate(str, &f)) {
                        gotoxy(2, 3);
                        printf("%s%.2f", str, f);
                    }
                }
                str[0] = 0;
            }
        } //if kbhit
    } //while
    _setcursortype(_NORMALCURSOR);
    gotoxy(1, 13);
}