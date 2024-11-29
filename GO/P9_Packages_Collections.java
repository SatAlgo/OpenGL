// 1. Program to Create Own Package
// In Java, a package is a mechanism for organizing Java classes into 
//   namespaces, providing a way to group related classes, interfaces, 
//   and sub-packages. Packages are used to avoid name conflicts and to 
//   control access to classes.

// Steps to Create and Use a Package:
// Create a package: Define a package at the beginning of your Java class 
//   file using the package keyword.
// Use the package: Import the package using the import keyword in the class that needs it.

// File: mypackage/Student.java
package mypackage; // Declaring package

public class Student {
    private String name;
    private int age;

    // Constructor
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to display student information
    public void display() {
        System.out.println("Student Name: " + name);
        System.out.println("Student Age: " + age);
    }
}


// Step 2: Use the package

// File: TestStudent.java
import mypackage.Student; // Import the package

public class TestStudent {
    public static void main(String[] args) {
        // Creating an object of Student class from mypackage
        Student student1 = new Student("John", 20);
        student1.display(); // Calling the method to display student information
    }
}


// 2. Program Based on Java Collections
// Java Collections Framework provides a set of classes and 
//   interfaces to store and manipulate data. Some of the 
//   commonly used collections are:

// List (e.g., ArrayList, LinkedList) - Stores ordered elements and allows duplicates.
// Set (e.g., HashSet, TreeSet) - Stores unique elements.
// Map (e.g., HashMap, TreeMap) - Stores key-value pairs, and each key is unique.

import java.util.ArrayList;

public class CollectionExample {
    public static void main(String[] args) {
        // Creating an ArrayList to store Integer elements
        ArrayList<Integer> list = new ArrayList<>();

        // Adding elements to the ArrayList
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);

        // Displaying the ArrayList
        System.out.println("ArrayList: " + list);

        // Accessing an element by index
        System.out.println("Element at index 2: " + list.get(2));

        // Removing an element
        list.remove(1); // Removes element at index 1 (20)

        // Displaying after removal
        System.out.println("ArrayList after removal: " + list);

        // Looping through the ArrayList
        System.out.println("Iterating over the list:");
        for (Integer num : list) {
            System.out.println(num);
        }
    }
}
