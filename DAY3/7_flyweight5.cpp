#include <iostream>

int main()
{
	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	// �Ʒ� ��� ������ ������(���� �ּ�? �ٸ� �ּ�)
	printf("%p\n", sa1);
	printf("%p\n", sa2);

	printf("%p\n", sp1);
	printf("%p\n", sp2);

}