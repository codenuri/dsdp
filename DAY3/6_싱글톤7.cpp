
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

	// C++11 ���� static ���������� ������ ȣ����
	// "���" ��ü���� ����ȭ ���� �����մϴ�.
	// ����ȭ ����� "spinlock(busy wait)" �Դϴ�

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








