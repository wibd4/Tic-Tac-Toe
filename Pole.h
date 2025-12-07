#pragma once
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Pole
{
	char pole[3][3];
	bool busy[3][3];
public:
	Pole() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				pole[i][j] = '#';
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				busy[i][j] = false;
			}
		}
	}

	void print()
	{
		cout << endl;
		cout << "№ 1" << " 2" << " 3" << endl;

		for (int i = 0; i < 3; i++) {
			cout << i + 1 << " ";
			for (int j = 0; j < 3; j++) {
				cout << pole[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}

	bool check()
	{
		int count{0};
		int diagl{ 0 };
		int j{2};

			/////////////////// PLAYER DIAGL /////////////////////

			for (int i = 0; i < 3; i++) {
				if (pole[i][i] == 'X') {
					diagl++;
				}
			}
			if (diagl == 3) {
				cout << GREEN << "Ты победил!" << RESET << endl;
				return true;
			}
			diagl = 0;
			for (int i = 0; i < 3; i++) {
				if (pole[i][j] == 'X') {
					diagl++;
				}
				j--;
			}
			if (diagl == 3) {
				cout << GREEN << "Ты победил!" << RESET << endl;
				return true;
			}

			/////////////////// BOT DIAGL /////////////////////

			diagl = 0;
			j = 2;

			for (int i = 0; i < 3; i++) {
				if (pole[i][i] == 'O') {
					diagl++;
				}
			}
			if (diagl == 3) {
				cout << RED << "Бот победил!" << RESET << endl;
				return true;
			}


			diagl = 0;


			for (int i = 0; i < 3; i++) {
				if (pole[i][j] == 'O') {
					diagl++;
				}
				j--;
			}
			if (diagl == 3) {
				cout << RED << "Бот победил!" << RESET << endl;
				return true;
			}
			
			/////////////////// PLAYER LINE --- /////////////////////
			count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (pole[i][j] == 'X') {
						count++;
					}
				}
				if (count == 3) {
					cout << GREEN << "Ты победил!" << RESET << endl;
					return true;
				}
				count = 0;
			}

			/////////////////// PLAYER LINE ||| /////////////////////
			count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (pole[j][i] == 'X') {
						count++;
					}
				}
				if (count == 3) {
					cout << GREEN << "Ты победил!" << RESET << endl;
					return true;
				}
				count = 0;
			}

			/////////////////// BOT LINE --- /////////////////////
			count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (pole[i][j] == 'O') {
						count++;
					}
				}
				if (count == 3) {
					cout << RED << "Бот победил!" << RESET << endl;
					return true;
				}
				count = 0;
			}

			/////////////////// BOT LINE ||| /////////////////////
			count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (pole[j][i] == 'O') {
						count++;
					}
				}
				if (count == 3) {
					cout << RED << "Бот победил!" << RESET << endl;
					return true;
				}
				count = 0;
			}
			
			count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (busy[i][j] == true) {
						count++;
					}
					else {}
				}
			}
			if (count == 9) {
				cout << YELLOW << "Ничья!" << RESET << endl;
				return true;
			}
			return false;
	}
	friend void player(Pole& pole);
	friend void bot(Pole& pole);
};

