#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;
int Div(int a, int b)noexcept(false)
{
	//try
	//{
	//throw logic_error("Some error");
		if (b == 0)
			throw invalid_argument("second param is zero");
		return a / b;
	//}
	/*catch (const char * ex)
	{
		cerr << "Error in function " << ex << endl;
		throw;
	}
	catch (...)
	{
		cout << "Some error" << endl;
	}*/
}

class Name
{
	string firstname;
	string lastname;
public:
	Name(const string& f, const string &l)
	{
		if (f.empty())
			throw invalid_argument("First param is empty");
		if (l.empty())
			throw invalid_argument("Second param is empty");
		firstname = f;
		lastname = l;
	}
	const string& getFirstname()const
	{
		return firstname;
	}
	void setFirstname(const string& f)
	{
		firstname = f;
	}
	const string& getLastname()const
	{
		return lastname;
	}
	void setLastname(const string& l)
	{
		lastname = l;
	}
	string getFullName()const
	{
		return firstname + " " + lastname;
	}
	~Name()
	{
		cout << "~Name()" << endl;
	}
};
class Person
{
	Name name;
	int age;
public:
	Person(const string&f, const string&l, int a)try:name(f, l)
	{
		age = a;
	}
	catch (const invalid_argument&ex)
	{
		cerr << "Error in class Person: " << ex.what() << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
};
void my_terminate()
{
	cout << "Text after main" << endl;
	exit(-1);
}
int main()
{
	set_terminate(my_terminate);
	string f_name, l_name;
	bool f;
	do {
		f = false;
		cout << "Enter first name -> ";
		getline(cin, f_name);
		cout << "Enter second name -> ";
		getline(cin, l_name);
		try
		{
			Person a(f_name, l_name, 23);
		}
		catch (int ex)
		{
			cerr << "error" << ex << endl;
			f = true;
		}
		/*catch (const invalid_argument&ex)
		{
			cerr << "Error in main: " << ex.what() << endl;
			f = true;
		}*/
	} while (f);
	/*string str = "Hello";
	cout << str[5] << endl;
	try
	{
		cout << str.at(5) << endl;
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;
	}*/

	/*int a, b;
	cout << "Enter first number -> ";
	cin >> a;
	cout << "Enter second number -> ";
	cin >> b;
	try
	{
		cout << Div(a, b) << endl;
	}
	catch(const char *ex)
	{
		cerr << "Error in main " << ex << endl;
	}
	catch (const invalid_argument&ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
	catch (const exception& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}*/
	system("pause");
}