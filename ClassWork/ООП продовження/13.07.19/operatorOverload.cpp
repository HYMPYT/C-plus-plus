#include<iostream>
using namespace std;

class Point3D
{
	int x, y, z;
public:
	Point3D(int x = 0, int y = 0, int z = 0): x(x),y(y),z(z)
	{}
	friend ostream& operator<<(ostream& os, const Point3D&obj)
	{
		os << "X= " << obj.x << " Y= " << obj.y << " Z= " << obj.z << endl;
		return os;
	}

};
class Point
{ 
	char*name = nullptr;
	int x;
	int y;
public:
	explicit Point(const char*n,int x = 0, int y = 0):x(x),y(y) //Инициализация простых параметров. explicit запрещает неявную передачу параметров.
	{
		cout << "!!!!!!" << endl;
		name = _strdup(n);
	}
	Point(const Point&obj)
	{
		x = obj.x;
		y = obj.y;
		name = _strdup(obj.name);
	}
	Point(Point&obj)
	{
		x = obj.x;
		y = obj.y;
		name = obj.name;
		obj.name = nullptr;
	}
	~Point()
	{
		delete[]name;
	}
	void setName(const char*s)
	{
		if (s)
		{
			delete[]name;
			name = _strdup(s);
		}
	}
	const char* getName()
	{
		return name;
	}
	void setX(int x)
	{
		this->x=x;
	}
	int getX()const
	{
		return x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getY()const
	{
		return y;
	}
	void print()
	{
		cout <<name<< ":\nX= " << x << " Y= " << y << endl;
	}
	Point operator+ (const Point&obj)
	{
		return Point("new_name",x + obj.x, y + obj.y); //{x + obj.x, y + obj.y} аналогичная форма записи
	}
	Point operator+ (int val)
	{
		return Point("new_name",x + val, y + val); 
	}
	bool operator== (const Point&obj)
	{
		return x == obj.x && y == obj.y;
	}
	bool operator!= (const Point&obj)
	{
		return !(*this == obj);  // тоже что и x != obj.x || y != obj.y;
	}
	Point & operator=(const Point&obj)
	{
		cout << "&"<<endl;
		if (this == &obj)
			return *this;

		delete[]name;

		x = obj.x;
		y = obj.y;
		name = _strdup(obj.name);

		return *this;
	}
	Point & operator=(Point&&obj)
	{
		cout << "&&" << endl;
		if (this == &obj)
			return *this;
		delete[]name;

		x = obj.x;
		y = obj.y;
		name = obj.name;
		obj.name = nullptr;
		return *this;
	}
	Point & operator++()//перегрузка для постфиксной формы - Point & operator++(int)
	{
		x++;
		y++;
		return *this;
	}
	Point & operator--()
	{
		x--;
		y--;
		return *this;
	}
	void operator+()
	{
		cout << "operator+" << endl;
	}
	friend ostream& operator<<(ostream& os, const Point&obj)
	{
		os << "X= " << obj.x << " Y= " << obj.y << endl;
		return os;
	}
	friend istream&operator>>(istream&is, Point&obj)
	{
		cout << "ener x -> ";
		is >> obj.x;
		cout << "ener y -> ";
		is >> obj.y;
		return is;
	}

	operator int() //преобразование пользовательских типов данных
	{
		return sqrt(pow(x,2)+pow(y,2));
	}
	explicit operator double()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	operator Point3D()
	{
		return Point3D(x, y, 12);
	}
};

int main()
{
	Point a("a", 12, 23);
	Point c("!!!!");
	int b = a;
	cout << b << endl;
	Point3D d = a;
	cout << d << endl;
	/*+a;*/
	//c = move (a);
	//Point d = a.operator + (b); // тоже что и a+b;
	/*a.print();*/
	/*c.print();*/
	//d.print();
	///*if (a == b)
	//{
	//	cout << "++++" << endl;
	//}
	//else
	//{
	//	cout << "----" << endl;
	//}*/
}