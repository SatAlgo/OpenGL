import java.util.*;

public class Student {
    private String name;
    private int rollNumber;

    // Constructor to initialize member variables
    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    // Method to display details
    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
    }

    public static void main(String[] args) {
        Student s = new Student("Alice", 101); // Call parameterized constructor
        s.displayDetails(); // Display student details
    }
}
