class StrangeComputer{
public:
	int setMemory(string mem)
	{
		int cur=0;
		int ret=0;
		int n=sz(mem);
		for(int i=0;i<n;i++)
		{
			int now=mem[i]-'0';
			if(now^cur)
			{
				ret++;
				cur=now;
			}
		}
		return ret;
	}
};

//ACRush
class OrderedNim{
public:
	string winner(vector<int> A)
	{
		int n=sz(A);
		bool isWin(false);
		for(int i=n-1;i>=0;i--)
		  isWin=!isWin || isWin && A[i]>1;
		return (isWin)?"Alice":"Bob";
	}
};

class OrderNim{
public:
	string winner(vector<int> layout)
	{
		// Alice 0, Bob 1
		int win=0;
		int ret=0;
		int pwin=win;
		int n=sz(layout);
		if(layout[n-2]==1)
		  win=1;
		else
		  win=0;
		
		if(n==2)
		{
			if(win==0)
			  return "Alice";
			else
			  return "Bob";
		}
		for(int i=n-3;i>=0;i--)
		{
			if(win==0)
			{
				if(layout[i]==1)
				  win=1;
				else
				  win=0;
			}
			else{
				win=0;
			}
		}
		if(win==0)
		  return "Alice";
		else
		  return "Bob";
	}
};


//gernot
class EnemyTowers{
public:
	int attack_single(int myUnits,int hpT,int attackT,int numTower){
		int total_hpT=hpT*numTower;
		int turns=1;
		for(;;){
			total_hpT-=myUnits;
			if(total_hpT<=0) return turns;
			numTower=(total_hpT-1)/hpT+1;
			myUnits-=attace*numTower;
			if(myUnits<=0) return -1;
			turns++;
		}
	}

	int attack(int myUnits,int hpT,int attackT,int numWodT,int numStoT){
		int min_turns=attack_single(myUnits,hpT,attackT,numWodT+numStoT);
		if(min_turns<1) return min_turns;
		int numWods,numStoS;
		int best_turns=10000000;
		int numWods_min=0;
		int numWods_max=myUnits;
		for(;;){
			if(numWods_min>numWods_max) break;
			numWodS=(numWods_max-numWods_min)/2+numWods_min;
			numStoS=myUnits-numWods;
			int wt=attack_single(numWods,hpT,attackT,numWodT);
			if(wt<1){
				numWods_min=numWods+1;
				continue;
			}
			int st=attack_single(numStoS,hpT,attackT,numStoT);
			if(st<1){
				numWodS_max=numWods-1;
				continue;
			}
			int turns=max(wt,st);
			if(best_turns>turns) best_turns=turns;
			if(wt==st) return betst_turns;
			if(wt<st){
				numWods_max=numWods-1;
			}
			else{
				numWodS_min=numWods+1;
			}
		}
		if(best_turns==1000000) return -1;
		return best_turns;
	}
};



//ancsik
public class EnemyTowers{
	public int attack(int myUnits,int hpT,int attackT,int numWodT,int numStoT)
	{
		int upper=myUnits;
		int lower=0;
		int hpW=numWodT*hpT;
		int hpS=numStoT*hpT;
		int best=Integer.MAX_VALUE;
		while(upper!=lower){
			int wUnits=(upper+lower)/2;
			int wRounds=calcRounds(wUnits,attackT,hpW,hpT);
			int sRounds=calcRounds(myUnits-wUntis,attackT,hpS,hpT);
			if(sRounds>wRounds){
				if(sRounds<best){
					best=sRounds;
				}
				if(wUnits!=upper){
					upper=wUnits;
				}
				else{
					break;
				}
			}
			else{
				if(wRounds<best){
					best=wRounds;
				}
				if(wUnits!=lower){
					lower=wUnits;
				}
				else{
					break;
				}
			}
		}
		if(best==Integer.MAX_VALUE){
			return -1;
		}
		return best;
	}
	private int calcRounds(int untis,int attack,int hp,int hpT){
		int rounds=0;
		while(hp>0 && units>0){
			hp-=units;
			units-=(hp%hpT==0) ? (hp/hpT)*attack:(1+hp/hpT)*attack;
			rounds++;
		}
		if(hp<=0){
			return rounds;
		}else{
			return Integer.MAX_VALUE;
		}
	}
};

