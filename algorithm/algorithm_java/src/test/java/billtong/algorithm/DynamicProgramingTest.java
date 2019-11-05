package billtong.algorithm;

import billtong.algorithm.dynamic_programing.MakeChange;
import org.junit.Test;

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
        System.out.println("the min coins\t" + cm.minCoins(target));
    }
}
