import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Knapsack {
    public static void solve(String filename) {
        Scanner in = null;

        try {
            in = new Scanner(new File(filename));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int n = in.nextInt();
        int m = in.nextInt();

        List<Integer> quantities = new ArrayList<>();
        List<Integer> costs = new ArrayList<>();


        for (int i = 0; i < m; i++) {
            quantities.add(in.nextInt());
        }

        m = in.nextInt();

        for (int i = 0; i < m; i++) {
            costs.add(in.nextInt());
        }

        System.out.println(budgetShopping(n, quantities, costs));


    }

    public static int budgetShopping(int n, List<Integer> bundleQuantities, List<Integer> bundleCosts) {
        // recursive DP solution
        int m = bundleQuantities.size();
        int[] dp = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (bundleCosts.get(j) <= i) {
                    dp[i] = Math.max(dp[i], dp[i - bundleCosts.get(j)] + bundleQuantities.get(j));
                }
            }
        }

        return dp[n];
    }

    public static void main(String[] args) {
        solve("knapsack.in");
    }
}
