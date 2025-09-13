#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, fx, fy;
    float sx, sy, float x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter fixed point (x,y) for scaling:");
    scanf("%d %d", &fx, &fy);
    printf("Enter scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    x1_new = (x1 - fx) * sx;
    y1_new = (y1 - fy) * sy;
    x2_new = (x2 - fx) * sx;
    y2_new = (y2 - fy) * sy;    
    x3_new = (x3 - fx) * sx;
    y3_new = (y3 - fy) * sy;

    x1_new += fx;
    y1_new += fy;
    x2_new += fx;
    y2_new += fy;
    x3_new += fx;
    y3_new += fy;

    setcolor(YELLOW);
    line((int)x1_new, (int)y1_new, (int)x2_new, (int)y2_new);
    line((int)x2_new, (int)y2_new, (int)x3_new, (int)y3_new);
    line((int)x3_new, (int)y3_new, (int)x1_new, (int)y1_new);

    getch();
    closegraph();
}
