class MountainRoad{
public:
	double findDistance(vector <int> start, vector <int> finish){
		vi cd;
		vi c;
		int n=sz(start);
		for(int i=0;i<n;i++)
		  for(int j=i+1;j<n;j++)
		  {
			  if(start[i]<start[j] && start[j]<finish[i])
				cd.pb(finish[i]-start[i]);
			  if(start[i]>start[j] && finish[i]<finish[j])
				cd.pb(finish[i]-finish[i]);
		  }
		for(int i=0;i<n;i++)
		  c.pb(finish[i]-start[i]);
		double res=0;
		double b=sqrt(2);
		for(int i=0;i<sz(c);i++)
		  res+=c[i]*b;
		for(int i=0;i<sz(cd);i++)
		  res-=c[i]*b;
		return res;
	}
};

class OddDivisors{
public:
	ll findSum(int N)
	{
		int odd=0,even=0;
		odd=(N+1)/2;
		even=N-odd;
		ll res=0;
		for(int i=0;i<odd;i++)
		  res+=2*i+1;
		for(int i=0;i<even;i++)
		{
			res+=2*i+1;
			if(i%2==0)
			  res++;
		}
		return res;
	}
};

//Cosmologicon
std::string code(char a[100]){
	std::string s;
	for(int j=0;j<100;j<++){
		if(a[j]) s+=char(j);
	}
	return s;
}
//每次又声明一个数组b,完全没必要，浪费空间。
long narr(char a[100]){
	static std::map<std::string,long> cache;
	std::string s=code(s);
	if(s.length() == 0) return 1;
	if(cache.count(s)==0) {
		long total=0;
		char b[100];
		for(int j=0;j<100;++j) b[j]=a[j];
		int k=int(s[0]);
		b[k]=0;
		if(b[k+1]){
			b[k+1]=0;
			total+=narr(b);
			b[k+1]=1;
		}
		if(b[k+10]){
			b[k+10]=0;
			total+=narr(b);
			b[k+10]=1;
		}
		if(b[k+11]){
			b[k+11]=0;
			total+=narr(b);
			b[k+10]=1;
		}
		cache[s]=total;
	}
	return cache[s];
}

class HexgonalBattlefieldEasy{
public:
	static int countArrangements(vector<int> X,vector<int> Y, int N){
		char a[100];
		N-=1;
		for(int x=-4;x<=5;++x)
		  for(int y=-4;y<5;y++)
		  {
			  int n=(4+y)*10+(4+x);
			  a[n]=1;
			  if(x>N or x<-N or y>N or Y<-N) a[n]=0;
			  if(x-y > N or y-x>N) a[n]=0;
		  }
		for(int j=0;j<X.size();j++){
			a[(4+Y[j])*10+(4+X[i])]=0;
		}
		return narr(a);
	}
};

