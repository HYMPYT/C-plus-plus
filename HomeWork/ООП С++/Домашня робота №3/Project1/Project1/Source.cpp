#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;

class Car
{
private:
	static string colors[4];

	string licensePlate;
	string color;
public:
	Car()
	{
		for (int i = 0; i < 8; i++)
		{
			if (i <= 1 || i >= 6)
				licensePlate += 65 + rand() % 25;
			else
				licensePlate += 48 + rand() % 9;
		}

		color = colors[rand() % 4];
	}
	Car(string _licensePlate, string _color)
	{
		licensePlate = _licensePlate;
		color = _color;
	}

	void setLicensePlate(string _licensePlate)
	{
		licensePlate = _licensePlate;
	}
	void setColor(string _color)
	{
		color = _color;
	}

	string getLicensePlate() const
	{
		return licensePlate;
	}
	string getColor() const
	{
		return color;
	}

	static string * getColors()
	{
		return colors;
	}

	friend ostream & operator<<(ostream & os, const Car & obj)
	{
		os << obj.licensePlate << endl;
		os << obj.color << endl;
		os << "--------------" << endl;

		return os;
	}

}; string Car::colors[4] = { "blue", "green", "red", "yellow" };

template <typename T>
class Queue
{
private:
	int capacity;
	int size;
	T * arr;
public:
	Queue()
	{
		capacity = 100;
		arr = new T[capacity];

		size = 0;
	}
	Queue(int _capacity)
	{
		capacity = _capacity;
		arr = new T[capacity];

		size = 0;
	}
	Queue(const Queue & obj)
	{
		capacity = obj.capacity;
		size = obj.size;

		arr = new T[capacity];

		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
	}
	Queue(Queue && obj)
	{
		capacity = obj.capacity;
		size = obj.size;
		arr = obj.arr;

		obj.capacity = 0;
		obj.arr = nullptr;
	}
	~Queue()
	{
		if (capacity)
			delete[] arr;
	}

	Queue & operator=(const Queue & obj)
	{
		if (this == &obj)
			return *this;

		if (capacity)
			delete[] arr;

		capacity = obj.capacity;
		size = obj.size;

		arr = new T[capacity];

		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];

		return *this;
	}
	Queue & operator=(Queue && obj)
	{
		if (this == &obj)
			return *this;

		if (capacity)
			delete[] arr;

		capacity = obj.capacity;
		size = obj.size;
		arr = obj.arr;

		obj.capacity = 0;
		obj.arr = nullptr;

		return *this;
	}

	void push(T element)
	{
		arr[size++] = element;
	}
	T pop()
	{
		T tmp = arr[0];

		for (int i = 0; i < size - 1; i++)
			arr[i] = arr[i + 1];

		size--;

		return tmp;
	}
	T peek() const
	{
		return arr[0];
	}

	int getSize() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}
	bool isFull() const
	{
		return size == capacity;
	}
};

class CarWash
{
private:
	int timeCounter = 0;

	string carColor;

	static void setColor(int background, int text)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}
public:
	CarWash() = default;

	void setCar(const Car & car)
	{
		if (timeCounter == 0)
		{
			timeCounter = 10;
			carColor = car.getColor();
		}
	}

	void wash()
	{
		if (!isEmpty())
			timeCounter--;
	}

	bool isEmpty() const
	{
		return timeCounter == 0;
	}

	void printCarWash()
	{
		cout << " |========| " << endl;

		if (isEmpty())
		{
			cout << " |        | " << endl;
		}
		else
		{
			cout << " | ";

			if (carColor == "blue")
				setColor(0, 9);
			else if (carColor == "green")
				setColor(0, 2);
			else if (carColor == "red")
				setColor(0, 4);
			else if (carColor == "yellow")
				setColor(0, 14);

			cout << "|====|";

			setColor(0, 15);

			cout << " | " << endl;
		}

		cout << " |=      =| " << endl;
	}
	void printCars(Queue <Car> cars)
	{
		int size = cars.getSize();
		for (int i = 0; i < size; i++)
		{
			Car car = cars.pop();
			if (car.getColor() == "blue")
				setColor(0, 9);
			else if (car.getColor() == "green")
				setColor(0, 2);
			else if (car.getColor() == "red")
				setColor(0, 4);
			else if (car.getColor() == "yellow")
				setColor(0, 14);

			cout << "   |====|" << endl;
		}
		setColor(0, 15);
	}
};

int main()
{
	srand(time(0));

	Queue <Car> q(480);
	CarWash main;

	int waitTime = 0;

	int maxQueueLength = 0;
	int maxWaitTime = 0;

	for (int i = 0; i < 480; i++)
	{
		cout << " current time: " << i << " minutes " << endl;
		cout << " cars in the queue: " << q.getSize() << endl;

		main.printCarWash();
		main.printCars(q);
		Sleep(500);
		cout << endl;

		if (rand() % 10 == 1)
		{
			Car c;
			q.push(c);

			cout << " Car color: " << c.getColor() << endl;

			if (q.getSize() > maxQueueLength)
				maxQueueLength = q.getSize();
		}

		if (main.isEmpty() && !q.isEmpty())
		{
			if (waitTime > maxWaitTime)
				maxWaitTime = waitTime;
			waitTime = 0;

			Car tmp = q.pop();

			cout << " Start washing the car: " << endl;

			cout << tmp << endl;

			main.setCar(tmp);
		}

		if (!main.isEmpty())
		{
			cout << " washing the car " << endl;
			main.wash();
		}
		else if (main.isEmpty() && q.isEmpty())
		{
			cout << " waiting for a client " << endl;
			waitTime++;
		}
	}

	if (waitTime > maxWaitTime)
		maxWaitTime = waitTime;
	waitTime = 0;

	cout << " Maximum cars' count in the queue: " << maxQueueLength << endl;
	cout << " Max wait time: " << maxWaitTime << endl;

	system("pause");
	return 0;
}