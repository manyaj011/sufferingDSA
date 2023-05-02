#include <bits/stdc++.h>
using namespace std;
class myhash
{
public:
  int *arr; // declaring a pointer that points to base address of the array
  int cap, size;
  myhash(int c)
  {
    arr = new int[c];
    cap = c;
    size = 0;
    for (int i = 0; i < cap; i++)
    {
      /* code */
      *(arr + i) = -1; // setting all the elements to -1 initially -1 shows space here
    }
    cout << "object created";
  }
  int hash(int key)
  {
    return (key % cap);
  } // why bracket na lgane p error aara h?

  bool search(int key)
  {
    int h = hash(key);
    int i = h;
    while (arr[i] != -1) // hm isme deleted m stop nhi kr rhe vrna arr[i]!=-2 bhi cond set krte
    {
      /* code */
      if (arr[i] == key)
        return true;
      i = (i + 1) % cap;
      if (i == h)
        return false;
    }
    return false;
  }
  bool insert(int key)
  {
    // conditions jhaan p insert nhi hoga
    //  1.cap full ho ya phr
    //  2.key already present ho
    if (size == cap)
      return false;
    int i = hash(key);
    while (arr[i] != -1 && arr[i] != -2 && arr[i] != key) // jb tk -1 nhi h ele ya -2 nhi h y key ke equal nhi h tb calue ko ins=crease krte jao
    {
      i = (i + 1) % cap;
    }
    // jese hi arr[i] == key hua mtlb key already present h
    if (arr[i] == key)
      return false;
    // agr arr[i] -1 ya -2 ke equal h
    else
    {
      arr[i] = key;
      size++;
      return true;
    }
  }
  bool erase(int key)
  {
    int h = hash(key);
    int i = h;
    // delete hm kr skte h tb jb key present ho
    //  key present nhi ho to del nhi vo tb hb dobara h p aajae ya phr koi space aa jae tb mtlb key present nhi h
    while (arr[i] != -1)
    {
      if (arr[i] == key)
      {
        arr[i] = -2;
        return true;
      }
      i = (i + 1) % cap;
      if (i == h)
        return false;
    }
    // agr arr[i]==-1 hogye to  return false
    return false;
  }
};
int main()
{
  myhash obj(7);
  cout << obj.insert(49) << endl;
  cout << obj.insert(50);
  cout << obj.insert(63);
  cout << obj.insert(64);
  cout << obj.insert(69);
  cout << obj.insert(68);
  cout << obj.search(49);
  cout << obj.search(69);
  cout << obj.erase(69);
  cout << obj.search(69);
  return 0;
}