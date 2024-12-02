#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// 함수 override : 기반 클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry(); // "Animal cry"
	Dog d;	  d.cry(); // "Dog cry" 

	Animal* p = &d; // 객체는 Dog 인데, 포인터는 Animal* 타입

	p->cry(); // 이 코드는 어떤 함수를 호출할까요 ?
			  // 어떤 함수를 호출하는것이 논리적으로 맞을까요 ?
}



