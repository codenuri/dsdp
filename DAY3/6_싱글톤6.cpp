#include <iostream>
#include <mutex>

// CRTP
// => 기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 사용할수 있게
//    하는 기법 ( C++ IDioms )

template<typename T>
class Singleton
{
private:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* instance;
	static std::mutex mtx;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (instance == nullptr)
			instance = new T;

		return *instance;
	}
};
T* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

// Mouse 도 위처럼 힙에 만드는 싱글톤을 사용하고 싶다.

class Mouse : public Singleton< Mouse  >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}


