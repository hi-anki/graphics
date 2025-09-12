#include <graphics.h>
#include <conio.h>

void main() {
    int gd = DETECT, gm;
    int x_coord, y_coord, pixel_color;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get input for the pixel's coordinates and color
    printf("Enter the x-coordinate: ");
    scanf("%d", &x_coord);
    printf("Enter the y-coordinate: ");
    scanf("%d", &y_coord);
    printf("Enter the color (0-15): ");
    scanf("%d", &pixel_color);

    // Print the pixel
    putpixel(x_coord, y_coord, pixel_color);

    // Wait for a key press before closing the graphics window
    getch();

    // Close the graphics mode
    closegraph();
}
