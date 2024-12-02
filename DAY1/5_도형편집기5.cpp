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

		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			// k ��° ������ ���纻�� �����ؼ� v �� �߰� �մϴ�
			// ��� �����ؾ� �ұ�� ?
			// k ��° ���� ������ ����� ?

			
			// �Ʒ� ó�� �ߴٸ� ���� OCP �����Ҽ� ���� �ڵ�
			// => �׷��� dynamic_cast �� ����ϴ� ���� ���� �������� �ƴϴ�.
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				Rect* r = new Rect;
			//	r->set_color = v[k]->color; // v[k] �� ��� �Ӽ��� r�� ����
				v.push_back(r);
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				Circle* c = new Circle;
				
				v.push_back(c);
			}
		}
	}
}

