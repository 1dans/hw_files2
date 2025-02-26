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
		cout << "Файл \"task2InappropriateWords.txt\" не знайдено\n";
		return;
	}
	string word = " ";
	cout << "Введіть слова, які ви хочете додати до списку неприйнятних слів:\n";
	cin.ignore();
	while (true) {
		getline(cin, word);
		if (word == "") break;
		else filterFill << word << endl;
	}
	filterFill.close();
	cout << "Слова успішно додані до списку неприйнятних слів.\n";

	fstream filter("task2InappropriateWords.txt", ios::in);
	if (!filter) {
		cout << "Файл \"task2InappropriateWords.txt\" не знайдено\n";
		return;
	}
	fstream filtred("task2Filtred.txt", ios::out);
	if (!filtred) {
		cout << "Файл \"task2Filtred.txt\" не знайдено\n";
		return;
	}
	fstream text("task2UnfiltredText.txt", ios::in);
	if (!text) {
		cout << "Файл \"task2UnfiltredText.txt\" не знайдено\n";
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
	cout << "Слова успішно відфільтровані\n";
	showWelcome();
}
