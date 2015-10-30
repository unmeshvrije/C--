import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SimpleCheckerBox {
    public static void main(String s[]){
        JFrame frame = new JFrame("Hello Swings");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	Container pane = frame.getContentPane();
	JPanel checker = new JPanel(new GridLayout(3,3));
	JButton button []= new JButton[9];
	for (int i = 0; i < 9; ++i) {
	    button[i] = new JButton("Click Me");
	    button[i].addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent me) {
		    button[i].setText("Clicked");
		}
	    });
            checker.add(button[i]);
	}

	pane.add(checker);
 
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }
}
