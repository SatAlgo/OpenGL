// 1. Single Inheritance
// In this type, a child class inherits from one parent class.

class Animal {
    void eat() {
        System.out.println("This animal eats food");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("The dog barks");
    }
}

public class SingleInheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat();  // Inherited from Animal class
        dog.bark(); // Defined in Dog class
    }
}


// 2. Multilevel Inheritance
// In this type, a class inherits from another derived class, forming a chain of inheritance.

class Animal {
    void eat() {
        System.out.println("This animal eats food");
    }
}

class Mammal extends Animal {
    void walk() {
        System.out.println("Mammals can walk");
    }
}

class Dog extends Mammal {
    void bark() {
        System.out.println("The dog barks");
    }
}

public class MultilevelInheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat();   // Inherited from Animal
        dog.walk();  // Inherited from Mammal
        dog.bark();  // Defined in Dog
    }
}


// 3. Hierarchical Inheritance
// In this type, multiple child classes inherit from a single parent class.

class Animal {
    void eat() {
        System.out.println("This animal eats food");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("The dog barks");
    }
}

class Cat extends Animal {
    void meow() {
        System.out.println("The cat meows");
    }
}

public class HierarchicalInheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat();  // Inherited from Animal
        dog.bark();

        Cat cat = new Cat();
        cat.eat();  // Inherited from Animal
        cat.meow();
    }
}

// 4. Hybrid Inheritance (Using Interfaces)
// Java doesn’t support multiple inheritance with classes to avoid ambiguity caused by the diamond problem. 
//   However, it can be achieved using interfaces.

interface Vehicle {
    void start();
}

class Car {
    void fuel() {
        System.out.println("The car uses fuel");
    }
}

class SportsCar extends Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("SportsCar starts with high speed");
    }
}

public class HybridInheritance {
    public static void main(String[] args) {
        SportsCar sc = new SportsCar();
        sc.fuel();  // From Car class
        sc.start(); // From Vehicle interface
    }
}

