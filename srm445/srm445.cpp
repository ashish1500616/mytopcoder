class TheEncryptionDivTwo{
public:
	string encrpypt(string mess)
	{
		int id=0;
		map<char,char> mp;
		int n=sz(mess);
		string ret;
		for(int i=0;i<n;i++)
		{
			if(!present(mp,mess[i]))
			  mp[mess[i]]='a'+id,id++;
			ret+=mp[mess[i]];
		}
		return ret;
	}
};	

class TheEncryptionDivTwo{
public:
	string encrypt(string message)
	{
		map<char,char> m;
		int id=0;
		int n=sz(message);
		string res;
		for(int i=0;i<n;i++)
		{
			if(present(m,message[i])){
				res+=m[message[i]];
			}else{
				char nc='a'+id;
				debug(nc)
				id++;
				m[message[i]]=nc;
				res+=nc;
			}
		}
		return res;				
	}
};




class TheNewHouseDivTwo{
public:
	int count(vector<int> x,vector<int> y)
	{
		int m[200][200];
		int res=0;
		memset(m,0,sizeof(m));
		int minx,miny,maxx,maxy;
		minx=*min_element(all(x));
		maxx=*max_element(all(x));
		miny=*min_element(all(y));
		maxy=*max_element(all(y));
		int n=sz(x);
		for(int i=0;i<n;i++)
		{
			m[x[i]+100][y[i]+100]=1;
		}

		minx+=100;
		miny+=100;
		maxx+=100;
		maxy+=100;

		for(int nx=minx+1;nx<maxx;nx++)
		  for(int ny=miny+1;ny<maxy;ny++)
		  {
			  if(m[nx+1][ny]==1 && m[nx-1][ny]==1 && m[nx][ny+1]==1 && m[nx][ny-1]==1) res++;
		  }
		return res;
	}
};


class TheLockDivTwo{
public:
	string password(int n,int k)
	{
		int N=1<<n;
		int a,b,c;
		a=0;
		set<int> m;
		m.insert(a);
		for(int i=1;i<k;)
		  for(b=0;b<N;b++)
		  {
			  c=a^b;
			  int c2=c&a;
			  if((c2==c || c2==0) && !present(m,b))
			  {
				  a=b;
				  m.insert(a);
				  i++;
				  break;
			  }
		  }
		string ret;
		for(int k=0;k<n;k++)
		{
			if(a&1)
			  ret='1'+ret;
			else
			  ret='0'+ret;
			a=a>>1;
		}
		return ret;
	
	}
};

class TheLockDivTwo{
public:
	string password(int n, int k)
	{
		set<int> m;
		int N=1<<n;
		int i=1;
		int a=0;
		m.insert(a);
		while(i<k)
		{
		  for(int b=0,step=0;step<N;b=(b+1)%N,step++)
		  {
		  	  if(a==b) continue;
			  int c=a^b;
			  int c2=c&a;
			  if((c==c2 || c2==0) && !present(m,b))
			  {   			  	  
				  a=b;
				  i++;
				  m.insert(b);
				  break;
			  }
		  }
		}
		string ret;
		debug(a)
		for(int j=0;j<n;j++)
		{
			if(a & 1) ret='1'+ret;
			else ret='0'+ret;
			a=a>>1;
		}
		return ret;
	}
};

		  

class TheEncryptionDivOne{
public:

	int count(string msg,string encMsg)
	{
		int ret;
		int n=sz(msg);
		int am[52];
		memset(am,-1,sizeof(am));
		int bm[52];
		memset(bm,-1,sizeof(bm));
		int a,b;
		for(int i=0;i<n;i++)
		{
			a=(msg[i]-'a')>=0?(msg[i]-'a'):(msg[i]-'A'+26);
			b=(encMsg[i]-'a')>=0?(encMsg[i]-'a'):(encMsg[i]-'A'+26);
			int c=abs(a-b);
			if(c==26 || c==0) return 0;
			if(am[a]!=-1 && am[a]!=b) return 0;
			if(am[a]==-1)
			{
				am[a]=1;
				bm[b]=1;
			}
		}

		vi va,vb;
		for(int i=0;i<52;i++)
		{
			if(am[i]==-1) va.pb(i);
			if(bm[i]==-1) vb.pb(i);
		}

		int c,c0,c1,c2,cov;
		c0=c1=c2=cov=0;
		c=sz(va);
		for(int i=0;i<c;i++)
		{
			cov=0;
			for(int j=0;j<c;j++)
				if(abs(va[i]-vb[j])==26 || abs(va[i]-vb[j])==0)
				  cov++;
			if(cov==0)
			  c0++;
			if(cov==1)
			  c1++;
			if(cov==2)
			  c2++;
		}
		
		ret=getP(c)-c1*getP(c-1)-c2*getP(c-2);
		return ret;
	}
	ll getP(int i)
	{
		if(i==0) return 1;
		return i*getP(i-1)%module;
	}

};