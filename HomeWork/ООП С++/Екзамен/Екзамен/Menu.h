#pragma once
#include"Book.h"
class Menu : public Book, public Reader
{
public:
	Menu() = default;
	~Menu() = default;

	void menu_editing_reader(vector<Reader> &reader_v, int id);
	void search_reader_menu(vector<Reader> &reader_v);
	void reader_menu(vector<Reader> &reader_v, int &ID_r);

	void menu_editing(vector<Book> &book_v, int id);
	void search_book_menu(vector<Book> book_v);
	void book_menu(vector<Book> &book_v, vector<Reader> &reader_v, int &ID_b);

	void SetColorBgTex(int Bg = 0, int Tex = 15);
};