#pragma once
#include <string>
#include "WinSock2.h" // здесь наход€тс€ объ€влени€, необходимые дл€ Winsock 2 API.
class Server {
	unsigned int socket_;
	unsigned int socketClient_;
	std::string ip_addr_ = "127.0.0.1";
public:
	Server();
	~Server();
	/// <summary>
	///  @brief отправить сообщение
	/// </summary>
	void send_message(const std::string& message);
	/// <summary>
	///  @brief получить сообщение
	/// </summary>
	std::string recive_message();
};

class Client {
	unsigned int socket_;
	std::string ip_addr_ = "127.0.0.1";
public:
	Client();
	~Client();
	/// <summary>
	///  @brief отправить сообщение
	/// </summary>
	void send_message(const std::string& message);
	/// <summary>
	///  @brief получить сообщение
	/// </summary>
	std::string recive_message();
};
//MVC

class Game {
	unsigned short answer_1_gamer = 0;
	unsigned short answer_2_gamer = 0;
	Server server;
public:
	Game();
	//void start();
	void turn();
	//void end();
};

