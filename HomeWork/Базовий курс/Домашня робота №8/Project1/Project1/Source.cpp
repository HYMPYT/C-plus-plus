#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*char str[250];
	cout << "Введите строку -> ";
	cin.getline(str, 250);
	cout << "Количество занятых элементов массива -> " << strlen(str) + 1 << endl;
	cout << "Количество свободных елементов массива -> " << 250 - (strlen(str) + 1) << endl;*/

	//2
	/*char str1[250];
	char str2[250];
	cout << "Введите первую строку -> ";
	cin.getline(str1, 250);
	int len1 = strlen(str1);
	char*res1 = new char[len1 + 1];
	strcpy(res1, str1);
	cout << "Введите вторую строку -> ";
	cin.getline(str2, 250);
	int len2 = strlen(str2);
	char*res2 = new char[len2 + 1];
	strcpy(res2, str2);
	if (strcmp(res1, res2) == 0)
		cout << "Строки совпадают." << endl;
	else
		cout << "Строки не совпадают." << endl;
	delete[]res1;
	delete[]res2;*/

	//3
	/*char buf[500];
	char word[50];
	cout << "Введите предложение -> ";
	cin.getline(buf, 500);
	cout << "Введите слово -> ";
	cin.getline(word, 50);
	if (strstr(buf, word))
		cout << "Слово которое вы ввели есть в предложении." << endl;
	else
		cout << "Слово которое вы ввели нет в предложении." << endl;*/

	//4
	/*char fio[250]="";
	char name[50];
	char surname[50];
	char patronymic[50];
	cout << "Введите фамилию -> ";
	cin.getline(surname, 50);
	int len2 = strlen(surname);
	char*res2 = new char[len2 + 1];
	strcpy(res2, surname);
	cout << "Введите имя -> ";
	cin.getline(name, 50);
	int len1 = strlen(name);
	char*res1 = new char[len1 + 1];
	strcpy(res1, name);
	cout << "Введите отчество -> ";
	cin.getline(patronymic, 50);
	int len3 = strlen(patronymic);
	char*res3 = new char[len3 + 1];
	strcpy(res3, patronymic);
	cout << "Результат -> ";
	strcat(fio, res2);
	strcat(fio, " ");
	strcat(fio, res1);
	strcat(fio, " ");
	strcat(fio, res3);
	cout << fio << endl;
	delete[]res1;
	delete[]res2;
	delete[]res3;*/
	system("pause");
}