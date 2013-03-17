#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#define NUM 100
#define DAY 3651

int main(void) {
  size_t t;
  size_t n;
  size_t p;
  size_t d[DAY];
  size_t h[NUM];

  cin>>t;
  while (t--) {
    memset(h,0,sizeof(h));
    memset(d,0,sizeof(d));

    cin>>n>>p;
    for (size_t i=0;i<p;i++) cin>>h[i];
    for (size_t i=0;i<p;i++)
      for (size_t j=h[i]-1;j<n;j+=h[i])
        d[j]=1;
    for (size_t i=0;i+5<n;i+=7) {
      d[i+5]=0;
      d[i+6]=0;
    }
    size_t sum=0;
    for (size_t i=0;i<n;i++) sum+=d[i];
    cout<<sum<<endl;
  }
  return 0;
}
