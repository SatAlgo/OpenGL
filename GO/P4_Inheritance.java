interface Engine {
    void power();
}

class Vehicle {
    void fuel() {
        System.out.println("Vehicles use fuel");
    }
}

class Car extends Vehicle {
    void type() {
        System.out.println("This is a car");
    }
}

class SportsCar extends Car implements Engine {
    @Override
    public void power() {
        System.out.println("Sports cars have powerful engines");
    }
}

class Bike extends Vehicle {
    void speed() {
        System.out.println("Bikes are fast");
    }
}

public class AllInheritanceTypes {
    public static void main(String[] args) {
        // Single Inheritance
        Car car = new Car();
        car.fuel();
        car.type();

        // Multilevel Inheritance
        SportsCar sportsCar = new SportsCar();
        sportsCar.fuel();
        sportsCar.type();
        sportsCar.power();

        // Hierarchical Inheritance
        Bike bike = new Bike();
        bike.fuel();
        bike.speed();
    }
}
