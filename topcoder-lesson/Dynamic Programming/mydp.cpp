using namespace std;
 
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence) 
  {
    if(sequence.size() == 1) return 1;
    vector<int> v(sequence.size()-1);
    for(int i=1;i<sequence.size();i++)
    {
      v[i-1] = sequence[i] - sequence[i-1];
    }
    //    dir is first nonzero
    int ii=0;
    while( ii < v.size() && v[ii] == 0)
    ii++;
    if(ii == v.size()) return 1;
    int dir = v[ii];
    int len = 2;
    for(int i=ii+1;i<v.size();i++)
    {
      if(v[i] * dir < 0)
      {
        dir *= -1;  
        len++;
      }
    }
    return len;
  }
};
 
 
 //BadNeighbors 
 class BadNeighbors 
{
  public:
  map<int, int> answer;
  vector<int> blah;
  
  int getAnswer(int i1, int i2)
  {
    int key = i1*500+i2;
    if (answer.count(key)) return answer[key];
    if (i1 > i2) return 0;
    answer[key] = MAX(getAnswer(i1+1,i2), getAnswer(i1+2,i2)+blah[i1]);
    return answer[key];
  }
  
  int maxDonations(vector <int> donations) 
  {
    blah = donations;
    int n = donations.size();
    return MAX(getAnswer(0,n-2), getAnswer(1,n-1));
  }
};



//FlowerGarden
char buf1[1000];
 
string i2s(int x) {
  sprintf(buf1,"%d",x);
  return buf1;
}
 
 
struct FlowerGarden {
  // MAIN
  vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
    int n = size(height);
    vector<bool> done(n,false);
    vector<int> res(n);
    REP(i,n) {
      int best = -1;
      REP(j,n) if(!done[j]) {
        bool ok = true;
        REP(k,n) if(k!=j && !done[k] && height[k]<height[j] &&
            bloom[k]<=wilt[j] && wilt[k]>=bloom[j]) ok = false;
      // I think the follow is right.
      //if(ok && (best==-1 || height[j]<height[best])) best=j;
        if(ok && (best==-1 || height[j]>height[best])) best=j;
      }
      res[i] = height[best];
      done[best] = true;
    }
    return res;
  }
  
 
 
};


//AvoidRoads
typedef long long i64;
 
i64 ans[ 102 ][ 102 ];
 
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
 
class AvoidRoads {
  public:
  long long numWays(int width, int height, vector <string> bad) {
    ans[ 0 ][ 0 ] = 1;
    set< pair< pair< int, int >, pair< int, int > > > nt;
    for( int i = 0; i < bad.size(); i++ ) {
      vector< int > st = sti( tokenize( bad[ i ], " " ) );
      nt.insert( make_pair( make_pair( st[ 0 ], st[ 1 ] ), make_pair( st[ 2 ], st[ 3 ] ) ) );
      nt.insert( make_pair( make_pair( st[ 2 ], st[ 3 ] ), make_pair( st[ 0 ], st[ 1 ] ) ) );
    }
    for( int x = 0; x <= width; x++ ) {
      for( int y = 0; y <= height; y++ ) {
        for( int k = 0; k < 2; k++ ) {
          int tx = x + dx[ k ];
          int ty = y + dy[ k ];
          if( !nt.count( make_pair( make_pair( x, y ), make_pair( tx, ty ) ) ) ) {
            ans[ tx ][ ty ] += ans[ x ][ y ];
          }
        }
      }
    }
    return ans[ width ][ height ];
  }
};


//ChessMetric
using namespace std; 

long long ways[100][100][55]; 

const int dx[16]={1,1,1,0,-1,-1,-1,0, 2,1,-1,-2,-2,-1,1,2}; 
const int dy[16]={1,0,-1,-1,-1,0,1,1, -1,-2,-2,-1,1,2,2,1}; 

