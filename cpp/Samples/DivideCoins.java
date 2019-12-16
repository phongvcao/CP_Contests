// Find the minimum number of US coins to make any amount
// Assume we have the following coins value:
// 1 cent, 5 cents, 10 cents, 21 cents, 25 cents
//

public class DivideCoins {
    private static int[] makeChange1(int[] coins, int n) {
        int numberOfDifferentCoins = coins.length;
        // solution is an int[] array that counts the amount of each type of
        // coins that we would need. It starts off with 5 elements representing
        // counting for each type of coins in the { 1, 5, 10, 21, 25 } array
        // coin types:
        //
        // Coin Types:          { 1, 5, 10, 21, 25 }
        // Coin Types Counts:   { 0, 0, 0, 0, 0 }
        //

        int[] solution;

        // If there is a single coin with value n, use it
        for (int i = 0; i < numberOfDifferentCoins; ++i) {
            if (coins[i] == n) {
                solution = new int[numberOfDifferentCoins];
                solution[i] = 1;
                return solution;
            }
        }

        // Else try all combinations of i and n - i coins
        solution = new int[numberOfDifferentCoins];
        int leastNumberOfCoins = Integer.MAX_VALUE;

        // n is the total value of coins that our solutions have to add up to
        // So here basically we divide the total values of coins n into 2 parts:
        // - The first part, called solution1, counts the needed amount of each
        //   type of coins to add up to i, which is incremented from 0 to n.
        // - The second part, called solution2, counts the needed amount of each
        //   type of coins to add up to n - i, which is decremented from n to 0
        //   (n - i)
        // - As the loop keeps going, there will be points when i and n - i
        //   reach the value of a type of coins among { 1, 5, 10, 21, 25 }. At
        //   this stage, a solution[] array consisting of all 0 elements except
        //   the one that has the same index with the coin of value i (or n - i).
        //
        // - In the very base case, both solution1[] and solution2[] arrays only
        //   consist of all 0 elements except the one that has the same index
        //   with the coin values of i and n - i, respectively. These 2
        //   solutions arrays then get merged and summed up together to form a
        //   final solution[] array to return as the return value for the
        //   makeChange1() function.
        //

        for (int i = 0; i < n; ++i) {
            int[] solution1 = makeChange1(coins, i);
            int[] solution2 = makeChange1(coins, n - i);

            int newCoinCount = totalCoinCount(solution1, solution2);

            if (newCoinCount < leastNumberOfCoins) {
                leastNumberOfCoins = newCoinCount;
                solution = arraySum(solution1, solution2);
            }
        }

        return solution;
    }


    private static void solveFor2(int n, int[] coins, int[][] solutions, int[] best) {
        int numberOfDifferentCoins = coins.length;

        // If there is a single coin with the value n, use it
        for (int i = 0; i < numberOfDifferentCoins; ++i) {
            if (coins[i] == n) {
                solutions[n] = new int[numberOfDifferentCoins];

                solutions[n][i] = 1;
                best[i] = 1;
                return;
            }
        }

        // Else try all combinations of i and n - i coins
        int leastNumberOfCoins = Integer.MAX_VALUE;
        for (int i = 1; i < n; ++i) {
            int coinCount = best[i] + best[n - i];
            if (coinCount < leastNumberOfCoins) {
                leastNumberOfCoins = coinCount;
                best[n] = coinCount;
                solutions[n] = arraySum(solutions[i], solutions[n - i]);
            }
        }
    }


    public static int[] makeChange2(int[] coins, int desiredTotal) {
        int numberOfDifferentCoins = coins.length;

        int[][] solutions = new int[desiredTotal + 1][];
        int[] best = new int[desiredTotal + 1];

        solutions[0] = new int[numberOfDifferentCoins];
        best[0] = 0;

        for (int n = 1; n <= desiredTotal; ++n) {
            solveFor2(n, coins, solutions, best);
        }

        return solutions[desiredTotal];
    }


    public static void main(String[] args) {
        int[] coins = { 1, 5, 10, 21, 25 };
        int solveForThisAmount = 63;
        int[] solution;

        // Try simple solution
        solution = makeChange1(coins, solveForThisAmount);
        System.out.println("solution: " + Arrays.toString(solution));

        // Try dynamic programming solution
        solution = makeChange2(coins, solveForThisAmount);
        System.out.println("solution: " + Arrays.toString(solution));
    }
}
