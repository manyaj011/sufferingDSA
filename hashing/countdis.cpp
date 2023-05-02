#include <bits/stdc++.h>
using namespace std;
int countdis(vector<int> v, int k)
{
 int n = v.size();
 for (int i = 0; i <= n - k; i++)
 {
  /* code */
  int count = 0;
  for (int j = 0; j < k; j++)
  {
   /* code */
   bool flag = false;
   for (int p = 0; p < j; p++) // to comapre elements till j ki vo pehle present h ya nhi
   {
    /* code */
    if (v[i + j] == v[i + p])
    {
     flag = true;
     break;
    }
   }
   if (flag == false)
    count++;
  }
  cout << count << " ";
 }
}

int optapp(vector<int> v, int k)
{
 int n = v.size();
 unordered_map<int, int> freq;
 int c = 0, i = 0;
 // traverse the first window and store the count of every element in hash map
 for (i = 0; i < k; i++)
 {
  /* code */
  if (freq[v[i]] == 0)
   c++;
  freq[v[i]] += 1;
 }
 // print the count of first window
 cout << c << " ";

 // to traverse through the remaining array
 for (int i = k; i < n; i++)
 {
  // if there is only one occurence of first element then decrease disticnt count
  if (freq[v[i - k]] == 1)
   c--;
  // reduce count of distinct element
  freq[v[i - k]] -= 1;

  // add new element
  // if this element occurs for the first time increment distinct count
  if (freq[v[i]] == 0)
   c++;
  freq[v[i]] += 1;

  cout << c << " ";
 }
}

//tc o(n)
//as o(k)
int main()
{
 vector<int> v = {10, 20, 20, 10, 30, 40, 10};
 // cout << countdis(v, 4);
 cout << optapp(v, 4);
 return 0;
}