class ChessMetric { 
  public: 
  long long howMany(int size, vector <int> start, vector <int> end, int nomoves) { 
    int x,y,i,j; 
    for(x=0;x<100;x++) for(y=0;y<100;y++) for(i=0;i<55;i++) ways[y][x][i]=0; 
    int sx=start[0],sy=start[1],ex=end[0],ey=end[1]; 
    ways[sy][sx][0]=1; 
    for(i=1;i<=nomoves;i++) { 
      for(x=0;x<size;x++) 
        for(y=0;y<size;y++) { 
          for(j=0;j<16;j++) { 
            int nx=x+dx[j]; 
            int ny=y+dy[j]; 
            if (nx<0 || ny<0 || nx>=size || ny>=size) continue; 
            ways[ny][nx][i]+=ways[y][x][i-1]; 
          } 
        } 
    } 
    cout << ways[ey][ex][nomoves] << endl; 
    return ways[ey][ex][nomoves]; 
  } 
}; 





//StripePainter
#define FORI(i,n) for(int i=0;i<(n);i++)
#define FORIS(i,s,n) for(int i=(s);i<(n);i++)
#define NUM55
int mem[NUM][NUM];

class StripePainter{
	int N;
	string s;
	int dp(int s,int e){
		if(s>e) return 0;
		if(s==e) return 1;
		int &res=mem[s][e];
		if(res>-1) return res;
		res=1+dp(s+1,e);
		FORIS(i,s+1,e+1){
			if(S[i]==S[s])
			{
				res=min(res,dp(s+1,i)+dp(i+1,e));
			}
		}
		return res;
	}
public:
	int minStrokes(string stripes){
		N=sz(stripes);
		S=stripes;
		memset(mem,-1,sizeof(mem));
		return dp(0,N-1);
	}
};





//QuickSums 
using namespace std;
 
class  QuickSums  {
public:
int s,target,mini;
int data[15];
char f;
string bil;
 
int go(int len,int start) {
  int i,j,k;
  long long res,m1;
  if(start==s) {
    res=0; k=0;
    for(i=0;i<len;i++) {
      m1=bil[k]-'0';
      for(j=k+1;j<=data[i];j++)
        m1=m1*10+(bil[j]-'0');
    //  cout<<m1<<endl;
      res+=m1; k=data[i]+1;
    }
    if(res==target) {
      f=1;
      if(mini>len-1) mini=len-1;
    }    
  //  cout<<res<<endl;
  }
  for(i=start;i<s;i++) {
    data[len]=i;
    go(len+1,i+1);
  }
  return 1;
}
 
int minSums (string num, int sum) {
  s=num.size();
  bil=num; mini=1000;
  long long temp;
  target=sum;
  f=0;
  sscanf(num.c_str(),"%lld",&temp);
  if(temp==sum) return 0;
  go(0,0);
  if(!f) return -1;
  return mini;
}
 
 
};


////StarAdventure
vector<string> board;
int dp[2][50+5][50+5][50+5];

