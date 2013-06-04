/*****
/* author:yinyin2010@gmail.com
/* time: 2008-4-7
/* score:135/250
/*
*/
#include <string>
#include <vector>

using namespace std;

class VerifyCreditCard{
public:
	VerifyCreditCard(){}
	string checkDigits(string cardNumber){
		int sum=0;

		if(cardNumber.size()%2==0){
			for(int i=0;i<cardNumber.size();i++){
				int temp=static_cast<int>(cardNumber.at(i)-'0');
				if(i%2==0){
					if(temp<5){
						sum+=temp*2;
					}else{
						sum+=temp*2-9;
					}
				}else{
					sum+=temp;
				}

			}
		}else{
			for(int i=0;i<cardNumber.size();i++){
				int temp=static_cast<int>(cardNumber.at(i)-'0');
				if(i%2!=0){
					if(temp<5){
						sum+=temp*2;
					}else{
						sum+=temp*2-9;
					}
				}else{
					sum+=temp;
				}

			}
		}

		if(sum%10==0) {return "VALID";}
		else {return "INVALID";}
	}
};
/**
int main(){
	VerifyCreditCard app;
	string cardnum="542987223412";
	string test=app.checkDigits(cardnum);
}
*/