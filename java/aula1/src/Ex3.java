import java.io.IOException;

public class Ex3 {

    public static void main(String[] args) {

        System.out.println("Insira o tamanho da piramide: ");

        try {
            int size = EntradaTeclado.leInt();

            for (int i = size; i > 0; i--) {

                System.out.println("*".repeat(i));
            }
        } catch (IOException e) {
            System.out.println("Valor invalido para o tamanho da piramide.");
        }
    }
}
