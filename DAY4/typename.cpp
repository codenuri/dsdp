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
	// dependent name : ���ø� ���� T �� �����ؼ� ��� �̸�!!
	//				    => �����Ϸ��� ������ ������ �ؼ�
	T::value* p;
//	T::DWORD* p2;	// error. ���ϱ�� �ؼ��ؾ� �ϴµ�, p2 ��� ������ ����
	typename T::DWORD* p2; // ok. dependent name �� ���� �ƴ�
							//    Ÿ������ �ؼ��� �޶�.
							//    p2�� ������ ������ �������� �ؼ�
}

int main()
{

}