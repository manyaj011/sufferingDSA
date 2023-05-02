#include <bits/stdc++.h>
using namespace std;
void printfreq(int *arr, int n)
{
 for (int i = 0; i < n; i++)
 {
  bool flag = false;
  // to check if for ex 20 pehle aa chuka h ya nhi agr aa chuka h mtlb vo print hogya uski total freq saath
  for (int j = 0; j < i; j++)
  {
   if (arr[i] == arr[j])
   {
    flag = true;
    break;
   }
  }
  if (flag == true)
   continue;
  // agr arr[i] pehle nhi aaya mtlb pehli baar aarha h to freq 1 p set krdi
  int freq = 1;
  for (int j = i + 1; j < n; j++)
  {
   if (arr[i] == arr[j])
   {
    freq++;
   }
  }
  cout << arr[i] << " "
       << "frequency:" << freq << endl;
 }
}
// gc O(n^2) as O(1)
// for linear time complexity we use hashmap
void hashmap(int arr[], int n)
{
 unordered_map<int, int> m;
 for (int i = 0; i < n; i++)
 {
  /* code */
  m[arr[i]]++;
  //this [] bracket will insert ele if not present previously with default value as zero ++ then indicates value is now 1 
  //if the elemnt is again found then map will access that key and change the value to ++ the previous value 
 }
 //this for loop will print in any order 
 for(auto e:m)
  cout<<e.first<<" "<<e.second<<endl;
  //this for loop will print in the order as mentioned in the array
 for (int i = 0; i < n; i++)
 { 
  /* code */
  if(m[arr[i]]!=-1)
  {
  cout<<arr[i]<<" "<<m[arr[i]]<<endl;
  m[arr[i]]==-1;
  }
 }
 //to avoid duplicates you can mark the freq as -1 or value as -1//error?
}
//tc is theta(n) as O(n)
int main()
{
 int arr[] = {10, 20, 20, 30, 10};
 // printfreq(arr, 5);
 hashmap(arr,5);
}