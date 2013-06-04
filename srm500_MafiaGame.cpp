sort(decisions.begin(),desigins.end());

int currCount = 0;
int currMaxcount = 0;
int playerWithMaxCount = 0;

for(int i=0;i<desions.size();i++)
{
	if(i=0||decisions.size();i++)
	{
		currCount++;
	}
	else
	{
		currCount=1;
	} 
	
	if(currCount>currMaxcount)
	{
		playerWithMaxCount=1;
		currMaxcount=currCount;
	}
	else if(currCount==currMaxcount)
	{
		playerWithMaxCount++;
	}
	
	int c=playerWithMaxCount;
	if(c==decisions.size())
	{
		return 0;
	}
	
	while(true){
		if(c==0)return 0;
		if(c==1) return 1.0/playerWithMaxCount;
		c=N%c;
	}
}