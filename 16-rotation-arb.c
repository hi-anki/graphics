#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, pivot_x, pivot_y;
    float theta, r_theta, sin, cos;
    float x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter pivot point (x,y) for rotation:");
    scanf("%d %d", &pivot_x, &pivot_y);
    printf("Enter rotation angle (in degrees, positive): ");
    scanf("%f", &theta);

    r_theta = theta * M_PI / 180.0;
    sin = sin(r_theta);
    cos = cos(r_theta);

    printf("Original triangle in white\n");
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    x1_new = (x1 - pivot_x) * cos - (y1 - pivot_y) * sin;
    y1_new = (x1 - pivot_x) * sin + (y1 - pivot_y) * cos;
    x2_new = (x2 - pivot_x) * cos - (y2 - pivot_y) * sin;
    y2_new = (x2 - pivot_x) * sin + (y2 - pivot_y) * cos;
    x3_new = (x3 - pivot_x) * cos - (y3 - pivot_y) * sin;
    y3_new = (x3 - pivot_x) * sin + (y3 - pivot_y) * cos;

    x1_new += pivot_x;
    y1_new += pivot_y;
    x2_new += pivot_x;
    y2_new += pivot_y;
    x3_new += pivot_x;
    y3_new += pivot_y;

    printf("Transformed triangle in yellow\n");
    setcolor(YELLOW);
    line((int)x1_new, (int)y1_new, (int)x2_new, (int)y2_new);
    line((int)x2_new, (int)y2_new, (int)x3_new, (int)y3_new);
    line((int)x3_new, (int)y3_new, (int)x1_new, (int)y1_new);

    getch();
    closegraph();
}
