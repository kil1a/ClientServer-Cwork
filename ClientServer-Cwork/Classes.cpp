#include "Classes.h"
#include <iostream>
#include <ws2tcpip.h> // �������� ������� ��� ������
// � �������� ����. inet_pton
#pragma comment(lib, "Ws2_32.lib") // ������� ����������

Server::Server()
{
	// ��������� ��� �������� ���������� � ������������� �������
	const int MAXSTRLEN = 255;
	WSADATA wsaData;
	sockaddr_in addr; // ��������� ����� � ����
	// ������������� �������
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	// ������� ��������� �����, �������� TCP
	socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// ��������� ������� IPv4
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip_addr_.c_str(), &addr.sin_addr);
	// ��������� ����.
	// ������� htons ��������� �������������� ����� �
	// ������� ������� ����, �.�. ����������� �������
	// �������� ������� �� �������� � ��������
	addr.sin_port = htons(8181);

	// ������ ����� � ���������� ������ � �����
	bind(socket_, (SOCKADDR*)&addr, sizeof(addr));
	// ��������� ����� � ������ ������������� ��������
	// �����������
	listen(socket_, 1);
	socketClient_ = accept(socket_, NULL, NULL);
}

Server::~Server()
{
	closesocket(socketClient_);
	closesocket(socket_);
	WSACleanup();
}

void Server::send_message(const std::string& message)
{
	send(socketClient_, message.c_str(), message.size(), 0);
}

std::string Server::recive_message()
{
	char buf[200];
	// �������� ��������� �� �������
	// ������� �������� �����������
	int i = recv(socketClient_, buf, 200, 0);

	return buf;
}

Client::Client() {
	// ��������� ��� �������� ���������� � ������������� �������
	const int MAXSTRLEN = 255;
	WSADATA wsaData;
	sockaddr_in addr; // ��������� ����� � ����
	// ������������� �������
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	// ������� ��������� �����, �������� TCP
	socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// ��������� ������� IPv4
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip_addr_.c_str(), &addr.sin_addr);
	// ��������� ����.
	// ������� htons ��������� �������������� ����� �
	// ������� ������� ����, �.�. ����������� �������
	// �������� ������� �� �������� � ��������
	addr.sin_port = htons(8181);
	connect(socket_, (SOCKADDR*)&addr, sizeof(addr));
}
Client::~Client() {
	closesocket(socket_);
	WSACleanup();
}

void Client::send_message(const std::string& message)
{
	send(socket_, message.c_str(), message.size(), 0);
}

std::string Client::recive_message()
{
	char buf[200];
	// �������� ��������� �� �������
	// ������� �������� �����������
	int i = recv(socket_, buf, 200, 0);

	return buf;
}
Game::Game() {}

void Game::turn()
{
	answer_2_gamer = std::stoi(server.recive_message());
	std::cout << "Enter your turn:";
	std::cin >> answer_1_gamer;

	if (answer_1_gamer > answer_2_gamer)
		std::cout << " first win\n";
	else
		std::cout << " second win\n";
}
