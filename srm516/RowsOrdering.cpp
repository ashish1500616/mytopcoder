class RowsOrdering {
public:
  int order(vector<string>);
};

const int md=(int)(1e9+7);

int RowsOrdering::order(vector<string> s) {
  int n=s.size(),m=s[0].length(),i,j,cnt[444],a[444];
  for(j=0;j<m;j++) {
    for(i=0;i<256;i++) cnt[i]=0;
    for(i=0;i<n;i++) cnt[s[i][j]]++;
    sort(cnt,cnt+256);
    reverse(cnt,cnt+256);
    a[j]=0;
    for(i=0;i<256;i++) a[j]+=i*cnt[i];
  }
  sort(a,a+m);
  reverse(a,a+m);
  long long ans=n,v=1;
  for(i=0;i<m;i++) {
    ans=(ans+v*a[i])%md;
    v=v*50%md;
  }
  return ans;
}