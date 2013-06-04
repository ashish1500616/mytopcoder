/************************************************************************/
/* author:yinyin2010@gmail.com
/* time 2008-4-6
/*
/*	P:
/*   1.how to convert string to int ?
/*		int num=atoi(number.c_str());
/*   2.how to delete a char in a string?
/*		iterator erase( iterator loc );
/*		iterator erase( iterator start, iterator end );
/*	 3. how many bite of int?
/*
/************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <sstream>

#include <stdlib.h>

using namespace std;


class RemovingDigits{
public:
	RemovingDigits(){}
	string maxNumber(string number,string digits){
		vector<int> removed_list;
		
		vector<string> str_choices;
		
		string p_str_num=number;




		for(int i=0;i<digits.size();i++){
			removed_list.push_back(static_cast<int>(digits.at(i))-48);
			//removed_list.push_back(atoi(digits.at(i)));
		}
		sort(removed_list.begin(),removed_list.end());
		reverse(removed_list.begin(),removed_list.end());
		int p_int_rm;
		while(!removed_list.empty()){
			p_int_rm=removed_list.back();
			removed_list.pop_back();
			char p_cha_rm;

			p_cha_rm='0'+p_int_rm;
			string::size_type loc(-1);
			while((loc=p_str_num.find(p_cha_rm,loc+1))!=string::npos){

				string pb_str_num=p_str_num;
				pb_str_num.erase(loc,1);
				str_choices.push_back(pb_str_num);


			}
			sort(str_choices.begin(),str_choices.end());
			
			//change the best int to string
			p_str_num=str_choices.back();
			str_choices.clear();
			

		}

		return p_str_num;
	}
};


/** the long isn't long enough!!
class RemovingDigits{
public:
	RemovingDigits(){}
	string maxNumber(string number,string digits){
		vector<int> removed_list;
		vector<long> choice_list;
		vector<string> str_choices;
		//int num=atoi(number.c_str());
		string p_str_num=number;
		
		
		

		for(int i=0;i<digits.size();i++){
			removed_list.push_back(static_cast<int>(digits.at(i))-48);
			//removed_list.push_back(atoi(digits.at(i)));
		}
		sort(removed_list.begin(),removed_list.end());
		
		int p_int_rm;
		while(!removed_list.empty()){
			p_int_rm=removed_list.back();
			removed_list.pop_back();
			char p_cha_rm;
		
			p_cha_rm='0'+p_int_rm;
			string::size_type loc(-1);
			while((loc=p_str_num.find(p_cha_rm,loc+1))!=string::npos){
				
				string pb_str_num=p_str_num;
				pb_str_num.erase(loc,1);
				str_choices.push_back(pb_str_num);

				long test=atol(pb_str_num.c_str());
				choice_list.push_back(test);
				
			}
			sort(str_choices.begin(),str_choices.end());
			sort(choice_list.begin(),choice_list.end());
			//change the best int to string
			int best=choice_list.back();
			choice_list.clear();
			ostringstream ostr;
			ostr<<best;
			p_str_num=ostr.str();
			//it doesn't work!!
			ostr.clear();
			
		}

		return p_str_num;
	}
};
*/
/**
int main(){
	RemovingDigits test;
	string digits="2345978";
	string number="2654982765982365";
	string max=test.maxNumber(number,digits);
}
*/