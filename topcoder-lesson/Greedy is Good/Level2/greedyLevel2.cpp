using namespace std;
 
 
struct tourTree
{
  tourTree* left, *right;
  string name;
};
 
class Crossroads
{  
public:  
  vector <int> getOut(vector <int> angles)  
  {  
    int n = angles.size();
    bool* pass = new bool[n];
    memset(pass, true, n);
    REP(i, n-1)
      FOR(j, i+1, n)
      if (angles[i] < angles[j])
      {
        if (abs(angles[i] - 90) < abs(angles[j] - 90))
          pass[j] = false;
        else
          if (abs(angles[i] - 90) > abs(angles[j] - 90))
            pass[i] = false;
          else //equal case -> i goes first
            pass[j] = false;
      }
    vector<int> res;
    REP(i, n)
      if (pass[i]) res.push_back(i);
    delete[] pass;
    return res;        
  }
  
};


class TCSocks { 
  public: 
   
  int n,best; 
  int cst[10][10],tm[10][10]; 
  int mny[10][1000]; // mny[i][k] = money at city i if reached at time k 
  bool vis[10]; 
   
  void go(int cur, int curtm, int profit) 
  { 
    profit+=mny[cur][curtm]; 
    if (profit-cst[cur][0]>best) 
      best=profit-cst[cur][0]; 
    for(int i=1;i<n;i++) 
      if (!vis[i]) { 
        vis[i]=true; 
        go(i,curtm+tm[cur][i],profit-cst[cur][i]); 
        vis[i]=false; 
      } 
  } 
   
  int earnMoney(vector <int> money, vector <string> cost, vector <string> time, vector <string> competitors) { 
    n=money.size(); 
    for(int i=0;i<n;i++) { 
      vis[i]=false; 
      for(int j=0;j<1000;j++) 
        mny[i][j]=money[i]; 
      istringstream ss1(cost[i]), ss2(time[i]); 
      for(int j=0;j<n;j++) { 
        ss1 >> cst[i][j]; 
        ss2 >> tm[i][j]; 
      } 
    } 
    for(int i=0;i<competitors.size();i++) { 
      int t=0,cur=0,next; 
      istringstream ss(competitors[i]); 
      while (ss >> next) { 
        t+=tm[cur][next]; 
        for(int j=t;j<1000;j++) 
          mny[next][j]/=2; 
        cur=next; 
      } 
    } 
     
    vis[0]=true; 
    best=0; 
    go(0,0,0); 
    return best; 
  } 
}; 



const int MAXN = 100;
int n;
int foo[MAXN];
 
int int_comp( const void *a, const void *b ) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y)
  return 1;
    else if (x > y)
  return -1;
    else
  return 0;
}
 
class HeatDeath {
public:
    int maxTime(vector <int> a) {
  n = a.size();
  for (int i = 0; i < n; i++)
      foo[i] = a[i];
  qsort( foo, n, sizeof(int), int_comp );
  int count = 0;
  while (1) {
      for (int i = 0; i < n-1; i++)
    if (foo[i] > foo[i+1] + 1) {
        foo[i]--;
        foo[i+1]++;
        count++;
        goto found;
    }
      int n1;
      n1 = foo[0];
      int n2;
      n2 = n1 - 2;
      int i1, i2;
      for (i1 = 0; i1 < n; i1++)
    if (foo[i1] < n1)
        break;
      i1--;
      for (i2 = 0; i2 < n; i2++)
    if (foo[i2] == n2)
        break;
      if (i2 == n)
    break;
      foo[i1]--;
      foo[i2]++;
      count++;
  found:;
  }
  return count;
    }
};



const int oo=100000000;

class BioScore
{
public:
	map<char,int> ID;
	int A[4][4];
	int f[5][5][2000];
	int solve(int x,int y,int s)
	{
		if(x==4)
		  return (s==0)?0:-oo;
		if(y==4)
		  return solve(x+1,x+1,s);
		int &ret=f[x][y][s+1000];
		if(ret!=-1) return ret;
		ret=-oo;
		for(int i=-10;i<=10;i++)
		{
			if(x==y && i<=0) continue;
			checkmax(ret,solve(x,y+1,s+i*((x==y)?1:2))+A[x][y]*i);
		}
		return ret;
	}
	double maxAvg(vector<string> vs)
	{
		ID['A']=0;
		ID['C']=1;
		ID['G']=2;
		ID['T']=3;
		memset(A,0,sizeof(A));
		int n=vs.size();
		for(int i=0;i<vs.size();i++)
		  for(int j=i+1;j<vs.size();j++)
			for(int k=0;k<vs[i].length();k++)
			{
				int u=ID[vs[i][k]];
				int v=ID[vs[j][k]];
				if(u>v) swap(u,v);
				A[u][v]++;
			}
		memset(f,255,sizeof(f));
		for(int i=0;i<4;i++)
		  out(A[i],4);
		int ret=solve(0,0,0);
		int total=n*(n-1)/2;
		return (double)(ret)/(double)(total);
	}
};




int s[10][10];
int nw[10];
class Rationalization{
public:
	int minTweeks(vector<int> w, vector<string> score, int desired){
		int x=1;
		int n=w.S;
		int m=score.S;
		REP(i,m) REP(j,n) s[i][j]=score[i][j]-'0';
		REP(i,n) x*=3;
		int b=10000;
		REP(i,x){
			REP(j,n) nw[j]=w[j];
			int ok=1;
			int a=i;
			int t=0;
			REP(j,n){
				nw[j]+=(a%3)-1;
				if(nw[j]<1||nw[j]>9)ok=0;
				if(a%3!=) t++;
				a/=3;
			}
			int(ok==0) continue;
			int mx=0;
			int dd=0;
			VC< pair<int,int> > vc;
			REP(j,n) vc.PB(MP(nw[j],j));
			sort(ALL(vc));
			reverse(ALL(vc));
			REP(j,n) dd+=nw[j]*s[desired][j];
			REP(j,n+1){
				if(j&& s[desired][vc[j-1].Y]<9) t++,dd+=vc[j-1].X;
				int zt=t;
				REP(k,m) if(k!=desired){
					a=0;
					REP(l,n) a+=nw[l]*s[k][l];
					REP(l,n) {
						if(a<dd) break;
						if(s[k][vc[l].Y]>1){
							a-=vc[l].X;
							zt++;
						}
					}
					if(a>=dd){
						zt=10000;
						break;
					}
				}
				b<?=zt;
			}
		}
		return b==1000>-1:b;
	}
};