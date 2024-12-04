#include <iostream>
#include <mutex>

// CRTP
// => ��� Ŭ���� ���鶧 �̷��� ������� �Ļ� Ŭ���� �̸��� ����Ҽ� �ְ�
//    �ϴ� ��� ( C++ IDioms )

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

// Mouse �� ��ó�� ���� ����� �̱����� ����ϰ� �ʹ�.

class Mouse : public Singleton< Mouse  >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}


