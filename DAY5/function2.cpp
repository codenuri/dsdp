// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; 

void f1(int n1) {}
void f2(int n1, int n2) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	// C�� �Լ� �����ʹ� �������� �����մϴ�.
	/*
	void(*f)(int);

	f = &f1; // ok.. signature�� ����
	f = &f2; // error. ��, ������ ������ �ٸ��� ������ �����ϴ�.
	*/

	// C++ ������ �Լ� �������� �Ϲ�ȭ�� ������ std::function<> ����

	std::function<void(int)> f; // void(*f)(int) �� ����

	f = &f1; // ok
	f(10);   // f1(10).. ��, �Լ������Ϳ� �����ϰ� ���

//	f = &f2; // error. ������ ������ �ٸ�

	// �ٽ� : std::function<> �� std::bind�� ����� ������ �ֽ��ϴ�.
	// => ���ڰ� 1�� �̻��� ��� �Լ��� 
	// => std::bind ����, ���ڰ� 1���� ����� �ֽ��ϴ�.

	f = std::bind(&f2, 3, _1);
	f(5); // f2(3, 5)


	f = std::bind(&f4, 1, 2 , _1 , 3);
	f(5); // f4(1, 2, 5, 3) �ǰ� �غ�����
}