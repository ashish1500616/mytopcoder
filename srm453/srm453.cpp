 

class TheTournamentDivTwo{
public:
	int find(vector<int> points){
		int tot,ret;
		tot=ret=0;
		for(int i=0;i<points.size();i++)
		  tot+=points[i];
		ret=tot/2;
		if(tot%2==1)
		  ret=-1;
		return ret;
	}
};


