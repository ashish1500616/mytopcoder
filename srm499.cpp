
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
// WhiteSpaceEditing
struct WhiteSpaceEditing
{
  vector<int> lengths;
  vector<int> lines;
  int n;
  
  int mem[51][51][51][2];
  
  int F(int a, int b, int current, int lengthDecided){
    int & res = mem[a][b][current][lengthDecided];
    if(res==-1){
      if(a==b-1){
        res=fabs(lengths[current]-lines[a]);
      }else{
        res=10000000;
        if(!lengthDecided){
          for(int i=0;i<lengths.size();i++){
            int cost=fabs(lengths[current]-lengths[i]);
            res=std::min(res,F(a,b,i,1)+cost);
          }
        }else {
          for(int c=a+1;c<b;c++){
            int top = F(a,c,current,0);
            int bottom = F(c,b,current,0);
            res=std::min(res,top+bottom);
          }
        }
      }
    }
    return res;
  }
  int getMininum(vector<int> lines)
  {
    n = lines.size();
    this->lines=lines;
    
    lengths = lines;
    lengths.push_back(0);
    
    memset(mem,-1,sizeof(mem));
    return F(0,n,n,0)+n-1;
  }
};

/////////////////
//PalindromeGame
vector<string> words;
vector<int> scores;

int maxScore(int middle){
  int n = words.size();
  bool used[n];
  fill(used,used+n,false);
  if(middle!=-1){
    used[middle]=true;
  }
  
  int result=0;
  for(int i=0;i<n;i++){
    if(!used[i]){
      string word=words[i];
      string rev=word;
      reverse(rev.begin(),rev.end());
      vector<int> right,left;
      
      for(int j=i;j<n;j++){
        if(!used[j]){
          if(words[j]==word){
            used[j]=true;
            right.push_back(scores[j]);
          } else if(words[j]==rev){
              used[j]=true;
            left.push_back(scores[j]);
          }
        }
      }
      
      sort(right.begin(),right.end(),greater<int>());
      sort(left.begin(),left.end(),greater<int>());
      
      if(rev==word){
        if(right.size()%2==0){
          result+=accumulate(right.begin(),right.end(),0);
        }else{
          result+=accumulate(right.begin(),right.end()-1,0);
        }
      }else {
        int t = (int) min(right.size(),left.size());
        result+=accumulate(right.begin(),right.begin()+t,0);
        result+=accumulate(left.begin(),left.begin()+t,0);
      }
    }
  }
  return result;
}

int getMaximum(vector<string> front, vector<int> back)
{
  words=front;
  scores=back;
  
  int res=maxScore(-1);
  for(int i=0;i<front.size();i++){
    string rev=words[i];
    reverse(rev.begin(),rev.end());
    if(rev==words[i]){
      res=std::max(res,scores[i]+maxScore(i));
    }
  }
  return res;
}


//#######################
//colorfulRabbits

int getMinimum(vector<int> replies)
{
    int n = (int)replies.size();
    sort(replies.begin(),replies.end());
  
  int t = 0, i = 0;
  while(i<n){
    int x=replies[i]+1;
    int c=0;
    while(1<n && replies[i]==x-1){
      c++;
      i++;
    }
    
    while(c%x!=0){
      c++;
    }
    //c=((c-1)/x+1)*x;
    t+=c;
  }
  return t;
}

