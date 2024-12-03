#include <cstdlib>

// 방법 #3. 단위전략 디자인(Policy Base Design)

// std::allocator<T> : C++ 표준에 이미 있는 메모리 할당기
//					   내부적으로 new, delete 사용
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<T> ax; // 이렇게 하면 강한 결합이므로 교체 안됨

	Alloc ax; // 템플릿 인자로 전달된 타입 사용

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
	vector<int> v(4); // 표준 할당기 사용
}


