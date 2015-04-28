package com.lr.serveurdessin.serveur;

import java.io.IOException;
import java.net.Socket;
import java.util.NoSuchElementException;
import java.util.Scanner;
import com.lr.serveurdessin.shapedessin.CadreDessin;

/**
 * un thread pour traiter un socket client qui connecte
 * @author samuel
 *
 */
public class DessinSession implements Runnable {
	/** socket de ce client **/
	Socket s;
	/** l'identité de ce client **/
	int clientNo;
	
	/**
	 * constructeur
	 * @param s socket du client
	 * @param clientNo l'identité du client
	 */
	public DessinSession( Socket s, int clientNo ) {
		this.s = s;
		this.clientNo = clientNo;
	}

	@Override
	public void run() {
		Scanner scan = null;
		try {
			scan = new Scanner( s.getInputStream() );
			String shapeString = scan.nextLine().trim();
			System.out.println( "message reçu:" + shapeString );
			String[] params = shapeString.split( " " );
			
			CadreDessin cadreDessin = new CadreDessin( "Dessin de client " + this.clientNo, params );
			cadreDessin.setVisible( true );
		} catch ( NoSuchElementException e ) {
			System.out.println( "message reçu est vide" );
		} catch ( Exception e ) {
			e.printStackTrace();
		} finally {
			if ( s != null ) {
				try {
					s.close();
					s = null;
				} catch ( IOException e ) {
					e.printStackTrace();
				}
			}
			if ( scan != null ) {
				scan.close();
				scan = null;
			}
		}
	}
}
