#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int size = s.length();
  char l = s[size - 1];
  char sl = s[size - 2];
  // ab
  string num;
  num.push_back(sl);
  num.push_back(l);
  int numb = stoi(num);
  cout << numb % 20 << endl;

 return 0;
}
