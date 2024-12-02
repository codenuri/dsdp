#include <iostream>

class Animal
{
public:
	// non-virtual : static binding 해달라는 의미
	//				 포인터 타입으로 함수 호출을 결정해 달라.
	void cry1() { std::cout << "Animal cry1" << std::endl; }


	// virtual function : dynamic binding 해달라는 의미
	//				실행할때 메모리 조사후 호출을 결정해 달라.
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};

class Dog : public Animal
{
public:	
	void cry1() { std::cout << "Dog cry1" << std::endl; }
	virtual  void cry2() { std::cout << "Dog cry2" << std::endl; }
};

int main()
{
	Dog d;	  

	Animal* p = &d; 

	p->cry1();  // static binding, 포인터 타입으로 결정
	p->cry2();  // dynamic binding, 실행시간 메모리 조사후 결정
}

