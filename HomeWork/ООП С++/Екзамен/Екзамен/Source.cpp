#include"Menu.h"
int main()
{
	Menu M;
	M.SetColorBgTex(5, 7);
	vector<Reader> readermas;
	vector<Book> bookmas;
	fstream fs;
	int id_r = 1;
	int id_b = 1;
	string choice;
	fs.open("library.bin.bin", ios::in | ios::binary);
	M.load(fs, bookmas, readermas, id_b, id_r);
	fs.close();
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
		getline(cin, choice);
		if (!choice.compare("book"))
		{
			M.book_menu(bookmas, readermas, id_b);
		}
		else if (!choice.compare("reader"))
		{
			M.reader_menu(readermas, id_r);
		}
		else if (!choice.compare("information book"))
		{
			system("cls");
			cout << "Enter genre -> ";
			getline(cin, choice);
			M.list_of_books_with_top_rating(bookmas, choice);
		}
		else if (!choice.compare("information reader"))
		{
			M.information_output_on_screen_about_the_most_active_readers(readermas);
		}
		else if (!choice.compare("exit"))
		{
			fs.open("Library.bin.bin", ios::out | ios::binary);
			M.save(fs, bookmas, readermas, id_b, id_r);
			fs.close();
			break;
		}
		else
		{
			system("cls");
			cout << "Entering wrong data. Try again." << endl;
			system("pause");
		}
	}
	system("pause");
}