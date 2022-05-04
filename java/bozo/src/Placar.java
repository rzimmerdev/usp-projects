<<<<<<< HEAD
import java.util.Arrays;

public class Placar {

    int[] placeholder;

    public Placar() {

        placeholder = new int[10];

        for (int i = 0; i < 10; i++) {
            placeholder[i] = -1;
        }
    }

    /**
     * Adds a sequence of dice values into the selected position in the scores placeholder,
     * unless position is already filled.
     *
     * @param posicao Position in placeholder 1-indexed to insert sequence of dices.
     * @param dados Sequence of dice values in Integer format to calculate value for given position.
     * @throws IllegalArgumentException when position argument corresponds to already filled position.
     */
    public void add(int posicao, int[] dados) throws IllegalArgumentException {

        if (placeholder[posicao - 1] != -1)
            throw new IllegalArgumentException("Posição já está ocupada!.");

        placeholder[posicao - 1] = 0;

        switch (posicao) {

            // Calculate score for dice-values as total weighted sum of dices with respective value.
            case 1, 2, 3, 4, 5, 6: {
                for (int i = 0; i < dados.length; i++) {
                    if (dados[i] == posicao)
                        placeholder[posicao - 1] += posicao;
                }
                break;
            }

            // Calculate if dice sequence is of type triplet + tuple, setting position score to 15.
            case 7: {
                Arrays.sort(dados);
                if ((dados[0] == dados[2] && dados[3] == dados[4]) || (dados[0] == dados[1] && dados[2] == dados[4]))
                    placeholder[6] = 15;
                break;
            }

            // Calculate if group of five dices is a sequence with step of 1.
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

            // Calculate if four dices are equal and assign score 30.
            case 9: {
                Arrays.sort(dados);
                if ((dados[0] == dados[3]) || (dados[1] == dados[4]))
                    placeholder[8] = 30;
                break;
            }

            // Calculate if all dices in a group of five are equal and assign score 40.
            case 10: {
                Arrays.sort(dados);
                if (dados[0] == dados[4])
                    placeholder[9] = 40;
            }
        }
    }

    /**
     * Gets current scoreboard values for a single user instance.
     *
     * @return Sum of non-empty values in scoreboard placeholder.
     */
    public int getScore() {
        int total = 0;
        for (int i = 0; i < 10; i++) {
            if (placeholder[i] > 0)
                total += placeholder[i];
        }
        return total;
    }

    /**
     * Prints the player board with respective scores assigned to each field.
     *
     * @return String representation of game board displayed horizontally.
     */
    @Override
    public String toString() {

        String board =
                " (1)    |   (7)    |   (4) \n" +
                " --------------------------\n" +
                " (2)    |   (8)    |   (5) \n" +
                " --------------------------\n" +
                " (3)    |   (9)    |   (6) \n" +
                " --------------------------\n" +
                "        |   (10)   |       \n" +
                "        +----------+       ";

        for (int i = 0; i < 10; i++) {
            // Maintain empty placeholders if value is still not filled.
            if (placeholder[i] == -1) {
                continue;
            }

            // Else, replace keeping horizontal formatting.
            board = board.replace(
                    "(" + (i + 1) + ")",
                    " " + placeholder[i] + (placeholder[i] > 9 ? "" : " ") + ((i + 1 > 9) ? " " : "")
            );
        }

        return board;
    }
=======
package PACKAGE_NAME;public class Placar {
>>>>>>> master
}
