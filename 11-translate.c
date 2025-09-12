#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int tx, ty;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    printf("Enter x3, y3: ");
    scanf("%d %d", &x3, &y3);

    printf("Enter translation factors (tx, ty): ");
    scanf("%d %d", &tx, &ty);

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Translate and draw new triangle
    setcolor(YELLOW);
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    line(x2 + tx, y2 + ty, x3 + tx, y3 + ty);
    line(x3 + tx, y3 + ty, x1 + tx, y1 + ty);

    getch();
    closegraph();
}
