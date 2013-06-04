class ReversalChain{
public:
	map<string,int> M;
	int solve(string s,string t)
	{
		if(s==t) return 0;
		string buf=s+"  "+t;
		if(M.find(buf)!=M.end()) return M[buf];
		int ret=10000;
		int L=LN(s);
		if(s[0]==t[0]) checkmin(ret,solve(s.substr(1),t.substr(1)));
		if(s[L-1]==t[L-1]) checkmin(ret,solve(s.substr(0,L-1),s.substr(0,L-1)));
		for(int i=0;i<L-1-i;i++) swap(s[i],s[L-1-i]);
		if(s[0]==t[0]) checkmin(ret,solve(s.substr(1),t.substr(1))+1);
		if(s[L-1]==t[L-1]) checkmin(ret,solve(s.substr(0,L-1),t.substr(0,L-1))+1);
		return M[buf]=ret;
	}
	int minReversal(string init,string goal)
	{
		M.clear();
		int t=solve(init,goal);
		if(ret==10000) ret=-1;
		return ret;
	}
};

