#include "calc.h"
int main()
{
	int n = 1;
	char m;
	double a, b, k;
	while (n == 1)
	{
		system("cls");
		cout << "Enter a -> ";
		cin >> a;
		system("cls");
		cout << "1 - exit." << endl;
		cout << "'+' - sum." << endl;
		cout << "'-' - rizn." << endl;
		cout << "'*' - mult." << endl;
		cout << "'/' - div." << endl;
		cout << "Enter operation -> ";
		cin >> m;
		switch (m)
		{
		case '+':
			system("cls");
			cout << "Enter b -> ";
			cin >> b;
			system("cls");
			cout << "Sum - > " << calc(a, b, sum) << endl;
			system("pause");
			break;
		case '-':
			system("cls");
			cout << "Enter b -> ";
			cin >> b;
			system("cls");
			cout << "Rizn -> " << calc(a, b, rizn) << endl;
			system("pause");
			break;
		case '*':
			system("cls");
			cout << "Enter b -> ";
			cin >> b;
			system("cls");
			cout << "Mult -> " << calc(a, b, mult) << endl;
			system("pause");
			break;
		case '/':
			system("cls");
			cout << "Enter b -> ";
			cin >> b;
			system("cls");
			k = calc(a, b, div);
			if (k == -1)
				cout << "Error." << endl;
			else
				cout << "Div -> " << calc(a, b, div) << endl;
			system("pause");
			break;
		case '1':
			n = 0;
			break;
		default:
			cout << "Entering wrong data. Try again." << endl;
			break;
		}
	}
	system("pause");
}