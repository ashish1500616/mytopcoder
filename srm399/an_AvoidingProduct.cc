/**
 author Burunduk2
 240 
*/

#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (_typeof((a).begin()) = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
typedef long long llong;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
 
#define m 10000
 
int u[m];
 
class AvoidingProduct
{
public:
  vector <int> getTriple( vector <int> a, int n )
  {
    memset(u, 0, sizeof(u));
    for (int i = 0; i < a.size(); i++)
      u[a[i]] = 1;
    int bx = -1, by = -1, bz = -1;
    for (int x = 1; bx == -1 || x <= n; x++)
      if (!u[x])
        for (int y = x; bx == -1 || x * y <= 2 * n + 1; y++)
          if (!u[y])
            for (int z = y; bx == -1 || x * y * z <= 2 * n + 1; z++)
              if (!u[z])
                if (bx == -1 || abs(bx * by * bz - n) > abs(x * y * z - n))
                  bx = x, by = y, bz = z;
    vi res;
    res.pb(bx);
    res.pb(by);
    res.pb(bz);
    return res;
  }
};

/**
 Petr
 243
 */

using System; 

public class AvoidingProduct { 
  public int[] getTriple(int[] a, int n) { 
        bool[] ok = new bool[n + 52]; 
        foreach (int u in a) 
            ok[u] = true; 
        int rx = 0; 
        int ry = 0; 
        int rz = 0; 
        int res = int.MaxValue; 
        for (int x = 1; x <= n + 51; ++x) 
            if (!ok[x]) 
                for (int y = x; y <= n + 51; ++y) 
                    if (!ok[y]) 
                        for (int z = y; z <= n + 51; ++z) 
                            if (!ok[z]) 
                            { 
                                int cur = Math.Abs(x * y * z - n); 
                                if (cur < res) 
                                { 
                                    res = cur; 
                                    rx = x; 
                                    ry = y; 
                                    rz = z; 
                                } 
                            } 
        return new int[] { rx, ry, rz }; 
  } 



} 
