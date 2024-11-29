public class Person {
    // Member Variables
    private String name;
    private int age;

    // Method to set details
    public void setDetails(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to display details
    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

    public static void main(String[] args) {
        Person p = new Person(); // Create an object
        p.setDetails("John", 25); // Call method to set details
        p.displayDetails(); // Call method to display details
    }
}
