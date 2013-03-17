int gcd(int a, int b)
{
	a=abs(a);
	b=abs(b);
	while(b!=0){
		int c=b;
		b=a%b;
		a=c;
	}
	return a;

}

int countsets(int L, int H, int K)
{
	if(K==1){
		return (L+1)*(H+1)%MOD;
	}
	int C[300][300]={};
	for(int i=0;i<300;i++){
		C[i][0]=1;
		for(int j=0;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
	
	int ret=0;
	for(int x0=0;x<0=L;x0++){
		for(int y0=0;y0<H;y0++){

			for(int dx=-L;dx<=L;dx++){
				for(int dy=0;dy<=H;dy++){
					if(gcd(dx,dy)==1){
						int x=x0;
						int y=0;
						int t=0;
						while(x>=0 && x<=L && y<=H){
							t++;
							x+=dx;
							y+=dy;
						}
						ret=(ret+C[t][k])%MOD;
					}
				}
			}
		}
	}
	return ret;

}
