char valid[1<<10]; 

class CandidateKeys { 
public: 
  vector <int> getKeys(vector <string> table) { 
    int n = table[0].size(); 
    int N = 1<<n; 
    memset(valid, 1, sizeof(valid)); 
    int minv = n+1, maxv = -1; 
    for (int i=1; i<N; ++i) { 
      if (!valid[i]) 
        continue; 
      vector<string> entries(table.size()); 
      for (int j=0; j<n; ++j) { 
        if ((1<<j) & i) 
          for (int k=0; k<(int)table.size(); ++k) 
            entries[k] += table[k][j]; 
      } 
      set<string> bla; 
      for (int j=0; j<(int)entries.size(); ++j) 
        bla.insert(entries[j]); 
      if (bla.size() != entries.size()) 
        continue; 
      int len = entries.back().size(); 
      if (len > maxv) 
        maxv = len; 
      if (len < minv) 
        minv = len; 
      for (int j=i+1; j<N; ++j) 
        if ((i&j) == i) 
          valid[j] = 0; 
    } 
    vector<int> res; 
    if (minv > maxv) 
      return res; 
    res.push_back(minv); 
    res.push_back(maxv); 
    return res; 
  } 
}; 






#include <algorithm> 
#include <cmath> 
#include <iostream> 
#include <limits> 
#include <list> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 
using namespace std; 

#define debug(c) cout << "> " << #c << " = " << c << endl; 
#define forn(i, a, b) for (int i = (int)(a); i < int(b); ++i) 
#define rep(i, n) for (int i = 0; i < (int)(n); ++i) 
#define repsz(i, c) for (int i = 0; i < (int)(c.size()); ++i) 
#define all(x) (x).begin(), (x).end() 
#define mp make_pair 
#define pb push_back 
#define inf(type) numeric_limits<type>::max() 
typedef pair<int, int> PI; 
typedef vector<PI> VPI; 
typedef long long ll; 

int count(int x) 
{ 
  int r = 0; 
  while (x) 
  { 
    if (x % 2 == 1) ++r; 
    x /= 2; 
  } 
  return r; 
} 
class CandidateKeys 
{ 
public: 
  vector <int> getKeys(vector <string> tbl) 
  { 
    int n = tbl[0].size(); 
    vector <int> pos; 
    for (int i = 0; i < (1 << n); ++i) 
    { 
      bool norm = true; 
      set<string> t; 
      for (int j = 0; j < tbl.size(); ++j) 
      { 
        string x; 
        for (int k = 0; k < n; ++k) 
          if (i & (1 << k)) x += tbl[j][k]; 
        if (t.find(x) != t.end()) norm = false; 
        else t.insert(x); 
      } 
      if (norm) pos.pb(i); 
    } 
    for (int i = 0; i < pos.size(); ++i) debug(pos[i]); 
    for (int i = 0; i < pos.size();) 
    { 
      bool gd = true; 
      for (int j = 0; j < pos.size(); ++j) 
      { 
        if (j != i && (pos[i] & pos[j]) == pos[j]) 
        { 
          gd = false; 
          break; 
        } 
      } 
      if (!gd) 
      { 
        swap(pos[i], pos[pos.size() - 1]); 
        pos.pop_back(); 
      } 
      else ++i; 
    } 
    vector <int> r; 
    if (pos.empty()) return r; 
    int minv = 100; 
    int maxv = -1; 
    for (int i = 0; i < pos.size(); ++i) 
    { 
      int num = count(pos[i]); 
      minv = min(minv, num); 
      maxv = max(maxv, num); 
    } 
    r.pb(minv);r.pb(maxv); 
    return r; 
  } 
};
