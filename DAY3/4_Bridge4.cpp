// ��������
// Point �� ��� ����� �� Ŭ������ ����
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() {} 



// �Ʒ�Ŭ������ �߻���(������)
// ������ü�� ������
// ����ڴ� �� Ŭ���� ����մϴ�.
// Point.h

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
Point::Point() { impl = new PointImpl;  }
void Point::print() { impl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


