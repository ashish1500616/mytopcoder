/**
	solafide
	196
	*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
struct MaximalProduct{
  long long maximalProduct(int s,int k){
    long long prod=1;
    long long lst=s/k;
    int numPlus=s%k;
    for(int i=0;i<k;i++){
      if(i<numPlus){
        prod*=(lst+1);
        }
      else{
        prod*=lst;
        }
      }
    return prod;
    }
  };
