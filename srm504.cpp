//MathContest

int countBlack(string ballSequence, int repetitions){
	int n=ballSequence.length(),t=n*repetitions;
	int b=0;
	int lo=0;hi=t-1;
	bool negative=false, reverse=false;
	
	while(lo<=hi){
		int x=(reverse?(hi--):(lo++));
		bool black=(ballSequence[x%n]=='B');
		
		if(negative){
			black=!black;
		}
		if(black){
			b++;
			negative=!nagative;
		}else {
			reverse=!reverse;
		}
	}
	return b;
}

// Algrid

vector<string> makeProgram(vector<string> output)
{
	int w=output[0].size(),h=output.size();
	for(int i=h-2;i>=0;i--){
		for(int j=w-2;j>=0;j--){
			char a=output[i],b=out[i][j+1];
			char & c=output[i+1][j], &d=output[i+1][j+1];
			if(a=='B'&&b='B'){
				swap(c,d);
			}else if(a=='B' && b=='W'){
				if(c=='W'||d=='W'){
					return vector<string>(0);
				}else {
					c=d='?';
				}
			}else if(a=='W'&&b=='B'){
				if(c=='B'||d=='B'){
					return vector<string>(0);
				}else{
					c=d='?';
				}
			}			
		}
		replace(output[i+1].begin(),output[i+1].end(),'?','B');
	}
	return output;
}