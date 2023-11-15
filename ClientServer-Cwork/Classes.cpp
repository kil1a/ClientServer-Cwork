#include "Classes.h"
#include <ws2tcpip.h> // содержит функции для работы
// с адресами напр. inet_pton
#pragma comment(lib, "Ws2_32.lib") // линкуем библиотеку

Server::Server()
{
	// структура для хранения информации о инициализации сокетов
	const int MAXSTRLEN = 255;
	WSADATA wsaData;
	sockaddr_in addr; // локальный адрес и порт
	// инициализация сокетов
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	// создаем потоковый сокет, протокол TCP
	socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// Семейство адресов IPv4
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip_addr_.c_str(), &addr.sin_addr);
	// Указываем порт.
	// Функиця htons выполняет преобразование числа в
	// сетевой порядок байт, т.к. стандартным сетевым
	// является порядок от старшего к младшему
	addr.sin_port = htons(8181);

	// биндим сокет к указанному адресу и порту
	bind(socket_, (SOCKADDR*)&addr, sizeof(addr));
	// открываем сокет в режиме прослушивания входящих
	// подключений
	listen(socket_, 2);
}

Server::~Server()
{
	closesocket(socketClient_);
	closesocket(socket_)
}
