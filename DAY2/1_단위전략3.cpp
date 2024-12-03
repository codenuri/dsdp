// ��� #2. strategy ���� ����
// => ���ϴ� ��(�޸� �Ҵ�/���� ���)�� ������ Ŭ������ ��������.

// ��ü�ؾ� �ϹǷ� �������̽��� ���� ����

template<typename T>
struct IAllocator
{
	virtual T* allocate(int sz) = 0;
	virtual void deallocate(T* p, int sz) = 0;
	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = new T[size];
		//....
	}
	~vector()
	{
		delete[] buff;
		//....
	}
};

int main()
{
	vector<int> v(4);
}


