if(b2==0||q2<=1)
{
	swap(b1,b2);
	swap(q1,q2);
	swap(n1,n2);
}

if(b1==0||q1<=1)
{
	set<long long> S;
	S.insert(b1);
	if(n1>1S.in)
	{
		S.insert(b1*q1);
	}
	long long curr=b2;
	for(int t=0;t<n2;t++)
	{
		S.insert(curr);
		curr*=q2;
		if(curr>500000000){
			return (n2-t-1)+S.size();
		}
		return S.size();
	}
}

Set<int> factors;
factor(b1,factors);
factor(q1,factors);
factor(b2,factors);
factor(q2,factors);

vector<int> F(factors.begin(),factors.end());
vector<int> repb1, rep12, repb2, repq2;
decompose(b1,repb1,F);
decompose(q1,repq1,F);
decompose(b2,repb2,F);
decompose(q2,repq2,F);

set<vectoc<int> > S;

for(int i=0;i<n1;i++)
{
	S.insert(repb1);
	for(int t=0;t<repb1.size();t++)
	{
		repb1[t]+=repq1[t];
	}
}
for(int i=0;i<n2;i++)
{
	S.insert(repb2);
	for(int t=0;t<repb2.size();t++)
	{
		repb2[t]+=repq2[t];
	}
}
return S.size();
