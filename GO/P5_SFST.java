class Animal {
    final String species = "Mammal"; // Final variable

    Animal() {
        System.out.println("Animal constructor called");
    }

    void sound() {
        System.out.println("Animals make sounds");
    }
}

class Dog extends Animal {
    final String breed = "Labrador"; // Final variable

    Dog() {
        super();  // Calling the parent class constructor
        System.out.println("Dog constructor called");
    }

    void sound() {
        super.sound();  // Calling the parent class method
        System.out.println("Dog barks");
    }

    void display() {
        System.out.println("Breed: " + breed);
        System.out.println("Species: " + species); // Accessing final variable from parent
    }

    static void staticMethod() {
        System.out.println("Static method in Dog class");
    }
}

public class KeywordsExample {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound();
        dog.display();

        // Static method call without object
        Dog.staticMethod();
    }
}
