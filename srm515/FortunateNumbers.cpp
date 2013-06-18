class FortunateNumbers {
public:
  int check(int a) {
    int r;
    while (a!=0) {
      r=a%10;
      if(r!=5 && r!=8) return 0;
      a=a/10;
    }
    return 1;
  }
  
  int getFortunate(vector<int> a, vector<int> b, vector<int> c) {
    int i,j,k;
    set<int> st;
    for (i=0;i<a.size();i++) {
      for (j=0;j<b.size();j++) {
        for (k=0;k<c.size();k++) {
          tmp=a[i]+b[j]+c[k];
          if(check(tmp)) {
            st.insert(tmp);
          }
        }
      }
    }
    return st.size();
  }
}