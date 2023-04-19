import static java.lang.Math.abs;

public class Ex7 {

    // Function to find roots of
    static double f(double x) {
        return Math.pow(x, 3) - Math.pow(x, 2) - 13 * x + 8;
    }

    // Uses the bissection method to find the mean valid value between x_0 and x_1,
    // then keeps searching until the value y_0, y_1 or the f(mean) have values smaller than
    // the expected error
    static double find_root(double x_0, double x_1, double error, int iter) {
        // f(x) = x^3 - x^2 - 13x + 8
        double y_0 = f(x_0); // 8
        double y_1 = f(x_1); // -5

        double mean = (x_0 + x_1) / 2; // 0.5
        double y_mean = f(mean); // 1.375

        iter++;
        System.out.printf("Iteracao atual: %d, com media da raiz: %f\n", iter, mean);

        if (abs(y_0) < error)
            return x_0;
        if (abs(y_1) < error)
            return x_1;

        if (y_mean < -error)
            return find_root(x_0, mean, error, iter);
        if (y_mean > error)
            return find_root(mean, x_1, error, iter);
        return mean;
    }

    static double scan_double(String error) {

        double value;

        while (true) {
            try {
                value = EntradaTeclado.leDouble();
                break;
            } catch (Exception e) {
                System.out.println(error);
            }
        }

        return value;
    }

    public static void main(String[] args) {

        double x_0 = 0, x_1 = 0;

        // Verify if user input values for the range of x will eventually find a root,
        // else request for new range of values
        while (f(x_0) * f(x_1) >= 0) {
            System.out.println("Insira o valor de x_0:");
            x_0 = scan_double("Valor invalido inserido, tente novamente: ");
            System.out.println("Insira o valor de x_1");
            x_1 = scan_double("Valor invalido inserido, tente novamente: ");

            if (f(x_0) * f(x_1) >= 0) {
                System.out.println("Nao ha raizes entre o intervalo definido.");
            }
        }

        System.out.println("Obtendo raizes para: f(x) = x^3 - x^2 - 13x + 8");

        System.out.printf("Raiz encontrada: %f;", find_root(Math.min(x_0, x_1), Math.max(x_0, x_1), Math.pow(10, -7), 0));
    }
}
