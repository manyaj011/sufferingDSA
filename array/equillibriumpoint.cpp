#include<bits/stdc++.h>
using namespace std;
bool epoint(int arr[], int n)
{
    
    for(int i=0;i<n;i++)
    {
        int ls=0,rs=0;
        for(int j=0;j<i;j++)
        {
            ls+=arr[j];
        }
        for(int k=i+1;k<n;k++)
        {
            rs+=arr[k];
        }
        if(rs==ls)
            return true;
    }
    return false;
}
//TC=O(n^2)
//AS=O(1)

//OPTIMAL SOLUTION

bool epointopt(int arr[], int n)
{
    int psum[n],rsum[n];
    psum[0]=arr[0];
    rsum[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        psum[i]=arr[i]+psum[i-1];
    }

    for(int i=n-2;i>=0;i--)
    {
        rsum[i]=arr[i]+rsum[i+1];
    }
    for(int i=1;i<n-1;i++)
    {
        if(psum[i-1]==rsum[i+1])
            return true;
        //for corner elements->
        if(psum[1]==0 || rsum[n-2]==0)
            return true;
    }
    return false;
}

//in two traversals

bool epointoptt(int arr[],int n)
{
    int res=0;
    int ls=0;
    for(int i=0;i<n;i++)
    {
        res+=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        res-=arr[i];
        if(ls==res) return true;
        ls+=arr[i];
    }
    return false;
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
    cout<<epointoptt(arr,n);
}