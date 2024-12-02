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


	// �ڽ��� ���纻�� �����ϴ� �����Լ��� ���� �θ� ���Ǵ� 
	// ��� �Դϴ�.
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color; // �ڽ��� ��� �Ӽ��� ���ο� ��ü�� ����
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
			std::cout << "���° ���� ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			// k ��° ������ ���纻�� �����ؼ� v �� �߰� �մϴ�
			// ��� �����ؾ� �ұ�� ?
			// k ��° ���� ������ ����� ?


			v.push_back(v[k]->clone()); // ������ !!
					// k ��° ������ ���� ������ �ʿ� ����.
					// java ������ �̷� ����� "don't ask do it"
					// �̶�� �մϴ�.
	
		}
	}
}

