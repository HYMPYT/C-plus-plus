#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
#include<ctime>
#include<random>
#include<functional>
#include<set>
#include<numeric>
using namespace std;
int rand_10_20()
{
	return rand() % 10 + 10;
}
class Numbers
{
	int n = 0;
public:
	Numbers(int val = 1)
	{
		n = val;
	}
	int operator()()//функциональный объект
	{
		return n++;
	}
};
bool compare(int a, int b)
{
	return a < b;
}
int main()
{
	/*random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> uid(10, 45);
	uniform_real_distribution<double> urd(0, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << uid(gen) << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << urd(gen) << " ";
	}
	cout << endl;*/

	random_device rd;
	mt19937 gen(rd());
	list<int> l(10);
	//Numbers gen(1);

	ostream_iterator<int> osi(cout, " ");
	int min = 1, max = 10;

	function<function<int()>(int, int)> f = [&](int min, int max)->function<int()> {
		return[&, min, max]()->int {
			uniform_int_distribution<int>uid(min, max);
			return uid(gen);
		};
	};

	/*function<int()> f = [min, max]()->int {
		return min + rand() % max - min + 1;
	};*/
	generate(l.begin(), l.end(), f(min, max));
	cout << "List: ";
	copy(l.begin(), l.end(), osi);
	cout << endl;


	/*cout << "Rlist: ";
	copy(l.rbegin(), l.rend(), osi);
	cout << endl;*/

	vector<int> v, even_v;


	generate_n(back_inserter(v), 10, f(min, max));
	/*generate_n(back_inserter(v), 10, [n]()mutable->int {
		return n++;
	});*/
	cout << "Vector: ";
	copy(v.begin(), v.end(), osi);
	cout << endl;

	cout << "Even_v: ";
	copy_if(v.begin(), v.end(), back_inserter(even_v), [](int val)->bool{
		return val % 2 == 0;
	});
	copy(even_v.begin(), even_v.end(), osi);
	cout << endl;

	auto it = find_if(v.begin(), v.end(), [](int val)->bool {
		return val % 2 == 0;
	});
	if (it != v.end())
	{
		cout << *it << " pos -> " << it - v.begin() << endl;
	}
	else
	{
		cout << "Error. There is no such element" << endl;
	}
	int n = count_if(v.begin(), v.end(), [](int val)->bool {
		return val % 2 == 0;
	});
	cout << n << endl;
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "Sum = " << sum << endl;
	int prod = accumulate(v.begin(), v.end(), 1, [](int a, int b)->int {
		return a * b;
	});
	cout << "Product = " << prod << endl;
	transform(v.begin(), v.end(), v.begin(), [](int val)-> int {
		return val * 2;
	});
	copy(v.begin(), v.end(), osi);
	cout << endl;

	vector<string> vs;
	transform(v.begin(), v.end(), back_inserter(vs), [](int val)->string {
		return to_string(val);
	});
	cout << "Vector string: ";
	copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " "));
	cout << endl;


	/*vector<int> v;
	copy(l.begin(), l.end(), back_inserter(v));
	copy(v.begin(), v.end(), osi);
	cout << endl;*/

	/*shuffle(v.begin(), v.end(), random_device());
	copy(v.begin(), v.end(), osi);
	cout << endl;*/

	/*sort(v.begin(), v.end(), compare);
	copy(v.begin(), v.end(), osi);
	cout << endl;*/

	/*set<int> s;
	copy(v.begin(), v.end(), inserter(s, s.begin()));
	copy(s.begin(), s.end(), osi);
	cout << endl;*/


	//вместо auto list<int>::iterator
	/*for (auto i = l.begin(); i != l.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	for (auto i = l.rbegin(); i != l.rend(); i++)
	{
		cout << *i << " ";
	}*/
	system("pause");
}
/*
Итераторы
1)input
2)output
3)forward
4)bidirectional
5)random access
6)contiguous
*/


/*
filter: copy_if, remove_if
map: transforms
reduce: accumulate
*/