map<string,int> mp;
 
struct GroceryBagger {
int minimumBags( int strength, vector <string> itemType ) 
{
    int r = 0;
    fu(i,itemType.size()) mp[itemType[i]]++;
    
    for( map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it ) {
        r += (it->second + strength - 1) / strength;
    }
 
    return r;
}
 
};


class FanFailure { 
public: 
vector <int> getRange(vector <int> a, int b) { 
  int i, j, k, x, y, z, n; 
  vector <int> ret; 
  ret.push_back(-1); 
  ret.push_back(-1); 
  sort(a.begin(), a.end()); 
  for( i = 0; i <= a.size(); i++ ) { 
    if( accumulate(a.begin()+i, a.end(), 0) >= b ) 
      ret[0] >?= i; 
    if( accumulate(a.begin(), a.end()-i, 0) >= b ) 
      ret[1] >?= i; 
  } 
  return ret; 
} 
};


class PlayGame {
  public:
  int saveCreatures(vector <int> a, vector <int> b) {
    s(a); s(b);
    int s = 0;
    for (int i = a.si - 1; i >= 0; i--) {
      //if larger
      for (int j = b.si - 1; j >= 0; j--) {
        if (a[i] > b[j]) {
          s += a[i];
          b.erase(b.begin() + j);
          goto hit;
        }
      }
      b.erase(b.end() - 1);
      hit:;
    }
    return s;
  }
};


class SchoolAssembly {
  public:
  int getBeans(int kids, int quantity) {
    int nB = kids*quantity + 4*(quantity-1);
    return (nB+19)/20;
    
  }
};
 

class RockStar { 
  public: 
  int getNumSongs(int ff, int fs, int sf, int ss) { 
    // !FDI 
    if(ff == 0 && fs == 0) return ss + (sf ? 1 : 0); 
    else if(fs == 0) return ff; 
    else if(sf < fs) return ff + ss + (sf+1) + sf; 
    else return ff + ss + fs + fs; 
    } 
  }; 



#define INF 2000000000 
int tcize(int n) {return n<INF ? n : -1;} 

class Apothecary { 
  public: 
  vector <int> balance(int W) { 
    // !FDI 
    vector<int> res; 
    int qty = 1; 
    while(W) { 
      if(W % (qty*3) == 0) ; 
      else if(W % (qty*3) == qty) { 
        W -= qty; 
        res.push_back(qty); 
        } 
      else { 
        W += qty; 
        res.push_back(-qty); 
        } 
      qty *= 3; 
      } 
    sort(res.begin(), res.end()); 
    return res; 
    } 
   
  
  }; 


const int INF = 1000000;
 
int bt( vector<int> t, int s )
{
    for (int i = 0; i < t.size(); i++)
  if (t[i] >= s)
      return t[i];
    return INF;
}
 
int int_comp( const void *a, const void *b )
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y)
  return -1;
    else if (x > y)
  return 1;
    else
  return 0;
}
 
class Boxing {
public:
    int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) {
  int count = 0;
  for (int s = 0; s <= 180000; s++) {
      int best_time[5];
      best_time[0] = bt( a, s );
      best_time[1] = bt( b, s );
      best_time[2] = bt( c, s );
      best_time[3] = bt( d, s );
      best_time[4] = bt( e, s );
      qsort( best_time, 5, sizeof(int), int_comp );
      if (best_time[2] <= s + 1000) {
    count++;
    s = best_time[2];
    //fprintf( stderr, "s = %d\n", s );
      }
  }
  return count;
    }
};


class Unblur {
  public:
  vector <string> original(vector <string> b) {
    VS r(b.size(), string(b[0].size(),'.'));
    for(int i=1;i+1<(int)b.size();i++) {
      for(int j=1;j+1<(int)b[0].size();j++) {
        int total = b[i-1][j-1] - '0';
        for(int di=i-2;di<=i;di++)for(int dj=j-2;dj<=j;dj++) {
          if (0<=di&&di<b.size() && 0<=dj&&dj<b[0].size()) {
            total -= (r[di][dj]=='#');
          }
        }
        r[i][j] = total==1?'#':'.';
      }
    }
    cout << r;
    return r;    
  }
};
