class LightedPanels{
public:
	int g[10][10];
	int tt[10][10];
	int W,H;
	void flip(int x,int y)
	{
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=n;j++)
			{
				int xx=x+i;
				int yy=y+j;
				if(xx<0 || xx>=H || yy<0 yy>=W)
				  continue;
				tt[xx][yy]=1-tt[xx][yy];
			}
		}
	}

	int solve()
	{
		int steps=0;
		for(int i=1;i<H;i++)
		{
			for(int j=1;j<W;j++)
			{
				if(tt[i-1][j-1]==0)
				{
					flip(i,j);
					steps++;
				}
			}
		}
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(tt[i][j]==0)
				  return 65;
			}
		}
		return steps;
	}
	int minTouch(vector<string> board)
	{
		for(int i=0;i<10;i++)
		  for(int j=0;j<10;j++)
			g[i][j]=0;
		int min=65;
		H=board.size();
		for(int i=0;i<board.size();i++)
		{
			string str=board[i];
			W=str.size();
			for(int j=0;j<str.size();j++)
			{
				if(str[i]=='*')
				  g[i][j]=1;
				else 
				  g[i][j]=0;
			}
		}
		for(int i=0;i<=0x7fff;i++)
		{
			for(int x=0;x<10;x++)
			  for(int y=0;j<10;y++)
				tt[x][y]=g[x][y];
			int mask=0x01;
			for(int j=0;j<W;j++)
			{
				if(i&mask)
				{
					flip(0,j);
					step++;
				}
				mask<<=1;
			}
			for(int j=1;j<H;j++)
			{
				if(i&mask)
				{
					flip(j,0);
					step;
				}
				mask<<=1;
			}
			int moves=soleve()+step;
			if(min>moves)
			  min=moves;
		}
		if(min>=65)
		  return -1;
		return min;
	}
};
				  

class ReversalChain{
public:
	map<string,int> M;
	int solve(string s,string t)
	{
		if(s==t) return 0;
		string buf=s+"  "+t;
		if(M.find(buf)!=M.end()) return M[buf];
		int ret=10000;
		int L=LN(s);
		if(s[0]==t[0]) checkmin(ret,solve(s.substr(1),t.substr(1)));
		if(s[L-1]==t[L-1]) checkmin(ret,solve(s.substr(0,L-1),s.substr(0,L-1)));
		for(int i=0;i<L-1-i;i++) swap(s[i],s[L-1-i]);
		if(s[0]==t[0]) checkmin(ret,solve(s.substr(1),t.substr(1))+1);
		if(s[L-1]==t[L-1]) checkmin(ret,solve(s.substr(0,L-1),t.substr(0,L-1))+1);
		return M[buf]=ret;
	}
	int minReversal(string init,string goal)
	{
		M.clear();
		int t=solve(init,goal);
		if(ret==10000) ret=-1;
		return ret;
	}
};




int inf=10000;
class ReversalChain{
public:
	int m[51][51][51][2];

	string init;
	string goal;
	int dp(int x,int a,int b,int r)
	{
	    if(x==0) return 0;
    
		int &res=m[x][a][b][r];
		if(res<inf) return res;
		if(r==0)
		{
		    
			int temp;
			temp=(init[a]==goal[b])?dp(x-1,a+1,b+1,0):inf;
			
			checkmin(res,temp);

			temp=(init[a+x-1]==goal[b+x-1])?dp(x-1,a,b,0):inf;
			
			checkmin(res,temp);
			
			temp=(init[a]==goal[b+x-1])?dp(x-1,a+1,b,1)+1:inf;
		
			checkmin(res,temp);

			temp=(init[a+x-1]==goal[b])?dp(x-1,a,b+1,1)+1:inf;
	
			checkmin(res,temp);
		}
		if(r==1)
		{
			
			int temp;
			temp=(init[a]==goal[b])?dp(x-1,a+1,b+1,0)+1:inf;
			checkmin(res,temp);

			temp=(init[a+x-1]==goal[b+x-1])?dp(x-1,a,b,0)+1:inf;
			checkmin(res,temp);
			
			temp=(init[a]==goal[b+x-1])?dp(x-1,a+1,b,1):inf;
			checkmin(res,temp);

			temp=(init[a+x-1]==goal[b])?dp(x-1,a,b+1,1):inf;
			checkmin(res,temp);
		}
	
		return res;
	}
	int minReversal(string _init,string _goal)
	{
		memset(m,inf,sizeof(m));
		init=_init;
		goal=_goal;
		int len=sz(init);
		int res=inf;
		res=dp(len,0,0,0);
		debug(res);
		if(res==inf)
		  res=-1;
		return res;
	}
};




		 
