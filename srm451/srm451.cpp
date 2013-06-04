class ReverseMagicalSource{
public:
	int find(int source,int A)
	{
		int ret=source;
		int time=1;
		while(ret<A)
		{
			time=10*time+1;
			ret=source*time;
		}
		return ret;
	}
}

class BoredPhilosophers{
public:
	vector<int> simulate(vector<string> text,int N)
	{
		string str;
		for(int i=0;i<text.size();i++)
		  str+=text[i];
		vector<string> w;
		istringstream sin(str);
		string t;
		while(sin>>t)
		  w.pb(t);
		set<string> p;
		vi ret;
		for(int i=1;i<=N;i++)
		{
			p.clear();
			int ps=0;
			for(int j=0;j+i-1<w.size();j++)
			{
				string now;
				for(int k=0;k<i;k++)
				  now+=w[j+k]+" ";
				if(!present(p,now))
				{
					ps++;
					p.insert(now);
				}
			}
			ret.pb(ps);
		}
		return ret;
	}
};
	

const int INF=10000;
class PizzaDelivery{
public:
	int G[300][300];
	int m;
	int n;
	int N;

	int deliverAll(vector<string> terrain){
		for(int i=0;i<300;i++) for(int j=0;j<300;j++) G[i][j]=INF;
		int store=0;
		vector<int> order;
		m=terrain.size();
		n=terrain[0].size();
		N=m*n;
		for(int i=0;i<m;i++) for(int j=0;j<n;j++)
			for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++) if(k*l==0) 
			{
				if(i+k>=m || i+k<0 || j+l>=n || j+l<0) continue;
				int s=i*n+j;
				int t=(i+k)*n+j+l;
				if(terrain[i][j]=='X')
				{
					store=s;
					G[s][t]=2;
					G[t][s]=2;
					cout<<"X at"<<s<<endl;
				}
				else if(terrain[i][j]=='$')
				{
					if(!cpresent(order,s)) order.pb(s);
		
					G[s][t]=2;
					G[t][s]=2;
					cout<<"$ at"<<s<<endl;
				}
				else if(terrain[i+k][j+l]!='X' && terrain[i+k][j+l]!='$')
				{
					int sh=terrain[i][j]-'0';
					int th=terrain[i+k][j+l]-'0';
					int diff=sh-th;
					if(diff<0) diff=-diff;
					if(diff==0)
					{
						G[s][t]=1;
						G[t][s]=1;
					}else if(diff==1)
					{
						G[s][t]=3;
						G[t][s]=3;
					}
				}
			}
		cout<<"debug the G"<<endl;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			  cout<<G[i][j]<<" ";
			cout<<endl;
		}
		cout<<"floyd"<<endl;
		for(int k=0;k<N;k++)
		  for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			  if(G[i][j]>G[i][k]+G[k][j])
				G[i][j]=G[i][k]+G[k][j];
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			  cout<<G[i][j]<<" ";
			cout<<endl;
		}
		
		for(int i=0;i<order.size();i++)
		{
		  cout<<"X to $"<<order[i]<<"="<<G[store][order[i]]<<endl;
		}

		int on=order.size();
		int ON=1<<on;
		int ret=INF;
		
		for(int i=0;i<ON;i++)
		{
			vector<int> boy1;
			vector<int> boy2;
			for(int j=0;j<order.size();j++)
			{
			  if(i & (1<<j))
				boy1.pb(G[store][order[j]]);
			  else
				boy2.pb(G[store][order[j]]);
			}
			sort(all(boy1));
			sort(all(boy2));
			
			int t1,t2,tmp;
			t1=t2=tmp=0;
			
			for(int k=0;i<boy1.size();k++)
			  cout<<boy1[k]<<" "<<endl;
			if(boy1.size()>0){
			for(int k=0;k<boy1.size()-1;k++)
			  t1+=boy1[k];
			t1=t1*2;
			t1+=boy1[boy1.size()-1];
			}
	
			if(boy2.size()>0){
			for(int k=0;k<boy2.size()-1;k++)
			  t2+=boy2[k];
			t2=t2*2;
			t2+=boy2[boy2.size()-1];
			}

			tmp=max(t1,t2);

			if(tmp<ret)
			  ret=tmp;
		}
		if(ret>=INF) return -1;
		return ret;
	}
};


