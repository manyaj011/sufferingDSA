#include <bits/stdc++.h>
using namespace std;
pair<int, int> pairwithgivensum(int arr[], int n, int s)
{
 unordered_set<int> h;
 for (int i = 0; i < n; i++)
 {
  /* code */

  if (h.find(s - arr[i]) != h.end())
   return make_pair(arr[i], s - arr[i]);
  else
   h.insert(arr[i]);
 }
 return make_pair(0, 0);
}

int main()
{
 int arr[] = {3, 2, 8, 15, -8};
 pair<int, int> k = pairwithgivensum(arr, 5, 17);
 if (k.first == 0 && k.second == 0)
  cout << "no pair found";
 else
  cout << "the pair is present with sum 17: " << k.first << " & " << k.second;
 return 0;
}