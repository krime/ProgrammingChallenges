#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

void analysis(string cipher, vector<string> dict) {
  istringstream iss(cipher);
  istream_iterator<string> eos;
  istream_iterator<string> ist(iss);
  vector<string> words(ist, eos);
  //while (){}
}

int main(void) {
  int n; // n words
  vector<string> dict; // raw words
  string text; // cipher text
  cin>>n;
  ostream_iterator<string> oit(cout, " ");
  for (int i=0;i<n;i++) {
    string tmp;
    cin>>tmp;
    dict.push_back(tmp);
  }
  // copy(dict.begin(), dict.end(), oit);
  while (getline(cin, text)) {
    // cout<<text<<endl;
    analysis(text, dict);
  }
  
  return 0;
}
