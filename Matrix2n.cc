
class Matrix2n {
public:
  // Constructors
  Matrix2n():
    r1(vector<int>()), r2(vector<int>()) {}
  Matrix2n(int n):
    r1(vector<int>(n)), r2(vector<int>(n)) {}
  Matrix2n(vector<int> row1, vector<int> row2):
    r1(row1), r2(row2) {}
  Matrix2n(int row1[], unsigned int n1, int row2[], unsigned int n2):
    r1(row1, row1+n1), r2(row2, row2+n2) {}
  // Copy Controls
  // Copy Constructor
  Matrix2n(const Matrix2n& m): r1(m.r1), r2(m.r2) {}
  // Assignment Operator
  const Matrix2n& operator=(const Matrix2n& m) {r1=m.r1;r2=m.r2;return *this;}
  // Assignment Operator (Compatible Version)
  Matrix2n& operator=(Matrix2n& m) {r1=m.r1;r2=m.r2;return *this;}
  // Destructor
  ~Matrix2n() {}

  // IO Operations
  friend istream& operator>>(istream& sin, Matrix2n& m) {
    int t=0;
    sin>>t;m.r1.push_back(t);
    sin>>t;m.r2.push_back(t);
    return sin;
  }
  friend ostream& operator<<(ostream& sout, const Matrix2n& m) {
    for (vector<int>::const_iterator it=m.r1.begin();it!=m.r1.end();it++)
      sout<<'\t'<<*it;
    sout<<endl;
    for (vector<int>::const_iterator it=m.r2.begin();it!=m.r2.end();it++)
      sout<<'\t'<<*it;
    return sout;
  }
  // Multiply Operation
  void Mul(const Matrix2n& m, Matrix2n& mp) const {
    if (this->r1.size()!=2) exit(1);
    for (vector<int>::size_type i=0; i!=m.r1.size(); i++) {
      mp.r1[i]=this->r1[0]*m.r1[i]+this->r1[1]*m.r2[i];
      mp.r2[i]=this->r2[0]*m.r1[i]+this->r2[1]*m.r2[i];
    }
  }
  
  // Fields
  vector<int> r1;
  vector<int> r2;
};

class Euclidian_Algorithm {
public:
  // Extended Euclidian Algorithm
  static void egcd(int a, int b, int &x, int &y);
};

void Euclidian_Algorithm::egcd(int a, int b, int &x, int &y) {
  int ma[2][3]={
    {1,0,a},
    {0,1,b}};
  Matrix2n m(ma[0],3,ma[1],3);
  int mt[2][2]={
    {0,1},
    {1,0}};
  Matrix2n rs(mt[0],2,mt[1],2);
  Matrix2n mp(3);
  //cout<<m<<endl;
  while (a%b) {
    int p=a/b;
    mt[0][0]=1,mt[0][1]=-p;
    mt[1][0]=0,mt[1][1]=1;
    Matrix2n ra(mt[0],2,mt[1],2);
    ra.Mul(m,mp);m=mp;
    rs.Mul(m,mp);m=mp;
    a=m.r1[2];b=m.r2[2];
  }
  x=m.r2[0];
  y=m.r2[1];
}

void egcd(int a, int b, int& x, int& y) {
  int mat[2][3]={
    {1,0,a},
    {0,1,b}};
  int ms[2][2]={
    {0,1},
    {1,0}};
  int mt[2][2]={
    {1,0},
    {0,1}};
  int mr[2][3]={{0}};
  while (a%b) {
    int p=a/b;
    mt[0][1]=-p;
    /*
    for (int i=0;i<2;i++) {
      for (int j=0;j<3;j++)
        cout<<'\t'<<mr[i][j];
      cout<<endl;
    }
    */
    for (int i=0;i<2;i++)
      for (int j=0;j<3;j++)
        mr[i][j]=mt[i][0]*mat[0][j]+mt[i][1]*mat[1][j];
    for (int i=0;i<2;i++)
      for (int j=0;j<3;j++)
        mat[i][j]=mr[i][j];
    for (int i=0;i<2;i++)
      for (int j=0;j<3;j++)
        mr[i][j]=ms[i][0]*mat[0][j]+ms[i][1]*mat[1][j];
    for (int i=0;i<2;i++)
      for (int j=0;j<3;j++)
        mat[i][j]=mr[i][j];
    a=mr[0][2];b=mr[1][2];
  }
  x=mr[1][0];y=mr[1][1];
}
