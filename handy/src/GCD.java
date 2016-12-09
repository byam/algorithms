
public class GCD {

    private static int gcd(int a, int b) {

        if (b == 0)
            return a;
        return gcd(b, a%b);
    }

    public static void main (String[] args){
        int a = 2336;
        int b = 1314;

        System.out.println("GCD: " + gcd(a, b));
    }
}
