public class Ex4 {

    static int scan_int(String error) {

        int value;

        while (true) {
            try {
                value = EntradaTeclado.leInt();
                break;
            } catch (Exception e) {
                System.out.println(error);
            }
        }

        return value;
    }

    public static void main(String[] args){

        // Prints right skewed pyramid to console given total height from user
        System.out.println("Insira o tamanho da piramide: ");

        int size = scan_int("Valor invalido inserido, tente novamente:");

        for (int i = size; i > 0; i--) {
            System.out.print(" ".repeat(size - i));
            System.out.println("*".repeat(i));
        }
    }
}
