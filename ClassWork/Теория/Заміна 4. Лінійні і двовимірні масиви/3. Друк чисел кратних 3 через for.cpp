#include <iostream>
using namespace std;

// ������: ������� ����� �� 100 �� N, �� ����� 3
void main()
{
	int N;
	cout << " Enter N=";
	cin >> N;

	// ����� 1 (��������� �� �����, �������� �����)
	for (int i = 100; i <= N; i++)
		if (i % 3 == 0) // ����������� ���� ����� 3
			cout << " " << i;
	cout << endl;

	// ����� 2 (��������� ���� ����� ����� )
	// ���������� ������
	for (int i = 102; i <= N; i += 3)
		cout << " " << i;
	cout << endl;	
}