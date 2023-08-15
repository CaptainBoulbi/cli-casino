#include <iostream>
#include <unistd.h>
#include <cstring>

#include "course.hpp"
#include "screen.hpp"
#include "jdc.hpp"
#include "carte.hpp"

carte tirer(JDC* j){
	carte c = j->pop();
	if (c.valeur == A) return tirer(j);
	return c;
}

static void spriteDel(sprite* s){
	for (int i=0; i<s->row; i++){
		delete s->data[i];
	}
	delete s->data;
}

bool victoire(Screen* s, char* c){
	char ligne[34] = "    VICTOIRE ";
	strcat(ligne, c);
	strcpy(s->screen[s->ligne()-1], ligne);
	return true;
}

void course(){
	int HCASE = 4;

	Screen sc(24, 34);

	strcpy(sc.screen[0], "Appuyer sur * pour tirer une carte");
	strcpy(sc.screen[1], "Appuyer sur q pour quitter        ");
	strcpy(sc.screen[2], "                                  ");
	strcpy(sc.screen[sc.ligne()-1], "                                  ");
	strcpy(sc.screen[sc.ligne()-2], "                                  ");

	for (int i=0; i<4; i++){
		strcpy(sc.screen[3+i*4], "    |    |    |    |              ");
		strcpy(sc.screen[4+i*4], "    |    |    |    |              ");
		strcpy(sc.screen[5+i*4], "    |    |    |    |              ");
		strcpy(sc.screen[6+i*4], "----+----+----+----+----          ");
	}
	strcpy(sc.screen[19], "    |    |    |    |              ");
	strcpy(sc.screen[20], "    |    |    |    |              ");
	strcpy(sc.screen[21], "    |    |    |    |              ");

	constexpr point<int> Ppal1 = {20, 3};
	constexpr point<int> Ppal2 = {20, 7};
	constexpr point<int> Ppal3 = {20, 11};
	constexpr point<int> Ppal4 = {20, 15};
	sc.addCard(Ppal1, CARTERETOURNE);
	sc.addCard(Ppal2, CARTERETOURNE);
	sc.addCard(Ppal3, CARTERETOURNE);
	sc.addCard(Ppal4, CARTERETOURNE);

	point<int> Ppioche = {29, 19};
	sc.addCard(Ppioche, CARTERETOURNE);

	point<int> Ppic = {0, 19};
	point<int> Pcoeur = {5, 19};
	point<int> Pcarreau = {10, 19};
	point<int> Ptrefle = {15, 19};
	sc.addCard(Ppic, {A, PIC});
	sc.addCard(Pcoeur, {A, COEUR});
	sc.addCard(Pcarreau, {A, CARREAU});
	sc.addCard(Ptrefle, {A, TREFLE});

	sprite bar = {NULL, 3, 4};
	bar.data = new char*[bar.row];
	for (int i=0; i<bar.row; i++){
		bar.data[i] = new char[bar.col];
	}

	strcpy(bar.data[0], "\\   ");
	strcpy(bar.data[1], " \\  ");
	strcpy(bar.data[2], "  \\ ");

	sc.addSprite({20, 19}, bar);

	sc.display();

	sprite vide = {NULL, 3, 4};
	vide.data = new char*[vide.row];
	for (int i=0; i<vide.row; i++){
		vide.data[i] = new char[vide.col];
	}

	strcpy(vide.data[0], "    ");
	strcpy(vide.data[1], "    ");
	strcpy(vide.data[2], "    ");

	JDC j;
	j.init();
	j.shuffle();

	bool vic = false;
	char input;
	std::cin >> input;
	int palier = 15;
	while (input != 'q' && !vic){
		carte c = tirer(&j);
		sc.addCard(Ppioche, c);

		switch (c.couleur){
			case PIC:
				if (Ppic.x <= 3){
					vic = victoire(&sc, "PIC");
				}else{
					sc.addSprite(Ppic, bar);
					Ppic.x -= HCASE;
					sc.addCard(Ppic, {A, PIC});
				}
				break;
			case COEUR:
				if (Pcoeur.x <= 3){
					vic = victoire(&sc, "COEUR");
				}else{
					sc.addSprite(Pcoeur, bar);
					Pcoeur.x -= HCASE;
					sc.addCard(Pcoeur, {A, COEUR});
				}
				break;
			case CARREAU:
				if (Pcarreau.x <= 3){
					vic = victoire(&sc, "CARREAU");
				}else{
					sc.addSprite(Pcarreau, bar);
					Pcarreau.x -= HCASE;
					sc.addCard(Pcarreau, {A, CARREAU});
				}
				break;
			case TREFLE:
				if (Ptrefle.x <= 3){
					vic = victoire(&sc, "TREFLE");
				}else{
					sc.addSprite(Ptrefle, bar);
					Ptrefle.x -= HCASE;
					sc.addCard(Ptrefle, {A, TREFLE});
				}
				break;
		}

		if (Ppic.x <= palier && Pcoeur.x <= palier && Pcarreau.x <= palier && Ptrefle.x <= palier){
			carte p = tirer(&j);
			switch (p.couleur){
				case PIC:
					sc.addSprite(Ppic, vide);
					Ppic.x += HCASE;
					sc.addCard(Ppic, {A, PIC});
					break;
				case COEUR:
					sc.addSprite(Pcoeur, vide);
					Pcoeur.x += HCASE;
					sc.addCard(Pcoeur, {A, COEUR});
					break;
				case CARREAU:
					sc.addSprite(Pcarreau, vide);
					Pcarreau.x += HCASE;
					sc.addCard(Pcarreau, {A, CARREAU});
					break;
				case TREFLE:
					sc.addSprite(Ptrefle, vide);
					Ptrefle.x += HCASE;
					sc.addCard(Ptrefle, {A, TREFLE});
					break;
			}

			switch(palier){
				case Ppal1.x:
					sc.addCard(Ppal1, p);
					break;
				case Ppal2.x:
					sc.addCard(Ppal2, p);
					break;
				case Ppal3.x:
					sc.addCard(Ppal3, p);
					break;
				case Ppal4.x:
					sc.addCard(Ppal4, p);
					break;
			}

			palier -= HCASE;
		}

		sc.display();
		//manche(&sc, &j);
		std::cin >> input;
	}

	spriteDel(&bar);
	spriteDel(&vide);
}

//Appuyer sur * pour tirer une carte
//Appuyer sur q pour quitter
//
//+--+|    |    |    |+--+
//|AP||    |    |    ||??|
//+--+|    |    |    |+--+
//----+----+----+----+----
//    |+--+|    |+--+|+--+
//    ||AC||    ||AT|||??|
//    |+--+|    |+--+|+--+
//----+----+----+----+----
//    |    |+--+|    |+--+
//    |    ||AK||    ||TT|
//    |    |+--+|    |+--+
//----+----+----+----+----
//    |    |    |    |+--+      +--+
//    |    |    |    ||TT|      |??|
//    |    |    |    |+--+      +--+
//----+----+----+----+----
//    |    |    |    |
//    |    |    |    |
//    |    |    |    |
//    VICTOIRE CARREAU
// 4 esp

// 17 34
