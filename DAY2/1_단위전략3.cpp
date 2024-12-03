#include <cstdlib>
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
	IAllocator<T>* alloc = nullptr;

public:
	// ���� vector �� ��� ��� �Լ�������
	// �޸� �Ҵ��� �ʿ��Ҷ� ����
	// "allocator(�޸� �Ҵ��)" ��ü�� �����ؾ� �մϴ�.
	vector(int sz, IAllocator<T>* p) : size(sz), alloc(p)
	{
		buff = alloc->allocate(sz);
	}
	~vector()
	{
		alloc->deallocate(buff, size);
	}
};

// ���� �پ��� ����� "�޸� �Ҵ��" Ŭ������ �����ϸ� �˴ϴ�.
// => IAllocator<T> �������̽��� �����ؼ� ����� �˴ϴ�.
template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	virtual T* allocate(int sz)
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	virtual void deallocate(T* p, int sz)
	{
		free(p);
	}
};

int main()
{
	MallocAllocator<int> ax;
	vector<int> v(4, &ax); // ax �� ����ؼ� �޸� ������ �޶�.
}


