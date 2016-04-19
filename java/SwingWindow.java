import javax.swing.*;

// Replace SwingWindow 

public class SwingWindow {
    public static void main(String s[]){
        JFrame frame = new JFrame("Hello Swings");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Add the ubiquitous "Hello World" label.
        JLabel label = new JLabel("<html>Hello World.<br>A quick brown fox jumps over the lazy dog.<br>A quick brown fox jumps over the lazy dog.</html>");
        frame.getContentPane().add(label);
 
        //Display the window.
        //frame.pack();
	frame.setSize(500,500);
        frame.setVisible(true);
    }
}
