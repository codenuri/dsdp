#include <iostream>
#include <mutex>

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
		std::lock_guard<std::mutex> g(mtx);

		if (instance == nullptr)
			instance = new Cursor;

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::mtx;

// Mouse 도 위처럼 힙에 만드는 싱글톤을 사용하고 싶다.
class Mouse
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}


