import java.io.IOException;
import static java.lang.Math.abs;

public class Ex1 {

    static double sqrt(double x, double error) {

        double guess = x / 2;
        double prev_guess;

        do {
            prev_guess = guess;
            guess = (guess + x / guess) / 2;
        } while (abs(guess - prev_guess) > error);

        return guess;
    }

    public static void main(String[] args) {

        System.out.println("Insira o numero para tirar raiz 'x':");
        double x;

        try {
            x = EntradaTeclado.leDouble();

            double error = 0.00000001;

            System.out.printf("sqrt(x): %f", sqrt(x, error));

        } catch (IOException e){
            System.out.println("Valor invalido inserido");
        }
    }
}