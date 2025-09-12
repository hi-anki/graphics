#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, x, y, p;
    int s1, s2;
    int i = 0, temp;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    if (x2 > x1) {
        s1 = 1;
    }
    else {
        s1 = -1;
    }

    if (y2 > y1) {
        s2 = 1;
    }
    else {
        s2 = -1;
    }

    if (dy > dx) {
        temp = dx;
        dx = dy;
        dy = temp;
        p = 2 * dy - dx;
        for (i = 0; i <= dx; i++) {
            putpixel(x, y, 15);
            while (p >= 0) {
                y = y + s2;
                p = p - 2 * dx;
            }
            x = x + s1;
            p = p + 2 * dy;
        }
    }
    else {
        p = 2 * dy - dx;
        for (i = 0; i <= dx; i++) {
            putpixel(x, y, 15);
            while (p >= 0) {
                x = x + s1;
                p = p - 2 * dx;
            }
            y = y + s2;
            p = p + 2 * dy;
        }
    }

    getch();
    closegraph();
}
