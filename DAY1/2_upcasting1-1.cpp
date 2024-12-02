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
	// => 컴파일러는 컴파일 시간에 p1이 가리키는 곳을 알수도 없고, 
	//    조사할수 없습니다.
	// => 따라서 아래 코드는 항상 성공합니다.(잘못된 캐스팅이지만)
	//    이경우 pdog 를 사용하면 "미정의 동작 발생"
	// => 결론, p1 이 가리키는 곳이 Dog 라는 확신이 있을때만
	//    static_cast 해야 합니다.
	Dog* pdog1 = static_cast<Dog*>(p1);
	
	std::cout << pdog1 << std::endl;

	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p1이 가리키는 곳을 조사해서
	//				  Dog 가 맞을때만 캐스팅 성공.
	//				  Dog 가 아닌 경우 0 반환
	Dog* pdog2 = dynamic_cast<Dog*>(p1);

	std::cout << pdog2 << std::endl;
}











