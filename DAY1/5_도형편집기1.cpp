// 15page ~ 
#include <iostream>
#include <vector>

// 파워 포인트 값은 프로그램을 객체지향으로 만드는 방법을 생각해 봅시다.
// #1. 모든 도형을 타입으로 설계해야 한다. (class 문법)

class Rect
{
	// x, y, w, h, 생성자등은 생략, 가상함수에 집중!!
public:
	void draw() { std::cout << "draw Rect\n"; }
};


int main()
{
	std::vector<Rect*> v;
}

