// 1. Program for Multi-threading
// Multi-threading allows a program to perform multiple operations simultaneously. 
//   Java provides the Thread class and Runnable interface to implement multi-threading.

class MyThread extends Thread {
    // Overriding the run() method to define thread behavior
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getId() + " Value: " + i);
            try {
                Thread.sleep(500);  // Pause for 0.5 seconds
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class MultiThreadExample {
    public static void main(String[] args) {
        // Creating two threads
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();import javax.swing.*;
import java.awt.*;

public class SwingExample {

    public static void main(String[] args) {
        // Create a JFrame (Main Window)
        JFrame frame = new JFrame("Swing Application");
        
        // Set the layout manager (using BorderLayout)
        frame.setLayout(new BorderLayout());
        
        // Create components (buttons, labels, text field)
        JButton button = new JButton("Click Me");
        JLabel label = new JLabel("Enter your name:");
        JTextField textField = new JTextField(15);
        
        // Create a panel to hold the label and text field (using FlowLayout)
        JPanel panel = new JPanel(new FlowLayout());
        panel.add(label);
        panel.add(textField);
        
        // Add components to the frame (center: text field, south: button)
        frame.add(panel, BorderLayout.CENTER);
        frame.add(button, BorderLayout.SOUTH);
        
        // Action listener for button
        button.addActionListener(e -> {
            String name = textField.getText();
            JOptionPane.showMessageDialog(frame, "Hello, " + name + "!");
        });

        // Set frame properties
        frame.setSize(300, 200);  // Frame size (width x height)
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // Close on exit
        frame.setLocationRelativeTo(null);  // Center the frame
        frame.setVisible(true);  // Make the frame visible
    }
}

        
        // Starting both threads
        thread1.start();
        thread2.start();
    }
}


// 2. Program to Create a Frame, Use Layout Management, and UI Components in Swing
// Java Swing provides a rich set of GUI components to create applications. 
//   We can use different layout managers (like FlowLayout, BorderLayout, GridLayout, etc.) to arrange components.

