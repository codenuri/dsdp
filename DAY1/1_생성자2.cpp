// github.com/codenuri/dsdp/OT.txt �о� ������

#include <iostream>

class Base
{
public:
	// �ٽ� : Base ���� ����Ʈ ������(���ھ��� ������)�� �����ϴ�.
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// �ٽ� #1. �Ʒ� �ڵ尡 �� �������� ������ ������
//	Derived()		{ }		// Derived()	  : Base()	{ }
//	Derived(int a)	{ }		// Derived(int a) : Basae()	{ }

	// �ٽ� #2. ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ� 
	//         �ݵ�� �Ļ� Ŭ���� �����ڿ��� ���� ��� Ŭ���� �����ڸ�
	//         ȣ���ϴ� �ڵ带 �����ؾ� �մϴ�.
	Derived()      : Base(0) {}		
	Derived(int a) : Base(a) {}	


};

int main()
{

}
