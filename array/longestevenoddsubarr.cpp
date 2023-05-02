#include<bits/stdc++.h>
using namespace std;
int leos(int arr[], int n)
{
    int res=1;
    for(int i=0;i<n;i++)
    {
        int curr=1;
        for(int j=i+1;j<n;j++)
        {
            if ( (arr[j]%2 == 0 && arr[j-1]%2 !=0) || (arr[j]%2 != 0 && arr[j-1]%2 == 0) )
                curr++;
            else break;
        }
        res=max(res,curr);
    }
    return res;
}
int leosopt(int arr[],int n)
{
    int res=1;
    int curr=1;
    for(int i=1;i<n;i++)
    {
        if ( (arr[i]%2 == 0 && arr[i-1]%2 !=0) || (arr[i]%2 != 0 && arr[i-1]%2 == 0) )
        {
            curr++;
            res=max(curr,res);
        }
        else
            curr=1;
    }
    return res;
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
    cout<<"max even odd sub array length is-"<<leosopt(arr,n);
}