#include <iostream>
#include <vector>


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



	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color;
		return s;
	}

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

