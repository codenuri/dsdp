#include <iostream>


// ���� �̾߱�.. 

class Point
{
	int x = 0;
	int y = 0;
public:
	// #1. ��� �Լ��� ���ڷ� this �� �߰� �˴ϴ�. 
	// => "this call" �̶�� �մϴ�.
	// ����� �ڵ�			// �����Ϸ��� ������ �ڵ�
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a; 
		y = b;				//		this->y = b;  ó�� ����Ȱ�
	}

	// #2. static ��� �Լ���  this �� �߰����� �ʴ� ��� �Լ� �Դϴ�.
	static void foo(int a)	// void foo(int a)
	{
		x = a;				// this->x = a; �� �Ǿ� �ϴµ�.
	}						//			�� �ȿ��� this ������.
							//			�׷���, error.
};				
int main()
{
	Point::foo(10); // ��ü ���� ȣ��. ���޵� ��ü�� ����.!
					// call Point::foo(10)

	Point p1;
	Point p2;

	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(10, 20); // set(&p2, 10, 20)
}