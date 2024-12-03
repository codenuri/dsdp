#include <cstdlib> // malloc/free

// github.com/codenuri/day2.zip
// 
// vector �� ���� ����� ������ �ʽ��ϴ�.
// vector �� ����ϴ� �޸� �Ҵ� ����� ��ü �����ؾ� �մϴ�.

// ��� #1. template method ���
// => ���ϴ� ���� �����Լ���
// => �޸� �Ҵ� ����� �����Ҽ� �־�� �ϹǷ�
// => �޸� �Ҵ�/���� �Լ��� �����Լ���!   


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = allocate(size);
	}
	~vector()
	{
		deallocate(buff, size);
	}

	// vector�� ��� ����Լ����� �޸� �Ҵ�/������ �ʿ��ϸ�
	// �Ʒ� �����Լ� ���
	virtual T* allocate(int sz)           { return new T[sz]; }
	virtual void deallocate(T* p, int sz) { delete[] p; }
};
//----------------------------------
// �޸� �Ҵ�/���� ����� �����Ϸ��� �Ļ� Ŭ������ ����
// ��ӵ� �����Լ��� override �ϸ� �˴ϴ�.
template<typename T> class MallocVector : public vector<T>
{
public:
	MallocVector( int sz ) : vector<T>(sz) {}

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
//	vector<int> v(4);
	MallocVector<int> v(4);
}

