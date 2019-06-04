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

void vivod(tochka *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].name << " " << "(" << a[i].x << ";" << a[i].y << ")" << "   ";
	}
}

void vivodTreh(tochka a, tochka b, tochka c) {
	cout << a.name << " " << "(" << a.x << ";" << a.y << ")" << "   ";
	cout << b.name << " " << "(" << b.x << ";" << b.y << ")" << "   ";
	cout << c.name << " " << "(" << c.x << ";" << c.y << ")" << "   ";
	cout << " не составляют треугольник"<<endl;

}

void vivodPryamoi(double k, double b) {
	cout << "Уравнение прямой: " << k << "*x+ " << b;
}

bool treug(tochka a, tochka b, tochka c) {
	double ab = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	double ac = sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y));
	double bc = sqrt((c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y));
	if (ab + bc < ac) {
		return false;
	}
	else
	{
		if (ab + ac < bc) {
			return false;
		}
		else
		{
			if (ac + bc < ac) {
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
	return (b.y - a.y) / (b.x - b.y);
}

double FindB(tochka a, tochka b) {
	return(b.x - a.y - a.x*b.y) / (b.x - a.x);
}

int main()
{
	setlocale(0, "rus");
	const int n = 10;
	tochka a[n];
	vvod(a, n);
	vivod(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				if (i != j && i != l && j != l) {
					if (!treug(a[i], a[j], a[l])) {
						vivodTreh(a[i], a[j], a[l]);
						vivodPryamoi(FindK(a[i], a[l]), FindB(a[i], a[l]));
					}
				}
			}
		}
	}
}


