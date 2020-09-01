#include"StudentMed.h"

int main()
{
	StudentMed obj("Petya", 23, 1, "dantist");
	cout << obj.getName() << " " << obj.getSpecialization()<<endl;
	cout << obj.getName() << endl;

	StudentMed tt(1, "dantist");
	cout << tt.getName() << " " << obj.getId() << endl;
	cout << tt.getName() << endl;

	Student stud("Student", 25, 7777);
	cout << stud.getName() << " " << stud.getAge() << " " << stud.getId() << endl;
	system("pause");
}