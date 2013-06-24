class NewItemShopTwo {
public:
  void parse(string customer, vector<int> p, vector<int> c) {
  //  ...
  }
  double getMaximum(vector<string> customers) {
    double sum=0, sum1=0, sum2=0;
    int sump1=100, sump2=100;
    for(int i=0;i<24;i++) {
      sump1-=p1[i];
      sump2-=p2[i];
    }
    for(int i=23;i>=0;--i) {
      sump1+=p1[i];
      sump2+=p2[i];
      double pr1=(sump1==0)?0:(double)p1[i]/sump1;
      double pr2=(sump2==0)?0:(double)p2[i]/sump2;
      sum=pr1*pr2*max(c1[i],c2[i])
        +pr1*(1-pr2)*max(c1[i],sum2)
        +(1-pr1)*pr2*max(sum1,c2[i])
        +(1-pr1)*(1-pr2)*max(sum1,sum2);
      sum1=pr1*c1[i]+(1-pr1)*sum1;
      sum2=pr2*c2[i]+(1-pr2)*sum2;
    }
    return sum;
  }
}