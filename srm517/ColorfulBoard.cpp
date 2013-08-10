class ColorfulBoard {
public:
  int theMin(vector <string>);
};

char a[55][55];
int mm[110][110];

int doIt(vector<string> board){
  int n,m;
  n=board.size();
  m=board[0].size();
  res=100000000;
  for (int color=0;color<n;color++) {
    int cur=m;
    int ok=1;
    memset(mm,0,sizeof(mm));
    for (int i=0;i<n;i++) {
      char c=' ';
      for (int j=0;j<m;j++) {
        if (board[i][j]!=board[color][j]) {
          if (c==' ') {
            c=board[i][j];
          } else if(c!=' ' && c!=board[i][j]){
            ok=0;
            break;
          }
          mm[i][j+n]=1;
        }
      }
      
      if(c!=' ') {
        cur++;
        for(int j=0;j<m;j++) {
          if(board[i][j]!=c) {
            mm[j+n][i]=1;
          }
        }
      }
    
    }
    if (!ok) {
      break;
    }
    for(int k=0;k<n+m;k++) {
      for(int i=0;i<n+m;i++) {
        for(int j=0;j<n+m;j++) {
          mm[i][j]=mm[i][k]|mm[k][j];
        }
      }
    }
    bool cycle=false;
    for(int i=0;i<n+m;i++) {
      if(mm[i][i]==1) {
        cycle=true;
        break;
      }
    }
    if(cycle) {
      continue;
    } 
  
    res=min(res,cur);
  }
  return res;
}

int ColorfulBoard::theMin(vector<string> board) {
  
}