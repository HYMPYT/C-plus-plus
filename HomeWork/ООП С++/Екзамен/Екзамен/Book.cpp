#include"Book.h"
Book::Book(const string&dop, const string&t, const string&a, const string&g, float p)
{
	date_of_publication = dop;
	title = t;
	author = a;
	genre = g;
	price = p;
}
Book::Book(const Book&obj)
{
	date_of_publication = obj.date_of_publication;
	title = obj.title;
	author = obj.author;
	genre = obj.genre;
	price = obj.price;
	rating = obj.rating;
	ID = obj.ID;
	status = obj.status;
}
Book::Book(Book&&obj)
{
	date_of_publication = obj.date_of_publication;
	title = obj.title;
	author = obj.author;
	genre = obj.genre;
	price = obj.price;
	rating = obj.rating;
	ID = obj.ID;
	status = obj.status;
	obj.date_of_publication = nullptr;
	obj.title = nullptr;
	obj.author = nullptr;
	obj.genre = nullptr;
	obj.price = 0;
	obj.rating = 0;
	obj.ID = 0;
	obj.status = 0;
}
//====================================================================================
const string& Book::getDateOfPublication()const
{
	return date_of_publication;
}
void Book::setDateOfPublication(const string& dop)
{
	date_of_publication = dop;
}
const string& Book::getTitle()const
{
	return title;
}
void Book::setTitle(const string& t)
{
	title = t;
}
const string& Book::getAuthor()const
{
	return author;
}
void Book::setAuthor(const string& a)
{
	author = a;
}
const string& Book::getGenre()const
{
	return genre;
}
void Book::setGenre(const string& g)
{
	genre = g;
}
float Book::getPrice()const
{
	return price;
}
void Book::setPrice(float p)
{
	price = p;
}
float Book::getRating()const
{
	return rating;
}
void Book::setRating(float r)
{
	rating = r;
}
int Book::getID()const
{
	return ID;
}
int Book::getStatus()const
{
	return status;
}
void Book::setStatus(int s)
{
	status = s;
}
Book& Book::operator=(const Book& obj)
{
	if (this == &obj)
		return *this;
	date_of_publication = obj.date_of_publication;
	title = obj.title;
	author = obj.author;
	genre = obj.genre;
	price = obj.price;
	rating = obj.rating;
	ID = obj.ID;
	status = obj.status;
	return *this;
}
Book& Book::operator=(Book&&obj)
{
	if (this == &obj)
		return *this;
	date_of_publication = obj.date_of_publication;
	title = obj.title;
	author = obj.author;
	genre = obj.genre;
	price = obj.price;
	rating = obj.rating;
	ID = obj.ID;
	status = obj.status;
	obj.date_of_publication = nullptr;
	obj.title = nullptr;
	obj.author = nullptr;
	obj.genre = nullptr;
	obj.price = 0;
	obj.rating = 0;
	obj.ID = 0;
	obj.status = 0;
	return *this;

}
//====================================================================================
void Book::object_display(Book obj)
{
	cout << "| " << setw(2) << obj.ID << " | ";
	cout << setw(40) << obj.title << " | ";
	cout << setw(20) << obj.author << " | ";
	cout << setw(10) << obj.genre << " | ";
	cout << setw(17) << obj.date_of_publication << " | ";
	cout << setw(5) << obj.price << " | ";
	cout << setw(6) << obj.rating << " |" << endl;
}
void Book::information_about_books_that_are_in_the_library(vector<Book> book_v)
{
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (auto i = book_v.begin(); i != book_v.end(); i++)
	{
		if ((*i).status == 1)
			object_display(*i);
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Book::fill_book(Book &obj)
{
	system("cls");
	cout << "Enter a book title -> ";
	getline(cin, obj.title);
	cout << "Enter author -> ";
	getline(cin, obj.author);
	cout << "Enter genre -> ";
	getline(cin, obj.genre);
	cout << "Enter price -> ";
	cin >> obj.price;
	cout << "Enter date of publication -> ";
	cin >> obj.date_of_publication;
}
void Book::add_book(vector<Book> &book_v, int &id)
{
	Book tmp;
	fill_book(tmp);
	tmp.ID = id++;
	book_v.push_back(tmp);
}
void Book::delete_last_book(vector<Book> &book_v, int &id)
{
	book_v.pop_back();
	id = id - 1;
	cout << "Deletion was successful." << endl;
}
int Book::find_by_id(vector<Book> &book_v, int id)
{
	int counter = 0;
	for (auto i = book_v.begin(); i != book_v.end(); i++)
	{
		if ((*i).ID == id)
			return counter;
		counter++;
	}
	return -1;
}
//void Book::menu_editing(vector<Book> &book_v, int id)
//{
//	string tmp;
//	int k = find_by_id(book_v, id);
//	if (k != -1)
//	{
//		while (1)
//		{
//			system("cls");
//			cout << "Editing menu" << endl;
//			cout << "\t- full editing (full)" << endl;
//			cout << "\t- partial editing (partial)" << endl;
//			cout << "\t- exit" << endl << ">>> ";
//			getline(cin, tmp);
//			if (!tmp.compare("full"))
//			{
//				fill_book(book_v[k]);
//			}
//			else if (!tmp.compare("partial"))
//			{
//				while (1)
//				{
//					system("cls");
//					cout << "Partial editing" << endl;
//					cout << "\t- title" << endl;
//					cout << "\t- author" << endl;
//					cout << "\t- genre" << endl;
//					cout << "\t- price" << endl;
//					cout << "\t- rating" << endl;
//					cout << "\t- date" << endl;
//					cout << "\t- exit" << endl << ">>> ";
//					getline(cin, tmp);
//					if (!tmp.compare("title"))
//					{
//						system("cls");
//						cout << "Enter a book title -> ";
//						getline(cin, book_v[k].title);
//					}
//					else if (!tmp.compare("author"))
//					{
//						system("cls");
//						cout << "Enter author -> ";
//						getline(cin, book_v[k].author);
//					}
//					else if (!tmp.compare("genre"))
//					{
//						system("cls");
//						cout << "Enter genre -> ";
//						getline(cin, book_v[k].genre);
//					}
//					else if (!tmp.compare("price"))
//					{
//						system("cls");
//						cout << "Enter price -> ";
//						cin >> book_v[k].price;
//					}
//					else if (!tmp.compare("rating"))
//					{
//						system("cls");
//						cout << "Enter popularity rating -> ";
//						cin >> book_v[k].rating;
//					}
//					else if (!tmp.compare("date"))
//					{
//						system("cls");
//						cout << "Enter date of publication -> ";
//						cin >> book_v[k].date_of_publication;
//					}
//					else if (!tmp.compare("exit"))
//					{
//						break;
//					}
//					else
//					{
//						system("cls");
//						cout << "Entering wrong data. Try again." << endl;
//						system("pause");
//					}
//				}
//			}
//			else if (!tmp.compare("exit"))
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Entering wrong data. Try again." << endl;
//				system("pause");
//			}
//		}
//	}
//}
void Book::sort(vector<Book> &book_v, int type)
{
	if (type == 1)
	{
		Book swap;
		for (int i = 0; i < book_v.size(); i++)
		{
			for (int j = i + 1; j < book_v.size(); j++)
				if (book_v[i].title.compare(book_v[j].title) > 0)
				{
					swap = book_v[i];
					book_v[i] = book_v[j];
					book_v[j] = swap;
				}
		}
	}
	if (type == 2)
	{
		Book swap;
		for (int i = 0; i < book_v.size(); i++)
		{
			for (int j = i + 1; j < book_v.size(); j++)
				if (book_v[i].rating > book_v[j].rating)
				{
					swap = book_v[i];
					book_v[i] = book_v[j];
					book_v[j] = swap;
				}
		}
	}
	if (type == 3)
	{
		Book swap;
		for (int i = 0; i < book_v.size(); i++)
		{
			for (int j = i + 1; j < book_v.size(); j++)
				if (book_v[i].author.compare(book_v[j].author) > 0)
				{
					swap = book_v[i];
					book_v[i] = book_v[j];
					book_v[j] = swap;
				}
		}
	}
	if (type == 4)
	{
		Book swap;
		for (int i = 0; i < book_v.size(); i++)
		{
			for (int j = i + 1; j < book_v.size(); j++)
				if (book_v[i].rating > book_v[j].rating)
				{
					swap = book_v[i];
					book_v[i] = book_v[j];
					book_v[j] = swap;
				}
		}
	}
}
void Book::search_for_a_book_by_title(vector<Book> &book_v, const string&str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < book_v.size(); i++)
	{
		if (!book_v[i].title.compare(str))
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
		object_display(book_v[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Book> tmp;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
		{
			if (!(*i).title.compare(str))
			{
				tmp.push_back(*i);
			}
		}
		sort(tmp, 1);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
			object_display(*i);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		tmp.clear();
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void Book::search_for_a_book_by_genre(vector<Book> &book_v, const string&str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < book_v.size(); i++)
	{
		if (!book_v[i].genre.compare(str))
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
		object_display(book_v[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Book> tmp;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
		{
			if (!(*i).genre.compare(str))
			{
				tmp.push_back(*i);
			}
		}
		sort(tmp, 2);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
			object_display(*i);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		tmp.clear();
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void Book::search_for_a_book_by_author(vector<Book> &book_v, const string&str)
{
	int n = 0, ind = 0;
	for (int i = 0; i < book_v.size(); i++)
	{
		if (!book_v[i].author.compare(str))
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
		object_display(book_v[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Book> tmp;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
		{
			if (!(*i).author.compare(str))
			{
				tmp.push_back(*i);
			}
		}
		sort(tmp, 3);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
			object_display(*i);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		tmp.clear();
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void Book::search_for_a_book_by_rating(vector<Book> &book_v, double rat)
{
	int n = 0, ind = 0;
	for (int i = 0; i < book_v.size(); i++)
	{
		if (book_v[i].rating == rat)
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
		object_display(book_v[ind]);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Book> tmp;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
		{
			if ((*i).rating == rat)
			{
				tmp.push_back(*i);
			}
		}
		sort(tmp, 4);
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = book_v.begin(); i != book_v.end(); i++)
			object_display(*i);
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
		tmp.clear();
	}
	else
	{
		system("cls");
		cout << "Invalid data entered, please try again!" << endl;
		system("pause");
	}
}
void Book::list_of_books_with_top_rating(vector<Book> &book_v, const string&str)
{
	vector<Book> buf;
	float max = book_v[0].rating;
	int max_i;
	for (int i = 1; i < book_v.size(); i++)
	{
		if (!book_v[i].genre.compare(str))
		{
			buf.push_back(book_v[i]);
		}
	}
	for (int i = 0; i < buf.size(); i++)
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
		buf.clear();
		return;
	}
	vector<Book> tmp;
	vector<Book> tmp_1;
	for (int i = 0; i < buf.size(); i++)
	{
		if (i == max_i)
			continue;
		tmp.push_back(buf[i]);
	}
	tmp_1.push_back(buf[max_i]);
	max = tmp[0].rating;
	for (int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i].rating >= max)
		{
			max = tmp_1[i].rating;
			max_i = i;
		}
	}
	buf.clear();
	buf.shrink_to_fit();
	for (int i = 0; i < tmp.size(); i++)
	{
		if (i == max_i)
			continue;
		buf.push_back(tmp[i]);
	}
	tmp_1[1] = tmp[max_i];
	max = buf[0].rating;
	for (int i = 1; i < buf.size(); i++)
	{
		if (buf[i].rating >= max)
		{
			max = buf[i].rating;
			max_i = i;
		}
	}
	tmp_1[2] = buf[max_i];
	sort(tmp_1, 4);
	system("cls");
	cout << "Top 3 books:" << endl << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = tmp_1.size()-1; i >= 0; i--)
		object_display(tmp_1[i]);
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
}
//void Book::search_book_menu(vector<Book> book_v)
//{
//	string tmp;
//	double rating;
//	while (1)
//	{
//		system("cls");
//		cout << "Search menu" << endl;
//		cout << "\t- search for a book by title (title)" << endl;
//		cout << "\t- search for a book by genre (genre)" << endl;
//		cout << "\t- search for a book by author (author)" << endl;
//		cout << "\t- search for a book by rating (rating)" << endl;
//		cout << "\t- exit" << endl << ">>> ";
//		getline(cin, tmp);
//		if (!tmp.compare("title"))
//		{
//			system("cls");
//			cout << "Enter title -> ";
//			getline(cin, tmp);
//			search_for_a_book_by_title(book_v, tmp);
//		}
//		else if (!tmp.compare("genre"))
//		{
//			system("cls");
//			cout << "Enter genre -> ";
//			getline(cin, tmp);
//			search_for_a_book_by_genre(book_v, tmp);
//		}
//		else if (!tmp.compare("author"))
//		{
//			system("cls");
//			cout << "Enter author -> ";
//			getline(cin, tmp);
//			search_for_a_book_by_author(book_v, tmp);
//		}
//		else if (!tmp.compare("rating"))
//		{
//			system("cls");
//			cout << "Enter rating -> ";
//			cin >> rating;
//			search_for_a_book_by_rating(book_v, rating);
//		}
//		else if (!tmp.compare("exit"))
//		{
//			break;
//		}
//		else
//		{
//			system("cls");
//			cout << "Entering wrong data. Try again." << endl;
//			system("pause");
//		}
//	}
//}
void Book::issuing_a_book(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader)
{
	for (int i = 0; i < book_v.size(); i++)
	{
		if (book_v[i].ID == id_book)
		{
			book_v[i].setStatus(0);
			break;
		}
	}
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (reader_v[i].getID() == id_reader)
		{
			reader_v[i].setTime(time(0));
			break;
		}
	}
}
int Book::return_the_book(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader, float rat)
{
	int Time_end = time(0);
	for (int i = 0; i < book_v.size(); i++)
	{
		if (book_v[i].ID == id_book)
		{
			book_v[i].setStatus(1);
			book_v[i].setRating((book_v[i].rating + rat) / 2 - 0.25);
			break;
		}
	}
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (reader_v[i].getID() == id_reader)
		{
			reader_v[i].setNumberOfBooksRead(reader_v[i].getNumberOfBooksRead() + 1);
			return Time_end - reader_v[i].getTime();
		}
	}
}
int Book::accrued_debt(int Time)
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
void Book::amount_of_accrued_interest(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader)
{
	float rat;
	system("cls");
	cout << "Enter a grade for the book(1-10) -> ";
	cin >> rat;
	int Time = return_the_book(book_v, reader_v, id_book, id_reader, rat);
	if (Time > 300)
	{
		system("cls");
		cout << "Accrued debts -> " << accrued_debt(Time) << " hryvnias." << endl;
		system("pause");
	}
}
void Book::information_on_books_held_by_readers(vector<Book> book_v)
{
	int n = 0;
	system("cls");
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |                   Title                  |        Author        |    Genre   |Date of publication| Price | Rating |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < book_v.size(); i++)
	{
		if (book_v[i].status == 0)
		{
			object_display(book_v[i]);
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
//void Book::book_menu(vector<Book> book_v, vector<Reader> reader_v, int ID_b)
//{
//	while (1)
//	{
//		string tmp;
//		system("cls");
//		cout << "Book" << endl;
//		cout << "\t- add book (add)" << endl;
//		cout << "\t- remove book (remove)" << endl;
//		cout << "\t- editing" << endl;
//		cout << "\t- search" << endl;
//		cout << "\t- show all available books (show)" << endl;
//		cout << "\t- issuing a book (issuing)" << endl;
//		cout << "\t- return the book (return)" << endl;
//		cout << "\t- display information about books held by readers (display)" << endl;
//		cout << "\t- exit" << endl << ">>> ";
//		getline(cin, tmp);
//		if (!tmp.compare("add"))
//		{
//			add_book(book_v, ID_b);
//		}
//		else if (!tmp.compare("remove"))
//		{
//			system("cls");
//			delete_last_book(book_v, ID_b);
//			system("pause");
//		}
//		else if (!tmp.compare("editing"))
//		{
//			int id_book;
//			system("cls");
//			cout << "Enter the id of the book -> ";
//			cin >> id_book;
//			cin.ignore();
//			menu_editing(book_v, id_book);
//		}
//		else if (!tmp.compare("search"))
//		{
//			search_book_menu(book_v);
//		}
//		else if (!tmp.compare("show"))
//		{
//			system("cls");
//			information_about_books_that_are_in_the_library(book_v);
//			system("pause");
//		}
//		else if (!tmp.compare("issuing"))
//		{
//			int id_book, id_reader;
//			system("cls");
//			cout << "Enter the id of the book -> ";
//			cin >> id_book;
//			cout << "Enter the id of the reader -> ";
//			cin >> id_reader;
//			issuing_a_book(book_v, reader_v, id_book, id_reader);
//		}
//		else if (!tmp.compare("return"))
//		{
//			int id_book, id_reader;
//			system("cls");
//			cout << "Enter the id of the book -> ";
//			cin >> id_book;
//			cout << "Enter the id of the reader -> ";
//			cin >> id_reader;
//			amount_of_accrued_interest(book_v, reader_v, id_book, id_reader);
//		}
//		else if (!tmp.compare("display"))
//		{
//			system("cls");
//			information_on_books_held_by_readers(book_v);
//		}
//		else if (!tmp.compare("exit"))
//		{
//			break;
//		}
//		else
//		{
//			system("cls");
//			cout << "Entering wrong data. Try again." << endl;
//			system("pause");
//		}
//	}
//}
//====================================================================================
void Book::save(fstream &fs, vector<Book> book_v, vector<Reader> reader_v, int id_book, int id_reader)
{
	int size_b = book_v.size(), size_r = reader_v.size();
	Book*bookmas = new Book[size_b];
	Reader*readermas = new Reader[size_r];
	for (int i = 0; i < size_b; i++)
	{
		bookmas[i] = book_v[i];
	}
	fs.write((char*)&id_book, sizeof(int));
	fs.write((char*)&size_b, sizeof(int));
	fs.write((char*)bookmas, sizeof(Book)*size_b);
	for (int i = 0; i < size_r; i++)
	{
		readermas[i] = reader_v[i];
	}
	fs.write((char*)&id_reader, sizeof(int));
	fs.write((char*)&size_r, sizeof(int));
	fs.write((char*)readermas, sizeof(Book)*size_r);
	delete[]bookmas;
	delete[]readermas;
}
void Book::load(fstream &fs, vector<Book> &book_v, vector<Reader> &reader_v, int &id_book, int &id_reader)
{
	if (book_v.size())
		book_v.clear();
	int size_b, size_r;
	fs.read((char*)&id_book, sizeof(int));
	fs.read((char*)&size_b, sizeof(int));
	Book*bookmas = new Book[size_b];
	fs.read((char*)bookmas, sizeof(Book)*size_b);
	for (int i = 0; i < size_b; i++)
	{
		book_v.push_back(bookmas[i]);
	}

	if (reader_v.size())
		reader_v.clear();
	fs.read((char*)&id_reader, sizeof(int));
	fs.read((char*)&size_r, sizeof(int));
	Reader*readermas = new Reader[size_r];
	fs.read((char*)readermas, sizeof(Reader)*size_r);
	for (int i = 0; i < size_r; i++)
	{
		reader_v.push_back(readermas[i]);
	}
}