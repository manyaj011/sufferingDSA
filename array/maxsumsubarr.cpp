#include<bits/stdc++.h>
using namespace std;
// int maxsumarr(vector<int> v)
// {
//     int size=v.size();
//     int sum;
//     sum=v[0];
   
//     for(int i=0;i<size;i++)
//     {
//         int temp=0;
//         for(int j=i;j<size;j++)
//         {
//             temp=temp+v[j];
//             sum=max(temp,sum);
//         }
//     }
//     return sum;
// }
int maxsumarropt(vector<int> v)
{
     int size=v.size();
     int maxending;
     maxending = v[0];
     int res = v[0]; 
    for(int i=1;i<size;i++)
    {
        maxending=max( maxending + v[i] ,v[i] );
        res=max(res,maxending);
    }
    
    return res;
}
int main()
{
    vector<int>v{8,-4,3,-5,4};
    // cout<<maxsumarr(v);
    cout<<maxsumarropt(v);
}