#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	typedef Shape* (*CREATOR)();

	std::map<int, CREATOR> create_map;

	MAKE_SINGLETON(ShapeFactory)
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			p = it->second();
		}
		return p;
	}
};



// ���忡 ��ǰ�� ����ϱ� ���� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// ���������� �����ڰ� ���� ȣ��Ǵ��� �����غ�����!!
// 1. ��� ���������� �����ڰ� ȣ��ǰ�
// 2. main �Լ� ����
// AutoRegister ar(1, &Rect::create);



class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static ��� ����Ÿ�� Ư¡�� ������ ������
	// => ���� �����Ǵ��� ?
	// => �ᱹ Rect �� ����ϴ� "��������" �Դϴ�
	// => main �Լ� ���������� �����˴ϴ�. ar ������ ȣ��. 
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

//						// Rect::ar �� ������ ȣ��
//						// => ��, Rect ��� Ŭ������ ���ؼ� ���� 1ȸ ����
//						// => "��ü�� �����ڰ� �ƴ� Ŭ������ �����ڰ���"
// Rect* r1 = new Rect;	// Rect ������ ȣ��
// Rect* r2 = new Rect; // Rect ������ ȣ��
// Rect* r3 = new Rect; // Rect ������ ȣ��
						// ��, �����ڴ� "��ü�� ���鶧 ����" ȣ��
						// ��ü�� 1��
/*
// C#
class Car
{
	public Car() {} // instance ������
	static Car() {} // static ������ - C# �� �ִ� ����
};

Car c1 = new Car(); // static ������ ȣ��
					// instance ������ ȣ��
Car c2 = new Car(); // instance ������ ȣ��
Car c3 = new Car(); // instance ������ ȣ��

*/

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	// C++17 ���ʹ� �Ʒ� ó���ϸ� �ܺμ��� �ʿ� �����ϴ�.
	// => inline static
	// => ������Ʈ�޴�=> DAY4�Ӽ� �޴� ���� C++���� C++17 �� �����ϼ���
	inline static AutoRegister ar{ 2, &Circle::create };
};







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




