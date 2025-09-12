#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, x, y, p, color = 15;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;

    int s1 = (x2 > x1) ? 1 : -1;
    int s2 = (y2 > y1) ? 1 : -1;

    if (dy > dx) {
        int temp = dx;
        dx = dy;
        dy = temp;
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, color);
            while (p >= 0) {
                y = y + s2;
                p = p - 2 * dx;
            }
            x = x + s1;
            p = p + 2 * dy;
        }
    } else {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, color);
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
