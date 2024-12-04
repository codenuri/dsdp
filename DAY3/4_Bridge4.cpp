// 구현계층
// Point 의 모든 기능은 이 클래스가 구현
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



// 아래클래스가 추상층(간접층)
// 구현자체는 없지만
// 사용자는 이 클래스 사용합니다.
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


