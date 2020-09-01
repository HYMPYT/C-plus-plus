#include<iostream>
using namespace std;
class Passport
{
	char* name = nullptr;
	char* sourname = nullptr;
	char* patronymic = nullptr;
	char* sex = nullptr;
	char* dateOfBirth = nullptr;
	char* citizenship = nullptr;
public:
	Passport() = default;
	Passport(const char *n, const char *sour, const char *p, const char *sex, const char *d, const char *c)
	{
		name = _strdup(n);
		sourname = _strdup(sour);
		patronymic = _strdup(p);
		this->sex = _strdup(sex);
		dateOfBirth = _strdup(d);
		citizenship = _strdup(c);
	}
	Passport(const Passport&obj)
	{
		name = _strdup(obj.name);
		sourname = _strdup(obj.sourname);
		patronymic = _strdup(obj.patronymic);
		sex = _strdup(obj.sex);
		dateOfBirth = _strdup(obj.dateOfBirth);
		citizenship = _strdup(obj.citizenship);
	}
	Passport(Passport&&obj)
	{
		name = obj.name;
		sourname = obj.sourname;
		patronymic = obj.patronymic;
		sex = obj.sex;
		dateOfBirth = obj.dateOfBirth;
		citizenship = obj.citizenship;
		obj.name = nullptr;
		obj.sourname = nullptr;
		obj.patronymic = nullptr;
		obj.sex = nullptr;
		obj.dateOfBirth = nullptr;
		obj.citizenship = nullptr;
	}
	~Passport()
	{
		delete[]name;
		delete[]sourname;
		delete[]patronymic;
		delete[]sex;
		delete[]dateOfBirth;
		delete[]citizenship;
	}
	const char* getName()
	{
		return name;
	}
	void setName(char*_name)
	{
		delete[]name;
		name = _strdup(_name);
	}

	const char* getSourname()
	{
		return sourname;
	}
	void setSourname(char*_sourname)
	{
		delete[]sourname;
		sourname = _strdup(_sourname);
	}

	const char* getPatronymic()
	{
		return patronymic;
	}
	void setPatronymic(char*_patronymic)
	{
		delete[]patronymic;
		patronymic = _strdup(_patronymic);
	}

	const char* getSex()
	{
		return sex;
	}
	void setSex(char*_sex)
	{
		delete[]sex;
		sex = _strdup(_sex);
	}

	const char* getDateOfBirth()
	{
		return dateOfBirth;
	}
	void setDateOfBirth(char*_dateOfBirth)
	{
		delete[]dateOfBirth;
		dateOfBirth = _strdup(_dateOfBirth);
	}

	const char* getCitizenship()
	{
		return citizenship;
	}
	void setCitizenship(char*_citizenship)
	{
		delete[]citizenship;
		citizenship = _strdup(_citizenship);
	}
	void print()
	{
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Sourname: " << sourname << endl;
		cout << "Name: " << name << endl;
		cout << "Patronymic: " << patronymic << endl;
		cout << "Sex: " << sex << endl;
		cout << "Date of birth: " << dateOfBirth << endl;
		cout << "Citizenship: " << citizenship << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	Passport & operator= (const Passport&obj)
	{
		if (this == &obj)
			return *this;

		delete[]name;
		name = _strdup(obj.name);

		delete[]sourname;
		sourname = _strdup(obj.sourname);

		delete[]patronymic;
		patronymic = _strdup(obj.patronymic);

		delete[]sex;
		sex = _strdup(obj.sex);

		delete[]dateOfBirth;
		dateOfBirth = _strdup(obj.dateOfBirth);

		delete[]citizenship;
		citizenship = _strdup(obj.citizenship);
		return *this;
	}
	Passport &operator=(Passport&&obj)
	{
		if (this == &obj)
			return *this;

		delete[]name;
		name = obj.name;
		obj.name = nullptr;

		delete[]sourname;
		sourname = obj.sourname;
		obj.sourname = nullptr;

		delete[]patronymic;
		patronymic = obj.patronymic;
		obj.patronymic = nullptr;

		delete[]sex;
		sex = obj.sex;
		obj.sex = nullptr;

		delete[]dateOfBirth;
		dateOfBirth = obj.dateOfBirth;
		obj.dateOfBirth = nullptr;

		delete[]citizenship;
		citizenship = obj.citizenship;
		obj.citizenship = nullptr;
		return *this;
	}
};
class ForeignPassport :public Passport
{
	char *visa = nullptr;
public:
	ForeignPassport(const char *n, const char *sour, const char *p, const char *sex, const char *d, const char *c, const char * v) :Passport(n, sour, p, sex, d, c)
	{
		visa = _strdup(v);
	}
	ForeignPassport(const ForeignPassport&obj) :Passport(obj)
	{
		visa = _strdup(obj.visa);
	}
	ForeignPassport(ForeignPassport &&obj) :Passport(move(obj))
	{
		visa = obj.visa;
		obj.visa = nullptr;
	}
	~ForeignPassport()
	{
		delete[]visa;
	}
	const char* getVisa()
	{
		return visa;
	}
	void setViza(char*v)
	{
		delete[]visa;
		visa = _strdup(v);
	}
	void print()
	{
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Sourname: " << getSourname() << endl;
		cout << "Name: " << getName() << endl;
		cout << "Patronymic: " << getPatronymic() << endl;
		cout << "Sex: " << getSex() << endl;
		cout << "Date of birth: " << getDateOfBirth() << endl;
		cout << "Citizenship: " << getCitizenship() << endl;
		cout << "Visa: " << visa << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	ForeignPassport &operator= (const ForeignPassport&obj)
	{
		if (this == &obj)
			return *this;

		Passport::operator=(obj);

		delete[]visa;
		visa = obj.visa;
		return *this;
	}
	ForeignPassport &operator=(ForeignPassport &&obj)
	{
		if (this == &obj)
			return *this;

		delete[]visa;
		visa = obj.visa;
		obj.visa = nullptr;
		
		Passport::operator=(move(obj));

		return *this;
	}
};
int main()
{
	ForeignPassport a("Ivan", "Bondar", "Andriyovuch", "Man", "29.12.2003", "Ukrain", "Italy");
	ForeignPassport b = a;
	b.print();
	ForeignPassport c = move(a);
	c.print();
	system("pause");
}