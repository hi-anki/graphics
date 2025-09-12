#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Outcode bit positions
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Define the clipping window boundaries
const int x_min = 100, y_min = 100;
const int x_max = 300, y_max = 300;

// Function to compute the outcode for a point
int computeCode(double x, double y) {
    int code = INSIDE; // initialize as inside
    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;
    return code;
}

void main() {
    int gd = DETECT, gm;
    double x1, y1, x2, y2;
    int code1, code2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Compute outcodes for both points
    code1 = computeCode(x1, y1);
    code2 = computeCode(x2, y2);

    int accept = 0; // Set to 1 if line is accepted
    
    // Original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both points inside, line is accepted
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both points outside and on the same side, line is rejected
            break;
        } else {
            // Clipping is needed
            double x, y;
            int outcode_out = (code1 != 0) ? code1 : code2;

            if (outcode_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (outcode_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (outcode_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (outcode_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (outcode_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
    }
    
    getch();
    closegraph();
}
