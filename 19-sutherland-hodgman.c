#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// Max number of vertices
#define MAX_VERTICES 20

// Define the clipping window boundaries
const int x_min = 100, y_min = 100;
const int x_max = 300, y_max = 300;

// Structure to hold a vertex
struct Point {
    int x, y;
};

// Function to draw a polygon
void drawPolygon(struct Point p[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(p[i].x, p[i].y, p[(i + 1) % n].x, p[(i + 1) % n].y);
    }
}

// Sutherland-Hodgman clipping function for one boundary
void sutherlandHodgman(struct Point in[], int in_n, struct Point out[], int *out_n, int edge) {
    *out_n = 0;
    for (int i = 0; i < in_n; i++) {
        struct Point p1 = in[i];
        struct Point p2 = in[(i + 1) % in_n];

        int p1_out, p2_out;
        
        switch (edge) {
            case 0: // Left
                p1_out = (p1.x < x_min);
                p2_out = (p2.x < x_min);
                break;
            case 1: // Right
                p1_out = (p1.x > x_max);
                p2_out = (p2.x > x_max);
                break;
            case 2: // Bottom
                p1_out = (p1.y < y_min);
                p2_out = (p2.y < y_min);
                break;
            case 3: // Top
                p1_out = (p1.y > y_max);
                p2_out = (p2.y > y_max);
                break;
        }

        if (!p1_out && !p2_out) { // Case 1: Both inside
            out[(*out_n)++] = p2;
        } else if (p1_out && !p2_out) { // Case 2: P1 outside, P2 inside (crossing in)
            struct Point intersection;
            if (edge == 0 || edge == 1) { // Left or Right
                intersection.y = p1.y + (p2.y - p1.y) * (edge == 0 ? x_min - p1.x : x_max - p1.x) / (p2.x - p1.x);
                intersection.x = (edge == 0 ? x_min : x_max);
            } else { // Bottom or Top
                intersection.x = p1.x + (p2.x - p1.x) * (edge == 2 ? y_min - p1.y : y_max - p1.y) / (p2.y - p1.y);
                intersection.y = (edge == 2 ? y_min : y_max);
            }
            out[(*out_n)++] = intersection;
            out[(*out_n)++] = p2;
        } else if (!p1_out && p2_out) { // Case 3: P1 inside, P2 outside (crossing out)
            struct Point intersection;
            if (edge == 0 || edge == 1) {
                intersection.y = p1.y + (p2.y - p1.y) * (edge == 0 ? x_min - p1.x : x_max - p1.x) / (p2.x - p1.x);
                intersection.x = (edge == 0 ? x_min : x_max);
            } else {
                intersection.x = p1.x + (p2.x - p1.x) * (edge == 2 ? y_min - p1.y : y_max - p1.y) / (p2.y - p1.y);
                intersection.y = (edge == 2 ? y_min : y_max);
            }
            out[(*out_n)++] = intersection;
        } // Case 4: Both outside, do nothing
    }
}

void main() {
    int gd = DETECT, gm;
    struct Point polygon[MAX_VERTICES], clipped_polygon[MAX_VERTICES];
    int n, clipped_n;

    initgraph(&gd, &gm, "C:\\BGI");

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter coordinates of each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d (x, y): ", i + 1);
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Draw the original polygon
    drawPolygon(polygon, n, RED);

    // Copy initial polygon to clipped_polygon array
    for (int i = 0; i < n; i++) {
        clipped_polygon[i] = polygon[i];
    }
    clipped_n = n;

    // Apply Sutherland-Hodgman for each of the 4 boundaries
    // Note: The order of clipping boundaries matters.
    struct Point temp_polygon[MAX_VERTICES];
    int temp_n;
    
    // Left edge
    sutherlandHodgman(clipped_polygon, clipped_n, temp_polygon, &temp_n, 0);
    for (int i = 0; i < temp_n; i++) clipped_polygon[i] = temp_polygon[i]; clipped_n = temp_n;

    // Right edge
    sutherlandHodgman(clipped_polygon, clipped_n, temp_polygon, &temp_n, 1);
    for (int i = 0; i < temp_n; i++) clipped_polygon[i] = temp_polygon[i]; clipped_n = temp_n;

    // Bottom edge
    sutherlandHodgman(clipped_polygon, clipped_n, temp_polygon, &temp_n, 2);
    for (int i = 0; i < temp_n; i++) clipped_polygon[i] = temp_polygon[i]; clipped_n = temp_n;

    // Top edge
    sutherlandHodgman(clipped_polygon, clipped_n, temp_polygon, &temp_n, 3);
    for (int i = 0; i < temp_n; i++) clipped_polygon[i] = temp_polygon[i]; clipped_n = temp_n;

    // Draw the clipped polygon
    drawPolygon(clipped_polygon, clipped_n, YELLOW);
    
    getch();
    closegraph();
}
