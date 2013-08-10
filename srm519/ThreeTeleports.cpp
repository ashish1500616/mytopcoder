struct point{
  int x,y;
  point(int x=0,int y=0): x(x),y(y){}
};

long long dist(point A, point B) {
  return abs(A.x-B.x)+abs(A.y-B.y);
}

int shorttestDistance(int xMe, int yMe, int xHome, int yHome, vector<string> teleports) {
  point p[8];
  p[0].x=xMe;
  p[0].y=yMe;
  p[1].x=xHome;
  p[1].y=yHome;
  for(int i=0;i<3;i++) {
    stringstream(teleports[i])>>p[2*i+2].x>>p[2*i+2].y>>p[2*i+3].x>>p[2*i+3].y;
  }
  
  long long g[8][8];
  for(int i=0;i<8;i++) {
    for(int j=0;j<8;j++) {
      g[i][j]=dist(p[i],p[j]);
    }
  }
  for(int i=0;i<3;i++) {
    g[2*i+2][2*i+3]=g[2*i+3][2*i+2]=min(10LL,g[2*i+2][2*i+3]);
  }
  
  for(int k=0;k<8;k++) {
    for(int i=0;i<8;i++) {
      for(int j=0;j<8;j++) {
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
  return g[0][1];
}