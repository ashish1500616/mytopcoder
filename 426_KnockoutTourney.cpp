#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class KnockoutTourney {
public:
	int meetRival(int N, int you, int rival){
		you --;
		rival --;
		int r = 0;
		while (you!=rival){
			you /=2;
			rival /=2;
			r ++;
		}
		return r;
	}
};