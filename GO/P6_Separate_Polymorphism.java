// 1. Compile-time Polymorphism (Method Overloading)
// In method overloading, we can have multiple methods with the 
//   same name but different parameters (different number of parameters 
//   or different types). The compiler 
//   decides which method to call based on the number or type of arguments passed.


class Calculator {
    // Method for adding two integers
    int add(int a, int b) {
        return a + b;
    }

    // Method for adding three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Method for adding two double numbers
    double add(double a, double b) {
        return a + b;
    }
}

public class MethodOverloadingExample {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        // Calling the overloaded methods
        System.out.println("Sum of two integers: " + calc.add(10, 20));
        System.out.println("Sum of three integers: " + calc.add(10, 20, 30));
        System.out.println("Sum of two doubles: " + calc.add(10.5, 20.5));
    }
}


// 2. Runtime Polymorphism (Method Overriding)
// In method overriding, a subclass provides its specific implementation 
//   of a method that is already defined in its superclass. The method 
//   in the subclass should have the same name, return type, and parameters 
//   as the one in the superclass. The method that is called is 
//   determined at runtime, based on the object type.



class Animal {
    // Method in parent class
    void sound() {
        System.out.println("Animals make sounds");
    }
}

class Dog extends Animal {
    // Overriding the method in child class
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    // Overriding the method in child class
    void sound() {
        System.out.println("Cat meows");
    }
}

public class MethodOverridingExample {
    public static void main(String[] args) {
        // Creating objects of subclasses
        Animal animal1 = new Dog(); // Upcasting
        Animal animal2 = new Cat(); // Upcasting

        // Calling the overridden methods
        animal1.sound();  // Outputs: Dog barks
        animal2.sound();  // Outputs: Cat meows
    }
}
