class ToolsBox{
public:
	int countTools(vector<string> need)
	{
		set<string> ret;
		string nd;
		int i,j;
		for(i=0;i<need.size();i++)
		  nd=need[i]+" ";
		i=j=0;
		for(j=0;j<nd.size();j++)
		  if(nd[j]==' ' && i!=j)
		  {
			  ret.insert(nd.substr(i,j));
			  i=j+1;
		  }
		return ret.size();
	}
};

int INF=100000;
class MazeMaker{
public:
	int M;
	int N;
	int E[300][300];

	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)
	{
		M=maze.size();
		N=maze[0].size();
		debug(M)
		debug(N)
		for(int i=0;i<300;i++)
		  for(int j=0;j<300;j++)
		  {
			E[i][j]=INF;
	    	if(i==j)
			  E[i][j]=0;
		  }
		for(int i=0;i<M;i++)
		  for(int j=0;j<N;j++)
			for(int k=0;k<moveRow.size();k++)
			{
			    if(maze[i][j]=='X') continue;
				int s=i*N+j;
				int x,y;
				x=i+moveRow[k];
				y=j+moveCol[k];

				if(x<0 || x>=M || y<0 || y>=N) continue;
				if(maze[x][y]=='X') continue;
				int t=x*N+y;
				E[s][t]=1;
				// direct map!!
				//E[t][s]=1;
			}
	
		int MN=M*N;
		for(int k=0;k<MN;k++)
		  for(int i=0;i<MN;i++)
			for(int j=0;j<MN;j++)
			  if(E[i][j]>E[i][k]+E[k][j])
				E[i][j]=E[i][k]+E[k][j];
	
		int start=startRow*N+startCol;
		int ret=-1;
		for(int i=0;i<M;i++)
		for(int j=0;j<N;j++) if(maze[i][j]!='X'){ // note the condition!
		  int ter=i*N+j;
		  if(ret<E[start][ter])
		  { 
			ret=E[start][ter];
		  }
		}
		if(ret==INF)
		  ret=-1;
		return ret;
	}
};


//ACRush

#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef pair<int,int> ipair;

class MazeMaker
{
public:
  int longestPath(vector <string> G, int sX, int sY, vector <int> mX, vector <int> mY)
  {
    vector<ipair> Q;
    int D[60][60];
    memset(D,255,sizeof(D));
    int sizeX=SIZE(G);
    int sizeY=LENGTH(G[0]);
    D[sX][sY]=0;
    Q.push_back(MP(sX,sY));
    for (int cl=0;cl<SIZE(Q);cl++)
    {
      int x=Q[cl].first;
      int y=Q[cl].second;
      for (int i=0;i<SIZE(mX);i++)
      {
        int x2=x+mX[i];
        int y2=y+mY[i];
        if (x2>=0 && x2<sizeX && y2>=0 && y2<sizeY && D[x2][y2]<0 && G[x2][y2]=='.')
        {
          D[x2][y2]=D[x][y]+1;
          Q.push_back(MP(x2,y2));
        }
      }
    }
    int R=0;
    for (int i=0;i<sizeX;i++)
      for (int j=0;j<sizeY;j++) if (G[i][j]=='.')
        if (D[i][j]<0)
          return -1;
        else
          checkmax(R,D[i][j]);
          
    int x=5,y=5;
    for(int l=R;l>=0;l--)
    {
      for(int k=0;k<mX.size();k++)
      {
        int x2,y2;
        x2=x-mX[k];
        y2=y-mY[k];
        if(x2<0 || x2>=sizeX || y2<0 || y2>sizeY) continue;
        if(D[x2][y2]==D[x][y]-1)
        {
          x=x2;
          y=y2;
          cout<<x2<<" "<<y2<<";";
          break;
        } 
      }
    }    
    return R;
  }
};

//blando
const int max_n=128,max_k=32;
class TheProduct{
public:
	long long max_c[max_n][max_k],min_c[max_n][max_k];

	long long maxProduct(vector<int> a,int k,int max_d)
	{
		long long oo=1<<64;
		int n=a.size();
		for(int i=0;i<n;i++){
			max_c[i][1]=a[i];
			min_c[i][1]=a[i];
		}
		for(int j=2;j<=k;j++){
			for(int i=0;i<n;i++){
				max_c[i][j]=-oo;
				min_c[i][j]=oo;
				if(i+1<j)
				  continue;
				for(int i1=0;i1<i;i1++){
					if(min_c[i1][j-1]==oo)
					  continue;
					if(i-i1>max_d)
					  continue;
					max_c[i][j]=max(max_c[i][j],a[i]*max_c[i1][j-1]);
					max_c[i][j]=max(max_c[i][j],a[i]*min_c[i1][j-1]);
					min_c[i][j]=min(min_c[i][j],a[i]*max_c[i1][j-1]);
					min_c[i][j]=min(min_c[i][j],a[i]*min_c[i1][j-1]);
				}
			}
		}
		long long ans=-oo;
		for(int i=0;i<n;i++){
		  if(max_c[i][k]>ans)
			ans=max[i][k];
		}
		return ans;
	}
};


