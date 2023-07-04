#include <bits/stdc++.h>
using namespace std;
int firstcirtour(vector<int> petrol, vector<int> dist)
{
 for (int start = 0; start < petrol.size(); start++)
 {
  int end = start;
  int curr_petrol = 0;
  while (true)
  {
   curr_petrol += (petrol[end] - dist[end]);
   if (curr_petrol < 0)
   {
    break;
   }
   end = (end + 1) % petrol.size();
   if (end == start)
   {
    return (start + 1);
   }
  }
 }
 return -1;
}

// this is the better solution
int better_sol(vector<int> petrol, vector<int> dist)
{
 int n = petrol.size();
 deque<int> dq;
 int curr_petrol = 0;
 for (int i = 0; i < n; i++)
 {
  /* code */
  int start = i;
  int end = start;
  while (true)
  {
   dq.push_back(end);
   curr_petrol += (petrol[end] - dist[end]);
   // if(curr_petrol >= 0){
   //  dq.push_back(i);
   // }
   while (!dq.empty() && curr_petrol < 0)
   {
    curr_petrol -= petrol[dq.front()] - dist[dq.front()];
    dq.pop_front();
   }
   end = (end + 1) % n;
   if (end == start)
    return (start + 1);
  }
 }
 return -1;
}

// the eff sol
int eff(vector<int> petrol, vector<int> dist)
{
 int start = 0;
 int curr_petrol = 0;
 int prev_petrol = 0;
 for (int i = 0; i < petrol.size(); i++)
 {
  curr_petrol += (petrol[i] - dist[i]);
  if (curr_petrol < 0)
  {
   start = i + 1;
   prev_petrol += curr_petrol;
   curr_petrol = 0;
  }
 }
 return ((curr_petrol + prev_petrol >= 0) ? start + 1 : -1);
}
int main()
{
 vector<int> petrol = {8, 9, 4};
 vector<int> dist = {5, 10, 12};
 cout << firstcirtour(petrol, dist)<<endl;
 cout << better_sol(petrol, dist)<<endl;
 cout << eff(petrol, dist)<<endl;
 return 0;
}