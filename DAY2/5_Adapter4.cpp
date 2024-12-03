#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ����� ����� ����� : list �� ��� ����� stack �� �����ϰڴٴ� ��

// ������ ����� ����� : list �� ��� ����� stack ���������θ� ����ϰڴٴ°�

// ���� : java �� stack �� vector ���� ��� �޾Ƽ� ����������ϴ�.
//		 => �߸��� �������� ��ǥ���� ���� �˷��� �ֽ��ϴ�.
//		 => �׷��� java �� stack �� ������� ���� deque �� ����ض� ��� �մϴ�.

template<typename T>
class stack 
{
	std::list<T> c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop()			 { c.pop_back(); }
	inline T& top()				 { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(20); // ���� �̷� ��� �Լ��� ����.


}
