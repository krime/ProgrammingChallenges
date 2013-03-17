#include <cstdio>
#include <cstdlib>
#include <cstring>

#define M 300
#define N 300

#define Exchange(a,b) {a=(a)^(b);b=(a)^(b);a=(a)^(b);}

void fillRegion(char img[][N], int x, int y, int m, int n);

void printImage(char img[][N], int m, int n, char* name);

int main(int argc, char** argv) {
  char img[M][N];
  int m,n;
  int x_1, x_2, y_1, y_2, x, y;
  
  char c;
  char name[256];
  
  memset(img, 0, M*N);
  m=n=x=y=x_1=x_2=y_1=y_2=c=0;
  while (scanf("%c", &c) != EOF) {
    if (c=='X') break;
    switch (c) {
    case 'I':
      scanf("%d %d", &n, &m);
      memset(img, 'O', M*N);
      break;
    case 'C':
      memset(img, 'O', M*N);
      break;
    case 'L':
      scanf("%d %d %c", &y, &x, &c);
      img[x-1][y-1] = c;
      break;
    case 'V':
      scanf("%d %d %d %c", &y, &x_1, &x_2, &c);
      if (x_1>x_2) Exchange(x_1, x_2);
      
      y --;
      x_1 --;
      for (x=x_1; x<x_2; x++)
        img[x][y]=c;
      break;
    case 'H':
      scanf("%d %d %d %c", &y_1, &y_2, &x, &c);
      if (y_1>y_2) Exchange(y_1, y_2);
      
      x --;
      y_1 --;
      for (y=y_1; y<y_2; y++)
        img[x][y]=c;
      break;
    case 'K':
      scanf("%d %d %d %d %c", &y_1, &x_1, &y_2, &x_2, &c);
      if (x_1>x_2) Exchange(x_1, x_2);
      if (y_1>y_2) Exchange(y_1, y_2);
      
      x_1 --;
      y_1 --;
      for (x=x_1; x<x_2; x++)
        for (y=y_1; y<y_2; y++)
          img[x][y]=c;
      break;
    case 'F':
      scanf("%d %d %c", &y, &x, &c);
      fillRegion(img, x-1, y-1, m, n);
      for (x=0; x<m; x++)
        for (y=0; y<n; y++)
          if (img[x][y]==-1)
            img[x][y]=c;
      break;
    case 'S':
      scanf("%s", name);
      printImage(img, m, n, name);
      break;
    }
    while (getchar()!='\n') continue;
  }
  return 0;
}

void printImage(char img[][N], int m, int n, char* name) {
  int i,j;
  puts(name);
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++)
      printf("%c", img[i][j]);
    puts("");
  }
}

void fillRegion(char img[][N], int x, int y, int m, int n) {
  char ch = img[x][y];
  img[x][y] = -1;
  if (x>0 && img[x-1][y] == ch) fillRegion(img, x-1, y, m, n);
  if (y>0 && img[x][y-1] == ch) fillRegion(img, x, y-1, m, n);
  if (x+1<m && img[x+1][y] == ch) fillRegion(img, x+1, y, m, n);
  if (y+1<n && img[x][y+1] == ch) fillRegion(img, x, y+1, m, n);
}
