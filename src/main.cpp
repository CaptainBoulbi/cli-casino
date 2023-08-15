#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <unistd.h>
#include <cstring>

#include "screen.hpp"
#include "jdc.hpp"
#include "machine.hpp"

void menu(){
	static Screen s(7, 18);
	
	sprite sp = {NULL, 7, 18};
	sp.data = new char*[sp.row];
	for (int i=0; i<sp.row; i++){
		sp.data[i] = new char[sp.col];
	}

	strcpy(sp.data[0], "Choisisez un jeu :");
 	strcpy(sp.data[1], "                  ");
 	strcpy(sp.data[2], "1 - Blackjack     ");
 	strcpy(sp.data[3], "2 - Roulette      ");
 	strcpy(sp.data[4], "3 - Machine a sous");
 	strcpy(sp.data[5], "4 - Course d'as   ");
 	strcpy(sp.data[6], "q - Quitter       ");

	s.addSprite({0, 0}, sp);
	s.display();
}

void selectGame(){
	char input;
	std::cin >> input;

	switch (input){
		case '1':
			//blackjack();
			std::cout << "blackjack" << std::endl;
			break;
		case '2':
			//roulette();
			std::cout << "roulette" << std::endl;
			break;
		case '3':
			machine();
			break;
		case '4':
			//course();
			std::cout << "course" << std::endl;
			break;
	}
	if (input != 'q'){
		menu();
		selectGame();
	}
}

void setup(){
	#ifndef _WIN32
	// echo off
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);

	// canon off
	struct termios term2;
	tcgetattr(1, &term2);
	term2.c_lflag &= ~ICANON;
	tcsetattr(1, TCSANOW, &term2);

	#else

	// active couleur sur windows
	DWORD outMode = 0;
	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if(stdoutHandle == INVALID_HANDLE_VALUE){
		exit(GetLastError());
	}
	if(!GetConsoleMode(stdoutHandle, &outMode)){
		exit(GetLastError());
	}
	outModeInit = outMode;
	
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if(!SetConsoleMode(stdoutHandle, outMode)){
		exit(GetLastError());
	}

	#endif
}

void tearDown(){
	std::cout << "\033[0m \033[?25h \033[?1049l\033[?1049l\033[?1049l" << std::endl;
	puts("\033[2J");
	puts("\033[0;0H");

	#ifndef _WIN32
	// echo on
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);

	// canon on
	struct termios term2;
	tcgetattr(1, &term2);
	term2.c_lflag |= ICANON;
	tcsetattr(1, TCSANOW, &term2);

	#else

	// restore la console sur windows
	if(!SetConsoleMode(stdoutHandle, outModeInit)){
		exit(GetLastError());
	}
	#endif
}

int main(){

	setup();
	menu();
	selectGame();
	tearDown();

	return 0;
}
