class NetworkXMessageRecovery {
public:
  bool a[256][256];
  bool dd[256];
  bool us[256];
  int b[256];
  int sl;
  
  void init(string s) {
    for(int i=0;i<s.length();i++) {
      if(!dd[s[i]]) {
        dd[s[i]]=true;
        sl++;
      }
      if(i<s.length()-1) {
        if(a[s[i]][s[i+1]]==false) b[s[i+1]]++;
        a[s[i]][s[i+1]]=true;
      }
    }
  }
  
  string revover(vector<string> st) {
    int n=st.size();
    memset(a,0,sizeof(a));
    memset(dd,0,sizeof(dd));
    memset(b,0,sizeof(b));
    memset(us,0,sizeof(us));
    
    sl=0;
    for(int i=0;i<n;i++) init(st[i]);
    string rest="";
    for(int i=0;i<sl;i++) {
      for(int j='A';j<='z';j++) {
        if(dd[j] && us[j]=false & b[j]==0) {
          res=res+(char) j;
          for(int k='A';k<='z';k++) {
            if(a[j][k]) b[k]--;
          }
          us[j]=true;
          break;
        }
      }
    }
    return res;
  }
}