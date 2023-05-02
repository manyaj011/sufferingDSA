#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2 == 0|| n%3 ==0) return false;
    int i=2;
    while(i*i<=n)
    {
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void primefac(int n)
{
    int i=2;
    while(i<n)
    {
    if(n%i==0)
    {
        if(isprime(i))
            cout<<i<<" ";
    }
    i++;
    }
}//why is it printing 4
int main()
{
    primefac(12);
}