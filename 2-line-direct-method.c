#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float m, c, x, y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    m = (float)(y2 - y1) / (x2 - x1);
    c = y1 - m * x1;

    printf("Displaying line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
    for (x = x1; x <= x2; x++) {
        y = m * x + c;
        putpixel(x, (int)(y + 0.5), 15);
    }

    getch();
    closegraph();
}
