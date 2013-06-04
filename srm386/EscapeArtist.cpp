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
 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
 
const int maxn=25+5;
const int oo=1000;
 
class EscapeArtist
{
public:
    int n;
    bool G[maxn][maxn];
    int D[maxn][maxn];
    double C[maxn][maxn];
    vector<int> path;
    double f[maxn][maxn],r[maxn][maxn];
    double calcL(int s,int t)
    {
        double &r=C[s][t];
        if (r>-1.0) return r;
        if (s==t) return r=1;
        r=0;
        for (int i=0;i<n;i++) if (D[s][i]==1 && D[s][i]+D[i][t]==D[s][t]) r+=calcL(i,t);
        return r;
    }
    double solveC(int s,int t,int d)
    {
        double &r=f[s][t];
        if (r>-1.0) return r;
        if (s==t) return 1.0;
        r=0;
        for (int i=0;i<n;i++) if (D[s][i]==1 && D[s][i]+D[i][t]==D[s][t]) 
        {
            if (d+1<path.size() && i==path[d+1]) 
                continue;
            if (d+1<path.size() && i==path[d] && s==path[d+1]) 
                continue;
            r+=solveC(i,t,d+1);
        }
        return r;
    }
    double getC(int src,int dest)
    {
        double &ret=r[src][dest];
        if (ret>-1.0) return ret;
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) f[i][j]=-2;
        return ret=solveC(src,dest,0);
    }
    double solve(int src,int dest,int p1,int p2,int step)
    {
        int d=D[src][dest];
        if (step>d) 
            return (p2!=dest)?0:1;
        double result=0.0;
        for (int i=0;i<n;i++) if (D[src][i]==step-1)
            for (int j=0;j<n;j++) if (G[i][j] && D[src][i]+1+D[j][dest]==d)
                if (p2==j || (i==p2 && j==p1))
                    result+=getC(src,i)*C[j][dest]/getC(src,dest);
        return result;
    }
  double bestRoute(vector <string> corridors, vector <int> agentStart, vector <int> agentTarget, int start, int finish)
  {
    n=corridors.size();
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) G[i][j]=corridors[i][j]=='1';
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) D[i][j]=oo;
        for (int i=0;i<n;i++) D[i][i]=0;
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (G[i][j]) D[i][j]=1;
        for (int k=0;k<n;k++) for (int i=0;i<n;i++) for (int j=0;j<n;j++) checkmin(D[i][j],D[i][k]+D[k][j]);
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=-2.0;
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) calcL(i,j);
        double result=1.0;
        int nextk=-1,step=0;
        path.clear();
        for (int k=start;k!=finish;k=nextk)
        {
            for (int i=0;i<n;i++) for (int j=0;j<n;j++) r[i][j]=-2.0;
            path.push_back(k);
            step++;
            double bestr=-1.0;
            for (int i=0;i<n;i++) if (G[i][k] && D[i][finish]+1==D[k][finish])
            {
                double p=1.0;
                for (int v=0;v<agentStart.size();v++)
                    p*=(1.0-solve(agentStart[v],agentTarget[v],k,i,step));
                if (p>bestr) bestr=p,nextk=i;
            }
            result*=bestr;
        }
        return 1.0-result;
  }
};
