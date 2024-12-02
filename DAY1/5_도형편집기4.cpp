#include <iostream>
#include <vector>

// 핵심 #1. 모든 파생 클래스(도형)의 공통의 특징은 
//          반드시 기반클래스(Shape) 에도 있어야 한다.
//          문법적인 규칙이 아닌, 디자인의 원칙

// 핵심 #2. 기반 클래스의 멤버 함수중 파생 클래스가 다시 만들게 되는것은
//			반드시 가상함수로 만들어야 한다.

class Shape
{
	int color;
public:
	virtual ~Shape() {} 

	// 아래 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생 클래스가 override 할 이유가 없습니다.
	// => non-virtual
	void set_color(int c) { color = c; }

	// 아래 함수는 파생 클래스가 override 해야 합니다.
	// => 면적을 구하는 공식은 도형 마다 다릅니다.
	// => virtual 이어야 합니다.
	virtual int get_area() { return - 1; }

	virtual void draw() { std::cout << "draw Shape\n"; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
			{
				p->draw();
			}
		}
	}
}

