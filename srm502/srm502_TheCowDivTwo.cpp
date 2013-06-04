
int find(int N, int K)
{
	int table[2][K+1][N];
	for(int p=N;p>=0;p--){
		for(int k=0;k<=K;k++){
			for(int s=0;s<N;s++){
				if(k==0){
					if(s==0){
						table[p%2][k][s]=1;
					}else {
						table[p%2][k][s]=0;
					}
				}else if(p==N){
					table[p%2][k][s]=0;
				}else {
					table[p%2][k][s]=table[(p+1)%2][k-1][(s-p+N)%N]+table[(p+1)%2][k][s];
					table[p%2][k][s]%=100000007;
				}		
			}
		}
	}
	return table[0%2][K][0];
}