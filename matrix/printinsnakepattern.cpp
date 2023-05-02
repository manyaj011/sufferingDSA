#include <bits/stdc++.h>
using namespace std;
void print(vector<int> arr[], int n)
{
 for (int i = 0; i < n; i++) //why n ki jgh arr[i].size rkhne se infinite loop chlra h 
 {
  if (i % 2 == 0)
  {
   for (int j = 0; j < arr[i].size(); j++)
   {
    /* code */
    cout << arr[i][j] << " ";
   }
   
  }
  if (i % 2 != 0)
  {
   for (int j = arr[i].size() - 1; j >= 0; j--)
   {
    /* code */
    cout << arr[i][j] << " ";
   }
   
  }
 }
}
int main()
{
 int n;
 cin >> n;
 vector<int> arr[n] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16}};
 print(arr, n);
 return 0;
}