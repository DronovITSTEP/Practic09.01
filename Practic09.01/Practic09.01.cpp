#include <iostream>

using namespace std;

/*
Есть стопка оладий различного радиуса. Единственная
операция, проводимая с ними — между любыми двумя суем
лопатку и меняем порядок оладий над лопаткой на обратный.
Необходимо за минимальное количество операций таких
отсортировать снизу вверх по убыванию радиуса.
*/

const int SIZE = 10;
//массив оладий
int pancakes[SIZE]{12,6,10,23,41,1,19,26,45,37 };

int temp, counter = 0; // кол-во переворотов

// максимальный оладь и его позиция в массиве
int max_pan, max_index = 0;

void findMaxPancake(int i); // поиск максимального размера и его позиции
void sortPancake(); // для переворачивания стопки
void maxPancakeDown(int i);

int main()
{
	for (int i = 0; i < SIZE; i++) {
		findMaxPancake(i);

		if (pancakes[i] == max_pan && i >= max_index) continue;
		else {
			sortPancake();
			for (int i = 0; i < SIZE; i++) {
				cout << pancakes[i] << " ";
			}
			cout << endl << endl;
			maxPancakeDown(i);
		}
	}

	for (int i = 0; i < SIZE; i++) {
		cout << pancakes[i] << " ";
	}
	cout << endl << endl;
	cout << endl << counter;
}

void findMaxPancake(int i) {
	max_pan = pancakes[i];
	for (int j = i; j < SIZE; j++) {
		if (max_pan < pancakes[j]) {
			max_pan = pancakes[j];
			max_index = j;
		}
	}
}
void sortPancake() {
	for (int j = max_index, h = SIZE - 1; j < h; j++, h--) {
		temp = pancakes[j];
		pancakes[j] = pancakes[h];
		pancakes[h] = temp;
	}
	counter++;
}
void maxPancakeDown(int i) {
	for (int j = i, h = SIZE - 1; j < h; j++, h--) {
		temp = pancakes[j];
		pancakes[j] = pancakes[h];
		pancakes[h] = temp;
	}
	counter++;
}

/*
Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива вправо.
Например:
Дан массив:
	4 5 6 7
	1 2 4 1
	4 5 6 9

Сдвигаем на три вправо:
	5 6 7 4
	2 4 1 1
	5 6 9 4
*/
void stepArrRight(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int i = 0; i < row; i++) {
			int temp = arr[i][col - 1];
			for (int j = col - 1; j > 0; j--) {
				arr[i][j] = arr[i][j - 1];
			}
			arr[i][0] = temp;
		}
		stepArrRight(arr, row, col, --step);
	}
}

/*
Сдвиг вниз на 2:
	1 2 4 1
	4 5 6 9
	4 5 6 7
*/
void stepArrDown(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int j = 0; j < col; j++) {
			int temp = arr[row - 1][j];
			for (int i = row - 1; i > 0; i--) {
				arr[i][j] = arr[i - 1][j];
			}
			arr[0][j] = temp;
		}
		stepArrDown(arr, row, col, --step);
	}
}