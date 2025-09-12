#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void main() {
    int gd = DETECT, gm;
    int x, y;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter the x-coordinate: ");
    scanf("%d", &x);

    printf("Enter the y-coordinate: ");
    scanf("%d", &y);

    printf("The pixel is in red color at (%d, %d)\n", x, y);
    putpixel(x, y, 4);
    
    getch();
    closegraph();
}
