#include<bits/stdc++.h>
using namespace std;

int minNumber(int arr[],int n, int low, int high)
{

  if(low>high) return -1;

  int mid = (low + high) / 2;

  if (arr[low] < arr[high])
    return arr[low];
  if (arr[high] == arr[low])
    return arr[low];
  if (arr[mid + 1] < arr[mid] && mid < high)
    return arr[mid + 1];
  if (arr[mid] < arr[mid - 1] && mid > low)
    return arr[mid];
  if (arr[high] > arr[mid])
    return minNumber(arr, n,low, mid - 1);
  else
    return minNumber(arr,n, mid + 1, high);
}
int main()
{
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
cin >> arr[i];
}
cout<<minNumber(arr,n,0,n-1);
return 0;
}


