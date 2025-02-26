#include "task3.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void task3() // правила транслітерації взяті з сайту https://www.kmu.gov.ua/npas/243262567
{
	fstream Ukr("task3Ukr.txt", ios::in);
	if (!Ukr) {
		cout << "Файл \"task3Ukr.txt\" не знайдено\n"; 
		return;
	}
	fstream Eng("task3Eng.txt", ios::in);
	if (!Eng) {
		cout << "Файл \"task3Eng.txt\" не знайдено\n";
		return;
	}
	fstream res("task3Final.txt", ios::app);
	if (!res) {
		cout << "Файл \"task3Final.txt\" не знайдено\n";
		return;
	}
	vector<string> ukr, eng;
	string ch;

	while (Ukr >> ch) ukr.push_back(ch);
	while (Eng >> ch) eng.push_back(ch);

	Ukr.close();
	Eng.close();

	

	string word;
	vector<string> ukrWords;
	cin.ignore();
	while (true) {
		cout << "Введіть слово для транслітерації (або залиште порожнім для виходу): ";
		getline(cin, word);
		if (word == "") break;
		string engWord = "";
		for (int i = 0; i < word.length(); ++i) {
			for (int j = 0; j < ukr.size(); ++j) {
                if (word[i] == ukr[j][0]) {
					engWord += eng[j];
					break;
				}
			}
		}
		res << word << " - " << engWord << endl;
	}
	res.close();
	cout << "Результат збережено в файлі task3Final.txt\n";
	showWelcome();
	return;
}
