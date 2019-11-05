package billtong.algorithm.dynamic_programing;

import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.IntStream;

/**
 * Change Making Problem
 * Definition: The change-making problem addresses the question of
 * finding the minimum number of coins (of certain denominations)
 * that add up to a given amount of money.
 */
@Data
@RequiredArgsConstructor
public class MakeChange {
    @NonNull
    private Set<Integer> coinSet;
    private int decisionTreeArray[];

    private int getDecisionTreeVal(int[] array, int index) {
        return index < 0 ? Integer.MAX_VALUE : array[index];
    }

    /**
     * we can recover the optimal solution if we have access to the array A,
     * by working backwards from the end of the solution.
     *
     * @param minNum
     * @return
     */
    private List<Integer> traceBackMinCoins(int minNum) {
        List<Integer> coins = new ArrayList<>(minNum);
        int loc = decisionTreeArray.length - 1;
        for (int i = minNum; i > 0; i--) {
            for (int coin : coinSet) {
                if (loc - coin >= 0 && i - decisionTreeArray[loc - coin] == 1) {
                    coins.add(coin);
                    loc -= coin;
                    break;
                }
            }
        }
        return coins;
    }

    /**
     * compare each turn's result from greedy algorithm,
     * get the minimum of minimums
     * create an array A with index values from 0 to target.
     * value is the min coins number, index is the target value
     * pseudo-Code
     * --------------
     * Set A[0] = 0;
     * for i = 0 to n;
     * A[i] = 1 + min(getDecisionTreeVal(A, i-c1), getDecisionTreeVal(A, i-c2), ..., getDecisionTreeVal(A, i-ck));
     * return traceBack(A[n]);
     * --------------
     *
     * @param target
     * @return
     */
    public List<Integer> minCoins(int target) {
        decisionTreeArray = new int[target + 1];
        decisionTreeArray[0] = 0;
        IntStream.range(1, target + 1).forEach(i -> {
            coinSet.stream()
                    .mapToInt(coin -> getDecisionTreeVal(decisionTreeArray, i - coin))
                    .min()
                    .ifPresent(value -> decisionTreeArray[i] = 1 + value);
        });
        return traceBackMinCoins(decisionTreeArray[target]);
    }
}
