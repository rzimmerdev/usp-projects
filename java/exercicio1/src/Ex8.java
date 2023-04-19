public class Ex8 {

    // Function to find roots of
    static double f(double x) {

        return Math.pow(x, 3) - Math.pow(x, 2) - 13 * x + 8;
    }

    // Derivative of function y = f(x), in respect to x
    static double dy_dx(double x) {

        return 3 * Math.pow(x, 2) - 2 * x - 13;
    }

    // Function to obtain square root (^1/2) using Newton-Raphson Metod of given value,
    // with maximum expected error
    static double find_root(double root, double error) {
        double y;
        int iter = 0;

        do {
            y = f(root);

            root -= y / dy_dx(root);

            iter++;
            System.out.printf("Iteracao atual: %d, com aproximacao da raiz: %f\n", iter, root);

        } while (Math.abs(y) > error);

        return root;
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

        double root = 0, error = Math.pow(10, -7);

        System.out.println("Insira o valor de x_0 (ponto proximo): ");
        root = scan_double("Valor invalido inserido, tente novamente:");

        System.out.printf("Raiz encontrada: %f", find_root(root, error));
    }
}
