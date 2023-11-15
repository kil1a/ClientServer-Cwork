#include "Classes.h"
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
	listen(socket_, 2);
}

Server::~Server()
{
	closesocket(socketClient_);
	closesocket(socket_)
}
