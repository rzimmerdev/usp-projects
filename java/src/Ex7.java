import java.io.IOException;

import static java.lang.Math.abs;

public class Ex7 {

    static double y(double x) {
        return Math.pow(x, 3) - Math.pow(x, 2) - 13 * x + 8;
    }

    static double find_root(double x_0, double x_1, double error, int iter) {
        // y(x) = x^3 - x^2 - 13x + 8
        double y_0 = y(x_0); // 8
        double y_1 = y(x_1); // -5

        double mean = (x_0 + x_1) / 2; // 0.5
        double y_mean = y(mean); // 1.375

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

    public static void main(String[] args) {

        double x_0 = 0, x_1 = 0;
        try {

            System.out.println("Insira o valor de x_0: ");
            x_0 = EntradaTeclado.leDouble();

        } catch (IOException e) {

            System.out.println("Valor invalido inserido.");
            System.exit(-1);
        }

        try {

            System.out.println("Insira o valor de x_1: ");
            x_1 = EntradaTeclado.leDouble();
            System.out.println("Obtendo raizes para: y(x) = x^3 - x^2 - 13x + 8");
            System.out.printf("Raiz encontrada: %f;", find_root(Math.min(x_0, x_1), Math.max(x_0, x_1), Math.pow(10, -7), 0));

        } catch (IOException i) {

            System.out.println("Valor invalido inserido.");
            System.exit(-1);
        }
    }
}
