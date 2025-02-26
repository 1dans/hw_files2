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
		cout << "�� ������� ������� ���� \"students.txt\"" << endl;
		return;
	}
	cout << "�� ����� �� �� ������ ���������� ��� ��������? �/�\n��� ����: ";
	cin >> choice;
	if (choice == '�' || choice=='�') {
		cout << "������ ��� ��� ��������\n (������� ���� \"�������\" �������, ���� ������ �������� ���)";
		while (true) {
			cin.ignore();
			cout << "�������: ";
			getline(cin, surname);
			if (surname == "") break;
			cout << "��'�: ";
			getline(cin, name);
			cout << "������ �� �������: ";
			cin >> examMark;
			Student student = { surname, name, examMark };
			s.push_back(student);
		}
	}
	out << "����� ����� 0";
	out.close();
	cout << "��� ��� �������� ���� ������ ������� � ���� \"students.txt\"\n";
	cout << "������ ��������� ��� ��� ��������� ��������: ";
	cin >> neededMark;
	fstream in("students.txt", ios::in);
	if (!in) {
		cout << "�� ������� ������� ���� \"students.txt\"" << endl;
		return;
	}
	int averageGroupMark = 0, count = 0;
	vector<int> groupAverage;
	cout << "��������, �� ����� ��� ����� ��� ����� " << neededMark << ":\n";
	while (in >> surname >> name >> examMark) {
		if (surname == "�����" && name == "�����" && examMark == 0) { 
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
	cout << "�� ������ �� �������� ������� ��� �� ������? �/�\n";
	cin >> choice;
	if (choice == '�' || choice == '�') {
		cout << "������� ��� �� ������:\n";
		for (int i = 0; i < groupAverage.size(); i++) {
			cout << "����� " << i + 1 << ": " << groupAverage[i] << endl;
		}
	}
}
