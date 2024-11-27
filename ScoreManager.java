import java.io.*;
import java.nio.file.Paths;


public class ScoreManager {

    public void writeScore(String s) {
        String fileName="SCORE_FILE.txt";


        try (FileWriter writer = new FileWriter(fileName)) {
            // Write the content to the file
            writer.write(s);
            System.out.println("File written successfully: " + fileName);
        } catch (IOException e) {
            // Handle any errors
            System.err.println("An error occurred while writing to the file.");
            e.printStackTrace();
        }
    }

    public void readScoresFromFile(){
        String fileName="SCORE_FILE.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            System.out.println("NEW HIGH SCORE");
            // Read and print each line from the file
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            // Handle any errors
            System.err.println("An error occurred while reading the file.");
            e.printStackTrace();
        }
    }
}
