// 1. Abstract Class
// An abstract class is a class that cannot be instantiated on its own. 
//   It is designed to be inherited by other classes. An abstract class 
//   can have both abstract methods (methods without a body) and concrete 
//   methods (methods with a body). The abstract methods must be 
//   implemented by the subclasses.

// Key Points about Abstract Class:
// An abstract class can have both abstract and non-abstract (concrete) methods.
// An abstract class can have member variables.
// A class can inherit only one abstract class (Java does not support multiple inheritance through classes).

// Abstract class
abstract class Animal {
    // Abstract method (does not have a body)
    abstract void sound();
    
    // Concrete method (has a body)
    void sleep() {
        System.out.println("This animal is sleeping.");
    }
}

// Subclass (inherited from Animal)
class Dog extends Animal {
    // Providing implementation for the abstract method
    void sound() {
        System.out.println("Dog barks");
    }
}

// Subclass (inherited from Animal)
class Cat extends Animal {
    // Providing implementation for the abstract method
    void sound() {
        System.out.println("Cat meows");
    }
}

public class AbstractClassExample {
    public static void main(String[] args) {
        // Creating objects of subclasses
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        // Calling methods
        myDog.sound();   // Outputs: Dog barks
        myCat.sound();   // Outputs: Cat meows
        
        myDog.sleep();   // Outputs: This animal is sleeping.
    }
}


// 2. Interface
// An interface is a contract that a class must follow. An interface 
//   can contain abstract methods (methods without a body), but 
//   since Java 8, it can also have default and static methods with a body. 
//   A class that implements an interface must provide implementations 
//   for all the abstract methods of the interface.

// Key Points about Interfaces:
// An interface cannot have instance variables, only constants (final variables).
// A class can implement multiple interfaces (Java supports multiple inheritance through interfaces).
// Interfaces can only have abstract methods until Java 8. From Java 8 onwards, 
//   interfaces can also have default methods and static methods.

// Defining an interface
interface Animal {
    // Abstract method (does not have a body)
    void sound();

    // Default method (from Java 8)
    default void sleep() {
        System.out.println("This animal is sleeping.");
    }
}

// Class implements the Animal interface
class Dog implements Animal {
    // Providing implementation for the abstract method
    public void sound() {
        System.out.println("Dog barks");
    }
}

// Class implements the Animal interface
class Cat implements Animal {
    // Providing implementation for the abstract method
    public void sound() {
        System.out.println("Cat meows");
    }
}

public class InterfaceExample {
    public static void main(String[] args) {
        // Creating objects of classes that implement the interface
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        // Calling methods
        myDog.sound();   // Outputs: Dog barks
        myCat.sound();   // Outputs: Cat meows
        
        myDog.sleep();   // Outputs: This animal is sleeping.
        myCat.sleep();   // Outputs: This animal is sleeping.
    }
}
