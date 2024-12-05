#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


// C++ ����
// => �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ�� "�������̽��� ���" �������� 
// => "Raw Pointer �� ������ ���" ���� ����.

template<typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*()
	{
		return current->data;
	}

	// �ݺ��ڸ� raw pointer ó�� ����Ϸ��� == �� != ������ �Ǿ�� �մϴ�.
	inline bool operator==(const slist_iterator& other)
	{
		return current == other.current;
	}

	inline bool operator!=(const slist_iterator& other)
	{
		return current != other.current;
	}
};







// �ݺ��ڸ� ������ ��� �Լ��� "begin" �̶�� �̸����� ���(����)����.
template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// �Լ��̸��� ��ӵǾ���, ��ȯ Ÿ���� �����Ӱ� �Ҽ� �����Ƿ�
	// �ڽ��� �ݺ��� Ÿ���� ��Ȯ�� ��밡��. new ���� �ʿ� ����.
	slist_iterator<T> begin()
	{
		slist_iterator<T> it(head);
		return it;
	}

	slist_iterator<T> end()
	{
		slist_iterator<T> it( nullptr );
		return it;
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// C++ STL �� �������� �ݺ��ڸ� ����ϴ� �ڵ�
	auto first = s.begin();
	auto last = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

