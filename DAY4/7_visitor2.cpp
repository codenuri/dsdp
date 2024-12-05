#include <iostream>
#include <list>
#include <vector>

// 모든 방문자 클래스가 지켜야 하는 규칙
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 방문자(visitor) : 결국 "요소 한개에 대한 연산을 정의 하는 클래스"
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






