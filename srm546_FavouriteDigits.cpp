string to_string(long long x){
	stringstream ss;
	ss<<x;
	return ss.str();
}

string to_int(const string &s){
	stringstream ss;
	ss<<s;
	long long x;
	ss>>x;
	return x;
}

long long findNext(long long intN, int digit1, int count1, int digit2, int count2){
	if(digit1>digit2){
		swap(digit1,digit2);
		swap(count1,count2);
	}
	char d1='0'+digit1, d2='0'+digit2;
	string N=to_string(intN-1);
	int L=max(count1+count2,int(N.size()));
	N=string(L-N.size(),'0')+N;
	
	int lc1=max(0,count1-(d1=='1'));
	int lc2=max(0,count2-(d2=='1'));
	string longer=string(1,'1')+string(L-lc1-lc2,'0')+string(lc1,di)+string(lc2,d2);
	
	string answer="";
	for(int i=0;i<L;i++){
		for(char d='9';d>N[i];d--){
			int c1=max(0,count1 - (d==d1));
			int c2=max(0,count2 - (d==d2));
			if(c1+c2>L-1-i) continue;
			string current=N.substr(0,i)+string(1,d)+string(L-i-1-c1-c2,'0')+string(c1,d1)+string(c2,d2);
			if(current[0]!='0') answer=current;
		}
		count1-=N[i]==d1;
		count2-=N[i]==d2;
	}
	if(answer=="")answer=longer;
	return to_int(answer);
}


















