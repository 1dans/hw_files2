#include "task2.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

void task2()
{
	fstream filterFill("task2InappropriateWords.txt", ios::app);
	if (!filterFill) {
		cout << "���� \"task2InappropriateWords.txt\" �� ��������\n";
		return;
	}
	string word = " ";
	cout << "������ �����, �� �� ������ ������ �� ������ ������������ ���:\n";
	cin.ignore();
	while (true) {
		getline(cin, word);
		if (word == "") break;
		else filterFill << word << endl;
	}
	filterFill.close();
	cout << "����� ������ ����� �� ������ ������������ ���.\n";

	fstream filter("task2InappropriateWords.txt", ios::in);
	if (!filter) {
		cout << "���� \"task2InappropriateWords.txt\" �� ��������\n";
		return;
	}
	fstream filtred("task2Filtred.txt", ios::out);
	if (!filtred) {
		cout << "���� \"task2Filtred.txt\" �� ��������\n";
		return;
	}
	fstream text("task2UnfiltredText.txt", ios::in);
	if (!text) {
		cout << "���� \"task2UnfiltredText.txt\" �� ��������\n";
		return;
	}
	vector<string> words;
	string line;
	bool appropriate = true;
	while (filter >> line) {
		words.push_back(line);
	}
	filter.close();
	while (text >> line) {
		for (string i : words) if (line == i) appropriate = false;
		if (appropriate) filtred << line << " ";
		else filtred << "**** ";
		appropriate = true;
	}
	text.close();
	filtred.close();
	cout << "����� ������ ������������\n";
	showWelcome();
}
