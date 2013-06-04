class KingdomXCitiesandVillages{
public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)
	{
		int i,j;
		double ans=0.0;
		REP(i,villageX.size()){
			int x=villageX[i],y=villageY[i];
			
			vector<pair<ll,int> > p;//dist,type
			REP(j,cityX.size()){
				int dx=cityX[j]-x;
				int dy=cityY[j]-y;
				ll d=(ll)dx*(ll)dx+(ll)dy*(ll)dy;
				p.push_back(make_pair(d,0));
			}
			REP(j,villageX.size()) if(j!=i){
				int dx=villageX[j]-x;
				int dy=villageY[j]-y;
				ll d=(ll)dx*(ll)dx + (ll)dy*(ll)dy;
				p.push_bakc(make_pair(d,1));
			}
			
			sort(p.begin(),p.end());
			REP(j,p.size()){
				double d=sqrt((double)(p[j].first));
				if(p[j].second==0){
					ans+=1.0/(cnt+1.0)*d;
					break;
				}else{
					ans+=1.0/(cnt+1.0)/(cnt+2.0)*d;
					cnt++;
				}
			}
		}
		return ans;
	}		
};



