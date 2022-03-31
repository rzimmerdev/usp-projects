import java.io.IOException;

import static java.lang.Math.abs;

public class Ex5 {

    static double sqrt(double x, double error) {

        double guess = x / 2, prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

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

    public static void main(String[] args) {

        System.out.println("Insira um numero para achar o menor primo mais proximo: ");

        int x;

        try {
            x = EntradaTeclado.leInt();

            for (int i = x; i > 2; i--) {
                if (is_prime(i)) {
                    System.out.printf("Resultado: %d", i);
                    break;
                }
            }

        } catch (IOException e) {
            System.out.println("Valor invalido para x inserido.");
        }
    }
}