/**
 SRM399
 author crazyb0y
 1000 858
*/

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
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;
 
struct DancingParty{
  int maxDances(vector <string> likes, int k);
};
class Graph{
private:
  struct edge{
    int to,cap,back;
  };
  vector<vector<edge> > adj;
  int n;
public:
  Graph(int n):n(n){
    adj.resize(n);
    for(int i=0;i<n;i++)
      adj[i].clear();
  }
  ~Graph(){
    for(int i=0;i<n;i++)
      adj[i].clear();
    adj.clear();
  }
  void insert(int i,int j,int c){
    adj[i].push_back((edge){j,c,adj[j].size()});
    adj[j].push_back((edge){i,0,adj[i].size()-1});
  }
  int dinic(int s,int t){
    int q[n],prev[n];
    int allflow=0;
    while(true){
      memset(prev,-1,sizeof(prev));
      int qf=0,qb=0;
      prev[q[qb++]=s]=-2;
      while(qb>qf&&prev[t]==-1)
        for(int u=q[qf++],i=0,v;i<adj[u].size();i++)
          if(prev[v=adj[u][i].to]==-1&&adj[u][i].cap>0)
            prev[q[qb++]=v]=adj[u][i].back;
      if(prev[t]==-1)
        break;
      for(int i=0,z;i<adj[t].size();i++)
        if(adj[z=adj[t][i].to][adj[t][i].back].cap>0&&prev[z]!=-1){
          int flow=adj[z][adj[t][i].back].cap;
          for(int v=z,u=prev[v];u>=0;v=adj[v][u].to,u=prev[v])
            flow<?=adj[adj[v][u].to][adj[v][u].back].cap;
          if(!flow)
            continue;
          adj[z][adj[t][i].back].cap-=flow;
          adj[t][i].cap+=flow;
          for (int v=z,u=prev[v];u>=0;v=adj[v][u].to,u=prev[v]){
            adj[adj[v][u].to][adj[v][u].back].cap-=flow;
            adj[v][u].cap+=flow;
          }
          allflow+=flow;
        }
    }
    return allflow;
  }
};
int DancingParty::maxDances(vector <string> G, int k){
  int n=G.size();
  int s=n*4,t=n*4+1;
  int lo=0,hi=n,mid;
  while(lo<hi){
    mid=lo+hi>>1;
    Graph flow(n*4+2);
    for(int i=0;i<n;i++){
      flow.insert(s,i,mid+1);
      flow.insert(i,i+n,k);
      flow.insert(i+n+n,i+n+n+n,k);
      flow.insert(i+n+n+n,t,mid+1);
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(G[i][j]=='Y')
          flow.insert(i,j+n+n+n,1);
        else
          flow.insert(i+n,j+n+n,1);
    if(flow.dinic(s,t)==(mid+1)*n)
      lo=mid+1;
    else
      hi=mid;
  }
  return lo;
}


/**
	author petr
	896 1000
	*/
	
using System; 

public class DancingParty { 
  public int maxDances(string[] likes, int k) { 
        int n = likes.Length; 
        int ret = 0; 
        for (int res = 1; res <= n; ++res) 
        { 
            int[,] g = new int[2 * n + 3, 2 * n + 3]; 
            for (int i = 0; i < n; ++i) 
            { 
                g[2 * n, i] = res; 
                g[i, 2 * n + 2] = k; 
                g[i + n, 2 * n + 1] = res; 
                g[2 * n + 2, i + n] = k; 
                for (int j = 0; j < n; ++j) 
                { 
                    if (likes[i][j] == 'Y') 
                        g[i, j + n] = 1; 
                } 
            } 
            if (flow(g, 2 * n + 3, 2 * n, 2 * n + 1) == res * n) 
                ret = res;             
        } 
        return ret; 
  } 

    private int flow(int[,] g, int n, int s, int t) 
    { 
        int res = 0; 
        bool[] mark = new bool[n]; 
        while (true) 
        { 
            for (int i = 0; i < n; ++i) 
                mark[i] = false; 
            int by = dfs(g, n, s, t, int.MaxValue, mark); 
            res += by; 
            if (by == 0) 
                break; 
        } 
        return res; 
    } 

    private int dfs(int[,] g, int n, int s, int t, int by, bool[] mark) 
    { 
        if (s == t) 
            return by; 
        mark[s] = true; 
        for (int i = 0; i < n; ++i) 
            if (g[s, i] > 0 && !mark[i]) 
            { 
                int b = dfs(g, n, i, t, Math.Min(by, g[s, i]), mark); 
                if (b > 0) 
                { 
                    g[s, i] -= b; 
                    g[i, s] += b; 
                    return b; 
                } 
            } 
        return 0; 
    } 


} 
