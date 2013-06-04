#include <algorithm> 
#include <cmath> 
#include <iostream> 
#include <limits> 
#include <list> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 
using namespace std; 

#define debug(c) cout << "> " << #c << " = " << c << endl; 
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end() 
#define mp make_pair 
#define pb push_back 
#define tr(c,i) for(typeof((c).begin() i=(c).begin(); i!=(c).end();i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x)!=(c).end())
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
typedef vector<int> vi; 
typedef pair<int,int> ii;
typedef long long ll; 
