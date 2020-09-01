#include"Subject.h"

int main()
{
	Practical *ps = new Practical();
	Lecture *ls = new Lecture();
	Subject *s = new PracticalSubject();
	s->setTypeOfSubject(ps);
	s->conductingClasses();
	delete s;
	cout << "+++++++++++++++++++++++++++++++++" << endl;
	s = new LectureSubject();
	s->setTypeOfSubject(ls);
	s->conductingClasses();
	delete s;
	delete ps;
	delete ls;
	system("pause");
}