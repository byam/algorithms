import java.util.Arrays;

public class AllPrime {

    private static boolean[] sieve(int n) {
        boolean[] primes = new boolean[n+1];

        Arrays.fill(primes, true);
        primes[0] = false;
        primes[1] = false;
        int m = (int) Math.sqrt(n);

        for (int i = 2; i <= m; i++) {
            if (primes[i])
                for (int j = i*i; j <= n; j+= i) {
                    primes[j] = false;
                }
        }

        return primes;
    }


    public static void main (String[] args){
        int n = 100;
        boolean[] primes;

        primes = sieve(n);

        // print all prime numbers
        for (int i = 1; i <= n; i++) {
            if (primes[i])
                System.out.print(i + " ");
        }
        System.out.println();
    }
}
