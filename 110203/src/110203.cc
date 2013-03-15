#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#define NUM 100
#define DAY 3650

int main(void) {
  char d[DAY];
  size_t t;
  size_t n;
  size_t p;
  size_t h[NUM];

  cin>>t;
  while (t--) {
    cin>>n>>p;
    for (size_t i=0;i<p;i++) cin>>h[i];

    memset(d,0,n*sizeof(char));
    for (size_t i=0;i<p;i++)
      for (size_t j=h[i]-1;j<n;j+=h[i])
        d[j]=1;
    for (size_t i=0;i<n;i++) cout<<' '<<(int)d[i];
    cout<<endl;
    // char weekday[2]={0,0};
    for (size_t i=0;i<n/7;i++) {
      d[i*7+5]=0;
      d[i*7+6]=0;
    }//memcpy(&d[i*7+5],weekday,2*sizeof(char));
    for (size_t i=0;i<n/7;i++)
      for (size_t j=0;j<7;j++)
        cout<<' '<<j+1;
    cout<<endl;
    for (size_t i=0;i<n;i++) cout<<' '<<(int)d[i];
    cout<<endl;
    char sum=0;
    for (size_t i=0;i<n;i++) sum+=d[i];
    cout<<(int)sum<<endl;
  }
  return 0;
}
