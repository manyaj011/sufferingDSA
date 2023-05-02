#include<bits/stdc++.h>
using namespace std;
// int trw(vector<int>v)
// {
//     int res=0;
//     int size=v.size();
//     cout<<size<<endl;
//     for(int i=1;i<size-1;i++)
//     {
//         int lmax=v[i];
//         for(int j=0;j<i;j++)
//         {
//             lmax=max(lmax,v[j]);
//         }
//         int rmax=v[i];
//         for(int j=i+1;j<size;j++)
//         {
//             rmax=max(rmax,v[j]);
//         }
//        // res=res+(min(lmax,rmax)-v[i]);
//     }
//     return res;
// }
int trwoptimal(vector<int>v)
{
    int res=0;
    int size=v.size();
    int lmax[size],rmax[size];
    lmax[0]=v[0];
    for(int i=1;i<size;i++)
        lmax[i]=max(v[i],lmax[i-1]);
    rmax[size-1]=v[size-1];
    for(int i=size-2;i>=0;i--)
        rmax[i]=max(v[i],rmax[i+1]);
    for(int i=1;i<size-1;i++)
        res=res+( min(lmax,rmax)-v[i]);
    return res;
}
int main()
{
    vector<int> v{3,0,1,2,5};
    // cout<<trw(v);


}