class StartAdventure{
public:
	int getScore(int x,int y){
		return board[x-1][y-1]-'0';
	}
	int getScore(int x,int y1,int y2, int y3){
		return getScore(x,y1)+getScore(x,y2)+getScore(x,y3);
	}
	int mostStars(vector<string> level){
		int rows=level.size();
		int cols=level[0].size();
		board=level;
		if(cols<=3){
			int res=0;
			for(int i=1;i<=rows;++i)
			  for(int j=1;j<=cols;++j)
				rew+=getScore(i,j);
			return res;
		}
		memset(dp,0,sizeof(dp));
		for(int r=1;r<=rows;++r){
			memset(dp[(r+1)&1],0,sizeof(dp[(r+1)&1]));
			// 0)Move down
			for(int i=1;i<=cols;++i)
			  for(int j=i+1;j<=cols;++j)
				for(int k=j+1;k<=cols;++k)
				  dp[(r+1)&1][i][j][k]>?=dp[r&1][i][j][k]+getScore(r,i,j,k);
			// 1) Move the leftmost column.
			for(int i=1;i<=cols;++i)
			  for(int j=i+2;j<=cols;++j)
				for(int k=j+1;k<=cols;++k)
				  dp[(r+1)&1][i+1][j][k]>?=dp[(r+1)&1][i][j][k]+getScore(r,i+1);
			// 2) Move the middle column
			for(int i=1;i<=cols;++i)
			  for(int j=i+1;j<=cols;++j)
				for(int k=j+2;k<=cols;++k)
				  dp[(r+1)&1][i][j+1][k]>?=dp[(r+1)&1][i][j][k]+getScore(r,j+1);
			// 3) Move the right column
			for(int i=1;i<=cols;++i)
			  for(int j=i+1;j<=cols;++j)
				for(int k=j+1;k+1<=cols;++k)
				  dp[(r+1)&1][i][j][k+]>?=dp[(r+1)&1][i][j][k]+getSrore(r,k+1);
		}
		return dp[(rows+1)&1][cols-2][cols-1][cols];
	}
};


using namespace std;
 
int len[50][50];
int pad[50][50];
int n;
 
// ShortPalindromes
/**
 shortest(base)
      if base is already a palindrome then
          return base
      if base has the form A...A then
          return A + shortest(...) + A
      if base has the form A...B then
          return min(A + shortest(...B) + A,
                     B + shortest(A...) + B)
*/
map<string,string> mp;

bool IsPalindrome(string s)
{
	int N=s.size();
	for(int i=0;i<=N/2;++i)
	  if(s[i]!=s[N-i-1]) return false;
	return true;
}

class ShortPalindromes{
public:
	string shortest(string base){
		if(Ispalindrome(base)) return base;
		mp.clear();
		::shortest(base);
		return mp[base];	
}
string shortest(string base)
{
		if(IsPalindrome(base)) return base;
		if(mp.count(base)) return my[base];
		int N=base.size();
		if(base[0]==base[N-1])return my[base]=base[0] + shortest(base.substr(1,N-2))+base[0];
		string ret1=base[0]+shortest(base.substr(1))+base[0];
		string ret2=base[N-1]+shortest(base.substr(0,N-1))+base[N-1];
		if(ret1.size()<ret2.size()) return mp[base]=ret1;
		if(ret1.size()>ret2.size()) return mp[base]=ret2;
		return mp[base]=min(ret1,ret2);
}



int mem1[55][3005];//
int mem2[55][55][55][3];

class MiniPaint{
	VS picture;
	int maxStrokes;
	int W,H;

	int dp2(int x,int y,int colr,int strk)
	{
		if(x>=W)return 0;
		int &res=mem2[x][y][strk][colr];
		if(res>-1)return res;
		int cur=(picture[y][x]=='B')?1:2;
		if(cur==colr) return res=dp2(x+1,y,colr,strk);
		res=dp2(x+1,y,colr,strk)+1;
		if(strk>0)
		  res=min(res,dp2(x+1,y,cur,strk-1));
		return res;
	}

	int dp1(int row, int strk)
	{
		if(row>=H) return 0;
		int &res=mem1[row][strk];
		if(res>-1) return res;
		int max_str_row=1;
		FORI(i,W-1) if(picture[row][i]!=picture[row][i+1]) max_str_row++;
		max_str_row=min(max_str_row,strk);
		FORI(n,max_str_row){
			int cur=dp2(0,row,0,n);
			int tst=cur+dp1(row+1,strk-n);
			res=(res==-1)?tst:min(res,tst);
		}
		return res;
	}
public:
	int leastBad(VS _picture,int _maxStrokes){
		picture=_picture;
		maxStrokes=_maxStrokes;
		H=SZ(picture);
		W=SZ(picture);
		memset(mem1,-1,sizeof(mem1));
		memset(mem2,-1,sizeof(mem2));
		return dp1(0,maxStrokes);
	}
};