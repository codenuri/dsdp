﻿#include <iostream>
#include <conio.h>

// 각 컨트롤은 자신에 상태가 변경되었을때
// => 자신만 알면 안되고
// => 중재자(Mediator)에게도 통보되게 합니다.



// 중재자의 인터페이스
struct IMediator
{
	virtual void ChangeState() = 0;
	virtual ~IMediator() {}
};

class CheckBox
{
	bool state;

	IMediator* pMediator; // 모든 협력자(Colleague)는 중재자를 알아야 합니다.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();   // 내 가상함수만 호출하지말고
							pMediator->ChangeState(); } // 중재자에도 전달.. 

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

class RadioBox
{
	bool state;

	IMediator* pMediator; // 모든 협력자(Colleague)는 중재자를 알아야 합니다.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();
							pMediator->ChangeState(); }

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

// 중재자 클래스
// 중재자는 모든 협력자(Collegue)를 알고 잇어야 합니다.
class LogInMediator : public IMediator
{
	CheckBox* c1;
	CheckBox* c2;
	RadioBox* r1;
	RadioBox* r2;
public:
	LogInMediator( CheckBox* a, CheckBox* b, RadioBox* c, RadioBox* d)
		: c1(a), c2(b), r1(c), r2(d)
	{
		c1->SetMediator(this);
		c2->SetMediator(this);
		r1->SetMediator(this);
		r2->SetMediator(this);
	}
	void ChangeState()
	{
		// 이제 모든 협력자(컨트롤)의 관계설정은 이곳에 집중됩니다.
		if ( c1->GetCheck() && c2->GetCheck() &&
			 r1->GetCheck() && r2->GetCheck())
		{
			 std::cout <<"버튼 Enable" << std::endl;
		}
		else
			std::cout << "버튼 disable" << std::endl;
	}
};


int main()
{
	CheckBox c1, c2;
	RadioBox r1, r2;
	LogInMediator m(&c1, &c2, &r1, &r2);

	_getch(); c1.SetCheck(true);
	_getch(); c2.SetCheck(true);
	_getch(); r1.SetCheck(true);
	_getch(); r2.SetCheck(true);
	_getch(); c1.SetCheck(false);
}








