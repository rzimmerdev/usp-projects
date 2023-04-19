import static java.lang.Math.abs;

public class Ex1 {

    // Function to obtain square root (^1/2) of given value, with maximum expected error
    static double sqrt(double x, double error) {

        double guess = x / 2;
        double prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

    static double scan_double(String name) {

        double value;

        System.out.println("Insira " + name + ":");
        while (true) {
            try {
                value = EntradaTeclado.leDouble();
                break;
            } catch (Exception e) {
                System.out.println("Valor invalido inserido, tente novamente:");
            }
        }

        return value;
    }

    public static void main(String[] args) {

        System.out.println("Insira o numero para tirar raiz 'x':");
        double x, error = 0.00000001;

        // Try to read a double value from console input, and print square root of value
        x = scan_double("Valor invalido inserido, tente novamente");
        System.out.printf("sqrt(x): %f", sqrt(x, error));
    }
}