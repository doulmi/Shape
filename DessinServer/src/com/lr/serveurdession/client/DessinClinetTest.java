package com.lr.serveurdession.client;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * un simple test client de dessiner
 * @author samuel
 *
 */
public class DessinClinetTest {
	public static void main( String[] args ) {
		Socket s = null;
		try {
			s = new Socket( "localhost", 8189 );
			OutputStream os = s.getOutputStream();
			PrintWriter writer = new PrintWriter( os );
			String segmentSample = "0 120.0 120.3 230.2 120.1 3";
			String cercleSample = "1 120 120 100 2";
			String polygonSample = "2 3 123 120 30 12 400 120 1";
			String groupSample = "3 2 0 120 120 230 120 3 1 120 120 100 2";
			String grandGroupSample = "3 3 0 120 120 230 120 3 1 120 120 100 2 2 3 123 120 30 12 400 120 1";
			String doubleGroupSample = "3 2 3 3 0 120 120 230 120 3 1 120 120 100 2 2 3 123 120 30 12 400 120 1 1 240 240 100 4";
			
//			writer.println( segmentSample );
//			writer.println( cercleSample );
//			writer.println( polygonSample );
//			writer.println( groupSample );
			writer.println( doubleGroupSample );
			writer.flush();
		} catch ( UnknownHostException e ) {
			e.printStackTrace();
		} catch ( IOException e ) {
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
		}
		
	}
}