//joey2005
char Map[55][55];
int dis[55][55];
int Dist[30];
int totCost[(1<<20)+5];
int e[30];
bool used[55][55];
int n,m,tot;

bool valid(int x,int y)
{
	return x>=0 && x<n && y>=0 && y<m;
}
bool passAble(int ax,int ay,int bx,int by)
{
	if(Map[ax][ay]=='$' || Map[bx][by]=='$') return true;
	if(Map[ax][ay]=='X' || Map[bx][by]=='X') return true;
	if(Map[ax][ay]+1==Map[bx][by] || Map[ax][ay]==Map[bx][by]+1) return true;
	return Map[ax][ay]==Map[bx][by];
}

int cost(int ax,int ay,int bx,int by)
{
	if(Map[ax][ay]=='$' || Map[bx][by]=='$' ) return 2;
	if(Map[ax][ay]=='X' || Map[bx][by]=='X' ) return 2;
	if(Map[ax][ay]+1==Map[bx][by] || Map[ax][ay]==Map[bx][by]+1) return 3;
	return 1;
}

class PizzDelivery{
public:
	int deliverAll(vector<string> terrain)
	{
		n=terrain.size();
		m=terrain[0].size();
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++)
			Map[i][j]=terrain[i][j];
		memset(used,false,sizeof(used));
		memset(dis,0xff,sizeof(dis));
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++) if(Map[i][j]=='X')
			dis[i][j]=0;
		for(int i=0;i<n*m;i++)
		{
			int x,y,Min=-1;
			for(int j=0;j<n;j++)
			  for(int k=0;k<m;k++) if(!used[j][k] && dis[j][k]>=0 && (Min==-1 || dis[j][k]<Min))
			  {
				  Min=dis[j][k];
				  x=j;
				  y=k;
			  }
			if(Min==-1) break;
			used[x][y]=true;
			for(int k=0;k<4;k++) if(valid(x+dx[k],y+dy[k]) && passAble(x,y,x+dx[k],y+dy[k]))
			  if(dis[x+dx[k]][y+dy[k]]<0)
				dis[x+dx[k]][y+dy[k]]=dis[x][y]+cost(x,y,x+dx[k],y+dy[k]);
			  else
				dis[x+dx[k]][y+dy[k]]=min(dis[x+dx][y+dy[k]],dis[x][y]+cost(x,y,x+dx[k],y+dy[k]));
		}
		tot=0;
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++) if(Map[i][j]=='$')
			Dist[tot++]=dis[i][j];
		for(int i=0;i<tot;i++) if(Dist[i]<0) return -1;
		e[0]=1;
		for(int i=1;i<tot;i++) e[i]=e[i-1]*2;
		sort(Dist.Dist+tot);
		for(int i=0;i<(1<<tot);i++)
		{
			totCost[i]=0;
			for(int j=0;j<tot;j++) if(i&e[j]) totCost[i]+=Dist[j]*2;
			for(int j=tot-1;j>=0;j--) if(i&e[j])
			{
				totCost[i]-=Dist[j];
				break;
			}
		}
		int ans=totCost[(1<<tot) -1],stat=(1<<tot)-1;
		for(int i=0;i<(1<<tot);i++)
		  ans=min(ans,max(totCost[i],totCost[stat-i]));
		return ans;
	}
};


//Div 1
class MagiclSource{
public:
	long long calculate(long long x)
	{
		if(x<10) return x;
		long long ret=x;
		long long time=0;
		int b=0;
		long long y=x;
		while(y>0)
		{
			b++;
			y=y/10;
			time=10*time+1;
		}
	

		while(time>0)
		{
			if(x%time==0)
			{
				ret=x/time;
				break;
			}
			time=time/10;
		}
		return ret;
	}
};


inline int calc(int x,int y,int v)
{
	x-=y*v;
	if(x<y*(y+1)/2) return -1;
	x-=y(y+1)/2;
	int ret=y;
	ret+=x/y;
	if(x%y) ret++;
	return v+ret;
}

