import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class PlacarTest {
    private Placar placar;
    private static Placar placar_static;

    @BeforeAll
    static void setupBeforeClass() {
        placar_static = new Placar();
    }

    @BeforeEach
    void setup() {
        placar = new Placar();
    }

    @AfterEach
    public void tearDown() {
        placar = null;
    }

    @Test
    public void testCreatePlacar() {
        assertEquals(0, placar.getScore());
    }

    /**
     * Selects two invalid board positions, one smaller
     * and one bigger than the plausible size, and returns
     * a correct test if both cases throw an IllegalArgumentException
     */
    @Test()
    public void testInvalidPosition() {
        int belowPosition = 0;
        int abovePosition = 11;
        int[] values = {1, 2, 3, 4, 5};

        assertThrows(IllegalArgumentException.class,
                ()-> placar.add(belowPosition, values));

        assertThrows(IllegalArgumentException.class,
                ()-> placar.add(abovePosition, values));
    }

    /**
     * Tests if the function to add new dice scores throws an error if the user selected position
     * is already preoccupied with a previously inserted value.
     */
    @Test()
    public void testOccupiedPosition() {
        int position = 1;
        int[] values = {1, 2, 3, 4, 5};

        placar.add(position, values);

        assertThrows(IllegalArgumentException.class,
                ()-> placar.add(position, values));
    }

    @Test
    public void testAdd() {
        int[] positions = {1, 2, 3, 4, 5, 6};
        int[][] values = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}};
        int last_score = 0;
        for (int i = 0; i < 6; i++) {
            int shift = i / 5;
            placar.add(positions[i], values[shift]);
            assertEquals(values[shift][i - shift], placar.getScore() - last_score);
            last_score = placar.getScore();
        }
    }

    /**
     * Tests if the Placar class object can correctly handle a full hand combination of dices,
     * in order or out of order, and each sequence to be verified before asserting that specific combination.
     *
     * A full hand combination has two equal dices, and three different from these two but equal amongst themselves.
     * Example:
     * 1, 1, 3, 3, 3 (In order)
     * 4, 4, 2, 4, 2 (Out of order)
     */
    @Test
    public void testFullHand() {
        int position = 7;
        // In order full hand
        placar.add(position, new int[]{1, 1, 3, 3, 3});
        assertEquals(15, placar.getScore());
        // Out of order full hand
        this.setup();
        placar.add(position, new int[]{4, 2, 2, 4, 2});
        assertEquals(15, placar.getScore());

        // Invalid full hand
        int[][] values = {
                {1, 2, 2, 3, 3},
                {1, 1, 2, 3, 3},
                {1, 1, 1, 2, 3},
                {1, 1, 2, 2, 3},
                {1, 1, 2, 3, 3},
                {1, 2, 3, 3, 3}
        };

        for (int[] value: values) {
            this.setup();
            placar.add(position, value);
            assertEquals(0, placar.getScore());
        }
    }

    /**
     * Tests if the Placar class object can correctly handle case in which four dices are equal,
     * in order or out of order, and each sequence to be verified before asserting that specific hand.
     */
    @Test
    public void testFourEquals() {
        int position = 9;
        //In order four equal dices
        placar.add(position, new int[]{4, 4, 4, 4, 5});
        assertEquals(30, placar.getScore());
        //Out of order four equal dices
        this.setup();
        placar.add(position, new int[]{4, 1, 4, 4, 4});
        assertEquals(30, placar.getScore());

        // Invalid Hand of Four
        int[][] values = {
                {1, 2, 2, 2, 3},
                {1, 1, 2, 2, 2},
                {1, 1, 1, 2, 3},
                {1, 2, 3, 3, 3},
                {1, 2, 2, 3, 3},
        };

        for (int[] value: values) {
            this.setup();
            placar.add(position, value);
            assertEquals(0, placar.getScore());
        }
    }

    /**
     * Tests if the Placar class object can correctly handle case in which all dices are equal,
     * and each sequence to be verified before asserting that specific hand.
     */
    @Test
    public void testGeneral() {
        int position = 10;
        placar.add(position, new int[]{3, 3, 3, 3, 3});
        assertEquals(40, placar.getScore());

        // Invalid General combinations
        int[][] values = {
                {1, 2, 2, 2, 2},
                {1, 1, 2, 2, 2},
                {1, 1, 1, 2, 2},
                {1, 1, 1, 1, 2}
        };

        for (int[] value: values) {
            this.setup();
            placar.add(position, value);
            assertEquals(0, placar.getScore());
        }
    }

    /**
     * Tests if the Placar class object can correctly handle sequences of dices (1-5, or 2-6),
     * as well as individually test each invalid case from all possible permutations of a non-valid sequence.
     */
    @Test
    public void testSequence() {
        int position = 8;
        // In order sequence
        placar.add(position, new int[]{1, 2, 3, 4, 5});
        assertEquals(20, placar.getScore());
        // Out of order sequence
        this.setup();
        placar.add(position, new int[]{6, 4, 3, 5, 2});
        assertEquals(20, placar.getScore());

        // Invalid Sequences
        int[][] values = {
                {1, 1, 1, 1, 1},
                {1, 2, 2, 2, 2},
                {1, 2, 3, 3, 3},
                {1, 2, 3, 4, 4},
                {2, 2, 2, 2, 2},
                {2, 3, 3, 3, 3},
                {2, 3, 4, 4, 4},
                {2, 3, 4, 5, 5},
                {1, 2, 3, 5, 6} // Will probably fail the test
        };

        for (int[] value: values) {
            this.setup();
            placar.add(position, value);
            assertEquals(0, placar.getScore());
        }
    }

    /**
     * Generates an example placeholder game with fixed input dices and scores
     *
     * Useful to test other functionalities without having to generate a new player each time.
     */
    public void partialGame() {
        // Game view:
        /*
                5      |   15     |   (4)
                --------------------------
                (2)    |   (8)    |   (5)
                --------------------------
                9      |   (9)     |   12
                --------------------------
                       |   40     |
                       +----------+
         */
        // Current Score:
        // 81

        // Full hand
        int[] values = {1, 1, 3, 3, 3};
        placar.add(7, values);

        // Sum of values '3'
        values = new int[]{1, 3, 5, 3, 3};
        placar.add(3, values);

        // Sum of values '6'
        values = new int[]{6, 6, 5, 1, 2};
        placar.add(6, values);

        // Sum of values '1'
        values = new int[]{1, 1, 1, 1, 1};
        placar.add(1, values);
    }

    /**
     * Tests the function to count total game score for one single player.
     *
     * Uses the :func:partialGame function to generate a placeholder game with known total score.
     */
    @Test
    public void testGetScore() {
        this.partialGame();

        assertEquals(41, placar.getScore());
    }

    /**
     * Tests the string representation of the Placar object, by filling in multiple positions with values.
     *
     * Filled in positions are expected to be adapted to match
     * line sizes as well as to expose the score for each respective field.
     */
    @Test
    public void testToString() {

        this.partialGame();

        String expected = """
                5      |   15     |   (4)\s
                --------------------------
                (2)    |   (8)    |   (5)\s
                --------------------------
                9      |   (9)    |   12 \s
                --------------------------
                       |   (10)   |
                       +----------+
                """;

        assertEquals(expected, placar.toString());

        // Adds score for the Full Hand position (last line)
        int[] values = new int[]{2, 2, 2, 2, 2};
        placar.add(10, values);

        expected = """
                5      |   15     |   (4)\s
                --------------------------
                (2)    |   (8)    |   (5)\s
                --------------------------
                9      |   (9)    |   12 \s
                --------------------------
                       |   40     |
                       +----------+
                """;

        assertEquals(expected, placar.toString());
    }
}