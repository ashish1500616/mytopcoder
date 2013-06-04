#include <iostream> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <map> 
#include <sstream> 
#include <cmath> 

using namespace std; 


const int dx[6]={0,1,1,0,-1,-1}; 
const int dy[6]={-1,-1,0,1,1,0}; 

vector< pair<int,int> > nodes; 
vector< pair<int,int> > edges; 
bool okdir[2600][6]; 
int newloc[2600][6]; 

class RoboCourier { 
  public: 
   
  int lookup(int x, int y) 
  { 
    for(int i=0;i<nodes.size();i++) 
      if (nodes[i].first==x && nodes[i].second==y) 
        return i;         
    nodes.push_back(make_pair(x,y)); 
    return nodes.size()-1; 
  } 
   
  int timeToDeliver(vector <string> path) { 
    int x=0,y=0,dir=0,src,dest; 
    string p=""; 
    for(int i=0;i<path.size();i++) p+=path[i]; 
    nodes.clear(); 
    edges.clear(); 
    memset(okdir,0,sizeof(okdir)); 
    lookup(x,y); 
    for(int i=0;i<p.size();i++) { 
      switch (p[i]) { 
        case 'R' : dir=(dir+1)%6; break; 
        case 'L' : dir=(dir+5)%6; break; 
        case 'F' :         
          src=lookup(x,y); 
          x+=dx[dir]; 
          y+=dy[dir];             
          dest=lookup(x,y); 
          okdir[src][dir]=1; 
          newloc[src][dir]=dest; 
          okdir[dest][(dir+3)%6]=1; 
          newloc[dest][(dir+3)%6]=src; 
          break; 
      } 
    } 
    dest=lookup(x,y); 
     
    int n=nodes.size(); 
    /* 
    for(int i=0;i<n;i++) { 
      printf("node %d  x=%d, y=%d  ",i,nodes[i].first,nodes[i].second); 
      for(int j=0;j<6;j++) 
        if (okdir[i][j]) 
          printf("%d ",newloc[i][j]); 
      printf("\n"); 
    } 
    exit(0); 
      */ 
    vector<int> vis(n*6,0); 
    vector<int> dist(n*6,99999999); 
    dist[0]=0; 
    while (1) { 
      int best=99999999,cur=-1; 
      for(int i=0;i<n*6;i++) { 
        if (dist[i]<best && !vis[i]) { 
          best=dist[i]; 
          cur=i; 
        } 
      } 
      if (cur<0) { 
        cerr << "Error!" << endl; 
        exit(-1); 
      } 
      vis[cur]=1; 
      int m=cur/6,dir=cur%6; 
      //printf("at node %d\n",m+1); 
      if (m==dest) { 
        //exit(0); 
        return best; 
      } 
      if (dist[m*6+(dir+1)%6]>best+3) dist[m*6+(dir+1)%6]=best+3; 
      if (dist[m*6+(dir+5)%6]>best+3) dist[m*6+(dir+5)%6]=best+3; 
      int steps=0; 
      while (okdir[m][dir]) { 
        steps++; 
        m=newloc[m][dir]; 
        int tm=steps==1?4:(8+(steps-2)*2); 
        if (dist[m*6+dir]>best+tm) dist[m*6+dir]=best+tm;       
        //cout << m << endl; 
      } 
    }     
  } 
};



public class RoboCourier {
  boolean ddd = false ;
  Hashtable pred = new Hashtable() ;
int[] s2ia(String s) {
  StringTokenizer t=new StringTokenizer(s.trim(), ",");
  int[]r=new int[t.countTokens()];
  int i=0;
  while(t.hasMoreTokens())try{
     r[i++]=Integer.parseInt((String)t.nextToken());
  }catch(Exception e){};
  return r;
}
 
