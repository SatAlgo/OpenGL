// Parent class
class Shape {
    void draw() {
        System.out.println("Drawing a shape");
    }
}

// Subclass Circle
class Circle extends Shape {
    void draw() {
        System.out.println("Drawing a Circle");
    }
}

// Subclass Rectangle
class Rectangle extends Shape {
    void draw() {
        System.out.println("Drawing a Rectangle");
    }
}

// Subclass Square
class Square extends Shape {
    void draw() {
        System.out.println("Drawing a Square");
    }
}

// Program to demonstrate polymorphism
public class PolymorphismExample {
    public static void main(String[] args) {
        // Creating objects of subclasses
        Shape shape1 = new Circle();  // Upcasting
        Shape shape2 = new Rectangle();  // Upcasting
        Shape shape3 = new Square();  // Upcasting

        // Calling overridden methods
        shape1.draw();  // Outputs: Drawing a Circle
        shape2.draw();  // Outputs: Drawing a Rectangle
        shape3.draw();  // Outputs: Drawing a Square

        // Demonstrating method overloading
        Shape shape4 = new Shape();
        shape4.draw();  // Outputs: Drawing a shape
    }
}
