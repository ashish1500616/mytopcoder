//InstantRunoffVoting 
import java.util.*; 
public class InstantRunoffVoting 
{ 
  public int winner(String[] voters) 
  { 
    int m = voters.length, n = voters[0].length(); 
    boolean[] used = new boolean[n]; 
    while(true) 
    { 
      int[] count = new int[n]; 
      for(int i=0;i<m;i++) 
      { 
        for(int j=0;j<n;j++) 
        { 
          int dig = voters[i].charAt(j)-'0'; 
          if(!used[dig]) 
          { 
            count[dig]++; 
            break; 
          } 
        } 
      } 
      int min = 10000; 
      for(int i=0;i<n;i++) 
      { 
        if(!used[i]) 
        { 
          if(count[i]*2>m) 
            return i; 
          else 
            min = Math.min(min, count[i]); 
        } 
      } 
      boolean ok = false; 
      for(int i=0;i<n;i++) 
        if(!used[i]) 
          if(count[i]==min) 
            used[i] = true; 
          else 
            ok = true; 
      if(!ok) 
        return -1; 
    } 
  } 
}


using namespace std; 
#define INF 0x7FFFFFFF 
#define PB push_back 

int foi[60]; 
int qte; 
class InstantRunoffVoting 
{ 
    public: 
    int  winner(vector <string> a ) 
    { 
      int i,j; 
      int tam=a.size(); 
      int n=a[0].size(); 
    while(1) 
    { 
      int votos[60]={0}; 
      for(i=0;i<tam;i++) 
      { 
        for(j=0;j<n;j++) 
        { 
          if(foi[a[i][j]-'0']==0) 
          { 
            votos[a[i][j]-'0']++; 
            break; 
          } 
        } 
      } 
      int menor=9999; 
      for(i=0;i<n;i++) 
      { 
        if(votos[i]<menor && foi[i]==0)menor=votos[i]; 
      } 
      for(i=0;i<n;i++) 
      { 
        if(votos[i]==menor) 
        { 
          foi[i]=1; 
          qte++; 
        } 
        if(votos[i]>=(tam/2)+1)return i; 
      } 
      if(qte==n)return -1; 
    } 
    } 
};
