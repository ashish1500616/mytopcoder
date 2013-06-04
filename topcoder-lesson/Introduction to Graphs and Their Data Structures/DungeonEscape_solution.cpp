View DungeonEscape   Problem Statement  
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <string>
#include <vector>
using namespace std;
 
#define Forc(i, c) for(typeof(c.begin()) i(c.begin()); i != c.end(); ++i)
#define In(c, x) (c.find(x) != c.end())
#define Inv(v, x) (find(v, x) >= 0)
#define X first
#define Y second
#define Pair(x, y) make_pair(x, y)
#define SetPair(a, x, y) pair<typeof(x), typeof(y)> a(x, y)
#define mkvecint makeVec<int, int>
#define mkvecstring makeVec<string, char *>
typedef pair<int, int> point; typedef long long ll;
 
template <class T> T strToInt(string); template <class T> string intToStr(T);
int strToInt(string str) { return strToInt<int>(str); }
string intToStr(int x) { return intToStr<int>(x); }
vector<string> tokenize(string, string = " ", bool = false);
vector<int> tokenizeInt(string, string = " ", bool = false);
template <class A, class B> int find(const vector<A>&, B);
template <class T> T nth(const set<T>&, int);
template <class A, class B> void hookSort(vector<A>&, vector<B>&, bool = false);
template <class T> ostream &operator <<(ostream&, const vector<T>&);
template <class A, class B> ostream &operator <<(ostream&, const pair<A, B>&);
template <class A, class B> vector<A> makeVec(int, ...);
 
/**************************************************************************************/
/************************** Begin Priority Queue / BFS Class **************************/
/**************************************************************************************/
 
template <class P, class V = int> struct PQ {
    map<P, V> minValue;
    set<pair<V, P> > q;
    PQ() {}
    PQ(P pos, V val = 0) { push_back(pos, val); }
    bool empty() { return q.empty(); }
    pair<P, V> pop_front();
    void push_back(P, V);
};
 
template <class P, class V>
pair<P, V> PQ<P, V>::pop_front() {
    P curr(q.begin()->Y);
    q.erase(q.begin());
    return Pair(curr, minValue[curr]);
}
 
template <class P, class V>
void PQ<P, V>::push_back(P pos, V val) {
    if (!In(minValue, pos)) {
        minValue[pos] = val;
        q.insert(Pair(val, pos));
        return;
    }
    if (minValue[pos] <= val) return;
    q.erase(Pair(minValue[pos], pos));
    minValue[pos] = val;
    q.insert(Pair(val, pos));
}
 
/**************************************************************************/
 
int MyCode(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) {
  int r(up.size()), c(up[0].length());
  PQ<point> pq(point(startLevel, startEasting));
  while (!pq.empty()) {
    pair<point, int> curr(pq.pop_front());
    if (curr.X.X < 0) return curr.Y;
    if (curr.Y >= c * (r - curr.X.X)) continue;
    char dn(up[curr.X.X][curr.X.Y]), ds(down[curr.X.X][curr.X.Y]), dw(west[curr.X.X][curr.X.Y]), de(east[curr.X.X][curr.X.Y]);
    if (dn != 'x') pq.push_back(point(curr.X.X-1, curr.X.Y), curr.Y + dn - '0');
    if (ds != 'x' && curr.X.X < r-1) pq.push_back(point(curr.X.X+1, curr.X.Y), curr.Y + ds - '0');
    if (dw != 'x' && curr.X.Y > 0) pq.push_back(point(curr.X.X, curr.X.Y-1), curr.Y + dw - '0');
    if (de != 'x' && curr.X.Y < c-1) pq.push_back(point(curr.X.X, curr.X.Y+1), curr.Y + de - '0');
  }
  return -1;
}
 
/**************************************************************************/
 
