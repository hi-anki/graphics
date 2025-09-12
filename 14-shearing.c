#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    float shx, shy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter triangle coordinates (x1,y1), (x2,y2), (x3,y3):\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("Enter shearing factors (shx, shy): ");
    scanf("%f %f", &shx, &shy);

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Shear and draw new triangle
    setcolor(YELLOW);
    line(x1 + shx * y1, y1 + shy * x1, x2 + shx * y2, y2 + shy * x2);
    line(x2 + shx * y2, y2 + shy * x2, x3 + shx * y3, y3 + shy * x3);
    line(x3 + shx * y3, y3 + shy * x3, x1 + shx * y1, y1 + shy * x1);

    getch();
    closegraph();
}
