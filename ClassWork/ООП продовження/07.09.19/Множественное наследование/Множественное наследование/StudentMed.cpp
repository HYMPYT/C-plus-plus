#include "StudentMed.h"
StudentMed::StudentMed(const string&n, int age, int id, const string&sp) :Doctor(n, age, sp), Student(n, age, id) {}
StudentMed::StudentMed(int id, const string&sp) : Student("Ivan", 23, id), Doctor("Aybolit", 57, sp) {}
