import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {

    public static void solve(String filename) {
        Scanner in = null;
        try {
            in = new Scanner(new File(filename));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int n = in.nextInt();
        int m = in.nextInt();

        List<Integer>[] graph = new ArrayList[n + 1];

        for (int i = 0; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            graph[a].add(b);
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j : graph[i]) {
                System.out.println(i + " " + j);
            }
        }
    }

    public static void main(String[] args) {
        solve("input.in");
    }
}
