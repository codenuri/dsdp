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

	// static_cast : 컴파일 시간 캐스팅
	Dog* pdog = static_cast<Dog*>(p1);

	std::cout << pdog << std::endl;


}











