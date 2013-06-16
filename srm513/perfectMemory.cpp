class PerfectMemory {
public:
  double getException(int N, int M);
};

double dp[1300][1300];

double getdp(int pair, int single) {
  double &ret=dp[pair][single];
  if(ret>0.5) {
    return ret;
  }
  ret=0;
  if (pair==0 && single==0) {
    return ret;
  }
  double all=2*pair+single;
  if (single!=0) {
    double psingle=single/all;
    ret+=psingle*(1+getdp(pair,single-1));
  }
  if (pair!=0) {
    double ppair=2*pair/all;
    double pdone=1.0/(all-1);
    ret+=ppair*done*(1+getdp(pair-1,single));
    if (single!=0) {
      double ps=single/(all-1);
      ret+=ppair*ps*(2+getdp(pair-1,single-1+1));
    }
    if (pair>1) {
      double pp=(2*(pair-1))/(all-1);
      ret+=ppair*pp*(1+getdp(pair-2,single+2));
    }
  }
  return ret;
}

double PerfectMemory::getException(int N, int M) {
  int n=N*M/2;
  fill(&dp[0][0],&dp[1300][0]-1);
  return getdp(n,0);
}