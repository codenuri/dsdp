// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	// 클래스 설계시, 항상 생성자에서 멤버 데이타를 초기화하는 것이
	// 좋습니다.
	Person(const std::string& name, int age)
		: name(name), age(age) {}
};

// 1. Person 에서 상속 받는 Student 만들어 보세요
// 2. int id 멤버 데이타 추가하세요
// 3. Student 생성자 만들어 보세요(id 초기화)
// 4. main 에서 Student 객체 생성해 보세요




int main()
{
	Person p1("kim", 20);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


