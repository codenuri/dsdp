#include <iostream>
#include <list>
#include <vector>

// ��� �湮�� Ŭ������ ���Ѿ� �ϴ� ��Ģ
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// �湮��(visitor) : �ᱹ "��� �Ѱ��� ���� ������ ���� �ϴ� Ŭ����"
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) {   };
};







int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;  
	s.accept(&tv);         

	ShowVisitor<int> sv; 
	s.accept(&sv);


}






