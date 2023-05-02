#include <bits/stdc++.h>
using namespace std;
int median(vector<int> v, vector<int> v1)
{
 vector<int> temp;
 for (int i = 0; i < v.size(); i++)
 {
  temp.push_back(v[i]);
 }
 for (int i = 0; i < v1.size(); i++)
 {
  temp.push_back(v1[i]);
 }
 sort(temp.begin(), temp.end());
 for (int i = 0; i < temp.size(); i++)
 {
  cout << temp[i] << " ";
 }
 int n = temp.size();
 if (n % 2 == 0)
  return (temp[n / 2] + temp[n / 2 - 1]) / 2;
 else
  return temp[n / 2];
}
int main()
{
 int n1, n2;
 cout << "enter size of first array:";
 cin >> n1;
 cout << "enter size of second array:";
 cin >> n2;
 vector<int> v(n1);
 cout << "enter ele in first array:";
 for (int i = 0; i < n1; i++)
 {
  cin >> v[i];
 }
 cout << "enter ele in second array:";
 vector<int> v1(n2);
 for (int i = 0; i < n2; i++)
 {
  cin >> v1[i];
 }
 cout << median(v, v1);
 return 0;
}