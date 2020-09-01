#include<iostream>
#include<cmath>
using namespace std;
class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction():numerator(1), denominator(1){}
	Fraction(int numerator, int denominator)
	{
		if (numerator == 0)
		{
			cout << "====================================================================================" << endl;
			cout << "Your numerator has been replaced by one if you do not agree, enter an another number" << endl;
			cout << "====================================================================================" << endl;
			this->numerator = numerator + 1;
			this->denominator = denominator;
		}
		else
			if (denominator == 0)
			{
				cout << "======================================================================================" << endl;
				cout << "Your denominator has been replaced by one if you do not agree, enter an another number" << endl;
				cout << "======================================================================================" << endl;
				this->denominator = denominator + 1;
				this->numerator = numerator;
			}
			else
			{
				if (numerator && denominator < 0)
				{
					this->numerator = abs(numerator);
					this->denominator = abs(denominator);
				}
				else
				{
					this->numerator = numerator;
					this->denominator = denominator;
				}
			}
	}
	int getNumerator() const
	{
		return numerator;
	}
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	int getDenominator() const
	{
		return denominator;
	}
	void setDenominator(int denominator)
	{
		this->denominator = denominator;
	}
	int NOD(int a, int b)
	{
		int a1 = abs(a), b1 = abs(b);
		while (a1 != 0 && b1 != 0)
		{
			if (a1 >= b1)
				a1 %= b1;
			else
				b1 %= a1;
		}
		return a1 + b1;
	}
	int NOK(int a, int b)
	{
		return (a * b) / NOD(a, b);
	}
	void reduce()
	{
		int nod = NOD(numerator, denominator);

		this->numerator /= nod;
		this->denominator /= nod;
	}
	void show(const char * str)
	{
		reduce();
		cout << str << endl;
		cout << numerator << " / " << denominator << endl;
	}
	Fraction operator+(Fraction &obj)
	{
		Fraction tmp;
		int value = NOK(this->denominator, obj.denominator);
		tmp.numerator = this->numerator * (value / this->denominator) + obj.numerator * (value / obj.denominator);
		tmp.denominator = value;
		return tmp;
	}
	Fraction operator-(Fraction &obj)
	{
		Fraction tmp;
		int value = NOK(denominator, obj.denominator);
		tmp.numerator = (numerator * (value / denominator)) - (obj.numerator * (value / obj.denominator));
		tmp.denominator = value;
		return tmp;
	}
	Fraction operator*(const Fraction &obj)
	{
		Fraction tmp;
		tmp.numerator = numerator * obj.numerator;
		tmp.denominator = denominator * obj.denominator;
		return tmp;
	}
	Fraction operator/(const Fraction &obj)
	{
		Fraction tmp;
		tmp.numerator = numerator * obj.denominator;
		tmp.denominator = denominator * obj.numerator;
		return tmp;
	}
	bool operator==(const Fraction &obj)
	{
		return this->numerator * obj.denominator - this->denominator * obj.numerator == 0;
	}
	bool operator!=(const Fraction &obj)
	{
		if (this->numerator * obj.denominator - this->denominator * obj.numerator > 0)
			return true;
		if (this->numerator * obj.denominator - this->denominator * obj.numerator < 0)
			return true;
		return false;
	}
	bool operator<(const Fraction &obj)
	{
		return this->numerator * obj.denominator - this->denominator * obj.numerator < 0;
	}
	bool operator<=(const Fraction &obj)
	{
		return this->numerator * obj.denominator - this->denominator * obj.numerator <= 0;
	}
	bool operator>(const Fraction &obj)
	{
		return this->numerator * obj.denominator - this->denominator * obj.numerator > 0;
	}
	bool operator>=(const Fraction &obj)
	{
		return this->numerator * obj.denominator - this->denominator * obj.numerator >= 0;
	}
};
int main()
{
	{
		Fraction a(3, -4);
		a.show("A:");
		Fraction b(2, 5);
		b.show("B:");
		(a + b).show("Rezult +");
		(a - b).show("Rezult -");
		(a * b).show("Rezult *");
		(a / b).show("Rezult /");

		cout << endl << " a > b ? " << (a > b) << endl;
		cout << " a < b ? " << (a < b) << endl;
		cout << " a >= b ? " << (a >= b) << endl;
		cout << " a <= b ? " << (a <= b) << endl;
		cout << " a == b ? " << (a == b) << endl;
		cout << " a != b ? " << (a != b) << endl;
	}
	system("pause");
}
