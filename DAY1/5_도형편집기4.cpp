#include <iostream>
#include <vector>

// �ٽ� #1. ��� �Ļ� Ŭ����(����)�� ������ Ư¡�� 
//          �ݵ�� ���Ŭ����(Shape) ���� �־�� �Ѵ�.
//          �������� ��Ģ�� �ƴ�, �������� ��Ģ

// �ٽ� #2. ��� Ŭ������ ��� �Լ��� �Ļ� Ŭ������ �ٽ� ����� �Ǵ°���
//			�ݵ�� �����Լ��� ������ �Ѵ�.

class Shape
{
	int color;
public:
	virtual ~Shape() {} 

	// �Ʒ� �Լ��� virtual �� �ұ�� ? non-virtual �� �ұ�� ?
	// => �Ļ� Ŭ������ override �� ������ �����ϴ�.
	// => non-virtual
	void set_color(int c) { color = c; }

	// �Ʒ� �Լ��� �Ļ� Ŭ������ override �ؾ� �մϴ�.
	// => ������ ���ϴ� ������ ���� ���� �ٸ��ϴ�.
	// => virtual �̾�� �մϴ�.
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

				p->draw();	// ������(Polymorphism)
							// => ������ ǥ������ ��Ȳ(��ü)�� ����
							//    �ٸ��� �����ϴ� ��
							
							// �� �ڵ�� ���ο� ����(Triangle)�� �߰��Ǿ
							// ������ �ʿ� �����ϴ�.
							// OCP �� �����ϴ� ���� �ڵ� ��Ÿ�� �Դϴ�.


				// ��ü���� ����� 3�� Ư¡
				// => ĸ��ȭ(private), ���, ������
			}
		}
	}
}

