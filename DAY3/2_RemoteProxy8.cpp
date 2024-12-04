#include <memory>
#include "ICalc.h"

int main()
{
	// C++ ǥ�ؿ� �̹� ����Ʈ�����Ͱ� �ִµ�(std::shared_ptr)
	// �װ��� ����ϸ� �ȵǳ��� ?

	std::shared_ptr<ICalc> p1(load_proxy());
						// p1 �� �Ҹ��ڿ��� "delete" �ϰ� �˴ϴ�
						// ��, DLL���� new �Ѱ��� exe �� delete �ϴ°�
						// �츮���� �ʿ��Ѱ��� delete �� �ƴ� Release()ȣ��

	sp<ICalc> p2(load_proxy());
				// p2 �� �Ҹ��ڿ��� 
				// "�������ּ�->Release()"

	// �׷��� C++ ǥ�ؿ� �̹� ����Ʈ�����Ͱ� ������
	// ���� ���¼ҽ��� �پ��� ������ "�ڽŸ��� ����Ʈ ������ ����"
	// ���� �ȵ���̵� �ҽ��� "sp" �� �ֽ��ϴ�.(������� ����)
}