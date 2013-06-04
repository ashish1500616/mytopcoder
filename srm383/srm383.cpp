
int mm[51][51];
class FloorLayout{
public:
	int countBoards(vector<string> layout)
	{
		int m=sz(layout);
		int n=sz(layout[0]);
		memset(mm,0,sizeof(mm));
		debug(m)
		debug(n)

		int res=0;
		// compute row
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(layout[i][j]=='|') continue;
				if(mm[i][j]>0) continue;
				cout<<"one"<<endl;
				debug(i)
				debug(j)
				res++;
				mm[i][j]=1;
				for(int k=j+1;k<n;k++)
				{
					if(layout[i][k]=='|') break;
					mm[i][k]=1;
					debug(i)
					debug(k)
				}
			}
		}
		debug(res)
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<m;i++)
			{
				if(layout[i][j]=='-') continue;
				if(mm[i][j]>0) continue;
				res++;
				mm[i][j]=1;
				for(int k=i+1;k<m;k++)
				{
					if(layout[k][j]=='-') break;
					mm[k][j]=1;
				}
			}
		}
		return res;
	}
};


int mm[1000][1000];
int time1[1000][1000];
int land[30][30];
int inf=10000;
class HillWalker{
public:
	int highestPoint(vector<string> landscape,int threshold,int time1ToDark)
	{
		int m=sz(landscape);
		int n=sz(landscape[0]);
		debug(m)
		debug(n)
		for(int i=0;i<1000;i++)
		  for(int j=0;j<1000;j++)
		  { mm[i][j]=inf;
		    time1[i][j]=inf;
		  }

		for(int i=0;i<m;i++)
		  for(int j=0;j<n;j++)
		  {
			  if((landscape[i][j]-'a')>=0)
				land[i][j]=landscape[i][j]-'a'+26;
			  else
				land[i][j]=landscape[i][j]-'A';
		  }


		for(int i=0;i<m;i++)
		  for(int j=0;j<n;j++)
		  {
			  for(int mi=-1;mi<=1;mi++)
				for(int mj=-1;mj<=1;mj++)
				{
					int ii=i+mi;
					int jj=j+mj;
					if(ii<0 || ii>=m || jj<0 || jj>=n) continue;
					if(ii==i && jj==j) continue;
					int id1=n*i+j;
					int id2=n*ii+jj;

					if(land[ii][jj]>land[i][j] && (land[ii][jj]-land[i][j])<=threshold)
					{
			   			mm[id1][id2]=(land[ii][jj]-land[i][j])*(land[ii][jj]-land[i][j]);
						
					}
					else if(land[ii][jj]<=land[i][j] && (land[i][j]-land[ii][jj])<=threshold)
					{   				   
						mm[id1][id2]=1;

					}
				}
		  }
        
		// compute time1up
		int N=m*n;

		
		for(int i=0;i<N;i++)
		  for(int j=0;j<N;j++)
			time1[i][j]=mm[i][j];
			
		for(int i=0;i<N;i++)
			time1[i][i]=1;

       	for(int k=0;k<N;k++)
		  for(int i=0;i<N;i++)
		    for(int j=0;j<N;j++)
		    { 
		      int tmp=time1[i][k]+time1[k][j];
		      if(tmp<time1[i][j])
		      { 
			    time1[i][j]=tmp;
			  }
			}


		int high=0;
		for(int i=1;i<N;i++)
		{
			if(time1[0][i]+time1[i][0]<=time1ToDark && land[i/n][i%n]>high)
			  high=land[i/n][i%n];
		}


		return high;
	}
};




