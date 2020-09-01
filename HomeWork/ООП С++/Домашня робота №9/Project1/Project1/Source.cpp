#include<iostream>
#include<fstream>
#include<string> 
#include<ctime>
#include<stdexcept>
using namespace std;
char* code(const string&str, int k, int size)
{
	char * tmp = new char[size + 1]{};
	int  i = 0;
	while (i < size)
	{
		tmp[i] += str[i] - k;
		i++;
	}
	return tmp;
}
char * decode(const string&str, int k, int size)
{
	char * tmp = new char[size + 1]{};
	int i = 0;
	while (i < size)
	{
		tmp[i] += str[i] + k;
		i++;
	}
	return tmp;
}
int main()
{
	srand(time(0));
	fstream finput, fkey, foutput;
	string input, output;
	int size, key;
	try
	{
		// шифровка
		cout << "=================Encryption=================" << endl;
		finput.open("test.txt", ios::in);
		if (!finput.is_open())
			throw logic_error("Can not open input file");
		while (!finput.eof())
		{
			getline(finput, input);
		}

		key = 1 + rand() % 9;
		size = input.length();
		cout << "Encryption Key -> " << key << endl;
		cout << "Original text -> " << input << endl;

		foutput.open("coded.txt", ios::out);
		if (!foutput.is_open())
			throw logic_error("Can not open output file");

		output = code(input, key, size);
		foutput << output;

		cout << "Encrypted text -> " << output << endl;

		foutput.close();

		fkey.open("key.bin", ios::out | ios::binary);
		if (!fkey.is_open())
			throw logic_error("Can not open key file");

		fkey.write((char*)&key, sizeof(int));

		fkey.close();
		finput.close();



		// дешифровка
		cout << endl << "=================Decryption=================" << endl;
		finput.open("coded.txt", ios::in);
		if (!finput.is_open())
			throw logic_error("Can not open input file");
		while (!finput.eof())
		{
			getline(finput, input);
		}

		size = input.length();
		cout << "Original text -> " << input << endl;

		fkey.open("key.bin", ios::in | ios::binary);
		if (!fkey.is_open())
			throw logic_error("Can not open key file");

		fkey.read((char*)&key, sizeof(int));

		foutput.open("decrypted.txt", ios::out);
		if (!foutput.is_open())
			throw logic_error("Can not open output file");

		output = decode(input, key, size);

		cout << "Decrypted text -> " << output << endl;

		foutput << output << endl;

		foutput.close();
		fkey.close();
		finput.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}
	system("pause");
}