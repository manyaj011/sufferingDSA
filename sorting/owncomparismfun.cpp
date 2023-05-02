#include<bits/stdc++.h>
using namespace std;
class point
{
 public:
  int x,y;
};
bool mycmp(point p1,point p2)
{
 return (p1.x<p2.x);
}
int main()
{
 // point arr[]={{3, 10}, {2, 8}, {5, 4}};
 // int n = sizeof(arr) / sizeof(arr[0]);
 // sort(arr, arr + n, mycmp);
 int n;
 cin>>n;
 vector<point>v(n);
 vector<point>::iterator it;
 for(it=v.begin();it<v.end();it++)
 {
  cin>>it.x>>it.y
 }//how to use???
 for (auto i : arr)
 {
  cout << i.x << " " << i.y << endl;
}
return 0;
}