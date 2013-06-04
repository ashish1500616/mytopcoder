/**
	author tomek
	415 500
	*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
typedef long long LL;
const LL INFLL = 1000000000000000000LL;
 
int length(LL a) {
  int res = 0;
  while(a) { a>>=1; ++res; }
  return res;
}
 
int ones(LL a) {
  int res = 0;
  while(a) {
    if(a&1) ++res;
    a>>=1;
  }
  return res;
}
 
LL cache[32][32][32][32][2];
 
LL calc(int n, int a,int b,int c,int cc) {
  if(a<0 || b<0 || c<0) return INFLL;
  LL &res = cache[n][a][b][c][cc];
  if(res!=-1) return res;
  res = INFLL;
  if(n==0) {
    if(a==0 && b==0 && c==0 && cc==0) res = 0;
    else res = INFLL;
  }
  else {
    REP(x,2) REP(y,2) {
      int z = x+y+cc;
      int cc2 = 0;
      if(z>=2) { z-=2; ++cc2; }
      LL v = 2 * calc(n-1, a-x, b-y, c-z, cc2) + z;
      res = min(res, v);
    }
  }
  return res;
}
 
struct BinarySum {
int rearrange(int a, int b, int c) {
  memset(cache,-1,sizeof(cache));
  int n = max(length(a),max(length(b),length(c)));
  LL res = calc(n, ones(a), ones(b), ones(c),0);
  if (res==INFLL) res = -1;
  return int(res);
}
 
};

/**
	author petr
	433 500
	*/

using System; 

public class BinarySum { 
  public int rearrange(int a, int b, int c) { 
        int na, nb, nc, ka, kb, kc; 
        process(a, out na, out ka); 
        process(b, out nb, out kb); 
        process(c, out nc, out kc); 
        int n = Math.Max(na, Math.Max(nb, nc)); 
        bool[, , ,,] can = new bool[n + 1, 2, ka + 1, kb + 1, kc + 1]; 
        int[,,,,] by = new int[n + 1, 2, ka + 1, kb + 1, kc + 1]; 
        can[0, 0, 0, 0, 0] = true; 
        int res = int.MaxValue; 
        for (int len = 1; len <= n; ++len) 
        { 
            for (int da = 0; da <= 1; ++da) 
                for (int db = 0; db <= 1; ++db) 
                    for (int pcarry = 0; pcarry <= 1; ++pcarry) 
                    { 
                        int s = da + db + pcarry; 
                        int dc = s % 2; 
                        int carry = s / 2; 
                        for (int ma = da; ma <= ka; ++ma) 
                            for (int mb = db; mb <= kb; ++mb) 
                                for (int mc = dc; mc <= kc; ++mc) 
                                    if (can[len - 1, pcarry, ma - da, mb - db, mc - dc]) 
                                    { 
                                        int cby = by[len - 1, pcarry, ma - da, mb - db, mc - dc] + (dc << (len - 1)); 
                                        if (!can[len, carry, ma, mb, mc] || by[len, carry, ma, mb, mc] > cby) { 
                                            can[len, carry, ma, mb, mc] = true; 
                                            by[len, carry, ma, mb, mc] = cby; 
                                            if (len == n && ma == ka && mb == kb && mc == kc && carry == 0) 
                                                res = Math.Min(res, cby); 
                                        } 
                                    } 
                    } 
        } 
        if (res == int.MaxValue) 
            res = -1; 
        return res; 
    } 

    void process(int x, out int n, out int k) 
    { 
        n = 0; 
        k = 0; 
        while (x > 0) 
        { 
            ++n; 
            if (x % 2 != 0) 
                ++k; 
            x /= 2; 
        } 
    } 

   

} 
