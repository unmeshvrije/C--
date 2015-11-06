//
import javax.swing.*;
import java.awt.GridLayout;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;


class CheckerBoardCell extends JButton implements MouseListener {
	public CheckerBoardCell(String label) {
		super.setText(label);
	}
	
	public void mousePressed(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	
	public void mouseClicked(MouseEvent me){
		if (me.getButton() == MouseEvent.BUTTON1) {
			super.setText("O");
			super.setEnabled(false);
		} else if (me.getButton() == MouseEvent.BUTTON3) {
			super.setText("X");
			super.setEnabled(false);
		}
	}
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	
}

public class CheckerBoard {
	public static void main(String s[]) {
		// Create object of class JFrame with label/title Hello Ween
		JFrame window = new JFrame("Tic Tac Toe !");
		
		// Default layout for the JFrame is BorderLayout with default position CENTER
		window.setLayout(new GridLayout(0,3));
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		/**
		* 0 1 2
		* 3 4 5
		* 6 7 8
		*/
		CheckerBoardCell buttons[] = new CheckerBoardCell[9];
		for (int i = 0; i < 9; ++i) {
			buttons[i] = new CheckerBoardCell("CHECK");
			buttons[i].addMouseListener(buttons[i]);
			window.getContentPane().add(buttons[i]);
		}
		window.pack();
		window.setVisible(true);
	}
}