int mm[1000][1000];
int time1[1000][1000];
int land[30][30];
int inf=10000;
class HillWalker{
public:
	int highestPoint(vector<string> landscape,int threshold,int time1ToDark)
	{
		int m=sz(landscape);
		int n=sz(landscape[0]);
		debug(m)
		debug(n)
		for(int i=0;i<1000;i++)
		  for(int j=0;j<1000;j++)
		  { mm[i][j]=inf;
		    time1[i][j]=inf;
		  }

		for(int i=0;i<m;i++)
		  for(int j=0;j<n;j++)
		  {
			  if((landscape[i][j]-'a')>=0)
				land[i][j]=landscape[i][j]-'a'+26;
			  else
				land[i][j]=landscape[i][j]-'A';
		  }
		for(int i=0;i<m;i++)
		{
		  for(int j=0;j<n;j++)
		     cout<<land[i][j]<<"\t";
		  cout<<endl;
		}
		

		for(int i=0;i<m;i++)
		  for(int j=0;j<n;j++)
		  {
			  for(int mi=-1;mi<=1;mi++)
				for(int mj=-1;mj<=1;mj++)
				{   if(mi*mj!=0) continue;
					int ii=i+mi;
					int jj=j+mj;
					if(ii<0 || ii>=m || jj<0 || jj>=n) continue;
					if(ii==i && jj==j) continue;
					int id1=n*i+j;
					int id2=n*ii+jj;

					if(land[ii][jj]>land[i][j] && (land[ii][jj]-land[i][j])<=threshold)
					{
			   			mm[id1][id2]=(land[ii][jj]-land[i][j])*(land[ii][jj]-land[i][j]);
						//cout<<id1<<":"<<id2<<"="<<mm[id1][id2]<<endl;
					}
					else if(land[ii][jj]<=land[i][j] && (land[i][j]-land[ii][jj])<=threshold)
					{   
					    //cout<<"id1:"<<land[i][j]<<" id2:"<<land[ii][jj]<<endl;
					    //debug(i) debug(j) debug(ii) debug(jj)
						mm[id1][id2]=1;
						if(id1==18 && id2==9) 
						{ cout<<"hahah"<<endl;
						  debug(ii) debug(jj) debug(i) debug(j)
						 }
						//cout<<id1<<":"<<id2<<"="<<mm[id1][id2]<<endl;
					}
				}
		  }
        
		// compute time1up
		int N=m*n;
		for(int i=0;i<N;i++)
		  if(mm[i][9]<inf) cout<<"debug mm[i][9] i:"<<i<<":"<<mm[i][9]<<endl;
		
		for(int i=0;i<N;i++)
		  for(int j=0;j<N;j++)
			time1[i][j]=mm[i][j];
			
		for(int i=0;i<N;i++)
			time1[i][i]=1;
		
		cout<<"time1[1][3]="<<time1[1][3]<<endl;
		cout<<"time1[0][3]="<<time1[0][3]<<endl;
		cout<<"time1[1][2]="<<time1[1][2]<<endl;
       	for(int k=0;k<N;k++)
		  for(int i=0;i<N;i++)
		    for(int j=0;j<N;j++)
		    { 
		      int tmp=time1[i][k]+time1[k][j];
		      if(tmp<time1[i][j])
		      {  //cout<<i<<" to "<<j<<" use "<<k<<"="<<tmp<<endl;
			  //time1[i][j]=min(time1[i][j],time1[i][k]+time1[k][j]);
			    time1[i][j]=tmp;
			  }
			}
	
		//cout<<"time1[0][3]"<<time1[0][3]<<endl;


		int high=0;
		for(int i=1;i<N;i++)
		{
			if(time1[0][i]+time1[i][0]<=time1ToDark && land[i/n][i%n]>high)
			  high=land[i/n][i%n];
		}
		cout<<endl;
		for(int i=0;i<N;i++)
		{
			cout<<time1[0][i]<<"\t";
			if(i!=0 && (i+1)%n==0) cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<N;i++)
		{
			cout<<time1[i][0]<<"\t";
			if(i!=0 && (i+1)%n==0) cout<<endl;
		}
		
		cout<<endl;
		for(int i=0;i<N;i++)
		{
			cout<<time1[0][i]+time1[i][0]<<"\t";
			if(i!=0 && (i+1)%n==0) cout<<endl;
		}

		return high;
	}
};