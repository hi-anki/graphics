#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    int x, y, p;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius r: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    p = 1 - r;

    while (x < y) {
        putpixel(xc + x, yc + y, 15);
        putpixel(xc - x, yc + y, 15);
        putpixel(xc + x, yc - y, 15);
        putpixel(xc - x, yc - y, 15);
        putpixel(xc + y, yc + x, 15);
        putpixel(xc - y, yc + x, 15);
        putpixel(xc + y, yc - x, 15);
        putpixel(xc - y, yc - x, 15);

        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }
    }

    getch();
    closegraph();
}
