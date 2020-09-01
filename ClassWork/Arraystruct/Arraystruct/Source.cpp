#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct Cat
{
	int id;
	char name[20];
	char breed[20];
	int age;
};
void fill_cat(Cat &obj)
{
	cout << "Enter the name -> ";
	cin.getline(obj.name, 20);
	cout << "Enter the breed -> ";
	cin.getline(obj.breed, 20);
	cout << "Enter the age -> ";
	cin >> obj.age;
	cin.ignore();
}
void add_cat(Cat*&arr, int &size, int &id)
{
	if (size == 0)
		arr = new Cat[1];
	else
	{
		Cat *tmp = new Cat[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
	}
	arr[size].id = id++;
	fill_cat(arr[size]);
	size++;
}
void print_cat(Cat obj)
{
	cout << "++++++++++++++++++++++" << endl;
	cout << "Id: " << obj.id << endl;
	cout << "Name: " << obj.name << endl;
	cout << "Breed: " << obj.breed << endl;
	cout << "Age: " << obj.age << endl;
	cout << "++++++++++++++++++++++" << endl;
}
int find_by_id(Cat*&arr, int &size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].id == id)
			return i;
	}
	return -1;
}
void del_cat(Cat*&arr, int &size, int id)
{
	int pos = find_by_id(arr, size, id);
	if (pos == -1)
		return;
	Cat * tmp = new Cat[--size];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (i == pos)
			j++;
		tmp[i] = arr[j];
	}
	delete[]arr;
	arr = tmp;
}
void save(Cat*arr, int size, int id)
{
	FILE*f = fopen("Shelter.save", "wb");
	if (f)
	{
		fwrite(&id, sizeof(int), 1, f);
		fwrite(&size, sizeof(int), 1, f);
		fwrite(arr, sizeof(Cat), size, f);
		fclose(f);
	}
}
void load(Cat*&arr, int &size, int &id)
{
	FILE*f = fopen("Shelter.save", "rb");
	if (f)
	{
		if (size)
			delete[]arr;
		fread(&id, sizeof(int), 1, f);
		fread(&size, sizeof(int), 1, f);
		arr = new Cat[size];
		fread(arr, sizeof(Cat), size, f);
		fclose(f);
	}
}
int main()
{
	int id = 1;
	int size = 0;
	Cat *shelter = nullptr;
	add_cat(shelter, size, id);
	add_cat(shelter, size, id);
	add_cat(shelter, size, id);
	del_cat(shelter, size, 2);
	//save(shelter, size, id);
	load(shelter, size, id);
	for (int i = 0; i < size; i++)
	{
		print_cat(shelter[i]);
	}

	if (size)
	{
		delete[]shelter;
	}
	system("pause");
}