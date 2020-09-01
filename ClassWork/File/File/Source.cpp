#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	FILE *f = nullptr;

	//txt file
	/*f = fopen("test.txt", "w");
	if (f)
	{
		fputs("Test Hello", f);
		fclose(f);
	}
	f = fopen("test.txt", "r");
	char buf[500];
	if (f)
	{
		while (!feof(f))
		{
			fgets(buf, 500, f);
			cout << buf;
			buf[0] = 0;
		}
		cout << endl;
		fclose(f);
	}*/

	//bin file
	/*int a[5] = { 65,66,67,68,69 };
	f = fopen("test.bin", "wb");
	if (f)
	{
		fwrite(a, sizeof(int), 5, f);
		fclose(f);
	}
	int b[5] = {};
	f = fopen("test.bin", "rb");
	if (f)
	{
		fread(b, sizeof(int), 5, f);
		fclose(f);
	}
	for (int i = 0; i < 5; i++)
		cout << b[i] << " ";
	cout << endl;*/

	srand(time(NULL));
	/*int size = rand() % 10 + 3;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 26 + 65;
	}
	f = fopen("arr.bin", "wb");
	if (f)
	{
		fwrite(&size, sizeof(int), 1, f);
		fwrite(arr, sizeof(int), size, f);
		fclose(f);
	}*/
	f = fopen("arr.bin", "rb");
	if (f)
	{
		int size_new;
		fread(&size_new, sizeof(int), 1, f);
		int *arr1 = new int[size_new];
		fread(arr1, sizeof(int), size_new, f);
		fclose(f);
		for (int i = 0; i < size_new; ++i)
		{
			cout << arr1[i] << " ";
		}
		cout << endl;
		delete[]arr1;
	}
	system("pause");
}