class BaronsAndCoins
{
public:
	int getMaximum(vector<int> x,vector<int> y)
	{
		x.push_back(0);
		y.push_back(0);
		n=s.size();
		for(int i=0;i<n;i++)
		  for(int j=i+1;j<n;j++)
			if(y[i]>y[j])
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
		memset(F,-2,sizeof(F));
		F[0][0]=0;
		int ret=0;
		for(int i=0;i<n;i++)
		  for(int j=0;j<=10000;j++)
			for(int k+1;k<n;k++)
			  if(y[i]<y[k] && x[i]<x[k]){
				  int v=calc(x[k]-x[i],y[k]-y[i],j);
				  if(v<0 || v>10000) continue;
				  F[k][v]=max(F[k][v],F[i][j]+1);
				  ret=max(ret,F[k][v]);
			  }
		return ret;
	}
};


			

typedef struct state{
	int layer;
	int pos;
	int minlen;
	int coins;
	state(int l,int p,int m,int c):layer(l),pos(p),minlen(m),coins(c){}
};

class BaronsAndCoins{
public:
	int geMaximum(vector<int> x,vector<int> y)
	{
		int nlay=*max_element(all(y));
		int xmax=*max_element(all(x));
		set<state> F;
		set<state> Fn;
		state init(0,0,0,0);
		int curlay=0;
		while(curlay<=nlay)
		{
			curlay++;
			vector<int> altx;
			for(int i=0;i<n;i++) if(y[i]==curlay)
			  altx.pb(x[i]);
			sort(all(altx));

			for(int i=0;i<F.size();i++) if(F[i].layer==curlay-1)
			{
				int nextx=F[i].pos+len;
				for(int j=0;j<altx.size();j++)
				  if(altx[j]>=nextx)
					break;
				if(j==altx.size()) continue;

				state ns(F[i].layer,nextx,len+1,F[i].coins);
				if(altx[j]==nextx)
				  ns.coins++;
				Fn.push(ns);

				if(altx[j]>nextx)
				{
					ns.coins++;
					ns.pos=altx[j];
					ns.next=altx[j]-F[i].pos+1;
					Fn.push(ns);
				}
			}
			F=Fn;
			Fn.clear();
		}

		int ret=0;
		for(int i=0;i<F.size();i++)
		  if(F[i].coins>ret)
			ret=F[i].coins;

		return ret;

	}
};

	



#define int64 long long

int64 d[60][110000];

class BaronsAndCoins{
public:
	int getMaximum(vector<int> x,vector<int> y)
	{
		int64 i,j,k,n,tmp,tmp1,best;
		vector< pair<int64,int64> > a;
		n=x.size();
		for(int i=0;i<n;i++)
		{
			a.pb(make_pair(x[i],y[i]));
		}
		sort(all(a));
		memset(d,-1,sizeof(d));
		for(i=0;i<n;i++)
		{
			tmp=(a[i].second+1)*a[i].second/2;
			if(a[i].first<tmp)
			  continue;
			if(a[i].first==tmp)
			  tmp1=a[i].second;
			else
			{
				tmp1=a[i].second;
				tmp1+=(a[i].first-tmp-1)/a[i].second+1;
			}
			d[i][tmp1]=1;
		}
		best=0;
		for(int i=0;i<n;i++)
		  for(int j=0;j<=10000;j++)
			if(d[i][j]>=0)
			{
				if(d[i][j]>best) best=d[i][j];
				for(k=i+1;k<n;k++)
				  if((a[k].first>a[i].first) && (a[k].second>a[i].second))
				  {
					  tmp=(a[k].second-a[i].second+1)*(a[k].second-a[i].second)/2+j*(a[k].second-a[i].second);
					  if(a[k].first-a[i].first<tmp)
						continue;
					  if(a[k].first-a[i].first==tmp)
						tmp1=a[k].second-a[i].second+j;
					  else
					  {
						  tmp1=a[k].second-a[i].second+j;
						  tmp1+=(a[k].first-a[i].first-tmp-1)/(a[k].second-a[i].second)+1;
					  }
					  if(d[i][j]+1>d[k][tmp1])
						d[k][tmp1]=d[i][j]+1;
				  }
			}
		return best;
	}
};


#define two(X) (1<<(X))
#define contain(S,X) (((S)&two(X))!=0)

