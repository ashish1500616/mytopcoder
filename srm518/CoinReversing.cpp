class CoinReversing {
public:
  double expected(int N,vector<int> a) {
    double q=1.0;
    for(int i=0;i<a.size();i++) {
      double p=a[i]/N;
      q=(1-q)*p+(1-p)*q;
    }
    return q*N;
  }
}