public class Adivinha {

    static int scan_int(String name) {

        int value;

        System.out.println("Insira " + name + ":");
        while (true) {
            try {
                value = EntradaTeclado.leInt();
                break;
            } catch (Exception e) {
                System.out.println("Valor invalido inserido, tente novamente:");
            }
        }

        return value;
    }

    static int next_guess(int current_guess, int max, int min, boolean is_smaller) {

        if (is_smaller) {
            return (min + current_guess) / 2;
        }
        else {
            return (current_guess + max) / 2;
        }
    }

    public static void main(String[] args) {

        int max = scan_int("o valor máximo");
        int min = 0;

        int current_guess = (max / 2);
        int response = scan_int("-1 se for menor, 0 se for correto, e 1 se for maior: " + current_guess);

        while (!(response == 0)) {

            if (response == -1) max = current_guess;
            if (response == 1) min = current_guess;

            current_guess = next_guess(current_guess, max, min, response == -1);

            int diff = max - current_guess;
            if (diff == -1 || diff == 1) {
                System.out.printf("Seu número é %d", current_guess);
                response = 0;
            }
            else {
                response = scan_int("-1 se for menor, 0 se for correto, e 1 se for maior: " + current_guess);
            }
        }
    }
}
