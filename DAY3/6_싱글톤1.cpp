// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고,
//			프로그램에서 어디서도 동일한 방법으로 접근가능하게 한다.

// => 결국 전역변수와 같은 의미. 
// => 그런데, 전역변수는 좋지 않다고 사용하지 말라고 합니다.!!
// => 그래서, 싱글톤 패턴에 대한 비판이 많습니다.
// -------------------------------------------------

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2.


	// 규칙 #3. 오직 한개를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c1, c2; // error
}








