#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// => 문자열을 보관했다가 화면에 이쁘게 출력하는 기능
class TextView
{
	// font 종류, 크기, 색상 등... 다양한 정보 관리 
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};




//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};


// 클래스 어답터 : 클래스 인터페이스 변경
// 객체   어답터 : 객체   인터페이스 변경

class Text : public TextView,  public Shape     
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체(변수)

	// 이미 생성된 객체 tv 를 v에 넣을수 있을까요 ?
	v.push_back(&tv); // ??
}







