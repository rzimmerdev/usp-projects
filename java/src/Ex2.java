import static java.lang.Math.abs;

public class Ex2 {

    // Function to obtain square root (^1/2) of given value, with maximum expected error
    static double sqrt(double x, double error) {

        double guess = x / 2, prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

    // Function to obtain roots of polynomial equation of degree 2.
    // Coefficients are in order of their respective degrees of x.
    static double[] solve_2(double coefficient_2, double coefficient_1, double constant) throws Exception {

        double error = 0.00000001;

        double delta = coefficient_1 * coefficient_1 - 4 * coefficient_2 * constant;

        if (delta < 0) {
            throw new Exception("A equacao nao tem raizes reais.");
        }

        double[] x = new double[2];

        double x_1 = (-coefficient_1 + sqrt(delta, error)) / (2 * coefficient_2);
        double x_2 = (-coefficient_1 - sqrt(delta, error)) / (2 * coefficient_2);

        x[0] = x_1;
        x[1] = x_2;

        return x;
    }

    // Function to encapsulate try and catch input errors when trying to read a double value.
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

        // Scan coefficients and constant of a polynomial equation and solve for its roots
        double coefficient_2, coefficient_1, constant;

        coefficient_2 = scan_double("o coeficiente de x^2");
        coefficient_1 = scan_double("o coeficiente de x");
        constant = scan_double("a constante");
        double [] x;
        try {
            x = solve_2(coefficient_2, coefficient_1, constant);
            System.out.printf("x_1: %f\nx_2: %f", x[0], x[1]);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
