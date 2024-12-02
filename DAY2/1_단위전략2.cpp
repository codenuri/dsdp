// vector 의 동작 방식은 변하지 않습니다.
// vector 가 사용하는 메모리 할당 방식을 교체 가능해야 합니다.

// 방법 #1. template method 사용
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

