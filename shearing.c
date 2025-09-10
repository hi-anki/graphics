#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 200, x3 = 50, y3 = 200;
    float shx = 0.5, shy = 0.0; // Shearing factors (shx for x-shear, shy for y-shear)
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;

    initgraph(&gd, &gm, NULL);
    
    printf("Original triangle is in white.\n");
    printf("Sheared triangle is in yellow.\n");

    // Draw original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    // Perform shearing
    new_x1 = x1 + (int)(shx * y1);
    new_y1 = y1 + (int)(shy * x1);
    new_x2 = x2 + (int)(shx * y2);
    new_y2 = y2 + (int)(shy * x2);
    new_x3 = x3 + (int)(shx * y3);
    new_y3 = y3 + (int)(shy * x3);

    // Draw sheared triangle
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);

    getch();
    closegraph();
    
    return 0;
}
