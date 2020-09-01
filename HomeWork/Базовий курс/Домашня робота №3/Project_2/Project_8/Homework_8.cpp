#include <iostream>
using namespace std;
int main()
{
	//1
	/*cout << "a)" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i >= j)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "b)" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i+j<=7)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "c)" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j >= i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "d)" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i+j>=7)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}*/

	//2
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j <= 4)
				cout << "*";
		}
		cout << endl;
	}
	for (int i = 4; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i - 3 >= j)
				cout << "*";
		}
		cout << endl;
	}*/

	//3
	/*int f = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (f == 1)
					cout << "*";
				else
					cout << " ";
				f = -f;
			}
			else
			{
				if (f == 1)
					cout << " ";
				else
					cout << "*";
				f = -f;
			}
		}
		cout << endl;
	}*/
	system("pause");
}