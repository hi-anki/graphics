#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 200, x3 = 50, y3 = 200;
    float sx = 1.5, sy = 1.5; // Scaling factors
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    int pivot_x = x1, pivot_y = y1; // Scaling with respect to the first point

    initgraph(&gd, &gm, NULL);
    
    printf("Original triangle is in white.\n");
    printf("Scaled triangle is in yellow.\n");

    // Draw original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Perform scaling
    new_x1 = pivot_x + (int)((x1 - pivot_x) * sx);
    new_y1 = pivot_y + (int)((y1 - pivot_y) * sy);
    new_x2 = pivot_x + (int)((x2 - pivot_x) * sx);
    new_y2 = pivot_y + (int)((y2 - pivot_y) * sy);
    new_x3 = pivot_x + (int)((x3 - pivot_x) * sx);
    new_y3 = pivot_y + (int)((y3 - pivot_y) * sy);
    
    // Draw scaled triangle
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);

    getch();
    closegraph();
    
    return 0;
}
