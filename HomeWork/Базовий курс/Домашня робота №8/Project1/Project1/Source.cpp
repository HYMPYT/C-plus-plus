#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*char str[250];
	cout << "������� ������ -> ";
	cin.getline(str, 250);
	cout << "���������� ������� ��������� ������� -> " << strlen(str) + 1 << endl;
	cout << "���������� ��������� ��������� ������� -> " << 250 - (strlen(str) + 1) << endl;*/

	//2
	/*char str1[250];
	char str2[250];
	cout << "������� ������ ������ -> ";
	cin.getline(str1, 250);
	int len1 = strlen(str1);
	char*res1 = new char[len1 + 1];
	strcpy(res1, str1);
	cout << "������� ������ ������ -> ";
	cin.getline(str2, 250);
	int len2 = strlen(str2);
	char*res2 = new char[len2 + 1];
	strcpy(res2, str2);
	if (strcmp(res1, res2) == 0)
		cout << "������ ���������." << endl;
	else
		cout << "������ �� ���������." << endl;
	delete[]res1;
	delete[]res2;*/

	//3
	/*char buf[500];
	char word[50];
	cout << "������� ����������� -> ";
	cin.getline(buf, 500);
	cout << "������� ����� -> ";
	cin.getline(word, 50);
	if (strstr(buf, word))
		cout << "����� ������� �� ����� ���� � �����������." << endl;
	else
		cout << "����� ������� �� ����� ��� � �����������." << endl;*/

	//4
	/*char fio[250]="";
	char name[50];
	char surname[50];
	char patronymic[50];
	cout << "������� ������� -> ";
	cin.getline(surname, 50);
	int len2 = strlen(surname);
	char*res2 = new char[len2 + 1];
	strcpy(res2, surname);
	cout << "������� ��� -> ";
	cin.getline(name, 50);
	int len1 = strlen(name);
	char*res1 = new char[len1 + 1];
	strcpy(res1, name);
	cout << "������� �������� -> ";
	cin.getline(patronymic, 50);
	int len3 = strlen(patronymic);
	char*res3 = new char[len3 + 1];
	strcpy(res3, patronymic);
	cout << "��������� -> ";
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