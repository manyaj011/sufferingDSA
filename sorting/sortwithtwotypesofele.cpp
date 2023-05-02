#include<bits/stdc++.h>
using namespace std;
void sort_an_Array_with_two_types(int arr[],int n ,int l,int h)
{
 int i=l-1;
 int j=h+1;
 do
 {
  i++;
 } while (arr[i]<0);
 do
 {
  j++;
 } while (arr[j]>0);
 if(i>=j) return;
 swap(arr[i],arr[j]);
}
void print(int arr[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<arr[i]<<" ";
 }
}
int main()
{
int n;
cin>>n;
// vector<int> v(n);
int arr[n];
for (int i = 0; i < n; i++)
{
cin >> arr[i];
}
sort_an_Array_with_two_types(arr,n,0,n-1);
print(arr,n);
return 0;
}