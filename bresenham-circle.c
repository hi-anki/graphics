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
  int p = 3 - 2 * r;

  printf("Drawing a circle with center (%d, %d) and radius %d\n", xc, yc, r);
  printf("\nPlotted pixels:\n");

  plot_circle_points(xc, yc, x, y);

  while (x < y) {
    if (p < 0) {
      x++;
      p = p + 4 * x + 6;
    } else {
      x++;
      y--;
      p = p + 4 * (x - y) + 10;
    }
    plot_circle_points(xc, yc, x, y);
  }

  return 0;
}
