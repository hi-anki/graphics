#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to perform boundary fill
void boundary_fill(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    if ((current_color != boundary_color) && (current_color != fill_color)) {
        putpixel(x, y, fill_color);
        boundary_fill(x + 1, y, fill_color, boundary_color);
        boundary_fill(x - 1, y, fill_color, boundary_color);
        boundary_fill(x, y + 1, fill_color, boundary_color);
        boundary_fill(x, y - 1, fill_color, boundary_color);
    }
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int seed_x, seed_y;

    initgraph(&gd, &gm, "C:\\BGI");

    // Get polygon coordinates
    printf("Enter triangle coordinates (x1,y1), (x2,y2), (x3,y3):\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Draw the polygon with a specific boundary color (e.g., White)
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Get a seed point inside the polygon
    printf("Enter a seed point (x,y) inside the polygon:\n");
    scanf("%d %d", &seed_x, &seed_y);
    
    // Perform boundary fill
    boundary_fill(seed_x, seed_y, YELLOW, WHITE);

    getch();
    closegraph();
}
