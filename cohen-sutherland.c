#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define TOP 8    // 1000
#define BOTTOM 4 // 0100
#define RIGHT 2  // 0010
#define LEFT 1   // 0001

int WXmax = 300, WYmax = 300, WXmin = 100, WYmin = 100;

int regionCode(float x, float y){
  int code = 0;

  if (y > WYmax) code |= TOP;
  if (y < WYmin) code |= BOTTOM;
  if (x > WXmax) code |= RIGHT;
  if (x < WXmin) code |= LEFT;

  return code;
}

void clipLine(float x1, float y1, float x2, float y2){
  float x, y, xn, yn, m;
  int rcode1, rcode2, outCode, accept = 0;

  rcode1 = regionCode(x1, y1);
  rcode2 = regionCode(x2, y2);

  while (1){
    if ((rcode1 | rcode2) == 0){
      // Accept the line completely
      printf("Line is completely within the window, accepted as is.\n");
      accept = 1;
      break;
    }
    else if ((rcode1 & rcode2) != 0){
      // Discard the line completely
      printf("Line is completely outside the window, discarded completely.\n");
      break;
    }
    else{
      if (rcode1 != 0){
        outCode = rcode1;
        xn = x1;
        yn = y1;
      }
      else{
        outCode = rcode2;
        xn = x2;
        yn = y2;
      }

      m = (y2 - y1) / (x2 - x1);
      if (outCode & TOP){
        y = WYmax;
        x = (y - yn + m * xn) / m;
      }
      else if (outCode & BOTTOM){
        y = WYmin;
        x = (y - yn + m * xn) / m;
      }
      else if (outCode & RIGHT){
        x = WXmax;
        y = m * (x - xn) + yn;
      }
      else if (outCode & LEFT){
        x = WXmin;
        y = m * (x - xn) + yn;
      }

      if (outCode == rcode1){
        x1 = x;
        y1 = y;
        rcode1 = regionCode(x1, y1);
      }
      else{
        x2 = x;
        y2 = y;
        rcode2 = regionCode(x2, y2);
      }
    }
  }

  if (accept){
    printf("Clipped line in RED.\n");
    setcolor(RED);
    line((int)x1, (int)y1, (int)x2, (int)y2);
  }
}

int main(){
  int gd = DETECT, gm;
  float x1, y1, x2, y2;

  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  printf("Enter (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("Enter (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  // printf("Enter (WXmin, WYmin): ");
  // scanf("%f %f", &WXmin, &WYmin);

  // printf("Enter (WXmax, WYmax): ");
  // scanf("%f %f", &WXmax, &WYmax);

  rectangle(WXmin, WYmin, WXmax, WYmax);

  printf("Original line in WHITE\n");
  line((int)x1, (int)y1, (int)x2, (int)y2);

  getch();
  clipLine((int)x1, (int)y1, (int)x2, (int)y2);

  getch();
  closegraph();
  return 0;
}