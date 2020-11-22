#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

//1 спосіб;
void create(int* a, const int n, const int min, const int max, int i)
{
	a[i] = min + rand() % (max - min + 1);
	if (i < n - 1)
		create(a, n, min, max, i + 1);

}


void print(int* a, const int n, int i)
{
	cout << " " << a[i] << "; ";
	if (i < n - 1)
		print(a, n, i + 1);
	else 
	cout << endl;
}


void inverse(int* a, const int n, int i)
{
		int tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
		i++;
		if (i < n - 1)
			inverse(a, n, i + 1);
}

// 2 спосіб із шаблонами функцій

template <typename T>
void create(T* a, const int n, T min, T max, T i)
{
	a[i] = min + rand() % (max - min + 1);
	if (i < n - 1)
		create(a, n, min, max, i + 1);
}

template <typename T>
void print(T* a, const int n, T i)
{
	cout << " " << a[i] << "; ";
	if (i < n - 1)
		print(a, n, i + 1);
	else
		cout << endl;
}

template <typename T>
T inverse(T* a, const int n, T i)
{
	int tmp = a[i];
	a[i] = a[i + 1];
	a[i + 1] = tmp;
	if (i < n - 1)
		inverse(a, n, i + 1);

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int min = -10;
	int max = 10;
	const int n = 10;
	int a[n];

	create(a, n, min, max, 0);
	cout << "Масив із рандомних чисел:" << endl;
	print(a, n, 0);
	cout << endl;
	cout << "Масив із інверсією: " << endl;
	inverse(a, n, 0);
	print(a, n, 0);
	cout << endl;
	system("pause");
}