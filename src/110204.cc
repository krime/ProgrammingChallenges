#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

void decryption(string ciphertext, vector<string> dict) {
  istringstream iss(ciphertext);
  istream_iterator<string> eos;
  istream_iterator<string> ist(iss);
  vector<string> cipher(ist, eos);
  for (vector<string>::iterator it=cipher.begin(); it!=cipher.end(); it++) {
    cout<<' '<<*it;
  }
  cout<<endl;
}

int main(void) {
  int n;               // n words    
  vector<string> dict; // raw words
  string input;        // cipher text
  cin>>n;
  ostream_iterator<string> oit(cout, " ");
  for (int i=0;i<n;i++) {
    string tmp;
    cin>>tmp;
    dict.push_back(tmp);
  }
  // copy(dict.begin(), dict.end(), oit);
  while (getline(cin, input)) {
    if (!input.size()) continue;
    decryption(input, dict);
  }
  
  return 0;
}
