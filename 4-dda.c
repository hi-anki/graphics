#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float dx, dy, steps, x_inc, y_inc;
    float x, y;
    int k;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x1;
    y = y1;

    putpixel(x, y, 15);

    for (k = 1; k <= steps; k++) {
        x = x + x_inc;
        y = y + y_inc;
        putpixel(x, y, 15);
    }

    getch();
    closegraph();
}
