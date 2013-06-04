class RatatingTriangles
{
	char m[51][51];
	int N,M;

	void rot()
	{
		char t[51][51];
		memset(t,' ',sizof(t));
		int i,j;
		for( i=0;i<N;i++)
		  for( j=0;j<M;j++)
			t[j][N-i-1]=m[i][j];
		swap(N,M);
		memcpy(m,t,sizeof(m));
	}

	int getOne(int i, int j)
	{
		int ret=0;
		int len;
		for( len=1;;len++)
		{
			int bi=i,bj=j-len+1,ti=i-len+1,tj=j;
			if(bj<0 || ti<0)
			  return ret;
			if(bi !=N-1 && m[bi+1][bj]=='#')
			  return ret;
			if(tj !=M-1 && m[ti][tj+1]=='#')
			  return ret;;
			int k,sum=0;
			for( k=0;k<len;k++)
			{
				if(m[bi][bj]=='.')
				  return ret;
				if(m[bi][bj]=='/')
				  sum++;
				bi--;
				bj++;
			}
			if(sum==len)
			  ret++;
		}
		return ret;
	}

	int getTwo(int i,int j)
	{
		int ret=0;
		int len;
		for(len=1;;len++)
		{
			int li=i, lj=j-len+1, ri=i, rj=j+len, bi=i-len+1;
			if( lj<0 || rj >= M || bi<0)
			  return ret;
			if( i!=N-1 && (m[i+1][lj]=='#' || m[i+1][rj]=='#'))
			  return ret;
			int k,sum=0;
			for( k=0;k<len;k++)
			{
				if(m[li][lj]=='.' || m[ri][rj]=='.')
				  return ret;
				if(m[li][lj]=='/' && m[ri][rj]=='/')
				  sum++;
				li--, ri--, lj++, rj--;
			}
			if( sum==len )
			  ret++;
		}
		return ret;
	}
public:
	int count(vector<string> grid)
	{
		int i,j;
		N=grid.size();
		M=grid[0].size();
		memset(m,' ',sizeof(mm));
		for( i=0;i<N;i++)
		  for(j=0;j<M;j++)
			m[i][j]=grid[i][j];
		int k;
		int sum=0;
		for(k=0;k<4;k++)
		{
			rot();
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					sum+=getOne(i,j);
					sum+=getTwo(i,j);
				}
			}
		}
		return sum;
	}
};









