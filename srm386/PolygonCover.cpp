#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 
using namespace std;
typedef double real;
const int MaxN = 16, MaxL = 1 << MaxN;
const real MaxC = 1E25;
 
class PolygonCover
{
private:
 real f [MaxL];
 
 inline real area (real x1, real y1, real x2, real y2, real x3, real y3)
 {
  return (x1 - x2) * (y1 + y2) + (x2 - x3) * (y2 + y3) + (x3 - x1) * (y3 + y1);
 }
 
public:
 double getArea (vector <int> x, vector <int> y)
 {
  int i, j, k, l, m, n, p;
  real g;
  n = x.size ();
  assert (n == y.size ());
  m = 1 << n;
  f[0] = 0.0;
  for (i = 1; i < m; i++)
   f[i] = MaxC;
  for (i = 0; i < m; i++)
  {
   for (j = 0; j < n; j++)
    for (k = j + 1; k < n; k++)
     for (l = k + 1; l < n; l++)
     {
      p = i | (1 << j) | (1 << k) | (1 << l);
      g = fabs (area (x[j], y[j], x[k], y[k], x[l], y[l]));
      if (f[p] > f[i] + g)
       f[p] = f[i] + g;
     }
  }
  return f[m - 1] * 0.5;
 }
};
