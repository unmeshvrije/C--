//
import javax.swing.*;
import java.awt.GridLayout;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import javax.swing.JOptionPane;


class CheckerBoardCell extends JButton implements MouseListener {
	CheckerBoard myBoard;
	
	public void setBoard(CheckerBoard board) {
		myBoard = board;
	}
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
		myBoard.checkResult();
	}
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
}

class CheckerBoard{
	
	CheckerBoardCell []grid;
	public CheckerBoard() {
		grid = new CheckerBoardCell[9];
		for (int i = 0; i < 9; ++i) {
			grid[i] = new CheckerBoardCell("CHECK");
		}
	}
	
	CheckerBoardCell[] getGrid() {
		return grid;
	}
	
	public void checkResult() {
		
		System.out.println();
		System.out.println("===================");
		for (int i = 0; i < 9; ++i) {
			
			if ((i%3) == 0) {
				System.out.println();
			}
			String str = grid[i].getText();
			if (str.equals("O") || str.equals("X")) {
				System.out.print(str + " ");
			} else {
				System.out.print("- ");
			}
		}
		
		if (
		grid[0].getText().equals(grid[1].getText()) &&
		grid[1].getText().equals(grid[2].getText()) &&
		!grid[0].getText().equals("CHECK")
		) {
			JOptionPane.showMessageDialog(null, grid[0].getText() + " won!");
		}
	}
}

public class TicTacToe {
	public static void main(String s[]) {
		JFrame window = new JFrame("Tic Tac Toe !");
		
		// Default layout for the JFrame is BorderLayout with default position CENTER
		window.setLayout(new GridLayout(3,3));
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		/**
		* 0 1 2
		* 3 4 5
		* 6 7 8
		*/
		CheckerBoard board = new CheckerBoard();
		CheckerBoardCell [] grid = board.getGrid();
		for (int i = 0; i < 9; ++i) {
			grid[i].setBoard(board);
			grid[i].addMouseListener(grid[i]);
			window.getContentPane().add(grid[i]);
		}
		window.pack();
		window.setVisible(true);
	}
}
