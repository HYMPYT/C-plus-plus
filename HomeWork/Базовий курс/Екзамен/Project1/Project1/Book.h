#pragma once
#include"Reader.h"
struct book
{
	char date_of_publication[20];
	char title[50];
	char author[100];
	char genre[100];
	float price;
	float rating = 0;
	int ID;
	int status = 1;
};
extern book *bookmas;
void object_display(book A);
void information_about_books_that_are_in_the_library(book * bookmas, int size_mas);
void fill_book(book &obj);
void add_book(book *&bookmas, int &size_mas, int &id);
void delete_last_book(book *&bookmas, int &size_mas, int &id);
int find_by_id(book*&bookmas, int &size_mas, int id);
void menu_editing(book *&bookmas, int size_mas, int id);
void sort(book *&bookmas, int size_mas, int type);
void search_for_a_book_by_title(book *&bookmas, int size_mas, char *str);
void search_for_a_book_by_genre(book *&bookmas, int size_mas, char *str);
void search_for_a_book_by_author(book *&bookmas, int size_mas, char *str);
void search_for_a_book_by_rating(book *&bookmas, int size_mas, double rat);
void list_of_books_with_top_rating(book *&bookmas, int size_mas, char *str);
void search_book_menu(int size_mas);
void issuing_a_book(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader);
int return_the_book(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader, float rat);
int accrued_debt(int Time);
void amount_of_accrued_interest(book*&bookmas, reader*&readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader);
void information_on_books_held_by_readers(book*bookmas, int size_mas);
void save(book *bookmas, reader *readermas, int size_mas_b, int size_mas_r, int id_book, int id_reader);
void load(book *&bookmas, reader *&readermas, int &size_mas_b, int &size_mas_r, int &id_book, int &id_reader);
void book_menu(book *bookmas, reader *readermas, int size_mas_b, int size_mas_r, int ID_b);