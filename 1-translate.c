#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  int x1, y1, x2, y2, x3, y3;
  int tx, ty;

  // test values:
  // (100,100) (150,50) (200,100)
  // tx = 50, ty = 80

  printf("Enter coordinates of first vertex (x1 y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter coordinates of second vertex (x2 y2): ");
  scanf("%d %d", &x2, &y2);
  printf("Enter coordinates of third vertex (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter translation factors tx ty: ");
  scanf("%d %d", &tx, &ty);

  initgraph(&gd, &gm, NULL);

  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);

  line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
  line(x2 + tx, y2 + ty, x3 + tx, y3 + ty);
  line(x3 + tx, y3 + ty, x1 + tx, y1 + ty);

  getch();
  closegraph();
  return 0;
}
