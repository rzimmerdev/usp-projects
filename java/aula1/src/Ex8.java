import java.io.IOException;

public class Ex8 {

    static double f(double x) {

        return Math.pow(x, 3) - Math.pow(x, 2) - 13 * x + 8;
    }

    static double dy_dx(double x) {

        return 3 * Math.pow(x, 2) - 2 * x - 13;
    }

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

    public static void main(String[] args) {

        double root = 0, error = Math.pow(10, -7);

        try {
            System.out.println("Insira o valor de x_0 (ponto proximo): ");
            root = EntradaTeclado.leDouble();
        } catch (IOException e) {
            System.out.println("Valor invalido inserido");
            System.exit(-1);
        }

        System.out.printf("Raiz encontrada: %f", find_root(root, error));
    }
}
