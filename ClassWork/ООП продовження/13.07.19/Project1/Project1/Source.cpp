#include<iostream>
using namespace std;
class Point3D
{
	int x;
	int y;
	int z;
public:
	Point3D(int x, int y, int z):x(x), y(y), z(z){}
	void print()
	{
		cout << "X = " << x << endl;
		cout << "Y = " << y << endl;
		cout << "Z = " << z << endl;
	}
};
class Point
{
	int x;
	int y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		/*this->x = x;
		this->y = y;*/
	}
	int getY() const
	{
		return y;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX() const
	{
		return x;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void print()
	{
		cout << "X = " << x << endl;
		cout << "Y = " << y << endl;
	}
	Point operator+(const Point &obj)
	{
		return Point(this->x + obj.x, this->y + obj.y);
	}
	Point operator+(int val)
	{
		return Point(this->x + val, this->y + val);
	}
	bool operator==(const Point&obj)
	{
		return x == obj.x && y == obj.y;
	}
	bool operator!=(const Point &obj)
	{
		return !(*this == obj);
	}
	Point & operator++()
	{
		cout << "Prefics" << endl;
		x++;
		y++;
		return *this;
	}
	Point & operator++(int)
	{
		cout << "Postfics" << endl;
		x++;
		y++;
		return *this;
	}
	Point & operator+()
	{
		cout << "+ overload" << endl;
		return *this;
	}
	friend Point operator+(int val, const Point &obj)
	{
		return Point(obj.x + val, obj.y + val);
	}
	friend ostream&operator<<(ostream&os, const Point&obj)
	{
		os << "X = " << obj.x << endl << "Y = " << obj.y << endl;
		return os;
	}
	friend istream&operator>>(istream&is, Point &obj)
	{
		cout << "Enter X -> ";
		is >> obj.x;
		cout << "Enter Y -> ";
		is >> obj.y;
		return is;
	}
	explicit operator int()
	{
		return x;
	}
	operator Point3D()
	{
		return Point3D(x, y, 0);
	}
};
int main()
{
	Point a(12, 23);
	int b = (int)a;
	cout << b << endl;
	Point3D c = a;
	c.print();
	/*cin >> a;
	cout << a << endl;*/
	/*a.print();
	cout << endl;
	b.print();
	cout << endl;
	Point c = a + b;
	c.print();*/
	system("pause");
}