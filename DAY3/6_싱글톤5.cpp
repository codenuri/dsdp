#include <iostream>
#include <mutex>

// RAII ���
// => Resource Acquision Is (������ü��) Initialization
// => �ڿ��� ȹ���� "������ü" �� �ʱ�ȭ ����(������)���� �̷�� ����.
// => �ڿ��� �Ҵ�/���� �� �ݵ�� ������/�Ҹ��ڿ� �����϶�� ���

template<typename T> class lock_guard
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
		std::lock_guard<std::mutex> g(mtx);
//		lock_guard<std::mutex> g(mtx);	// #1. g �� �����ڿ��� mtx.lock()
										// #2. g �� �Ҹ��ڿ��� mtx.unlock()
//		mtx.lock();						// #3. ���� �߻��� ����������
										//     �����ϰ� �ı� �˴ϴ�.
										//     �Ҹ��ڰ� ȣ��ȴٴ°�(�ڿ��ݳ���)


			if (instance == nullptr)
				instance = new Cursor;

//		if (...) return;		// #4. �̷� �ڵ尡 �־ g �� �Ҹ��ڴ� ȣ��
//								//     �����ϰ� mtx.unlock() ����.
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


