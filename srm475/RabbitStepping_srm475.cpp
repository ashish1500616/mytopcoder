#include <algorithm> 
#include <cmath> 
#include <iostream> 
#include <fstream>
#include <list> 
#include <map> 
#include <string>
#include <vector>

using namespace std;
ofstream fout("RabbitStepping.out");

int debug=0;
class RabbitStepping{
public:
	double getExpected(string field, int r)
	{
		double ret=0;
		int max=1<<field.size();
		double time=0;
		double total=0;
		for(int i=0;i<max;i++)
		{
			if(countbit(i)!=r)
			  continue;
	        if(debug)
	        {
	        	cout<<"call onecomb: comb="<<i<<endl;
	        }
			total+=onecomb(field,i);
			if(debug)cout<<"total="<<total<<endl;
			time++;
		}
		if(time!=0)
		  ret=total/time;

		return ret;
		
	}
	int countbit(int num)
	{
		int ret=0;
		while(num>0)
		{
			num=num & (num-1);
			ret++;
		}
		return ret;
	}

	double onecomb(string field, int comb)
	{
		int size=field.size();
		vector<int> cells(size);
		vector<int> cells2(size);
		for(int i=0;i<size;i++)
		{
			cells[i]=0;
			cells2[i]=0;
		}
		for(int i=0;i<size;i++)
		  if(comb & 1<<i)
			cells[i]=1;
			
		showcells(cells,size);
		
		while(size>2)
		{
			//move all rabbit
			for(int i=0;i<size;i++)
			{
				if(i==0 && cells[i]>0)
				{
				  moveright(cells,cells2,i);
				  //showcells(cells,size);
				  continue;
				}
			    if(i==size-2 && cells[i]>0)
				{
					moveleft(cells,cells2,i);
					//showcells(cells,size);
					continue;
				}
				if(i==size-1 && cells[i]>0)
				{
					moveleft(cells,cells2,i);
					//showcells(cells,size);
					continue;
				}

				if(field[i]=='W' && cells[i]>0)
				  moveleft(cells,cells2,i);
				if(field[i]=='B' && cells[i]>0)
				  moveright(cells,cells2,i);
				if(field[i]=='R' && cells[i]>0)
				  moveleft(cells,cells2,i);
		        //showcells(cells,size);

			}
			cells=cells2;
   			for(int i=0;i<size;i++)
            {
     	        cells2[i]=0;
            }
			//clear cell have two rabbit
			for(int i=0;i<size;i++)
			  if(cells[i]>1)
				cells[i]=0;
			//could reduce size
			if(cells[size-1]==0)
			  size--;
            
	        //debug
	        showcells(cells,size);       
		}
		return cells[0]+cells[1];
	}
	void moveleft(vector<int> &src,vector<int> &dst, int index)
	{
		src[index]--;
		dst[index-1]++;
	}
	
	void moveright(vector<int> &src,vector<int> &dst,int index)
	{
		src[index]--;
		dst[index+1]++;
	}
	void showcells(vector<int> cells,int size)
	{
		if(!debug) return;
		for(int i=0;i<size;i++)
		{
			cout<<cells[i]<<" ";
		}
		cout<<endl;
	}
};
/**
int main(){
	string field="WRBRW";
	int r=4;
	RabbitStepping rabbitstepping;
	double ret=rabbitstepping.getExpected(field,r);
	cout<<ret<<endl;
}
*/
