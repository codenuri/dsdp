#include <stdio.h>

int main()
{
	int x[3] = { 1,2,3 };

	int(*p1)[3] = &x;  // �迭�� �ּ�

	int* p2 = x;   // �迭�� 1��° ����� �ּ�


	int y[3][2] = { 1,2,3,4,5,6 };

	? p3 = &y;
	? p4 = y;

	int z[3][2][2] = { 0 };
	? p5 = &z;
	? py = z;


}