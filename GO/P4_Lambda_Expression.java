import java.util.ArrayList;

public class LambdaExample {
    public static void main(String[] args) {
        // Create a list of integers
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(5);

        // Use a lambda expression to print each number
        numbers.forEach(number -> System.out.println("Number: " + number));

        // Lambda for custom operation
        int result = operate(5, 10, (a, b) -> a + b); // Add two numbers
        System.out.println("Sum: " + result);
    }

    // Method accepting lambda as a parameter
    public static int operate(int a, int b, MathOperation op) {
        return op.operation(a, b);
    }

    // Functional Interface
    interface MathOperation {
        int operation(int a, int b);
    }
}
