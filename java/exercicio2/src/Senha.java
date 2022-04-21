public class Senha {
    int max_range;
    int random_number;

    public Senha(int range) {
        max_range = range;

        Random random_generator = new Random();
        random_number = random_generator.getIntRand(max_range);
    }

    void decide_next(int guess) {
        if (guess < random_number) {
            System.out.println("O numero secreto é maior!");
        }
        else if (guess > random_number) {
            System.out.println("O número secreto é menor!");
        }
        else {
            System.out.println("Parabéns, você acertou.");
        }
    }
}

class Main {
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

    public static void main(String[] args) {

        int max_range = scan_int("o valor maximo");

        Senha jogo = new Senha(max_range);

        int current_guess = -1;

        while (current_guess != jogo.random_number) {

            current_guess = scan_int("o seu proximo palpite");

            jogo.decide_next(current_guess);
        }
    }
}