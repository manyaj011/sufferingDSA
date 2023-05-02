#include<bits/stdc++.h>
using namespace std;
int maxsum(int arr[],int n, int k)
{
    
  int res=0;
     int sum=0;   
        for(int i=0;(i+k-1)<n;i++)
        {
            int sum=0;
            for(int j=0;j<k;j++)
                sum+=arr[i+j];
            res=max(res,sum);
        }
        
    return res;
}//TC:O(n*k)
//AS:O(1)


//OPTIMAL APPROACH
int maxsumopt(int arr[],int n,int k)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    int res=sum;
    for(int i=0;i+k<n;i++)
    {
        sum=sum-arr[i]+arr[i+k];
        res=max(res,sum);
    }
    return res;
}
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
    cout<<"enter the value of k-";
    cin>>k;
    cout<<maxsumopt(arr,n,k);
}