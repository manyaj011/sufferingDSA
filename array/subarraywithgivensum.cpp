#include<bits/stdc++.h>
using namespace std;
bool subarrsum(int arr[],int n,int given_sum)
{
    
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(given_sum==sum)
                return true;
        }
    }
    return false;
}//TC O(n^2)
bool subarrsumopt(int arr[],int n,int given_sum)
{
    int sum=0,s=0;
    for(int e=0;e<n;e++)
    {
        sum+=arr[e];
        while(given_sum<sum)
        {
            sum-=arr[s];
            s++;
        }
        if(given_sum==sum)
        {
            return true;
        }
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
    int given_sum;
    cout<<"enter the given sum-";
    cin>>given_sum;
    if(subarrsumopt(arr,n,given_sum)==1) cout<<"yes";
    else cout<<"no";
    
}