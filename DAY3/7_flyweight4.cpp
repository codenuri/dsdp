#include <iostream>

// �����Ϸ��� flyweight

int main()
{
	// �Ʒ� 2���� ������(�޸𸮱���)�� ������ ������
	char sa[] = "hello";

//	char* sp = "hello";	// �� �ڵ��
						// C ��� ok. C++ ����

	const char* sp = "hello"; // C++�� ok..
							  // ���ڿ� �����ʹ� "char*" �� �ƴ�
							  // "const char*" �� �����Ѿ� �Ѵ�.


	*sa = 'X'; // ok. stack �� R/W ����
	*sp = 'X'; // char* sp ��� runtime error. sp �� ����Ű�� ���� ����޸�
				// const char* sp ��� compile-error
}