#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
  int gd = DETECT, gm;
  int x1, y1, x2, y2, x3, y3;
  float angle, rad;

  // test values: (100,100) (150,50) (200,100)
  // angle = 45

  printf("Enter coordinates of first vertex (x1 y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter coordinates of second vertex (x2 y2): ");
  scanf("%d %d", &x2, &y2);
  printf("Enter coordinates of third vertex (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter rotation angle in degrees: ");
  scanf("%f", &angle);

  rad = angle * M_PI / 180.0;

  initgraph(&gd, &gm, NULL);

  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);

  int xr1 = x1 * cos(rad) - y1 * sin(rad);
  int yr1 = x1 * sin(rad) + y1 * cos(rad);
  int xr2 = x2 * cos(rad) - y2 * sin(rad);
  int yr2 = x2 * sin(rad) + y2 * cos(rad);
  int xr3 = x3 * cos(rad) - y3 * sin(rad);
  int yr3 = x3 * sin(rad) + y3 * cos(rad);

  line(xr1, yr1, xr2, yr2);
  line(xr2, yr2, xr3, yr3);
  line(xr3, yr3, xr1, yr1);

  getch();
  closegraph();
  return 0;
}
