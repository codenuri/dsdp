// vector �� ���� ����� ������ �ʽ��ϴ�.
// vector �� ����ϴ� �޸� �Ҵ� ����� ��ü �����ؾ� �մϴ�.

// ��� #1. template method ���
// => 


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = new T[size];
	}
	~vector()
	{
		delete[] buff;
	}
};

int main()
{
	vector<int> v(4);
}

