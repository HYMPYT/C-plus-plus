#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<fstream>
using namespace std;
class Reader
{
	string surname;
	string name;
	string patronymic;
	string date_of_birth;
	int passport_ID;
	int ID;
	int number_of_books_read = 0;
	int Time;
public:
	Reader() = default;
	Reader(const string&s, const string&n, const string& p, const string&dob, int pass_id);
	Reader(const Reader&obj);
	Reader(Reader &&obj);
	~Reader() = default;

	const string& getSurname()const;
	void setSurname(const string&s);
	const string& getName()const;
	void setName(const string&n);
	const string& getPatronymic()const;
	void setPatronymic(const string&p);
	const string& getDateOfBirth()const;
	void setDateOfBirth(const string&d);
	int getPassport_ID()const;
	void setPassport_ID(int val);
	int getID()const;
	void setID(int val);
	int getNumberOfBooksRead();
	void setNumberOfBooksRead(int val);
	int getTime()const;
	void setTime(int val);
	Reader&operator=(const Reader&obj);
	Reader&operator=(Reader&&obj);

	void object_display(Reader obj);
	void information_about_library_readers(vector<Reader> reader_v);
	void fill_reader(Reader &obj);
	void add_reader(vector<Reader> &reader_v, int &id);
	void delete_last_reader(vector<Reader> &reader_v, int &id);
	int find_by_id_reader(vector<Reader> &reader_v, int id);
	//void menu_editing_reader(vector<Reader> &reader_v, int id);
	void sort_reader(vector<Reader> &reader_v, int type);
	void search_for_a_reader_by_SNP(vector<Reader> &reader_v, const string& str_1, const string&str_2, const string&str_3);
	void search_for_a_reader_by_number_of_books_read(vector<Reader> &reader_v, int num);
	void search_for_a_reader_by_ID(vector<Reader> &reader_v, int id);
	void search_for_a_reader_by_passport_ID(vector<Reader> &reader_v, int p_id);
	void information_output_on_screen_about_the_most_active_readers(vector<Reader> &reader_v);
	//void search_reader_menu(vector<Reader> &reader_v);
	int number_of_days_and_debt(int Time, int type);
	void expired_reader_information_date_of_return_of_the_book(vector<Reader> &reader_v);
	//void reader_menu(vector<Reader> reader_v, int ID_r);
};