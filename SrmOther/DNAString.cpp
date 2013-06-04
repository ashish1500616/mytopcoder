/************************************************************************/
/* 1.how to cast from vector<string>::iterator to string?
/* 2 string's size()
/* 3 min_element() and max_element()
/************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class DNAString{
public:
	DNAString(){}
	int minChanges(int maxPeriod,vector<string> dna){
		//A[i] if the period is i,then the change is A[i]
		int A[50]={0};

		//cstr a string of dna
		string cstr;
		
		int acgt[4]={0};
		for(int period=maxPeriod;period>=1;period--){
			for(vector<string>::iterator ite=dna.begin();ite!=dna.end();ite++){
				cstr=*ite;
				//to check the changes of a word under period
				for(int index=0;index<period;index++){
					int ii=index;
					while(ii<cstr.size()){
						if(cstr.at(ii)=='A'){
							acgt[0]++;
						}
						if(cstr.at(ii)=='C'){
							acgt[1]++;
						}
						if(cstr.at(ii)=='G'){
							acgt[2]++;
						}
						if(cstr.at(ii)=='T'){
							acgt[3]++;
						}

						ii+=period;
						
					}
					int max_same=*max_element(acgt,acgt+4);
					A[period]+=acgt[0]+acgt[1]+acgt[2]+acgt[3]-max_same;
					acgt[0]=acgt[1]=acgt[2]=acgt[3]=0;
				}
				
			}
		}
		return *min_element(A+1,A+maxPeriod+1);

	}	


};


int main(){
	DNAString alg;
	vector<string> test;
	
	test.push_back("ACGTATAGCATGACA");
	test.push_back("ACAGATATTATG");
	test.push_back("ACAGATGTAGCAGTA");
	test.push_back("ACCA");
	test.push_back("GCA");
	int min=alg.minChanges(12,test);
	cout<<min<<endl;
}