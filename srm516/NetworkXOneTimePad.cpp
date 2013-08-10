class NetworkXOneTimePad {
public:
  int crack(vector<string> plaintexts, vector<string> ciphertexts);
};

string xoruj(string const &a, string const & b) {
  string res;
  FORIND(i,a) res+=(a[i]==b[i]?'0':'1');
  return res;
}

int NetworkXoneTimePad::crack(vector<string> plaintexts, vector<string> ciphertexts) {
  int res=0;
  set<string> K;
  set<string> pp(ALL(plaintexts));
  FOREACH(p,plaintexts) FOREACH(c,ciphertexts) {
    K.insert(xoruj(*p,*c));
  }
  FOREACH(it,K) {
    bool ok=true;
    FOREACH(C,ciphertexts) {
      string p=xoruj(*C,*it);
      if(pp.count(p)==0) ok=false;
    }
    if(ok) res++;
  }
  return res;
}

// petr
import java.util.*;

public class NetworkXOneTimePad {
  public int crack(String[] plaintexts, String[] ciphertexts) {
    long [] plain=covert(plaintexts);
    long [] cipher=covert(ciphertexts);
    int res=0;
    for(long x:plain) {
      long key=cipher[0]^x;
      boolean ok =true;
      for(long a:cipher) {
        boolean found=false;
        for(long b:plain) 
          if((a^key)==b)
            found=true;
        if(!found) ok=false;
      }
      if(ok) res++;
    }
    return res;
  }
  private long[] covert[String[] arr) {
    long[] res=new long[arr.length];
    for(int i=0; i<arr.length;++i) 
      res[i]=Long.parseLong(arr[i],2);
    return res;
  }
};
