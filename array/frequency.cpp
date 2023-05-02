#include<bits/stdc++.h>
using namespace std;
void frequency(vector<int> v)
{
    int size=v.size();
    int freq=1;
    int i=1;
    while(i<size)
    {
        while(i<size && v[i]==v[i-1])
        {
            freq++;
            i++;
        }
        cout<<"the frequency of "<<v[i-1]<<" is "<<freq<<endl;
        i++;
        freq=1;

    }
    if(size==1 || v[size-1]!=v[size-2])
    {
        cout<<"the frequency of "<<v[i]<<" is "<<freq<<endl;
    }
}
int main()
{
    int n,a;
    cin>>n;
    vector<int>v(n);
    for(int i=0 ; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    frequency(v);
}