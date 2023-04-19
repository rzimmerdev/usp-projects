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

    /**
     * @return Total sides on dice.
     */
    public int getLado() {
        return this.valor;
    }

    /**
     * Sets dice value to random value between range 1 and maximum faces on dice (6 being the default and included).
     */
    public void rolar() {
        this.valor = 1 + gerador.getIntRand(faces);
    }

    /**
     * Horizontal representation of the dice value as in a physical 6-sided dice.
     *
     * @return String representation of the dice value.
     */
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
}