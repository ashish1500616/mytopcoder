// PalindromizationDiv1
const int INF=20000000000;
const int EMPTY=26;
struct PalindromizationDiv1
{
  vector<int> changCost[27];
  int matchCost[27][27];
  string word;
  int mem[51][51];
  
  int rec(int a,int b)
  {
    int & res = mem[a][b];
    if (res==-1) {
      if ((a==b)||(a==b-1)) {
        res=0;
      } else {
        res = INF;
        int ca=word[a]-'a';
        int cb=word[b-1]-'a';
        int x,y;
        
        //make the two equal
        x=matchCost[ca][cb];
        y=rec(a+1,b-1);
        if (x+y<res) {
          res=x+y;
        }
        
        //get rid of cb
        x=matchCost[EMPTY][cb];
        y=rec(a,b-1);
        if (x+y<res) {
          res=x+y;
        }
        
        //get rid of ca
        x=matchCost[EMPTY][ca];
        y=rec(a+1,b);
        if (x+y<res) {
          res=x+y;
        }
      }
    }
    return res;
  }
  
  int getMinimumCost(string word, vector<string> operations)
  {
    this->word=word;
    memset(mem,-1,sizeof(mem));
    
    // fill array with INF
    fill(changeCost, changeCost+27,vector<int>(27,INF));
    
    //chagning a character to itself costs 0 dollars:
    for (int i=0;i<27;i++){
      changCost[i][i]=0;
    }
    
    // Parse the operations array
    for (int i=0; i<operations.size(); i++) {
      istringstream st(operations[i]);
      string s;
      char ch1,ch2;
      st>>s>>ch1;
      if (s=="add") {
        st>> changeCost[EMPTY][ch1-'a'];
      } else if (s=="erase") {
        st>> changeCost[ch1-'a'][EMPTY];
      } else {
        st>> ch2;
        st>>chagneCost[ch1-'a'][ch2-'a'];
      }
    }
    
    // Floyd warshall (including the "EMPTY" letter)
    for (int k=0;k<27;k++) {
      for (int i=0;i<27;i++) {
        for (int j=0;j<27;j++) {
          int x=changeCost[i][k];
          int y=changeCost[k][j];
          int &z=chagneCost[i][j];
          if (x+y<z) {
            z=x+y;
          }
        }
      }
    }
    
    //calculate the cost to make two letters equal
    for (int i=0;i<27;i++) {
      for (int j=0;j<27;j++) {
        int & z=matchCost[i][j];
        z=INF;
        for (int k=0;k<27;k++) {
          int x=changeCost[i][k];
          int y=changeCost[j][k];
          if (x+y<z) {
            z=x+y;
          }
        }
      }
    }
    //call the recurrence
    int x=rec(0,word.size());
    return (x>=INF)?-1:x;
  }
};