// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Bunnies like programming and they sometimes make useless devices. 

One group of bunnies made a device called Converter. 
Converter has two fixed integers, n and z, 
and works as follows: 

	It receives a card on which an integer x is written. 
	This card will not be returned. 
	It selects an integer y between 1 and n, inclusive, 
	such that x + y^2 + z^3 is a multiple of n. 
	If there is more than one such y, Converter allows the user to choose exactly one of them. 
	If there is no such y, Converter will break and will never be usable again. 
	It returns a card on which the integer y is written. 

Initially you have a card on which an integer start is written. 
Your goal is to get a card on which an integer goal is written. 
Return the minimum number of times you must use Converter in order to achieve the goal. 
If it is impossible to get such a card, return -1 instead. 


DEFINITION
Class:BunnyConverter
Method:getMinimum
Parameters:int, int, int, int
Returns:int
Method signature:int getMinimum(int n, int z, int start, int goal)


CONSTRAINTS
-n will be between 1 and 500,000, inclusive. 
-z, start and goal will each be between 1 and n, inclusive. 


EXAMPLES

0)
5
1
5
3

Returns: 1

By using Converter once for a card with 5, you can choose 2 or 3 as y. 

For example, y = 3 can be chosen because 5 + 3^2 + 1^3 = 15 is a multiple of 5. 


1)
5
1
5
1

Returns: 2

By using Converter once for a card with 5, you can choose 2 or 3 as y. 

By using Converter once for a card with 3, you can choose 1 or 4 as y. 


2)
6
2
3
4

Returns: -1

You will never get a card with 4. 


3)
7
7
7
7

Returns: 0

4)
499979
499979
499976
3

Returns: 249988



*/
// END CUT HERE
//#line 97 "BunnyConverter.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
//#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <vector>

using namespace std;

const int oo=10000000;
int dis[500001];
int vis[500001];
int n;
int z;
int start;
int goal;
vector<int> tmpys;

class BunnyConverter
{
	public:

		int solvey(int x,vector<int>& ys)
		{
			cout<<"solvey x="<<x<<endl;
			int has=false;
			for(int y=1;y<=n;y++)
			{
				long w;
				if(n==z)
				  w=x+y*y;
				else
				  w=x+y*y+z*z*z;
				if(w<0)
				   break;
				cout<<"teset w:"<<w<<endl;
				if(w%n==0)
				{
					cout<<"put y:"<<y<<endl;
					ys.push_back(y);
					has=true;
				}
			}
	        for(int i=0;i<ys.size();i++)
	            cout<<ys[i]<<" ";
            cout<<endl;
			return has;
		}
		void dfs(int x,int d)
		{
			if(vis[x]==1)
			  return;
			vis[x]=1;
			dis[x]=d;
			if(x==goal)
			  return;
			vector<int> tmp=tmpys;
			tmpys.clear();
			solvey(x,tmpys);
			for(int i=0;i<tmpys.size();i++)
			{
				dfs(tmpys[i],d+1);
			}
			tmpys=tmp;
		}

        int getMinimum(int _n, int _z, int _start, int _goal)
        {
			n=_n;
			z=_z;
			start=_start;
			goal=_goal;
			for(int i=0;i<500001;i++)
			{
				dis[i]=oo;
			}
			memset(vis,0,sizeof(vis));
			dfs(start,0);

			int ret;
			if(dis[goal]==oo)
			  ret=-1;
			else
			  ret=dis[goal];
			  cout<<ret<<endl;
			return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 5; int Arg3 = 3; int Arg4 = 1; verify_case(0, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 5; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = -1; verify_case(2, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 7; int Arg3 = 7; int Arg4 = 0; verify_case(3, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 499979; int Arg1 = 499979; int Arg2 = 499976; int Arg3 = 3; int Arg4 = 249988; verify_case(4, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        int temp;
        BunnyConverter ___test;
        ___test.run_test(-1);
        cin>>temp;
        return 0;
}
// END CUT HERE
