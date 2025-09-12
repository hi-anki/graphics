#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, color = 15;
    float x_step, y_step;
    int i, steps;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    x_step = (float)dx / steps;
    y_step = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (i = 0; i < steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += x_step;
        y += y_step;
    }

    getch();
    closegraph();
}
