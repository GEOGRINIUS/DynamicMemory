#include<iostream>

using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int ROWS, const int COLS);

template<typename T>void Print(T arr[], const int n);
void Print(int** arr, const int ROWS, const int COLS);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T arr[], int& n, T value);
template<typename T>T* insert(T arr[], int& n, T value, int index);
template<typename T>
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int** pop_row_back(int** arr, int& rows, const int cols);
void pop_col_back(int** arr, const int rows, int& cols);

int** pop_row_front(int** arr, int& rows, const int cols);
void pop_col_front(int** arr, const int rows, int& cols);


//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	cout << "DynamicMemory" << endl;
	int n = 5;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_back(arr, n, 3.14);
	Print(arr, n);
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_front(arr, n, 2.7);
	Print(arr, n);
	int index;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	arr = insert(arr, n, 9.11, 3);
	Print(arr, n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	Print(arr = erase(arr, n, index), n);
	delete[] arr;
#endif //DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "¬ведите количество строк: "; cin >> rows;
	cout << "¬ведите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);

#endif // DYNAMIC_MEMORY_2
	int n = 5;
	cout << "¬ведите размер массива: "; cin >> n;
	double* arr = new double[n];

	FillRand(arr, n);
	Print(arr, n);

	arr = push_back(arr, n, 3.14);
	Print(arr, n);

	arr = push_front(arr, n, 2.7);
	Print(arr, n);

	arr = insert(arr, n, 9.11, 3);
	Print(arr, n);

	delete[] arr;

}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;
}
void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>
T* push_back(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		buffer[0] = 0; // явно задаЄм значение дл€ нового столбца
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
T* insert(T arr[], int& n, T value, int index)
{
	if (index > n)return arr;
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = value;
	delete[] arr;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}


int* erase(int arr[], int& n, int index)
{
	if (index >= n)return arr;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	return buffer;
}
