#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define MAX_VERTICES 10

// Function to sort intersection points
void sort_intersections(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main() {
    int gd = DETECT, gm;
    int n, i, y;
    int x_coords[MAX_VERTICES], y_coords[MAX_VERTICES];
    int intersections[MAX_VERTICES];
    int count;
    int y_min, y_max;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter coordinates of each vertex:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d (x, y): ", i + 1);
        scanf("%d %d", &x_coords[i], &y_coords[i]);
    }
    
    // Draw the polygon
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        line(x_coords[i], y_coords[i], x_coords[(i + 1) % n], y_coords[(i + 1) % n]);
    }

    // Find min and max y to determine scan range
    y_min = y_coords[0];
    y_max = y_coords[0];
    for (i = 1; i < n; i++) {
        if (y_coords[i] < y_min) y_min = y_coords[i];
        if (y_coords[i] > y_max) y_max = y_coords[i];
    }
    
    // Scan-line algorithm
    for (y = y_min; y <= y_max; y++) {
        count = 0;
        for (i = 0; i < n; i++) {
            int x1 = x_coords[i];
            int y1 = y_coords[i];
            int x2 = x_coords[(i + 1) % n];
            int y2 = y_coords[(i + 1) % n];

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                // Calculate intersection x-coordinate
                float x_intersect = x1 + (float)(y - y1) / (y2 - y1) * (x2 - x1);
                intersections[count++] = (int)x_intersect;
            }
        }
        
        sort_intersections(intersections, count);

        // Fill pixels between pairs of intersections
        for (i = 0; i < count; i += 2) {
            line(intersections[i], y, intersections[i + 1], y);
        }
    }

    getch();
    closegraph();
}
