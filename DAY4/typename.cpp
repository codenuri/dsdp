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
	Sample::value* p;
	Sample::DWORD* p;
}