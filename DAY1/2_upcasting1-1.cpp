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
	Dog* pdog = static_cast<Dog*>(p1);
	
	std::cout << pdog << std::endl;


}











