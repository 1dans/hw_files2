#include "task1.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string surname, name;
	double examMark;
};

void task1()
{
	vector<Student> s;
	string surname=" ", name;
	double examMark, neededMark;
	char choice;
	fstream out("students.txt", ios::app);
	if (!out) {
		cout << "Не вдалося відкрити файл \"students.txt\"" << endl;
		return;
	}
	cout << "Чи хотіли би ви додати інформацію про студентів? т/н\nВаш вибір: ";
	cin >> choice;
	if (choice == 'т' || choice=='Т') {
		cout << "Введіть дані про студента\n (Залиште поле \"прізвище\" пороіжнім, якщо хочете закінчити ввід)";
		while (true) {
			cin.ignore();
			cout << "Прізвище: ";
			getline(cin, surname);
			if (surname == "") break;
			cout << "Ім'я: ";
			getline(cin, name);
			cout << "Оцінка за екзамен: ";
			cin >> examMark;
			Student student = { surname, name, examMark };
			s.push_back(student);
		}
	}
	out << "кінець групи 0";
	out.close();
	cout << "Дані про студентів були успішно записані у файл \"students.txt\"\n";
	cout << "Введіть мінімальний бал для виведення студентів: ";
	cin >> neededMark;
	fstream in("students.txt", ios::in);
	if (!in) {
		cout << "Не вдалося відкрити файл \"students.txt\"" << endl;
		return;
	}
	int averageGroupMark = 0, count = 0;
	vector<int> groupAverage;
	cout << "Студенти, які мають бал більше або рівний " << neededMark << ":\n";
	while (in >> surname >> name >> examMark) {
		if (surname == "кінець" && name == "групи" && examMark == 0) { 
			if (count != 0) {
				groupAverage.push_back(averageGroupMark / count);
				averageGroupMark = 0;
				count = 0;
			}
		}
		if (examMark >= neededMark) {
			cout << surname << " " << name << " " << examMark << endl;
		}
		averageGroupMark += examMark;
		count++;
	}
	in.close();
	cout << "Чи хочете ви дізнатися середній бал по групах? т/н\n";
	cin >> choice;
	if (choice == 'т' || choice == 'Т') {
		cout << "Середній бал по групах:\n";
		for (int i = 0; i < groupAverage.size(); i++) {
			cout << "Група " << i + 1 << ": " << groupAverage[i] << endl;
		}
	}
}
