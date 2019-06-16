// kustTochki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct tochka {
	char name;
	double x, y;
};



void vvod(tochka *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i].name = (char)((int)'A' + rand() % 26);
		a[i].x = rand() % 50 + 10;
		a[i].y = rand() % 50 + 10;
	}
}

void vvod2(tochka *a, int n) {
	double X, Y;
	for (int i = 0; i < n; i++) {
		cin >> X;
		a[i].x = X;
		cin >> Y;
		a[i].y = Y;
	}
}

void vivod(tochka *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].name << " " << "(" << a[i].x << ";" << a[i].y << ")" << "   ";
	}
	cout << endl;
}

void vivodTreh(tochka a, tochka b, tochka c) {
	cout << a.name << " " << "(" << a.x << ";" << a.y << ")" << "   ";
	cout << b.name << " " << "(" << b.x << ";" << b.y << ")" << "   ";
	cout << c.name << " " << "(" << c.x << ";" << c.y << ")" << "   ";
	cout << " не составляют треугольник"<< endl;

}

void vivodTrehTreug(tochka a, tochka b, tochka c) {
	cout << a.name << " " << "(" << a.x << ";" << a.y << ")" << "   ";
	cout << b.name << " " << "(" << b.x << ";" << b.y << ")" << "   ";
	cout << c.name << " " << "(" << c.x << ";" << c.y << ")" << "   ";
	cout << " составляют треугольник" << endl;

}

void vivodPryamoi(double k, double b) {
	if (k == 1) {
		if (b == 0) {
			cout << "Уравнение прямой: y = " << "x"<< endl;
		}
		else
		{
			cout << "Уравнение прямой: y = " << "x + " << b << endl;
		}
		
	}
	else
	{
		if (k == 0) {
			cout << "Уравнение прямой: y = " <<  b << endl;
		}
		else
		{
			if (b == 0) {
				cout << "Уравнение прямой: y = " << k << "*x" << endl;
			}
			else
			{
				cout << "Уравнение прямой: y = " << k << "*x + " << b << endl;
			}
		}
		
	}
	
}

bool treug(tochka a, tochka b, tochka c) {
	double ab = floor(sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))*100+.5)/100;
	double ac = floor(sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y)) * 100 + .5) / 100;
	double bc = floor(sqrt((c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y)) * 100 + .5) / 100;
	if (ab + bc <= ac) {
		return false;
	}
	else
	{
		if (ab + ac <= bc) {
			return false;
		}
		else
		{
			if (ac + bc <= ab) {
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

double FindK(tochka a, tochka b) {
	return (b.y - a.y) / (b.x - a.x);
}

double FindB(tochka a, tochka b) {
	//return(b.x - a.y - a.x*b.y) / (b.x - a.x);
	return b.y - (b.y - a.y) / (b.x - a.x)*b.x;
}

int main()
{
	setlocale(0, "rus");
	const int n = 5;
	tochka a[n];
	vvod2(a, n);
	vivod(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			for (int l = j; l < n; l++) {
				if (i != j && i != l && j != l) {
					if (!treug(a[i], a[j], a[l])) {
						vivodTreh(a[i], a[j], a[l]);
						vivodPryamoi(FindK(a[i], a[l]), FindB(a[i], a[l]));
					}
					else 
					{
						vivodTrehTreug(a[i], a[j], a[l]);
					}
				}
			}
		}
	}
	
}

