#include <cstdlib>
#include <memory> // std::allocator �� ���⿡ �ֽ��ϴ�.

// ��� #3. �������� ������(Policy Base Design)

// ���ϴ� ��(�޸� �Ҵ� ���) �� �ٸ� Ŭ������ �и�!!

// ��� ��ü �����ϰ� �Ұ��ΰ� ?
// strategy : �������̽��� ���� ��ü �����ϰ� ����.
//			  Edit/IValidator ����
//			  ��κ��� ��ü���� �� ���
//			  => ������ ���� 23���� �Ѱ�

// policy base design : template ���ڷ� ��ü �����ϰ� ����.
//			  C++ ���������� ���Ǵ� ������ ���
//			=> C++ IDioms �� �ִ� ���. ������ ���� �ƴ�.



// ������ ���� : ��κп� ��ü���� �� ���� ������ ���, 23��

// IDioms : ����� Ư¡�� ����� ������ ���
//          C++ IDioms, Java Idioms, C# IDioms ��... 
// ���ۿ��� "C++ IDioms" �˻�, 1��° ��ũ




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


