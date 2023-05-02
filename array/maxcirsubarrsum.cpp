#include<bits/stdc++.h>
using namespace std;
// int csas(int arr[], int n)
// {
//     int res=0;
//     for(int i=0;i<n;i++)
//     {
//         int curr_max=arr[i];
//         int curr_sum=arr[i];
        
//         for(int j=1;j<n;j++)
//         {
//             int index=(i+j)%n;
//             curr_sum+=arr[index];
//             curr_max=max(curr_sum,curr_max);

//         }
//         res=max(res,curr_max);
//     }
//     return res;
// }
int csasopt(int arr[],int n)
{
   int res_max=arr[0],res_min=arr[0];
   int maxending=arr[0],minending=arr[0];
   int arr_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        maxending=max(maxending + arr[i], arr[i]);
        res_max=max(maxending,res_max);
        minending=min(minending + arr[i],arr[i]);
        
        res_min=min(minending,res_min);
        arr_sum+=arr[i];
    }
    // for(int i=0;i<n;i++)
    // {
    //     minending=min(minending + arr[i],arr[i]);
    //     res_min=min(minending,res_min);
    // }
    if(res_max<0)
        return res_max;
    else
        return max(res_max,arr_sum-res_min);
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
    cout<<csasopt(arr,n);

    
}