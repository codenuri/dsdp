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
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// �̷��� �ص� ������, �ݺ��� �̸��� �����̳ʸ��� �ٸ��� �ֽ��ϴ�.
	// auto ����
	//slist_iterator<int> it = s.iterator(); 

	auto it = s.iterator();

	// ���� it �� �����ʹ� �ƴ����� �����Ϳ� ������ ������ �����մϴ�.
	++it;

	std::cout << *it << std::endl;
}

// �� �ڵ�� �������� ������ ���Ͽ��� ����ϴ� iterator ���� �Դϴ�.
// => Java, C#, Python, Swift �� ��κ��� ���� ���ڵ�� �����ϰ� �����մϴ�.

// �׷���, C++ �������� �̾߱� �ϴ� �� �ڵ��� ����

// #1. �ݺ��ڸ� ������ s.iterator() �� ��ȯ�ϴ� �ݺ��ڴ� "new" �� ����� �˴ϴ�.
//     => delete �� �ʿ����� ������� ?

// #2. ��Ҹ� ��ȸ �Ҷ� ����ϴ� next()/hasNext() �� �����Լ� �Դϴ�.
//    => ��õ ~ ������ ȣ��Ǵ� ��� ������尡 ����� �����ϴ�.

// #3. �迭�� ��¥ �����͸� ����ؼ� ��� ��ҿ� ���������� �����մϴ�.
//    => ��¥ �����ʹ� next() �Լ��� �ƴ� "++" �� �̵��մϴ�.
//    => "��� �÷���"�� �����ϰ� ����!!! �� ��Ģ�� ���� �˴ϴ�.
//    => �迭�� �÷���(�����̳�)�Դϴ�.