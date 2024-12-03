#include <cstdlib>

// ��� #3. �������� ������(Policy Base Design)

// std::allocator<T> : C++ ǥ�ؿ� �̹� �ִ� �޸� �Ҵ��
//					   ���������� new, delete ���
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<T> ax; // �̷��� �ϸ� ���� �����̹Ƿ� ��ü �ȵ�

	Alloc ax; // ���ø� ���ڷ� ���޵� Ÿ�� ���

public:
	vector(int sz ) : size(sz)
	{
		buff = ax.allocate(sz);
	}
	~vector()
	{
		ax.deallocate(buff, size);
	}
};

template<typename T> class MallocAllocator 
{
public:
	inline T* allocate(int sz)
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, int sz)
	{
		free(p);
	}
};

int main()
{
//	vector<int, MallocAllocator<int>> v(4); 
	vector<int> v(4); // ǥ�� �Ҵ�� ���
}


