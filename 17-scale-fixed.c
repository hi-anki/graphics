#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int fixed_x, fixed_y;
    float sx, sy;
    float new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get triangle coordinates
    printf("Enter triangle coordinates (x1,y1), (x2,y2), (x3,y3):\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Get scaling details
    printf("Enter fixed point (x,y) for scaling:\n");
    scanf("%d %d", &fixed_x, &fixed_y);
    printf("Enter scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Perform composite transformation

    // Step 1: Translate the triangle so the fixed point is at the origin (0,0)
    // The translation factors are (-fixed_x, -fixed_y)
    
    // Step 2: Scale the translated triangle about the new origin
    new_x1 = (x1 - fixed_x) * sx;
    new_y1 = (y1 - fixed_y) * sy;
    
    new_x2 = (x2 - fixed_x) * sx;
    new_y2 = (y2 - fixed_y) * sy;
    
    new_x3 = (x3 - fixed_x) * sx;
    new_y3 = (y3 - fixed_y) * sy;

    // Step 3: Translate the scaled triangle back to the original fixed point location
    // The translation factors are (+fixed_x, +fixed_y)
    new_x1 += fixed_x;
    new_y1 += fixed_y;
    new_x2 += fixed_x;
    new_y2 += fixed_y;
    new_x3 += fixed_x;
    new_y3 += fixed_y;

    // Draw the transformed triangle
    setcolor(YELLOW);
    line((int)new_x1, (int)new_y1, (int)new_x2, (int)new_y2);
    line((int)new_x2, (int)new_y2, (int)new_x3, (int)new_y3);
    line((int)new_x3, (int)new_y3, (int)new_x1, (int)new_y1);

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
}
