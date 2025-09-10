#include <stdio.h>

void plot_circle_points(int xc, int yc, int x, int y) {
  printf("(%d, %d)\n", xc + x, yc + y);
  printf("(%d, %d)\n", xc - x, yc + y);
  printf("(%d, %d)\n", xc + x, yc - y);
  printf("(%d, %d)\n", xc - x, yc - y);
  printf("(%d, %d)\n", xc + y, yc + x);
  printf("(%d, %d)\n", xc - y, yc + x);
  printf("(%d, %d)\n", xc + y, yc - x);
  printf("(%d, %d)\n", xc - y, yc - x);
}

int main() {
  int xc = 0, yc = 0, r = 10;
  int x = 0, y = r;
  int p = 1 - r; // Initial decision parameter

  printf("Drawing a circle with center (%d, %d) and radius %d\n", xc, yc, r);
  printf("\nPlotted pixels:\n");

  plot_circle_points(xc, yc, x, y);

  while (x < y) {
    x++;
    if (p < 0) {
      p = p + 2 * x + 1;
    } else {
      y--;
      p = p + 2 * x - 2 * y + 1;
    }
    plot_circle_points(xc, yc, x, y);
  }

  return 0;
}
