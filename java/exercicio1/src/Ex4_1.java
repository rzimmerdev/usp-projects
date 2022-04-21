import static java.lang.Math.abs;

public class Ex4_1 {

    // Function to obtain square root (^1/2) of given value, with maximum expected error
    static double sqrt(double x, double error) {

        double guess = x / 2, prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

    // Verify if all values up until square root of x divide x, else confirm that x is indeed prime
    static boolean is_prime(double x) {

        double error = 0.00000001;

        // Verify base cases
        if (x < 2)
            return false;
        if (x == 2)
            return true;
        if (x % 2 == 0)
            return false;

        for (int i = 3; i <= sqrt(x, error); i++) {
            if (x % i == 0)
                return false;
        }

        return true;
    }

    static int scan_int(String error) {

        int value;

        while (true) {
            try {
                value = EntradaTeclado.leInt();
                break;
            } catch (Exception e) {
                System.out.println(error);
            }
        }

        return value;
    }

    public static void main(String[] args) {

        System.out.println("Insira um numero para verificar a primalidade: ");

        int x = scan_int("Valor invalido para x inserido.");
        System.out.println("is_prime = " + is_prime(x));
    }
}