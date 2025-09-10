#include <stdio.h>
#include <stdlib.h>

void plot_line(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    printf("Plotting line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
    printf("Plotted pixels:\n");

    while (1) {
        printf("(%d, %d)\n", x1, y1);

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

int main() {
    int x1 = 10, y1 = 10;
    int x2 = 25, y2 = 20;
    plot_line(x1, y1, x2, y2);
    return 0;
}
