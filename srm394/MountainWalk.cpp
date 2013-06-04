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



class MountainWalk{
public:
	int cellsVisited(vector <string> areaMap, int heightDifference){
		bool visited[100][100];
		//memset(visited,0,sizeof(visited));
		int ilim=areaMap.size();
		int jlim=areaMap[0].size();
		debug(ilim)
		debug(jlim)
		int im[]={1,0,-1,0};
		int jm[]={0,-1,0,1};
		int num=1;
		int i=0,j=0;
		visited[0][0]=true;
		while(1){
			for(int k=0;k<=3;k++){
				int itmp,jtmp;
				itmp=i+im[k];
				jtmp=j+jm[k];
				//int diff=abs(areaMap[itmp][jtmp]-areaMap[i][j]);
				if(itmp>=0 && itmp<ilim && jtmp>=0 && jtmp<jlim && !visited[itmp][jtmp] && abs(areaMap[itmp][jtmp]-areaMap[i][j])<=heightDifference){
					visited[itmp][jtmp]=true;
					i=itmp;
					j=jtmp;
					debug(i)
					debug(j)
					num++;
					break;
				}
				if(k==3)
				  return num;
			}
		}
	}
};
