#include "Menu.h"
void Menu::menu_editing_reader(vector<Reader>& reader_v, int id)
{
	string tmp;
	int k = find_by_id_reader(reader_v, id);
	if (k != -1)
	{
		while (1)
		{
			system("cls");
			cout << "Editing menu" << endl;
			cout << "\t- full editing (full)" << endl;
			cout << "\t- partial editing (partial)" << endl;
			cout << "\t- exit" << endl << ">>> ";
			getline(cin, tmp);
			if (!tmp.compare("full"))
			{
				fill_reader(reader_v[k]);
			}
			else if (!tmp.compare("partial"))
			{
				while (1)
				{
					system("cls");
					cout << "Partial editing" << endl;
					cout << "\t- surname" << endl;
					cout << "\t- name" << endl;
					cout << "\t- patronymic" << endl;
					cout << "\t- date" << endl;
					cout << "\t- passport ID (ID)" << endl;
					cout << "\t- exit" << endl << ">>> ";
					getline(cin, tmp);
					if (!tmp.compare("surname"))
					{
						system("cls");
						cout << "Enter surname -> ";
						getline(cin, tmp);
						reader_v[k].setSurname(tmp);
					}
					else if (!tmp.compare("name"))
					{
						system("cls");
						cout << "Enter name -> ";
						getline(cin, tmp);
						reader_v[k].setName(tmp);
					}
					else if (!tmp.compare("patronymic"))
					{
						system("cls");
						cout << "Enter patronymic -> ";
						getline(cin, tmp);
						reader_v[k].setPatronymic(tmp);
					}
					else if (!tmp.compare("date"))
					{
						system("cls");
						cout << "Enter date of birth -> ";
						getline(cin, tmp);
						reader_v[k].setDateOfBirth(tmp);
					}
					else if (!tmp.compare("ID"))
					{
						system("cls");
						int passport;
						cout << "Enter passport ID -> ";
						cin >> passport;
						reader_v[k].setPassport_ID(passport);
					}
					else if (!tmp.compare("exit"))
					{
						break;
					}
					else
					{
						system("cls");
						cout << "Entering wrong data. Try again." << endl;
						system("pause");
					}
				}
			}
			else if (tmp.compare("exit"))
			{
				break;
			}
			else
			{
				system("cls");
				cout << "Entering wrong data. Try again." << endl;
				system("pause");
			}
		}
	}
}
void Menu::search_reader_menu(vector<Reader>& reader_v)
{
	string tmp;
	int num;
	while (1)
	{
		system("cls");
		cout << "Search menu" << endl;
		cout << "\t- search for a reader by SNP (SNP)" << endl;
		cout << "\t- search for a reader by number of books read (number)" << endl;
		cout << "\t- search for a reader by ID (ID)" << endl;
		cout << "\t- search for a reader by passport ID (passport)" << endl;
		cout << "\t- exit" << endl << ">>> ";
		getline(cin, tmp);
		if (!tmp.compare("SNP"))
		{
			system("cls");
			string choice_1, choice_2, choice_3;
			cout << "Enter sourname -> ";
			getline(cin, choice_1);
			cout << "Enter name -> ";
			getline(cin, choice_2);
			cout << "Enter patronymic -> ";
			getline(cin, choice_3);
			search_for_a_reader_by_SNP(reader_v, choice_1, choice_2, choice_3);
		}
		else if (!tmp.compare("number"))
		{
			system("cls");
			cout << "Enter number of books read -> ";
			cin >> num;
			search_for_a_reader_by_number_of_books_read(reader_v, num);
		}
		else if (!tmp.compare("ID"))
		{
			system("cls");
			cout << "Enter ID -> ";
			cin >> num;
			search_for_a_reader_by_ID(reader_v, num);
		}
		else if (!tmp.compare("passport"))
		{
			system("cls");
			cout << "Enter passport ID -> ";
			cin >> num;
			search_for_a_reader_by_passport_ID(reader_v, num);
		}
		else if (!tmp.compare("exit"))
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
	}
}
void Menu::reader_menu(vector<Reader> &reader_v, int &ID_r)
{
	string tmp;
	while (1)
	{
		system("cls");
		cout << "Reader" << endl;
		cout << "\t- add reader (add)" << endl;
		cout << "\t- remove reader (remove)" << endl;
		cout << "\t- editing" << endl;
		cout << "\t- search" << endl;
		cout << "\t- show all readers (show)" << endl;
		cout << "\t- conclusion overdue reader information date of return of the book (conclusion)" << endl;
		cout << "\t- exit" << endl << ">>> ";
		getline(cin, tmp);
		if (!tmp.compare("add"))
		{
			add_reader(reader_v, ID_r);
		}
		else if (!tmp.compare("remove"))
		{
			system("cls");
			delete_last_reader(reader_v, ID_r);
			system("pause");
		}
		else if (!tmp.compare("editing"))
		{
			int id_reader;
			system("cls");
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			menu_editing_reader(reader_v, id_reader);
			system("pause");
		}
		else if (!tmp.compare("search"))
		{
			search_reader_menu(reader_v);
			system("pause");
		}
		else if (!tmp.compare("show"))
		{
			system("cls");
			information_about_library_readers(reader_v);
			system("pause");
		}
		else if (!tmp.compare("conclusion"))
		{
			system("cls");
			expired_reader_information_date_of_return_of_the_book(reader_v);
			system("pause");
		}
		else if (!tmp.compare("exit"))
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
	}
}
//=================================================================================
void Menu::menu_editing(vector<Book>& book_v, int id)
{
	string tmp;
	int k = find_by_id(book_v, id);
	if (k != -1)
	{
		while (1)
		{
			system("cls");
			cout << "Editing menu" << endl;
			cout << "\t- full editing (full)" << endl;
			cout << "\t- partial editing (partial)" << endl;
			cout << "\t- exit" << endl << ">>> ";
			getline(cin, tmp);
			if (!tmp.compare("full"))
			{
				fill_book(book_v[k]);
			}
			else if (!tmp.compare("partial"))
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
					getline(cin, tmp);
					if (!tmp.compare("title"))
					{
						system("cls");
						cout << "Enter a book title -> ";
						getline(cin, tmp);
						book_v[k].setTitle(tmp);
					}
					else if (!tmp.compare("author"))
					{
						system("cls");
						cout << "Enter author -> ";
						getline(cin, tmp);
						book_v[k].setAuthor(tmp);
					}
					else if (!tmp.compare("genre"))
					{
						system("cls");
						cout << "Enter genre -> ";
						getline(cin, tmp);
						book_v[k].setGenre(tmp);
					}
					else if (!tmp.compare("price"))
					{
						system("cls");
						int price;
						cout << "Enter price -> ";
						cin >> price;
						book_v[k].setPrice(price);
					}
					else if (!tmp.compare("rating"))
					{
						system("cls");
						int rating;
						cout << "Enter popularity rating -> ";
						cin >> rating;
						book_v[k].setRating(rating);
					}
					else if (!tmp.compare("date"))
					{
						system("cls");
						cout << "Enter date of publication -> ";
						getline(cin, tmp);
						book_v[k].setDateOfPublication(tmp);
					}
					else if (!tmp.compare("exit"))
					{
						break;
					}
					else
					{
						system("cls");
						cout << "Entering wrong data. Try again." << endl;
						system("pause");
					}
				}
			}
			else if (!tmp.compare("exit"))
			{
				break;
			}
			else
			{
				system("cls");
				cout << "Entering wrong data. Try again." << endl;
				system("pause");
			}
		}
	}
}
void Menu::search_book_menu(vector<Book> book_v)
{
	string tmp;
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
		getline(cin, tmp);
		if (!tmp.compare("title"))
		{
			system("cls");
			cout << "Enter title -> ";
			getline(cin, tmp);
			search_for_a_book_by_title(book_v, tmp);
		}
		else if (!tmp.compare("genre"))
		{
			system("cls");
			cout << "Enter genre -> ";
			getline(cin, tmp);
			search_for_a_book_by_genre(book_v, tmp);
		}
		else if (!tmp.compare("author"))
		{
			system("cls");
			cout << "Enter author -> ";
			getline(cin, tmp);
			search_for_a_book_by_author(book_v, tmp);
		}
		else if (!tmp.compare("rating"))
		{
			system("cls");
			cout << "Enter rating -> ";
			cin >> rating;
			search_for_a_book_by_rating(book_v, rating);
		}
		else if (!tmp.compare("exit"))
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
	}
}
void Menu::book_menu(vector<Book> &book_v, vector<Reader> &reader_v, int &ID_b)
{
	while (1)
	{
		string tmp;
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
		getline(cin, tmp);
		if (!tmp.compare("add"))
		{
			add_book(book_v, ID_b);
		}
		else if (!tmp.compare("remove"))
		{
			system("cls");
			delete_last_book(book_v, ID_b);
			system("pause");
		}
		else if (!tmp.compare("editing"))
		{
			int id_book;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			cin.ignore();
			menu_editing(book_v, id_book);
		}
		else if (!tmp.compare("search"))
		{
			search_book_menu(book_v);
		}
		else if (!tmp.compare("show"))
		{
			system("cls");
			information_about_books_that_are_in_the_library(book_v);
			system("pause");
		}
		else if (!tmp.compare("issuing"))
		{
			int id_book, id_reader;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			issuing_a_book(book_v, reader_v, id_book, id_reader);
		}
		else if (!tmp.compare("return"))
		{
			int id_book, id_reader;
			system("cls");
			cout << "Enter the id of the book -> ";
			cin >> id_book;
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			amount_of_accrued_interest(book_v, reader_v, id_book, id_reader);
		}
		else if (!tmp.compare("display"))
		{
			system("cls");
			information_on_books_held_by_readers(book_v);
		}
		else if (!tmp.compare("exit"))
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
	}
}
//=================================================================================
void Menu::SetColorBgTex(int Bg, int Tex)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}