#include<iostream>
using namespace std;
struct House
{
	char Owner[50], Address[100], Material[50], Date_of_construction[50];
	float Height, Cost_of;
	int Number_of_floors, Number_of_apartments;
};
void data_editing(House &A)
{
	int n = 1, b = 0;
	while (n == 1)
	{
		system("cls");
		cout << "1 - Field replacement Owner." << endl;
		cout << "2 - Field replacemen Address." << endl;
		cout << "3 - Field replacemen Height." << endl;
		cout << "4 - Field replacemen Number of floors." << endl;
		cout << "5 - Field replacemen Number of apartments." << endl;
		cout << "6 - Field replacemen Date of construction." << endl;
		cout << "7 - Field replacemen Material." << endl;
		cout << "8 - Field replacemen Cost of sq.m.." << endl;
		cout << "9 - Exit." << endl << ">>> ";
		cin >> b;
		switch (b)
		{
		case 1:
			system("cls");
			cin.ignore();
			cout << "Enter owner -> ";
			cin.getline(A.Owner, 50);
			break;
		case 2:
			system("cls");
			cin.ignore();
			cout << "Enter address -> ";
			cin.getline(A.Address, 100);
			break;
		case 3:
			system("cls");
			cout << "Enter height -> ";
			cin >> A.Height;
			break;
		case 4:
			system("cls");
			cout << "Enter number of floors -> ";
			cin >> A.Number_of_floors;
			break;
		case 5:
			system("cls");
			cout << "Enter number of apartments -> ";
			cin >> A.Number_of_apartments;
			break;
		case 6:
			system("cls");
			cin.ignore();
			cout << "Enter date of construction -> ";
			cin.getline(A.Date_of_construction, 50);
			break;
		case 7:
			system("cls");
			cin.ignore();
			cout << "Enter material -> ";
			cin.getline(A.Material, 50);
			break;
		case 8:
			system("cls");
			cout << "Enter cost of sq.m. -> ";
			cin >> A.Cost_of;
			break;
		case 9:
			n = 0;
			break;
		default:
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			break;
		}

	}
}
void object_fill(House &A)
{
	cout << "Enter height -> ";
	cin >> A.Height;
	cin.ignore();
	cout << "Enter owner -> ";
	cin.getline(A.Owner, 50);
	cout << "Enter address -> ";
	cin.getline(A.Address, 100);
	cout << "Enter date of construction -> ";
	cin.getline(A.Date_of_construction, 50);
	cout << "Enter material -> ";
	cin.getline(A.Material, 50);
	cout << "Enter number of floors -> ";
	cin >> A.Number_of_floors;
	cout << "Enter number of apartments -> ";
	cin >> A.Number_of_apartments;
	cout << "Enter cost of sq.m. -> ";
	cin >> A.Cost_of;
}
void object_display(House A)
{
	system("cls");
	cout << "Owner -> " << A.Owner << endl;
	cout << "Address -> " << A.Address << endl;
	cout << "Height -> " << A.Height << endl;
	cout << "Number of floors -> " << A.Number_of_floors << endl;
	cout << "Number of apartments -> " << A.Number_of_apartments << endl;
	cout << "Date of construction -> " << A.Date_of_construction << endl;
	cout << "Material -> " << A.Material << endl;
	cout << "Cost of sq.m. -> " << A.Cost_of << endl;
	system("pause");
}
void menu(House &A)
{
	int n = 1, b = 0;
	while (n == 1)
	{
		system("cls");
		cout << "1 - Filling an object from the keyboard." << endl;
		cout << "2 - Displaying information about the object." << endl;
		cout << "3 - Editing object data." << endl;
		cout << "4 - Exit." << endl << ">>> ";
		cin >> b;
		switch (b)
		{
		case 1:
			system("cls");
			object_fill(A);
			break;
		case 2:
			system("cls");
			object_display(A);
			break;
		case 3:
			system("cls");
			data_editing(A);
			break;
		case 4:
			n = 0;
			break;
		default:
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			break;
		}
	}
}
int main()
{
	House A;
	menu(A);
	system("pause");
}