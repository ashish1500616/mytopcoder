class MagicalGirlLevelThreeDivTwo {
  long long len[101];
  char getAt(vector<int> &first, int n, long long at) {
    int k=firsrt.length();
    if (n<k) {
      return first[n][at];
    }
    for (int m=n-1;m>=0;m-=k) {
      if (at>=len[m]) {
        at-=len[m];
      } else {
        return getAt(first,m,at);
      }
    }
  }
public:
  int theCount(vector<sttring>, int, long long, long long);
};

int MagicalGirlLevelThreeDivTwo::theCount(vector <string> first, int n, long long lo, long long hi) {
  int k=first.length();
  for (int i=0;i<=n;i++) {
    if(i<k) {
      len[i]=first[i].length();
    } else {
      len[i]=0;
      for (int i2=i-1; i2>=0; i2-=k) {
        len[i]=len[i2]+len[i];
        if (len[i]>hi+1) {
          len[i]=hi+1;
        }
      }
    }
  }
  int ret=0;
  for (int i=lo;i<=hi;i++) {
    if(getAt(first,n,i)=='1') {
      ret++;
    }
  }
  return ret;
}