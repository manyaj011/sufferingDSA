#include<bits/stdc++.h>
using namespace std;
int getsum(int arr[],int n,int start,int end)
{
    int sum=0;
    for(int i=start;i<=end;i++)
    {
        sum+=arr[i];
    }
    return sum;

}
//theta(end-start+1)
//O(n)

int getsumopt(int arr[], int n, int start, int end)
{
    int psum[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        psum[i]=sum;
    }
    //or
    // psum[0]=arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     psum[i]=psum[i-1];arr[i];
    // }
    if(start==0)
        return psum[end];
    else
        return psum[end]-psum[start-1];
}
int getweightedsumopt(int arr[], int n, int start, int end)
{
    int psum[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+= arr[i];
        psum[i]=sum;
    }
    //or
    // psum[0]=arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     psum[i]=psum[i-1];arr[i];
    // }
    if(start==0)
        return psum[end];
    else
        return psum[end]-psum[start-1];
}
int main()
{   int n;
    cout<<"Enter size of array-";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array-";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<getsumopt(arr,n,0,2)<<" ";
    cout<<getsumopt(arr,n,1,3)<<" ";
    cout<<getsumopt(arr,n,2,6)<<" ";

}
