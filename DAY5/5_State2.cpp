#include <iostream>

// ��� #1. ���ϴ� ���� �����Լ���

class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()  { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperCharacter : public Character
{
public:
	void do_run() override { std::cout << "fast run" << std::endl; }
	void do_attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperCharacter; // ���� ĳ���� ��ü�� ������ ����Ȱ��� �ƴ϶�
							// ������ �ٸ� ���ο� ĳ���� ��ü ����
							// => ���۸� �ٲ۰��� �ƴ϶�, ���µ� ����Ȱ�

							// => ���ϴ� ���� ���´� ���� �ϴµ�, 
							//    ����(����Լ�)�� �ٲٰ� ������ !!
	p->run();
	p->attack();
}



