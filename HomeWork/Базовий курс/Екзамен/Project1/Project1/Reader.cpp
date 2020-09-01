
#include"Reader.h"
reader *readermas = nullptr;
void SetColorBgTex(int Bg, int Tex) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}
void SetConsCurPos(int x, int y) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hConsole, coord);
}
void SetConsWinSize(int XSize = 20, int YSize = 10) 
{
	HWND hWnd = GetForegroundWindow();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = YSize;
	windowSize.Left = 0;
	windowSize.Right = XSize;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { XSize + 1, YSize + 1 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}
void object_display(reader A)
{
	cout << "| " << setw(2) << A.ID << " | ";
	cout << setw(15) << A.surname << " | ";
	cout << setw(10) << A.name << " | ";
	cout << setw(20) << A.patronymic << " | ";
	cout << setw(13) << A.date_of_birth << " | ";
	cout << setw(11) << A.passport_ID << " | ";
	cout << setw(20) << A.number_of_books_read << " |" << endl;
}
void information_about_library_readers(reader * readermas, int size_mas)
{
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size_mas; i++)
	{
		object_display(readermas[i]);
	}
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
void fill_reader(reader &obj)
{
	system("cls");
	cout << "Enter surname -> ";
	cin.getline(obj.surname, 50);
	cout << "Enter name -> ";
	cin.getline(obj.name, 50);
	cout << "Enter patronymic -> ";
	cin.getline(obj.patronymic, 50);
	cout << "Enter date of birth -> ";
	cin >> obj.date_of_birth;
	cout << "Enter passport ID -> ";
	cin >> obj.passport_ID;
}
void add_reader(reader *&readermas, int &size, int &id)
{
	if (size == 0)
		readermas = new reader[1];
	else
	{
		reader *tmp = new reader[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = readermas[i];
		}
		delete[]readermas;
		readermas = tmp;
	}
	readermas[size].ID = id++;
	fill_reader(readermas[size]);
	size++;
}
void delete_last_reader(reader *&readermas, int &size_mas, int &id)
{
	reader * tmp = new reader[--size_mas];
	for (int i = 0; i < size_mas; i++)
	{
		tmp[i] = readermas[i];
	}
	delete[]readermas;
	readermas = tmp;
	id = id - 1;
	cout << "Deletion was successful." << endl;
}
int find_by_id_reader(reader*&readermas, int &size_mas, int id)
{
	for (int i = 0; i < size_mas; i++)
	{
		if (readermas[i].ID == id)
			return i;
	}
	return -1;
}
void menu_editing_reader(reader *&readermas, int size_mas, int id)
{
	char cho[100];
	int k = find_by_id_reader(readermas, size_mas, id);
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
				fill_reader(readermas[k]);
			}
			else if (!strcmp(choice_2, "partial"))
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
					cin.getline(cho, 100);
					len = strlen(cho);
					char *choice_3 = new char[len + 1];
					strcpy(choice_3, cho);
					if (!strcmp(choice_3, "surname"))
					{
						system("cls");
						cout << "Enter surname -> ";
						cin.getline(readermas[k].surname, 50);
					}
					else if (!strcmp(choice_3, "name"))
					{
						system("cls");
						cout << "Enter name -> ";
						cin.getline(readermas[k].name, 50);
					}
					else if (!strcmp(choice_3, "patronymic"))
					{
						system("cls");
						cout << "Enter patronymic -> ";
						cin.getline(readermas[k].patronymic, 50);
					}
					else if (!strcmp(choice_3, "date"))
					{
						system("cls");
						cout << "Enter date of birth -> ";
						cin >> readermas[k].date_of_birth;
					}
					else if (!strcmp(choice_3, "ID"))
					{
						system("cls");
						cout << "Enter passport ID -> ";
						cin >> readermas[k].passport_ID;
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
void sort_reader(reader *&readermas, int size_mas, int type)
{
	if (type == 1)
	{
		reader swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
			{
				if (strcmp(readermas[i].surname, readermas[j].surname) > 0)
				{
					swap = readermas[i];
					readermas[i] = readermas[j];
					readermas[j] = swap;
				}
				if (!strcmp(readermas[i].surname, readermas[j].surname))
				{
					if (strcmp(readermas[i].name, readermas[j].name) > 0)
					{
						swap = readermas[i];
						readermas[i] = readermas[j];
						readermas[j] = swap;
					}
					if (!strcmp(readermas[i].name, readermas[j].name))
					{
						if (strcmp(readermas[i].patronymic, readermas[j].patronymic) > 0)
						{
							swap = readermas[i];
							readermas[i] = readermas[j];
							readermas[j] = swap;
						}
					}
				}
			}
		}
	}
	if (type == 2)
	{
		reader swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (readermas[i].number_of_books_read > readermas[j].number_of_books_read)
				{
					swap = readermas[i];
					readermas[i] = readermas[j];
					readermas[j] = swap;
				}
		}
	}
	if (type == 3)
	{
		reader swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (readermas[i].ID > readermas[j].ID)
				{
					swap = readermas[i];
					readermas[i] = readermas[j];
					readermas[j] = swap;
				}
		}
	}
	if (type == 4)
	{
		reader swap;
		for (int i = 0; i < size_mas; i++)
		{
			for (int j = i + 1; j < size_mas; j++)
				if (readermas[i].passport_ID > readermas[j].passport_ID)
				{
					swap = readermas[i];
					readermas[i] = readermas[j];
					readermas[j] = swap;
				}
		}
	}
}
void search_for_a_reader_by_SNP(reader *&readermas, int size_mas, char *str_1, char *str_2, char *str_3)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (!strcmp(readermas[i].surname, str_1))
		{
			if (!strcmp(readermas[i].name, str_2))
			{
				if (!strcmp(readermas[i].patronymic, str_3))
				{
					n++;
					ind = i;
				}
			}
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		object_display(readermas[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		reader *tmp = new reader[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (!strcmp(readermas[i].surname, str_1))
			{
				if (!strcmp(readermas[i].name, str_2))
				{
					if (!strcmp(readermas[i].patronymic, str_3))
					{
						tmp[j] = readermas[i];
						j++;
					}
				}
			}
		}
		sort_reader(tmp, n, 1);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void search_for_a_reader_by_number_of_books_read(reader *&readermas, int size_mas, int num)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (readermas[i].number_of_books_read == num)
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		object_display(readermas[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		reader *tmp = new reader[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (readermas[i].number_of_books_read == num)
			{
				tmp[j] = readermas[i];
				j++;
			}
		}
		sort_reader(tmp, n, 2);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void search_for_a_reader_by_ID(reader *&readermas, int size_mas, int id)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (readermas[i].ID == id)
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		object_display(readermas[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		reader *tmp = new reader[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (readermas[i].ID == id)
			{
				tmp[j] = readermas[i];
				j++;
			}
		}
		sort_reader(tmp, n, 3);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void search_for_a_reader_by_passport_ID(reader *&readermas, int size_mas, int p_id)
{
	int n = 0, ind = 0;
	for (int i = 0; i < size_mas; i++)
	{
		if (readermas[i].passport_ID == p_id)
		{
			n++;
			ind = i;
		}
	}
	if (n == 1)
	{
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		object_display(readermas[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		reader *tmp = new reader[n];
		for (int i = 0, j = 0; i < size_mas; i++)
		{
			if (readermas[i].passport_ID == p_id)
			{
				tmp[j] = readermas[i];
				j++;
			}
		}
		sort_reader(tmp, n, 4);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
			object_display(tmp[i]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void information_output_on_screen_about_the_most_active_readers(reader *&readermas, int size_mas)
{
	int max = readermas[0].number_of_books_read, max_i;
	reader *tmp = new reader[3];
	reader *tmp_1 = new reader[size_mas - 1];
	reader *tmp_2 = new reader[size_mas - 2];
	for (int i = 1; i < size_mas; i++)
	{
		if (readermas[i].number_of_books_read >= max)
		{
			max = readermas[i].number_of_books_read;
			max_i = i;
		}
	}
	if (max == 0)
	{
		system("cls");
		cout << "None of the readers have read at least one book." << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size_mas; i++)
	{
		if (i < max_i)
			tmp_1[i] = readermas[i];
		if (i > max_i)
			tmp_1[i - 1] = readermas[i];
	}
	tmp[0] = readermas[max_i];
	max = tmp[0].number_of_books_read;
	for (int i = 1; i < size_mas - 1; i++)
	{
		if (tmp[i].number_of_books_read >= max)
		{
			max = tmp[i].number_of_books_read;
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
	max = tmp_2[0].number_of_books_read;
	for (int i = 1; i < size_mas - 2; i++)
	{
		if (tmp_2[i].number_of_books_read >= max)
		{
			max = tmp_2[i].number_of_books_read;
			max_i = i;
		}
	}
	tmp[2] = tmp_2[max_i];
	system("cls");
	cout << "Top 3 readers:" << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 3; i++)
		object_display(tmp[i]);
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	delete[]tmp_1;
	delete[]tmp_2;
	delete[]tmp;
}
void search_reader_menu(int size_mas)
{
	char cho[100];
	int len = 0;
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
		cin.getline(cho, 100);
		len = strlen(cho);
		char * choice = new char[len + 1];
		strcpy(choice, cho);
		if (!strcmp(choice, "SNP"))
		{
			system("cls");
			cout << "Enter sourname -> ";
			cin.getline(cho, 100);
			len = strlen(cho);
			char * choice_1 = new char[len + 1];
			strcpy(choice_1, cho);
			cout << "Enter name -> ";
			cin.getline(cho, 100);
			len = strlen(cho);
			char * choice_2 = new char[len + 1];
			strcpy(choice_2, cho);
			cout << "Enter patronymic -> ";
			cin.getline(cho, 100);
			cin.ignore();
			len = strlen(cho);
			char * choice_3 = new char[len + 1];
			strcpy(choice_3, cho);
			search_for_a_reader_by_SNP(readermas, size_mas, choice_1, choice_2, choice_3);
			delete[]choice_1;
			delete[]choice_2;
			delete[]choice_3;
		}
		else if (!strcmp(choice, "number"))
		{
			system("cls");
			cout << "Enter number of books read -> ";
			cin >> num;
			search_for_a_reader_by_number_of_books_read(readermas, size_mas, num);
		}
		else if (!strcmp(choice, "ID"))
		{
			system("cls");
			cout << "Enter ID -> ";
			cin >> num;
			search_for_a_reader_by_ID(readermas, size_mas, num);
		}
		else if (!strcmp(choice, "passport"))
		{
			system("cls");
			cout << "Enter passport ID -> ";
			cin >> num;
			search_for_a_reader_by_passport_ID(readermas, size_mas, num);
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
int number_of_days_and_debt(int Time, int type)
{
	int days = Time % 60;
	if (days > 5)
	{
		days = days - 5;
		if (type == 0)
			return days;
		if (type == 1)
			return 10 * days;
	}
	else
		return 0;
}
void expired_reader_information_date_of_return_of_the_book(reader *readermas, int size_mas)
{
	int Time_end = time(0);
	for (int i = 0; i < size_mas; i++)
	{
		if ((Time_end - readermas[i].Time) > 300)
		{
			object_display(readermas[i]);
			cout << "Amount of overdue days -> " << number_of_days_and_debt((Time_end - readermas[i].Time), 0) << endl;
			cout << "Accrued debt -> " << number_of_days_and_debt((Time_end - readermas[i].Time), 1) << " hryvnias." <<endl << endl;
		}
	}
}
void reader_menu(reader *readermas, int size_mas_r, int ID_r)
{
	char cho[100];
	int len;
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
		cin.getline(cho, 100);
		len = strlen(cho);
		char * choice_1 = new char[len + 1];
		strcpy(choice_1, cho);
		if (!strcmp(choice_1, "add"))
		{
			add_reader(readermas, size_mas_r, ID_r);
		}
		else if (!strcmp(choice_1, "remove"))
		{
			system("cls");
			delete_last_reader(readermas, size_mas_r, ID_r);
			system("pause");
		}
		else if (!strcmp(choice_1, "editing"))
		{
			int id_reader;
			system("cls");
			cout << "Enter the id of the reader -> ";
			cin >> id_reader;
			menu_editing_reader(readermas, size_mas_r, id_reader);
			system("pause");
		}
		else if (!strcmp(choice_1, "search"))
		{
			search_reader_menu(size_mas_r);
			system("pause");
		}
		else if (!strcmp(choice_1, "show"))
		{
			system("cls");
			information_about_library_readers(readermas, size_mas_r);
			system("pause");
		}
		else if (!strcmp(choice_1, "conclusion"))
		{
			system("cls");
			expired_reader_information_date_of_return_of_the_book(readermas, size_mas_r);
			system("pause");
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