#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int pivot_x, pivot_y;
    float theta, rad_theta;
    float new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\BGI");

    // Get triangle coordinates
    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    printf("Enter x3, y3: ");
    scanf("%d %d", &x3, &y3);

    // Get rotation details
    printf("Enter pivot point (x,y) for rotation:\n");
    scanf("%d %d", &pivot_x, &pivot_y);

    printf("Enter rotation angle (in degrees, positive): ");
    scanf("%f", &theta);

    // Convert angle to radians
    rad_theta = theta * M_PI / 180.0;
    float sin_theta = sin(rad_theta);
    float cos_theta = cos(rad_theta);

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Perform composite transformation

    // Step 1: Translate the triangle so the pivot point is at the origin (0,0)
    // The translation factors are (-pivot_x, -pivot_y)
    
    // Step 2: Rotate the translated triangle about the new origin
    new_x1 = (x1 - pivot_x) * cos_theta - (y1 - pivot_y) * sin_theta;
    new_y1 = (x1 - pivot_x) * sin_theta + (y1 - pivot_y) * cos_theta;
    
    new_x2 = (x2 - pivot_x) * cos_theta - (y2 - pivot_y) * sin_theta;
    new_y2 = (x2 - pivot_x) * sin_theta + (y2 - pivot_y) * cos_theta;
    
    new_x3 = (x3 - pivot_x) * cos_theta - (y3 - pivot_y) * sin_theta;
    new_y3 = (x3 - pivot_x) * sin_theta + (y3 - pivot_y) * cos_theta;
    
    // Step 3: Translate the rotated triangle back to the original pivot point location
    // The translation factors are (+pivot_x, +pivot_y)
    new_x1 += pivot_x;
    new_y1 += pivot_y;
    new_x2 += pivot_x;
    new_y2 += pivot_y;
    new_x3 += pivot_x;
    new_y3 += pivot_y;

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
