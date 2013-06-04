/**
 ahmed_aly
 245
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class CircularLine {
public:
  int longestTravel(vector <int>);
};
 
int CircularLine::longestTravel(vector <int> t) {
  int res=-1;
  int tot=0;
  int i;
  for(i=0;i<t.size();i++)
    tot+=t[i];
  for(i=0;i<t.size();i++)
    for(int j=i+1;j<t.size();j++)
    {
      int sum=0;
      for(int k=i;k<j;k++)
        sum+=t[k];
      res=max(res,min(sum,tot-sum));
    }
  return res;
}