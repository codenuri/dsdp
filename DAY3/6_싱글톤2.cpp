#include <iostream>

// static �������� vs static ��� ����Ÿ 

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;		// ���ڵ�� ���� ����
//	static Cursor instance; // �� �ڵ�� ���� �ƴմϴ�.
public:
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}
};
//Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

//	Cursor& c1 = Cursor::get_instance();

}







