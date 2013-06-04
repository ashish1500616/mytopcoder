class EggCartons{
public:
	int minCartons(int n)
	{
		int nb=n/8;
		if(n%8==0) return nb;
		int ret=-1;
		for(int i=nb;i>=0;i--)
		{
			int r=n-i*8;
			if(r%6==0){
				ret=i+r/6;
				return ret;
			}
		}
		return ret;
	}
};

class NotTwo{
public:
	int maxStones(int width,int height)
	{
		int ret=0;
		for(int i=0;i<width;i++)
		  for(int j=0;j<height;j++)
		  {
			  if((i/2)%2==0 ^ (j/2)%2!=0)
				ret++;
		  }
		return ret;
	}
};

class HamiltonPath{
public:
	bool vis[55];
	vector<string> roads;
	int n;
	void dfs(int i)
	{
		vis[i]=true;
		for(int j=0;j<n;j++)
		  if((roads[i][j]=='Y')&&(!vis[i])) dfs(j);
	}
	
	int countPaths(vector<string> _roads)
	{
		roads=_roads;
		memset(vis,false,sizeof(vis));
		n=roads.size();
		for(int i=0;i<n;i++)
		{
			int s=0;
			for(int j=0;j<n;j++)
			  if(roads[i][j]=='Y')
				s++;
			if(s>2) return 0;
			d[i]=s;
		}
		int tot1=0,tot2=0;
		for(int i=0;i<n;i++)
		  if((!vis[i]) && (d[i]<2))
		  {
			  dfs(i);
			  if(d[i]==0) tot1++;
			  else tot2++;
		  }
		for(int i=0;i<n;i++)
		  if(!vis[i]) return 0;
		long long ret=1;
		for(int i=0;i<tot1+tot2;i++) ret=(ans*(i+1))%1000000007;
		for(int i=0;i<tot2;i++)
		  ret=(ret*2)%1000000007;
		return ret;
	}
};
		


//wrong
class HamiltonPath{
public:
	int m[55];
	int c[55];
	int f(int n)
	{
		int ret=1;
		if(n==0) return 1;
		for(int i=1;i<=n;i++)
		  ret=(ret*i)%1000000007;
		return ret;
	}

	int countPaths(vector<string> roads){
		int n=roads.size();
		for(int i=0;i<n;i++) 
		  m[i]=i,c[i]=0;
		for(int i=0;i<n;i++)
		  for(int j=i+1;j<n;j++)
			if(roads[i][j]=='Y')
			{
				m[j]=m[i];
			}
		for(int i=0;i<n;i++)
		{
			int j=m[i];
			while(j!=m[j])
			{
				j=m[j];
			}
			m[i]=j;
		}
		int N=0;
		for(int i=0;i<n;i++)
		  if(m[i]==i)
			N++;

		for(int i=0;i<n;i++)
		  c[m[i]]++;

		if(N==0) return 0;

		int ret=f(N);
		for(int i=0;i<n;i++)
		  if(c[i]>0)
			ret=(ret*f(c[i]))%1000000007;
		
		return ret;
	}
};

class IOIString{
public:
	int MOD=1000000007;
	int countIOIs(vector<string> mask){
		int n,i,j,d,allI=0,cnt=0;
		string s;
		for(i=0;i<mask.size();i++) s+=mask[i];
		n=s.size();
		for(i=0;i<n;i++) if(s[i]=='I') allI++;

		if(allI==0) cnt++;
		for(i=0;i<n;i++) if((s[i]=='I' && allI==1) || (s[i]=='?' && allI==0)) cnt++;
		for(d=0;d<n;d+=2) for(i=0;i<n;i++){
			int I=0,O=0;
			if(s[i]=='I') I++;
			if(s[i]=='O') O++;
			for(j=i+d;j<n;j+=d){
				if(s[j]=='I') I++;
				if(s[j]=='O') O++;
				if(I==allI && O==0) cnt++;
			}
		}
		int ret=1;
		for(i=0;i<n;i++) if(s[i]=='?') ret=(ret*2)%MOD;
		ret=(ret-cnt+MOD)%MOD;
		return ret;
	}
};

		

		



			
