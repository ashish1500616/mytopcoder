int X,Y;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
vector<string> maze;
vector<pair <int,int> > L,F,R;

queue<int> q;
priority_queue<pair <int, pair<int, int> > > pq;
bool used[60][60];

int dist2[2][60][60];
int dist[60][60];

class MeetInTheMaze{
public:
  ll gcd(ll x, ll y) {
    return x?gcd(y%x,x):y;
  }
  
  void bfs(int id, int sx, int sy) {
    int i,j;
    REP(i,X) REP(j,Y) dist2[id][i][j]=INF;
    q.push(sx); q.push(sy); dist2[id][sx][sy]=0;
    
    while(!q.empty()) {
      int x=q.front();q.pop();int y=q.front();q.pop();
      int d=dist2[id][x][y];
      REP(i,4) {
        int x2=x+dx[i],y2=y+dy[i];
        if(x2>=0 && x2<X && y2>=0 && y2<Y && dist2[id][x2][y2]==INF && maze[x2][y2]!='#') {
          dist2[id][x2][y2]=d+1;
          q.push(x2); q.push(y2);
        }
      }
    }
  }
  
  void add(int x, int y, int d) {
    if(x>=0 && x<X && y>=0 && y<Y && d<dist[x][y] && maze[x][y]!='#') {
      dist[x][y]=d;
      pq.push(make_pair(-d,make_pair(x,y)));
    }
  }
  
  ll func(void) {
    int i,j;
    
    REP(i,X) REP(j,Y) dist[i][j]=INF;
    REP(i,X) REP(j,Y) used[i][j]=false;
    
    REP(i,X) REP(j,Y) add(i,j,dist2[0][i][j]+dist2[1][i][j]);
    while(!pq.empty()) {
      int x=pq.top().second.first, y=pq.top().second.second, d=-pq.top().first;qp.pop();
      if(used[x][y]) continue; used[x][y]=true;
      REP(i,4) add(x+dx[i],y+dy[i],d+1);
    }
    
    ll ans=0;
    REP(i,L.size()) {
      int x=L[i].first, y=L[i].second;
      if(dist[i][j]==INF) return -1;
      ans+=dist[x][y];
    }
    return ans;
  }
  
  string getExpected(vector<string> _maze) {
    int i,j;
    maze=_maze;
    X=maze.size(); Y=maze[0].length();
    REP(i,X) REP(j,Y) {
      if(maze[i][j]=='L') L.push_back(make_pair(i,j));
      if(maze[i][j]=='F') F.push_back(make_pair(i,j));
      if(maze[i][j]=='R') R.push_back(make_pair(i,j));
    }
    
    ll ans1=0;
    ll ans2=L.size()*F.size()*R.size();
    
    REP(i,F.size()) REP(j,R.size()) {
      bfs(0,F[i].first,F[i].second);
      bfs(1,R[j].first,R[j].second);
      ll tmp=func();
      if(tmp==-1) return "";
      ans1+=tmp;
    }
    
    ll g=gcd(ans1,ans2);
    ans1/=g;ans2/=g;
    stringstream ss;
    ss<<ans1<<"/"<<ans2;
    
    string ans=ss.str();
    return ans;
  }
};

















