#include <iostream> 
using namespace std;
#define tab "\t"

void fillrand(int** arr, int rows, int cols);
void Print(int** arr, int rows, int cols);

void push_cols_front(int**& arr, int rows, int& cols);
void push_cols_back(int**& arr, int rows, int& cols);
void insert_cols(int**& arr, int rows, int& cols);
void Add_cols(int**& arr, int rows, int& cols);

void pop_cols_front(int**& arr, int rows, int& cols);
void pop_cols_back(int**& arr, int rows, int& cols);
void erase_cols(int**& arr, int rows, int& cols);
void Delete_cols(int**& arr, int rows, int& cols);

int main()
{
	setlocale(LC_ALL, "rus");
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество колонок: "; cin >> cols;
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		arr[i] = new int[cols] {};
	}

	fillrand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Выберите действие" << endl;
	cout << "1 - Добавление строки"
		"\n2 - Удаление строки" << endl;
	int choice; cin >> choice;
	switch (choice)
	{
	case 1:
		Add_cols(arr, rows, cols);
		break;
	case 2:
		Delete_cols(arr, rows, cols);
	}
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;

	int rep;
	cout << "Для повтора 1(выход 0): "; cin >> rep;
	switch (rep)
	{
	case 1:
		main();
		break;
	case 0:
		return 0;
	}
	
}

void fillrand(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = rand() % 100;
		}
	}

}
void Print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void push_cols_front(int**& arr, int rows, int& cols)
{
	cols++;
	int** buffer = new int* [rows] {};

	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols];
		
		for (int j = 0; j < cols; j++) {

			if (j == 0) {
				buffer[i][j] = 1;
			}
			else
				buffer[i][j] = arr[i][j - 1];
        }
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void push_cols_back(int**& arr, int rows, int& cols)
{
	cols++;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++) {

			if (j == cols - 1) {
				buffer[i][j] = 1;
			}
			else
				buffer[i][j] = arr[i][j];
		}
    }

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void insert_cols(int**& arr, int rows, int& cols)
{
	int index;
	cout << "Введите куда вставить строку: "; cin >> index;
	cols++;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};
		
		for (int j = 0; j < cols; j++) {

			if (j > index) {
				buffer[i][j] = arr[i][j - 1];
			}
			if (j == index) {
				buffer[i][j] = 1;
			}
			if(j < index)
				buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void Add_cols(int**& arr, int rows, int& cols)
{
	int choice;
	cout << "Выберите куда добавить строку." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_cols_front(arr, rows, cols);
		break;
	case 2:
		push_cols_back(arr, rows, cols);
		break;
	case 3:
		insert_cols(arr, rows, cols);
	}
}

void pop_cols_front(int**& arr, int rows, int& cols)
{
	cols--;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j + 1];
		}
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;

}
void pop_cols_back(int**& arr, int rows, int& cols)
{
	cols--;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	
}
void erase_cols(int**& arr, int rows, int& cols)
{
	int index;
	cout << "Введите какую строку удалить: "; cin >> index;
	cols--;
	int** buffer = new int* [rows] {};

	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[cols] {};

		for (int j = 0; j < cols; j++) {

			if (j < index) {
				buffer[i][j] = arr[i][j];
				
			}
			if (j >= index) {
				buffer[i][j] = arr[i][j+1];
			}
		}
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void Delete_cols(int**& arr, int rows, int& cols)
{
	int choice;
	cout << "Выберите какую строку удалить." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_cols_front(arr, rows, cols);
		break;
	case 2:
		pop_cols_back(arr, rows, cols);
		break;
	case 3:
		erase_cols(arr, rows, cols);
	}
}