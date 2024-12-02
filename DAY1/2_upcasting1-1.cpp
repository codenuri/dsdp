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

	// 핵심 #1. p1이 가리키는 객체는 실행 시간에 변경될수 있습니다.
	// => 따라서 p1 이 어떤 객체를 가리키는지는 컴파일 시간에는
	//   알수 없습니다
	//if (사용자입력 == 1) p1 = &d;

	// static_cast : 컴파일 시간 캐스팅
	Dog* pdog = static_cast<Dog*>(p1);
	
	std::cout << pdog << std::endl;


}











