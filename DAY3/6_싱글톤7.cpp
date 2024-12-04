
#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:

	// �Ʒ� �Լ��� ��Ƽ������ ȯ�濡�� �����ұ��?
	// => ���� �Ѱ��� ��ü�� �����ǰ�, Cursor �� ������ ȣ���� 
	//    ����ȭ ���� �����Ҽ� ������� ?

	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();

}








