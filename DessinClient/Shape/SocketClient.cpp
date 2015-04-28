#include "SocketClient.h"

SocketClient* SocketClient::getInstance() {
	static SocketClient client;
	return &client;
}

void SocketClient::sendDessinData( const string& dessinData ) {
	int r;
	WSADATA wsaData;
	SOCKET sock;

	// MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2
	/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */
	r = WSAStartup( MAKEWORD(2,0), &wsaData );

	if ( r ) {
		cout << "WSAStartup echoué" << endl;
		exit( 0 );
	}

	cout << "client vers le serveur de dessiner" << endl;
	cout << "initialisation effectuee"<<endl;

	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi 
	// mettre 0 et la fct choisit le
	// protocole en fct des 2 1ers paramètres

	// pour les valeurs des paramètres : 
	// cf. fct socket dans la doc sur winsock
	sock = socket( familleAdresses, typeSocket, protocole);

	//------------------------------ création du représentant du serveur ----------------------------------------
	if ( ! sameServer ) {
		cout <<"tapez l'adresse IP du serveur de dessiner : " << endl;
		cin >> adress;

		cout <<"tapez le port du serveur du serveur de dessiner: " << endl;
		cin >> port;
		sameServer = true;
	}

	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adress.c_str());   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(port);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

	//------------------------------ connexion du client au serveur ---------------------------------------
	r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
	// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r == SOCKET_ERROR) {
		cout << "connetct echoue" << endl;
		closesocket( sock ); //ferme le socket
		WSACleanup();       //clean up le socket data;
		exit( 0 );
	}
	cout << "connexion au serveur de dessin réussie" << endl;

	bool continuer = true;
	do {
		string s(dessinData + "\r\n");
		if ( continuer ) {
			int size = s.size();
			//------------------ envoi de la requête au serveur -------------------------------
			// envoie au plus size octets
			r = send( sock, s.c_str(), size, 0 );

			if (r == SOCKET_ERROR) {
				cout << "echoue d'envoyer le message" << endl;
				closesocket( sock );
				WSACleanup();
				break;
			}
		}
	} while ( continuer );

	r = shutdown(sock, SD_BOTH);	// on coupe la connexion pour l'envoi et la réception
	// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	r = closesocket( sock );     // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	//if ( r ) throw Erreur("La fermeture du socket a échoué");

	WSACleanup();
	cout << "arrêt normal du client" << endl;
}