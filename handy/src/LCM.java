
public class LCM {

    private static int gcd(int a, int b) {

        if (b == 0)
            return a;
        return gcd(b, a%b);
    }

    private static int lcm(int a, int b) {

        return a * b / gcd(a, b);
    }


    public static void main (String[] args){
        int a = 2336;
        int b = 1314;

        System.out.println("LCM: " + lcm(a, b));
    }
}
