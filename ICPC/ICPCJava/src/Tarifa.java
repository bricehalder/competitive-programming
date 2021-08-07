import java.util.Scanner;

public class Tarifa {
    public static void main(String[] args) {
        System.out.println(solve());
    }
    public static int solve() {
        Scanner in = new Scanner(System.in);

        int X = in.nextInt();
        int N = in.nextInt();

        int sum = 0;

        for (int i = 0; i < N; i++) {
            sum += in.nextInt();
        }

        return X * (N + 1) - sum;
    }
}
