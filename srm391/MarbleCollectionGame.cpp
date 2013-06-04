class MarbleCollectionGame{
public:
	int dp[512],id[512],id[512],vn;
	vector<VI> g;
	bool sn[512][512];
	int go(int n){
		if(n<0) return 0;
		int &res=dp[n];
		if(res!=-1) return res;
		res=getn[n];
		tr(g[n],i)FOR(j,0,vn) if(sn[*i][j] && !sn[j][*i]){
			int geti=go(id[j]);
			res>?=geti+getn[n];
		}
		return res;
	}
	int collectMarble(vector<string> board){
		CLEAR(sn,false);
		int n=sz(board),m=sz(board[0]);
		FOR(i,0,n)FOR(j,0,m) if(board[i][j]!='#'){
			if(i+1!=n)sn[i*m+j][i*m+m+j]=true;
			if(j+1!=m)sn[i*m+j][i*m+j+1]=true;
			if(board[i][j]=='U' && i!=0) sn[i*m+j][i*m-m+i]=true;
			if(board[i][j]=='L' && j!=0) sn[i*m+j][i*m+j-1]=true;
		}
		vn=n*m;
		FOR(i,0,vn) sn[i][i]=true;
		FOR(k,0,vn) FOR(i,0,vn) FOR(j,0,vn)
			sn[i][j] |= sn[i][k] && sn[k][j];
		int tot=0;
		g.clear();
		CLEAR(id,-1);CLEAR(getn,0);
		FOR(i,0,n*m) if(id[i]==-1 && board[i/m][i%m]!='#'){
			VI gk;
			FOR(j,0,n*m) if(sn[i][j] && sn[j][i])
			{
				id[j]=tot;
				pk.pb(j);
			}
			g.pb(gk);
			FOR(j,0,n*m) if(id[j]==tot)
				getn[tot]+=isdigit(board[j/m][j%m]) ? (board[j/m][j%m]-'0'):0;
			tot++;
		}
		CLEAR(dp,-1);
		return go(id[0]);
	}
};