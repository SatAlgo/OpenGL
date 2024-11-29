// 1. String
// Definition: A String is an immutable sequence of characters. 
// Once a String object is created, it cannot be modified.
public class StringExample {
    public static void main(String[] args) {
        String str = "Hello";
        str = str + " World"; // Creates a new String object
        System.out.println(str); // Output: Hello World
    }
}

// 2. StringBuffer
// Definition: A StringBuffer is a mutable sequence of characters. 
// It allows you to modify the content without creating a new object.
public class StringBufferExample {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Hello");
        sb.append(" World"); // Modifies the same object
        System.out.println(sb); // Output: Hello World
    }
}


// 3. StringBuilder
// Definition: A StringBuilder is similar to StringBuffer but without 
// synchronization, making it faster for single-threaded applications.
public class StringBuilderExample {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("Hello");
        sb.append(" World"); // Modifies the same object
        System.out.println(sb); // Output: Hello World
    }
}
