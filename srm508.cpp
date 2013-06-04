int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R)
{
  int ret=0;
  for (int sx=-200, sx<=200;sx++) {
    for (int sy=-200,sy<200;sy++) {
      bool good=true;
      for (int i=0;i<X.size();i++) {
        int left=abs(X[i]-sx)+abs(Y[i]-sy);
        if (left>R[i]) {
          good=false;
        }
      }
      if (good) {
        ret++;
      }
    }
  }
  return ret;
}

//DivideAndShift

class DivdeAndShift{
public:
  int getLeast(int N, intM)
  {
    --M;
    int ret=10000000;
    for (int last=1;last<=N;last++) {
      if(N%last!=0) 
        continue;
      int cur=numDivsors(N/last)+min(M%last, last-M%last);
      ret=min(ret,cur);
    }
    return ret;
  }
  int numDivsors(int x){
    int ret=0;
    for (int i=2;i*i<=x;i++) {
      while (x%i==0) {
        ret++;
        x/=i;
      }
    }
    if(x>1) ++res;
    return res;
  }
};

// YetAnotherORProblem2
const int MOD=100000000009;
struct YetAnotherORProblem2
{
  int N, R;
  long long mem[31][11];
  
  long long rec(int T, int nequal)
  {
    long long &res=mem[T][nequal];
    
    if (res==-1) {
      res=0;
      int p=T-1;
      if (T==0) {
        //Base case
        res=1;
      } else if (nequal==N) {
        //all the rows are still equal
        if (R&(1<<p)) {
          //a) use 0 in all bits of this column
          // all the rows become smaller than R
          res=rec(T-1,0);
          
          //b) use 1 in one of the N rows. The other
          // rows must have 0 in this column.
          // only one row will remain nequal.
          res+=(N*rec(T-1,1));
        } else {
          // all bits in this column must be zero
          res=rec(T-1,N);
        }
      } else if (nequal==1) {
        // only one row is still equal to R 
        if (R&(1<<p)) {
          //a) use 0 in the equal row
          // and 0 in all of the other rows.
          res=rec(T-,0);
          
          //b) use 0 in the equal row
          // and in the one of the other rows.
          res+=(N-1)*rec(T-1,0);
          
          //c) use 1 in the equal row. 0 is forced
          // in the remaining rows.
          res+=rec(T-1,1);
        } else {
          //the p-th bit in the equal row must be 0.
          // at most one of the other bits can be 1.
          res=rec(T-1,1);
          res+=((N-1)*rec(T-1,1));
        }
      } else {
        // none of the rows is equal to $R
        res=rec(T-1,0);
        res+=N*rec(T-1,0);
      }
      res%=MOD;
    }
    return res;
  }
  int countSequences(int N, int R)
  {
    this->N=N;
    this->R=R;
    memset(mem,-1,sizeof(mem));
    return (int)(rec(30,N)%MOD);
  }
};

// YetAnotherORProblem
const int MOD=10000000009;
struct YetAnotherORProblem
{
  long long mem[1<<10][61];
  int N;
  vector<long long> R;
  long long rec(int lowerSet, int T) {
    long long & res = mem[lowerSet][T];
    if (res==-1) {
      res=0;
      if (T==0) {
        res=1;
      } else {
        int p = T-1;
        // Assign bits for the p-th position:
        // all zero, zlowerSer is the new set of
        // all row lower than their R[i]s after assigning
        // a 0 to them.
        int zlowerSet = lowerSet;
        for (int i=0;i<N;i++) {
          if (!(lowerSet&(1<<i))&&(R[i]&(1<<p))) {
            zlowerSet+=1<<i;
          }
        }
        res = rec(zlowerSet, T-1);
        
        //exactly one is 1:
        for (int o=0;o<N;o++) {
          int nlowerSet = lowerSet;
          for (int i=0;i<N;i++) if (i!=o) {
            if(!(lowerSet&(1<<i))&&(R[i]&(1<<p))) {
              nlowerSet+=1<<i;
            }
          }
          if(!(lowerSet&(1<<o))) {
            if(R[o]&(1<<p)) {
              // Tht p-th bit of R[o] is 1
              // we can use a 1 bit in row o.
            } else {
              // we cannot do it.
              // the number must be <=R[i]
              continue;
            }
          } else {
            // already smaller, we can use any value for this row
          }
          res += rec(nlowerSet, T-1);
        }
        res%=MOD;
      }
    }
    return res;
  }
};


// NumberLabyrinthDiv2
const int INF=100000000000000;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct NumberLabyprintDiv2
{
  int getMinimumNumberOfMoves(vector<string> board, int r1, int c1, int r2, int c2, int K)
  {
    int R=board.size();
    int C=board[0].size();
    int distance[50][50][51];
    
    // Fill distance matrix with large numbers:
    for (int r=0;i<R;i++) {
      for(int c=0;c<C;c++) {
        for(int k=0;k<=K;k++) {
          distance[r][c][k]=INF;
        }
      }
    }
    
    // we start at vector (r1,c1,K):
    distance[r1][c1][K]=0;
    
    queue<int> Q;
    //Each cell is represented by (r,c,k), instead
    // of using a more complicated queue that holds
    // 3 values in each of its nodes, we can push
    // three different values at a time and then
    // pop them in order in each step:
    Q.push(r1);
    Q.push(c1);
    Q.push(K);
    while(!Q.empty()) {
      int r=Q.front();Q.pop();
      int c=Q.front();Q.pop();
      int k=Q.front();Q.pop();
      
      if(r==r2 && c==c2) {
        return distance[r2][c2][k];
      }
      
      //Pick appropriate values for d
      for (int d=1; d<=9; d++) {
        for(int t=0;t<4;t++) {
          bool subk=((board[r][c]=='.') && (k>0));
          
          if(subk||board[r][c]-'0' ==d ) {
            int nr=r+dx[t]*d;
            int nc=c+dy[t]*d;
            int nk=k-(subk?1:0);
            
            if((nr>=0 && nc>=0 && nr<R && nc<C) && distance[nr][nc][nk]>distance[r][c][k]+1) {
              distance[nr][nc][nk]=distance[r][c][k]+1;
              Q.push(nr);
              Q.push(nc);
              Q.push(nk);
            }
          }
        }
      }
    }
    return -1;
  }
};



