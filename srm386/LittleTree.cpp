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

vector <vector<int> > tbl; 
vector <int> h; 
vector <int> len; 
int val = 0; 
int norm; 
void go(int x) 
{ 
  for (int i = 0; i < tbl[x].size(); ++i) 
  { 
    int dst = tbl[x][i]; 
    h[dst] = h[x] + 1; 
    go(dst); 
    len[x] = max(len[x], 1 + len[dst]); 
  } 
} 
void go1(int x) 
{ 
  int maxh = h[x] + len[x]; 
  int need = max(0, maxh - norm); 
  int can = max(h[x] - 1, 0); 
  int add = min(can, need); 
  debug(x); 
  debug(maxh); 
  debug(need); 
  debug(can); 
  val += add; 
  h[x] -= add; 
  for (int i = 0; i < tbl[x].size(); ++i) 
  { 
    int dst = tbl[x][i]; 
    h[dst] = h[x] + 1; 
    go1(dst); 
  } 
} 
class LittleTree 
{ 
public: 
  int minCost(int n, vector <string> edges, int height) 
  { 
    norm = height; 
    tbl.resize(n); 
    string s; 
    for (int i = 0; i < edges.size(); ++i) s += edges[i]; 
    istringstream c(s); 
    int f; 
    while (c >> f) 
    { 
      char cc; 
      c >> cc; 
      int l; 
      c >> l; 
      tbl[f].pb(l); 
      debug(f); 
      debug(l); 
    } 
    h.resize(n); 
    len.assign(n, 0); 
    h[0] = 0; 
    go(0); 
    for (int i = 0; i < n; ++i) debug(h[i]); 
    for (int i = 0; i < n; ++i) debug(len[i]); 
    go1(0); 
    return val; 
  } 
};