#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to perform flood fill
void flood_fill(int x, int y, int new_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, new_color);
        flood_fill(x + 1, y, new_color, old_color);
        flood_fill(x - 1, y, new_color, old_color);
        flood_fill(x, y + 1, new_color, old_color);
        flood_fill(x, y - 1, new_color, old_color);
    }
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int seed_x, seed_y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get polygon coordinates
    printf("Enter triangle coordinates (x1,y1), (x2,y2), (x3,y3):\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Draw the polygon
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Get a seed point inside the polygon
    printf("Enter a seed point (x,y) inside the polygon:\n");
    scanf("%d %d", &seed_x, &seed_y);
    
    // Perform flood fill
    flood_fill(seed_x, seed_y, YELLOW, BLACK); // Filling with yellow, old color is black

    getch();
    closegraph();
}
