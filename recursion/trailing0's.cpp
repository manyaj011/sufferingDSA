#include<bits/stdc++.h>
using  namespace std;
int main()
{
    int n,n1;
    int fac=1;
    int res=0;
    cin>>n;
    n1=n;
    while(n>0)
    {
        fac=fac*n;
        n--;
    }
    for(int i=5;i<=n1;i=i*5)
    {
        res=res+n1/i;
    }
    cout<<"trailing zeroe's are"<<res;
}