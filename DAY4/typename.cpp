// ����
class Sample
{
	inline static int value = 10;
	using DWORD = int;
};
int p = 0;

template<typename T>
void foo()
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
//	Sample::value* p;		// ���ϱ� �ǹ�
//	Sample::DWORD* p;		// ������ ������ ����

	// "Ŭ�����̸�::�̸�" ���� "�̸�" ��
	// 1. �� �ϼ� �ִ� : static ��� ����Ÿ, enum �����..
	// 2. Ÿ���ϼ� �ִ� : ����(typedef, using)
	// => �̸��� �ǹ̿� ���� * ���� �������� �ǹ̰� �޶�����.

	// �Ʒ� �ڵ带 �����Ϸ��� ��� �ؼ��ؾ� �ұ�� ?
	T::value* p;
	T::DWORD* p;
}

int main()
{

}