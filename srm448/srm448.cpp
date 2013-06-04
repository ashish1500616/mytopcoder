class TheBlackJackDivTwo{
public:
	int score(vector<string> cards)
	{
		int n=sz(cards);
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(cards[i][0]=='A')
			  res+=11;
			else if(cards[i][0]=='K' || cards[i][0]=='Q' || cards[i][0]=='J' || cards[i][0]=='T')
			  res+=10;
			else 
			  res+=cards[i][0]-'0';
		}
		return res;
	}
};

class TheCardShufflingDivTwo{
public:
	int shuffle(int n, int m){
		stack<int> m;
		stack<int> l;
		stack<int> r;
		for(int i=n;i>=1;i--)
		  m.push(i);

		for(int k=0;k<m;k++)
		{
			for(int i=0;i<n;i++)
			{
				if(i%2==0)
				{
					l.push(m.top());
					m.pop();
				}
				else{
					r.push(m.top());
					m.pop();
				}
			}

			for(int i=0;i<sz(l);i++)
			{
				m.push(l.top());
				l.pop();
			}
			for(int i=0;i<sz(r);i++)
			{
				m.push(r.top());
				r.pop();
			}
		}
		int res=0;
		res=m.top();
		return res;
	}
};


int F[70000][16];
int C[256];

inline check(string a,string b)
{
	if(a[0]==b[0]) return true;
	if(C[a[1]]==C[b[1]]) return true;
	return false;
}

class TheCardDivTwo{
	public:
	int count(vector<string> st)
	{
		int n=sz(st);
		C['C']=C['S']=1;
		C['D']=C['H']=2;
		memset(F,0,sizeof(F));
		for(int i=0;i<n;i++)
		  F[1<<i][i]=1;
		for(int s=0;s<1<<n;s++)
		  for(int i=0;i<n;i++)
			if(F[s][i])
			{
				for(int j=0;j<n;j++)
				  if(!(s&(1<<j)) && check(st[i],st[j]))
					F[s|(1<<j)][j]=(F[s|(1<<j)][j]+F[s][i])%mod;
			}
		ll ret=0;
		ll des=1<<n-1;
		for(int i=0;i<n;i++)
		  ret=(ret+F[des][i])%mod;
		return ret;
	}
};


int c[52];
int g[52][52];
int N;
class TheCardLineDivTwo{
public:
	vi getnei(int i)
	{
		vi nei;
		for(int j=0;j<52;j++) if(g[i][j])
		  nei.pb(j);
		return nei;
	}
	int go1(stack<int> vis)
	{
		if(vis.size()==N)
		  return 0;
		int cur=vis.top();
		vi cur_nei=getnei(cur);
		if(sz(cur_nei)==0) return -1;
		int tmp=0;
		for(int i=0;i<sz(cur_nei);i++)
		{
			stack<int> nn=vis;
			nn.push(cur_nei[i]); 
			int tt=go1(nn);
			if(tt!=-1)
			  tmp+=tt;
		}
		if(tmp==0)
		  return -1;
		else 
		  return tmp;
	}
		

	int count(vector <string> cards)
	{
		N=sz(cards);
		memset(c,-1,sizeof(c));
		memset(g,-1,sizeof(g));
		for(int i=0;i<sz(cards);i++)
		{
			int color=0;
			if(cards[i][1]=='S')
			  color=0;
			if(cards[i][1]=='C')
			  color=13;
			if(cards[i][1]=='D')
			  color=13*2;
			if(cards[i][1]=='H')
			  color=13*3;
			int num=0;
			if(cards[i][0]=='T')
			  num=8;
			else if(cards[i][0]=='J')
			  num=9;
			else if(cards[i][0]=='Q')
			  num=10;
			else if(cards[i][0]=='K')
			  num=11;
			else if(cards[i][0]=='A')
			  num=12;
			else 
			  num=cards[i][0]-'0'-2;
			c[color+num]=1;
		}
		for(int i=0;i<52;i++) if(c[1])
		{
			int color=i/13;
			for(int j=color*13;j<color*13+13;j++) if(c[j])
			{
				g[i][j]=1;
			}
			int num=i%13;
			for(int j=num;j<52;j+=13) if(i!=j && c[j])
			{
				g[i][j]=1;
			}
		}

		//
		int res=0;
		for(int i=0;i<52;i++)if(c[i])
		{
			stack<int> vis;
			vis.push(i);
			int tmp=go1(vis);
			if(tmp!=-1)
			  res+=tmp;
		}
		if(res==0)
		  res=-1;
		return res;
	}
};


class TheBlackJackDiveOne{
public:
	double solve(int s,int C[])
	{
		if(s>=21) return 0;
		int total=0;
		for(int i=2;i<12;i++)
			total+=C[i];
		double result=0;
		for(int i=0;i<12;i++)
		  if(C[i]>0)
		  {
			  C[i]--;
			  result+=solve(s+i,C[]);
			  C[i]++;
		  }
		return result/total+1.0;
	}
	double exptected(vector<string> cards)
	{
		int C[12];
		for(int i=2;i<=9;i++)
		  C[i]=4;
		C[10]=16;
		C[11]=4;
		int s=0;
		for(int i=0;i<sz(cards);i++)
		{
			int d=0;
			char c=cards[i][0];
			if(c=='T' || c=='J' || c=='Q' || c=='K')
			  d=10;
			else if(c=='A')
			  d=11;
			else 
			  d=c-'0';
			C[d]--;
			s+=d;
		}
		double res=0;
		res=sovle(s,C);
		return res;
	}
};

class TheCardShufflingDiveone{
public:
	int sleft;
	int sright;
	int solve(int n)
	{
		if(n<=2) return n;
		int nleft=(n+1)/2;
		int nright=n-nleft;
		int r=solve(n-2);
		if(r<=nright-1)
		{
			int p=(nright-sright%nright)*2;
			p+=r*2;
			p%=(nright*2);
			if(p==0) p=nright*2;
			return p;
		}
		else
		{
			int p=(nleft-sleft%nleft)*2-1;
			p+=(r-nright)*2;
			p%=(nleft*2);
			return p;
		}
	}
	int shuffle(int n,int left,int right)
	{
		sleft=left;
		sright=right;
		int ret=sovle(n);
		return ret;
	}
};

public class TheCardShufflingDivOne{
	public int shuffle(int n,int left, int right){
		int cards=n%2;
		if(cards==0)
		  cards=0;
		int rem=cards;
		while(cards<n)
		{
			cards+=2;
			int numL=cards/2+cards%2;
			int numR=cards/2;
			if(rem<numR-1)
			{
				int id=numR-rem+1;
				id+=(right%numR);
				if(id>numR)
				  id-=numR;
				rem=(numR-id+1)*2;
			}
			else
			{
				int id=numL-(rem-numR+1)+1;
				id+=(left%numL);
				if(id>numL)
				  id-=numL;
				rem=(numL-id+1)*2-1;
			}
		}
		return rem;
	}

};

		


			








