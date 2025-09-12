#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void main() {
    int gd = DETECT, gm;
    int x, y;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\BGI");

    // Get input for the pixel's coordinates and color
    printf("Enter the x-coordinate: ");
    scanf("%d", &x);

    printf("Enter the y-coordinate: ");
    scanf("%d", &y);

    // Print the pixel
    printf("The pixel is in red color at (%d, %d)", x, y);
    putpixel(x, y, 4);

    // Wait for a key press before closing the graphics window
    getch();

    // Close the graphics mode
    closegraph();
}
