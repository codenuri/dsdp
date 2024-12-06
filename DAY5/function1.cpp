// function1.cpp
#include <iostream>
#include <functional>

void f1(int n1) {}
void f2(int n1, int n2) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // 4�� �Լ�

	// std::bind : �Լ��� ���ڸ� ������ ���ο� �Լ��� ����� ����
	// ���� : std::bind(M���Լ��ּ�, M�� ���� )

	auto a1 = std::bind(&f4, 1, 2, 3, 4); // 4���Լ� => 0���Լ�

	a1(); // f4(1,2,3,4)


	auto a2 = std::bind(&f4, 5, _1, 7, _2);

	a2(3, 8); // f4(5, 3, 7, 8);
}