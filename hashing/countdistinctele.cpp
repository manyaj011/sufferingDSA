#include<bits/stdc++.h>
using namespace std;
int countDistinct(int *arr,int n)
{
 // unordered_set<int>s;
 // for(int i=0;i<n;i++)
 //  s.insert(arr[i]);

 // alternative short way
 unordered_set<int>s (arr,arr+n);
 // arr points to the first address and arr+n points to the address after the last element 
 return s.size();
}
//tc is theta(n) as is O(n)
int main()
{
 int arr[]={10,20,10,20,30};
 cout<<countDistinct(arr,5);
}