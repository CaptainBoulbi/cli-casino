#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <cstdlib>
#include "jdc.hpp"

template <typename T>
struct point{
	T x;
	T y;
};

struct sprite{
	std::string* s;
	int row;
	int col;
};

class Screen{
	public:
		std::string** screen;

		Screen(int col, int row){
			this->col = col;
			this->row = row;

			this->screen = new std::string*;
			for (int i=0; i<row; i++){
				this->screen[i] = new std::string;
			}
		};

		~Screen(){
			for (int i=0; i<row; i++){
				delete this->screen[i];
			}
			delete this->screen;
		};

		void background(){
			for (int i=0; i<row; i++){
				this->screen[i] = new std::string;
				for (int y=0; y<col; y++){
					if (y%2 && i%2) *(this->screen[i]) += "X";
					else if (!(i%2) && !(y%2)) *(this->screen[i]) += "X";
					else *(this->screen[i]) += "O";
				}
			}
		};

		void display(){
			std::cout << "\033[1;48;5;22m" << std::endl;
			for (int i=0; i<row; i++){
				std::cout << *(this->screen[i]) << std::endl;
			}
			std::cout << "\033[0m" << std::endl;
		}

		void addCard(point<int> p, carte c){
			this->screen[p.x]->replace(p.y, 4, "╭──╮");
			this->screen[p.x+1]->replace(p.y+1, 1, JDC::valeur(c));
			this->screen[p.x+1]->replace(p.y, 1, "│");
			this->screen[p.x+1]->replace(p.y+5, 1, "│");
			this->screen[p.x+1]->replace(p.y+4, 1, JDC::couleur(c));
			this->screen[p.x+2]->replace(p.y, 4, "╰──╯");
		};

		int ligne(){
			return this->row;
		}

		int colone(){
			return this->col;
		}
	private:
		int row;
		int col;
};

#endif
