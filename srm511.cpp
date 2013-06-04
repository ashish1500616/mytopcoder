# srm 511
#GameOfLifeDivOne
public long theCount(String init, int T, int K) {
    int N = init.length(), i, j, i2, j2, k, k2, one;
    String init2 = init + init;

    int edge[][][][] = new int[2 * N + 1][2][2 * N + 1][2];
    for(i = 0; i <= 2 * N; i ++) for(i2 = 0; i2 < 2; i2 ++)
        for(j = 0; j <= 2 * N; j ++) for(j2 = 0; j2 < 2; j2 ++) {
            edge[i][i2][j][j2] = -1;
            if(i < j && (j - i) % 2 != (i2 + j2) % 2) {
                boolean flag = true;
                for(k = i; k < j; k ++) {
                    if((k - i) % 2 == 0 && init2.charAt(k) == '0' + (i2 ^ 1)) flag = false;
                    if((k - i) % 2 == 1 && init2.charAt(k) == '0' + i2) flag = false;
                }
                if(flag) {
                    if(i2 == 0 && j2 == 0) edge[i][i2][j][j2] = Math.max((j-i)/2-T, 0);
                    else if(i2 == 1 && j2 == 1) edge[i][i2][j][j2] = Math.min((j-i+1)/2+T, j-i);
                    else edge[i][i2][j][j2] = (j - i) / 2;
                }
            }
        }
    long ans = 0;
    if(K <= N/2 && edge[0][0][N][1] != -1) ans ++;
    if(K <= N/2 && edge[0][1][N][0] != -1) ans ++;

    for(k = 0; k < N; k ++) for(k2 = 0; k2 < 2; k2 ++) {
        long dp[][][] = new long[2 * N + 1][2][N + 1];
        for(i=0;i <= 2 * N; i ++) for(i2 = 0; i2 < 2; i2 ++)
            for(one = 0; one <= N; one ++)
                dp[i][i2][one] = 0;
        dp[k][k2][0] = 1;
        for(i = k;i < N + k; i ++)
            for(i2 = 0; i2 < 2; i2 ++)
                for(one = 0; one <= N; one ++)
                    if(dp[i][i2][one] != 0) {
                        for(j = i + 1; j <= N + k; j ++)
                            if(j < N || (j == N + k && i < N)) for(j2 = 0; j2 < 2; j2 ++) if(edge[i][i2][j][j2] != -1) {
                                int one2 = one + edge[i][i2][j][j2];
                                dp[j][j2][one2] += dp[i][i2][one];
                            }
                    }
        for(one=K;one<=N;one++) ans += dp[N+k][k2][one];
    }
    return ans;
}