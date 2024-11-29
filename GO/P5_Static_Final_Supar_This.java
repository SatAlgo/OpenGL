// 1. static Keyword
// The static keyword is used to create class-level variables and methods. 
//   These members belong to the class itself, not instances of the class. 
//   It means that a static member is shared by all instances of the class.

class Counter {
    static int count = 0;

    Counter() {
        count++;
    }

    static void displayCount() {
        System.out.println("Count: " + count);
    }
}

public class StaticKeyword {
    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter.displayCount(); // Static method called without object
    }
}


// 2. final Keyword
// The final keyword is used to make variables, methods, or classes unchangeable after they are defined.

class Vehicle {
    final int MAX_SPEED = 120;  // final variable

    final void start() {  // final method
        System.out.println("Vehicle started");
    }
}

class Car extends Vehicle {
    // Cannot override the start() method from Vehicle because it's final
    // void start() { }  // Compilation error
}

public class FinalKeyword {
    public static void main(String[] args) {
        Vehicle v = new Vehicle();
        System.out.println("Max Speed: " + v.MAX_SPEED);  // Final variable
        v.start();  // Final method
    }
}


// 3. super Keyword
// The super keyword refers to the immediate parent class of the current object. It is used to access:

// Parent class constructors.
// Parent class methods and variables.

class Animal {
    Animal() {
        System.out.println("Animal Constructor");
    }

    void sound() {
        System.out.println("Animals make sounds");
    }
}

class Dog extends Animal {
    Dog() {
        super();  // Calling the parent class constructor
        System.out.println("Dog Constructor");
    }

    void sound() {
        super.sound();  // Calling the parent class method
        System.out.println("Dog barks");
    }
}

public class SuperKeyword {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound();
    }
}


// 4. this Keyword
// The this keyword refers to the current object of the class. It can be used to:

// Refer to instance variables when there is a naming conflict with local variables.
// Call another constructor in the same class using this().

class Person {
    String name;
    int age;

    // Constructor with parameters
    Person(String name, int age) {
        this.name = name;  // Using 'this' to refer to the instance variable
        this.age = age;
    }

    // Constructor with a single parameter, calling the other constructor
    Person(String name) {
        this(name, 18);  // Calling the constructor with two parameters
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

public class ThisKeyword {
    public static void main(String[] args) {
        Person person1 = new Person("John", 25);
        Person person2 = new Person("Alice");

        person1.display();
        person2.display();
    }
}
