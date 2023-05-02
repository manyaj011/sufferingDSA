#include<bits/stdc++.h>
using namespace std;
bool prime(int a)
{
    if(a==1) return false;
    if(a==2 || a==3) return true;
    if(a%2==0 || a%3==0) return false;

    int i=5;
    while(i*i<=a)
    {
        if(a%i==0 || a%(i+2)==0) return false;
        i=i+6;
    }
    return true;
}
int main()
{
    cout<<prime(7)<<endl;
    cout<<prime(121);
}