// 

public class StrongEconomy{
	public long earn(long n, long k, long price,long target){
		long l=n;
		long s=k;
		long g=0;
		long t=0;
		long best=Long.MAX_VALUE;

		if(BigInteger.ValueOf(n).multiply(BigInteger.valueOf(k)).compareTo(BigInteger.valueOf(target))>=0)
		{
			return 1;
		}

		while(true){
			best=min(best,t+ru(target-g,f*s));
			if(f*s>target)
			  break;
			long dt=max(0,ru(price-g,f*s));

			g+=dt*f*s;
			t+=dt;
			g-=price;

			if(f<s)
			  f++;
			else
			  s++;
		}
		return best;
	}
	public long ru(long a,long b)
	{
		return (a+b-1)/b;
	}
}


typedef long long int64;
const int64 oo=10000000000LL*10000000000LL;

class RowGame{
public:
	int n,m;
	int64 G[110][110],F[110],E[110];
	pair<int64,int64> D[110];
	int64 score(vector<int> board,int _m)
	{
		int size=SIZE(board);
		m=_m;
		n=size+size;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) G[i][j]=-oo;
		for(int i=0;i<size;i++)
		  for(int j=0;j<size;j++)
		  {
			  if(i<=j)
			  {
				  int64 s=0;
				  for(int k=i;k<=j;k++) s+=board[k];
				  G[i][j+size]=s;
			  }
			  if(i>=j)
			  {
				  int64 s=0;
				  for(int k=j;k<=i;k++) s+=board[k];
				  G[i+size][j]=s;
			  }
		  }
		for(int i=0;i<n;i++) E[i]=0;
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
			if(G[i][j]!=-oo && G[j][i]!=-oo && G[i][j]>=0)
			  checkmax(E[i],G[i][j]+G[j][i]);
		for(int i=0;i<n;i++) F[i]=-oo;
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
			if(G[i][j]!=-oo)
			  checkmax(F[i],G[i][j]);
		for(int i=0;i<n;i++)
		  D[i]=MP(oo,oo);
		D[0]=MP(0,0);
		for(int step=0;step<n;step++)
		  for(int i=0;i<n;i++)
			if(D[i].first!=-oo)
			  for(int j=0;j<n;j++)
				if(G[i][j]!=-oo)
				{
					int64 tfirst=D[i].first;
					int64 tsecond=D[i].second;
					if(tsecond+G[i][j]<0)
					{
						if(E[i]<=0) continue;
						int64 cnt=(-tsecond-G[i][j]+E[i]-1)/E[i];
						tfirst+=cnt*2;
						tsecond+=E[i]*cnt;
					}
					tfirst++;
					tsecond+=G[i][j];
					if(tfirst<D[j].first || tfirst==D[j].first && tsecond>D[j].second)
					{
						D[j].first=tfirst;
						D[j].second=tsecond;
					}
				}
		int64 R=0;
		for(int i=0;i<n;i++)
		  if(D[i].first!=oo && D[i].first<=m)
		  {
			  int64 now=D[i].second;
			  checkmax(R,now);
			  if(D[i].first+1<=m)
				for(int j=0;j<n;j++)
				  if(G[i][j]!=-oo)
					checkmax(R,now+G[i][j]);
			  if(E[i]>0)
			  {
				  checkmax(R,now+(m-D[i].first)/2*E[i]);
				  if(m-D[i].first>=1)
					checkmax(R,now+(m-D[i].first-1)/2*E[i]+F[i]);
			  }
		  }
		return R;
	}
};

					


