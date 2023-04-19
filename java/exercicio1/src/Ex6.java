public class Ex6 {

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

        // Keep track of important variables, that will need to be printed after 0 is read
        double smallest = 0, biggest = 0, current;

        // Keep scanning new doubles up until 0 is scanned
        System.out.println("Insira a sequencia a seguir: ");
        do {
            current = scan_double("Valor inserido invalido, valores validos: (0, 0.1, -5.000, 111111, ...)");

            // Base case to see if 0 is not the first value inserted
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
        } while (current != 0);

        System.out.printf("Maior: %f\nMenor: %f", biggest, smallest);
    }

}
