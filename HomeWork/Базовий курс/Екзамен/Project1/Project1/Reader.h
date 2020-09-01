#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
struct reader
{
	char surname[50];
	char name[50];
	char patronymic[50];
	char date_of_birth[20];
	int passport_ID;
	int ID;
	int number_of_books_read = 0;
	int Time;
};
extern reader *readermas;
void SetColorBgTex(int Bg = 0, int Tex = 15);
void SetConsCurPos(int x, int y);
void SetConsWinSize(int XSize, int YSize);
void object_display(reader A);
void information_about_library_readers(reader * readermas, int size_mas);
void fill_reader(reader &obj);
void add_reader(reader *&readermas, int &size, int &id);
void delete_last_reader(reader *&readermas, int &size_mas, int &id);
int find_by_id_reader(reader*&readermas, int &size_mas, int id);
void menu_editing_reader(reader *&readermas, int size_mas, int id);
void sort_reader(reader *&readermas, int size_mas, int type);
void search_for_a_reader_by_SNP(reader *&readermas, int size_mas, char *str_1, char *str_2, char *str_3);
void search_for_a_reader_by_number_of_books_read(reader *&readermas, int size_mas, int num);
void search_for_a_reader_by_ID(reader *&readermas, int size_mas, int id);
void search_for_a_reader_by_passport_ID(reader *&readermas, int size_mas, int p_id);
void information_output_on_screen_about_the_most_active_readers(reader *&readermas, int size_mas);
void search_reader_menu(int size_mas);
int number_of_days_and_debt(int Time, int type);
void expired_reader_information_date_of_return_of_the_book(reader *readermas, int size_mas);
void reader_menu(reader *readermas, int size_mas_r, int ID_r);