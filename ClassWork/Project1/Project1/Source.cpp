#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
void fill_array(int **arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void print_array(int ** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}
int Sum(int **arr, int row, int col)
{
	int s = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			s = s + arr[i][j];
		}
	}
	return s;
}
void delete_string(int **&arr, int &row, int k)
{
	if (k < 0 || k >= row)
		return;
	else
	{
		int **tmp = new int*[row - 1];
		for (int i = 0; i < k; i++)
		{
			tmp[i] = arr[i];
		}
		for (int i = k + 1; i < row; i++)
		{
			tmp[i - 1] = arr[i];
		}
		row = row - 1;
		delete[]arr[k];
		delete[]arr;
		arr = tmp;
	}
}
int s_len(char *str)
{
	int b = 0;
	while (str[b] != '\0')
		b++;
	return b;
}
void s_copy(char *str, char *buf)
{
	while (*(str++) = *(buf++));
	/*int b = 0;
	do {
		str[b] = buf[b];
	} while (buf[b++] != '\0');*/
}
int main()
{
	srand(time(NULL));
	/*char arr[6] = { 'H', 'e', 'l', 'l', 'o' };
	char mas[] = "Hello";
	cout << arr << endl;
	cout << mas << endl;*/
	//=======================================
	/*int age;
	cout << "How old are you -> ";
	cin >> age;
	cout << age << " is my favorite age!" << endl;
	cin.ignore();
	char name[20];
	cout << "Enter your name -> ";
	cin.getline(name, 20);
	cout << "Hello " << name << endl;*/
	//============================================
	/*char buf[500];
	cout << "Enter the text -> ";
	cin.getline(buf, 500);
	int len = strlen(buf);
	char *str = new char[len + 1];
	strcpy(str, buf);
	cout << str << endl;
	if (strpbrk(str, "01234566789"))
		cout << "++++" << endl;
	else
		cout << "----" << endl;
	delete[]str;*/
	//=================================================
	char str[] = "    one,two.three:four;five!!!six---";
	char *pt = strtok(str, " ,.:;!-");
	while (pt)
	{
		cout << pt << endl;
		pt = strtok(NULL, " ,.:;!-");
	}
	//===============================================================
	/*int row = 5;
	int **arr = new int*[row];
	int *col = new int[row];
	for (int i = 0; i < row; i++)
	{
		col[i] = rand() % 6 + 2;
		arr[i] = new int[col[i]];
	}*/

	//заповнення двовимірного масиву

	/*for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}*/

	/*fill_array(arr, row, col);
	print_array(arr, row, col);
	cout << "SUM ARRAY -> " << Sum(arr, row, col) << endl;
	int k;
	cout << "Enter k -> ";
	cin >> k;
	delete_string(arr, row, k);
	print_array(arr, row, col);*/

	//видалення двовимірного масиву

	/*for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	delete[]col;*/


	//===========================================================

	//створення 3 вимірного масиву
	/*int x = 3, y = 4, z = 5;
	int***arr = new int**[x];
	for (int i = 0; i < x; i++)
	{
		arr[i] = new int *[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = new int[z];
		}
	}*/
	//=================================================
	/*for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				arr[i][j][k] = rand() % 10;
			}
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				cout << arr[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}*/
	//==================================================
	/*for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			delete[]arr[i][j];
		}
	}
	for (int i = 0; i < x; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;*/
	system("pause");
}