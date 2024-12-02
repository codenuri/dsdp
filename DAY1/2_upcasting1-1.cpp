// 2_upcasting1-1.cpp 
#include <iostream>

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
class Cat : public Animal
{
public:
	int speed;
};

int main()
{
	Dog d;
	Cat c;

	Animal* p1 = &c;

	// �ٽ� #1. p1�� ����Ű�� ��ü�� ���� �ð��� ����ɼ� �ֽ��ϴ�.
	// => ���� p1 �� � ��ü�� ����Ű������ ������ �ð�����
	//   �˼� �����ϴ�
	//if (������Է� == 1) p1 = &d;

	// static_cast : ������ �ð� ĳ����
	// => �����Ϸ��� ������ �ð��� p1�� ����Ű�� ���� �˼��� ����, 
	//    �����Ҽ� �����ϴ�.
	// => ���� �Ʒ� �ڵ�� �׻� �����մϴ�.(�߸��� ĳ����������)
	//    �̰�� pdog �� ����ϸ� "������ ���� �߻�"
	// => ���, p1 �� ����Ű�� ���� Dog ��� Ȯ���� ��������
	//    static_cast �ؾ� �մϴ�.
	Dog* pdog1 = static_cast<Dog*>(p1);
	
	std::cout << pdog1 << std::endl;

	// dynamic_cast : ����ð� ĳ����
	//				  ����ð��� p1�� ����Ű�� ���� �����ؼ�
	//				  Dog �� �������� ĳ���� ����.
	//				  Dog �� �ƴ� ��� 0 ��ȯ
	Dog* pdog2 = dynamic_cast<Dog*>(p1);

	std::cout << pdog2 << std::endl;
}











