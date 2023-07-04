#include <bits/stdc++.h>
using namespace std;
void maxi(vector<int> arr, int k)
{
 deque<int> dq;
 for (int i = 0; i < k; i++)
 {
  /* code */
  while (!dq.empty() && arr[i] >= arr[dq.back()])
  {
   dq.pop_back();
  }
  dq.push_back(i);
 }
 for (int i = k; i < arr.size(); i++)
 {
  cout << arr[dq.front()] << " ";
  while (!dq.empty() && dq.front() <= i - k)
  {
   dq.pop_front();
  }
  while (!dq.empty() && arr[i] >= arr[dq.back()])
  {
   dq.pop_back();
  }
  dq.push_back(i);
 }
 cout << arr[dq.front()] << " ";
}

int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 maxi(v, 3);
 return 0;
}