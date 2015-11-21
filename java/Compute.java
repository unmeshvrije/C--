/*
This program is aimed to teach a simple calculator program in Java.
Given:
Two labels to enter numbers. Two text fields to accept numbers
One button for operation. One text field for the output/result.

Assignment:
1. Modify the code such that the answer appears in the result text box
2. Add a different operation. Like subtraction, multiplication, division etc.
2.1 Add more buttons and text fields. Hint: you need to change the grid layout
*/

import javax.swing.*;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Calculator implements ActionListener{
	JLabel enterNumber1;
	JTextField number1;
	
	JLabel enterNumber2;
	JTextField number2; 
	
	JButton operation;
	JTextField result;
	
	public void actionPerformed(ActionEvent ae) {
		int num1 = Integer.parseInt(number1.getText());
		int num2 = Integer.parseInt(number2.getText());
		
		operation.setText(Integer.toString(num1 + num2));
	}
	
	public JLabel getLabel1() {return enterNumber1;}
	public JLabel getLabel2() {return enterNumber2;}
	public JTextField getTextField1() {return number1;}
	public JTextField getTextField2() {return number2;}
	public JTextField getTextField3() {return result;}
	public JButton getButton() {return operation;}
	
	public Calculator(){
		enterNumber1 = new JLabel("Enter 1st number :");
		number1 = new JTextField();
		enterNumber2 = new JLabel("Enter 2nd number :");
		number2 = new JTextField();
		operation = new JButton("+");
		result = new JTextField();
	}

}

public class Compute {
	public static void main(String s[]) {
		JFrame window = new JFrame("Simple Calculator");
		
		// Default layout for the JFrame is BorderLayout with default position CENTER
		window.setLayout(new GridLayout(3,2));
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		
		Calculator myCalculator = new Calculator();
		
		JLabel enterNumber1 = myCalculator.getLabel1();
		JTextField number1 = myCalculator.getTextField1();
		JLabel enterNumber2 = myCalculator.getLabel2();
		JTextField number2 = myCalculator.getTextField2();
		JButton operation = myCalculator.getButton();
		JTextField result = myCalculator.getTextField3();
		
		operation.addActionListener(myCalculator);
		
	    window.add(enterNumber1);
	    window.add(number1);
	    window.add(enterNumber2);
	    window.add(number2);
	    window.add(operation);
	    window.add(result);
		
		window.pack();
		window.setVisible(true);
	}
}
