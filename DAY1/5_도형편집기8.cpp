#include <iostream>
#include <vector>

class not_implemented {}; //���ܸ� ���� Ŭ����
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

	// ���� �Լ�      : �Ļ�Ŭ������ override ���� ������ �⺻ ���� �����ϰڴٴ� �ǵ�
	// ���� ���� �Լ� : �Ļ� Ŭ�������� �ݵ�� override �϶�� �����ϴ� ��

	virtual void draw_imp() = 0;


	// �Ʒ� �Լ���
	// 1. ���� �����Լ��� �ص� �����ϴ�.
	// 2. ���� ���� ������ ������ �ʽ��ϴ�.
	// virtual Shape* clone() = 0; 

	// 1. �Ļ� Ŭ������ ����� ���� �ʿ�� ����.
	// 2. �Ļ�Ŭ������ override ���� �ʾҴµ� ������� ������ ok
	// 3. �Ļ�Ŭ������ override ���� �ʾҴµ� ����ϸ� ���� �߻�
	// 4. �Ļ�Ŭ������ override ��  ����ϸ� ok
	// => ��, ����Ϸ��� override �϶�� �ǹ�
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
			std::cout << "���° ���� ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());


		}
	}
}

