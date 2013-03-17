string rec(string letters, int minInv, string minStr)
{
	if(letters==""){
		return "";
	}
	for(int i=0;i<letters.size();i++){
		if(minStr.size()>0 && minStr[0]>letters[i])
			continue;
	
		int ninv=max(minInv-i,0);
		int nn=letters.size()-1;

		if(nn*(nn-1)/2 >= ninv){
			nletters=letters.substr(0,i)+letters.substr(i+1);
			nstr="";
			if(minStr.size()>0 && minStr[0]==letters[i])
				nstr=minStr.substr(1);
			return string(1,letters[i])+rec(nletters,nInv,nStr);
		}
	}
	return "";
}