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
//#include "PointImpl.h"
class PointImpl; // Ŭ���� ���漱�� �־
				 // ������ ������ ��밡��
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { impl = new PointImpl;  }
void Point::print() { impl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// �� ����� �ᱹ "Bridge" �����ε�

// C++������ "PIMPL" �̶�� �θ��ϴ�.

// "Pointer to IMPLementation"

// ���� 1. �����Ϸ� ��ȭ��,������ �ӵ� ����
//		  PointImpl.h �� ���ص�
//		  ���� ����� �ڵ�� �� ������ �ʿ� ����.
//        (�߰����� �������� �ϸ� �ȴ�.)

// ���� 2. �Ϻ��� ���� ����
//		  ������ ����� ������ �ʿ� ����.
//		  �������� ����� �����ϸ�ȴ�.
