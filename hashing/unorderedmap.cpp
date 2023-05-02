#include <bits/stdc++.h>
using namespace std;
int main()
{
 // unordered map doesnt have any order bw theie elements and uses hashing to store data
 unordered_map<string, int> m;
 m["gfg"] = 20; // this square bracket are member access operator and is used both for insertiona nd accessing like if fgf key is present it will provide its value to 20 and if not presdet then it will make gfg and points to 20
 m["ide"] = 30;
 m.insert({"courses", 15});
 for (auto x : m)
  cout << x.first << " " << x.second << endl;
 // since it is unordered any key can be printed first
 auto it = m.find("ide");
 if (it != m.end())
  cout << "found"
       << " " << it->second << endl;
 else
  cout << "not found \n";
 for (auto it = m.begin(); it != m.cend(); it++)
 {
  cout << it->first << " " << it->second << endl;
 }
 if (m.count("ide") > 0)
  cout << "found \n";
 else
  cout << "not found \n";
 cout << m.size() << endl;
 m.erase(m.begin());
 m.erase("ide");
 cout << m.size() << endl;
 m.erase(m.begin(), m.end());
 cout << m.size() << endl;
 // tc of begin() end() size() empty() O(1)
 //  tc of count() find() [] at -search in hashing so O(1) erase(key)(delete in O(1)) insert() as in hashing  O(1)
 return 0;
}