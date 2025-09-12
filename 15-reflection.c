#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int choice;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Choose reflection axis:\n");
    printf("1. X-axis\n");
    printf("2. Y-axis\n");
    scanf("%d", &choice);

    printf("Original triangle in white\n");
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Reflect and draw new triangle
    setcolor(YELLOW);
    if (choice == 1) {
        printf("Reflected triangle about x-axis in yellow\n");
        line(x1, getmaxy() - y1, x2, getmaxy() - y2);
        line(x2, getmaxy() - y2, x3, getmaxy() - y3);
        line(x3, getmaxy() - y3, x1, getmaxy() - y1);
    } else if (choice == 2) {
        printf("Reflected triangle about y-axis in yellow\n");
        line(getmaxx() - x1, y1, getmaxx() - x2, y2);
        line(getmaxx() - x2, y2, getmaxx() - x3, y3);
        line(getmaxx() - x3, y3, getmaxx() - x1, y1);
    } else {
        printf("Invalid choice.");
    }

    getch();
    closegraph();
}
