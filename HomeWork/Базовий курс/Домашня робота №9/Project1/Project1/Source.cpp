#include<iostream>
using namespace std;
struct Film
{
	int Id;
	char name_film[100];
	char creator[100];
	char genre[100];
	float price;
	float popularity_rating;
};
void fill_film(Film &obj)
{
	system("cls");
	cin.ignore();
	cout << "Enter film name -> ";
	cin.getline(obj.name_film, 100);
	cout << "Enter creator -> ";
	cin.getline(obj.creator, 100);
	cout << "Enter genre -> ";
	cin.getline(obj.genre, 100);
	cout << "Enter price -> ";
	cin >> obj.price;
	cout << "Enter popularity rating -> ";
	cin >> obj.popularity_rating;
}
void add_film(Film *&arr, int &size, int &id)
{
	if (size == 0)
		arr = new Film[1];
	else
	{
		Film *tmp = new Film[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
	}
	arr[size].Id = id++;
	fill_film(arr[size]);
	size++;
}
void delete_last_film(Film *&videostore, int &size_mas)
{
	Film * tmp = new Film[--size_mas];
	for (int i = 0; i < size_mas; i++)
	{
		tmp[i] = videostore[i];
	}
	delete[]videostore;
	videostore = tmp;
	cout << "Deletion was successful." << endl;
}
int find_by_id(Film*&arr, int &size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].Id == id)
			return i;
	}
	return -1;
}
void del_film_by_id(Film*&arr, int &size, int id)
{
	int pos = find_by_id(arr, size, id);
	if (pos == -1)
		return;
	Film * tmp = new Film[--size];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (i == pos)
			j++;
		tmp[i] = arr[j];
	}
	delete[]arr;
	arr = tmp;
	system("cls");
	cout << "Deletion was successful." << endl;
}
void object_display(Film A)
{
	cout << "++++++++++++++++++++++++++++++++" << endl;
	cout << "Id -> " << A.Id << endl;
	cout << "Film name -> " << A.name_film << endl;
	cout << "Creator -> " << A.creator << endl;
	cout << "Genre -> " << A.genre << endl;
	cout << "Price -> " << A.price << endl;
	cout << "Popularity rating -> " << A.popularity_rating << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
}
void search_for_a_film_by_title(Film *&videostore, int size_mas, char *str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(videostore[i].name_film,str))
		{
			n = 1;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		object_display(videostore[ind]);
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Invalid name entered, please try again!" << endl;
		system("pause");
	}
}
void search_for_a_film_by_genre(Film *&videostore, int size_mas, char *str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(videostore[i].genre, str))
		{
			n = 1;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		object_display(videostore[ind]);
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Invalid genre entered, please try again!" << endl;
		system("pause");
	}
}
void all_fimls(Film *A, int size)
{
	for (int i = 0; i < size; i++)
	{
		object_display(A[i]);
	}
	system("pause");
}
int main()
{
	int id = 1;
	int size_mas = 0, choose = 0, n = 1;
	Film * videostore = nullptr;
	while (n == 1)
	{
		system("cls");
		cout << "1 - Adding a new film in the videostore." << endl;
		cout << "2 - Delete the last film." << endl;
		cout << "3 - Delete a film by id." << endl;
		cout << "4 - Search film by title." << endl;
		cout << "5 - Search for a film by genre." << endl;
		cout << "6 - Display all information about movies." << endl;
		cout << "7 - Exit" << endl << ">>>> ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			add_film(videostore, size_mas, id);
			break;
		case 2:
			system("cls");
			delete_last_film(videostore, size_mas);
			system("pause");
			break;
		case 3:
			system("cls");
			int id_f;
			cout << "Enter the id of the film you want to delete -> ";
			cin >> id_f;
			del_film_by_id(videostore, size_mas, id_f);
			system("pause");
			break;
		case 4:
			system("cls");
			char str[100];
			cin.ignore(1);
			cout << "Enter the name of the film you are looking for -> ";
			cin.getline(str, 100);
			search_for_a_film_by_title(videostore, size_mas, str);
			break;
		case 5:
			system("cls");
			char str1[100];
			cin.ignore(1);
			cout << "Enter the genre of the film you are looking for -> ";
			cin.getline(str1, 100);
			search_for_a_film_by_genre(videostore, size_mas, str1);
			break;
		case 6:
			system("cls");
			all_fimls(videostore, size_mas);
			break;
		case 7:
			n = 0;
			break;
		default:
			system("cls");
			cout << "Entering wrong data, please try again!" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
}