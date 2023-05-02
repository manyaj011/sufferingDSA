#include <bits/stdc++.h>
using namespace std;
// this is the recurssive method
int firstoccur(vector<int> v, int low, int high, int target)
{
 int n = v.size();

 if (low > high)
  return -1;

 int mid = (low + high) / 2;
 if (target > v[mid])
 {
  return firstoccur(v, mid + 1, high, target);
 }
 else if (target < v[mid])
 {
  return firstoccur(v, low, mid - 1, target);
 }
 else
 {
  // if mid is zero it means low=high=0 means it is the first element
  if (mid == 0 || v[mid] != v[mid - 1])
  {
   return mid;
  }
  else
   // if mid = mid - 1 then we again run the loop beacuse mid se pehle koi index h jhaan element present h
   return firstoccur(v, low, mid - 1, target);
 }
}

// iterative way
int firstoccur_iter(vector<int> v, int target)
{
 int n = v.size();
 int low = 0;
 int high = n - 1;
 while (low <= high)
 {
  int mid = (low + high) / 2;
  if (target > v[mid])
  {
   low = mid + 1;
  }
  else if (target < v[mid])
  {
   high = mid - 1;
  }
  else
  {
   if (mid == 0 || v[mid - 1] != v[mid])
   {
    return mid;
   }
   else
   {
    high = mid - 1;
   }
  }
 }
}
// last occurence of the number by recurssive way

int last_occur(vector<int> v, int low, int high, int target)
{

 int n = v.size();
 if (low > high)
  return -1;

 int mid = (low + high) / 2;
 if (target > v[mid])
 {
  return last_occur(v, mid + 1, high, target);
 }
 else if (target < v[mid])
 {
  return last_occur(v, low, mid - 1, target);
 }
 else
 {
  if (mid == n - 1 || v[mid] != v[mid + 1])
   return mid;
  else
   return last_occur(v, mid + 1, high, target);
 }
}
int count_occur(vector<int>v,int target)
{
 int first=firstoccur_iter(v,target);
 if(first==-1) return 0;
 else
  return (last_occur(v,0,v.size()-1,target)-first + 1);
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
 cout << "enter the target element:";
 int target;
 cin >> target;
 // int f_index=firstoccur(v, 0, n - 1, target);
 // cout<<"the first occurence is at "<<f_index;
 int f_index_iter = firstoccur_iter(v, target);
 cout << "the first occurence is at " << f_index_iter << endl;
 cout << "the last occurence is at " << last_occur(v, 0, n - 1, target) << endl;
 cout << "the total occurences are "<<count_occur(v,target);
 return 0;
}