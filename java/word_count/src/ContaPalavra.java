import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeMap;

public class ContaPalavra {
    /**
     * Function to count occurrences of words inside a given input file.
     * File name should be inserted on the Console, and the file itself should
     * be on the same directory as the executable.
     */
    private final String filename;
    private TreeMap<String, Integer> count;

    public ContaPalavra(String filename) {
        // Receives the filename to be used when performing scanning counting, and printing operations.
        this.filename = filename;
        this.count = null;
    }

    /**
     * Initializes a TreeMap (Map ordered by its keys) based on the words inside the given file.
     */
    public void criaMapa() {
        this.count = new TreeMap<>();

        // Try to open the predefined file, and print an error message otherwise.
        try (BufferedReader br = new BufferedReader(new FileReader(this.filename))) {

            String line;
            // Reads line by line each sequence of words within file, splitting by space characters
            // and adding words to internal Map
            while ((line = br.readLine()) != null) {

                String[] words = line.split("\\s+");

                // Merges the current word with the TreeMap =>
                // If word already exists within the Map, and sum one to its value
                // If word doesn't exist, insert it into the Map, and set its value to 1
                for (String word : words) {
                    this.count.merge(word.toLowerCase().replaceAll("[+.^:;,\"()!?]",""), 1, Integer::sum);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Erro: Arquivo de entrada nao encontrado!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Prints the internal TreeMap object, with the format
     * word: count, for all words within the predefined file TreeMap.
     */
    public void mostraMapa() {
        System.out.println("Contagem de palavras: ");
        for (String word : this.count.keySet()) {
            System.out.println(word + ": " + this.count.get(word));
        }
    }

    /**
     *  Creates the ContaPalavra object instance and reads a given input file.
     *  Also counts and prints the generated TreeMap with the words inside the file.
     */
    public static void main(String[] args) {

        System.out.println("Insira o nome do arquivo que contem o texto:");
        Scanner scan = new Scanner(System.in);
        String filename = scan.nextLine();

        ContaPalavra conta_palavra = new ContaPalavra(filename);

        conta_palavra.criaMapa();
        conta_palavra.mostraMapa();
    }
}

