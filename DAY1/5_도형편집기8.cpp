#include <iostream>
#include <vector>

class not_implemented {}; //예외를 위한 클래스
class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}

	// 가상 함수      : 파생클래스가 override 하지 않으면 기본 구현 제공하겠다는 의도
	// 순수 가상 함수 : 파생 클래스에게 반드시 override 하라고 지시하는 것

	virtual void draw_imp() = 0;


	// 아래 함수도
	// 1. 순수 가상함수로 해도 좋습니다.
	// 2. 예외 전달 구현도 나쁘지 않습니다.
	// virtual Shape* clone() = 0; 

	// 1. 파생 클래스가 만드시 만들 필요는 없다.
	// 2. 파생클래스가 override 하지 않았는데 사용하지 않으면 ok
	// 3. 파생클래스가 override 하지 않았는데 사용하면 예외 발생
	// 4. 파생클래스가 override 고  사용하면 ok
	// => 즉, 사용하려면 override 하라는 의미
	virtual Shape* clone() { throw not_implemented(); }



	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone()
	{
		return new Rect(*this);
	}
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

	virtual Shape* clone()
	{
		return new Circle(*this);
	}
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

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());


		}
	}
}

