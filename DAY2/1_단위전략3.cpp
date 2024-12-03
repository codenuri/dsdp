// 방법 #2. strategy 패턴 적용
// => 변하는 것(메모리 할당/해지 방법)을 별도의 클래스로 설계하자.

// 교체해야 하므로 인터페이스를 먼저 설계

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


