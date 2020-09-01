#include<iostream>
#include<string>
using namespace std;
int main()
{
	//1

	/*string str;
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	int pos1 = str.find_first_of('h');
	int pos2 = str.find_last_of('h');
	string tmp = str.substr(pos1 + 1, pos2 - pos1);
	reverse(tmp.begin(), tmp.end());
	str = str.substr(0, pos1) + tmp + str.substr(pos2);
	cout << str << endl;*/
	
	//2

	/*string str;
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	int pos;
	for (int i = 0; i < str.length();)
	{
		if (str[i] == 'n')
		{
			pos = i;
			str = str.erase(pos) + str.substr(pos + 1);
			i--;
		}
		i++;
	}
	cout << str << endl;*

	//3

	/*string str;
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	int pos, posf = str.find_first_of('h'), posl = str.find_last_of('h');
	for (int i = 0; i < str.length(); i++)
	{
		if (i == posf || i == posl)
			continue;
		if (str[i] == 'h')
		{
			pos = i;
			str = str.replace(pos, 1, "H");
		}
	}
	cout << str << endl;*/

	//4

	/*string str, tmp;
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	for (int i = 0; i < str.length(); i++)
	{
		if (i % 3 != 0)
		{
			tmp = tmp + str[i];
		}

	}
	cout << tmp <<endl;*/

	//5

	/*string str;
	const char* s = "one";
	cout << "Enter the line -> ";
	getline(cin, str);
	cout << str << endl;
	int pos;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1')
		{
			pos = i;
			str = str.substr(0, pos) + ' ' + ' ' + str.substr(pos);
			str = str.replace(pos, 3, s);
		}
	}
	cout << str << endl;*/
	system("pause");
}