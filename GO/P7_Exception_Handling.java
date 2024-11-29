// Exception Handling in Java
// Exception handling is a mechanism to handle runtime errors, 
//   so the normal flow of the application can be maintained. 
//   It allows you to manage errors gracefully without terminating 
//   the program unexpectedly. Java provides a robust framework 
//   for handling exceptions using the try, catch, throw, and finally blocks.

// Below is a detailed explanation of exception handling in Java 
//   and how to implement your own exception class.

import java.util.Scanner;

public class ExceptionHandlingExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Handling ArithmeticException
        try {
            System.out.print("Enter a number to divide by 0: ");
            int num = scanner.nextInt();
            int result = 10 / num;  // Will cause ArithmeticException if num is 0
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero!");
        }

        // Handling InputMismatchException
        try {
            System.out.print("Enter a string: ");
            String str = scanner.nextLine();  // Potential InputMismatchException
            int parsedNumber = Integer.parseInt(str);  // Will cause NumberFormatException if not a valid number
            System.out.println("Parsed number: " + parsedNumber);
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid number format!");
        }

        // Handling ArrayIndexOutOfBoundsException
        try {
            int[] arr = {1, 2, 3};
            System.out.println("Array element: " + arr[5]);  // Will cause ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array index out of bounds!");
        }

        // Finally block (executed regardless of exception)
        finally {
            System.out.println("This will always execute.");
        }

        scanner.close();
    }
}


// 2. Program to Create Your Own Exception Class
// In Java, you can define custom exceptions by creating a 
//   class that extends Exception or RuntimeException. Custom 
//   exceptions are useful when you want to represent specific 
//   error conditions that are relevant to your application.

// Step 1: Define a custom exception class
class AgeNotValidException extends Exception {
    // Constructor that accepts a custom error message
    public AgeNotValidException(String message) {
        super(message);
    }
}

public class CustomExceptionExample {
    // Method that checks if age is valid
    static void checkAge(int age) throws AgeNotValidException {
        if (age < 18) {
            // Step 3: Throw custom exception if age is less than 18
            throw new AgeNotValidException("Age must be 18 or above!");
        } else {
            System.out.println("Age is valid.");
        }
    }

    public static void main(String[] args) {
        try {
            checkAge(15);  // Will throw AgeNotValidException
        } catch (AgeNotValidException e) {
            // Step 2: Catch the custom exception and handle it
            System.out.println("Caught Exception: " + e.getMessage());
        }

        try {
            checkAge(20);  // Age is valid
        } catch (AgeNotValidException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        }
    }
}
