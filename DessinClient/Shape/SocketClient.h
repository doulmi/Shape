#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <WinSock2.h>
#include <sstream>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib") 

using namespace std;

/** 
@brief le SocketClient pour envoyer les dates au serveur en utilisant TCP/IP protocol, c'est un singleton
 */
class SocketClient {
private:
	/** si ce socketClient envoye toujours les data au meme serveur */
	bool sameServer;

	/** si sameServer est vrai, c'est l'adresse du serveur */
	string adress;

	/** si sameServer est vrai, c'est le port du serveur */
	short port;

	//comme singleton, le constructeur est privé
	SocketClient() : sameServer( false ), port( 0 ) {}

	//comme singleton, le constructueur de recopie est privé
	SocketClient( const SocketClient& client );

	//comme singleton, l'opérateur d’affectation est privé
	SocketClient& operator=( const SocketClient& client );
public:

	/**
	 @brief envoyer un message au serveur 
	 @param le data à envoyer
	 */
	void sendDessinData( const string& dessinData );

	/**
	 * @return instance de SocketClinet
	 */
	static SocketClient* getInstance();
	~SocketClient() {}
};
#endif //__CLIENT_H__