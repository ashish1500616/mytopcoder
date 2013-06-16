class YetAnotherIncredibleMachine{
public:
  int countWays(vector<int>, vector<int>, vector<int>);
};

const int mod=1000000009;

int YetAnotherIncredibleMachine::countWays(vector<int> a, vector<int> b, vector<int> balls) {
  int n=SZ(a);
  long long res=1;
  REP(i,n) {
    int mult=1;
    FOR(j,a[i]-b[i],a[i]+1) {
      bool ok=true;
      REP(k,SZ(balls)) {
        if(balls[k]>=j && balls[k]<=j+b[i]) {
          ok=false;
          break;
        }
      }
      mult+=ok;
    }
    res*=mult;
    res%=mod;
  }
  return res;
}