#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res==0 && b%res==0)
        {
            break;
        }
        res--;
    }
    return res;
}
//optimised
int gcdo(int a,int b)
{
    if(b==0) return a;
    else return gcdo(b,a%b);
}
int lcm(int a,int b)
{
    return (a*b)/gcdo(a,b);
}
int main()
{
    cout<<gcdo(10,15)<<endl;
    cout<<lcm(4,6);


}