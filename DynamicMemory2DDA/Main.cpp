#include<iostream>

using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int ROWS, const int COLS);

void Print(int** arr, const int ROWS, const int COLS);

int** insert_row(int** arr, int& rows, const int cols, int index);
int** erase_row(int** arr, int& rows, const int cols, int index);

int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int** pop_row_back(int** arr, int& rows, const int cols);
void pop_col_back(int** arr, const int rows, int& cols);

int** pop_row_front(int** arr, int& rows, const int cols);
void pop_col_front(int** arr, const int rows, int& cols);

void main()
{
	setlocale(LC_ALL, "");
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

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
	arr = insert_row(arr, rows, cols, 2); // Вставляем строку на позицию 2
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
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
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
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
		buffer[0] = 0; // Явно задаём значение для нового столбца
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int** insert_row(int** arr, int& rows, const int cols, int index)
{
	if (index < 0 || index > rows) return arr; // Проверка на корректность индекса
	// Создаём новый массив строк с увеличенным количеством строк
	int** new_arr = new int* [rows + 1];
	// Копируем строки до индекса
	for (int i = 0; i < index; i++)
		new_arr[i] = arr[i];
	// Создаём новую строку (заполняем нулями или другими значениями по умолчанию)
	new_arr[index] = new int[cols](); // () инициализирует нулями
	// Копируем строки после индекса
	for (int i = index; i < rows; i++)
		new_arr[i + 1] = arr[i];
	delete[] arr; // Удаляем старый массив строк
	rows++; // Увеличиваем количество строк
	return new_arr; // Возвращаем новый массив
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
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	if (index < 0 || index >= rows) return arr; // Проверка на корректность индекса
	int** buffer = new int* [rows - 1]; // Создаём новый массив строк с уменьшенным количеством строк

	for (int i = 0; i < index; i++)
		buffer[i] = arr[i]; // Копируем строки до индекса
	for (int i = index + 1; i < rows; i++)
		buffer[i - 1] = arr[i]; // Копируем строки после индекса

	delete[] arr[index]; // Удаляем строку, которую нужно удалить
	delete[] arr; // Удаляем старый массив строк
	rows--; // Уменьшаем количество строк
	return buffer; // Возвращаем новый массив
}