class BrickPuzzle{
public:
	int n,m;
	int f0[two(22)],f1[two(22)];
	int workId,visId[two(22)];
	int mask,cover;
	int sizeQ,sizeQ0,Q0[1000000],Q[1000000];
	bool D1[22],D2[22],GO[22],G1[22],G2[22];
	void DFS(int depth,int newset,int cnt)
	{
		if(depth==m)
		{
			if(visId[newset]!=workId) Q[sizeQ++]=newset,visId[newset]=workId,f1[newset]=cnt;
			else if(cnt<f1[newset]) f1[newset]=cnt;
			return;
		}
		if(GO[depth])
		  DFS(depth+1,newset,cnt);
		if(G1[depth])
		  DFS(depth+4,newset,cnt+1);
		if(G2[depth])
		  DFS(depth+2,newset|two(depth),cnt+1);
	}

	void DFS2(int depth,int newset,int last,int cnt)
	{
		if(depth==m)
		{
			if(visId[newset]!=workId) Q[sizeQ++]=newset,visId[newset]=workId,f0[newset]=cnt;
			else if(cnt<f0[newset]) f0[newset]=cnt;
			return;
		}
		if(contain(mask,depth))
		{
			if(last<depth-1 && depth<m) DFS2(depth+2,newset|two(depth-1)|two(depth),depth,cnt);
			if(last<depth && depth<m) DFS2(depth+2,newset|tow(depth)|tow(depth+1),depth+1,cnt);
			if(last<depth && depth+2<m) DFS2(depth+2,newset|two(depth+1)|two(depth+2),depth+2,cnt);
		}
		else
		  DFS(depth+1,newset,last,cnt);
	}
	int leastShapes(vector<string> board)
	{
		n=SIXE(board);
		m=LENGTH(board[0]);
		memset(vidId,0,sizeof(visID));
		workId=0;
		f0[0]=0;
		sizeQ=0;
		Q[sizeQ++]=0;
		for(int x=0;x<n;x++)
		{
			cover=0;
			for(int y=0;y<m;y++) if(board[x][y]=='.') cover|=two(y);
			workId++;
			sizeQ0=sizeQ;
			for(int cl=0;cl<sizeQ0;cl++) Q0[cl]=Q[cl];
			sizeQ=0;
			for(int depth=0;depth<m;depth++)
			{
				D1[depth]=D2[depth]=false;
				if(depth+3<m && (board[x][depth]=='.' || board[x][depth+1]=='.' || board[x][depth+2]=='.' || board[x][depth+3]=='.' ))
				  D1[depth]=true;
				if(x+1<n && depth+1<m && (board[x][depth]=='.' || board[x][depth+1]=='.' || board[x+1][depth]=='.' ||board[x+1][depth+1]=='.')) D2[depth]=true;
				if(x+1<n && depth+1<m && depth-1>=0 && (board[x][depth]=='.' || board[x][depth+1]=='.' || board[x+1][depth]=='.')) D2[depth]=true;
				if(x+1<n && depth+2<m && (board[x][depth]=='.' || board[x][depth+1]=='.' || board[x+1][depth+2]=='.' )) D2[depth]=true;
			}
			for(int cl=0;cl<sizeQ0;cl++)
			{
				mask=Q0[cl];
				for(int depth=0;depth<m;depth++)
				{
					G0[depth]=G1[depth]=G2[depth]=false;
					if(!contain(cover,depth) || contain(cover,depth) && contain(mask,depth)) G0[depth]=true;
					if(D1[depth] && depth+3<m && (mask&(two(depth)*15))==0) G1[depth]=true;
					if(D2[depth] && depth+1<m && x+1<n && (mask&(two(depth)*3))==0) G2[depth]=true;
				}
				DFS(0,0,f0[mask]);
			}
			workId++;
			sizeQ0=sizeQ;
			for(int cl=0;cl<sizeQ0;cl++) Q0[cl]=Q[cl];
			sizeQ=0;
			for(int cl=0;cl<sizeQ0;cl++)
			{
				mask=Q0[cl];
				DFS2(0,0,-1,f1[mask]);
			}
		}
		return (visId[0]==workId)?f0[0]:-1;
	}
};
				











