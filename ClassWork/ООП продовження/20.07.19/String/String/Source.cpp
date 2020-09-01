#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	int pos = str.find(" ");
	str = str.substr(pos + 1) + " " + str.substr(0, pos);
	cout << str << endl;
	system("pause");
}