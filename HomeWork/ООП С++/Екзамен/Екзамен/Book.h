#pragma once
#include"Reader.h"
class Book
{
	string date_of_publication;
	string title;
	string author;
	string genre;
	float price;
	float rating = 0;
	int ID;
	int status = 1;
public:
	Book() = default;
	Book(const string&dop, const string&t, const string&a, const string&g, float p);
	Book(const Book & obj);
	Book(Book&&obj);
	~Book() = default;

	const string& getDateOfPublication()const;
	void setDateOfPublication(const string& dop);
	const string& getTitle()const;
	void setTitle(const string& t);
	const string& getAuthor()const;
	void setAuthor(const string& a);
	const string& getGenre()const;
	void setGenre(const string& g);
	float getPrice()const;
	void setPrice(float p);
	float getRating()const;
	void setRating(float r);
	int getID()const;
	int getStatus()const;
	void setStatus(int s);
	Book&operator=(const Book&obj);
	Book&operator=(Book&&obj);

	void object_display(Book obj);
	void information_about_books_that_are_in_the_library(vector<Book> book_v);
	void fill_book(Book &obj);
	void add_book(vector<Book> &book_v, int &id);
	void delete_last_book(vector<Book> &book_v, int &id);
	int find_by_id(vector<Book> &book_v, int id);
	//void menu_editing(vector<Book> &book_v, int id);
	void sort(vector<Book> &book_v, int type);
	void search_for_a_book_by_title(vector<Book> &book_v, const string&str);
	void search_for_a_book_by_genre(vector<Book> &book_v, const string&str);
	void search_for_a_book_by_author(vector<Book> &book_v, const string&str);
	void search_for_a_book_by_rating(vector<Book> &book_v, double rat);
	void list_of_books_with_top_rating(vector<Book> &book_v, const string&str);
	//void search_book_menu(vector<Book> book_v);
	void issuing_a_book(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader);
	int return_the_book(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader, float rat);
	int accrued_debt(int Time);
	void amount_of_accrued_interest(vector<Book> &book_v, vector<Reader> &reader_v, int id_book, int id_reader);
	void information_on_books_held_by_readers(vector<Book> book_v);
	//void book_menu(vector<Book> book_v, vector<Reader> reader_v, int ID_b);

	void save(fstream &fs, vector<Book> book_v, vector<Reader> reader_v, int id_book, int id_reader);
	void load(fstream &fs, vector<Book> &book_v, vector<Reader> &reader_v, int &id_book, int &id_reader);
};