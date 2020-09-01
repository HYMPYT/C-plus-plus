#include"Book.h"
book *bookmas = nullptr;
void object_display(book A)
{
	cout << "| " << setw(2) << A.ID << " | ";
	cout << setw(40) << A.title << " | ";
	cout << setw(20) << A.author << " | ";
	cout << setw(10) << A.genre << " | ";
	cout << setw(17) << A.date_of_publication << " | ";
	cout << setw(5) << A.price << " | ";
	cout << setw(6) << A.rating << " |" << endl;
}
void information_about_books_that_are_in_the_library(book * bookmas, int size_mas)
{
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size_mas; i++)
	{
		if (bookmas[i].status == 1)
			object_display(bookmas[i]);
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}
void fill_book(book &obj)
{
	system("cls");
	cout << "Enter a book title -> ";
	cin.getline(obj.title, 50);
	cout << "Enter author -> ";
	cin.getline(obj.author, 100);
	cout << "Enter genre -> ";
	cin.getline(obj.genre, 100);
	cout << "Enter price -> ";
	cin >> obj.price;
	cout << "Enter date of publication -> ";
	cin >> obj.date_of_publication;
}
void add_book(book *&bookmas, int &size_mas, int &id)
{
	if (size_mas == 0)
		bookmas = new book[1];
	else
	{
		book *tmp = new book[size_mas + 1];
		for (int i = 0; i < size_mas; i++)
		{
			tmp[i] = bookmas[i];
		}
		delete[]bookmas;
		bookmas = tmp;
	}
	bookmas[size_mas].ID = id++;
	fill_book(bookmas[size_mas]);
	size_mas++;
}
void delete_last_book(book *&bookmas, int &size_mas, int &id)
{
	book * tmp = new book[--size_mas];
	for (int i = 0; i < size_mas; i++)
	{
		tmp[i] = bookmas[i];
	}
	delete[]bookmas;
	bookmas = tmp;
	id = id - 1;
	cout << "Deletion was successful." << endl;
}
int find_by_id(book*&bookmas, int &size_mas, int id)
{
	for (int i = 0; i < size_mas; i++)
	{
		if (bookmas[i].ID == id)
			return i;
	}
	return -1;
}
void menu_editing(book *&bookmas, int size_mas, int id)
{
	char cho[100];
	int k = find_by_id(bookmas, size_mas, id);
	if (k != -1)
	{
		while (1)
		{
			system("cls");
			cout << "Editing menu" << endl;
			cout << "\t- full editing (full)" << endl;
			cout << "\t- partial editing (partial)" << endl;
			cout << "\t- exit" << endl << ">>> ";
			cin.getline(cho, 100);
			int len = strlen(cho);
			char *choice_2 = new char[len + 1];
			strcpy(choice_2, cho);
			if (!strcmp(choice_2, "full"))
			{
				fill_book(bookmas[k]);
			}
			else if (!strcmp(choice_2, "partial"))
			{
				while (1)
				{
					system("cls");
					cout << "Partial editing" << endl;
					cout << "\t- title" << endl;
					cout << "\t- author" << endl;
					cout << "\t- genre" << endl;
					cout << "\t- price" << endl;
					cout << "\t- rating" << endl;
					cout << "\t- date" << endl;
					cout << "\t- exit" << endl << ">>> ";
					cin.getline(cho, 100);
					len = strlen(cho);
					char *choice_3 = new char[len + 1];
					strcpy(choice_3, cho);
					if (!strcmp(choice_3, "title"))
					{
						system("cls");
						cout << "Enter a book title -> ";
						cin.getline(bookmas[k].title, 50);
					}
					else if (!strcmp(choice_3, "author"))
					{
						system("cls");
						cout << "Enter author -> ";
						cin.getline(bookmas[k].author, 100);
					}
					else if (!strcmp(choice_3, "genre"))
					{
						system("cls");
						cout << "Enter genre -> ";
						cin.getline(bookmas[k].genre, 100);
					}
					else if (!strcmp(choice_3, "price"))
					{
						system("cls");
						cout << "Enter price -> ";
						cin >> bookmas[k].price;
					}
					else if (!strcmp(choice_3, "rating"))
					{
						system("cls");
						cout << "Enter popularity rating -> ";
						cin >> bookmas[k].rating;
					}
					else if (!strcmp(choice_3, "date"))
					{
						system("cls");
						cout << "Enter date of publication -> ";
						cin >> bookmas[k].date_of_publication;
					}
					else if (!strcmp(choice_3, "exit"))
					{
						delete[]choice_3;
						break;
					}
					else
					{
						system("cls");
						cout << "Entering wrong data. Try again." << endl;
						system("pause");
					}
					delete[]choice_3;
				}
			}
			else if (!strcmp(choice_2, "exit"))
			{
				delete[]choice_2;
				break;
			}
			else
			{
				system("cls");
				cout << "Entering wrong data. Try again." << endl;
				system("pause");
			}
			delete[]choice_2;
		}
	}
}
void sort(book *&bookmas, int size_mas, int type)
{
	if (type == 1)
	{
		book swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (strcmp(bookmas[i].title, bookmas[j].title) > 0)
				{
					swap = bookmas[i];
					bookmas[i] = bookmas[j];
					bookmas[j] = swap;
				}
		}
	}
	if (type == 2)
	{
		book swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (bookmas[i].rating > bookmas[j].rating)
				{
					swap = bookmas[i];
					bookmas[i] = bookmas[j];
					bookmas[j] = swap;
				}
		}
	}
	if (type == 3)
	{
		book swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (strcmp(bookmas[i].author, bookmas[j].author) > 0)
				{
					swap = bookmas[i];
					bookmas[i] = bookmas[j];
					bookmas[j] = swap;
				}
		}
	}
	if (type == 4)
	{
		book swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (bookmas[i].rating > bookmas[j].rating)
				{
					swap = bookmas[i];
					bookmas[i] = bookmas[j];
					bookmas[j] = swap;
				}
		}
	}
}
void search_for_a_book_by_title(book *&bookmas, int size_mas, char *str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(bookmas[i].title, str))
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		object_display(bookmas[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		book *tmp = new book[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (!strcmp(bookmas[i].title, str))
			{
				tmp[j] = bookmas[i];
				j++;
			}
		}
		sort(tmp, n, 1);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		delete[]tmp;
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void search_for_a_book_by_genre(book *&bookmas, int size_mas, char *str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(bookmas[i].genre, str))
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		object_display(bookmas[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		book *tmp = new book[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (!strcmp(bookmas[i].genre, str))
			{
				tmp[j] = bookmas[i];
				j++;
			}
		}
		sort(tmp, n, 2);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		delete[]tmp;
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void search_for_a_book_by_author(book *&bookmas, int size_mas, char *str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(bookmas[i].author, str))
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		object_display(bookmas[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		book *tmp = new book[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (!strcmp(bookmas[i].author, str))
			{
				tmp[j] = bookmas[i];
				j++;
			}
		}
		sort(tmp, n, 3);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		delete[]tmp;
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void search_for_a_book_by_rating(book *&bookmas, int size_mas, double rat)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (bookmas[i].rating == rat)
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		object_display(bookmas[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		book *tmp = new book[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (bookmas[i].rating == rat)
			{
				tmp[j] = bookmas[i];
				j++;
			}
		}
		sort(tmp, n, 4);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		delete[]tmp;
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void list_of_books_with_top_rating(book *&bookmas, int size_mas, char *str)
{
	int n = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(bookmas[i].genre, str))
		{
			n++;
		}
	}
	book * buf = new book[n];
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(bookmas[i].genre, str))
			buf[i] = bookmas[i];
	}
	float max = buf[0].rating;
	int max_i;
	book *tmp = new book[3];
	book *tmp_1 = new book[size_mas - 1];
	book *tmp_2 = new book[size_mas - 2];
	for (int i = 1; i < size_mas; i++)
	{
		if (buf[i].rating >= max)
		{
			max = buf[i].rating;
			max_i = i;
		}
	}
	if (max == 0)
	{
		system("cls");
		cout << "None of the books has a rating." << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size_mas; i++)
	{
		if (i < max_i)
			tmp_1[i] = buf[i];
		if (i > max_i)
			tmp_1[i - 1] = buf[i];
	}
	tmp[0] = buf[max_i];
	max = tmp[0].rating;
	for (int i = 1; i < size_mas - 1; i++)
	{
		if (tmp[i].rating >= max)
		{
			max = tmp[i].rating;
			max_i = i;
		}
	}
	for (int i = 0; i < size_mas - 1; i++)
	{
		if (i < max_i)
			tmp_2[i] = tmp_1[i];
		if (i > max_i)
			tmp_2[i - 1] = tmp_1[i];
	}
	tmp[1] = tmp_1[max_i];
	max = tmp_2[0].rating;
	for (int i = 1; i < size_mas - 2; i++)
	{
		if (tmp_2[i].rating >= max)
		{
			max = tmp_2[i].rating;
			max_i = i;
		}
	}
	tmp[2] = tmp_2[max_i];
	sort(tmp, 3, 4);
	system("cls");
	cout << "Top 3 books:" << endl << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 2; i >= 0; i--)
		object_display(tmp[i]);
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	delete[]tmp_1;
	delete[]tmp_2;
	delete[]tmp;
	delete[]buf;
}
void search_book_menu(int size_mas)
{
	char cho[100];
	int len = 0;
	double rating;
	while (1)
	{
		system("cls");
		cout << "Search menu" << endl;
		cout << "\t- search for a book by title (title)" << endl;
		cout << "\t- search for a book by genre (genre)" << endl;
		cout << "\t- search for a book by author (author)" << endl;
		cout << "\t- search for a book by rating (rating)" << endl;
		cout << "\t- exit" << endl << ">>> ";
		cin.getline(cho, 100);
		cin.ignore();
		len = strlen(cho);
		char * choice = new char[len + 1];
		strcpy(choice, cho);
		if (!strcmp(choice, "title"))
		{
			system("cls");
			cout << "Enter title -> ";
			cin.getline(cho, 100);
			len = strlen(cho);
			char * choice_1 = new char[len + 1];
			strcpy(choice_1, cho);
			search_for_a_book_by_title(bookmas, size_mas, choice_1);
			delete[]choice_1;
		}
		else if (!strcmp(choice, "genre"))
		{
			system("cls");
			cout << "Enter genre -> ";
			cin.getline(cho, 100);
			len = strlen(cho);
			char * choice_1 = new char[len + 1];
			strcpy(choice_1, cho);
			search_for_a_book_by_genre(bookmas, size_mas, choice_1);
			delete[]choice_1;
		}
		else if (!strcmp(choice, "author"))
		{
			system("cls");
			cout << "Enter author -> ";
			cin.getline(cho, 100);
			len = strlen(cho);
			char * choice_1 = new char[len + 1];
			strcpy(choice_1, cho);
			search_for_a_book_by_author(bookmas, size_mas, choice_1);
			delete[]choice_1;
		}
		else if (!strcmp(choice, "rating"))
		{
			system("cls");
			cout << "Enter rating -> ";
			cin >> rating;
			search_for_a_book_by_rating(bookmas, size_mas, rating);
		}
		else if (!strcmp(choice, "exit"))
		{
			delete[]choice;
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
		delete[]choice;
	}
}
void issuing_a_book(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader)
{
	for (int i = 0; i < size_mas_b; i++)
	{
		if (bookmas[i].ID == id_book)
		{
			bookmas[i].status = 0;
			break;
		}
	}
	for (int i = 0; i < size_mas_r; i++)
	{
		if (readermas[i].ID == id_reader)
		{
			readermas[i].Time = time(0);
			break;
		}
	}
}
int return_the_book(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader, float rat)
{
	int Time_end = time(0);
	for (int i = 0; i < size_mas_b; i++)
	{
		if (bookmas[i].ID == id_book)
		{
			bookmas[i].status = 1;
			bookmas[i].rating = (bookmas[i].rating + rat) / 2 - 0.25;
			break;
		}
	}
	for (int i = 0; i < size_mas_r; i++)
	{
		if (readermas[i].ID == id_reader)
		{
			readermas[i].number_of_books_read += 1;
			return Time_end - readermas[i].Time;
		}
	}
}
int accrued_debt(int Time)
{
	int days = Time % 60;
	if (days > 5)
	{
		days = days - 5;
		return 10 * days;
	}
	else
		return 0;
}
void amount_of_accrued_interest(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader)
{
	float rat;
	system("cls");
	cout << "Enter a grade for the book(1-10) -> ";
	cin >> rat;
	int Time = return_the_book(bookmas, readermas, size_mas_b, size_mas_r, id_book, id_reader, rat);
	if (Time > 300)
	{
		system("cls");
		cout << "Accrued debts -> " << accrued_debt(Time) << " hryvnias." << endl;
		system("pause");
	}
}
void information_on_books_held_by_readers(book*bookmas, int size_mas)
{
	int n = 0;
	system("cls");
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size_mas; i++)
	{
		if (bookmas[i].status == 0)
		{
			object_display(bookmas[i]);
			n = 1;
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	if (n == 0)
	{
		system("cls");
		cout << "All books are currently in the library." << endl;
	}
	system("pause");
}
void save(book *bookmas, reader *readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader)
{
	FILE*f = fopen("Library.bin", "wb");
	if (f)
	{
		fwrite(&id_book, sizeof(int), 1, f);
		fwrite(&size_mas_b, sizeof(int), 1, f);
		fwrite(bookmas, sizeof(book), size_mas_b, f);
		fwrite(&id_reader, sizeof(int), 1, f);
		fwrite(&size_mas_r, sizeof(int), 1, f);
		fwrite(readermas, sizeof(reader), size_mas_r, f);
		fclose(f);
	}
}
void load(book *&bookmas, reader *&readermas, int &size_mas_b, int &size_mas_r, int &id_book, int &id_reader)
{
	FILE*f = fopen("Library.bin", "rb");
	if (f)
	{
		if (size_mas_b)
			delete[]bookmas;
		fread(&id_book, sizeof(int), 1, f);
		fread(&size_mas_b, sizeof(int), 1, f);
		bookmas = new book[size_mas_b];
		fread(bookmas, sizeof(book), size_mas_b, f);
		if (size_mas_r)
			delete[]readermas;
		fread(&id_reader, sizeof(int), 1, f);
		fread(&size_mas_r, sizeof(int), 1, f);
		readermas = new reader[size_mas_r];
		fread(readermas, sizeof(reader), size_mas_r, f);
		fclose(f);
	}
}
void book_menu(book *bookmas, reader *readermas, int size_mas_b, int size_mas_r, int ID_b)
{
	while (1)
	{
		char cho[100];
		int len;
		system("cls");
		cout << "Book" << endl;
		cout << "\t- add book (add)" << endl;
		cout << "\t- remove book (remove)" << endl;
		cout << "\t- editing" << endl;
		cout << "\t- search" << endl;
		cout << "\t- show all available books (show)" << endl;
		cout << "\t- issuing a book (issuing)" << endl;
		cout << "\t- return the book (return)" << endl;
		cout << "\t- display information about books held by readers (display)" << endl;
		cout << "\t- exit" << endl << ">>> ";
		cin.getline(cho, 100);
		len = strlen(cho);
		char * choice_1 = new char[len + 1];
		strcpy(choice_1, cho);
		if (!strcmp(choice_1, "add"))
		{
			add_book(bookmas, size_mas_b, ID_b);
		}
		else if (!strcmp(choice_1, "remove"))
		{
			system("cls");
			delete_last_book(bookmas, size_mas_b, ID_b);
			system("pause");
		}
		else if (!strcmp(choice_1, "editing"))
		{
			int id_book;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			menu_editing(bookmas, size_mas_b, id_book);
		}
		else if (!strcmp(choice_1, "search"))
		{
			search_book_menu(size_mas_b);
		}
		else if (!strcmp(choice_1, "show"))
		{
			system("cls");
			information_about_books_that_are_in_the_library(bookmas, size_mas_b);
			system("pause");
		}
		else if (!strcmp(choice_1, "issuing"))
		{
			int id_book, id_reader;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			issuing_a_book(bookmas, readermas, size_mas_b, size_mas_r, id_book, id_reader);
		}
		else if (!strcmp(choice_1, "return"))
		{
			int id_book, id_reader;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			amount_of_accrued_interest(bookmas, readermas, size_mas_b, size_mas_r, id_book, id_reader);
		}
		else if (!strcmp(choice_1, "display"))
		{
			system("cls");
			information_on_books_held_by_readers(bookmas, size_mas_b);
		}
		else if (!strcmp(choice_1, "exit"))
		{
			delete[]choice_1;
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
		delete[]choice_1;
	}
}