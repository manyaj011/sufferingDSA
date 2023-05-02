 #include<bits/stdc++.h>
using namespace std;
int maxAppear(int left[],int right[],int n)
{
 int freq[100]={0};
 for(int i=0;i<n;i++)
 {
  for(int j=left[i];j<=right[i];j++)
  {
   freq[j]+=1;
  }
 }
 int res=0;
 for(int i=0;i<100;i++)
 {
  if(freq[i]>freq[res])
   res=i;
 }
 return res;
}//OPTIAML APPROACH
int maxAppearopt(int left[],int right[],int n)
{
  int freq[100]={0};
 for(int i=0;i<n;i++)
 {
  freq[left[i]]==1;
  freq[right[i]+1]=-1;
 }
 int psum[100];
 psum[0]=freq[0];
 int res=0;
 for(int i=1;i<100;i++)
 {
  psum[i]=freq[i]+psum[i-1];
  if(freq[i]>freq[res])
   res=i;
 }
 return res;
 // vector<int>psum(100);
 // psum[0]=freq[0];
 // for(int i=1;i<100;i++)
 // {
 //  psum[i]=freq[i]+psum[i-1];
 // }
 // sort(psum.begin(),psum.end());
 // return psum[99];


}
int main()
{
 int n;
    cout<<"enter size of array-";
    cin>>n;
    int larr[n],rarr[n];
    cout<<"enter elements of left_array-";
    for(int i=0;i<n;i++)
    {
        cin>>larr[i];
    }
    cout<<"enter elements of right_array-";
    for(int i=0;i<n;i++)
    {
        cin>>rarr[i];
    }

    cout<<maxAppear(larr,rarr,n);

}