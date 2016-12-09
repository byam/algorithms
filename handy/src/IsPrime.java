
public class IsPrime {

    private static boolean isPrime(int p) {
        if (p <= 1)
            return false;
        if (p % 2 == 0)
            return false;

        int m = (int) Math.sqrt(p);

        for (int i = 3; i <= m; i+=2) {
            if (p % i == 0)
                return false;
        }

        return true;

    }

    public static void main (String[] args){
        int p = 79;
        int np = 77;

        if (isPrime(p))
            System.out.println(p + " is prime number");
        else
            System.out.println(p + " is not prime number");

        if (isPrime(np))
            System.out.println(np + " is prime number");
        else
            System.out.println(np + " is not prime number");
    }

}
