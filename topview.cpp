string findOrder(vector<string> grid)
{
	int n = 0;
	map<char,int> charid;
	char idchar[200];
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			char ch = grid[i][j];
			if(ch!='.'){
				if(!charid.count(ch)){
					idchar[n]=ch;
					charid[ch]=n;
					n++
				}
			}
		}
	}
	
	bool before[n][n];
	memset(before,0,sizeof(before));
	
	int w=grid.size();
	int h=grid[0].size();
	
	for(int i=0;i<n;i++){
		int minx=w-1,maxx=-1;
		int miny=h-1,maxy=-1;
		for(int x=0;x<w;x++){
			for(int y=0;y<h;y++){
				if(grid[x][y]==charid[i]){
					minx=std::min(minx,x);
					maxx=std::max(maxx,x);
					miny=std::min(miny,y);
					maxy=std::max(maxy,y);
				}
			}
		}
		
		for(int x=minx;x<maxx;x++){
			for(int y=miny;y<maxy;y++){
				if(grid[x][y]=='.'){
					return "ERROR!";
				}
				if(grid[x][y]!=idchar[i]){
					before[i][charid[grid[x][y]]]=true;
				}
			}
		}
	}
	string ret="";
	vector<bool> removed(n,false);
	for(int i=0;i<n;i++){
		pair<char,int> best=make_char('z'+1,-1);
		
		for(int j=0;j<n;j++){
			if(!removed[j]){
				bool can=true;
				for(int k=0;k<n;k++){
					can &=(removed[k]||!before[k][j]);
				}
				if(can){
					best=std::min(best,make_pair(idchar[j],j));
				}
			}
		}
		if(best.second==-1){
			return "ERROR!";
		}
		ret+=best.first;
		removed[best.second]=true;
	}
}
