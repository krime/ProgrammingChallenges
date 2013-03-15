
int egcd(int a, int b, int& x, int& y) {
  int ma[3]={1,0,a};
  int mb[3]={0,1,b};
  while (a%b) {
    for (int i=0;i<3;i++) cout<<'\t'<<ma[i];
    cout<<endl;
    int p=a/b;
    int mt[3]={ma[0]-mb[0]*p,ma[1]-mb[1]*p,ma[2]-mb[2]*p};
    memcpy(ma,mb,3*sizeof(int));
    memcpy(mb,mt,3*sizeof(int));
    a=ma[2];
    b=mb[2];
  }
  x=mb[0];y=mb[1];
  return b;
}
