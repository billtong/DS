package billtong.algorithm;

import billtong.algorithm.dynamic_programing.LongestCommonSubstring;
import billtong.algorithm.dynamic_programing.MakeChange;
import org.junit.Assert;
import org.junit.Test;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class DynamicProgramingTest {

    @Test
    public void changeMakingTesting() {
        Integer arr[] = {1, 4, 9};
        int target = 12;
        Set<Integer> coins = new HashSet<>(Arrays.asList(arr));
        MakeChange cm = new MakeChange(coins);
        Assert.assertTrue(cm.minCoins(target).containsAll(Arrays.asList(4, 4, 4)));
    }

    /**
     * 0	1	1	1	1	1	1
     * 0	1	1	1	2	2	2
     * 0	1	2	2	2	2	2
     * 1	1	2	2	2	3	3
     * 1	2	2	3	3	3	4
     * 1	2	2	3	3	4	4
     * (i:6, j:7)
     * (i:5, j:7)
     * (i:4, j:6)
     * (i:3, j:5)
     * (i:2, j:5)
     * (i:1, j:4)
     * (i:0, j:3)
     */
    @Test
    public void longestCommonSubstring() {
        String a = "bdcaba";
        String b = "abcbdab";
        String lcs = new LongestCommonSubstring(a, b).solve();
        Assert.assertTrue(lcs.equals("bcba") || lcs.equals("bdab"));
    }
}
