#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
void bubbleSort(int a[], int left, int right);
void print_array(int A[], int n);
void zapovnenya(int A[], int n);
void random_filling(int A[], int n);
void random_number(int A[], int n);
void interesting_sorting(int A[], int n, int k);


int main()
{
	srand(time(NULL));
	//1
	/*const int n = 10;
	int A[n], left = 0, right = 0;
	zapovnenya(A, n);
	cout << "Array:" << endl;
	print_array(A, n);
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
		{
			left = i;
			cout << "A[" << left << "] = " << A[i] << endl;
			break;
		}
	}
	for (int i = n-1; i >= 0; i--)
	{
		if (A[i] < 0)
		{
			right = i;
			cout << "A[" << right << "] = " << A[i] << endl;
			break;
		}
	}
	left = left + 1;
	bubbleSort(A, left, right);
	cout << "Sort array:" << endl;
	print_array(A, n);*/

	//2
	/*const int n = 20;
	int A[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = i + 1;
	}
	print_array(A, n);*/

	//a
	/*random_filling(A, n);
	print_array(A, n);*/

	//b
	/*random_number(A, n);*/

	//c
	/*int k;
	cout << "Enter the index -> ";
	cin >> k;
	interesting_sorting(A, n, k);
	print_array(A, n);*/
	system("pause");
}


void bubbleSort(int a[], int left, int right)
{
	int i, j;
	int x;
	for (i = left; i < right; i++)
	{
		for (j = right - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}
void print_array(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << A[i];
	}
	cout << endl;
}
void zapovnenya(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = -20 + rand() % 41;
	}
}
void random_filling(int A[], int n)
{
	int x, y, b;
	for (int i = 0; i < n; i++)
	{
		x = rand() % 20;
		y = rand() % 20;
		b = A[x];
		A[x] = A[y];
		A[y] = b;
	}
}
void random_number(int A[], int n)
{
	int x = 1 + rand() % 20;
	cout << "Randome number -> " << x << endl;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == x)
			cout << "Random number index -> " << i << endl;
	}
}
void interesting_sorting(int A[], int n, int k)
{
	int i, j;
	int x;
	for (i = 0; i < k; i++)
	{
		for (j = k - 1; j > i; j--)
		{
			if (A[j - 1] < A[j])
			{
				x = A[j - 1];
				A[j - 1] = A[j];
				A[j] = x;
			}
		}
	}
	for (i = k + 1; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				x = A[j - 1];
				A[j - 1] = A[j];
				A[j] = x;
			}
		}
	}
}