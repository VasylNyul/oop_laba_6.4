#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>


using namespace std;
template <class T>
class arr
{
	T* v;
	int size;
public:
	arr(int newsize);
	arr(arr&);
	~arr();

	friend arr<T> operator < <>(arr<T>& x, arr<T>& y);
	T& operator [] (int index);
	arr& operator = (const arr&);
	friend ostream& operator << <>(ostream&, arr&);
	friend istream& operator >> <>(istream&, arr&);
};

template <class T>
arr<T>::arr(int newsize)
{
	v = new T[size = newsize];
	for (int i = 0; i < size; i++)
		v[i] = T();
}

template <class T>
arr<T>::arr(arr<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}

template <class T>
arr<T>::~arr()
{
	delete[] v;
}

template <class T>
arr<T> operator < (arr<T>& x, arr<T>& y)
{
	if (x.size != y.size)
	{
		throw exception("Розмір повинен бути однаковий!");
	}
	arr<T> z(x.size);
	for (int i = 0; i < x.size; i++)
	{
		z[i] = x[i] == y[i] ? 1 : 0;
	}
	return z;
}

template <class T>
T& arr<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Індекс вийшов за межі");
	}
	return v[index];
}

template <class T>
arr<T>& arr<T>::operator = (const arr<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, arr<T>& x)
{
	cout << "Введіть " << x.size << " елементів масиву" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "Елемент[" << i << "] = ";
		is >> x.v[i];
	}
	return is;
}

template <class T>
ostream& operator << (ostream& os, arr<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		arr<int> A(5), B(5), C(5);
		cout << "Перший масив A:" << endl;
		cin >> A;
		cout << "Четвертий елемент масиву A(indexing):" << endl;
		cout << A[3] << endl << endl;

		cout << "Другий масив B:" << endl;
		cin >> B;

		/*cout << "Присвоєння A = B :" << endl;
		A = B;
		cout << A;*/

		cout << "Порівняння масивів:" << endl;
		C = B < A;
		bool q;
		for (int a = 0; a < 5; a++)
		{
			if (C[a] == 1)
				q = true;
			else
				q = false;
		}
		if (q)
			cout << "Рівні";
		else
			cout << "Різні";
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}