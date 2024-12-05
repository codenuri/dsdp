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
	void visit(T& e) { e = e * 2; }
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};



// ��� �����̳ʴ� accept �� �־�� �Ѵ�.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

// std::list �� Ȯ�忡�� �湮�� ����� ������ ���ô�
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






