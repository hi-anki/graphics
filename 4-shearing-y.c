#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  int x1, y1, x2, y2, x3, y3;
  int shy;

  // test values: (100,100) (150,50) (200,100)
  // shy = 2

  printf("Enter coordinates of first vertex (x1 y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter coordinates of second vertex (x2 y2): ");
  scanf("%d %d", &x2, &y2);
  printf("Enter coordinates of third vertex (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter shear factor shy: ");
  scanf("%d", &shy);

  initgraph(&gd, &gm, NULL);

  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);

  line(x1, y1 + shy * x1, x2, y2 + shy * x2);
  line(x2, y2 + shy * x2, x3, y3 + shy * x3);
  line(x3, y3 + shy * x3, x1, y1 + shy * x1);

  getch();
  closegraph();
  return 0;
}
