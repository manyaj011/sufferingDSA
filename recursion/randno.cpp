#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number;
    int i,c=1;

    srand(time(0));
    number = rand() % 1000;
    cout<<number<<endl;
    //cout<<"Guess the Number";
    //cin>>i;
    while(i!=number)
    {
    cout<<"Guess the Number again";
    cin>>i;
    cout<<endl;
    if(i>number)
    {
        cout<<"LOWER NUMBER PLEASE"<<endl;
        c++;
    }
    else if(i<number)
    {
        cout<<"HIGHER NUMBER PLEASE"<<endl;
        c++;
    }
    }
        cout<<" you took "<< c << "chances to guess the correct number";
}