#include <iostream>
#include <ctime>
#include "Pole.h"

using std::cout;
using std::cin;
using std::endl;

void player(Pole& pole)
{
	cout << endl;
	cout << "player" << endl;
	int row;
	int col;
	while (true) {
		cout << "Введите столбец: ";
		cin >> col;
		cout << "Введите строчку: ";
		cin >> row;
		if (row > 0 && col > 0 && row < 4 && col < 4) {
			if (pole.busy[row - 1][col - 1] == false) {
				pole.busy[row - 1][col - 1] = true;
				pole.pole[row - 1][col - 1] = 'X';
				return;
			}
			else {
				cout << "Занято." << endl;
			}
		}
		else {
			cout << "Неверный ввод." << endl;
		}
	}
}

void bot(Pole& pole)
{
	cout << endl;
	cout << "Bot";
	int row;
	int col;
	while (true) {
		row = 1 + rand() % 3;
		col = 1 + rand() % 3;
		if (pole.busy[row - 1][col - 1] == false) {
			pole.busy[row - 1][col - 1] = true;
			pole.pole[row - 1][col - 1] = 'O';
			return;
		}
		else {}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(0));

	Pole pole{};
	pole.print();
	while (true) {
		player(pole);
		pole.print();
		if (pole.check() == true) {
			return 0;
		}
		bot(pole);
		pole.print();
		if (pole.check() == true) {
			return 0;
		}
	}
}
