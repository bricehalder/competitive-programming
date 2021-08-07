import java.util.ArrayList;

public class PrimeSum {
    public static ArrayList<Integer> primesum(int a) {
        // generate all prime numbers using sieve
        // for all prime numbers, check if complement is also in set

        ArrayList<Integer> primeNums = new ArrayList<>();

        boolean[] primes = new boolean[a + 1];
        for (int i = 0; i < primes.length; i++) {
            primes[i] = true;
        }

        for (int i = 2; i * i < (a + 1); i++) {
            if (primes[i]) {
                for (int j = i * 2; j < primes.length; j += i) {
                    primes[j] = false;
                }
            }
        }

        for (int i = 2; i < (primes.length + 1) / 2; i++) {
            if (!primes[i]) {
                continue;
            }

            if (primes[a - i]) {
                primeNums.add(i);
                primeNums.add(a - i);
                return primeNums;
            }
        }

        return primeNums;
    }

    public static void main(String[] args) {
        System.out.println(primesum(4));
    }
}
