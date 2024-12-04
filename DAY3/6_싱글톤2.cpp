#include <iostream>

// static �������� vs static ��� ����Ÿ 

// static �������� : get_instance() �� ȣ����� ������ �������� �ʴ´�.
//					get_instance() �� ó�� ȣ��ɶ� Cursor ����(������ ȣ��)
//					=> ������ �ʱ�ȭ. �ʿ��� ��츸(����) ����ڴ�
//

// static ��� ����Ÿ : get_instance() �� ȣ����� �ʾƵ� Cursor ����
//					=> ���α׷��� ó�� load�ɶ�(main�Լ� ȣ������)�� 
//						������ ȣ��
//					=> �̸�(early) �ʱ�ȭ
//					=> ��Ī�ÿ� ��� �ʱ�ȭ �ϰ�, �����߿��� ������ �ϰ� ������
//						�̹�ĵ� ������ �ʴ�.


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;		// ���ڵ�� ���� ����
	static Cursor instance; // �� �ڵ�� ���� �ƴմϴ�.
public:
	static Cursor& get_instance()
	{
//		static Cursor instance;

		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();

}







