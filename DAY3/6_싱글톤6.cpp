#include <iostream>
#include <mutex>

// CRTP
// => Curiously Recurring Template Pattern
// => �ű��ϰԵ� ��޵ɼ� �ִ� ���ø� ����
// => ��� Ŭ���� ���鶧 �̷��� ������� �Ļ� Ŭ���� �̸��� ����Ҽ� �ְ�
//    �ϴ� ��� ( C++ IDioms )

template<typename T>
class Singleton
{
protected:
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

template<typename T> T* Singleton<T>::instance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse �� ��ó�� ���� ����� �̱����� ����ϰ� �ʹ�.

class Mouse : public Singleton< Mouse  >
{
};

class Keyboard : public Singleton< Keyboard  >
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}

// github.com/aosp-mirror		�ȵ���̵� OS �ҽ� �ڵ� �Դϴ�.
// platform system core         �������丮 ����

// libutils/include/utils/ Singleton.h ���� ������

