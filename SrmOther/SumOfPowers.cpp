#include<iostream>
#include <vector>

using namespace std;
class SumOfPowers{
public:
	SumOfPowers(){};
	int value(int n,int k){
		int item;
		int temp=0;
		int item_temp=0;
		for(int in_n=1;in_n<=n;in_n++){
			item=in_n;
			item_temp=item;
			for(int in_k=1;in_k<k;in_k++){
			item_temp*=item;
			}
			temp+=item_temp;
			
			temp=temp%1000000007;
			
		}
		
		double mode=1000000007;
		return temp%1000000007;
		//return temp%mode;
	}
};

int main(){
	SumOfPowers app;
	int res=app.value(123456789,1);

	cout<<res<<endl;
}