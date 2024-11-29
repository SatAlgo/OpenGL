import java.io.*;

public class FileHandlingExample {
    public static void main(String[] args) {
        // Creating a new file
        try {
            File file = new File("example.txt");

            // Check if the file exists, and create it if it doesn't
            if (file.createNewFile()) {
                System.out.println("File created: " + file.getName());
            } else {
                System.out.println("File already exists.");
            }

            // Writing to a file using FileWriter
            FileWriter writer = new FileWriter("example.txt");
            writer.write("Hello, welcome to file handling in Java!");
            writer.close();
            System.out.println("Successfully wrote to the file.");

            // Reading from a file using FileReader and BufferedReader
            FileReader reader = new FileReader("example.txt");
            BufferedReader bufferedReader = new BufferedReader(reader);

            String line;
            while ((line = bufferedReader.readLine()) != null) {
                System.out.println(line);
            }

            bufferedReader.close();
            reader.close();

            // Deleting the file
            if (file.delete()) {
                System.out.println("File deleted: " + file.getName());
            } else {
                System.out.println("Failed to delete the file.");
            }

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
