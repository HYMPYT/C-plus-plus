#include<iostream>

using namespace std;

class MyVector
{
	int size = 0;
	int capacity = 0;
	int *arr = nullptr;
public:
	MyVector() = default;
	MyVector(int n, int val)
	{
		size = capacity = n;
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = val;
		}
	}
	MyVector(const MyVector& obj)
	{
		size = obj.size;
		capacity = obj.capacity;

		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	~MyVector()
	{
		if (capacity)
			delete[] arr;
	}
	MyVector& operator =(const MyVector&obj)
	{
		if (this == &obj)
			return*this;

		if (capacity)
		{
			delete[]arr;
			arr = nullptr;
		}
		size = obj.size;
		capacity = obj.capacity;
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
		return *this;
	}
	MyVector & operator =(MyVector&&obj)
	{
		if (this == &obj)
			return*this;

		if (capacity)
		{
			delete[]arr;
			arr = nullptr;
		}

		size = obj.size;
		arr = obj.arr;
		capacity = obj.capacity;
		obj.arr = nullptr;
		size = 0;
		capacity = 0;
	}
	bool operator== (const MyVector&obj)
	{
		if (size != obj.size)
			return false;
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != obj.arr[i])
				return false;
		}
		return true;
	}
	bool operator!= (const MyVector&obj)
	{
		if (size != obj.size)
			return true;
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != obj.arr[i])
				return true;
		}
		return false;
	}
	bool operator> (const MyVector&obj)
	{
		return size > obj.size;
	}
	bool operator< (const MyVector&obj)
	{
		return size < obj.size;
	}

	bool operator<=(const MyVector&obj) const
	{
		return this->size < obj.size;
	}
	bool operator>=(const MyVector&obj) const
	{
		return  obj.size < this->size;
	}
	int & operator [](int pos)
	{
		return arr[pos];
	}
	bool empty()
	{
		if (size == 0)
			return true;
	}
	int getsize()const
	{
		return size;
	}
	int getcapacity()const
	{
		return capacity;
	}
	void my_realloc()
	{
		int tmp_cap = (capacity ? 1 : capacity) * 2;
		int *tmp = new int[tmp_cap];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
		capacity = tmp_cap;
	}
	void push_back(int val)
	{
		if (size + 1 > capacity)
			my_realloc();
		arr[size] = val;
		size++;
	}
	void pop_back()
	{
		if (size >= 1)
			size--;
	}
	void resize(int val)
	{
		if (size > val)
		{
			size = val;
		}
		if (size < val)
		{
			int *tmp = new int[val];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = arr[i];
			}
			delete[]arr;
			arr = tmp;
			capacity = val;
			for (int i = size; i < val; ++i)
			{
				arr[i] = 0;
			}
		}
	}
	void clear()
	{
		size = 0;
	}
	void erase(int ind)
	{
		if (ind >= size)
			cout << "Index out of range!" << endl;;
		size--;
		for (int i = ind; i < size; ++i)
			arr[i] = arr[i + 1];
	}
	void insert(int ind, int  val)
	{
		if (size + 1 > capacity)
			my_realloc();
		arr[ind] = val;
		size++;
	}
};

int main()
{

}