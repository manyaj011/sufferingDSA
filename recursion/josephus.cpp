#include<bits/stdc++.h>
using namespace std;
int jos(int n, int k)
    {
       if(n==1) return 0;
       else
       return (jos(n-1,k)+k)%n;
    }
int josephus(int n, int k)
    {
       return jos(n,k)+1;
    }
int solve( vector<int> res, int k ,int index)
{
    int size=res.size();
    if(size==1) 
        return res[0];
    index=(index+k-1)%size;
    res.erase(res.begin()+index);
    return solve(res, k, index);

}
int josephusv(int n, int k)
{
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        res.push_back(i+1);
    }
    return solve(res,k,0);
}
int main()
{
    cout<<"enter the number of persons in circle-"; int n; cin>>n;
    cout<<"enter the value of k-"; int k ; cin>>k;
    cout<<"the safest place is "<<josephusv(n,k);

}