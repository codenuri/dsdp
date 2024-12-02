#include <iostream>
#include <vector>



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape\n"; }


	// 자신의 복사본을 생성하는 가상함수는 아주 널리 사용되는 
	// 기법 입니다.
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color; // 자신의 모든 속성을 새로운 객체에 복사
		return s;
	}

};





class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone()
	{
		Rect* s = new Rect;
		return s;
	}
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone()
	{
		Circle* s = new Circle;
		return s;
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

			// k 번째 도형의 복사본을 생성해서 v 에 추가 합니다
			// 어떻게 구현해야 할까요 ?
			// k 번째 만든 도형은 뭘까요 ?


			v.push_back(v[k]->clone()); // 다형성 !!
					// k 번째 도형이 뭔지 조사할 필요 없다.
					// java 에서는 이런 기법을 "don't ask do it"
					// 이라고 합니다.
	
		}
	}
}

