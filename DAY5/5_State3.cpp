#include <iostream>

// ��� #2. ���ϴ� ���� �ٸ� Ŭ������
// => ����Ÿ�� ���� �ϴµ�, ��� ����(����Լ�)�� �����ϰ� �ʹٴ°�
// => ��� ����Լ����� �������� Ŭ������ ����

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �̿ܿ� jump(), slide(), fly() ���� ��� ĳ������ ������
	// �������̽��� ���
};
// ���� �������� ����Ŭ������ ���� �մϴ�.
class NoItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class BadItem : public IState
{
public:
	void run()    override { std::cout << "slow run" << std::endl; }
	void attack() override { std::cout << "weak attack" << std::endl; }
};

// �� �ڵ��� �ǵ�
// => ��� �Լ����� �������� ����� �а�!!!


class Character
{
	NoItem    state1;
	SuperItem state2;
	BadItem   state3;

	IState* current = &state1;

	int gold;
	int item;
public:
	void run()    { current->run(); }
	void attack() { current->attack(); }

	void acquire_item()
	{
		current = &state2;

		// Ÿ�̸� ��ġ�� 30�� �ڿ� �Ʒ� �ڵ� ����ǰ�
		// current = &state1;
	}
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_item();	// �̼���, p�� ����(��� ����Ÿ)�� ��� ���� �˴ϴ�.
						// �׷���, ��� �Լ��� ��� ����˴ϴ�.
						// ��ġ �ٸ� Ŭ������ ����ϴ°� ���� ���Դϴ�.

	p->run();
	p->attack();

}

// �ᱹ �� �ڵ�� ���ϴ� ���� �ٸ� Ŭ������ ����
// �������̽� ������� ��ü�ϴ� �ڵ� �Դϴ�.

// �Ʒ� 3���� ������ class Diagram �� ���� �մϴ�.


// strategy : ��ü�� ����ϴ� "�˰�����" �� ��ü �ϴ°�
//(��������)	  ex) �ٵϰ��ӿ��� "������ ����" �ϴ� ���
//			  ��ü�� ���� ��ü�� ����Ǵ� ���� �ƴϴ�.

// state : ��ü�� "����"�� ���� ���(���� ��κ���) ������ ����.
//		   ex) ���Ǳ�� "���� ���� ����" �� ���� ��� ������ ����˴ϴ�.
//			   "NoCoin", "HasCoin" ���� 2���� ���� Ŭ������ ����
//				"���� ���Խ� ���¸� ��ü"

// builder : ������ ��ü�� ���鶧
//			 ����� ����� �����ϰ� �ϰ�
//			 �� ������ ����� �ٸ��� �Ҷ�.
