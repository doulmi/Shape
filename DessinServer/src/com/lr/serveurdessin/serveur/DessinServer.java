package com.lr.serveurdessin.serveur;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * le server pour dessiner
 * @author samuel
 *
 */
public class DessinServer {
	/** serveur socket **/
	ServerSocket ss = null;

	/** le somme de count **/
	int clientCount = 0;
	
	/** le port de ce serveur **/
	int port = 8189;
	
	/** 
	 * démarrer ce serveur
	 */
	public void start() {
		try {
			ss = new ServerSocket( port );
			System.out.println( "Dessin Serveur start, the port is " + port );
			
			while ( true ) {
				Socket coming = ss.accept();
				System.out.println( "a client connect" );

				Runnable r = new DessinSession( coming, clientCount );
				Thread t = new Thread( r );
				t.start();
				clientCount ++;
			}
		} catch ( IOException e ) {
			e.printStackTrace();
		} finally {
			if ( ss != null ) {
				try {
					ss.close();
				} catch ( IOException e ) {
					e.printStackTrace();
				}
				ss = null;
			}
		}
	}
}
