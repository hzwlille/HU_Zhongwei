import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class ConnexionWindows extends JFrame{
	private static final long serialVersionUID = 1L;
	
	public ConnexionWindows(){
		super();
		this.setSize(300, 100);
		JPanel panelWindows=new JPanel();
		JTextField myHost=new JTextField();
		panelWindows.add(myHost);
		this.add(panelWindows);
		this.setVisible(true);
	}
	
//	public static connexion(){
//		
//	}

}
