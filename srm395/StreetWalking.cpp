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
#define cpresent(c,x) (find(all(all(c),x)!=(c).end())
typedef long long ll;

class StreetWalking{
public:
	long long minTime(int X, int  Y, int walkTime, int sneakTime)
	{
	    ll time=0;
	    if(sneakTime<walkTime){
	      ll diff=abs(X-Y);
	      ll ss=max(X,Y)-diff;
	      debug(ss)
	      debug(diff)
	      if(diff%2==0){
	        time=(ss+diff)*sneakTime;
	      }
	      else{
	        time=(ss+diff-1)*sneakTime+walkTime;
	        debug(time)
	      }
		}
		else if(walkTime*2>sneakTime)
		{
		 // sneak some
		  ll diff=abs(X-Y);
		  ll st=max(X,Y)-diff;
		  time=st*sneakTime+diff*walkTime;
		}
		else
		{
		  time=(X+Y)*walkTime;
		}
		return time;
	}
};
	
			















