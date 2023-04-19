import java.util.Arrays;

public class RolaDados {

    Dado[] todos;

    public RolaDados() {
        this(5);
    }

    // Initialize each dice and roll value to avoid any errors.
    public RolaDados(int total) {

        todos = new Dado[total];
        for (int i = 0; i < total; i++) {

            todos[i] = new Dado();
            todos[i].rolar();
        }
    }

    /**
     * Rolls every dice on the board, using boolean specified roll function.
     *
     * @return Integer list corresponding to each dice value on the newly generated board.
     */
    public int[] rolar() {

        boolean[] which = new boolean[todos.length];
        Arrays.fill(which, true);
        return rolar(which);
    }

    /**
     * Transforms a string into a boolean sequence of dices to be rolled, performing
     * boolean specified roll function on the translated string.
     *
     * @param s Integer parseable string corresponding to dices to be rolled.
     * @return Integer list corresponding to each dice value on the board, even the ones that were not re-rolled.
     */
    public int[] rolar(String s) {

        String[] indexes = s.split(" ");
        boolean[] which = new boolean[todos.length];

        for (int i = 0; i < indexes.length; i++) {
            int index;
            try {
                index = Integer.parseInt(indexes[i]);
            } catch (final NumberFormatException e) {
                continue;
            }
            if (index - 1 < todos.length && index - 1 >= 0)
                which[index - 1] = true;
        }

        return rolar(which);
    }

    /**
     * Boolean-filtered function to roll selected dices on board.
     *
     * @param which Boolean list with indexes corresponding to dice to be rolled,
     *              with 1 meaning to roll and 0 to ignore.
     * @return Integer list corresponding to each dice value on the board, even the ones that were not re-rolled.
     */
    public int[] rolar(boolean[] which) {
        int[] values = new int[todos.length];
        for (int i = 0; i < todos.length; i++) {
            if (which[i] && todos[i] != null)
                todos[i].rolar();

            assert todos[i] != null;
            values[i] = todos[i].valor;
        }

        return values;
    }

    /**
     * Visualization of sequence of dices side-by-side for current game board.
     * Each dice corresponds to a single instance of a self-managed dice and can be
     * individually changed.
     *
     * @return String representation of dices on game board displayed horizontally.
     */
    @Override
    public String toString() {
        StringBuilder horizontal = new StringBuilder();

        // Print header for each dice on the first line, as to avoid keeping the indexes of each dice on the
        // board on the dice itself.
        for (int i = 0; i < todos.length; i++) {
            horizontal.append(" ").append(i + 1).append("         ");
        }
        horizontal.append("\n");

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < todos.length; j++) {

                // Splits each dice string representation on a per-line basis,
                // and prints each dice one line at a time.
                horizontal.append(todos[j].toString().split("\n")[i]);
                horizontal.append("    ");
            }

            horizontal.append("\n");
        }

        return horizontal.toString();
    }
}
