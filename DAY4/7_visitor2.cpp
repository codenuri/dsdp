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
	void visit(T& e) { e = e * 2; }
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};



// 모든 컨테이너는 accept 가 있어야 한다.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

// std::list 를 확장에서 방문자 기능을 제공해 봅시다
template<typename T> 
class MyList : public std::list<T>,	public IAcceptor<T>
{
public:
	void accept(IVisitor<T>* visitor)
	{

	}
};


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;  
	s.accept(&tv);         

	ShowVisitor<int> sv; 
	s.accept(&sv);


}






