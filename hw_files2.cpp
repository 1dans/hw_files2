#include "main.h"
#include "task1.h"
#include "task2.h"
#include <iostream>
using namespace std;
#include <fstream>



void showWelcome() {
	cout << "��������:\n1 - ��������\n2 - ���������� �����\n3 - ������������� (���-����)\nq - �����\n��� ����: ";
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
		default: cout << "������ ������� ����. ������ 1, 2, 3 ��� q\n"; break;
		}
		if (choice == 'q') break;
	}
	cout << "�������!";
	return 0;
}