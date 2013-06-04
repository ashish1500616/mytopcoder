class SoldierLabeling{
pubic:
	int bound(int n)
	{
		int r=0;
		while(n>0)
		{
			n=n/10;
			r++;
		}
		return r;
	}
	int count(int n,int lower,int upper)
	{
		int min,max;
		min=max=1;
		int res=0;
		for(int i=1;i<=n;i++)
		  if(bound(i)>=lower && bound(i)<=upper)
			res++;
		return res;
	}
};




int dx=[0,1,0,-1];
int dy=[1,0,-1,0];
int color[3][3]=[[1,3,1],[3,2,3],[1,3,1]];
class CubeWalking{
public:
	string finalPosition(string movement)
	{
		int n=sz(movement);
		int d=0;
		int x,y;
		x=y=1;
		for(int i=0;i<n;i++)
		{
			char cmd=movement[i];
			if(cmd=='L')
			{
				d=d-1;
				if(d<0) d+=4;
			}
			if(cmd=='R')
			{
				d=d+1;
				if(d>3) d-=4;
			}
			if(cmd=='W')
			{
				int nx,ny;
				nx=(x+dx[d])%3;
				if(nx<0) nx+=3;
				ny=(y+dy[d])%3;
				if(ny<0) ny+=3;
				x=nx;
				y=ny;
			}
		}
		string res;
		int c=color[x][y];
		if(c==1) res="RED";
		if(c==2) res="GREEN";
		if(c==3) res="BLUE";
		return res;
	}
};




struct pp{
	ll a;
	ll b;
	ll c;
	pp(ll i,ll j, ll k):a(i),b(j),c(k){}
};
struct peg{
	pp s;
	int c;
	peg(pp z,int cc):s(z),c(cc){}
};

bool operator<(const pp& a, const pp& b){
	if(a.a!=b.a) return a.a<b.a;
	if(a.b!=b.b) return a.b<b.b;
	return a.c<b.c;
}

bool operator==(const pp& a, const pp& b){
	return a.a==b.a && a.b==b.b && a.c==b.c;
}

set<pp> vis;

long long conv(const string& a){
	long long r=0;
	for(int i=0;i<a.size();i++)
	  r=r*4+(a[i]-'A' +1);
	return r;
}

long long sconv(const string& a,const string& b, const string& c)
{
	return conv(a)*1048576LL*1048576LL + conv(b)*1048576LL + conv(c);
}

class HanoiTower{
public:
	int moves(string pegA,string pegB,string pegC){
		int r=0;
		queue<peg> q;
		q.push(peg(pp(conv(pegA),conv(pegB),conv(pegC)),0));
		int numA=0,numB=0,numC=0;
		string big=pegA+pegB+pegC;
		for(int i=0;i<big.size();i++){
			if(big[i]=='A') numA++;
			else if(big[i]=='B') numB++;
			else numC++;
		}
		string tA=string(numA,'A'),tB=string(numB,'B'),tc=string(numC,'C');
		pp target=pp(conv(tA),conv(tB),conv(tC));
		while(!q.empty()){
			peg z=q.front();q.pop();
			if(z.s==target) return z.c;
			if(vis.count(z.s)!=0) continue;
			vis.insert(z.s);
			ll aa=z.s.a;
			ll bb=z.s.b;
			ll cc=z.s.c;
			int(aa>0){
				int m=aa%4;
				q.push(peg(pp((aa-m)/4,bb*4+m,cc),z.c+1));
				q.push(peg(pp((aa-m)/4,bb,cc*4+m),z.c+1));
			}
			if(bb>0){
				int m=bb%4;
				q.push(peg(pp(aa*4+m,(bb-m)/4,cc),z.c+1));
				q.push(peg(pp(aa,(bb-m)/4,cc*4+m),z.c+1));
			}
			if(cc>0){
				int m=cc%4;
				q.push(peg(pp(aa*4+m,bb,(cc-m)/4),z.c+1));
				q.push(peg(pp(aa,bb*4+m,(cc-m)/4),z.c+1));
			}
		}
		return r;
	}
};
							

					



