#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
using namespace std;
class MyArray
{
	int size = 0;
	double* arr = nullptr;
public:
	MyArray() = default;
	MyArray(int s, double val)
	{
		size = s;
		arr = new double[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = val;
		}
	}
	~MyArray()
	{
		if (size)
			delete[]arr;
	}
	int getSize()const
	{
		return size;
	}
	double &operator[](int pos)
	{
		return arr[pos];
	}
	void save(fstream & fs)
	{
		fs.write((char*)&size, sizeof(int));
		fs.write((char*)arr, sizeof(double)*size);
	}
	void load(fstream &fs)
	{
		if (size)
			delete[]arr;
		fs.read((char*)&size, sizeof(int));
		arr = new double[size];
		fs.read((char*)arr, sizeof(double)*size);
	}
};
int main()
{
	fstream fs;
	string str;
	MyArray obj(10, 32.2323);
	MyArray to_read;
	try
	{
		fs.open("my_array.bin", ios::in | ios::binary);
		if (!fs.is_open())
			throw logic_error("Can not open file");
		to_read.load(fs);
		for (int i = 0; i < to_read.getSize(); i++)
		{
			cout << to_read[i] << " ";
		}
		cout << endl;
		fs.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}
	/*try
	{
		fs.open("my_array.bin", ios::out | ios::binary);
		if (!fs.is_open())
			throw logic_error("Can not open file");
		obj.save(fs);
		fs.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}*/
	/*double arr[5]{ 1.2,2.3,3.4,4.5,5.6 }, mas[5]{};
	try
	{
		fs.open("test.bin", ios::in | ios::binary);
		if (!fs.is_open())
			throw logic_error("Can not open file");
		fs.read((char*)mas, sizeof(double) * 5);
		for (int i = 0; i < 5; i++)
		{
			cout << mas[i] << " ";
		}
		cout << endl;
		fs.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}*/
	/*try
	{
		fs.open("test.bin", ios::out | ios::binary);
		if (!fs.is_open())
			throw logic_error("Can not open file");
		fs.write((char*)arr, sizeof(double) * 5);
		fs.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}*/
	//try
	//{
	//	fs.open("test.txt", ios::in);
	//	if (!fs.is_open())
	//		throw logic_error("Can not open file");
	//	//cout << fs.rdbuf() << endl;
	//	while (!fs.eof())
	//	{
	//		getline(fs, str);
	//		cout << str << endl;
	//	}
	//	fs.close();
	//}
	//catch (const logic_error& ex)
	//{
	//	cout << "Error. " << ex.what() << endl;
	//}
	//fs.open("test.txt", ios::out | ios::in | ios::ate | ios::app | ios::trunc | ios::binary);
	/*try
	{
		fs.open("test.txt", ios::out);
		if (!fs.is_open())
			throw logic_error("Can not open file");
		fs << "Some text" << endl;
		fs << "One more line of text" << endl;
		fs.close();
	}
	catch (const logic_error& ex)
	{
		cout << "Error. " << ex.what() << endl;
	}*/

	system("pause");
}