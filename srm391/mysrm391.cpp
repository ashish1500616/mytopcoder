int m[10005];

class SnowyWinter{
public:
	int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints){
		memset(m,0,sizeof(m));
		int n=sz(startPoints);
		for(int i=0;i<n;i++)
		{
			int s=startPoints[i];
			int t=endPoints[i];
			for(int j=s;j<=s;j++)
			{
				if(m[j]==0)
				  m[j]=1;
			}
		}
		int res=0;
		for(int k=0;k<1005;k++)
		  res+=m[k];
		return res;
	}
};



class IsomorphicWords{
public:
	int countPairs(vector <string> words){
		int n=sz(words);
		int res=0;
		for(int i=0;i<n;i++)
		  for(int j=i+1;j<n;j++)
		  {
			  if(isomo(words[i],words[j])&&isomo(words[j],words[i]))
				res++;
		  }
		return res;
	}
	bool isomo(string str1,string str2)
	{
		if(sz(str1)!=sz(str2))return false;
		map<char,char> m;
		int n=sz(str1);
		for(int i=0;i<n;i++)
		{
			char s1=str1[i];
			char s2=str2[i];
			if(present(m,s1))
			{
				if(m[s1]!=s2)
				  return false;
			}else
			{
				m[s1]=s2;
			}
		}
		debug(str1)
		debug(str2)
		return true;
	}
};



typedef vector<int> path;
map<path,int> m;
int mx[]={1,0,-1,0};
int my[]={0,1,0,-1};
vector<string> board;
int W,H;
class MarbleCollectionGame{
public:
	int collectMarble(vector<string> _board)
	{
		board=_board;
		W=sz(board[0]);
		H=sz(board);
		int res=0;
		path p;
		res=dp(p);
		if(board[0][0]>='0' && board[0][0]<='9')
		  res+=board[0][0]-'0';
		return res;


	}
	int dp(path p)
	{
		int n=sz(p);
		
		int x,y;
		x=y=0;
		if(present(m,p))
		  return m[p];
		m[p]=0;
		int &num=m[p];
		for(int i=0;i<n;i++)
		{
			x+=mx[p[i]];
			y+=my[p[i]];
			
		}
		debug(x)
		debug(y)
		
		for(int k=0;k<2;k++) 
		{
		    debug(k)
		    cout<<"k begin"<<endl;
			int nx,ny;
			nx=x+mx[k];
			ny=y+my[k];
		

			debug(W)
			debug(H)
			cout<<"test"<<endl;
			debug(nx)
			debug(ny)
			cout<<"end test"<<endl;
			if(nx<W && nx>-1 && ny<H && ny>-1)
		    {
		        if(board[ny][nx]=='#') continue;
		        debug(nx)
			    debug(ny)
				path n=p;
				n.pb(k);
				
				int add=0;
				if(board[ny][nx]<='9' && board[ny][nx]>='0')
					add=board[ny][nx]-'0';
				cout<<"test add"<<endl;
				debug(ny)
				debug(nx)
				debug(add)
				int tmp=dp(n)+add;
				if(tmp>num)
				  num=tmp;
	
				cout<<"here1";
				debug(num);
				
			}
			debug(k)
		}
		cout<<"here2";
		if(board[y][x]=='L')
		{
		    
			int nx,ny;
			nx=x+mx[2];
			ny=y+my[2];
			if(nx<W && nx>-1 && ny<H && ny>-1)
			{
				path n=p;
				n.pb(2);
				num=max(num,dp(n));
			}
		}
		if(board[y][x]=='U')
		{
			int nx,ny;
			nx=x+mx[3];
			ny=y+my[3];
			if(nx<W && nx>-1 && ny<H && ny>-1)
			{
				path n=p;
				n.pb(3);
				num=max(num,dp(n));
			}
		}
		debug(num)
		return num;

	}
};