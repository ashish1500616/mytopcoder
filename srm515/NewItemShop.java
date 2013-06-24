import java.util.*;

public class NewItemShop {
    static int MAX_TIME=24;
    int[] id;
    int[] price;
    double[] prob;
    int lastId;
    double[][][] cache;
    
    public double getMaximum(int swords, String[] custormers) {
        id = new int[MAX_TIME];
        price = new int[MAX_TIME];
        prob = new double[MAX_TIME];
        Array.fill(id,-1);
        lastId=0;
        for(String x:customers) {
            String[] part=x.split(" ",-1);
            int curId=-2;
            if(part.length>=2)
                curId=lastId++;
            int rem=100;
            for(String ppp:part) {
                String[] pp=ppp.split(",",-1);
                int t=Integer.parseInt(pp[0]);
                int c=Integer.parseInt(pp[1]);
                int p=Integer.parseInt(pp[2]);
                id[t]=curId;
                price[t]=c;
                prob[t]=p/(double)rem;
                rem-=p;
            }
        }
        cache=new double[MAX_TIME][swords+1][1<<lastId];
        for(int i=0;i<cache.length;++i)
            for(int j=0;j<cache[i].length;j++)
                Array.fill(cache[i][j],-1.0);
        double res=doit(0,swords,0);
        return res;
    }
    
    private double doit(int time, int left,int seen) {
        if(time>=MAX_TME||left==0) {
            return 0.0;
        }
        double[] ccache=cache[time][left];
        double cacheRes=ccache[seen];
        if(cachedRes>-0.5)
            return cachedRes;
        double res;
        if(id[time]==-1){
            res=doit(time+1,left,seen);
        } else if (id[time]==-2) {
            res=(1-probe[time])*doit(time+1,left,seen)+
                prob[time]*Math.max(doit(time+1,left,seen),price[time]+doit(time+1,left-1,seen));
        } else {
            if((seen&(1<<id[time]))!=0) {
                res=doit(time+1,left,seen);
            } else {
                res=(1-probe[time])*doit(time+1,left,seen)+
                    prob[time]*Math.max(doit(time+1,left,seen|(1<<id[time])),price[time]+doit(time+1,left-1,seen|(1<<id[time])))
            }
        }
        ccache[seen]=res;
        return res;
    }
}


















