#include <stdio.h>
#include "Header.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <complex>

int GetKey() noexcept {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int Ent() noexcept {
	while (true) {
		int key = GetKey();
		if (key == 13) return key;
	}
}

template <class T>
void FirstMenu(Polynom<T> main) {
	while (true) {
		system("cls");
		main.PrintPolynom();
		std::cout << "\n1. Change coefficient";
		std::cout << "\n2. Add to another polynomial";
		std::cout << "\n3. Subtract another polynomial";
		std::cout << "\n4. Multiply by a scalar number";
		std::cout << "\n5. Calculate for a given x";
		std::cout << "\n6. Back";
		int m = GetKey();
		if (m == 49) {
			system("cls");
			std::cout << "To what degree do you want to change the coefficient?\n";
			int degreetochange;
			std::cin >> degreetochange;
			std::cout << "Enter a new coefficient: ";
			T newcoef;
			std::cin >> newcoef;
			try {
				main.Set(newcoef, degreetochange);
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "The change was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 50) {
			system("cls");
			std::cout << "Enter the greatest degree of the second polynomial!\n";
			int maxdegree2;
			std::cin >> maxdegree2;
			try {
				Polynom<T> second(maxdegree2);
				int i = 0;
				while (i != maxdegree2 + 1) {
					std::cout << "Coefficient at i = " << maxdegree2 - i << ":";
					T coef = 0;
					std::cin >> coef;
					second.Set(coef, maxdegree2 - i);
					i++;
				}
				std::cout << "Second polynomial: ";
				second.PrintPolynom();
				std::cout << "\n";
				main = main + second;
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "The addition was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 51) {
			system("cls");
			std::cout << "Enter the greatest degree of the second polynomial!\n";
			int maxdegree2;
			std::cin >> maxdegree2;
			try {
				Polynom<T> second(maxdegree2);
				int i = 0;
				while (i != maxdegree2 + 1) {
					std::cout << "Coefficient at i = " << maxdegree2 - i << ":";
					T coef = 0;
					std::cin >> coef;
					second.Set(coef, maxdegree2 - i);
					i++;
				}
				std::cout << "Second polynomial: ";
				second.PrintPolynom();
				std::cout << "\n";
				main = main - second;
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "Subtraction was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 52) {
			system("cls");
			std::cout << "Enter the number by which the polynomial will be multiplied: ";
			T scalar;
			std::cin >> scalar;
			main = main * scalar;
			std::cout << "Multiplication by a number was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 53) {
			system("cls");
			std::cout << "Enter x: ";
			T x;
			std::cin >> x;
			std::cout << "" << main.Result(x);
			std::cout << "\nPress Enter to continue...";
			Ent();
		}
		if (m == 54) break;
	}
}

int PreMenu() {
	while (true) {
		system("cls");
		std::cout << "1. <int>\n";
		std::cout << "2. <float>\n";
		std::cout << "3. <double>\n";
		std::cout << "4. <std::complex<float>>\n";
		std::cout << "5. <std::complex<double>>\n";
		std::cout << "6. Exit\n";
		int m = GetKey();
		if (m == 49) {
			return 1;
		}
		if (m == 50) {
			return 2;
		}
		if (m == 51) {
			return 3;
		}
		if (m == 52) {
			return 4;
		}
		if (m == 53) {
			return 5;
		}
		if (m == 54) {
			return 0;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true){
		int type = PreMenu();
		if (type == 0) {
			return 0;
		}
		std::cout << "Enter the greatest degree of the polynomial!\n";
		int maxdegree = 0;
		try {
			std::cin >> maxdegree;
			if (type == 1) {
				Polynom<int> main(maxdegree);
				FirstMenu(main);
			}
			if (type == 2) {
				Polynom<float> main(maxdegree);
				FirstMenu(main);
			}
			if (type == 3) {
				Polynom<double> main(maxdegree);
				FirstMenu(main);
			}
			if (type == 4) {
				Polynom<std::complex<float>> main(maxdegree);
				FirstMenu(main);
			}
			if (type == 5) {
			Polynom<std::complex<double>> main(maxdegree);
			FirstMenu(main);
			}
		}
		catch (const char* err) {
		std::cout << "Error: " << err;
		}
	}
}