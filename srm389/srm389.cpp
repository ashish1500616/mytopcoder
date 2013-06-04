class BoxesOfBooks{
public:
	
	int boxes(vector<int> weight,int maxWeight)
	{
		int n=sz(weight);
		if(n==0) return 0;
		int i=0,res=1;
		int cur=maxWeight;
		for(i=0;i<n;i++)
		{
			if(weight[i]<=cur)
			{
				cur=cur-weight[i];
			}else{
				cur=maxWeight-weight[i];
				res++;
			}
		}
		return res;
	}
};

