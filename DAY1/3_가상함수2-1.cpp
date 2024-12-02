#include <iostream>

// �Ʒ� �� ���� �ڵ尡 ������ �Ҹ��ڰ� ������ �ƴϾ �˴ϴ�.
// => �����Լ��� �����ϴ�.
// Base* p = new Derived;
// delete p;

// �Ǵٸ� �ذ�å

class Base
{

protected:
	~Base() {}	
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;

//	delete p;	// ������ ����, protected �Ҹ���

	delete  static_cast<Derived*>(p); // ok

}

// ����, "C++ core guideline" �˻�
// 1��° ��ũ ����
// => C++ â���ڿ� ǥ�� �������� �ߴ� �����ڰ� ����� �ִ� 
//    guide line

 