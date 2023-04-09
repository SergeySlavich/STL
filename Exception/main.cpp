#include<iostream>
using namespace std;

//define EXCEPTION_BASICS
//#define DIVISION_BY_ZERO

int factorial(int n)
{
	if (n > 12) throw std::exception("Arithmetical overflow.");
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}


void main()
{
	setlocale(LC_ALL, "");
#ifdef EXCEPTION_BASICS

	try
	{
		//throw 1;
		//throw "Somthing went wrong";
		throw std::exception("STD exception trown");
	}
	catch (int e)
	{
		std::cerr << "Error #" << e << std::endl;
	}
	catch (const char* e)
	{
		std::cerr << "Error: " << e << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
		//метод what() возвращает сообщение об ошибке в виде C-string (const char*)
	}
	catch (...)
	{
		std::cerr << "Error: some exception was thrown..." << endl;
	}
	cout << "Final" << endl;
#endif // EXCEPTION_BASICS

#ifdef DIVISION_BY_ZERO

	int a, b; cout << "input two of numbers: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Somthing went wrong!" << endl;
	}
#endif // DEBUG


	int n;
	cout << "Input number:"; cin >> n;
	try
	{
		cout << factorial(n) << endl;
	}
	catch (exception& e)
	{
		std::cerr << e << endl;
	}
}