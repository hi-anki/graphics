#include <stdio.h>
#include <math.h>

int main() {
  float x1 = 10, y1 = 10;
  float x2 = 25, y2 = 20;
  float dx, dy, steps;
  float x, y;
  int i;

  dx = x2 - x1;
  dy = y2 - y1;

  if (fabs(dx) > fabs(dy)) {
    steps = fabs(dx);
  } else {
    steps = fabs(dy);
  }

  x = x1;
  y = y1;

  float x_inc = dx / steps;
  float y_inc = dy / steps;

  printf("Plotting line from (%.2f, %.2f) to (%.2f, %.2f)\n", x1, y1, x2, y2);
  printf("Steps: %.2f\n", steps);
  printf("x_inc: %.2f, y_inc: %.2f\n", x_inc, y_inc);
  printf("\nPixel coordinates:\n");

  for (i = 0; i <= steps; i++) {
    printf("(%d, %d)\n", (int)(x + 0.5), (int)(y + 0.5));
    x += x_inc;
    y += y_inc;
  }

  return 0;
}
