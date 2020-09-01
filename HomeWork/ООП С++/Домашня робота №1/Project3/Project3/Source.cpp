#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Student
{
	char *name;
	char *sourname;
	char *patronymic;
	int age;
public:
	Student()
	{
		name = new char[50]{};
		sourname = new char[50]{};
		patronymic = new char[50]{};
		age = 0;
	}
	Student(const Student & obj)
	{
		name = _strdup(obj.name);
		sourname = _strdup(obj.sourname);
		patronymic = _strdup(obj.patronymic);
		age = obj.age;
	}
	Student(char *Name, char* Sourname, char* Patronymic, int Age)
	{
		name = _strdup(Name);
		sourname = _strdup(Sourname);
		patronymic = _strdup(Patronymic);
		age = Age;
	}
	Student(Student&&obj)
	{
		age = obj.age;
		name = obj.name;
		obj.name = nullptr;
		obj.age = 0;
	}
	~Student()
	{
		if (name)
			delete[] name;
	}
	Student & operator=(const Student & obj)
	{
		if (this == &obj)
			return *this;
		if (name)
			delete[]name;
		if (sourname)
			delete[]sourname;
		if (patronymic)
			delete[]patronymic;
		name = _strdup(obj.name);
		sourname = _strdup(obj.sourname);
		patronymic = _strdup(obj.patronymic);
		age = obj.age;
	}
	void setInfo()
	{
		char buf[50];
		cin.ignore();
		cout << "Enter name of student" << endl;
		cin.getline(buf, 50);
		strcpy(name, buf);
		cout << "Enter sourname of student" << endl;
		cin.getline(buf, 50);
		strcpy(sourname, buf);
		cout << "Enter patronymic of student" << endl;
		cin.getline(buf, 50);
		strcpy(patronymic, buf);
		cout << "Enter age of student" << endl;
		cin >> age;
		this->age = age;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Sourname: " << sourname << endl;
		cout << "Patronymic: " << patronymic << endl;
		cout << "Age: " << age << endl;
	}
};

class Group
{
	Student *stud;
	char *faculty;
	int course;
	int cnt;
	int num;

public:
	Group()
	{
		Student *stud = nullptr;
		faculty = new char[100];
		course = 0;
		cnt = 0;
	}
	Group(char* Faculty, int Course)
	{
		faculty = _strdup(Faculty);
		course = Course;
	}
	~Group()
	{
		delete[] stud;
		delete[] faculty;
	}
	void groupInfo()
	{
		char bufer[100];
		cout << "Enter name of the faculty: " << endl;
		cin.getline(bufer, 100);
		strcpy(faculty, bufer);
		cout << "Enter number of course: " << endl;
		cin >> course;
		this->course = course;
	}
	void addStud()
	{
		cout << "Enter information about new student." << endl;
		Student* tmp = new Student[cnt + 1];
		for (int i = 0; i < cnt; i++)
		{
			tmp[i] = stud[i];
		}
		delete[] stud;
		stud = tmp;
		stud[cnt].setInfo();
		cnt++;
	}
	void delStud()
	{
		cout << "Enter student's ID to delete -> ";
		cin >> num;
		num -= 1;
		if (num >= 0 && num <= cnt)
		{
			if (cnt == 1)
			{
				delete[] stud;
				stud = nullptr;
			}
			else
			{
				Student *tmp = new Student[cnt - 1];
				for (int i = 0; i < num; i++)
					tmp[i] = stud[i];

				for (int i = num + 1; i < cnt; i++)
					tmp[i - 1] = stud[i];

				delete[] stud;
				stud = tmp;
			}
			num--;
			cnt--;
			cout << "Deleted." << endl;
		}
	}
	void groupPrint()
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Information about group" << endl;
		if (cnt > 0)
		{
			cout << "Name of faculty: " << faculty << endl;
			cout << "Number of course: " << course << endl << endl;
			for (int i = 0; i < cnt; i++)
			{
				cout << "Student #" << i + 1 << endl;
				stud[i].print();
				cout << endl;
			}
		}
		else
		{
			cout << "List is empty!!!" << endl;
		}
	}
};

int main()
{
	Group z;
	z.groupInfo();
	z.addStud();
	z.addStud();
	z.addStud();
	z.groupPrint();
	z.delStud();
	z.groupPrint();
	system("pause");
}