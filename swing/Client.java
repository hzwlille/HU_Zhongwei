//
// Client Java pour communiquer avec le Serveur C++ 
// eric lecolinet - telecom paristech - 2015
//

import java.awt.event.InputMethodEvent;
import java.io.*;
import java.net.*;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Client
{
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;

  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  ///Créer un nouveau client sans démarrer la connexion
  public static Client makeClient(){
	  	Client client = null;
		String host = DEFAULT_HOST;
	    int port = DEFAULT_PORT;   
	    
	    //ConnexionWindows newConnexion=new ConnexionWindows();
	  
	    
	    try {
	    	client = new Client(host, port);
	    }
	    catch (Exception e) {
	    	String message = null;
	    	String message1=null;
	    	JFrame dialogue=new JFrame();
	    	//dialogue.addInputMethodListener(new InputMethodEvent(source, id, caret, visiblePosition));
	    	//JOptionPane.showInputDialog(dialogue, message,  "3");
	    	//JOptionPane.showInputDialog(dialogue, message1,  "33");
	    	JOptionPane.showMessageDialog(new JFrame(),"Client: Couldn't connect to "+host+":"+port);
	    	System.exit(1);
	    }
	    JOptionPane.showMessageDialog(new JFrame(),"Client connected to "+host+":"+port);
	    return client;
  }


  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
  /// recupere sa reponse et l'affiche sur le Terminal.
  /// Noter que le programme bloque si le serveur ne repond pas.
  ///
  public static void startClient(Client client) {

    // pour lire depuis la console
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    
    while (true) {
      System.out.print("Request: ");
      try {
        String request = cin.readLine();
        String response = client.send(request);
        System.out.println("Response: " + response);
      }
      catch (java.io.IOException e) {
        System.err.println("Client: IO error");
        return;
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ///
  /// Initialise la connexion.
  /// Renvoie une exception en cas d'erreur.
  ///
  public Client(String host, int port) throws UnknownHostException, IOException {
    try {
      sock = new java.net.Socket(host, port);
    }
    catch (java.net.UnknownHostException e) {
      System.err.println("Client: Couldn't find host "+host+":"+port);
      throw e;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't reach host "+host+":"+port);
      throw e;
    }
    
    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't open input or output streams");
      throw e;
    }
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  /// Envoie une requete au server et retourne sa reponse.
  /// Noter que la methode bloque si le serveur ne repond pas.
  ///
  public String send(String request) {
    // Envoyer la requete au serveur
    try {
      request += "\n";  // ajouter le separateur de lignes
      output.write(request, 0, request.length());
      output.flush();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't send message: " + e);
      return null;
    }
    
    // Recuperer le resultat envoye par le serveur
    try {
    	String newLine;
    	
    	String readOfLines="";
    	boolean stop=false;
    	while(!stop){
    		newLine=input.readLine();
    		readOfLines+=newLine+"\n";
    		if(newLine.equals("End_affiche")){
    			stop=true;
    		}
    	}
      return readOfLines;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't receive message: " + e);
      return null;
    }
  }
  
  public String boutonSend(String request){
	  //Envoyer la requete au serveur par clique des boutons
	  return this.send(request);
  }

}


