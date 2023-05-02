#include<bits/stdc++.h>
using namespace std;
void minflips(int arr[], int n )
{
    if(arr[0]==0)
    {
        int i=1;
        while(i<n)
        {
        while(arr[i]!=1 && i<n)
        {
            i++;
        }
        if(i<n)
            cout<<endl<<" from "<<i<<" to ";
        while(arr[i]!=0 && i<n)
        {
            arr[i]==0;
            i++;
        }
        if(i<n)
            cout<<i-1;
        }
    }
    else if(arr[0]==1)
    {
        int i=1;
        while(i<n)
        {
            while(arr[i]!=0 && i<n)
            {
                i++;
            }
            if(i<n)
                cout<<endl<<"from "<<i<<" to ";
            while(arr[i]!=1 && i<n)
            {
                arr[i]==1;
                i++;
            }
            if(i<n)
                cout<<i-1;
        }
    }
}
void minflipsopt(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            if(arr[i]!=arr[0])
                cout<<"from "<<i<<" to ";
            else 
                cout<<(i-1)<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
    {
        cout<<(n-1)<<endl;
    }
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
    // minflips(arr,n);
    minflipsopt(arr,n);
    cout<<endl;
    for(auto i:arr)
    {
        cout<<arr[i]<<" ";
    }
}