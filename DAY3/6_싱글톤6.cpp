#include <iostream>
#include <mutex>

class Singleton
{
private:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* instance;
	static std::mutex mtx;
public:
	static Singleton& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (instance == nullptr)
			instance = new Singleton;

		return *instance;
	}
};
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

// Mouse 도 위처럼 힙에 만드는 싱글톤을 사용하고 싶다.
class Mouse : public Singleton
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}


