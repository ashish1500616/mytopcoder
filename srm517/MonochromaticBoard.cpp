class MonochromaticBoard{
public:
  int theMin(vector<string> board){
    int res=0;
    int r[50];
    int c[50];
    int onewhite=false;
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<50;i++)
      for(int j=0;j<50;j++) {
        r[i]=0;
        c[i]=0;
      }
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(board[i][j]=='W') {
          onewhite=true;
        } else {
          r[i]++;
          c[j]++;
        }
      }
    }
    if(!onewhite) {
      res=min(n,m);
      return res;
    }
    for(int i=0;i<n;i++) {
      if(r[i]==m) res++;
    }
    for(int j=0;j<m;j++) {
      if(c[j]==n) res++;
    }
    return res;
  }
};