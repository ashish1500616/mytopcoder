class CompositeSmash {
public:
  string thePossible(int, int);
};
 
int f[222222];
 
string CompositeSmash::thePossible(int N, int target) {
  int i,j;
  bool can,ok;
  for(i=1;i<=N;i++){
    if (i==target) {
      f[i]=1;
      continue;
    }
    ok=true;
    can=false;
    for (j=2;j*j<=i;j++) {
      if (i%j==0) {
        can=true;
        if(!(f[k]||f[i/k])) {
          ok=false;
        }
      }
    }
    if (can&&ok) {
      f[i]=1;
    } else {
      f[i]=0;
    }
  }
  if(f[N]) {
    return "Yes";
  } else {
    return "No";
  }
}