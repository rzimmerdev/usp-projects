import java.util.Arrays;

public class Bozo {

    static String scan_str(String name) {

        String value;

        System.out.println("Insira " + name + ":");
        while (true) {
            try {
                value = EntradaTeclado.leString();
                String[] indexes = value.split(" ");

                for (int i = 0; i < indexes.length; i++)
                    Integer.parseInt(indexes[i]);

                break;
            } catch (Exception e) {
                System.out.println("Valor invalido inserido, tente novamente:");
            }
        }

        return value;
    }

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

        Dado.RolaDados dados = new Dado(). new RolaDados();
        Placar jogador = new Placar();

        System.out.println("Pressione ENTER para iniciar o jogo!");
        for (int i = 0; i < 10; i++) {

            try {
                EntradaTeclado.leString();
            } catch (Exception e) {
                System.out.println(e);
            }

            dados.rolar();
            System.out.println(dados);

            String choices = scan_str("quais dados quer rolar novamente (separados por espaço), ou 0 para não rolar nenhum");
            dados.rolar(choices);

            System.out.println(dados);

            choices = scan_str("quais dados quer rolar novamente (separados por espaço), ou 0 para não rolar nenhum");
            int[] valores = dados.rolar(choices);

            System.out.println(dados);

            System.out.println(jogador);

            int position = scan_int("a posição em que queira inserir seus dados");
            jogador.add(position, valores);
            System.out.println(jogador);

            if (i < 9) {
                System.out.println("Pressione ENTER para começar a próxima rodada");
            }
        }
    }
}

class Placar {

    int[] placeholder;

    public Placar() {

        placeholder = new int[10];

        for (int i = 0; i < 10; i++) {
            placeholder[i] = -1;
        }
    }

    public void add(int posicao, int[] dados) throws java.lang.IllegalArgumentException {

        if (placeholder[posicao - 1] != -1)
            throw new IllegalArgumentException("Posição já está ocupada, seu ignóbil.");

        placeholder[posicao - 1] = 0;

        switch (posicao) {
            case 1, 2, 3, 4, 5, 6: {
                for (int i = 0; i < dados.length; i++) {
                    if (dados[i] == posicao)
                        placeholder[posicao - 1] += posicao;
                }
                break;
            }

            case 7: {
                Arrays.sort(dados);
                if ((dados[0] == dados[2] && dados[3] == dados[4]) || (dados[0] == dados[1] && dados[2] == dados[4]))
                    placeholder[6] = 15;
                break;
            }

            case 8: {
                Arrays.sort(dados);
                int i = 5;
                if (dados[4] == 6)
                    i = 6;

                for (int j = 0; j < 5; j++) {
                    if (dados[4 - j] != i)
                        i = 0;
                    i--;
                }
                if (i != -1)
                    placeholder[7] = 20;
                break;
            }

            case 9: {
                Arrays.sort(dados);
                if ((dados[0] == dados[3]) || (dados[1] == dados[4]))
                    placeholder[8] = 30;
                break;
            }

            case 10: {
                Arrays.sort(dados);
                if (dados[0] == dados[4])
                    placeholder[9] = 40;
            }
        }
    }

    public int getScore() {
        int total = 0;
        for (int i = 0; i < 10; i++) {
            if (placeholder[i] == 1)
                total += placeholder[i];
        }
        return total;
    }

    @Override
    public String toString() {

        String board =  " (1)    |   (7)    |   (4) \n" +
                        " --------------------------\n" +
                        " (2)    |   (8)    |   (5) \n" +
                        " --------------------------\n" +
                        " (3)    |   (9)    |   (6) \n" +
                        " --------------------------\n" +
                        "        |   (10)   |       \n" +
                        "        +----------+       ";

        for (int i = 0; i < 10; i++) {

            if (placeholder[i] == -1) {
                continue;
            }
            board = board.replace(
                    "(" + (i + 1) + ")",
                    " " + placeholder[i] + (placeholder[i] > 9 ? "" : " ")
            );
        }

        return board;
    }
}