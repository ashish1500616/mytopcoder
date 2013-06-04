class MinimalDifference{
public:
	int findNumber(int A,int B,int C){
		int diff=111111;
		int cd;
		int ret;
		cd=digits(C);
		for(int i=A;i<=B;i++){
			int cur=digits(i);
			if(abs(cur-cd)<diff){
			  ret=i;
			  diff=abs(cur-cd);
			}
		}
		return ret;
		
	}
	int digits(int n){
		int d=0;
		while(n>0){
			d+=n%10;
			n=n/10;
		}
		return d;
	}
};


class WordsGame{
public:
	int n;
	int numSwaps(string os,string word){
		int ret=0;
		for(int i=0;i<n;i++)
		{
			if(os[i]!=word[i])
			{
				for(int j=i;j<n;j++)
					if(os[j]==word[i])
					  swap(os[i],os[j]),ret++;
			}
		}
		return ret;
	}

	int minimumSwaps(vector<string> grid,string word)
	{
		int ret=1000000;
		n=sz(grid);
		vector<string> can;
		string tmp;
		string sortword=word;
		sort(all(sortword));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			  tmp+=grid[i][j];
			string sorttmp=tmp;
			sort(all(sorttmp));
		  	if(sortword==sorttmp)
			  can.pb(tmp);
		  	tmp.clear();
		}
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)
			  tmp+=grid[i][j];
			string sorttmp=tmp;
			sort(all(sorttmp));
			if(sortword==sorttmp)
			  can.pb(tmp);
			tmp.clear();
		}
		for(int i=0;i<sz(can);i++)
		{
			int cur=numSwaps(can[i],word);
			if(cur<ret)
			  ret=cur;
		}
		if(ret==1000000)
		  ret=-1;
		return ret;
	}
};

const int dis[10][7]={
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,1},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1},
};

class NumbersAndMatches{
public:
	long long dp[127][127];

	long long differentNumbers(long long N,int K)
	{
		const int m=126;
		for(int i=0;i<=m;i++)
		  for(int j=0;j<=m;j++)
			dp[i][j]=!i && !j;

		int inc[10][10],dec[10][10];

		for(int i=0;i<10;i++)
		  for(int j=0;j<10;j++)
		  {
			  inc[i][j]=dec[i][j]=0;
			  for(int k=0;k<7;k++)
			  {
				  if(dis[i][k]<dis[j][k])
					inc[i][j]++;
				  if(dis[i][k]>dis[j][k])
					dec[i][j]++;
			  }
		  }
		while(N>0)
		{
			int n=N%10;
			N/=10;
			for(int i=m;i>=0;i--)
			  for(int j=m;j>=0;j--)
				if(dp[i][j])
				{
					long long me=dp[i][j];
					dp[i][j]-=me;
					for(int k=0;k<10;k++)
					{
						dp[i+inc[n][k]][j+dec[n][k]]+=me;
					}
				}
		}
		long long ret=0;
		for(int i=0;i<=K;i++)
		  ret+=dp[i][i];
		return ret;
	}
};


};

			 


