class ContiguousSubsequences{
public:
	vi findMaxAverage(vi a,int K)
	{
		int n=sz(a);
		double best=0.0;
		int begin=0;length=0;
		for(int i=0;i<n;i++)
		  for(int j=i;j<n;j++)
			if(j-i+1>=K){
				int sum=0;
				for(int m=i;m<=j;m++)
				  sum+=a[m];
				double curr=(0.0+sum)/(0.0+(j-i+1.0));
				if(curr>best)
				{
					best=curr;
					begin=i;
					length=j;
				}
				else if(fabs(curr-best)<1e-9){
					if(j-i>length-begin)
					  begin=i,length=j;
				}
			}
		vector<int> res;
		res.pb(begin);
		res.pb(length);
		return res;
	}
};
			


class ContiguousSubsequences{
public:
	vi findMaxAverage(vi a,int K)
	{
		for(int i=0;i<51;i++) imax[i]=-1;
		memset(iind,-1,sizeof(iind));

		int n=sz(a);
		for(int i=0;i<n;i++)
		{	
			int itmp=0;
			if(i+K>=n+1) continue;
			for(int k=0;k<K;k++)
				itmp+=a[i+k];
			imax[i]=(float)itmp/K;
			iind[i]=i+K-1;
			
			for(int j=i+K;j<n;j++)
			{	
				itmp+=a[j];
				float max=(float)itmp/(j-i+1);
				if(max>imax[i])
				{
					imax[i]=max;
					iind[i]=j;
					debug(max)
				}
				if(max==imax[i])
				{  iind[i]=j;}
			}
		}

		 
		int resi,resj;
		float max=imax[0];
		resi=0;
		resj=iind[0];
		for(int i=0;i<n;i++)
		{
			if(max<imax[i])
			{
				max=imax[i];
				resi=i;
				resj=iind[i];
			}
			if(max==imax[i])
			{
				if(iind[i]-i>resj-resi)
				{   
					resi=i;
					resj=iind[i];
					
				}
			}
		}
		vi res;
		res.pb(resi);
		res.pb(resj);
		return res;
	}
};

class CharmingTicketsEasy{
public:
	int count(int K,string good){
		long long dp[51][451]={0};
		long long dp2[51]={0};
		int i,j,k;
		int g[10]={10};
		long long tmp;
		long long ret=0;

		for(i=0;i<good.length();i++) g[good[i]-'0']=1;
		
		dp[0][0]=1;
		for(i=0;i<=49;i++){
			for(j=0;j<10;j++){
				if(g[j]==1){
					for(k=0;k<=450;k++){
						dp[i+1][k+j]+=dp[i][k];
						dp[i+1][k+j]%=999983;
					}
				}
			}
		}

		for(i=0;i<=50;i++)
		  for(j=0;j<=450;j++){
			  dp2[i]+=dp[i][j]*dp[i][j]%999983;
			  dp2[i]%=999983;
		  }

		tmp=dp[K/2]*dp[K-K/2]%999983;

		for(j=0;j<=450;j++){
			ret+=dp[K][j]*dp[K][j]*2%999983;
			ret%=999983;
		}
		ret+=999983-tmp;
		ret%=999983;
		
		return (int) ret;
	}
};

class PointOnACircle{
public:
	int C[360];
	boo V[360];
	int solve(vi A)
	{
		if(sz(A)<2) return 0;
		int R1=0,R2=0;
		for(int i=0;i<sz(A);i++)
		  if(A[i]==1 && i+1<sz(A) && A[i]==1)
			R1++,i++;
		int t=A[0];
		for(int i=0;i<sz(A)-1;i++) A[i]=A[i+1];
		A[sz(A)-1]=t;
		for(int i=0;i<sz(A);i++)
		  if(A[i]==1 && i+1<sz(A) && A[i+1]==1)
			R2++,i++;
		return max(R1,R2);
	}

	int color(vector<string> vs)
	{
		string str="";
		for(int i=0;i<sz(vs);i++) str+=vs[i];
		istringstream sin(str);
		memset(C,0,sizeof(C));
		for(int v;sin>>v;C[v]++);
		int result=0;
		for(int d=0;d<360;d++)
		{
			memset(V,false,sizeof(V));
			int total=0;
			for(int i=0;i<360;i++) if(!V[i])
			{
				vector<int> A;
				for(int k=i;!V[k];V[k]=true,k=(k+d)%360)
				  A.push_back(C[k]);
				int D=solve(A);
				total+=D;
			}
			checkmax(reslut,total);
		}
		return result*2;
	}
};
