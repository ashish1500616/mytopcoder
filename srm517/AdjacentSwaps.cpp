class AdjacentSwaps {
public:
  int theCount(vector <int>);
};
 
const int md = (int)(1e9+7);
int f[55][55], d[55][55];

int AdjacentSwaps::theCount(vector<int> p) {
  int i,j,k,q,ok,ft;
  int b[55],c[55];
  memset(d,0,sizeof(d));
  for(i=0;i<=50;i++) {
    d[i][0]=1;
  }
  for (i=0;i<=50;i++) {
    for (j=0;j<=i;j++) {
      d[i][j]=(d[i-1][j]+d[i-1][j-1])%md;
    }
  }
  
  memset(f,0,sizeof(f));
  for (i=n-1;i>=0;i--) {
    for (j=i;j<n;j++) {
      if (i==j) {
        f[i][j]=1;
      } else {
        f[i][j]=0;
        memset(b,0,sizeof(b));
        for(k=i;k<=j;k++) {
          b[k]=p[k];
        }
        sort(b+i,b+j+1);
        for (k=i;k<j;k++) {
          memset(c,0,sizeof(c));
          for (int q=i;q<k;q++) {
            c[b[q]]=1;
          }
          c[b[k+1]]=1;
          ok=1;
          for (q=i;q<=k;q++) {
            if(!c[p[q]]) {
              ok=0;
              break;
            }
          }
          if (ok) {
            ft=f[i][k]*f[k+1][j]%md;
            ft=ft*d[j-i-1][k-i+1-1];
            f[i][j]=(f[i][j]+ft)%md;
          }
        }
      }
    }
  }
  return f[0][n-1];
}