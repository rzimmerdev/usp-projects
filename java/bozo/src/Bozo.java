public class Bozo {

    /**
     * Function to encapsulate string scanning from console, fine-tuned
     * to deal with values that don't represent an array of integers.
     *
     * @return Returns scanned line as string, making sure string can be split and each
     *         element transformed into integer.
     */
    static String scan_str() {

        String value;

        System.out.println("Insira " + "quais dados quer rolar novamente (separados por espaço), ou 0 para não rolar nenhum" + ":");
        while (true) {
            try {
                value = EntradaTeclado.leString();
                value.split(" ");

                // Try and parse each space separated character to int, and catch exception if not
                // possible to convert.

                break;
            } catch (Exception e) {
                System.out.println("Valor invalido inserido, tente novamente:");
            }
        }

        return value;
    }

    /**
     * Function to encapsulate int scanning, for reading positions
     * and dealing with invalid values.
     *
     * @return Single integer read from console line.
     */
    static int scan_int() {

        int value;

        System.out.println("Insira " + "a posição em que queira inserir seus dados" + ":");
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

    /**
     *  Runs an entire game of Yahtzee on single-player, printing game status to
     *  console and reading user inputs per line.
     */
    public static void main(String[] args) {

        RolaDados dados = new RolaDados();
        Placar jogador = new Placar();

        System.out.println("Pressione ENTER para iniciar o jogo!");
        for (int i = 0; i < 10; i++) {

            try {
                EntradaTeclado.leString();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

            // Allow user to roll dices twice.
            dados.rolar();
            System.out.println(dados);

            String choices = scan_str();
            dados.rolar(choices);
            System.out.println(dados);

            choices = scan_str();
            int[] valores = dados.rolar(choices);
            System.out.println(dados);

            System.out.println(jogador);

            // Test if user-inputted position to insert dice sequence is empty,
            // and keep requiring a new input otherwise.
            while (true) {
                try {
                    int position = scan_int();
                    jogador.add(position, valores);
                    break;
                } catch (IllegalArgumentException e) {
                    System.out.println(e.getMessage());
                }
            }

            System.out.println(jogador);
            if (i < 9) {
                System.out.println("Pressione ENTER para começar a próxima rodada");
            }
        }

        System.out.printf("O jogo acabou! Sua pontuação foi: %d", jogador.getScore());
    }
}

