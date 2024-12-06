#include <iostream>

// 방법 #2. 변하는 것을 다른 클래스로
// => 데이타는 유지 하는데, 모든 동작(멤버함수)를 변경하고 싶다는것
// => 모든 멤버함수들을 여러개의 클래스로 제공

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 jump(), slide(), fly() 등의 모든 캐릭터의 동작을
	// 인터페이스로 약속
};
// 이제 여러개의 동작클래스를 설계 합니다.
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

// 위 코드의 의도
// => 멤버 함수들을 여러벌을 만들어 둔것!!!


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

		// 타이머 설치후 30초 뒤에 아래 코드 실행되게
		// current = &state1;
	}
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_item();

	p->run();
	p->attack();

}



