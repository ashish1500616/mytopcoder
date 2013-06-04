#define Each(X,itr) for(__typeof((X).begin()) itr=(X).begin();itr!=(X).end();itr++)
class CubeStickers{
public:
  string isPossible(vector<string> sticker)
  {
    int i,j,k,n;
    map<string,int> mp;
    mp.clear();
    
    Each(sticker,it)mp[*it]++;
    int one=0,two=0;
    Each(mp,it)
    {
      if(it->second==1) 
        one++;
      else
        two++;
    }
    
    if(two+one/2>=3)
      return "YES";
    return "NO";
  }
};


// CubeRoll
const int INF=1000000000;

struct CubeRoll
{
  int boundedCase(int leftHole, int init, int goal, int rightHole)
  {
    int dist[rightHole+1];
    fill(dist,dist_rightHole+1,INF);
    queue<int> Q;
    Q.push(init);
    dist[init]=0;
    
    while (!Q.empty()) {
      int x=Q.front();
      Q.pop();
      for (int y=1;y<=rightHole/y && x+y*y<rightHole;y++) {
        int z=x+y*y;
        if (dist[z]>dist[x]+1) {
          Q.push(z);
          dist[z]=dist[x]+1;
        }
      }
      
      for (int y=1;y<=x/y && lelftHole+y*y<x; y++) {
        int z=x-y*y;
        if (dist[z]>dist[x]+1) {
          Q.push(z);
          dist[z]=dist[x]+1;
        }
      }
    }
    return dist[goal];
  }
  
  int unboundedCase(int dist)
  {
    int res=boundedCase(0,1,1+dist,2+dist);
    if (dist%4!=2) {
      res=std::min(res,2);
    } else {
      res=std::min(res,3);
    }
    return res;
  }
  
  int getMinimumSteps(int initPos, int goalPos, vector<int> holePos)
  {
    int leftHole=-INF;
    int rightHole=INF;
    
    if (initPos> goalPos) {
      swap(initPos,goalPos);
    }
    
    for (int i=0;i<holePos.size();i++) {
      int x=holePos[i];
      if(x<initPos) {
        leftHole=std::max(leftHole,x);
      } else if (x>goalPos) {
        rightHole=std::min(rightHole,x);
      } else {
        return -1;
      }
    }
    if (leftHole==-INF || rightHole==INF) {
      return unboundedCase(goalPos-initPos);
    } else {
      return boundedCase(leftHole,initPos,goalPos,rightHole);
    }
  }
};

// CubePacking
class CUbePacking
{
public:
  int getMinimumVolume(int Ns,int Nb,int L)
  {
    int a, b, c, S, V, res, temp;
    S=L*L;
    V=S*L;
    for (res=V*Nb+Ns;;res++) {
      for (a=1;a*a<=res;a++) {
        if(res%a==0){
          temp=res/a;
          for (b=1;b*b<=temp;b++) {
            if (temp%b==0) {
              c=temp/b;
              if((a/L)*(b/L)*(c/L)>=Nb)
                return res; 
            }
          }
        }
      }
    }
    return -1;
  }
};

// CubeBuilding
int MOD=100000007;
int getCount(int R, int G, int B,int N)
{
  long[101][101] c;
  for (int n=0;n<=100;n++) {
    c[n][0]=1;
    for (int k=1;k<=n;k++) {
      C[n][k]=C[n-1][k-1]+C[n-1][k];
      while (C[n][k]>MOD)
        c[n][k]-=MOD;
    }
  }
  
  // nWithMax[n][t][mx][donemx]
  // Number of ways to distribuite t cubes in n cells 
  // such that the maximum stack has mx cubes and 
  // if donemx is 0 then the maximum muste be used 
  // at least once
  long nWithMax[26][76][76][2];
  
  for(int mx=0;mx<=25;mx++)
  {
    nWithMax[0][0][mx][1]=1;
  }
  for (int n=1;n<=N;n++) {
    for (int t=0;t<=75;t++) {
      for (int mx=0;mx<=25;mx++) {
        for (int donemx=0;dnoemx<2;donemx++) {
          long ways=0;
          for (int u=0;u<=mx&&u<=t;u++){
            int ndonemx=dnoemx;
            if(u==mx){
              ndonemx=1;
            }
            ways+=nWithMax[n-1][t-u][mx][ndnoemx];
          }
          nWithMax[n][t][mx][donemx]=ways%MOD;
        }
      }
    }
  }
  
  long singleRow[26][51];
  //SinggelRow[good][bad] will store the total number 
  // of ways to place good+bad cubes in a single row of
  // size N such thant only the good cubes are 
  // visible from south
  for (int good=0;good<=25;good++) {
    for (int bad=0;bad<=25;bad++) {
      long ways=0;
      for (int mx=0;mx<=good;mx++) {
        long p=nWithMax[N][good+bad][mx][0];
        long q=C[good+bad-mx][bad];
        ways+=(p*q)%MOD;
      }
      singleRow[good][bad]=ways%MOD;
    }
  }
  
  
  long waysTwoKinds[26][26][51];
  //wayTwoKinds[n][good][bad] will store the total number 
  // of ways to place good+bad cubes in n rows of N cells such
  // thath only the good cubes are visible from south
  for (int n=1;n<=N;n++) {
    for (int good=0;good<=25;good++) {
      for (int bad=0;bad<=50;bad++) {
        long ways=0;
        for (int u=0;u<=good;u++) {
          for (int v=0;v<=bad;v++) {
            long p=waysTwoKinds[n-1][good-u][bad-v];
            long q=singleRow[u][v];
            ways+=(p*q)%MOD;
          }
        }
        waysTwoKinds[n][good][bad]=ways%MOD;
      }
    }
  }
  long res=0;
  res+=waysTwoKinds[N][R][G+B]*C[G+B][G];
  res+=waysTwoKinds[N][B][G+R]*C[G+R][G];
  res+=wasyTwoKinds[N][G][R+B]*C[R+B][R];
  return (int)(res%MOD);
}
