import java.io.IOException;
import static java.lang.Math.abs;

public class Ex2 {
    static double sqrt(double x, double error) {

        double guess = x / 2, prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

    static double[] solve_2(double coefficient_2, double coefficient_1, double constant) {

        double error = 0.00000001;

        double delta = sqrt(coefficient_1 * coefficient_1 - 4 * coefficient_2 * constant, error);

        double x_1 = (-coefficient_1 + delta) / (2 * coefficient_2);
        double x_2 = (-coefficient_1 - delta) / (2 * coefficient_2);

        double[] x = new double[2];
        x[0] = x_1;
        x[1] = x_2;

        return x;
    }

    static double scan_double(String name) {

        double value;

        System.out.println("Insira " + name + ":");
        while (true) {
            try {
                value = EntradaTeclado.leDouble();
                break;
            } catch (IOException e) {
                System.out.println("Valor invalido inserido, tente novamente:");
                try {
                    EntradaTeclado.leString();
                } catch (IOException str) {
                    System.out.println("Erro.");
                }
            }
        }

        return value;
    }

    public static void main(String[] args) {

        double coefficient_2, coefficient_1, constant;

        coefficient_2 = scan_double("o coeficiente de x^2");
        coefficient_1 = scan_double("o coeficiente de x");
        constant = scan_double("a constante");

        double[] x = solve_2(coefficient_2, coefficient_1, constant);

        System.out.printf("x_1: %f\nx_2: %f", x[0], x[1]);
    }
}
