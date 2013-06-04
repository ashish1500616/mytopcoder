class ImportantTasks{
public:
	int maximalCost(vi complexity,vi computers)
	{
		int nt=sz(complexity);
		int nc=sz(computers);
		sort(all(complexity));
		sort(all(computers));
		int i=0,j=0;
		int res=0;
		while(i<nt && j<nc)
		{
			if(complexity[i]<=computers[j])
			{
				i++;
				j++;
				res++;
			}
			if(complexity[i]>computers[j])
			  j++;
		}
		return res;
	}
};


int B[8][8];
int C[8][8];
int di[]={-2,-1,-2,1,-1,2,1,2};
int dj[]={-1,-2,1,-2,2,-1,2,1};
class KnightsTour{
public:

	int visitedPositions(vector <string> board)
	{
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		int ki,kj;
		ki=kj=0;
		for(int i=0;i<8;i++)
		  for(int j=0;j<8;j++)
		  {
			  if(board[i][j]=='*')
				B[i][j]=-1;
			  if(board[i][j]=='K')
				ki=i,kj=j;
		  }
		B[ki][kj]=1;
		C[ki][kj]=1;
		int res=0;
		res++;
		int i=ki,j=kj;
		while(1)
		{
			int ni,nj;
			int k;
			for(k=0;k<8;k++)
			{
				ni=i+di[k];
				nj=j+dj[k];

				if(ni<0 || ni>=8 || nj<0 || nj>=8)
				  continue;
				if(B[ni][nj]==1 || B[ni][nj]==-1)
				  continue;
				res++;
				i=ni;
				j=nj;
				B[ni][nj]=1;
				C[ni][nj]=res;

				break;

			}
			if(k>=8)
			  break;
		}
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
			cout<<B[i][j]<<"\t";
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
			cout<<C[i][j]<<"\t";
			cout<<endl;
		}
		
		return res;
	}
};
class KnightsTour{
public:
	int visitedPositons(vector<string> A)
	{
		int R=0;
		int x=0,y=0;
		for(int i=0;i<8;i++)
		  for(int j=0;j<8;j++)
			if(A[i][j]=='K')
			{
				x=i;
				y=j;
				A[i][j]='.';
			}
		while(1)
		{
			R++;
			A[x][y]='#';
			int minC=10000,bx=-1,by=-1;
			for(int dx=-2;dx<=2;dx++)
			  for(int dy=-2;dy<=2;dy++) if(dx*dx+dy*dy==5)
			  {
				  int x2=x+dx;
				  int y2=y+dy;
				  if(x2<0 || x2>=8 || y2<0 || y2>=8) continue;
				  if(A[x2][y2]!='.') continue;
				  int C=0;
				  for(int dx2=-2;dx2<=2;dx2++)
					for(int dy2=-2;dy2<=2;dy2++) if(dx2*dx2+dy2*dy2==5)
					{
						int x3=x2+dx2;
						int y3=y2+dy2;
						if(x3>=0 && x3<8 && y3>=0 && y3<8 && A[x3][y3]=='.') C++;
					}
				  if(C<minC) minC=C,bx=x2,by=y2;
			  }
			if(minC==10000) break;
			x=bx;
			y=by;
		}
		return R;
	}
};