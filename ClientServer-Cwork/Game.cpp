#include <iostream>
#include <string>
#include "Classes.h"
#pragma comment(lib, "Ws2_32.lib") // линкуем библиотеку
// Windows Sockets
using namespace std;

int main() {
#ifdef SERVER
	Game first_player;
	first_player.turn();
#else
	Client second_player;
	int answer;
	std::cout << "Enter your turn:";
	std::cin >> answer;
	second_player.send_message(std::to_string(answer));
#endif
}