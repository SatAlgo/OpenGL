// Generics in Java allow us to write code that works 
//   with any type of data. It is used to ensure type safety 
//   and eliminate the need for type casting. Generics can be 
//   applied to classes, interfaces, and methods.

// Example 1: Generic Method Implementation

public class GenericMethodExample {
    // Generic method to print any type of array
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.println(element);
        }
    }

    public static void main(String[] args) {
        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] strArray = {"Hello", "World", "Generics"};

        System.out.println("Integer Array:");
        printArray(intArray);  // Passing Integer array

        System.out.println("\nString Array:");
        printArray(strArray);  // Passing String array
    }
}


// Example 2: Generic Class Implementation


// Generic class to hold any type of object
class Box<T> {
    private T value;

    // Set the value
    public void setValue(T value) {
        this.value = value;
    }

    // Get the value
    public T getValue() {
        return value;
    }
}

public class GenericClassExample {
    public static void main(String[] args) {
        // Create a Box for Integer type
        Box<Integer> intBox = new Box<>();
        intBox.setValue(100);
        System.out.println("Integer Value: " + intBox.getValue());

        // Create a Box for String type
        Box<String> strBox = new Box<>();
        strBox.setValue("Generics in Java");
        System.out.println("String Value: " + strBox.getValue());
    }
}
