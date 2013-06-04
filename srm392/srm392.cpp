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
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end() 
#define mp make_pair 
#define pb push_back 
#define tr(c,i) for(typeof((c).begin() i=(c).begin(); i!=(c).end();i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(all(c),x)!=(c).end())
typedef vector<int> vi; 
typedef pair<int,int> ii;
typedef long long ll; 

int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
class AverageCandyLifetime{
public:
	double getAverage(vector <int> eatenCandies)
	{
		int n=sz(eatenCandies);
		int num=0;
		int cur=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cur+=m[i];
			sum+=eatenCandies[i]*cur;
			num+=eatenCandies[i];
		}
		double res=(double)sum/num;
		debug(sum)
		debug(num)
		return res;
	}
};



#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;
#define IM "impossible"
class TwoStringMasks {
  public:
    string shortestCommon(string s1, string s2) {
      int i, j;
      string ret;
      while (s1[0] != '*' && s2[0] != '*') {
        if (s1[0] != s2[0])
          return IM;
        ret += s1[0];
        s1 = s1.substr(1, s1.length() - 1);
        s2 = s2.substr(1, s2.length() - 1);
      }
      string tmp;
      while (s1[s1.length() - 1] != '*' && s2[s2.length() - 1] != '*') {
        if (s1[s1.length() - 1] != s2[s2.length() - 1])
          return IM;
        tmp = s1[s1.length() - 1] + tmp;
        s1 = s1.substr(0, s1.length() - 1);
        s2 = s2.substr(0, s2.length() - 1);
      }
      if (s1 == "*") {
        string tmp2 = s1;
        s1 = s2;
        s2 = tmp2;
      }
      if (s2 == "*") {
        for (i = 0; i < s1.length() - 1; i ++)
          if (s1[i] == '*')
            break;
        return (ret + s1.substr(0, i) + s1.substr(i + 1, s1.length() - i - 1) + tmp);
      }
      if (s1[0] != '*') {
        string tmp2 = s1;
        s1 = s2;
        s2 = tmp2;
      }
      for (i = 0; i < s2.length(); i ++) {
        if (s2.length() - 2 - i + 1 >= s1.length())
          continue;
        for (j = i; j < s2.length() - 1; j ++)
          if (s1[j - i + 1] != s2[j])
            break;
        if (j >= s2.length() - 1)
          return (ret + s2.substr(0, i) + s1.substr(1, s1.length() - 1) + tmp);
      }
    }
};
