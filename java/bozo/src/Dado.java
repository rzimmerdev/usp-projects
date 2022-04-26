import java.util.Arrays;

public class Dado {

    int faces, valor;
    static Random gerador = new Random();

    public Dado() {
        this(6);
    }

    public Dado(int faces) {
        this.valor = 0;
        this.faces = faces;
    }

    public int getLado() {
        return this.valor;
    }

    public void rolar() {
        this.valor = 1 + gerador.getIntRand(6);
    }

    @Override
    public String toString() {

        switch (this.valor) {
            case 1: {
                return "+-----+\n|     |\n|  *  |\n|     |\n+-----+\n";
            }
            case 2: {
                return "+-----+\n|*    |\n|     |\n|    *|\n+-----+\n";
            }
            case 3: {
                return "+-----+\n|*    |\n|  *  |\n|    *|\n+-----+\n";
            }
            case 4: {
                return "+-----+\n|*   *|\n|     |\n|*   *|\n+-----+\n";
            }
            case 5: {
                return "+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+\n";
            }
            case 6: {
                return "+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+\n";
            }
            default: {
                return "";
            }
        }
    }

    public class RolaDados {

        Dado[] todos;

        public RolaDados() {
            this(5);
        }

        public RolaDados(int total) {

            todos = new Dado[total];
            for (int i = 0; i < total; i++) {

                todos[i] = new Dado();
                todos[i].rolar();
            }
        }

        public int[] rolar() {

            boolean[] which = new boolean[todos.length];
            Arrays.fill(which, true);
            return rolar(which);
        }

        public int[] rolar(String s) {

            String[] indexes = s.split(" ");
            boolean[] which = new boolean[todos.length];

            for (int i = 0; i < indexes.length; i++) {
                int index = Integer.parseInt(indexes[i]);
                if (index - 1 < todos.length && index - 1 >= 0)
                    which[index - 1] = true;
            }

            return rolar(which);
        }

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

        @Override
        public String toString() {
            StringBuilder horizontal = new StringBuilder();

            for (int i = 0; i < todos.length; i++) {
                horizontal.append(" ").append(i + 1).append("         ");
            }
            horizontal.append("\n");

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < todos.length; j++) {

                    horizontal.append(todos[j].toString().split("\n")[i]);
                    horizontal.append("    ");
                }

                horizontal.append("\n");
            }

            return horizontal.toString();
        }
    }
}