#include <algorithm> 
#include <cmath> 
#include <iostream> 

#include <list> 
#include <map> 
#include <string>
#include <vector>

using namespace std;
int debug=0;
struct node{
	int start;
	int end;
	int flag;// 0 even, 1 odd
};

struct node nodes[30];
struct node nodes2[60];
int M[60][60];

class RabbitJumping{
public:
	int getMinimum(vector<int> holes,int largeJump)
	{
		int nh=holes.size()/2;
		int n=nh+1;
		nodes[0].start=0-largeJump;
		for(int i=0;i<nh;i++)
		{
			nodes[i].end=holes[2*i]-1;
			nodes[i+1].start=holes[2*i+1]+1;
		}
		nodes[n-1].end=1000000001;
		for(int i=0;i<n;i++)
		{
			if(debug)cout<<i<<" "<<nodes[i].start<<" "<<nodes[i].end<<endl;
		}
		int n2=0;
		for(int i=0;i<n;i++)
		{
			if(nodes[i].start%2==0)
			{
				nodes2[n2].start=nodes[i].start;
				nodes2[n2].end=(nodes[i].end/2)*2;
				nodes2[n2].flag=0;
				n2++;
				if(nodes[i].end-nodes[i].start>1)
				{
					nodes2[n2].start=nodes[i].start+1;
					nodes2[n2].end=((nodes[i].end+1)/2)*2-1;
					nodes2[n2].flag=1;
					n2++;
				}
			}
			else
			{
				nodes2[n2].start=nodes[i].start;
				nodes2[n2].end=((nodes[i].end+1)/2)*2-1;
				nodes2[n2].flag=1;
				n2++;
				if(nodes[i].end-nodes[i].start>1)
				{
					nodes2[n2].start=nodes[i].start+1;
					nodes2[n2].end=(nodes[i].end/2)*2;
					nodes2[n2].flag=0;
					n2++;
				}
			}
		}
		if(debug)cout<<"split to two nodes"<<endl;
		for(int i=0;i<n2;i++)
		{
			if(debug)cout<<i<<" "<<nodes2[i].start<<" "<<nodes2[i].end<<" "<<nodes2[i].flag<<endl;
		}
		for(int i=0;i<n2;i++)
		  for(int j=0;j<n2;j++)
			M[i][j]=100000;
		
		if(debug)cout<<"connect n2="<<n2<<endl;
		for(int i=0;i<n2;i++)
		{
			for(int j=i+1;j<n2;j++)
			{
				int dmin,dmax;
				dmin=min(abs(nodes2[j].start-nodes2[i].end),abs(nodes2[j].start-nodes2[i].start));
				
				dmax=max(abs(nodes2[j].end-nodes2[i].start),abs(nodes2[j].end-nodes[j].end));
				
				bool ok=(nodes2[i].flag ^ nodes2[j].flag) == (largeJump%2);
				if(debug)cout<<"debug connect"<<i<<" "<<j<<endl;
				if(debug)cout<<"min="<<dmin<<";max"<<dmax<<";ok="<<ok<<endl;
				if(largeJump>=dmin && largeJump<=dmax && ok)
				{
				    M[i][j]=1;
				    M[j][i]=1;
				}
				/**
				//if(max>largeJump)
				  //break;
                */
			}
		}

		for(int i=0;i<n2;i++)
  		{
  			for(int j=0;j<n2;j++)
  			    if(debug)cout<<M[i][j]<<" ";
            if(debug)cout<<endl;
  		}
		for(int k=0;k<n2;k++)
		  for(int i=0;i<n2;i++)
			for(int j=0;j<n2;j++)
			  if(M[i][k]+M[k][j]<M[i][j])
				M[i][j]=M[i][k]+M[k][j];
		int ret;
		int src,dst;
		if(nodes2[0].flag==0)
		{
			src=0;
		}
		else
		{
			src=1;
		}
		if(nodes2[n2-1].flag==1)
		{
			dst=n2-1;
		}
		else
		{
			dst=n2-2;
		}
        if(debug)cout<<"src="<<src<<";dst="<<dst<<endl;
		if(M[src][dst]==100000)
		  ret=-1;
		else
		  ret=M[src][dst];
		return ret;
	}
};

int main(){
	RabbitJumping rabbit;
	vector<int> holes;
	holes.push_back(2);
	holes.push_back(3);
	int largeJump=3;
	int ret=rabbit.getMinimum(holes,largeJump);
	cout<<ret<<endl;
}}
