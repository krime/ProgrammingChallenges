#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 3000

int main(void) {
  int n=N;
  int i=0, p1=0, p2=0, k=0;
  int a[N]={0};
  int jolly=1;

  while (scanf("%d", &n)!=-1) {
    memset(a,0,sizeof (int)*N);
    jolly=1;
    
    scanf("%d",&p1);
    for (i=0;i<n-1;i++) {
      scanf("%d", &p2);
      if (!jolly) continue;
      k=p2>p1?p2-p1:p1-p2;
      if (k>=n||!k||a[k]) {jolly=0;continue;}
      else a[k]++;
      p1=p2;
    }
    if (jolly) puts("Jolly");
    else puts("Not jolly");
  }
  return 0;
}
