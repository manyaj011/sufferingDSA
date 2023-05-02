#include<bits/stdc++.h>
using namespace std;
bool equalpart(int arr[] ,int n)
{
    int psum[n],rsum[n];
    psum[0]=arr[0],rsum[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        psum[i]=psum[i-1]+arr[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        rsum[i]=rsum[i+1]+arr[i];
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=n-1;j>=n/2;j--)
        {
            if(psum[i]==rsum[j])
            {
                int sum=0;
                for(int k=i+1;k<j;k++)
                {
                    sum+=arr[k];
                }
                if(sum==psum[i]) return true;
            }
        }
    }
    return false;
}
//O(n^3)


int main()
{
     int n,k;
    cout<<"enter size of array-";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array-";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<equalpart(arr,n);
}