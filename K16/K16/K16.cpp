/*
����������� ��������-��������������� ��������� ��� ���������� ������� ����������,
� ������� ����������� �����������, �������� ������������ ����� ������ �� ���������.
��� ���������� ������ ������������ ��������� �������� ������ ������������ �����.
�������� ������� ��������� ���������� ��� ������� ��������� ������������ ������
������������ � ������ ������������ ������.

����������� ���������� ���������� ������ ���� �������� �� ���������� �������������
������ ������������. ��� ����������-������ ������ �������� ���������� ������ �����
��� ��������� ������ ������������, � ��� ������������ ����� ������ ��������� ������
��������� ����������. ������������ ������� ������������ � ����� ������ ������������
������ ������������� ������������ ������.
*/

#include <iostream>
#include "Dot.h"
#include "Rectangle.h"

using namespace std;

bool inputFunc(Triangle* temp)
{
	//std::cin.clear();
	double x, y;
	Dot p[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter point[" << i + 1 << "] coordinats in format: x y." << endl;

		cin >> x >> y;
		if (std::cin.fail()) //if it return true, previous input failed
			return true;

		Dot t(x, y);
		p[i] = t;
	}
	Triangle rect(p[0], p[1], p[2]);
	*temp = rect;
	return false;
}

int main()
{
	Triangle aXzKakNazvat;

	cout << "This program counts the radius of the described circle around the triangle." << endl;

	while (true)
	{
		cout << "New triangle:" << endl;
		if (inputFunc(&aXzKakNazvat))
		{
			cout << "Error. Incorrect input. Terminate." << endl << endl;
			break;
		}

		double R;
		if (!(R = aXzKakNazvat.calcRadius()))
			cout << "Error. The triangle doesn't exist. R=0." << endl;
		else
			cout << "Described circle around this triangle is " << R << "." << endl << endl;

	}
	return 0;
}