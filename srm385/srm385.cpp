class RussianSpeedLimits{
public:
	int getCurrentLimit(vector<string> signs)
	{
		int n=sz(signs);
		int city=1;
		int cs=60;
		int os=90;
		int cur;
		for(int i=0;i<n;i++)
		{
			if(signs[i]=="city")
			  city=-city;
		}
		if(signs[n-1]=="city" || signs[n-1]=="default")
		{
			if(city>0) return cs;
			if(city<0) return os;
		}
		else
		{
			stringstream ss(signs[n-1]);
			ss>>cur;
		}
		return cur;
	}
};

class UnderscoreJustification{
public:
	string justifyLine(vector<string> words,int width)
	{
		int all,min,max,nmin,nmax;
		int n=sz(words);
		all=0;
		for(int i=0;i<n;i++)
		  all+=sz(words[i]);
		min=(width-all)/(n-1);
		max=min+1;
		nmax=(width-all)%(n-1);
		nmin=(width-all-max*nmax)/min;
		string res;
		res=words[0];
		for(int i=1;i<n;i++)
		{
			if((words[i][0]>'Z' && nmax) || (words[i][0]<'_' && !nmin))
			{
				nmax--;
				for(int j=0;j<max;j++)
				  res+='_';
			}
			else if((words[i][0]<'_' && nmin) || (words[i][0]>'Z' && !nmax))
			{
				nmin--;
				for(int j=0;j<min;j++)
				  redds+='_';
			}
			res+=words[i];
		}
		return res;
	}
};



		


