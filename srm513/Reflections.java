# petr
import java.util.*;
 
public class Reflections {
  public long minimumMoves(int[] mirrorX, int[] mirrorY, int[] mirrorZ, int[] finalPosition) {
    return solve(toLongArr(mirrorX), finalPosition[0]) + solve(toLongArr(mirrorY), finalPosition[1]) + solve(toLongArr(mirrorZ), finalPosition[2]);
  }
 
    private long[] toLongArr(int[] arr) {
        long[] res = new long[arr.length];
        for (int i = 0; i < arr.length; ++i) res[i] = arr[i];
        return res;
    }
 
    private long solve(long[] mirror, long need) {
        int n = mirror.length;
        int half = n / 2;
        long[][][] all = buildAll(mirror, 0, half);
        long[][][] all2 = buildAll(mirror, half, n - half);
        long res = Long.MAX_VALUE;
        for (int numPlus2 = 0; numPlus2 < all2.length; ++numPlus2)
            for (int numMinus2 = 0; numMinus2 < all2[numPlus2].length; ++numMinus2)
                for (int numPlus = 0; numPlus < all.length; ++numPlus)
                    for (int numMinus = 0; numMinus < all[numPlus].length; ++numMinus) {
                        int totalPlus = numPlus + numPlus2;
                        int totalMinus = numMinus + numMinus2;
                        if (totalPlus == totalMinus || totalPlus == totalMinus + 1) {
                            long[] first = all[numPlus][numMinus];
                            long[] second = all2[numPlus2][numMinus2];
                            for (long x : first) {
                                long target = need - x;
                                int left = -1;
                                int right = second.length;
                                while (right - left > 1) {
                                    int middle = (left + right) / 2;
                                    if (second[middle] >= target)
                                        right = middle;
                                    else
                                        left = middle;
                                }
                                if (left >= 0)
                                    res = Math.min(res, totalPlus + totalMinus + (target - second[left]));
                                if (right < second.length)
                                    res = Math.min(res, totalPlus + totalMinus + (second[right] - target));
                            }
                        }
                    }
        return res;
    }
 
    private long[][][] buildAll(long[] mirror, int first, int len) {
        int[][] cnt = new int[len + 1][len + 1];
        long[][][] all = new long[len + 1][len + 1][];
        doit(mirror, first, first + len, 0, 0, 0, cnt, all, 1);
        for (int numPlus = 0; numPlus <= len; ++numPlus)
            for (int numMinus = 0; numMinus <= len; ++numMinus) {
                all[numPlus][numMinus] = new long[cnt[numPlus][numMinus]];
            }
        cnt = new int[len + 1][len + 1];
        doit(mirror, first, first + len, 0, 0, 0, cnt, all, 2);
        for (int numPlus = 0; numPlus <= len; ++numPlus)
            for (int numMinus = 0; numMinus <= len; ++numMinus) {
                Arrays.sort(all[numPlus][numMinus]);
            }
        return all;
    }
 
    private void doit(long[] mirror, int cur, int last, int numPlus, int numMinus, long sum, int[][] cnt, long[][][] all, int stage) {
        if (cur == last) {
            if (stage == 2) {
                all[numPlus][numMinus][cnt[numPlus][numMinus]] = 2 * sum;
            }
            ++cnt[numPlus][numMinus];
            return;
        }
        doit(mirror, cur + 1, last, numPlus, numMinus, sum, cnt, all, stage);
        doit(mirror, cur + 1, last, numPlus + 1, numMinus, sum + mirror[cur], cnt, all, stage);
        doit(mirror, cur + 1, last, numPlus, numMinus + 1, sum - mirror[cur], cnt, all, stage);
    }
 
}