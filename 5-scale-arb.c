#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  int x1, y1, x2, y2, x3, y3;
  int sx, sy, xr, yr;

  // test values: (100,100) (150,50) (200,100)
  // sx=2, sy=2, reference=(100,100)

  printf("Enter coordinates of first vertex (x1 y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter coordinates of second vertex (x2 y2): ");
  scanf("%d %d", &x2, &y2);
  printf("Enter coordinates of third vertex (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter scaling factors sx sy: ");
  scanf("%d %d", &sx, &sy);
  printf("Enter reference point (xr yr): ");
  scanf("%d %d", &xr, &yr);

  initgraph(&gd, &gm, NULL);

  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);

  int nx1 = xr + (x1 - xr) * sx;
  int ny1 = yr + (y1 - yr) * sy;
  int nx2 = xr + (x2 - xr) * sx;
  int ny2 = yr + (y2 - yr) * sy;
  int nx3 = xr + (x3 - xr) * sx;
  int ny3 = yr + (y3 - yr) * sy;

  line(nx1, ny1, nx2, ny2);
  line(nx2, ny2, nx3, ny3);
  line(nx3, ny3, nx1, ny1);

  getch();
  closegraph();
  return 0;
}
