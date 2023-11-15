#include <string>
#include "WinSock2.h"
class Server {
	unsigned int socket;
	unsigned int socketClient;
	std::string ip_addr = "127.0.0.1";
public:
	Server();
	~Server();
	void send_message(const std::string& message);
	std::string recive_message();



};
class Client {
public:
	Client();
	~Client();
	void send_message(const std::string& message);
	std::string recive_message();
};