#include <iostream>
#include <mutex>

// RAII 기술
// => 자원의 할당/해지 는 반드시 생성자/소멸자에 의존하라는 기술

template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* instance;
	static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		lock_guard<std::mutex> g(mtx);

//		mtx.lock();

		if (instance == nullptr)
			instance = new Cursor;

//		mtx.unlock();

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();

}


