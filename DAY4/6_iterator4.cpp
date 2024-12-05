#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 모든 반복자가 지켜야 하는 규칙 설계
// 반복자의 인터페이스
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// 모든 컬렉션(컨테이너)가 지켜야 하는 규칙
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//------------------------------------------------
// 싱글리스트 반복자
template<typename T> 
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	T& next() override
	{
		T& tmp = current->data;
		current = current->next;
		return tmp;
	}
	bool hasNext() override
	{
		return current != nullptr;
	}
};










// 모든 컬렉션에서는 iterator 를 꺼낼수 있어야 한다.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }




	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head); // 1번재 노드로 초기화된 반복자
	}
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IIterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
					// #1. it 가 가리키는 값 반환
					// #2. it 는 다음으로 이동
	}
}
