#include <iostream>

// static 지역변수 vs static 멤버 데이타 

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;		// 이코드는 에러 지만
//	static Cursor instance; // 이 코드는 에러 아닙니다.
public:
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}
};
//Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

//	Cursor& c1 = Cursor::get_instance();

}







