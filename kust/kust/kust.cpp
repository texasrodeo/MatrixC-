// kust.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


using namespace std;

int** CreateMatrix(int size)
{
	int **a;
	a = new int*[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
		for (int j = 0; j < size; j++)
			a[i][j] = rand() % 10;//только однозначные числа
	}
	return a;
}

void OutputMatrix(int **Matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int SumDiagonals(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				sum += Matrix[i][j];
				sum += Matrix[i][size - 1 - j];
			}
				
		}
		
	}
	return sum;
}

int SumAboveMain(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < j)
				sum += Matrix[i][j];
		}

	}
	return sum;
}

int SumUnderMain(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i > j)
				sum += Matrix[i][j];
		}

	}
	return sum;
}

int SumAboveSide(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= 0; j--) {
			if (i + j < size - 1)
				sum += Matrix[i][j];
				
		}

	}
	return sum;
}

int SumUnderSide(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size;j++) {
			if (i + j > size - 1)
				sum += Matrix[i][j];
		}

	}
	return sum;
}

int SumAboveMainAndSide(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < j && i + j < size - 1)
				sum += Matrix[i][j];
		}
	}
	return sum;
}

int SumPerimetr(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0 || i == size - 1) {
			for (int j = 0; j < size; j++) {
				
					sum += Matrix[i][j];
			}
		}
		else
		{
			for (int j = 0; j < size; j++) {
				if (j == 0 || j == size - 1)
					sum += Matrix[i][j];
			}
		}
		
	}
	return sum;
}

int SumUnderMainAndAboveSide(int **Matrix, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i > j && i + j < size - 1)
				sum += Matrix[i][j];
		}
	}
	return sum;
}

int main()
{
	setlocale(0, "rus");
	cout << "Введите размер квадратной матрицы:" << endl;

	int size;
	cin >> size;
	int **Matrix = CreateMatrix(size);
	OutputMatrix(Matrix, size);
	cout << "Сумма диагоналей: " << SumDiagonals(Matrix, size) << endl;
	cout << "Сумма над главной диагональю: " <<SumAboveMain(Matrix, size)<<endl;
	cout <<"Сумма под главной диагональю: " << SumUnderMain(Matrix, size)<<endl;
	cout << "Сумма над побочной: " <<SumAboveSide(Matrix, size)<<endl;
	cout << "Сумма под побочной: " <<SumUnderSide(Matrix, size)<<endl;
	cout << "Сумма выше главной и побочной: " << SumAboveMainAndSide(Matrix, size) << endl;
	cout << "Сумма ниже главной и выше побочной: " << SumUnderMainAndAboveSide(Matrix, size) << endl;
	cout << "Сумма по периметру: " << SumPerimetr(Matrix, size) << endl;
}


