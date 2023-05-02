#include <bits/stdc++.h>
using namespace std;
void insert(vector<bool> &v, int n)
{
 v[n] = true;
}
void search(vector<bool> &v, int n)
{
 if (v[n] == true)
  cout << n << " is present" << endl;
 else
  cout << n << " is not present" << endl;
}
void deletee(vector<bool> &v, int n)
{
 v[n] = false;
}
int main()
{
 int n;
 cin >> n;
 vector<bool> v(n, false);
 insert(v, 10);
 insert(v, 20);
 insert(v, 119);
 search(v, 10);
 search(v, 20);
 deletee(v, 119);
 search(v, 119);
 return 0;
}