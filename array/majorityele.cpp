#include<bits/stdc++.h>
using namespace std;
int majele(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int count = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count ++;
            }
        }

        if(count>n/2)
                return i;
    }
    return -1;
}
int majeleopt(int arr[], int n)
{
    int count =1; int res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[res]==arr[i])
            count++;
        else
            count--;
        if(count==0)
        {
            count=1;
            res=i;
        }
            
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[res]==arr[i])
        {
            count++;
        }
        if(count>n/2)
        {
            return res;
        }
    }
    return -1;
}
int main()
{
   int n;
    cout<<"enter size of array-";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array-";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<majeleopt(arr,n); 
}
