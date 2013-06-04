class GuessingNextElement{
public:
	int guess(vector<int> A)
	{
		int p,aq,gq;
		int n=sz(A);
	
		int ret=0;
		p=A[0];
		aq=A[1]-A[0];
		gq=A[1]/A[0];
		for(int i=2;i<n;i++)
		{
			if(aq!=A[i]-A[i-1])
			  aq=-1;
			if(gq!+A[i]/A[i-1])
			  gq=-1;
		}
		if(aq!=-1)
		  ret=A[n-1]+aq;
		if(gq!=-1)
		  ret=A[n-1]*gq;
		return ret;
	}
};

class MarblesRegroupingEasy{
public:
	int ok[51];
	int minMoves(vector<string> boxes)
	{
		int n=sz(boxes);
		int m=sz(boxes[0]);
		int ret=123456789;
		for(int joke=0;joke<n;joke++)
		{
			memset(ok,0,sizeof(boxes));
			ok[joke]=1;
			int tret=0;
			for(int i=0;i<n;i++)
			{
				if(i==joke) continue;
				int color=0;
				for(int j=0;j<m;j++)
				{
					if(boxes[i][j]>'0')
					  color++;
				}
				if(color==0)
				  ok[i]=1;
				if(color>1)
				{
					ok[i]=1;
					tret++;
				}
			}
			
			for(int j=0;j<m;j++)
			{
				int cs=0;
				for(int i=0;i<n;i++)
				{
					if(ok[i]) continue;
					if(boxes[i][j]>'0')
					{
						cs++;
					}
				}
				if(cs==0) continue;
				tret+=cs-1;
			}
			if(tret<ret)
			  ret=tret;
		}
		return ret;
	}
};

class MarblesRegroupingHard{
public:
	int dp[51][1<<14];
	int doit(int id,int mask)
	{
		int &res=dp[id][mask];
		if(res!=-1) return res;
		if(id==n) return res=0;

		res=0;
		int tot=0;
		int i,j;

		// bucket id empty
		for(i=0; i<m;i++)
		  tot+=ar[id][i];
		res=tot+doit(id+1,mask);

		// assign color j to bucket id
		for(j=0; j<m;j++) if( mask & (1<<j))
		{
			tot=0;
			for(i=0;i<m;i++) if(i!=j) tot+=ar[id][i];
			res <?=tot+doit(id+1,mask^(1<<j));
		}
		return res;
	}
	int minMoves(vector<string> boxes)
	{
		n=boxes.size();
		int i;
		for(i=0;i<n;i++)
		{
			ar[i]=s2vi(boxes[i]);
		}
		m=ar[0].size();
		memset(dp,-1,sizeof(dp));
		int res=doit(0,(1<<m)-1);
		return res;
	}
};

