#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<ctime>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
	setlocale(0, "rus");
	srand(time(0));
	map<int, string> m;
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(4, "four"));
	m.insert(pair<int, string>(2, "two"));
	m.insert(pair<int, string>(5, "five"));
	for (auto item : m)
	{
		cout << item.first << " -> " << item.second << endl;
	}
	cout << endl;
	unordered_map<string, string>um;
	um.insert(pair<string, string>("one", "один"));
	um.insert(pair<string, string>("five", "пять"));
	um.insert(pair<string, string>("four", "четыре"));
	um.insert(pair<string, string>("two", "два"));
	um.insert(pair<string, string>("three", "три"));
	cout << um["two"] << endl;
	for (auto item : um)
	{
		cout << item.first << " -> " << item.second << endl;
	}
	cout << endl;

	/*srand(time(0));
	deque<int> d(10);
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = rand() % 12;
		cout << d[i] << " ";
	}
	cout << endl;
	unordered_set<int> s;
	for (int i = 0; i < d.size(); i++)
	{
		s.insert(d[i]);
	}
	for (int item : s)
	{
		cout << item << " ";
	}
	cout << endl;*/

	/*vector <vector<int>> arr(4);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(4);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	/*vector<int> v(10);
	for (auto i = v.begin(); i != v.end(); i++)
	{
		*i = rand() % 10;
	}
	for (int item:v)
	{
		cout << item << " ";
	}
	cout << endl;*/


	/*vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 5);
	int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v4(arr, arr + 10);
	vector<int> v5 = v4;
	vector<int> v6(v5.begin(), v5.end());
	v6.insert(v6.begin(), 1000);
	v6.erase(v6.begin() + 5);
	for (int i = 0; i < v6.size(); i++)
	{
		cout << v6[i] << " ";
	}
	cout << endl;*/
	//for (int i = 0; i < 50; i++)
	//{
	//	cout << v1.capacity() << " -> " << v1.size() << endl;
	//	v1.push_back(i);
	//}
	////v1.shrink_to_fit();
	//v1.clear();
	//cout << v1.capacity() << " -> " << v1.size() << endl;
	system("pause");
}