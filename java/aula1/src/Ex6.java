import java.io.IOException;

public class Ex6 {

    public static void main(String[] args) {

        double smallest = 0, biggest = 0, current;

        System.out.println("Insira a sequencia a seguir: ");
        do {
            try {
                current = EntradaTeclado.leDouble();
                if (smallest == 0) {
                    smallest = current;
                }
                if (biggest == 0) {
                    biggest = current;
                }
                if (current != 0) {
                    smallest = Math.min(smallest, current);
                    biggest = Math.max(biggest, current);
                }

            } catch (IOException e) {
                System.out.println("Valor invalido inserido.");
                break;
            }
        } while (current != 0);

        System.out.printf("Maior: %f\nMenor: %f", biggest, smallest);
    }

}
