//when pivot is last element then partioning acc to pivot

#include <bits/stdc++.h>
using namespace std;
int lomuto(vector<int> v, int l, int h)
{
 int i = l - 1; // index for smaller elements window initially no elements in smaller window
 int pivot = v[h];
 for (int j = l; j < h; j++) // less than h kunki last wale ko to pivot hi maana h usme swapping end m lg ri h
 {
  if (v[j] < pivot) // check if the element is smaller than pivot
  {
   i++; // increment thr size of smaller window to swap the smaller ele
   swap(v[j], v[i]);
  }
 }
 swap(v[i + 1], v[h]);
 for (int i = 0; i < v.size(); i++)
 {
  cout << v[i] << " ";
 }
 cout << endl;
 return (i + 1); // position of pivot
}

// what if the pivot is not the last element , we cn swap the last elemnt by the pivot element by swap(v[pivot_position],v[h])

int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 cout << "the posotion of pivot element is-" << lomuto(v, 0, v.size() - 1);
 return 0;
}