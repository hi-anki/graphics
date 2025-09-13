#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    int x, y, d;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius r: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    d = 3 - 2 * r;

    while (x <= y) {
        putpixel(xc + x, yc + y, 15);
        putpixel(xc - x, yc + y, 15);
        putpixel(xc + x, yc - y, 15);
        putpixel(xc - x, yc - y, 15);
        putpixel(xc + y, yc + x, 15);
        putpixel(xc - y, yc + x, 15);
        putpixel(xc + y, yc - x, 15);
        putpixel(xc - y, yc - x, 15);

        x++;
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            y = y - 1;
            d = d + 4 * (x - y) + 10;
        }
    }

    getch();
    closegraph();
}
