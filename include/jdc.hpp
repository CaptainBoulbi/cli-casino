#ifndef JDC_HPP
#define JDC_HPP

#include <iostream>
#include <cstdlib>
#include "carte.hpp"

class JDC{
	public:
		JDC(){
			this->len = 0;
		};

		void init(){
			this->len = 52;
			int index = 0;
			for (int i=0; i<4; i++){
				for (int y=0; y<13; y++){
					index = (i*13)+y;
					this->jdc[index].couleur = (CCarte)i;
					this->jdc[index].valeur = (VCarte)(y+2);
				}
			}
		}

		void shuffle(){
			srand(time(0));
			for (int i=0; i<52; i++){
				int randomIndex = rand()%52;
				carte swap = this->jdc[randomIndex];

				this->jdc[randomIndex] = this->jdc[i];
				this->jdc[i] = swap;
			}
		};

		void display(){
			for (int i=0; i<this->len; i++){
				if (!(i%13)) std::cout << std::endl;
				std::cout << i << ':' << this->jdc[i].valeur << '+' << this->jdc[i].couleur << '\t';
			}
			std::cout << std::endl;
		};

		carte top(){
			if (this->len <= 0) throw "jdc empty";
			return this->jdc[this->len-1];
		}

		carte pop(){
			if (this->len <= 0) throw "jdc empty";
			this->len--;
			return this->jdc[this->len];
		}

		carte push(carte c){
			if (this->len == 52) throw "jdc full";
			this->jdc[this->len] = c;
			this->len++;
			return c;
		}

		carte get(int index){
			if (index < 0 || index > this->len) throw "jdc out of bound";
			return this->jdc[index];
		}

		std::string valeur(carte c){
			if ((int)c.valeur < 10) return std::to_string(c.valeur);
			switch(c.valeur){
				case T:
					return "T";
				case J:
					return "J";
				case Q:
					return "Q";
				case K:
					return "K";
				case A:
					return "A";
				default:
					return "?";
			}
		}

		std::string couleur(carte c){
			switch(c.couleur){
				case PIC:
					return "♠";
				case COEUR:
					return "♥";
				case TREFLE:
					return "♣";
				case CARREAU:
					return "♦";
				default:
					return "?";
			}
		};

		std::string* ascii(carte c){
			std::string* s = new std::string[3];
			std::string co = this->couleur(c);
			s[0] = "\033[38;5;235m╭──╮";
			if (co == "♥" || co == "♦") s[1] = "│\033[31m"+this->valeur(c)+co+"\033[38;5;235m│";
			else s[1] = "│\033[30m"+this->valeur(c)+co+"\033[38;5;235m│";
			s[2] = "╰──╯";
			return s;
		};

		int length(){
			return this->len;
		}

	private:
		carte jdc[52];
		int len;
};

#endif
