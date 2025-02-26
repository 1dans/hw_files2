#include "main.h"
#include "task1.h"
#include "task2.h"
#include <iostream>
using namespace std;
#include <fstream>



void showWelcome() {
	cout << "Завдання:\n1 - студенти\n2 - неприйнятні слова\n3 - транслітерація (укр-англ)\nq - вийти\nВаш вибір: ";
}

int main()
{
	char choice;
	system("chcp 1251>null");
	showWelcome();
	while (true) {
		cin >> choice;
		switch (choice) {
		case '1': task1(); break;
		case '2': task2(); break;
		case '3': /*task3();*/ break;
		case 'q': break;
		default: cout << "Такого варіанту немає. Введіть 1, 2, 3 або q\n"; break;
		}
		if (choice == 'q') break;
	}
	cout << "Бувайте!";
	return 0;
}