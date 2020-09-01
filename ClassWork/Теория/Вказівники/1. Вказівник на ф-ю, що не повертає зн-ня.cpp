#include <iostream>
using namespace std;

// приклад оголошення і використання вказівника на фукнцію
void hello() {
	cout << "Hello, World" << endl;
}

void goodbye() {
	cout << "Good Bye, World" << endl;
}

void main()
{
	// приклад оголошення вказівника на фукнцію
	void(*message)();

	// прив'язка вказівника до ф-ї
	message = hello;
	// виклик через вказівник ф-ї, на яку він вказує
	message();

	message = goodbye;
	message();
	system("Pause");
}