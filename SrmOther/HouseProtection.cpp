#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 

#define SZ(X) ((int)(X.size())) 
const double pi=acos(-1.0); 
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;} 
template<class T> inline T sqr(T x){return x*x;} 

class HouseProtection 
{ 
public: 
	int n,m; 
	bool G[50][50]; 
	int p[50]; 
	bool visited[50]; 
	bool find(int v) 
	{ 
		for (int i=0;i<m;i++) if (G[v][i] && !visited[i]) 
		{ 
			visited[i]=true; 
			if (p[i]<0 || find(p[i]))  
			{ 
				p[i]=v; 
				return true; 
			} 
		} 
		return false; 
	} 
	int solve(vector<int> X1,vector<int> Y1,vector<int> X2,vector<int> Y2,double R) 
	{ 
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) 
			G[i][j]=(sqr(X1[i]-X2[j])+sqr(Y1[i]-Y2[j])<=sqr(R+R)); 
		int result=n+m; 
		memset(p,255,sizeof(p)); 
		for (int i=0;i<n;i++) 
		{ 
			memset(visited,false,sizeof(visited)); 
			if (find(i)) result--; 
		} 
		return result; 
	} 
	double safetyFactor(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, int R) 
	{ 
		n=SZ(X1); 
		m=SZ(X2); 
		double result=0; 
		for (int cnt=1;cnt<=n+m;cnt++) 
		{ 
			double H=0,T=R; 
			for (int step=0;step<100;step++) 
			{ 
				double M=(H+T)/2.0; 
				if (solve(X1,Y1,X2,Y2,M)>=cnt) H=M; 
				else T=M; 
			} 
			checkmax(result,(double)cnt*sqr(H)); 
		} 
		return result*pi; 
	} 
};
