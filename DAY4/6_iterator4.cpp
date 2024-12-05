#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ ����
// �ݺ����� �������̽�
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// ��� �÷���(�����̳�)�� ���Ѿ� �ϴ� ��Ģ
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//------------------------------------------------
// �̱۸���Ʈ �ݺ���
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










// ��� �÷��ǿ����� iterator �� ������ �־�� �Ѵ�.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }




	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head); // 1���� ���� �ʱ�ȭ�� �ݺ���
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
					// #1. it �� ����Ű�� �� ��ȯ
					// #2. it �� �������� �̵�
	}

	delete it;
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