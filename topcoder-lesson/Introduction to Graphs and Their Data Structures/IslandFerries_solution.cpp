using namespace std;
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
typedef long long I64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<I64> VI64;
typedef unsigned uint;
typedef const char cchar;
typedef pair<int,int> PII;
typedef vector<double> VD;
typedef vector<PII> VPII;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORR(i,a,b) for(int i=(a);i<=(b);i++)
#define VAR(a,b) __typeof(b) a=b
#define FORIT(it,c) for(VAR(it,(c).begin());it!=(c).end();it++)
#define ALL(x) (x).begin(),(x).end()
#define UNIQ(x) (x).erase(unique(ALL(x)),(x).end())
 
 
static vector<string> tokenize(string s, string ch) {
   vector<string> ret;
   int p2;
   for( unsigned p = 0; p < s.size(); p = p2+1 ) {
      p2 = s.find_first_of(ch, p);
      if( p2 == -1 ) p2 = s.size();
      if( p2-p > 0 ) ret.push_back( s.substr(p, p2-p) );
   }
   return ret;
} 
template <class T>
static string toString(T val) {
    ostringstream os;
    os << val;
    return os.str();
}
 
template <class T>
static void parse(const string&s, T &val) {
    istringstream iss(s);
    iss >> val;
}
struct IslandFerriesImpl {
    vector <string> legs;
    vector <string> vprices;
    IslandFerriesImpl(vector <string> _legs,vector <string> _prices) {
        legs = _legs;
        vprices = _prices;
    }
 
    vector<vector<PII> > ferryLegs;
    vector<VI> prices;
 
    vector <int> costs() {
        int nisland = vprices.size();
        int nferry = legs.size();
 
        FOR(i,nferry) {
            ferryLegs.push_back(vector<PII>());
            VS toks = tokenize(legs[i]," -");
            FOR(j,toks.size()/2) {
                int from,to;
                parse(toks[j*2],from);
                parse(toks[j*2+1],to);
                ferryLegs[i].push_back(PII(from,to));
            }
        }
 
        FOR(i,nisland) {
            prices.push_back(VI());
            VS toks = tokenize(vprices[i]," ");
            FOR(j,toks.size()) {
                int pr;
                parse(toks[j],pr);
                prices[i].push_back(pr);
            }
        }
 
        int dist[50][1<<11];
        memset(dist,-1,sizeof(dist));
 
        queue<PII> q;
        q.push(PII(0,0));
        dist[0][0] = 0;
 
        while(!q.empty()) {
            PII fr = q.front(); q.pop();
            int at = fr.first;
            int have = fr.second;
 
            int nhave = 0;
            FOR(j,nferry)
                if(have & (1<<j)) {
                    nhave++;
 
                    for(int leg=0;leg<ferryLegs[j].size();leg++) {
                        if(ferryLegs[j][leg].first == at) {
                            int toat = ferryLegs[j][leg].second;
                            int tohave = have & ~(1<<j);
                            int todist = dist[at][have];
                            if(dist[toat][tohave] == -1 ||
                                    dist[toat][tohave] > todist) {
                                dist[toat][tohave] = todist;
                                q.push(PII(toat,tohave));
                            }
                        }
                    }
                }
 
            if(nhave < 3) {
                FOR(j,nferry)
                    if(!(have & (1<<j))) {
                        int toat = at;
                        int tohave = have | (1<<j);
                        int todist = dist[at][have] + prices[at][j];
                        if(dist[toat][tohave] == -1 ||
                                dist[toat][tohave] > todist) {
                            dist[toat][tohave] = todist;
                            q.push(PII(toat,tohave));
                        }
                    }
            }
        }
 
        VI ret;
        for(int i=1;i<nisland;i++) {
            ret.push_back(dist[i][0]);
        }
        return ret;
    };
};
 
 
struct IslandFerries {
    vector <int> costs(vector <string> legs,vector <string> prices) {
        IslandFerriesImpl impl(legs,prices);
        return impl.costs();
    }
 
};
