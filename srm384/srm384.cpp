class Prank{
public:
	vector<int> realWeight(int apparentGain)
	{
		int inf=100000;
		vi res;
		for(int i=1;i<inf;i++)
		{
			int s1=i*i;
			int s2=(i+1)*(i+1);
			if(s2-s1>apparentGain) break;
			for(int j=i+1;j<inf;j++)
			{
				int cur=j*j;
				if(cur-s1>apparentGain) break;
				if(cur-s1==apparentGain) res.pb(j);
			}
		}
		return res;
	}
};


class Library{
public:
	int documentAccess(vector<string> records,vector<string> userGroups,vector<string> roomRights)
	{
		set<string> docs;
		string d,r,g;
		int n=sz(records);
		for(int i=0;i<n;i++)
		{
			stringstream stream(records[i]);
			stream>>d>>r>>g;
			if(cpresent(userGroups,g))
			  if(cpresent(roomRights,r))
				docs.insert(d);
		}
		int res=sz(docs);
		return res;
	}
};