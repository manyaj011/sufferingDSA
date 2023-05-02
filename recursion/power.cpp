#include<iostream>
using namespace std;
long long int poww(long long int n, long long int x, long long int m)
{
    long long int res=1;
    while(n>0)
    {
        if(n & 1)//(n/2!=0)
            res=(res*x)%m;
        x=(x*x)%m;
        n=n>>1;//(n=n/2)
    
    }
    return res;
}
int main()
{
    cout<<poww(4,3,956781);
}