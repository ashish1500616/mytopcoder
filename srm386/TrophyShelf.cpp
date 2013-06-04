#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <memory> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <functional>
#include <bitset>
using namespace std;
class TrophyShelf {
  public:
  vector <int> countVisible(vector <int> vi) {
      vector<int> q;
  int i,cnt=0,cur=0;
  for(i=0;i<vi.size();i++){
    if(vi[i]>cur){
      cnt++;
    cur=vi[i];
    }
  }
  q.push_back(cnt);
  cur=0;
  cnt=0;
  for(i=vi.size()-1;i>=0;i--){
    if(vi[i]>cur){
      cnt++;
    cur=vi[i];
    }
  }
  q.push_back(cnt);
  return q;
  }
};
