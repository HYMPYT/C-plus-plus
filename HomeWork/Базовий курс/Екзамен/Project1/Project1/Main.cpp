#include"Book.h"
int main()
{
	SetColorBgTex(5, 7);
	int size_r = 0;
	int size_b = 0;
	int id_r = 1;
	int id_b = 1;
	char ch[100];
	int len = 0;
	load(bookmas, readermas, size_b, size_r, id_b, id_r);
	SetConsWinSize(110, 40);
	SetConsCurPos(45, 15);
	cout << "WELCOME TO THE LIBRARY!" << endl;
	_getch();
	while (1)
	{
		system("cls");
		cout << "Library" << endl;
		cout << "\t- book" << endl;
		cout << "\t- reader" << endl;
		cout << "\t- information about the most popular books in their genre (information book)" << endl;
		cout << "\t- information about the most active readers (information reader)" << endl;
		cout << "\t- exit" << endl << ">>> ";
		cin.getline(ch, 100);
		len = strlen(ch);
		char * choice = new char[len + 1];
		strcpy(choice, ch);
		if (!strcmp(choice, "book"))
		{
			book_menu(bookmas, readermas, size_b, size_r, id_b);
		}
		else if (!strcmp(choice, "reader"))
		{
			reader_menu(readermas, size_r, id_r);
		}
		else if (!strcmp(choice, "information book"))
		{
			system("cls");
			cout << "Enter genre -> ";
			cin.getline(ch, 100);
			len = strlen(ch);
			char * choice_1 = new char[len + 1];
			strcpy(choice_1, ch);
			list_of_books_with_top_rating(bookmas, size_b, choice_1);
			delete[]choice_1;
		}
		else if (!strcmp(choice, "information reader"))
		{
			information_output_on_screen_about_the_most_active_readers(readermas, size_r);
		}
		else if (!strcmp(choice, "exit"))
		{
			delete[]choice;
			save(bookmas, readermas, size_b, size_r, id_b, id_r);
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
	system("pause");
}