struct DungeonEscape {
  int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) {
    static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
    return MyCode(up,down,east,west,startLevel,startEasting);
  }
  
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"0x4",
 "0x3",
 "0x3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0x9",
 "009",
 "0x9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0x9",
 "1x9",
 "009"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0x9",
 "0x0",
 "009"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 2; int Arg6 = 10; verify_case(0, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_1() { string Arr0[] = {"xxxxxxxxx1",
 "1xxxxxxxxx",
 "xxxxxxxxx1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xxxxxxxxxx",
 "xxxxxxxxxx",
 "xxxxxxxxxx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111111111",
 "xxxxxxxxxx",
 "1111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxx",
 "1111111111",
 "xxxxxxxxxx"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = 30; verify_case(1, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_2() { string Arr0[] = {"xxxxxxxxx1",
 "xxxx999991",
 "x999999991"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111111111",
 "1111111111",
 "1111111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111122242",
 "2222222241",
 "2111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxx1",
 "1111111111",
 "xxxxxxxxx1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = -1; verify_case(2, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_3() { string Arr0[] = {"1x2x3x4x5x6x7x8x9",
 "00000000000000000",
 "98765432223456789",
 "12345678987654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000",
 "00000000000000000",
 "00000000000000000",
 "00000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; int Arg5 = 12; int Arg6 = 17; verify_case(3, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
 
// END CUT HERE
};
 
template <class T> T strToInt(string str) {
  stringstream ss(str);
  T answer;
  ss >> answer;
  return answer;
}
 
template <class T> string intToStr(T x) {
  stringstream s;
  s << x;
  return s.str();
}
 
vector<string> tokenize(string str, string delim, bool returnDelims) {
  vector<string> answer;
  string temp;
  for (int i(0); i < str.length(); ++i) {
    bool isDelim(false);
    for (int j(0); j < delim.length(); ++j)
      if (str[i] == delim[j]) isDelim = true;
    if (!isDelim) {
      temp += str[i];
      continue;
    }
    if (temp != "") answer.push_back(temp);
    temp = "";
    if (returnDelims) answer.push_back(string(1, str[i]));
  }
  if (temp != "") answer.push_back(temp);
  return answer;
}
 
vector<int> tokenizeInt(string str, string delim, bool returnDelims) {
  vector<string> tokens(tokenize(str, delim, returnDelims));
  vector<int> answer(tokens.size());
  for (int i(0); i < tokens.size(); ++i)
    answer[i] = strToInt(tokens[i]);
  return answer;
}
 
template <class A, class B> int find(const vector<A> &vec, B item) {
  for (int i(0); i < vec.size(); ++i)
    if (vec[i] == item) return i;
  return -1;
}
 
template <class T> T nth(const set<T> &s, int x) {
  typename set<T>::iterator answer(s.begin());
  for (int i(0); i < x; ++i) ++answer;
  return *answer;
}
 
template <class A, class B> void hookSort(vector<A> &a, vector<B> &b, bool complete) {
  vector<pair<A, int> > toSort(a.size());
  for (int i(0); i < a.size(); ++i)
    toSort[i] = Pair(a[i], i);
  sort(toSort.begin(), toSort.end());
  vector<B> old(b);
  for (int i(0); i < b.size(); ++i)
    b[i] = old[toSort[i].Y];
  if (complete)
    sort(a.begin(), a.end());
}
 
template <class T> ostream &operator <<(ostream &os, const vector<T> &vec) {
  if (vec.empty()) return os;
  for (int i(0); i < vec.size() - 1; ++i) os << vec[i] << ',';
  return os << vec[vec.size() - 1];
}
 
template <class A, class B> ostream &operator <<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.X << ',' << p.Y << ')';
}
 
template <class A, class B> vector<A> makeVec(int n, ...) {
  vector<A> answer(n);
  va_list vl;
  va_start(vl, n);
  for (int i(0); i < n; ++i) answer[i] = va_arg(vl, B);
  va_end(vl);
  return answer;
}
  
