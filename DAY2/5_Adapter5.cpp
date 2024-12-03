#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter ���ϰ� policy base design �� ����

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop() { c.pop_back(); }
	inline T& top() { return c.back(); }
};
#include <stack> // �̾ȿ� �ڵ尡 ���� ���� ���� �մϴ�.
				 // stack adapter ��� �θ��ϴ�.
				 // cppreference.com ���� Container Library ����

int main()
{
	std::stack<int, std::list<int>> s3;
	

	stack<int, std::list<int>> s1;  
	stack<int, std::vector<int>> s2; // vector �� stack ó�� ����ϰڴٴ�
									// �ǵ�. 

	stack<int> s; // ���� �ڷᱸ���� deque
	s.push(10);

}
