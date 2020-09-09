package Section02;

public class Code17 {
    public static void main(String[] args) {
        for(int n=0; n<100000; n++){
            if(isPrime(n))
                System.out.println(n);
        }
    }

    static boolean isPrime(int n) {
        if (n<2)
            return false;
        for(int i=2; i*i<=n; i++)
            if(n%i == 0)
                return false;
        return true;
    }
}
