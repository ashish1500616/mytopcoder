#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> diff(string s)
{
  int r=0, g=0, b=0, y=0;
  for (int i=0;i<s.size();i++) {
    switch(s[i]) {
      case 'R':
        r++;
        break;
      case 'G':
        g++;
        break;
      case 'B':
        b++;
        break;
      case 'Y':
        y++;
        break;
    }
  }
  vector<int> ret;
  ret.push_back(r);
  ret.push_back(g);
  ret.push_back(b);
  ret.push_back(y);
}

class NinePuzzle
{
public:
  int getMinimumCost(string init, string goal) {
    vector<int> a = diff(init);
    vector<int> b = diff(goal);
    int ret=0;
    for (int i=0;i<a.size();i++) {
      ret=ret+fabs(a[i]-b[i]);
    }
    return ret/2;
  }
};

///////////////////////////
class PoxStones {
public:
  int getCount(int N, int M, vector<int> sx, vector<int> sy) {
    int res;
    map< vector<int>, int> cnt;
    for(int row=1; row<=M; row++) {
      for (int col=1;col<=N;col++) {
        vector<int> dists;
        for(int i=0;i<sx.size();i++) {
          int dist=max(abs(sx[i]-col), abs(sy[i]-row));
          dists.push_back(dist);
        }
        cnt[dists]++;
      }
    }
    res=1;
    vector<int> fact(N*N+1,1);
    for(int i=2;i<=N*N;i++) {
      fact[i]=(ll(fact[i-1]*i)%MOD;
    }
    for(int map<vector<int>, int>::const_iterator it = cnt.begin();it!=cnt.end; it++) {
      res=(ll(res)*fact[it->second])%MOD;
    }
    return res;
  }
};