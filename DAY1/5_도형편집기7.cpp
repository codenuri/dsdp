#include <iostream>
#include <vector>

// template method ����
// => ��� Ŭ������ ������ ���� ��ü���� �帧�� ���� �ڵ带 ����
// => ���ؾ� �ϴ� �κи� �����Լ�ȭ �ؼ� �Ļ� Ŭ������ �ٽ� �����ȸ ����
// => ���� �θ� ���Ǵ� ������ ����.



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ�ȿ��� ���ؾ� �ϴ� �κ��� �ִٸ� �и��Ǿ���Ѵ�.
	// => ���ؾ� �ϴ� �κ��� �����Լ��� �и��Ѵ�.

	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

	void draw()
	{ 
		std::cout << "lock mutex\n";

		draw_imp();		
		
		std::cout << "unlock mutex\n";

	}







	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color; 
		return s;
	}

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
			std::cout << "���° ���� ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
		

		}
	}
}

