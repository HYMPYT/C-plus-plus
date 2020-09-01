#include "Reader.h"
Reader::Reader(const string&s, const string&n, const string& p, const string&dob, int pass_id)
{
	surname = s;
	name = n;
	patronymic = p;
	date_of_birth = dob;
	passport_ID = pass_id;
}
Reader::Reader(const Reader&obj)
{
	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	date_of_birth = obj.date_of_birth;
	passport_ID = obj.passport_ID;
	ID = obj.ID;
	number_of_books_read = obj.number_of_books_read;
	Time = obj.Time;
}
Reader::Reader(Reader &&obj)
{
	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	date_of_birth = obj.date_of_birth;
	passport_ID = obj.passport_ID;
	ID = obj.ID;
	number_of_books_read = obj.number_of_books_read;
	Time = obj.Time;
	obj.surname = nullptr;
	obj.name = nullptr;
	obj.patronymic = nullptr;
	obj.date_of_birth = nullptr;
	obj.passport_ID = 0;
	obj.ID = 0;
	obj.number_of_books_read = 0;
	obj.Time = 0;
}
//====================================================================================
void Reader::object_display(Reader obj)
{
	cout << "| " << setw(2) << obj.ID << " | ";
	cout << setw(15) << obj.surname << " | ";
	cout << setw(10) << obj.name << " | ";
	cout << setw(20) << obj.patronymic << " | ";
	cout << setw(13) << obj.date_of_birth << " | ";
	cout << setw(11) << obj.passport_ID << " | ";
	cout << setw(20) << obj.number_of_books_read << " |" << endl;
}
const string& Reader::getSurname()const
{
	return surname;
}
void Reader::setSurname(const string&s)
{
	surname = s;
}
const string& Reader::getName()const
{
	return name;
}
void Reader::setName(const string&n)
{
	name = n;
}
const string&Reader::getPatronymic()const
{
	return patronymic;
}
void Reader::setPatronymic(const string&p)
{
	patronymic = p;
}
const string&Reader::getDateOfBirth()const
{
	return date_of_birth;
}
void Reader::setDateOfBirth(const string&d)
{
	date_of_birth = d;
}
int Reader::getPassport_ID()const
{
	return passport_ID;
}
void Reader::setPassport_ID(int val)
{
	passport_ID = val;
}
int Reader::getID()const
{
	return ID;
}
void Reader::setID(int val)
{
	ID = val;
}
int Reader::getNumberOfBooksRead()
{
	return number_of_books_read;
}
void Reader::setNumberOfBooksRead(int val)
{
	number_of_books_read = val;
}
int Reader::getTime()const
{
	return Time;
}
void Reader::setTime(int val)
{
	Time = val;
}
Reader& Reader::operator=(const Reader&obj)
{
	if (this == &obj)
		return *this;

	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	date_of_birth = obj.date_of_birth;
	passport_ID = obj.passport_ID;
	ID = obj.ID;
	number_of_books_read = obj.number_of_books_read;
	Time = obj.Time;
	return *this;
}
Reader& Reader::operator=(Reader&&obj)
{
	if (this == &obj)
		return *this;

	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	date_of_birth = obj.date_of_birth;
	passport_ID = obj.passport_ID;
	ID = obj.ID;
	number_of_books_read = obj.number_of_books_read;
	Time = obj.Time;
	obj.surname = nullptr;
	obj.name = nullptr;
	obj.patronymic = nullptr;
	obj.date_of_birth = nullptr;
	obj.passport_ID = 0;
	obj.ID = 0;
	obj.number_of_books_read = 0;
	obj.Time = 0;
	return *this;
}
//====================================================================================
void Reader::information_about_library_readers(vector<Reader> reader_v)
{
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < reader_v.size(); i++)
	{
		object_display(reader_v[i]);
	}
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
void Reader::fill_reader(Reader&obj)
{
	system("cls");
	cout << "Enter surname -> ";
	getline(cin, obj.surname);
	cout << "Enter name -> ";
	getline(cin, obj.name);
	cout << "Enter patronymic -> ";
	getline(cin, obj.patronymic);
	cout << "Enter date of birth -> ";
	cin >> obj.date_of_birth;
	cout << "Enter passport ID -> ";
	cin >> obj.passport_ID;
}
void Reader::add_reader(vector<Reader> &reader_v, int &id)
{
	Reader tmp;
	fill_reader(tmp);
	tmp.ID = id++;
	reader_v.push_back(tmp);
}
void Reader::delete_last_reader(vector<Reader> &reader_v, int&id)
{
	reader_v.pop_back();
	id = id - 1;
	cout << "Deletion was successful." << endl;
}
int Reader::find_by_id_reader(vector<Reader> &reader_v, int id)
{
	int counter = 0;
	for (auto i = reader_v.begin(); i != reader_v.end(); i++)
	{
		if ((*i).ID == id)
			return counter;
		counter++;
	}
	return -1;
}
//void Reader::menu_editing_reader(vector<Reader> &reader_v, int id)
//{
//	string tmp;
//	int k = find_by_id_reader(reader_v, id);
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
//				fill_reader(reader_v[k]);
//			}
//			else if (!tmp.compare("partial"))
//			{
//				while (1)
//				{
//					system("cls");
//					cout << "Partial editing" << endl;
//					cout << "\t- surname" << endl;
//					cout << "\t- name" << endl;
//					cout << "\t- patronymic" << endl;
//					cout << "\t- date" << endl;
//					cout << "\t- passport ID (ID)" << endl;
//					cout << "\t- exit" << endl << ">>> ";
//					getline(cin, tmp);
//					if (!tmp.compare("surname"))
//					{
//						system("cls");
//						cout << "Enter surname -> ";
//						getline(cin, reader_v[k].surname);
//					}
//					else if (!tmp.compare("name"))
//					{
//						system("cls");
//						cout << "Enter name -> ";
//						getline(cin, reader_v[k].name);
//					}
//					else if (!tmp.compare("patronymic"))
//					{
//						system("cls");
//						cout << "Enter patronymic -> ";
//						getline(cin, reader_v[k].patronymic);
//					}
//					else if (!tmp.compare("date"))
//					{
//						system("cls");
//						cout << "Enter date of birth -> ";
//						getline(cin, reader_v[k].date_of_birth);
//					}
//					else if (!tmp.compare("ID"))
//					{
//						system("cls");
//						cout << "Enter passport ID -> ";
//						cin >> reader_v[k].passport_ID;
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
//			else if (tmp.compare("exit"))
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
void Reader::sort_reader(vector<Reader> &reader_v, int type)
{
	if (type == 1)
	{
		Reader swap;
		for (int i = 0; i < reader_v.size(); i++)
		{
			for (int j = i + 1; j < reader_v.size(); j++)
			{
				if (reader_v[i].surname.compare(reader_v[j].surname) > 0)
				{
					swap = reader_v[i];
					reader_v[i] = reader_v[j];
					reader_v[j] = swap;
				}
				if (reader_v[i].surname.compare(reader_v[j].surname) == 0)
				{
					if (reader_v[i].name.compare(reader_v[j].name) > 0)
					{
						swap = reader_v[i];
						reader_v[i] = reader_v[j];
						reader_v[j] = swap;
					}
					if (reader_v[i].name.compare(reader_v[j].name) == 0)
					{
						if (reader_v[i].patronymic.compare(reader_v[j].patronymic) > 0)
						{
							swap = reader_v[i];
							reader_v[i] = reader_v[j];
							reader_v[j] = swap;
						}
					}
				}
			}
		}
	}
	if (type == 2)
	{
		Reader swap;
		for (int i = 0; i < reader_v.size(); i++)
		{
			for (int j = i + 1; j < reader_v.size(); j++)
				if (reader_v[i].number_of_books_read > reader_v[j].number_of_books_read)
				{
					swap = reader_v[i];
					reader_v[i] = reader_v[j];
					reader_v[j] = swap;
				}
		}
	}
	if (type == 3)
	{
		Reader swap;
		for (int i = 0; i < reader_v.size(); i++)
		{
			for (int j = i + 1; j < reader_v.size(); j++)
				if (reader_v[i].ID > reader_v[j].ID)
				{
					swap = reader_v[i];
					reader_v[i] = reader_v[j];
					reader_v[j] = swap;
				}
		}
	}
	if (type == 4)
	{
		Reader swap;
		for (int i = 0; i < reader_v.size(); i++)
		{
			for (int j = i + 1; j < reader_v.size(); j++)
				if (reader_v[i].passport_ID > reader_v[j].passport_ID)
				{
					swap = reader_v[i];
					reader_v[i] = reader_v[j];
					reader_v[j] = swap;
				}
		}
	}
}
void Reader::search_for_a_reader_by_SNP(vector<Reader> &reader_v, const string& str_1, const string&str_2, const string&str_3)
{
	int n = 0, ind = 0;
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (!reader_v[i].surname.compare(str_1))
		{
			if (!reader_v[i].name.compare(str_2))
			{
				if (!reader_v[i].patronymic.compare(str_3))
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
		object_display(reader_v[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Reader> tmp;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
		{
			if ((*i).surname.compare(str_1))
			{
				if ((*i).name.compare(str_2))
				{
					if ((*i).patronymic.compare(str_3))
					{
						tmp.push_back(*i);
					}
				}
			}
		}
		sort_reader(tmp, 1);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = tmp.begin(); i != tmp.end(); i++)
			object_display(*i);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void Reader::search_for_a_reader_by_number_of_books_read(vector<Reader> &reader_v, int num)
{
	int n = 0, ind = 0;
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (reader_v[i].number_of_books_read == num)
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
		object_display(reader_v[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Reader> tmp;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
		{
			if ((*i).number_of_books_read == num)
			{
				tmp.push_back(*i);
			}
		}
		sort_reader(tmp, 2);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
			object_display(*i);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void Reader::search_for_a_reader_by_ID(vector<Reader> &reader_v, int id)
{
	int n = 0, ind = 0;
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (reader_v[i].ID == id)
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
		object_display(reader_v[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Reader> tmp;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
		{
			if ((*i).ID == id)
			{
				tmp.push_back(*i);
			}
		}
		sort_reader(tmp, 3);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
			object_display(*i);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void Reader::search_for_a_reader_by_passport_ID(vector<Reader> &reader_v, int p_id)
{
	int n = 0, ind = 0;
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (reader_v[i].passport_ID == p_id)
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
		object_display(reader_v[ind]);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
	if (n > 1)
	{
		vector<Reader> tmp;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
		{
			if ((*i).passport_ID == p_id)
			{
				tmp.push_back(*i);
			}
		}
		sort_reader(tmp, 4);
		system("cls");
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (auto i = reader_v.begin(); i != reader_v.end(); i++)
			object_display(*i);
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
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
void Reader::information_output_on_screen_about_the_most_active_readers(vector<Reader> &reader_v)
{
	int max = reader_v[0].number_of_books_read, max_i;
	for (int i = 1; i < reader_v.size(); i++)
	{
		if (reader_v[i].number_of_books_read >= max)
		{
			max = reader_v[i].number_of_books_read;
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
	vector<Reader> buf;
	vector<Reader> tmp;
	vector<Reader> tmp_1;
	for (int i = 0; i < reader_v.size(); i++)
	{
		if (i == max_i)
			continue;
		buf.push_back(reader_v[i]);
	}
	tmp[0] = reader_v[max_i];
	max = buf[0].number_of_books_read;
	for (int i = 1; i < buf.size(); i++)
	{
		if (buf[i].number_of_books_read >= max)
		{
			max = buf[i].number_of_books_read;
			max_i = i;
		}
	}
	for (int i = 0; i < buf.size(); i++)
	{
		if (i == max_i)
			continue;
		tmp_1.push_back(buf[i]);
	}
	tmp[1] = buf[max_i];
	max = tmp_1[0].number_of_books_read;
	for (int i = 1; i < tmp_1.size(); i++)
	{
		if (tmp_1[i].number_of_books_read >= max)
		{
			max = tmp_1[i].number_of_books_read;
			max_i = i;
		}
	}
	tmp[2] = tmp_1[max_i];
	system("cls");
	cout << "Top 3 readers:" << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (auto i = tmp.begin(); i != tmp.end(); i++)
		object_display(*i);
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
}
//void Reader::search_reader_menu(vector<Reader> &reader_v)
//{
//	string tmp;
//	int num;
//	while (1)
//	{
//		system("cls");
//		cout << "Search menu" << endl;
//		cout << "\t- search for a reader by SNP (SNP)" << endl;
//		cout << "\t- search for a reader by number of books read (number)" << endl;
//		cout << "\t- search for a reader by ID (ID)" << endl;
//		cout << "\t- search for a reader by passport ID (passport)" << endl;
//		cout << "\t- exit" << endl << ">>> ";
//		getline(cin, tmp);
//		if (!tmp.compare("SNP"))
//		{
//			system("cls");
//			string choice_1, choice_2, choice_3;
//			cout << "Enter sourname -> ";
//			getline(cin, choice_1);
//			cout << "Enter name -> ";
//			getline(cin, choice_2);
//			cout << "Enter patronymic -> ";
//			getline(cin, choice_3);
//			search_for_a_reader_by_SNP(reader_v, choice_1, choice_2, choice_3);
//		}
//		else if (!tmp.compare("number"))
//		{
//			system("cls");
//			cout << "Enter number of books read -> ";
//			cin >> num;
//			search_for_a_reader_by_number_of_books_read(reader_v, num);
//		}
//		else if (!tmp.compare("ID"))
//		{
//			system("cls");
//			cout << "Enter ID -> ";
//			cin >> num;
//			search_for_a_reader_by_ID(reader_v, num);
//		}
//		else if (!tmp.compare("passport"))
//		{
//			system("cls");
//			cout << "Enter passport ID -> ";
//			cin >> num;
//			search_for_a_reader_by_passport_ID(reader_v, num);
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
int Reader::number_of_days_and_debt(int Time, int type)
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
void Reader::expired_reader_information_date_of_return_of_the_book(vector<Reader> &reader_v)
{
	int Time_end = time(0);
	for (int i = 0; i < reader_v.size(); i++)
	{
		if ((Time_end - reader_v[i].getTime()) > 100)
		{
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| ID |     Surname     |    Name    |      Patronymic      | Date of birth | Passport ID | Number of books read |" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			object_display(reader_v[i]);
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Amount of overdue days -> " << number_of_days_and_debt((Time_end - reader_v[i].getTime()), 0) << endl;
			cout << "Accrued debt -> " << number_of_days_and_debt((Time_end - reader_v[i].getTime()), 1) << " hryvnias." << endl << endl;
		}
	}
}
//void Reader::reader_menu(vector<Reader> reader_v, int ID_r)
//{
//	string tmp;
//	while (1)
//	{
//		system("cls");
//		cout << "Reader" << endl;
//		cout << "\t- add reader (add)" << endl;
//		cout << "\t- remove reader (remove)" << endl;
//		cout << "\t- editing" << endl;
//		cout << "\t- search" << endl;
//		cout << "\t- show all readers (show)" << endl;
//		cout << "\t- conclusion overdue reader information date of return of the book (conclusion)" << endl;
//		cout << "\t- exit" << endl << ">>> ";
//		getline(cin, tmp);
//		if (!tmp.compare("add"))
//		{
//			add_reader(reader_v, ID_r);
//		}
//		else if (!tmp.compare("remove"))
//		{
//			system("cls");
//			delete_last_reader(reader_v, ID_r);
//			system("pause");
//		}
//		else if (!tmp.compare("editing"))
//		{
//			int id_reader;
//			system("cls");
//			cout << "Enter the id of the reader -> ";
//			cin >> id_reader;
//			menu_editing_reader(reader_v, id_reader);
//			system("pause");
//		}
//		else if (!tmp.compare("search"))
//		{
//			search_reader_menu(reader_v);
//			system("pause");
//		}
//		else if (!tmp.compare("show"))
//		{
//			system("cls");
//			information_about_library_readers(reader_v);
//			system("pause");
//		}
//		else if (!tmp.compare("conclusion"))
//		{
//			system("cls");
//			expired_reader_information_date_of_return_of_the_book(reader_v);
//			system("pause");
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