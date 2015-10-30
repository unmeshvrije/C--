import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import vegetables.Pumpkin;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class CarvingTable extends JPanel implements MouseListener {
    @Override
    public void paintComponent(Graphics g) {
	super.paintComponent(g);
	Point pos = new Point(250,250);
	int width = 200;
	int height = 150;
	int closeness = 15;
	int stemHeight = 28;
	int stemWidth = 12;
	Color stemColor = new Color(0, 102, 0);;

	int ex, ey;

	ex=(int)pos.getX()-width/2;
	ey=(int)pos.getY()-height/2;
	g.setColor(Color.orange);
	g.fillOval(ex,ey,width, height);
	g.fillOval(ex+closeness,ey, width, height);


	ex=(int)pos.getX()+ stemWidth;
	ey=(int)pos.getY()-height/2-stemHeight;
	g.setColor(stemColor);
	g.fillRect(ex,ey,stemWidth, stemHeight);
    }

    public void mousePressed(MouseEvent me) {
	int x = me.getX();
	int y = me.getY();
	Graphics g = this.getGraphics();
	g.fillRect(x, y, 10, 10);
    }

    public void mouseClicked(MouseEvent me) {}
    public void mouseReleased(MouseEvent me) {}
    public void mouseEntered(MouseEvent me) {}
    public void mouseExited(MouseEvent me) {}
}

public class PumpkinCarving {
    public static void main(String s[]){
        JFrame window = new JFrame("Hello Swings");
	window.setSize(500,500);
	window.getContentPane().setBackground(new Color(255, 0, 0));
	window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        CarvingTable myTable = new CarvingTable();
	myTable.addMouseListener(myTable);
        window.add(myTable);
        window.setVisible(true);
    }
}
