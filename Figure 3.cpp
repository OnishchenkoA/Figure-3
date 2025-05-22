#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class Figure
{
protected:
	std::string name = "Фигура";
	int sides = 0;
	//bool correct = false;

	virtual bool Check()
	{
		if (sides == 0)
		{
			return true;
		}
		else { return false; }
	}

public:
	virtual void print_info()
	{
		std::cout << name << ":" << std::endl;
		if (Check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }
		std::cout << "Количество сторон: " << sides << std::endl;
	}
	
};

class Triangle : public Figure
{
protected:
	double a = 0, b = 0, c = 0;
	double A = 0, B = 0, C = 0;
	
public:
	Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Треугольник";
		sides = 3;
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	bool Check() override
	{
		if ((get_A() + get_B() + get_C()) == 180) { return true; }
		else { return false; }
	}
	void print_info() override
	{
		std::cout << std::endl;
		Figure::print_info();
		std::cout << "Стороны: " << "a = " << get_a() << "  b = " << get_b() << "  c = " << get_c() << std::endl;
		std::cout << "Углы: " << "A = " << get_A() << "  B = " << get_B() << "  C = " << get_C() << std::endl;
	}
};

class Pryamoug_Triangle : public Triangle
{
public:
	Pryamoug_Triangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
		name = "Прямоугольный треугольник";
	}
	bool Check() override
	{
		if (Triangle::Check() && (C = 90)) { return true; }
		else { return false; }
	}
};

class Ravnobedr_Triangle : public Triangle
{
public:
	Ravnobedr_Triangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{
		name = "Равнобедренный треугольник";
	}
	bool Check() override
	{
		if (Triangle::Check() && (a = c) && (A = C)) { return true; }
		else { return false; }
	}
};

class Ravnostor_Triangle : public Triangle
{
public:
	Ravnostor_Triangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{
		name = "Равносторонний треугольник";
	}
	bool Check() override
	{
		if (Triangle::Check() && (a = b = c) && (A = B = C = 60)) { return true; }
		else { return false; }
	}
};

class Quadrangle : public Figure
{
protected:
	double a, b, c, d;
	double A, B, C, D;
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
		name = "Четырёхугольник";
		sides = 4;
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_d() { return d; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	double get_D() { return D; }
	bool Check() override
	{
		if ((get_A() + get_B() + get_C() + get_D()) == 360) { return true; }
		else { return false; }
	}
	void print_info() override
	{
		std::cout << std::endl;
		Figure::print_info();
		std::cout << "Стороны: " << "a = " << a << "  b = " << b << "  c = " << c << " d = " << d << std::endl;
		std::cout << "Углы: " << "A = " << A << "  B = " << B << "  C = " << C << " D = " << D << std::endl;
	}
};

class Paralel : public Quadrangle
{
public:
	Paralel(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		name = "Параллелограмм";
	}
	bool Check() override
	{
		if (Quadrangle::Check() && (a = c) && (b = d) && (A = C) && (B = D)) { return true; }
		else { return false; }
	}
};

class Pryamoug : public Paralel
{
public:
	Pryamoug(double a, double b) : Paralel(a, b, 90, 90)
	{
		name = "Прямоугольник";
	}
	bool Check() override
	{
		if (Quadrangle::Check() && (a = c) && (b = d) && (A = B = C = D = 90)) { return true; }
		else { return false; }
	}
};

class Romb : public Paralel
{
public:
	Romb(double a, double A, double B) : Paralel(a, a, A, B)
	{
		name = "Ромб";
	}
	bool Check() override
	{
		if (Quadrangle::Check() && (a = b = c = d) && (A = C) && (B = D)) { return true; }
		else { return false; }
	}
};

class Square : public Romb
{
public:
	Square(double a) : Romb(a, 90, 90)
	{
		name = "Кварат";
	}
	bool Check() override
	{
		if (Quadrangle::Check() && (a = b = c = d) && (A = B = C = D =90)) { return true; }
		else { return false; }
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	Figure figure;
	figure.print_info();
	Triangle triangle(12, 26, 18, 65, 45, 92);
	triangle.print_info();
	Pryamoug_Triangle pryam_triangle(24, 86, 14, 65, 25);
	pryam_triangle.print_info();
	Ravnobedr_Triangle ravnobedr_triangle(48, 26, 65, 90);
	ravnobedr_triangle.print_info();
	Ravnostor_Triangle ravnostor_triangle(29);
	ravnostor_triangle.print_info();
	Quadrangle quadrangle(26, 12, 54, 68, 65, 35, 90, 45);
	quadrangle.print_info();
	Paralel paralel(26, 16, 95, 65);
	paralel.print_info();
	Pryamoug pryamoug(98, 42);
	pryamoug.print_info();
	Romb romb(19, 95, 120);
	romb.print_info();
	Square square(33);
	square.print_info();
}

