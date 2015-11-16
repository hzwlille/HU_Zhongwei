import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class main {

	/**
	 * @param args
	 */

	class Ecoute implements ActionListener 
	{ 
		public void actionPerformed(ActionEvent e) { 
			System.out.println("Done!"); 
			this.notify(); // ne compile pas ! 
		} 
	} 
	public static void main(String[] args) {

		Client client = null;
		client=Client.makeClient();
		Fenetre a=new Fenetre(client);
		a.setVisible(true);
		a.setMinimumSize(a.getSize());
		Client.startClient(client);	


	}

}
