#include<bits/stdc++.h>
using namespace std;
void leftrotate(int arr[],int n)
{ 
    int temp = arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
void leftrotateopt(int arr[], int n,int d)
{
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++)
    {
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++)
    {
        arr[n-d+i]=temp[i];
    }
}
int main()
{
    
    int arr[]={10,5,30,15};
    /*int d;
    cin>>d;    
    for(int i=0;i<d;i++)
    {
        leftrotate(arr,4);
    }*/
    leftrotateopt(arr,4,2);
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
}