  /**
   *   Not the fastest djikstra in the world.
   */
  class ent {
    Object o ;
    double pri ;
    int at ;
    ent(Object o_, double p, int a) {
       o = o_ ;
       pri = p ;
       at = a ;
    }
    public String toString() {
       return "(" + o + "," + pri + "," + at + ")" ;
    }
  }
  class djik {
    djik(Object start) {
       if (start != null) addState(start, 0.0) ;
    }
    double valueOf(Object o) {
      ent e = (ent)h.get(o) ;
      if (e == null) return -1.0 ; // not found: returns -1
      return e.pri ;
    }
    boolean addState(Object o, double value) {
      return addState(null, o, value) ;
    }
    boolean addState(Object prev, Object o, double value) {
      ent e = (ent)h.get(o) ;
      if (e != null && e.pri <= value)
         return false ; // already here
      if (e == null) {
         e = new ent(o, value, heap.size()) ;
         heap.add(e) ;
         h.put(o, e) ;
      } else {
         e.pri = value ;
      }
      upheap(e) ;
      if (prev != null)
         pred.put(o, prev) ;
      return true ;
    }
    Object nextState() {
      if (heap.size() == 0) return null ;
      ent e = (ent)(heap.get(0)) ;
      if (heap.size() > 1) {
         ent otop = (ent)(heap.get(heap.size()-1)) ;
         heap.set(0, otop) ;
         otop.at = 0 ;
         heap.remove(heap.size()-1) ;
         downheap(otop) ;
      } else {
         heap.remove(0) ;
      }
      return e.o ;
    }
    void upheap(ent e) {
      int w = e.at ;
      while (w > 0) {
         int par = w / 2 ;
         ent pare = (ent)(heap.get(par)) ;
         if (pare.pri <= e.pri)
            break ;
         pare.at = w ;
         heap.set(w, pare) ;
         w = par ;
      }
      e.at = w ;
      heap.set(w, e) ;
    }
    void downheap(ent e) {
      int w = e.at ;
      int n = heap.size()-1 ;
      while (w <= n/2) {
         int par = w * 2 ;
         ent pare = (ent)(heap.get(par)) ;
         if (par<n) {
            ent par2 = (ent)(heap.get(par+1)) ;
            if (par2.pri < pare.pri) {
               par++ ;
               pare = par2 ;
            }
         }
         if (pare.pri >= e.pri)
            break ;
         pare.at = w ;
         heap.set(w, pare) ;
         w = par ;
      }
      e.at = w ;
      heap.set(w, e) ;
    }
    int size() { return h.size() ; }
    int levAt = 0 ;
    ArrayList heap = new ArrayList() ;
    Map h = new HashMap() ;
  }
  int dir[] = { 1, -1000, -1001, -1, 1000, 1001, 1 } ;
  HashSet vd = new HashSet() ;
  HashSet pts = new HashSet() ;
  void seen(int i) {
    pts.add(new Integer(i)) ;
  }
  void tran(int p1, int d) {
    //    System.out.println("Can go " + p1 + "," + d) ;
    vd.add(p1 + "," + d) ;
  }
  public int timeToDeliver(String[] path) {
    int i, j, k ;
    int p = 0 ;
    int d = 0 ;
    for (i=0; i<path.length; i++) {
      String s = path[i] ;
      for (j=0; j<s.length(); j++) {
  switch (s.charAt(j)) {
  case 'L': d = (d + 5) % 6 ; break ;
  case 'R': d = (d + 1) % 6 ; break ;
  case 'F': tran(p, d) ;
    tran(p+dir[d], (d+3)%6) ;
    seen(p) ; seen(p+dir[d]) ;
    p += dir[d] ;
    //    System.out.println("At " + p) ;
    break ;
  }
      }
    }
    int best = 1000000000 ;
    djik dj = new djik("0,0") ;
    while (true) {
       String s = (String)(dj.nextState()) ;
       if (s == null) return best ;
       //       System.out.println("At " + s) ;
       int[] p2 = s2ia(s) ;
       double oval = dj.valueOf(s) ;
       if (p2[0] == p) {
   best = Math.min(best, (int)oval) ;
       }
       dj.addState("" + p2[0] + "," + ((p2[1] + 1) % 6), oval+3) ;
       dj.addState("" + p2[0] + "," + ((p2[1] + 5) % 6), oval+3) ;
       int pp = p2[0] ;
       int cst = 4 ;
       for (i=0; true; i++) {
   String t = "" + pp + "," + p2[1] ;
   if (vd.contains(t)) {
     pp += dir[p2[1]] ;
     //     System.out.println("Can go " + t + " -> " + pp + "," + p2[1] + " " + oval+cst) ;
     dj.addState("" + pp + "," + p2[1], oval+cst) ;
     if (i == 0) {
       cst += 4 ;
     } else {
       cst += 2 ;
     }
   } else {
     break ;
   }
       }
    }
  }
}
