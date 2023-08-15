#include <iostream>
#include <unistd.h>
#include <cstring>

#include "machine.hpp"
#include "screen.hpp"
#include "jdc.hpp"

void spriteDel(sprite* s){
	for (int i=0; i<s->row; i++){
		delete s->data[i];
	}
	delete s->data;
}

void jack(Screen* s){
	strcpy(s->screen[5], "   J A C K P O T   ");
}

void manche(Screen* s, char in){
	strcpy(s->screen[5], "                   ");
	strcpy(s->screen[3], "| - - | - - | - - |");
	s->display();

	srand(time(0));

	char symbole[] = "OP@7AX";
	int symb_l = 6;

	// cheat &
	if (in == '&'){
		char c = symbole[(rand()%symb_l)];
		
		s->screen[3][3] = c;
		s->screen[3][9] = c;
		s->screen[3][15] = c;
		jack(s);

		s->display();
		return;
	}

	for (int i=0; i<15; i++){
		for (int y=0; y<(i%3)+1; y++){
			s->screen[3][3+6*y] = symbole[(rand()%symb_l)];
		}
		s->display();
		usleep(200000);
	}

	if (s->screen[3][3] == s->screen[3][9] && s->screen[3][9] == s->screen[3][15]) jack(s);
	else strcpy(s->screen[5], "     P E R D U     ");
	s->display();
};

void machine(){
	Screen sm(6, 19);

	sprite sp = {NULL, 3, 19};
	sp.data = new char*[sp.row];
	for (int i=0; i<sp.row; i++){
		sp.data[i] = new char[sp.col];
	}

	strcpy(sp.data[0], "+-----+-----+-----+");
	strcpy(sp.data[1], "| - - | - - | - - |");
	strcpy(sp.data[2], "+-----+-----+-----+");

	sprite t = {NULL, 2, 19};
	t.data = new char*[t.row];
	for (int i=0; i<t.row; i++){
		t.data[i] = new char[t.col];
	}

	strcpy(t.data[0], "Pour jouer : *     ");
	strcpy(t.data[1], "Pour quitter : q   ");

	sm.addSprite({0, 2}, sp);
	sm.addSprite({0, 0}, t);
	jack(&sm);
	sm.display();

	// game
	char input;
	std::cin >> input;
	while (input != 'q'){
		manche(&sm, input);
		std::cin >> input;
	}

	spriteDel(&sp);
	spriteDel(&t);
}
